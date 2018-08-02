/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_SINGLEEDGESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_SINGLEEDGESTORE_H_

#include <unordered_set>
#include "net/datastructures/stores/EdgeStore.h"

namespace uu {
namespace net {


class SimpleEdgeStore :
    public EdgeStore
{

  private:
    typedef EdgeStore super;

  public:

    /**
     * Constructor.
     */

    SimpleEdgeStore(
        EdgeDir dir
    );


    /*static
    std::unique_ptr<SimpleEdgeStore >
    create(
        EdgeDir dir,
           std::unique_ptr<A>& attr
    );*/

    /**
     * Adds a new edge.
     * Multiple edges between the same pair of vertices are not allowed.
     * @param node1 a pointer to the "from" vertex if directed, or to one end of
     * the edge if undirected.
     * @param node2 a pointer to the "to" vertex if directed, or one end of the
     * edge if undirected.
     * @return a pointer to the new edge, or nullptr if the edge already exists.
     **/
    virtual
    const Edge *
    add(
        const Vertex* vertex1,
        const Vertex* vertex2
    );

    /**
     * Adds a new edge.
     * Multiple edges between the same pair of vertices are not allowed.
     * @param node1 a pointer to the "from" vertex if directed, or to one end of
     * the edge if undirected.
     * @param node2 a pointer to the "to" vertex if directed, or one end of the
     * edge if undirected.
     * @return a pointer to the new edge, or nullptr if the edge already exists.
     **/
    virtual
    const Edge *
    add(
        std::shared_ptr<const Edge>  e
    ) override;



    /**
     * Returns an edge.
     * This function can also be used to check if an edge is present.
     * @param node1 a pointer to the "from" actor if directed, or to one end
     * of the edge if undirected.
     * @param node2 a pointer to the "to" actor if directed, or one end
     * of the edge if undirected.
     * @return a pointer to the requested edge, or NULL if it does not exist.
     **/
    const Edge*
    get(
        const Vertex* vertex1,
        const Vertex* vertex2
    ) const;


    using core::SharedPtrSortedRandomSet<const Edge>::add; // @super?
    using super::neighbors;
    using super::is_directed;
    using super::attach;
    using super::summary;

    using super::edge_directionality;
    //using EdgeStore<A>::edges;
    using super::sidx_neighbors_out;
    using super::sidx_neighbors_in;
    using super::sidx_neighbors_all;
    using super::observers;


    virtual
    bool
    erase(
        const Edge * const e
    ) override;


    void
    erase(
        const Vertex * const v
    ) override;

  protected:

    // Indexes to objects (Component IDX):
    std::unordered_map<VertexId, std::unordered_map<VertexId, const Edge*> > cidx_edge_by_vertexes;

};

std::unique_ptr<SimpleEdgeStore>
create_simple_edge_store(EdgeDir dir);

} // namespace net
} // namespace uu

#endif
