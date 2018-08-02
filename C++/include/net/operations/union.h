/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_OPERATIONS_UNION_H_
#define UU_NET_OPERATIONS_UNION_H_

namespace uu {
namespace net {

/**
 * Returns the union of two graphs.
 *
 * @param g1, g2 input graphs
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
std::shared_ptr<G>
graph_union(
    const std::shared_ptr<const G>& g1,
    const std::shared_ptr<const G>& g2
);


/**
 * Returns the union of two attributed graphs.
 *
 * @param g1, g2 input graphs
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
std::shared_ptr<G>
attributed_graph_union(
    const std::shared_ptr<const G>& g1,
    const std::shared_ptr<const G>& g2
);


} // namespace net
} // namespace uu

#endif
