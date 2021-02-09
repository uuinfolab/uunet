#ifndef UU_COMMUNITY_OPTIMIZESLICES_H_
#define UU_COMMUNITY_OPTIMIZESLICES_H_

#include "networks/Network.hpp"
#include <vector>

namespace uu {
namespace net {

std::vector<double>
optimize_slices(
    const Network* original_net,
    size_t max_slices);

}
}

#endif
