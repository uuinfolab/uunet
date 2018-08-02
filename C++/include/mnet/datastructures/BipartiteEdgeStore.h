/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_BIPARTITEEDGESTORE_H_
#define UU_NET_DATASTRUCTURES_BIPARTITEEDGESTORE_H_

#include <unordered_set>
#include "core/datastructures.h"
#include "core/datastructures/Attributed.h"
#include "net/datastructures/Edge.h"
#include "net/datastructures/EmptyAttributeStore.h"
#include "mnet/datastructures/MultilayerObserver.h"

namespace uu {
namespace net {

template <typename A>
class BipartiteEdgeStore :
    public core::Attributed<A>
{

  protected:

  public:
    /**
     * Constructor.
     */

    BipartiteEdgeStore();

    /**
     * @brief Adds a new edge to the Network.
     * Multiple edges between the same pair of nodes are not allowed.
     * @param node1 a pointer to the "from" vertex if directed, or to one end of
     * the edge if undirected.
     * @param node2 a pointer to the "to" vertex if directed, or one end of the
     * edge if undirected.
     * @return a pointer to the new edge, or NULL if the edge already exists.
     **/
    template <int N0, int N1>
    std::shared_ptr<Edge>
    add(
        const std::shared_ptr<Vertex>& vertex1,
        const std::shared_ptr<Vertex>& vertex2
    );

    template <int N0, int N1>
    std::shared_ptr<Edge>
    get(
        const std::shared_ptr<Vertex>& vertex1,
        const std::shared_ptr<Vertex>& vertex2
    ) const;


    /**
     * @brief Deletes an existing edge.
     * Attribute values associated to this edge are also deleted.
     * @param edge a pointer to the edge to be deleted
     * @return true if the object has been erased, false if it was not present.
     **/
    template <int N0, int N1>
    bool
    erase(
        const std::shared_ptr<Edge>& edge
    );

    /**
     * @brief Returns the nodes with an edge from/to the input node.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return an iterator containing pointers to actors.
     **/
    template <int N0, int N1>
    const
    std::shared_ptr<VertexList>
    neighbors(
        const std::shared_ptr<Vertex>& vertex,
        EdgeMode mode
    ) const;


    void
    attach(
        const std::shared_ptr<MultilayerObserver<Edge> >& observer
    );


    virtual
    std::string
    summary(
    ) const;

  protected:

    std::array<std::array<std::shared_ptr<SimpleEdgeStore<EmptyAttributeStore<Edge> > >,2>,2> edge_stores_;
    std::array<std::shared_ptr<core::Container<Vertex> >,2> vertex_stores_;

    std::vector<std::shared_ptr<MultilayerObserver<Edge> > > observers;
};


template <typename A>
BipartiteEdgeStore<A>::
BipartiteEdgeStore(
    EdgeDir dir
) :
    core::Attributed<A>()
{
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            edge_stores_[i][j] = SimpleEdgeStore<EmptyAttributeStore<Edge> >::create(dir);
        }
    }
}

template <typename A>
std::shared_ptr<BipartiteEdgeStore<A> >
BipartiteEdgeStore<A>::
create(
    EdgeDir dir
)
{
    std::shared_ptr<BipartiteEdgeStore<A> > g;
    g = std::shared_ptr<BipartiteEdgeStore<A> >(new BipartiteEdgeStore(dir));
    return g;
}

template <typename A>
template <int N0, int N1>
std::shared_ptr<Edge>
BipartiteEdgeStore<A>::
add(
    const std::shared_ptr<Vertex>& vertex1,
    const std::shared_ptr<Vertex>& vertex2)
{
    std::shared_ptr<Edge> new_edge = edge_stores_.at(N0).at(N1)->add(vertex1,vertex2);
    // @todo add existing edge to the second store,
    // otherwise get<0,1>(i,j) != get<1,0>(j,i) for und. edges
    edge_stores_.at(N1).at(N0)->add(vertex1,vertex2);

    if (!new_edge)
    {
        std::shared_ptr<Edge> edge = edge_stores_.at(N0).at(N1)->get(vertex1,vertex2);

        for (auto obs: observers)
        {
            obs->notify_add(edge, N0, N1);
        }

    }

    else
    {
        for (auto obs: observers)
        {
            obs->notify_add(new_edge, N0, N1);
        }
    }

    return new_edge;

}

template <typename A>
template <int N0, int N1>
std::shared_ptr<Edge>
BipartiteEdgeStore<A>::
get(
    const std::shared_ptr<Vertex>& vertex1,
    const std::shared_ptr<Vertex>& vertex2
) const
{
    return edge_stores_.at(N0).at(N1)->get(vertex1,vertex2);
}


template <typename A>
template <int N0, int N1>
bool
BipartiteEdgeStore<A>::
erase(
    const std::shared_ptr<Edge>& edge
)
{
    bool res = edge_stores_.at(N0).at(N1)->erase(get<N0,N1>(edge->v1, edge->v2));
    edge_stores_.at(N1).at(N0)->erase(get<N1,N0>(edge->v1, edge->v2));

    for (auto obs: observers)
    {
        obs->notify_erase(edge, N0, N1);
    }

    return res;
}

/*
template <typename A>
void
BipartiteEdgeStore<A>::
    notify_erase(const std::shared_ptr<Vertex>& vertex)
{
    for (std::shared_ptr<Vertex> neighbor: *neighbors(vertex,uu::net::OUT))
    {
        erase(get(vertex,neighbor));
    }

    for (std::shared_ptr<Vertex> neighbor: *neighbors(vertex,uu::net::IN))
    {
        erase(get(neighbor,vertex));
    }
}

template <typename A>
void
BipartiteEdgeStore<A>::notify_add(const std::shared_ptr<Vertex>& vertex)
{
}
*/


template <typename A>
template <int N0, int N1>
const
std::shared_ptr<VertexList>
BipartiteEdgeStore<A>::
neighbors(
    const std::shared_ptr<Vertex>& vertex,
    EdgeMode mode
) const
{
    return edge_stores_.at(N0).at(N1)->neighbors(vertex, mode);
}

template <typename A>
void
BipartiteEdgeStore<A>::
attach(
    const std::shared_ptr<MultilayerObserver<Edge> >& obs
)
{
    observers.push_back(obs);
}


template <typename A>
std::string
BipartiteEdgeStore<A>::
summary(
) const
{
    size_t s = 0;

    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            /*if (i>j && !edge_stores_.at(i).at(j)->is_directed())
            {
                continue;
            }*/

            size_t num_edges_i_j = edge_stores_.at(i).at(j)->get_all()->size();
            s += num_edges_i_j;
        }
    }

    s /= 2;

    std::string summary = std::to_string(s) + " interlayer " + (s==1?"edge":"edges");
    return summary;
}


} // namespace net
} // namespace uu

#endif
