/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_STORETYPES_H_
#define UU_MNET_DATASTRUCTURE_STORETYPES_H_

#include <memory>
#include <string>
#include "net/datastructures/stores/VertexStore.h"
#include "net/datastructures/stores/SimpleEdgeStore.h"
#include "net/datastructures/stores/AttributeStore.h"
#include "mnet/datastructures/UnionVertexStore.h"
#include "mnet/datastructures/MultilayerEdgeStore.h"

namespace uu {
namespace net {

using SimpleUnionVertexStore = UnionVertexStore;

// @todo change Directed
/*
template <size_t N>
using SimpleMultilayerEdgeStore = MultilayerEdgeStore<SimpleEdgeStore, N, EmptyAttributeStore<const Edge>>; */

/*
template<typename V, typename E>
std::string
Graph<V,E>::
summary(
) const
{
    std::string summary =
        "Graph (" +
        vertices_->summary() + ", " +
        edges_->summary() + ")";
    return summary;
}*/


} // namespace net
} // namespace uu

#endif
