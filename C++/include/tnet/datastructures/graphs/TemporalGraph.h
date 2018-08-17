/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_TNET_DATASTRUCTURE_GRAPHS_TEMPORALGRAPH_H_
#define UU_TNET_DATASTRUCTURE_GRAPHS_TEMPORALGRAPH_H_

#include <memory>
#include <string>
#include "net/datastructures/graphs/Graph.h"
#include "net/datastructures/stores/VertexStore.h"
#include "net/datastructures/stores/AttributedSimpleEdgeStore.h"
#include "net/datastructures/stores/Attributes.h"
#include "tnet/datastructures/stores/Times.h"

namespace uu {
namespace net {

using TemporalGraph =
    Graph<
    VertexStore,
    AttributedSimpleEdgeStore<Attributes<Edge, Times<Edge>>>
    >;

std::unique_ptr<TemporalGraph>
create_temporal_graph(
    const std::string& name,
    EdgeDir dir = EdgeDir::UNDIRECTED,
    bool allow_loops = false
);

}
}

#endif
