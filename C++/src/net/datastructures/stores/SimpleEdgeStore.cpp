/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "net/datastructures/stores/SimpleEdgeStore.h"

namespace uu {
namespace net {



SimpleEdgeStore::
SimpleEdgeStore(
    EdgeDir dir
) :
    EdgeStore(dir)
{
}


const Edge *
SimpleEdgeStore::
add(
    const Vertex* vertex1,
    const Vertex* vertex2
)
{
    // Edge::create will also take care of checking that the pointers are not null
    std::shared_ptr<const Edge> e = Edge::create(vertex1, vertex2, edge_directionality);

    return add(e);
}



const Edge *
SimpleEdgeStore::
add(
    std::shared_ptr<const Edge> e
)
{
    if (!e.get())
    {
        throw core::NullPtrException("edge in add(edge)");
    }

    for (auto obs: observers)
    {
        obs->notify_add(e.get());
    }

    if (get(e->v1, e->v2))
    {
        return nullptr;
    }

    const Edge * new_edge = super::add(e);

    if (!new_edge)
    {
        return nullptr;
    }

    cidx_edge_by_vertexes[e->v1][e->v2] = new_edge;

    if (!is_directed())
    {
        cidx_edge_by_vertexes[e->v2][e->v1] = new_edge;

        if (sidx_neighbors_out.count(e->v2)==0)
        {
            sidx_neighbors_out[e->v2] = std::make_unique<VertexList>();
        }

        sidx_neighbors_out[e->v2]->add(e->v1);

        if (sidx_neighbors_in.count(e->v1)==0)
        {
            sidx_neighbors_in[e->v1] = std::make_unique<VertexList>();
        }

        sidx_neighbors_in[e->v1]->add(e->v2);
    }

    return new_edge;
}



const Edge*
SimpleEdgeStore::
get(
    const Vertex* vertex1,
    const Vertex* vertex2
) const
{
    if (!vertex1)
    {
        throw core::NullPtrException("vertex1 in get(vertex1, vertex2)");
    }

    if (!vertex2)
    {
        throw core::NullPtrException("vertex2 in get(vertex1, vertex2)");
    }

    if (cidx_edge_by_vertexes.count(vertex1)>0 &&
            cidx_edge_by_vertexes.at(vertex1).count(vertex2)>0)
    {
        return cidx_edge_by_vertexes.at(vertex1).at(vertex2);
    }

    else
    {
        return nullptr;
    }
}



bool
SimpleEdgeStore::
erase(
    const Edge* edge
)
{
    if (!edge)
    {
        throw core::NullPtrException("edge in erase(edge)");
    }

    for (auto obs: observers)
    {
        obs->notify_erase(edge);
    }

    cidx_edge_by_vertexes[edge->v1].erase(edge->v2);
    sidx_neighbors_in[edge->v2]->erase(edge->v1);
    sidx_neighbors_out[edge->v1]->erase(edge->v2);

    // if the edge is directed, we erase neighbors only if there isn't
    // an edge in the other direction keeping them neighbors
    if (is_directed())
    {
        if (!get(edge->v2,edge->v1))
        {
            sidx_neighbors_all[edge->v2]->erase(edge->v1);
            sidx_neighbors_all[edge->v1]->erase(edge->v2);
        }
    }

    else
    {
        cidx_edge_by_vertexes[edge->v2].erase(edge->v1);
        sidx_neighbors_in[edge->v1]->erase(edge->v2);
        sidx_neighbors_out[edge->v2]->erase(edge->v1);
        sidx_neighbors_all[edge->v1]->erase(edge->v2);
        sidx_neighbors_all[edge->v2]->erase(edge->v1);
    }

    return core::SharedPtrSortedRandomSet<const Edge>::erase(edge);
}



void
SimpleEdgeStore::
erase(
    const Vertex* vertex
)
{

    if (!vertex)
    {
        throw core::NullPtrException("vertex in erase(vertex) from edge store");
    }

    std::unordered_set<const Edge*> to_erase;

    for (const Vertex* neighbor: neighbors(vertex,EdgeMode::OUT))
    {
        const Edge* e = get(vertex,neighbor);

        to_erase.insert(e);
    }

    for (const Vertex* neighbor: neighbors(vertex,EdgeMode::IN))
    {
        to_erase.insert(get(neighbor,vertex));
    }


    for (auto e: to_erase)
    {
        erase(e);
    }
}


std::string
SimpleEdgeStore::
summary(
) const
{
    size_t s = size();
    std::string summary =
        std::to_string(s) +
        (s==1?" edge":" edges");
    return summary;
}


}
}
