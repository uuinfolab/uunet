/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_EDGESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_EDGESTORE_H_

#include <unordered_set>
#include <unordered_map>
#include "core/datastructures/containers/SharedPtrSortedRandomSet.h"
#include "core/datastructures/containers/Attributed.h"
#include "core/datastructures/observers/Observer.h"
#include "core/datastructures/observers/Subject.h"
#include "net/datastructures/objects/Edge.h"
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeList.h"
#include "net/datastructures/objects/VertexList.h"
#include "core/exceptions/OperationNotSupportedException.h"

namespace uu {
namespace net {

class EdgeStore :
    public core::SharedPtrSortedRandomSet<const Edge>,
    public core::Subject<const Edge>
{

  protected:

    EdgeStore(
        EdgeDir dir
    );


  public:

    virtual
    const Edge *
    add(
        std::shared_ptr<const Edge>  e
    ) override;

    virtual
    bool
    erase(
        Edge const * const e
    ) override = 0;

    /**
     * @brief Deletes all edges adjacent to a vertex.
     * Attribute values associated to this edge are also deleted.
     * @param edge a pointer to the edge to be deleted
     **/
    virtual
    void
    erase(
        const Vertex* v
    ) = 0;


    /**
     * @brief Returns the nodes with an edge from/to the input node.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return an iterator containing pointers to vertexs.
     **/
    const
    VertexList&
    neighbors(
        const Vertex* vertex,
        EdgeMode mode
    ) const;


    bool
    is_directed(
    );

    //using core::Attributed<A>::attributes_;

    virtual
    std::string
    summary(
    ) const;


  protected:

    // largest identifier assigned so far
    //static EdgeId max_edge_id;


    /** Edge directionality */
    EdgeDir edge_directionality;

    /** All edges in this store */
    //std::shared_ptr<EdgeList> edges;

    // Indexes to sets of objects (Set IDX):
    std::unordered_map<VertexId, std::unique_ptr<VertexList>> sidx_neighbors_out;
    std::unordered_map<VertexId, std::unique_ptr<VertexList>> sidx_neighbors_in;
    std::unordered_map<VertexId, std::unique_ptr<VertexList>> sidx_neighbors_all;

};


} // namespace net
} // namespace uu

#endif /* UU_NET_DATASTRUCTURES_COREEDGESTORE_H_ */
