/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_OPERATIONS_CONTRACTION_H_
#define UU_OPERATIONS_CONTRACTION_H_

#include <string>
#include "objects/Edge.hpp"

namespace uu {
namespace net {

/**
 * Removes the two end vertices of the input edge and replaces
 * them with a new single vertex.
 *
 * Multiedges are compacted into a single edge
 *
 * e must be an edge in G.
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
void
edge_contraction(
    G* g,
    const Edge* e,
    const std::string& vertex_name
);


}
}

#include "contraction.ipp"

#endif
