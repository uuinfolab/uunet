#ifndef UU_NET_DATASTRUCTURES_STORES_MDSIMPLEEDGESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_MDSIMPLEEDGESTORE_H_

#include <unordered_set>
#include "networks/_impl/stores/MDEdgeStore.hpp"

namespace uu {
namespace net {


class
    MDSimpleEdgeStore final :
    public MDEdgeStore,
    public std::enable_shared_from_this<MDSimpleEdgeStore>
{
    
    typedef MDEdgeStore super;
    

  public:
    
    
    MDSimpleEdgeStore(
        VCube* cube1,
        VCube* cube2,
        EdgeDir dir,
        LoopMode loops
    );

    using super::super;

    //using super::value_type;

    using super::cube1_;
    using super::cube2_;

    using super::add;
    //using super::get;
    using super::neighbors;
    using super::is_directed;
    using super::attach;
    using super::erase;
    using super::size;
    //using super::summary;

    using super::edges_;
    using super::dir_;
    using super::sidx_neighbors_out;
    using super::sidx_neighbors_in;
    using super::sidx_neighbors_all;
    using super::sidx_incident_out;
    using super::sidx_incident_in;
    using super::sidx_incident_all;
    using super::observers;


    /**
     * Adds a new edge.
     * @param e edge to be added.
     * @return a pointer to the new edge, or nullptr if the edge already exists.
     **/
    virtual
    const MLEdge2*
    add(
        std::shared_ptr<const MLEdge2>  e
    ) override;

    const MLEdge2 *
    add(
        const Vertex* vertex1,
        const Vertex* vertex2
        );
    
    /**
     * Returns an edge.
     * This function can also be used to check if an edge is present.
     * @param vertex1 a pointer to the "from" actor if directed, or to one end
     * of the edge if undirected.
     * @param vertex2 a pointer to the "to" actor if directed, or one end
     * of the edge if undirected.
     * @return a pointer to the requested edge, or nullptr if it does not exist.
     **/
    const MLEdge2*
    get(
        const Vertex* vertex1,
        const VCube* cube1,
        const Vertex* vertex2,
        const VCube* cube2
    ) const;
    
    const MLEdge2*
    get(
        const Vertex* vertex1,
        const Vertex* vertex2
    ) const;



    virtual
    bool
    erase(
        const MLEdge2* e
    ) override;


    /*
    virtual
    void
    add(
        const VCube* layer
    ) override;

    virtual
    void
    erase(
        const VCube* layer
    ) override;



    virtual
    void
    erase(
          const Vertex* vertex,
          const VCube* layer
    );*/


  protected:

    // Indexes to objects (Component IDX):
    std::unordered_map<const VCube*, std::unordered_map<const VCube*, std::unordered_map<const Vertex*, std::unordered_map<const Vertex*, const MLEdge2*>>>> cidx_edge_by_vertexes;
};


}
}

#endif
