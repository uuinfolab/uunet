/**

 */

#include "net/datastructures/stores/MultiEdgeStore.h"

namespace uu {
namespace net {


MultiEdgeStore::
MultiEdgeStore(
    EdgeDir dir
) :
    EdgeStore(
        dir
    )
{
}


const Edge *
MultiEdgeStore::
add(
    const Vertex* vertex1,
    const Vertex* vertex2
)
{

    std::shared_ptr<const Edge> e = Edge::create(vertex1, vertex2, edge_directionality);

    return add(e);
}


const Edge*
MultiEdgeStore::
add(
    std::shared_ptr<const Edge> e
)
{
    for (auto obs: observers)
    {
        obs->notify_add(e.get());
    }

    // No need to check for edge existence

    // EDGE CREATION

    const Edge * new_edge = super::add(e);

    if (!new_edge)
    {
        return nullptr;
    }


    /// MULTI SPEC.
    cidx_edges_by_vertices[e->v1->id][e->v2->id].insert(new_edge);

    /// DIR SPECIFIC.
    if (edge_directionality==EdgeDir::UNDIRECTED)
    {
        cidx_edges_by_vertices[e->v2->id][e->v1->id].insert(new_edge);

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



core::SortedRandomSet<const Edge*>
MultiEdgeStore::
get(
    const Vertex* vertex1,
    const Vertex* vertex2
) const
{
    core::SortedRandomSet<const Edge*> result;

    if (cidx_edges_by_vertices.count(vertex1->id)>0 &&
            cidx_edges_by_vertices.at(vertex1->id).count(vertex2->id)>0)
    {
        auto edges = cidx_edges_by_vertices.at(vertex1->id).at(vertex2->id);

        for (auto edge: edges)
        {
            result.add(edge);
        }

        //return result;
    }

    return result;

}





bool
MultiEdgeStore::
erase(
    const Edge* edge
)
{
    for (auto obs: observers)
    {
        obs->notify_erase(edge);
    }

    cidx_edges_by_vertices[edge->v1->id][edge->v2->id].erase(edge);

    if (cidx_edges_by_vertices[edge->v1->id][edge->v2->id].size()==0)
    {
        sidx_neighbors_in[edge->v2->id]->erase(edge->v1);
        sidx_neighbors_out[edge->v1->id]->erase(edge->v2);
    }

    // if the edge is directed, we erase neighbors only if there isn't
    // any edge in the other direction keeping them neighbors
    if (edge->directionality==EdgeDir::DIRECTED && cidx_edges_by_vertices[edge->v2->id][edge->v1->id].size()==0)
    {
        sidx_neighbors_all[edge->v2->id]->erase(edge->v1);
        sidx_neighbors_all[edge->v1->id]->erase(edge->v2);
    }

    if (edge->directionality==EdgeDir::UNDIRECTED)
    {
        cidx_edges_by_vertices[edge->v2->id][edge->v1->id].erase(edge);

        if (cidx_edges_by_vertices[edge->v1->id][edge->v2->id].size()==0)
        {
            sidx_neighbors_in[edge->v1->id]->erase(edge->v2);
            sidx_neighbors_out[edge->v2->id]->erase(edge->v1);
            sidx_neighbors_all[edge->v1->id]->erase(edge->v2);
            sidx_neighbors_all[edge->v2->id]->erase(edge->v1);
        }
    }

    bool res = core::SharedPtrSortedRandomSet<const Edge>::erase(edge);
    return res;
}


void
MultiEdgeStore::
erase(
    const Vertex* vertex
)
{
    std::unordered_set<const Edge*> to_erase;

    for (const Vertex* neighbor: neighbors(vertex,EdgeMode::OUT))
    {
        auto edges = get(vertex,neighbor);

        for (auto edge: edges)
        {
            to_erase.insert(edge);
        }
    }

    for (const Vertex* neighbor: neighbors(vertex,EdgeMode::IN))
    {
        auto edges = get(neighbor,vertex);

        for (auto edge: edges)
        {
            to_erase.insert(edge);
        }
    }

    for (auto e: to_erase)
    {
        erase(e);
    }
}


std::string
MultiEdgeStore::
summary(
) const
{
    std::string summary = std::to_string(size()) + " multi edges";
    return summary;
}


}
}
