#ifndef UU_NETWORKS_TIME_H_
#define UU_NETWORKS_TIME_H_

#include <array>
#include "core/attributes/Time.hpp"
#include "core/attributes/Time.hpp"
#include "networks/Network2.hpp"

namespace uu {
namespace net {

void
make_temporal(
    Network2* net
);

bool
is_temporal(
    const Network2* net
);

void
add_time(
    Network2* net,
    const MLEdge2* edge,
    const core::Time& t
);


std::set<core::Time>
get_times(
    const Network2* net,
    const MLEdge2* edge
);

std::array<core::Time, 2>
get_time_bounds(
    const Network2* net
);

}
}

#endif
