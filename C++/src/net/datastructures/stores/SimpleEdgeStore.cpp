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

    std::shared_ptr<const Edge> e = Edge::create(vertex1, vertex2, edge_directionality);

    return add(e);
}



const Edge *
SimpleEdgeStore::
add(
    std::shared_ptr<const Edge> e
)
{

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

    cidx_edge_by_vertexes[e->v1->id][e->v2->id] = new_edge;

    if (!is_directed())
    {
        cidx_edge_by_vertexes[e->v2->id][e->v1->id] = new_edge;

        if (sidx_neighbors_out.count(e->v2->id)==0)
        {
            sidx_neighbors_out[e->v2->id] = std::make_unique<VertexList>();
        }

        sidx_neighbors_out[e->v2->id]->add(e->v1);

        if (sidx_neighbors_in.count(e->v1->id)==0)
        {
            sidx_neighbors_in[e->v1->id] = std::make_unique<VertexList>();
        }

        sidx_neighbors_in[e->v1->id]->add(e->v2);
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
    if (cidx_edge_by_vertexes.count(vertex1->id)>0 &&
            cidx_edge_by_vertexes.at(vertex1->id).count(vertex2->id)>0)
    {
        return cidx_edge_by_vertexes.at(vertex1->id).at(vertex2->id);
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
    for (auto obs: observers)
    {
        obs->notify_erase(edge);
    }

    bool res = core::SharedPtrSortedRandomSet<const Edge>::erase(edge);
    cidx_edge_by_vertexes[edge->v1->id].erase(edge->v2->id);
    sidx_neighbors_in[edge->v2->id]->erase(edge->v1);
    sidx_neighbors_out[edge->v1->id]->erase(edge->v2);

    // if the edge is directed, we erase neighbors only if there isn't
    // an edge in the other direction keeping them neighbors
    if (is_directed())
    {
        if (!get(edge->v2,edge->v1))
        {
            sidx_neighbors_all[edge->v2->id]->erase(edge->v1);
            sidx_neighbors_all[edge->v1->id]->erase(edge->v2);
        }
    }

    else
    {
        cidx_edge_by_vertexes[edge->v2->id].erase(edge->v1->id);
        sidx_neighbors_in[edge->v1->id]->erase(edge->v2);
        sidx_neighbors_out[edge->v2->id]->erase(edge->v1);
        sidx_neighbors_all[edge->v1->id]->erase(edge->v2);
        sidx_neighbors_all[edge->v2->id]->erase(edge->v1);
    }

    return res;
}



void
SimpleEdgeStore::
erase(
    const Vertex* vertex
)
{

    std::unordered_set<const Edge*> to_erase;

    for (const Vertex* neighbor: neighbors(vertex,EdgeMode::OUT))
    {
        const Edge* e = get(vertex,neighbor);
        std::cout << " -> " << e->v1 << ", " << e->v2 << std::endl;
        std::cout << "    " << vertex << " : " << vertex->id << " " << vertex->name << std::endl;

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

std::unique_ptr<SimpleEdgeStore>
create_simple_edge_store(EdgeDir dir)
{
    return std::make_unique<SimpleEdgeStore>(dir);
}

}
}
