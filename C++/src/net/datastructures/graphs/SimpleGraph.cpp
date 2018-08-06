/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */
#include "net/datastructures/graphs/SimpleGraph.h"
#include "net/datastructures/observers/AdjVertexCheckObserver.h"
#include "net/datastructures/observers/PropagateObserver.h"

namespace uu {
namespace net {

std::unique_ptr<SimpleGraph>
create_simple_graph(
    const std::string& name,
                    EdgeDir dir,
                    bool allow_loops)
{

    std::unique_ptr<VertexStore> vs;
    vs = std::make_unique<VertexStore>();

    std::unique_ptr<SimpleEdgeStore> es;
    es = std::make_unique<SimpleEdgeStore>(dir);

    std::unique_ptr<SimpleGraph> graph;
    graph = std::make_unique<SimpleGraph>(name, std::move(vs), std::move(es));

    // register observers
    std::unique_ptr<PropagateObserver<SimpleEdgeStore, const Vertex>> obs1;
    obs1 = std::make_unique<PropagateObserver<SimpleEdgeStore, const Vertex>>(graph->edges());
    graph->vertices()->attach(obs1.get());
    graph->register_observer(std::move(obs1));
    
    std::unique_ptr<AdjVertexCheckObserver<VertexStore>> obs2;
    obs2 = std::make_unique<AdjVertexCheckObserver<VertexStore>>(graph->vertices());
    graph->edges()->attach(obs2.get());
    graph->register_observer(std::move(obs2));
    
    if (!allow_loops)
    {
            // @todo add loop observer
    }
    
    return graph;
}

}
}

