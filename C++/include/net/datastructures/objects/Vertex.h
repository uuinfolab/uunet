/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_OBJECTS_VERTEX_H_
#define UU_NET_DATASTRUCTURES_OBJECTS_VERTEX_H_

#include <string>
#include <memory>
#include "core/datastructures/objects/NamedObject.h"

namespace uu {
namespace net {

/**
 * A vertex in a graph.
 */
class
    Vertex :
    public core::NamedObject,
    public std::enable_shared_from_this<Vertex>
{

  public:

    /** Constructor. */
    Vertex(
        const std::string& name
    );

    static
    std::shared_ptr<const Vertex>
    create(
        const std::string& name
    );

    /** Output function, presenting a complete description of the vertex. */
    std::string
    to_string(
    ) const;

};

} 
}

#endif
