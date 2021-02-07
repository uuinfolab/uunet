#ifndef UU_COMMUNITY_OPTIMIZESLICES_H_
#define UU_COMMUNITY_OPTIMIZESLICES_H_

#include "networks/Network2.hpp"
#include <vector>

namespace uu {
namespace net {

std::vector<double>
optimize_slices(
    const Network2* original_net,
    size_t max_slices);

}
}

#endif
