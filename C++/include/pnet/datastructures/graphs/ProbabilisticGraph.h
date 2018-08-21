/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_PNET_DATASTRUCTURE_GRAPHS_PROBABILISTICGRAPH_H_
#define UU_PNET_DATASTRUCTURE_GRAPHS_PROBABILISTICGRAPH_H_

#include <memory>
#include <string>
#include "net/datastructures/graphs/Graph.h"                                          //ok
#include "net/datastructures/stores/VertexStore.h"                                    //ok 
#include "net/datastructures/stores/AttributedSimpleEdgeStore.h"                      //ok
#include "net/datastructures/stores/Attributes.h"                                     //ok
#include "pnet/datastructures/stores/Probabilities.h"                                 // weight to probability

namespace uu {
namespace net {                                                                       // ok

using ProbabilisticGraph =                                                            // ok
    Graph<
    VertexStore,
    AttributedSimpleEdgeStore<Attributes<Edge, Probabilities<Edge>>>                  // ok
    >;

std::unique_ptr<ProbabilisticGraph>
create_probabilistic_graph(
    const std::string& name,
    EdgeDir dir = EdgeDir::UNDIRECTED,
    bool allow_loops = false
);

}
}

#endif
