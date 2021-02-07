#include "networks/time.hpp"

namespace uu {
namespace net {

void
make_temporal(
    Network2* net
)
{
    net->edges()->attr()->add("t_", core::AttributeType::TIMESET);
}

void
add_time(
    Network2* net,
    const MLEdge2* edge,
    const core::Time& t
)
{
    net->edges()->attr()->add_time(edge, "t_", t);
}

std::set<core::Time>
get_times(
    const Network2* net,
    const MLEdge2* edge
)
{
    return net->edges()->attr()->get_times(edge, "t_");
}

}
}

