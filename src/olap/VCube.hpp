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
    const std::string& name
    );
    
    std::string
    to_string(
    ) const;

    void
    attach(
        core::Observer<const Vertex>* obs
    );
    
    
    template <typename C>
    friend std::unique_ptr<C>
    vslice(
    const std::string& cube_name,
        C* cube,
        const std::vector<std::vector<size_t>>& indexes
           );
    
  protected:
    
    VCube(
    const std::string& cube_name,
        const std::vector<std::string>& dim,
        const std::vector<std::vector<std::string>>& members
    );
    
    using super::init;
    
    VertexStore*
    init(
        size_t pos
    ) override;
    
    void
    init(
    ) override;
    
    virtual
    void
    reset(
    ) override;
    
};



}
}

#endif
