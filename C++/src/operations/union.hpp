/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_OPERATIONS_UNION_H_
#define UU_OPERATIONS_UNION_H_

#include <memory>

namespace uu {
namespace net {

/**
 * Computes the union of two graphs.
 *
 * The operation is only allowed if both graphs are directed or both are undirected.
 *
 * Currently attributes are not considered.
 *
 * @param g1, g2 input graphs
 */
template<typename G>
std::unique_ptr<G>
graph_union(
    const G* g1,
    const G* g2,
    const std::string& name = ""
);

/**
 * Adds a graph to another
 *
 * @param g1
 */
template<typename G>
void
graph_add(
    const G* g,
    G* target
);


/**
 * Stores the union of two graphs into a third graph, assigning a weight to edges
 * to indicate in how many input graphs the edge was present.
 *
 * @param g1, g2 input graphs
 */
template<typename G, typename W>
void
weighted_graph_add(
    const G* g,
    W* target);

/**
 * Stores the union of two graphs into a third graph, assigning a weight to edges
 * to indicate in how many input graphs the edge was present.
 *
 * @param g1, g2 input graphs
 */
template<typename GraphIterator, typename W>
void
weighted_graph_union(
    GraphIterator begin,
    GraphIterator end,
    W* target);

/**
 * Stores the union of two graphs into a third graph, assigning a weight to edges
 * to indicate in how many input graphs the edge was present.
 *
 * @param g1, g2 input graphs
 */
template<typename G, typename W>
void
weighted_graph_union(
    const G* g1,
    const G* g2,
    W* target);


/**
 * Stores the union of two graphs into a third graph, assigning a weight to edges
 * to indicate in how many input graphs the edge was present
 *
 * @param g1, g2 input graphs
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
std::unique_ptr<G>
attributed_graph_union(
    const G* g1,
    const G* g2,
    G* target
);


}
}

#include "union.ipp"

#endif