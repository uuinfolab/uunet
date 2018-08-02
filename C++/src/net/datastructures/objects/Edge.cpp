#include "net/datastructures/objects/Edge.h"

namespace uu {
namespace net {


EdgeId
Edge::
max_edge_id = 0;


Edge::
Edge(
    EdgeId id,
    const Vertex* v1,
    const Vertex* v2,
    EdgeDir dir
) :
    Object(id),
    v1(v1),
    v2(v2),
    directionality(dir)
{
}

std::shared_ptr<Edge>
Edge::
create(
    const Vertex* v1,
    const Vertex* v2,
    EdgeDir dir
)
{
    EdgeId eid = ++Edge::max_edge_id;
    return std::make_shared<Edge>(eid,v1,v2,dir);
}


std::string
Edge::
to_string(
) const
{
    switch (directionality)
    {
    case EdgeDir::DIRECTED:
        return "(" + v1->to_string() + " -> " + v2->to_string() + ")";

    case EdgeDir::UNDIRECTED:
        return "(" + v1->to_string() + " -- " + v2->to_string() + ")";
    }

    return ""; // cannot get here
}

} // namespace net
} // namespace uu
