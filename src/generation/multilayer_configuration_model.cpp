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
swap_edges(
    Network *li,
    uu::core::PropertyMatrix<s_pair, const Network *, bool> &P,
    const s_pair &s1,
    const s_pair &s2,
    const s_pair &new_s1,
    const s_pair &new_s2
)
{
    li->edges()->erase(s1.first, s1.second);
    li->edges()->erase(s2.first, s2.second);
    li->edges()->add(new_s1.first, new_s1.second);
    li->edges()->add(new_s2.first, new_s2.second);

    P.set(s1, li, false);
    P.set(std::make_pair(s1.second, s1.first), li, false);
    P.set(s2, li, false);
    P.set(std::make_pair(s2.second, s2.first), li, false);
    P.set(new_s1, li, true);
    P.set(std::make_pair(new_s1.second, new_s1.first), li, true);
    P.set(new_s2, li, true);
    P.set(std::make_pair(new_s2.second, new_s2.first), li, true);
}

void
modify_according_to_jaccard_edge(
    MultilayerNetwork *net,
    const std::vector<double> &j_e,
    double tol
)
{
    auto P = edge_existence_property_matrix(net);
    size_t n = net->actors()->size();
    size_t l = net->layers()->size();
    auto get_index = [l](size_t i, size_t j)
    {
        auto p = std::minmax(i, j);
        return (size_t) (p.first * (l - p.first / 2.0 - 1.5) + p.second - 1);
    }; // a function to return an index of a array storing a triangular matrix

    // number of coordinates for each pair of layers where vectors are true (yy), false (nn)
    std::valarray<size_t> yy((size_t) 0, j_e.size()), nn(P.num_structures, j_e.size());
    std::valarray<double> error(j_e.size()); // error for each pair of layers

    for (size_t i = 0; i < l; ++i)
    {
        for (size_t j = i + 1; j < l; ++j)
        {
            auto l_i = net->layers()->at(i);
            auto l_j = net->layers()->at(j);
            size_t index = get_index(i, j);

            for (auto s: P.structures())
            {
                yy[index] += (P.get(s, l_i).value && P.get(s, l_j).value);
                nn[index] -= (P.get(s, l_i).value || P.get(s, l_j).value);
            }

            error[index] = yy[index] / (double) (P.num_structures - nn[index]) - j_e[index];
        }
    }

    // Parameters for the simulated annealing algorithm
    double T_0 = 1e-3;
    double beta = 0.01;
    size_t k_max = 100 * ceil(std::log(n) * n);

    s_pair s1, s2, new_s1, new_s2;

    for (size_t k = 0; k < k_max; k++)
    {
        double T = T_0 / (1 + beta + k);
        size_t l_ind = uu::core::irand(l); // index of the layer which might be updated
        auto li = net->layers()->at(l_ind);
        auto e1 = li->edges()->get_at_random();
        auto e2 = li->edges()->get_at_random();

        if (e1->v1 == e2->v1 || e1->v1 == e2->v2 || e1->v2 == e2->v2 || e1->v2 == e2->v1) // the edges cannot be swapped
        {
            continue;
        }

        s1 = std::make_pair(e1->v1, e1->v2);
        s2 = std::make_pair(e2->v1, e2->v2);
        new_s1 = std::make_pair(e1->v1, e2->v1);
        new_s2 = std::make_pair(e1->v2, e2->v2);

        if (P.get(new_s1, li).value || P.get(new_s2, li).value)
        {
            new_s1 = std::make_pair(e1->v1, e2->v2);
            new_s2 = std::make_pair(e1->v2, e2->v1);

            if (P.get(new_s1, li).value || P.get(new_s2, li).value) // the edges cannot be swapped
            {
                continue;
            }
        }

        std::valarray<size_t> yy_new(yy), nn_new(nn);
        std::valarray<double> new_error(error);

        for (size_t j = 0; j < l; ++j)
        {
            if (j == l_ind)
            {
                continue;
            }

            size_t index = get_index(l_ind, j);
            auto l_j = net->layers()->at(j);
            std::valarray<bool> Pl1slice = { P.get(s1, l_j).value, P.get(s2, l_j).value, P.get(new_s1, l_j).value, P.get(new_s2, l_j).value };
            yy_new[index] += 2 * (- Pl1slice[0] - Pl1slice[1] + Pl1slice[2] + Pl1slice[3]);
            nn_new[index] += 2 * (- !Pl1slice[2] - !Pl1slice[3] + !Pl1slice[0] + !Pl1slice[1]);
            new_error[index] = yy_new[index] / (double) (P.num_structures - nn_new[index]) - j_e[index];
        }

        double diff = (std::abs(new_error) - std::abs(error)).sum();
        double p = std::min(1.0, (diff < 0) + std::exp(-diff / T));

        if (p >= uu::core::drand())
        {
            yy = yy_new;
            nn = nn_new;
            error = new_error;

            swap_edges(li, P, s1, s2, new_s1, new_s2);

            if (std::abs(error).max() <= tol)
            {
                break;
            }
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

}
}