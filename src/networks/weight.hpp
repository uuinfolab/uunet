#ifndef UU_NETWORKS_WEIGHT_H_
#define UU_NETWORKS_WEIGHT_H_

#include "networks/Network2.hpp"

namespace uu {
namespace net {

void
make_weighted(
    Network2* net
);


void
set_weight(
    Network2* net,
    const MLEdge2* edge,
    double p
);

/**
 * Returns the edge probability, or 1.0 if the edge has not been
 * annotated with any probability.
 * throw ElementNotFoundException if the edge does not belong to the network
 */
double
get_weight(
    const Network2* net,
    const MLEdge2* edge
);

}
}

#endif
