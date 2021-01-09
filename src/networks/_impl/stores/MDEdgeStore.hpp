#ifndef UU_NET_DATASTRUCTURES_STORES_MDEDGESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_MDEDGESTORE_H_

#include <memory>
#include <unordered_map>
#include "core/datastructures/containers/SharedPtrSortedRandomSet.hpp"
#include "core/datastructures/observers/ObserverStore.hpp"
#include "core/datastructures/observers/Subject.hpp"
#include "olap/VCube.hpp"
#include "objects/MLEdge2.hpp"
#include "objects/EdgeDir.hpp"
#include "objects/EdgeMode.hpp"
#include "objects/LoopMode.hpp"
#include "networks/_impl/containers/GenericObjectList.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/exceptions/WrongParameterException.hpp"
#include "core/exceptions/assert_not_null.hpp"

namespace uu {
namespace net {

class
MDEdgeStore
  :
    public core::SharedPtrSortedRandomSet<const MLEdge2>,
    // This makes the store allowing observers which can trigger reactions when the store is updated
    public core::Subject<const MLEdge2>,
    // This allows the edge store to store its own observers
    public core::ObserverStore
{

  private:

    typedef core::SharedPtrSortedRandomSet<const MLEdge2> super;

  protected:

    /** Cube from where vertices at one end of the edges must come from */
    VCube* cube1_;
    /** Cube from where vertices at the other end of the edges must come from */
    VCube* cube2_;
    /** Edge directionality (DIRECTED or UNDIRECTED) */
    EdgeDir dir_;
    /** Loop mode (ALLOWED or DISALLOWED) */
    LoopMode loops_;
    
  public:

    typedef const MLEdge2 value_type;
    typedef std::tuple<const Vertex*, const VCube*, const Vertex*, const VCube*> key_type;

    MDEdgeStore(
        VCube* cube1,
        VCube* cube2,
        EdgeDir dir = EdgeDir::UNDIRECTED,
        LoopMode loops = LoopMode::ALLOWED
    );

  public:

    using super::size;
    using super::add;
    using super::erase;

    virtual
    const MLEdge2*
    add(
        std::shared_ptr<const MLEdge2> e
    ) override;

    /**
     * Adds a new edge.
     * Multiple edges between the same pair of vertices are not allowed.
     * @param vertex1 a pointer to the "from" vertex if directed, or to one end of
     * the edge if undirected.
     * @param vertex2 a pointer to the "to" vertex if directed, or one end of the
     * edge if undirected.
     * @return a pointer to the new edge, or nullptr if the edge already exists.
     **/
    virtual
    const MLEdge2 *
    add(
        const Vertex* vertex1,
        const VCube* cube1,
        const Vertex* vertex2,
        const VCube* cube2
    );

    virtual
    bool
    erase(
        const MLEdge2* e
    ) override = 0;

    /*
        virtual
        GenericObjectList<MLEdge2>*
                                            get(
                                                const VCube* cube1_,
                                                const VCube* cube2_
                                            ) const;
    */

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


    bool
    is_directed(
    ) const;

    /*
        void
        set_directed(
            const VCube* cube1_,
            const VCube* cube2_,
            bool directed
        );
    */

    virtual
    void
    erase(
    const VCube* vcube,
    const Vertex* vertex
    );

  protected:


    /** Edges */
    std::unique_ptr<GenericObjectList<MLEdge2>> edges_;

    // Indexes to sets of objects (Set IDX):
    std::unordered_map<const VCube*, std::unordered_map<const VCube*, std::unordered_map<const Vertex*, std::unique_ptr<GenericObjectList<Vertex>>>>> sidx_neighbors_out;
    std::unordered_map<const VCube*, std::unordered_map<const VCube*, std::unordered_map<const Vertex*, std::unique_ptr<GenericObjectList<Vertex>>>>> sidx_neighbors_in;
    std::unordered_map<const VCube*, std::unordered_map<const VCube*, std::unordered_map<const Vertex*, std::unique_ptr<GenericObjectList<Vertex>>>>> sidx_neighbors_all;

    std::unordered_map<const VCube*, std::unordered_map<const VCube*, std::unordered_map<const Vertex*, std::unique_ptr<GenericObjectList<MLEdge2>>>>> sidx_incident_out;
    std::unordered_map<const VCube*, std::unordered_map<const VCube*, std::unordered_map<const Vertex*, std::unique_ptr<GenericObjectList<MLEdge2>>>>> sidx_incident_in;
    std::unordered_map<const VCube*, std::unordered_map<const VCube*, std::unordered_map<const Vertex*, std::unique_ptr<GenericObjectList<MLEdge2>>>>> sidx_incident_all;
};

}
}

#endif
