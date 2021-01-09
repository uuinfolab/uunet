#include "objects/MLEdge2.hpp"

#include "core/exceptions/assert_not_null.hpp"

namespace uu {
namespace net {


MLEdge2::
MLEdge2(
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
std::shared_ptr<MLEdge2>
                          MLEdge2::
                          create(
                              const Vertex* v1,
                              const VCube* c1,
                              const Vertex* v2,
                              const VCube* c2,
                              EdgeDir dir
                          )
{
    return std::make_shared<MLEdge2>(v1,c1,v2,c2,dir);
}
*/

std::string
MLEdge2::
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
operator<<(std::ostream& os, const MLEdge2& e)
{
    os << e.to_string();
    return os;
}


}
}

