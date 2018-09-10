#include "net/datastructures/objects/Vertex.h"

namespace uu {
namespace net {

Vertex::
Vertex(
    const std::string& name
) :
    NamedObject(name)
{
}


std::shared_ptr<const Vertex>
Vertex::
create(
    const std::string& name
)
{
    return std::make_shared<const Vertex>(name);
}

std::string
Vertex::
to_string() const
{
    return name;
}


std::ostream&
operator<<(std::ostream& os, const Vertex& v)
{
    os << v.to_string();
    return os;
}

}
}
