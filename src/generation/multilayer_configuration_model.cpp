#include "generation/multilayer_configuration_model.hpp"

namespace uu {
namespace net {

typedef std::pair<const Vertex*, const Vertex*> s_pair;

void
order_degrees_pearson(
    std::vector<std::vector<size_t>> &deg,
    std::vector<double> &r,
    double tol
)
{
    size_t l = deg.size();
    size_t n = deg[0].size();
    size_t tm_size = l * (l - 1) / 2; // triangular matrix size
    auto get_index = [l](size_t i, size_t j)
    {
        auto p = std::minmax(i, j);
        return (size_t) (p.first * (l - p.first / 2.0 - 1.5) + p.second - 1);
    }; // a function to return an index of a array storing a triangular matrix
    std::vector<double> norms(l); // norms of degrees vectors for each layer
    std::vector<std::vector<double>> v(l); // v[i][j] = deg[i][j] - mean(deg[i])

    for (size_t l_i = 0; l_i < l; l_i++)
    {
        double seq_mean = std::accumulate(deg[l_i].begin(), deg[l_i].end(), 0.0) / n;
        v[l_i] = std::vector<double>(n);
        std::transform(deg[l_i].begin(), deg[l_i].end(), v[l_i].begin(), [seq_mean](size_t v)
        {
            return v - seq_mean;
        });
        norms[l_i] = sqrt(std::inner_product(v[l_i].begin(), v[l_i].end(), v[l_i].begin(), 0.0));
    }

    std::valarray<double> c(tm_size); // denominators from the Pearson cc formula for each pair of layers
    std::valarray<double> error(tm_size); // Pearson cc errors for each pair of layers

    for (size_t l_i = 0; l_i < l; l_i++)
    {
        for (size_t l_j = l_i+1; l_j < l; l_j++)
        {
            size_t index = get_index(l_i, l_j);
            c[index] = norms[l_i] * norms[l_j];
            error[index] = std::inner_product(v[l_i].begin(), v[l_i].end(), v[l_j].begin(), 0.0) - c[index] * r[index];
        }
    }

    // Parameters for the simulated annealing algorithm
    size_t k_max = 4 * l * n;
    double T_0 = n;
    double beta = 0.1;

    for (size_t k = 0; k < k_max; k++)
    {
        double T = T_0 / (1 + beta * k);
        size_t l_ind = uu::core::irand(l); // index of the layer which might be updated
        size_t i1 = uu::core::irand(n), i2 = uu::core::irand(n); // indices of elements to be swapped

        if (v[l_ind][i1] == v[l_ind][i2])
        {
            continue;
        }

        std::valarray<double> new_error(error);

        for (size_t l_i = 0; l_i < l; l_i++)
        {
            if (l_i == l_ind)
            {
                continue;
            }

            new_error[get_index(l_i, l_ind)] += (- v[l_i][i1] * v[l_ind][i1] - v[l_i][i2] * v[l_ind][i2]
                                                 + v[l_i][i1] * v[l_ind][i2] + v[l_i][i2] * v[l_ind][i1]);
        }

        double diff = std::abs(new_error).sum() - std::abs(error).sum();
        double p = std::min(1.0, (diff < 0) + exp(- diff / T)); // probability of the elements being swapped

        if (p >= uu::core::drand())
        {
            std::swap(v[l_ind][i1], v[l_ind][i2]);
            std::swap(deg[l_ind][i1], deg[l_ind][i2]);
            error = new_error;

            if (std::abs((error / c)).max() <= tol)
            {
                break;
            }
        }
    }
}


void
_property_matrix_comparison
(
    const std::vector<Network *> &layers,
    std::unordered_map<Network *, std::unordered_set<Dyad>> &edges,
    const std::vector<double> &j_e,
    std::valarray<size_t> &yy,
    std::valarray<size_t> &nn,
    std::valarray<double> &error,
    size_t num_structures
)
{
    size_t l = edges.size();
    auto get_index = [l](size_t i, size_t j) // expected i < j
    {
        return (size_t) (i * (l - i / 2.0 - 1.5) + j - 1);
    }; // a function to return an index of a array storing a triangular matrix


    for (size_t i = 0; i < layers.size(); i++)
    {
        for (size_t j = i + 1; j < layers.size(); j++)
        {
            size_t index = get_index(i, j);
            yy[index] = 0;

            for(const auto &edge: edges[layers[i]])
            {
                yy[index] += 2 * edges[layers[j]].count(edge);
            }

            nn[index] = num_structures - ( 2 * edges[layers[i]].size() + 2 * edges[layers[j]].size() - yy[index]);
            error[index] = yy[index] / (double) (num_structures - nn[index]) - j_e[index];
        }

    }
}

void
_modify_jaccard_edge
(
    const std::vector<Network *> &layers,
    const std::vector<double> &j_e,
    std::unordered_map<Network *, std::unordered_set<Dyad>> &edges,
    size_t n,
    double tol
)
{
    std::unordered_map<Network *, std::vector<const Dyad *>> edges_vec;

    for(const auto &it: edges)
    {
        auto layer = it.first;
        edges_vec[layer] = std::vector<const Dyad *>();
        edges_vec[layer].reserve(layer->edges()->size());

        for(const auto &edge: it.second)
        {
            edges_vec[layer].push_back(&edge);
        }
    }

    size_t l = edges.size(); // number of layers
    size_t num_structures = n * (n-1); // number of structures in the property matrix
    auto get_index = [l](size_t i, size_t j) // expected i < j
    {
        return (size_t) (i * (l - i / 2.0 - 1.5) + j - 1);
    }; // a function to return an index of a array storing a triangular matrix

    // number of coordinates for each pair of layers where vectors are true (yy), false (nn)
    std::valarray<size_t> yy(j_e.size()), nn(j_e.size());
    std::valarray<double> error(j_e.size()); // error for each pair of layers

    _property_matrix_comparison(layers, edges, j_e, yy, nn, error, num_structures);

    // Parameters for the simulated annealing algorithm
    double Temp = 1.5 * l * n; // initial temperature
    const double alpha = 0.95; // value governing the decrease of temperature
    const double beta = 1000; // value used in the probability function
    const size_t k_max = 50 * l * n; // max number of iterations

    for (size_t k = 0; k < k_max; k++)
    {
        Temp *= alpha;
        size_t l_ind = uu::core::irand(l); // index of the layer which might be updated
        auto li = layers[l_ind];
        size_t e1_ind = uu::core::irand(edges_vec[li].size()), e2_ind = uu::core::irand(edges_vec[li].size());
        auto e1 = *edges_vec[li][e1_ind];
        auto e2 = *edges_vec[li][e2_ind];
        auto e1_first = *e1.begin(), e1_second = *(++e1.begin());
        auto e2_first = *e2.begin(), e2_second = *(++e2.begin());

        if (e1_first == e2_first || e1_first == e2_second || e1_second == e2_second || e1_second == e2_first) // edges cannot be swapped
        {
            continue;
        }

        bool ff_ss = (uu::core::drand() <= 0.5); // if connect e1_first with e2_first and e1_second with e2_second
        auto new_e1 = Dyad(e1_first, (ff_ss) ? e2_first : e2_second);
        auto new_e2 = Dyad(e1_second, (ff_ss) ? e2_second : e2_first);

        if (edges[li].count(new_e1) || edges[li].count(new_e2)) // edges cannot be swapped
        {
            new_e1 = Dyad(e1_first, (ff_ss) ? e2_second : e2_first);
            new_e2 = Dyad(e1_second, (ff_ss) ? e2_first : e2_second);

            if (edges[li].count(new_e1) || edges[li].count(new_e2)) // edges cannot be swapped
            {
                continue;
            }
        }

        std::valarray<size_t> yy_new(yy), nn_new(nn);
        std::valarray<double> new_error(error);

        // compute the error after the swap
        for (size_t j = 0; j < l; ++j)
        {
            if (j == l_ind)
            {
                continue;
            }

            auto indices = std::minmax(l_ind, j);
            size_t index = get_index(indices.first, indices.second);
            auto l_j = layers[j];
            std::valarray<bool> Pl1slice = { edges[l_j].count(e1) > 0, edges[l_j].count(e2) > 0, edges[l_j].count(new_e1) > 0, edges[l_j].count(new_e2) > 0 };
            yy_new[index] += 2 * (- Pl1slice[0] - Pl1slice[1] + Pl1slice[2] + Pl1slice[3]);
            nn_new[index] += 2 * (- !Pl1slice[2] - !Pl1slice[3] + !Pl1slice[0] + !Pl1slice[1]);
            new_error[index] = yy_new[index] / (double) (num_structures - nn_new[index]) - j_e[index];
        }

        double diff = (std::abs(new_error) - std::abs(error)).sum();
        double p = std::min(1.0 - (diff == 0), (diff < 0) + std::exp(-beta * diff / Temp));

        if (p >= uu::core::drand())
        {
            yy = yy_new;
            nn = nn_new;
            error = new_error;

            // swap edges
            auto res1 = edges[li].emplace(new_e1);
            auto res2 = edges[li].emplace(new_e2);
            edges_vec[li][e1_ind] = &(*res1.first);
            edges_vec[li][e2_ind] = &(*res2.first);
            edges[li].erase(e1);
            edges[li].erase(e2);

            if (std::abs(error).max() <= tol)
            {
                break;
            }
        }
    }
}

void
modify_jaccard_edge
(
    MultilayerNetwork *net,
    const std::vector<double> &j_e,
    double tol
)
{
    std::unordered_map<Network *, std::unordered_set<Dyad>> edges;
    std::vector<Network *> layers(net->layers()->size());
    // TODO remove the layers vector, but for now it is necessary because we need to keep the same order as j_e,
    //  when it's constructed with net->layers()->at(i), which is not preserved when calling net->layers()

    for(size_t i = 0; i < net->layers()->size(); i++)
    {
        auto layer = net->layers()->at(i);
        layers[i] = layer;
        edges[layer] = std::unordered_set<Dyad>();
        edges[layer].reserve(layer->edges()->size());

        for(const auto &edge: *layer->edges())
        {
            edges[layer].emplace(Dyad(edge->v1, edge->v2));
        }
    }

    _modify_jaccard_edge(layers, j_e, edges, net->actors()->size(), tol);

    // update the edges in the network
    for (auto layer: *net->layers())
    {
        for (auto edge: *layer->edges())
        {
            auto pos = edges[layer].find(Dyad(edge->v1, edge->v2));
            if (pos != edges[layer].end())
            {
                edges[layer].erase(pos);
            }
            else
            {
                layer->edges()->erase(edge);
            }
        }

        for(const auto& dyad: edges[layer])
        {
            layer->edges()->add(*dyad.begin(), *(++dyad.begin()));
        }
    }
}

void
add_layers_with_given_degrees(
    const std::vector<std::vector<size_t>> &deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &actors,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml
)
{
    size_t layers_count = layers_names.size();

    for (size_t i = 0; i < layers_count; i++)
    {
        auto l = ml->layers()->add(layers_names[i], EdgeDir::UNDIRECTED, LoopMode::DISALLOWED);
        from_degree_sequence(deg_seq[i], actors, l);
    }
}

void
add_layers_with_given_degrees(
    const std::vector<std::vector<size_t>> &in_deg_seq,
    const std::vector<std::vector<size_t>> &out_deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &actors,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml
)
{
    size_t layers_count = layers_names.size();

    for (size_t i = 0; i < layers_count; i++)
    {
        auto l = ml->layers()->add(layers_names[i], EdgeDir::DIRECTED, LoopMode::DISALLOWED);
        from_degree_sequence(in_deg_seq[i], out_deg_seq[i], actors, l);
    }
}

void
add_layers_with_given_degrees
(
    const std::vector<std::vector<size_t>> &deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &actors,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml,
    const std::vector<double> &j_e,
    double tol
)
{
    size_t layers_count = layers_names.size();
    std::unordered_map<Network *, std::unordered_set<Dyad>> edges;
    std::vector<Network *> layers;

    for (size_t i = 0; i < layers_count; i++)
    {
        auto l = ml->layers()->add(layers_names[i], EdgeDir::UNDIRECTED, LoopMode::DISALLOWED);
        layers[i] = l;

        for (const auto& v : actors)
        {
            l->vertices()->add(v);
        }
        edges[l] = std::unordered_set<Dyad>();
        edges_from_degree_sequence(deg_seq[i], actors, edges[l]);
    }

    _modify_jaccard_edge(layers, j_e, edges, actors.size(), tol);

    for (auto layer: *ml->layers())
    {
        for (const auto &dyad: edges[layer])
        {
            layer->edges()->add(*dyad.begin(), *(++dyad.begin()));
        }
    }
}

}
}