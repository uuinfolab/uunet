#include "objects/MLVertex2.hpp"

#include "core/exceptions/assert_not_null.hpp"

namespace uu {
namespace net {

MLVertex2::
MLVertex2(
    const Vertex* v,
    const VCube* c
) :
    v(v),
    c(c),
    key(v, c)
{
    core::assert_not_null(v, "MLVertex2::constructor", "v");
    core::assert_not_null(c, "MLVertex2::constructor", "c");
}

MLVertex2::
MLVertex2(
) :
    v(nullptr),
    c(nullptr),
    key(v, c)
{
}


bool
MLVertex2::
operator==(
const MLVertex2& mlv
) const
{
    return v == mlv.v && c == mlv.c;
}

bool
MLVertex2::
operator<(
const MLVertex2& mlv
) const
{
    return v < mlv.v || (v == mlv.v && c < mlv.c);
}

bool
MLVertex2::
operator!=(
const MLVertex2& mlv
) const
{
    return v != mlv.v || c != mlv.c;
}

bool
MLVertex2::
operator>(
const MLVertex2& mlv
) const
{
    return v > mlv.v || (v == mlv.v && c > mlv.c);
}


std::string
MLVertex2::
to_string(
) const
{
    return v->to_string() + "@" + c->to_string();
}


std::ostream&
operator<<(std::ostream& os, const MLVertex2& v)
{
    os << v.to_string();
    return os;
}


}
}
