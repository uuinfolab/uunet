#ifndef UU_OLAP_ECUBE_H_
#define UU_OLAP_ECUBE_H_

#include <memory>
#include <string>
#include <unordered_map>
#include "networks/_impl/stores/MDSimpleEdgeStore.hpp"
#include "olap/VCube.hpp"
#include "olap/MLCube.hpp"
#include "objects/MLEdge2.hpp"

namespace uu {
namespace net {

/**
 * Similar to an edge store, but updates happen at cell level
 */
class
    ECube
    : public MLCube<MDSimpleEdgeStore>
{

  private:

    VCube* cube1_;
    VCube* cube2_;

    //std::string name_;
    
    typedef MLCube<MDSimpleEdgeStore> super;
    typedef MDSimpleEdgeStore EStore;
    typedef MDSimpleEdgeStore* entry_type;
    typedef const MLEdge2* element_type;

  public:

    // ECube(const std::vector<size_t>& dim);

    ECube(
        const std::string& name,
        VCube* cube1,
        VCube* cube2,
        EdgeDir dir = EdgeDir::UNDIRECTED,
        LoopMode loops = LoopMode::ALLOWED
    );

    /*
    std::unique_ptr<ECube>
    model(
        const std::vector<std::string>& dim,
        const std::vector<std::vector<std::string>>& members
    ) const;
*/

    const MLEdge2 *
    add(
        const Vertex* vertex1,
        const VCube* cube1,
        const Vertex* vertex2,
        const VCube* cube2
    );
    
    const MLEdge2 *
    add(
        const Vertex* vertex1,
        const Vertex* vertex2
    );
    
    
    /**
     * @brief Returns the nodes with an edge from/to the input vertex.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return the list of neighbors.
     **/
    const
    GenericObjectList<Vertex>*
    neighbors(
        const Vertex* vertex,
        const VCube* cube,
        EdgeMode mode
    ) const;

    /**
     * @brief Returns the nodes with an edge from/to the input vertex.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return the list of neighbors.
     **/
    const
    GenericObjectList<MLEdge2>*
                                          incident(
                                                  const Vertex* vertex,
                                                  const VCube* cube,
                                                  EdgeMode mode
                                          ) const;

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
        core::Observer<const MLEdge2>* obs
    );

    bool
    is_directed(
    ) const;

    void
    erase(
    const VCube* vcube,
    const Vertex* vertex
    );
    
  protected:

    using super::init;
    
    virtual
    MDSimpleEdgeStore*
    init(
        size_t pos
    ) override;
    
     void
     init(
     ) override;

    
    void
    reset(
          ) override;
    
    /** Edge directionality */
    EdgeDir dir_;
    
    /** Loop mode (ALLOWED or DISALLOWED) */
    LoopMode loops_;
    

};



}
}

#endif
