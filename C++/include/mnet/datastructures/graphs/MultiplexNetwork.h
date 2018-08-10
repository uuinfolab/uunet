/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_GRAPHS_MULTIPLEXNETWORK_H_
#define UU_MNET_DATASTRUCTURE_GRAPHS_MULTIPLEXNETWORK_H_

#include <memory>
#include <string>
#include "net/datastructures/graphs/SimpleGraph.h"
#include "net/datastructures/stores/VertexStore.h"
#include "net/datastructures/stores/EmptyEdgeStore.h"
#include "mnet/datastructures/MultilayerNetwork.h"
#include "mnet/datastructures/VertexOverlappingLayerStore.h"

namespace uu {
namespace net {

/**
 *
 */
using MultiplexNetwork =
    MultilayerNetwork<
    VertexStore,
    VertexOverlappingLayerStore<SimpleGraph>
    EmptyEdgeStore
    >;

}
}

#endif
