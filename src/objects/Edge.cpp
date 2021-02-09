#include "objects/Edge.hpp"

#include "core/exceptions/assert_not_null.hpp"

namespace uu {
namespace net {


Edge::
Edge(
    const Vertex* v1,
    const VCube* c1,
    const Vertex* v2,
    const VCube* c2,
    EdgeDir dir
) :
    v1(v1),
    c1(c1),
    v2(v2),
    c2(c2),
    key(std::make_tuple(v1, c1, v2, c2)),
    dir(dir)
{
    core::assert_not_null(v1, "constructor", "v1");
    core::assert_not_null(c1, "constructor", "c1");
    core::assert_not_null(v2, "constructor", "v2");
    core::assert_not_null(c2, "constructor", "c2");
}

/*
std::shared_ptr<Edge>
                          Edge::
                          create(
                              const Vertex* v1,
                              const VCube* c1,
                              const Vertex* v2,
                              const VCube* c2,
                              EdgeDir dir
                          )
{
    return std::make_shared<Edge>(v1,c1,v2,c2,dir);
}
*/

std::string
Edge::
to_string(
) const
{
    switch (dir)
    {
    case EdgeDir::DIRECTED:
        return "(" + v1->to_string() +
               "@" + c1->to_string() +
               " -> " + v2->to_string() +
               "@" + c2->to_string() + ")";

    case EdgeDir::UNDIRECTED:
        return "(" + v1->to_string() +
               "@" + c1->to_string() +
               " -- " + v2->to_string() +
               "@" + c2->to_string() + ")";
    }
}


std::ostream&
operator<<(std::ostream& os, const Edge& e)
{
    os << e.to_string();
    return os;
}


}
}

