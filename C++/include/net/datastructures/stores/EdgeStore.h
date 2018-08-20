/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_EDGESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_EDGESTORE_H_

#include <unordered_set>
#include <unordered_map>
#include "core/datastructures/containers/SharedPtrSortedRandomSet.h"
#include "core/datastructures/observers/Subject.h"
#include "net/datastructures/objects/Edge.h"
#include "net/datastructures/objects/EdgeMode.h"
#include "net/datastructures/objects/EdgeList.h"
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/VertexList.h"
#include "core/exceptions/OperationNotSupportedException.h"

namespace uu {
namespace net {

/**
 * An Edge Store is a basic class to store edges. It provides functionality shared among
 * different types of edge stores.
 *
 * Once an edge store has been created with a given directionality (DIRECTED or UNDIRECTED),
 * only edges with the same directionality can be added to the store.
 */
class EdgeStore :
    public core::SharedPtrSortedRandomSet<const Edge>,
    public core::Subject<const Edge>
{

  private:
    typedef core::SharedPtrSortedRandomSet<const Edge> super;

  protected:

    EdgeStore(
        EdgeDir dir
    );


  public:

    using super::add;

    virtual
    const Edge *
    add(
        std::shared_ptr<const Edge>  e
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
    const Edge *
    add(
        const Vertex* vertex1,
        const Vertex* vertex2
    ) = 0;

    virtual
    bool
    erase(
        const Edge * const e
    ) override = 0;

    /**
     * Deletes all edges incident to a vertex.
     **/
    virtual
    void
    erase(
        const Vertex* v
    ) = 0;


    /**
     * @brief Returns the nodes with an edge from/to the input vertex.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return the list of neighbors.
     **/
    const
    VertexList*
    neighbors(
        const Vertex* vertex,
        EdgeMode mode
    ) const;

    /**
     * @brief Returns the nodes with an edge from/to the input vertex.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return the list of neighbors.
     **/
    const
    EdgeList*
    incident(
              const Vertex* vertex,
              EdgeMode mode
              ) const;

    
    bool
    is_directed(
    );

    virtual
    std::string
    summary(
    ) const;


  protected:

    /** Edge directionality */
    EdgeDir edge_directionality;

    // Indexes to sets of objects (Set IDX):
    std::unordered_map<const Vertex*, std::unique_ptr<VertexList>> sidx_neighbors_out;
    std::unordered_map<const Vertex*, std::unique_ptr<VertexList>> sidx_neighbors_in;
    std::unordered_map<const Vertex*, std::unique_ptr<VertexList>> sidx_neighbors_all;
    
    std::unordered_map<const Vertex*, std::unique_ptr<EdgeList>> sidx_incident_out;
    std::unordered_map<const Vertex*, std::unique_ptr<EdgeList>> sidx_incident_in;
    std::unordered_map<const Vertex*, std::unique_ptr<EdgeList>> sidx_incident_all;

};


}
}

#endif
