#include "net/datastructures/objects/Edge.h"
#include "core/exceptions/NullPtrException.h"

namespace uu {
namespace net {

Edge::
Edge(
    const Vertex* v1,
    const Vertex* v2,
    EdgeDir dir
) :
    v1(v1),
    v2(v2),
    dir(dir)
{
    if (!v1) throw core::NullPtrException("vertex v1 missing during edge creation");
    if (!v2) throw core::NullPtrException("vertex v1 missing during edge creation");
}

std::shared_ptr<Edge>
Edge::
create(
    const Vertex* v1,
    const Vertex* v2,
    EdgeDir dir
)
{
    return std::make_shared<Edge>(v1,v2,dir);
}


std::string
Edge::
to_string(
) const
{
    switch (dir)
    {
    case EdgeDir::DIRECTED:
        return "(" + v1->to_string() + " -> " + v2->to_string() + ")";

    case EdgeDir::UNDIRECTED:
        return "(" + v1->to_string() + " -- " + v2->to_string() + ")";
    }

    return ""; // cannot get here
}

}
} 
