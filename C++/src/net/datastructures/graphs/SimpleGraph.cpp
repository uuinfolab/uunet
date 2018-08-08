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
    EdgeDir dir,
    bool allow_loops)
{

    auto vs = std::make_unique<VertexStore>();

    auto es = std::make_unique<SimpleEdgeStore>(dir);

    auto graph = std::make_unique<SimpleGraph>(name, std::move(vs), std::move(es));

    if (!allow_loops)
    {
        // @todo add loop observer
    }

    return graph;
}

}
}

