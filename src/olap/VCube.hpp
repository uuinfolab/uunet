#ifndef UU_OLAP_VCUBE_H_
#define UU_OLAP_VCUBE_H_

#include <memory>
#include <string>
#include <unordered_map>
#include "olap/MLCube.hpp"
#include "networks/_impl/stores/VertexStore.hpp"

namespace uu {
namespace net {

/**
 * Similar to a vertex store, but updates happen at cell level
 */
class
    VCube
    : public MLCube<VertexStore>
{

private:
    
    typedef MLCube<VertexStore> super;
    
    public:

    VCube(
    );
    
    std::string
    to_string(
    ) const;

    void
    attach(
        core::Observer<const Vertex>* obs
    );

  protected:
    
    virtual
    void
    reset(
    );
    
};



}
}

#endif
