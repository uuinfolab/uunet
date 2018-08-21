/**
 * History:
 * - 2018.08.16 file created.
 */

#ifndef UU_PNET_MEASURES_MOSTPROBABLEPATH_H_
#define UU_PNET_MEASURES_MOSTPROBABLEPATH_H_

#include <vector>
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeMode.h"

namespace uu {
namespace net {

/**
 * Returns the most probable path between two vertices of a graph.
 * @param g input graph
 * @param s input source vertex
 * @param d input destination vertex
 * @param mode to select directed/undirected path
 * @return the most probable path from vertex s to vertex d in g
 */
/*
template<typename G>
std::vector<size_t>                                  // data structure for the path?      (type: for later)
most_probable_path(
               const G* g,
    	       const Vertex* s,
    	       const Vertex* d,
               const EdgeMode mode                  // in-out undirected    put this comment in documentation/ put default value
);

*/





/**
 * Returns the probability of the most probable path between two vertices of a graph.
 * @param g input graph
 * @param s input source vertex
 * @param d input destination vertex
 * @param mode to select directed/undirected path
 * @return the most probable path from vertex s to vertex d in g
 */
/*
template<typename G>
size_t
most_probable_path_prob(
               const G* g,
    	       const Vertex* s,
    	       const Vertex* d,
               const EdgeMode mode                                              what should be mode parameter?
);
*/

}
}

#endif
