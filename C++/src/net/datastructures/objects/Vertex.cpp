#include "net/datastructures/objects/Vertex.h"

namespace uu {
namespace net {


VertexId Vertex::max_vertex_id = 0;

Vertex::
Vertex(
    VertexId id,
    const std::string& name
) :
    NamedObject(id,name)
{
}


std::shared_ptr<const Vertex>
Vertex::
create(
    const std::string& name
)
{
    VertexId vid = ++Vertex::max_vertex_id;
    return std::make_shared<const Vertex>(vid, name);
}

std::string
Vertex::
to_string() const
{
    return name;
}

} // namespace mnet
} // namespace uu
