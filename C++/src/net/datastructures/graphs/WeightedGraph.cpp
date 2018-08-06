/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */
#include "net/datastructures/graphs/WeightedGraph.h"
#include "net/datastructures/observers/AdjVertexCheckObserver.h"
#include "net/datastructures/observers/PropagateObserver.h"

namespace uu {
namespace net {

std::unique_ptr<WeightedGraph>
create_weighted_graph(
    const std::string& name,
    EdgeDir dir
)
{
    std::unique_ptr<VertexStore> vs;
    vs = std::make_unique<VertexStore>();

    using A = uu::net::Attributes<uu::net::Edge, uu::net::Weights<uu::net::Edge>>;
    std::unique_ptr<A> w_attr;
    w_attr = std::make_unique<A>();
    
    std::unique_ptr<AttributedSimpleEdgeStore<A>> es;
    es = std::make_unique<AttributedSimpleEdgeStore<A>>(dir, std::move(w_attr));

    std::unique_ptr<WeightedGraph> graph;
    graph = std::make_unique<WeightedGraph>(name, std::move(vs), std::move(es));

    // register observers
    std::unique_ptr<PropagateObserver<AttributedSimpleEdgeStore<A>, const Vertex>> obs1;
    obs1 = std::make_unique<PropagateObserver<AttributedSimpleEdgeStore<A>, const Vertex>>(graph->edges());
    graph->vertices()->attach(obs1.get());
    graph->register_observer(std::move(obs1));
    
    std::unique_ptr<AdjVertexCheckObserver<VertexStore>> obs2;
    obs2 = std::make_unique<AdjVertexCheckObserver<VertexStore>>(graph->vertices());
    graph->edges()->attach(obs2.get());
    graph->register_observer(std::move(obs2));
    
    return graph;
}

}
}

