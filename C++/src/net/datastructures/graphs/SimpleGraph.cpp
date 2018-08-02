/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */
#include "net/datastructures/graphs/SimpleGraph.h"

namespace uu {
namespace net {

std::unique_ptr<SimpleGraph>
create_simple_graph(
    const std::string& name,
    EdgeDir dir
)
{

    std::unique_ptr<VertexStore> vs;
    vs = create_vertex_store();

    std::unique_ptr<SimpleEdgeStore> es;
    es = create_simple_edge_store(dir);

    std::unique_ptr<SimpleGraph> graph;
    graph = std::make_unique<SimpleGraph>(name, std::move(vs), std::move(es));

    return graph;
}

} // namespace net
} // namespace uu

