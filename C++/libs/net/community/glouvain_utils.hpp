#ifndef UU_NET_COMMUNITY_GLOUVAINUTILS_H_
#define UU_NET_COMMUNITY_GLOUVAINUTILS_H_

#include <chrono>
#include <unordered_map>
#include <vector>
#include <memory>
#include "net/community/MetaNetwork.hpp"
#include "community/CommunityStructure.hpp"
#include "community/Community.hpp"
#include "objects/EdgeMode.hpp"
#include "objects/Vertex.hpp"
#include "measures/size.hpp"
#include "measures/strength.hpp"
#include "networks/AttributedHomogeneousMultilayerNetwork.hpp"

namespace uu {
namespace net {


std::pair<std::unique_ptr<WeightedNetwork>, std::map<const Vertex*, std::pair<const Vertex*, const Network*>>>
convert(
        const AttributedHomogeneousMultilayerNetwork* g,
        double omega
);

}
}

#endif
