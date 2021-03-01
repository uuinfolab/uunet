#ifndef UU_GENERATION_MULTILAYER_CONFIGURATION_MODEL_H
#define UU_GENERATION_MULTILAYER_CONFIGURATION_MODEL_H

#include "networks/MultilayerNetwork.hpp"
#include "core/utils/names.hpp" // NameIterator
#include "generation/configuration_model.hpp" // from_degree_sequence
#include "core/utils/random.hpp" // drand
#include <algorithm> // std::inner_product, std::transform
#include <valarray>

namespace uu {
namespace net {

void
order_degrees_pearson(
    std::vector<std::vector<size_t>> &deg,
    std::vector<double> &r,
    double tol=1e-3
);

void
add_layers_with_given_degrees(
    const std::vector<std::vector<size_t>> &deg_seq,
    const uu::core::NameIterator &vertices_names,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml
);

void
add_layers_with_given_degrees(
    const std::vector<std::vector<size_t>> &in_deg_seq,
    const std::vector<std::vector<size_t>> &out_deg_seq,
    const uu::core::NameIterator &vertices_names,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml
);

}
}

#endif
