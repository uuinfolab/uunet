#ifndef UU_OBJECTS_MLEDGE2_H_
#define UU_OBJECTS_MLEDGE2_H_

#include <iostream>
#include <memory>
#include <string>
#include <tuple>
#include "objects/EdgeDir.hpp"
#include "objects/Vertex.hpp"
#include "olap/VCube.hpp"
//#include "objects/MLVertex.hpp"

namespace uu {
namespace net {

class
    Edge :
    public core::Object,
    public std::enable_shared_from_this<Edge>
{

  public:

    typedef std::tuple<const Vertex*, const VCube*, const Vertex*, const VCube*> key_type;

    /** Constructor. */
    Edge(
        const Vertex* v1,
        const VCube* c1,
        const Vertex* v2,
        const VCube* c2,
        EdgeDir dir
    );

    /*
    static
    std::shared_ptr<Edge>
                              create(
                                  const Vertex* v1,
                                  const VCube* c1,
                                  const Vertex* v2,
                                  const VCube* c2,
                                  EdgeDir dir
                              );
     */

    std::string
    to_string(
    ) const;

    /** The v at the first end of this edge. */
    const Vertex* v1;

    /** The c at the first end of this edge. */
    const VCube* c1;

    /** The v at the second end of this edge. */
    const Vertex* v2;

    /** The c at the second end of this edge. */
    const VCube* c2;

    const key_type key;

    /** Edge directionality. */
    const EdgeDir dir;

};


std::ostream&
operator<<(std::ostream& os, const Edge& e);


}
}

#endif
