#include "networks/weight.hpp"

#include "core/exceptions/WrongParameterException.hpp"

namespace uu {
namespace net {

void
make_weighted(
    Network2* net
)
{
    net->edges()->attr()->add("w_", core::AttributeType::DOUBLE);
}

void
set_weight(
    Network2* net,
    MLEdge2* edge,
    double p
)
{
    if (p < 0 || p > 1)
    {
        std::string err = "probabilities must be between 0 and 1";
        throw core::WrongParameterException(err);
    }
    net->edges()->attr()->set_double(edge, "w_", p);
}

double
get_weight(
    const Network2* net,
    MLEdge2* edge
)
{
    auto val = net->edges()->attr()->get_double(edge, "w_");
    if (val.null)
    {
        if (net->edges()->contains(edge))
        {
            return 1.0;
        }
        else
        {
            throw core::ElementNotFoundException("edge in network " + net->name);
        }
    }
    return val.value;
}

}
}

