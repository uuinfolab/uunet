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
    EdgeDir dir,
    bool allow_loops
)
{
    auto vs = std::make_unique<VertexStore>();

    using A = uu::net::Attributes<uu::net::Edge, uu::net::Weights<uu::net::Edge>>;
    auto w_attr = std::make_unique<A>();

    auto es = std::make_unique<AttributedSimpleEdgeStore<A>>(dir, std::move(w_attr));

    auto graph = std::make_unique<WeightedGraph>(name, std::move(vs), std::move(es));


    return graph;
}

}
}

