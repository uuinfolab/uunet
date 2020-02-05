/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_OPERATIONS_SUBDIVISION_H_
#define UU_OPERATIONS_SUBDIVISION_H_

#include <string>
#include "objects/Edge.hpp"

namespace uu {
namespace net {

/**
 * Adds a new vertex to the graph subdividing the input edge.
 *
 * e must be an edge in E(g).
 */
template<typename G>
void
edge_subdivision(
    G* g,
    const Edge* e,
    const std::string& vertex_name
);


}
}

#include "subdivision.ipp"

#endif
