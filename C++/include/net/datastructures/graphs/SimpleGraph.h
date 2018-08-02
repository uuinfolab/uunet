/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURE_GRAPHS_SIMPLEGRAPH_H_
#define UU_NET_DATASTRUCTURE_GRAPHS_SIMPLEGRAPH_H_

#include <memory>
#include <string>
#include "net/datastructures/graphs/Graph.h"
#include "net/datastructures/stores/VertexStore.h"
#include "net/datastructures/stores/SimpleEdgeStore.h"

namespace uu {
namespace net {

using SimpleGraph =
    Graph<
    VertexStore,
    SimpleEdgeStore
    >;

std::unique_ptr<SimpleGraph>
create_simple_graph(
    const std::string& name,
    EdgeDir dir);

}
}

#endif
