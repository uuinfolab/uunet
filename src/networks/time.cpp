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

bool
is_temporal(
    const Network2* net
)
{
    auto attr = net->edges()->attr()->get("t_");
    if (attr->type == core::AttributeType::DOUBLE)
        return true;
    return false;
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

