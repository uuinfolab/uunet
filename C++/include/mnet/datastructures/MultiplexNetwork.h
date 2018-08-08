/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_NETWORKTYPES_H_
#define UU_MNET_DATASTRUCTURE_NETWORKTYPES_H_

#include <memory>
#include <string>
#include "net/datastructures/graphs/SimpleGraph.h"
#include "net/datastructures/stores/VertexStore.h"
#include "mnet/datastructures/MultiplexNetwork.h"
#include "mnet/datastructures/MultilayerNetwork.h"
#include "mnet/datastructures/VertexOverlappingLayerStore.h"
#include "mnet/datastructures/VertexDisjointLayerStore.h"
#include "mnet/datastructures/store_types.h"

namespace uu {
namespace net {

/**
 * ....Graph is a generic class that can be instantiated into several specific types of network.
 *
 * A Graph is instantiated by specifying a VertexStore (V) and an EdgeStore (E).
 */
using SimpleMultiplexNetwork =
    MultiplexNetwork<
    VertexStore,
    VertexOverlappingLayerStore<SimpleGraph,AttributeStore<SimpleGraph>>
    >;

using SimpleBipartiteGraph =
    MultilayerNetwork<
    SimpleUnionVertexStore,
    VertexDisjointLayerStore<SimpleGraph, SimpleGraph>,
    SimpleMultilayerEdgeStore<2>
    >;

} // namespace net
} // namespace uu

#endif
