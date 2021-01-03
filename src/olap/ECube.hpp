#ifndef UU_OLAP_ECUBE_H_
#define UU_OLAP_ECUBE_H_

#include <memory>
#include <string>
#include <unordered_map>
#include "networks/_impl/stores/MDSimpleEdgeStore.hpp"
#include "olap/VCube.hpp"
#include "olap/MLCube.hpp"
#include "objects/MLEdge.hpp"

namespace uu {
namespace net {

/**
 * Similar to an edge store, but updates happen at cell level
 */
class
    ECube
    : public MLCube<MDSimpleEdgeStore<VCube>>
{

  private:

    const VCube* vc1;
    const VCube* vc2;

    //std::string name_;
    
    typedef MLCube<MDSimpleEdgeStore<VCube>> super;
    typedef MDSimpleEdgeStore<VCube> EStore;
    typedef MLEdge<Vertex, VCube> IEdge;
    typedef MDSimpleEdgeStore<VCube>* entry_type;
    typedef const IEdge* element_type;

  public:

    // ECube(const std::vector<size_t>& dim);

    ECube(
        //const std::string& name,
        const VCube* vc1,
        const VCube* vc2,
        EdgeDir dir
    );

    /*
    std::unique_ptr<ECube>
    model(
        const std::vector<std::string>& dim,
        const std::vector<std::vector<std::string>>& members
    ) const;
*/

    const MLEdge<Vertex,VCube> *
    add(
        const Vertex* vertex1,
        const VCube* layer1,
        const Vertex* vertex2,
        const VCube* layer2
    );
    
    const MLEdge<Vertex,VCube> *
    add(
        const Vertex* vertex1,
        const Vertex* vertex2
    );
    
    const VCube*
    vcube1(
    ) const;


    const VCube*
    vcube2(
    ) const;


    std::string
    to_string(
    ) const;

    void
    attach(
        core::Observer<const IEdge>* obs
    );

    bool
    is_directed(
    ) const;


  private:

    void
    reset(
          );
    
    /** Edge directionality */
    EdgeDir dir;

};



}
}

#endif
