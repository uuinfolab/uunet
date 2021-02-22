#ifndef UU_GENERATION_MULTILAYER_CONFIGURATION_MODEL_H
#define UU_GENERATION_MULTILAYER_CONFIGURATION_MODEL_H

#include "networks/MultiNetwork.hpp"
#include "core/utils/random.hpp" // drand
#include <algorithm> // std::inner_product, std::transform

namespace uu {
namespace net {

double
pearson_correlated_sequences(
    const std::vector<size_t> &x,
    std::vector<size_t> &y,
    double r,
    double tol=1e-3
);

}
}

#endif
