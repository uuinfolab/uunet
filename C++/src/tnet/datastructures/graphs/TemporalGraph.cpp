/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */
#include "tnet/datastructures/graphs/TemporalGraph.h"
#include "net/datastructures/observers/AdjVertexCheckObserver.h"
#include "net/datastructures/observers/PropagateObserver.h"
#include "net/datastructures/observers/NoLoopCheckObserver.h"

namespace uu {
namespace net {

std::unique_ptr<TemporalGraph>
create_temporal_graph(
    const std::string& name,
    EdgeDir dir,
    bool allows_loops
)
{
    auto vs = std::make_unique<VertexStore>();

    using A = uu::net::Attributes<uu::net::Edge, uu::net::Times<uu::net::Edge>>;
    auto w_attr = std::make_unique<A>();

    auto es = std::make_unique<TemporalMultiEdgeStore>(dir, std::move(w_attr));

    GraphType t;
    t.allows_loops = allows_loops;
    t.allows_multi_edges = true;
    t.is_directed = dir==EdgeDir::DIRECTED ? true : false;
    t.is_temporal = true;

    auto graph = std::make_unique<TemporalGraph>(name, t, std::move(vs), std::move(es));

    if (!allows_loops)
    {
        auto obs = std::make_unique<NoLoopCheckObserver>();
        graph->edges()->attach(obs.get());
        graph->register_observer(std::move(obs));
    }

    return graph;
}

}
}

