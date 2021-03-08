#ifndef UU_GENERATION_MULTILAYER_CONFIGURATION_MODEL_H
#define UU_GENERATION_MULTILAYER_CONFIGURATION_MODEL_H

#include "networks/MultilayerNetwork.hpp"
#include "generation/configuration_model.hpp"
#include "core/utils/random.hpp"
#include "core/propertymatrix/PropertyMatrix.hpp"
#include "measures/layer.hpp"
#include <algorithm>
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
modify_according_to_jaccard_edge(
    MultilayerNetwork *net,
    const std::vector<double> &j_e,
    double tol=1e-3
);

void
add_layers_with_given_degrees(
    const std::vector<std::vector<size_t>> &deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &actors,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml
);

void
add_layers_with_given_degrees(
    const std::vector<std::vector<size_t>> &in_deg_seq,
    const std::vector<std::vector<size_t>> &out_deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &actors,
    const std::vector<std::string> &layers_names,
    MultilayerNetwork *ml
);

}
}

#endif
