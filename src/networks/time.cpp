#include "networks/time.hpp"

namespace uu {
namespace net {

void
make_temporal(
    Network* net
)
{
    net->edges()->attr()->add("t_", core::AttributeType::TIMESET);
}


bool
is_temporal(
    const Network* net
)
{
    auto attr = net->edges()->attr()->get("t_");

    if (attr->type == core::AttributeType::DOUBLE)
    {
        return true;
    }

    return false;
}


void
add_time(
    Network* net,
    const Edge* edge,
    const core::Time& t
)
{
    net->edges()->attr()->add_time(edge, "t_", t);
}


std::set<core::Time>
get_times(
    const Network* net,
    const Edge* edge
)
{
    return net->edges()->attr()->get_times(edge, "t_");
}


std::array<core::Time, 2>
get_time_bounds(
    const Network* net
)
{
    bool init = false;
    core::Time min;
    core::Time max;

    for (auto edge: *net->edges())
    {
        auto times = get_times(net, edge);

        for (auto time: times)
        {
            if (!init)
            {
                init = true;
                min = time;
                max = time;
            }

            else
            {
                if (time < min)
                {
                    min = time;
                }

                else if (time > max)
                {
                    max = time;
                }
            }
        }
    }

    if (!init)
    {
        std::string err = "cannot return time bounds of network with no associated times";
        throw core::OperationNotSupportedException(err);
    }

    std::array<core::Time, 2> res({min, max});
    return res;
}

}
}

