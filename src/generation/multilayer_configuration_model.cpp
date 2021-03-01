#include "generation/multilayer_configuration_model.hpp"

namespace uu {
namespace net {

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
    size_t k_max = 4 * l * (size_t) ceil(pow(log(n), 2) * sqrt(n));
    double T_0 = n;
    double beta = 0.1;

    for (size_t k = 0; k < k_max; k++)
    {
        double T = T_0 / (1 + beta * k);
        size_t l_ind = uu::core::getRandomInt(l); // index of the layer which might be updated
        size_t i1 = uu::core::getRandomInt(n), i2 = uu::core::getRandomInt(n); // indices of elements to be swapped

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
            error = new_error;

            if (std::abs((error / c)).max() <= tol)
            {
                break;
            }
        }
    }
}

void
add_layers_with_given_degrees(
    const std::vector<std::vector<size_t>> &deg_seq,
    const uu::core::NameIterator &vertices_names,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml
)
{
    size_t layers_count = layers_names.size();

    for (size_t i = 0; i < layers_count; i++)
    {
        auto l = ml->layers()->add(layers_names[i], EdgeDir::UNDIRECTED, LoopMode::DISALLOWED);
        from_degree_sequence(deg_seq[i], vertices_names, l);
    }
}

void
add_layers_with_given_degrees(
    const std::vector<std::vector<size_t>> &in_deg_seq,
    const std::vector<std::vector<size_t>> &out_deg_seq,
    const uu::core::NameIterator &vertices_names,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml
)
{
    size_t layers_count = layers_names.size();

    for (size_t i = 0; i < layers_count; i++)
    {
        auto l = ml->layers()->add(layers_names[i], EdgeDir::DIRECTED, LoopMode::DISALLOWED);
        from_degree_sequence(in_deg_seq[i], out_deg_seq[i], vertices_names, l);
    }
}

}
}