#ifndef UU_NET_COMMUNITY_GMETANETWORK_H_
#define UU_NET_COMMUNITY_GMETANETWORK_H_

#include <unordered_map>
#include <vector>
#include <memory>
#include "networks/MultiNetwork.hpp"

namespace uu {
namespace net {

class GMetaNetwork
{
  public:

    std::unique_ptr<MultiNetwork> w;
    std::unordered_map<const MLEdge2*, size_t> edge_type;
    std::unordered_map<const MLEdge2*, double> edge_weight;
    size_t order = 0;
    std::unordered_map<const Vertex*, std::set<const Vertex*>> mapping;
    std::unordered_map<const Vertex*, const Vertex*> reverse_mapping;

    GMetaNetwork();

    template <typename VertexIterator>
    const Vertex*
    add(
        VertexIterator begin,
        VertexIterator end
    );


    const Vertex*
    add(
        const Vertex* u
    );


    /* type: -1 (interlayer), n (layer n) */
    const MLEdge2*
    edge(
        const Vertex* u,
        const Vertex* v,
        size_t type,
        double weight = 1.0
    );

    double
    get_weight(
        const MLEdge2*
    ) const;

    size_t
    get_type(
        const MLEdge2*
    ) const;

    const MultiNetwork*
    get(
    ) const;

};

}
}

#include "GMetaNetwork.ipp"

#endif
