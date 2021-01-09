#ifndef UU_OBJECTS_MLVERTEX2_H_
#define UU_OBJECTS_MLVERTEX2_H_

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include "objects/Vertex.hpp"
#include "olap/VCube.hpp"

namespace uu {
namespace net {

class
    MLVertex2 :
    public core::Object,
    public std::enable_shared_from_this<MLVertex2>
{

  public:

    typedef std::pair<const Vertex*, const VCube*> key_type;

    MLVertex2(
        const Vertex* v,
        const VCube* c
    );

    MLVertex2(
    );

    bool
    operator==(
        const MLVertex2& v
    ) const;
    
    bool
    operator<(
    const MLVertex2& v
    ) const;
    
    bool
    operator!=(
    const MLVertex2& v
    ) const;
    
    bool
    operator>(
    const MLVertex2& v
    ) const;
    
    
    std::string
    to_string(
    ) const;

    const Vertex* v;

    const VCube* c;

    key_type key;

};

std::ostream&
operator<<(std::ostream& os, const MLVertex2& v);

}
}

#endif
