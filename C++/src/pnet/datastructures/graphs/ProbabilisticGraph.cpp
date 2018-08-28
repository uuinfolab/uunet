/**
 * History:
 * - 2018.08.17 file created.
 */
#include "pnet/datastructures/graphs/ProbabilisticGraph.h"                                                        
#include "net/datastructures/observers/AdjVertexCheckObserver.h"          
#include "net/datastructures/observers/PropagateObserver.h"
#include "net/datastructures/observers/NoLoopCheckObserver.h"

namespace uu {
namespace net {

std::unique_ptr<ProbabilisticGraph>
create_probabilistic_graph(
    const std::string& name,
    EdgeDir dir,
    bool allows_loops
)
{
    auto vs = std::make_unique<VertexStore>();

    using A = uu::net::Attributes<uu::net::Edge, uu::net::Probabilities<uu::net::Edge>>;                          // uu::net::Weights            to            uu::pnet::Probabilities
    auto p_attr = std::make_unique<A>();                                                                          // w_attr                      to            p_attr

    auto es = std::make_unique<AttributedSimpleEdgeStore<A>>(dir, std::move(p_attr));

    GraphType t;
    t.allows_loops = allows_loops;
    t.is_directed = dir==EdgeDir::DIRECTED ? true : false;
    t.is_probabilistic = true;                                                                                   

    auto graph = std::make_unique<ProbabilisticGraph>(name, t, std::move(vs), std::move(es));

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

