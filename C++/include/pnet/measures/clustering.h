/**
 * History:
 * - 2018.08.16 file created.
 */

#ifndef UU_PNET_MEASURES_CLUSTERING_H_
#define UU_PNET_MEASURES_CLUSTERING_H_

#include <vector>
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeMode.h"

namespace uu {
namespace net {

/**
 * Returns the expected clustering coefficient of a vertex in graph. This measure has been introduced in  (J. J. Pfeiffer and J. Neville. Methods to determine node centrality and clustering in graphs with uncertain structure. In 5th International AAAI Conference on Weblogs and Social Media, 2011).
 * @param g input graph
 * @param v input vertex
 * @return the expected clustering coefficient of the vertex in g
 */
template<typename G>
double                                                                         // size_t
expected_clustering_coefficient(
               const G* g,
	       const Vertex* v,

);


/**
 * Returns the distribution of the expected clustering coefficient in graph.
 * @param g input graph
 * @return the the distribution of the expected clustering coefficient in g
 */
/*
template<typename G>
std::vector<double>
expected_clustering_coefficient_distribution(
               const G* g,
	       const Vertex* v,
               //const EdgeMode mode                                             
);
*/







}
}

#endif
