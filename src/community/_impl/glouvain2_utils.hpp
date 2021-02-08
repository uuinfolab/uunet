#ifndef UU_NET_COMMUNITY_GLOUVAINUTILS_H_
#define UU_NET_COMMUNITY_GLOUVAINUTILS_H_

#include <chrono>
#include <unordered_map>
#include <vector>
#include <memory>
#include "community/_impl/GMetaNetwork.hpp"
#include "community/CommunityStructure.hpp"
#include "community/Community.hpp"
#include "objects/EdgeMode.hpp"
#include "objects/Vertex.hpp"
#include "measures/size.hpp"
#include "measures/strength.hpp"
#include "networks/MultilayerNetwork2.hpp"
#include "networks/OrderedMultiplexNetwork2.hpp"

namespace uu {
namespace net {


std::tuple<std::unique_ptr<GMetaNetwork>, std::map<const Vertex*, MLVertex2>, std::vector<std::unique_ptr<const Vertex>>>
convert(
    const MultilayerNetwork2* g,
    double omega
);

std::tuple<std::unique_ptr<GMetaNetwork>, std::map<const Vertex*, MLVertex2>, std::vector<std::unique_ptr<const Vertex>>>
convert(
    const OrderedMultiplexNetwork2* g,
    double omega
);

void
expand(
    const std::vector<std::unique_ptr<GMetaNetwork>>& levels,
    size_t i,
    const Vertex* v,
    Community<const Vertex*>* com
);

std::unique_ptr<CommunityStructure<Network2>>
        communities(
            const std::vector<std::unique_ptr<GMetaNetwork>>& levels
        );

std::unique_ptr<GMetaNetwork>
aggregate(
    const GMetaNetwork* meta,
    std::unordered_map<const Vertex*, size_t> community
);

std::unique_ptr<GMetaNetwork>
pass(
    const GMetaNetwork* meta
);


}
}

#endif
