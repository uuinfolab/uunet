/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_OBJECTS_EDGE_H_
#define UU_NET_DATASTRUCTURES_OBJECTS_EDGE_H_

#include <string>
#include <memory>
#include <iostream>
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeDir.h"

namespace uu {
namespace net {

/**
 * An edge between two actors.
 */
class
    Edge :
    public core::Object,
    public std::enable_shared_from_this<Edge>
{

  public:

    /** Constructor. */
    Edge(
        const Vertex* v1,
        const Vertex* v2,
        EdgeDir dir
    );

    static
    std::shared_ptr<Edge>
    create(
        const Vertex* v1,
        const Vertex* v2,
        EdgeDir dir
    );

    /** Output function, presenting a complete description of the edge. */
    std::string
    to_string(
    ) const;

    /** The vertex at the first end of this edge. */
    const Vertex* v1;

    /** The vertex at the second end of this edge. */
    const Vertex* v2;

    /** Edge directionality. */
    const EdgeDir dir;

};


std::ostream&
operator<<(std::ostream& os, const Edge& e);


}
}

#endif
