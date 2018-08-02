/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_MEASURES_DEGREE_H_
#define UU_NET_MEASURES_DEGREE_H_

namespace uu {
namespace net {

/**
 * Returns the maximum degree (\Delta) of a graph.
 * @param g input graph
 * @return the degree of the vertex with the maximum degree in g
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
int
maximum_degree(
    const std::shared_ptr<const G> g
);


/**
 * Returns the minimum degree (\delta) of a graph.
 * @param g input graph
 * @return the degree of the vertex with the minimum degree in g
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
int
minimum_degree(
    const std::shared_ptr<const G> g
);

/**
 * Returns the degree sequence of a graph.
 * @param g input graph
 * @return a vector of length n with the ordered sequence of vertex degrees in the g
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
std::vector<int>
degree_sequence(
    const std::shared_ptr<const G> g
);

/**
 * Returns the degree distribution of a graph.
 * @param g input graph
 * @return a vector dd, where dd[i] is the number of vertices having degree i
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
std::vector<int>
degree_distribution(
    const std::shared_ptr<const G> g
);
} // namespace net
} // namespace uu

#endif
