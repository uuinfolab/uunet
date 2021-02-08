#include "networks/_impl/stores/MDMultiEdgeStore.hpp"

#include "core/exceptions/assert_not_null.hpp"
#include "core/exceptions/ElementNotFoundException.hpp"

namespace uu {
namespace net {


MDMultiEdgeStore::
MDMultiEdgeStore(
    VCube* cube1,
    VCube* cube2,
    EdgeDir dir,
    LoopMode loops
) : super(cube1, cube2, dir, loops) // super will check if they are null
{
    cidx_edges_by_vertices[cube1][cube2];

    if (cube1 != cube2)
    {
        cidx_edges_by_vertices[cube2][cube1];
    }

}

const MLEdge2 *
MDMultiEdgeStore::
add(
    std::shared_ptr<const MLEdge2> e
)
{
    core::assert_not_null(e.get(), "MDMultiEdgeStore::add", "e");

    for (auto obs: observers)
    {
        obs->notify_add(e.get());
    }

    // No need to check for edge existence
    std::cout << "here " << e.get() << std::endl;

    for (auto eg: *edges_)
    {
        std::cout << eg << std::endl;
    }

    auto new_edge = super::add(e);
    std::cout << "new " << new_edge << std::endl;

    if (!new_edge)
    {
        return nullptr;
    }


    /// MULTI SPEC.
    cidx_edges_by_vertices[e->c1][e->c2][e->v1][e->v2].insert(new_edge);

    /// DIR SPECIFIC.

    if (!is_directed())
    {
        cidx_edges_by_vertices[e->c2][e->c1][e->v2][e->v1].insert(new_edge);
    }

    return new_edge;
}

const MLEdge2 *
MDMultiEdgeStore::
add(
    const Vertex* vertex1,
    const Vertex* vertex2
)
{
    if (cube1_ != cube2_)
    {
        std::string err = "ending vertex cubes cannot be inferred and must be specified";
        throw core::OperationNotSupportedException(err);
    }

    return add(vertex1, cube1_, vertex2, cube2_);
}

core::SortedRandomSet<const MLEdge2*>
MDMultiEdgeStore::
get(
    const typename MLEdge2::key_type& key
) const
{
    return get(std::get<0>(key), std::get<1>(key), std::get<2>(key), std::get<3>(key));
}

core::SortedRandomSet<const MLEdge2*>
MDMultiEdgeStore::
get(
    const Vertex* vertex1,
    const VCube* cube1,
    const Vertex* vertex2,
    const VCube* cube2
) const
{

    core::assert_not_null(vertex1, "get", "vertex1");
    core::assert_not_null(cube1, "get", "cube1");
    core::assert_not_null(vertex2, "get", "vertex2");
    core::assert_not_null(cube2, "get", "cube2");

    auto l1 = cidx_edges_by_vertices.find(cube1);

    if (l1 == cidx_edges_by_vertices.end())
    {
        throw core::ElementNotFoundException("Wrong pair of vertex stores");
    }

    auto l2 = l1->second.find(cube2);

    if (l2 == l1->second.end())
    {
        throw core::ElementNotFoundException("Wrong pair of vertex stores");
    }

    core::SortedRandomSet<const MLEdge2*> result;

    auto v1 = l2->second.find(vertex1);

    if (v1 == l2->second.end())
    {
        return result;
    }

    auto v2 = v1->second.find(vertex2);

    if (v2 == v1->second.end())
    {
        return result;
    }

    else
    {
        for (auto edge: v2->second)
        {
            result.add(edge);
        }
    }

    return result;
}


bool
MDMultiEdgeStore::
contains(
    const typename MLEdge2::key_type& key
) const
{
    auto e = get(key);

    if (e.size()>0)
    {
        return true;
    }

    else
    {
        return false;
    }
}


core::SortedRandomSet<const MLEdge2*>
MDMultiEdgeStore::
get(
    const Vertex* vertex1,
    const Vertex* vertex2
) const
{
    if (cube1_ != cube2_)
    {
        std::string err = "ending vertex cubes cannot be inferred and must be specified";
        throw core::OperationNotSupportedException(err);
    }

    return get(vertex1, cube1_, vertex2, cube2_);
}


bool
MDMultiEdgeStore::
erase(
    const MLEdge2* edge
)
{
    core::assert_not_null(edge, "erase", "edge");

    for (auto obs: observers)
    {
        obs->notify_erase(edge);
    }

    //edges_->erase(edge);

    cidx_edges_by_vertices[edge->c1][edge->c2][edge->v1][edge->v2].erase(edge);

    if (cidx_edges_by_vertices[edge->c1][edge->c2][edge->v1][edge->v2].size() ==0)
    {
        sidx_neighbors_in[edge->c2][edge->c1][edge->v2]->erase(edge->v1);
        sidx_neighbors_out[edge->c1][edge->c2][edge->v1]->erase(edge->v2);
        sidx_incident_in[edge->c2][edge->c1][edge->v2]->erase(edge);
        sidx_incident_out[edge->c1][edge->c2][edge->v1]->erase(edge);
    }

    // if the edge is directed, we erase neighbors only if there isn't
    // an edge in the other direction keeping them neighbors
    if (is_directed())
    {

        if (cidx_edges_by_vertices[edge->c2][edge->c1][edge->v2][edge->v1].size() == 0)
        {
            sidx_neighbors_all[edge->c2][edge->c1][edge->v2]->erase(edge->v1);
            sidx_neighbors_all[edge->c1][edge->c2][edge->v1]->erase(edge->v2);
            sidx_incident_all[edge->c2][edge->c1][edge->v2]->erase(edge);
            sidx_incident_all[edge->c1][edge->c2][edge->v1]->erase(edge);
        }
    }

    else
    {

        cidx_edges_by_vertices[edge->c2][edge->c1][edge->v2][edge->v1].erase(edge);

        if (cidx_edges_by_vertices[edge->c1][edge->c2][edge->v1][edge->v2].size()==0)
        {
            sidx_neighbors_in[edge->c1][edge->c2][edge->v1]->erase(edge->v2);
            sidx_neighbors_out[edge->c2][edge->c1][edge->v2]->erase(edge->v1);
            sidx_neighbors_all[edge->c1][edge->c2][edge->v1]->erase(edge->v2);
            sidx_neighbors_all[edge->c2][edge->c1][edge->v2]->erase(edge->v1);
            sidx_incident_in[edge->c1][edge->c2][edge->v1]->erase(edge);
            sidx_incident_out[edge->c2][edge->c1][edge->v2]->erase(edge);
            sidx_incident_all[edge->c1][edge->c2][edge->v1]->erase(edge);
            sidx_incident_all[edge->c2][edge->c1][edge->v2]->erase(edge);
        }
    }


    return edges_->erase(edge);
}

bool
MDMultiEdgeStore::
erase(
    const typename MLEdge2::key_type& key
)
{
    auto edges = get(key);
    bool res = (bool)edges.size();

    for (auto e: edges)
    {
        erase(e);
    }

    return res;
}

/*
        void
    MDMultiEdgeStore::
    erase(
          const Vertex* vertex,
          const VCube* layer
          )
    {
        super::erase(vertex, layer);
    }


    void
MDMultiEdgeStore::
erase(
const MLVertex2* vertex
)
{

    core::assert_not_null(layer, "erase", "layer");
    core::assert_not_null(vertex, "erase", "vertex");

    std::unordered_set<const MLEdge2*> to_erase;

    std::vector<const VCube*> layers = {cube1, cube2};

    for (auto l: layers)
    {
        for (auto neighbor: *neighbors(layer,l,vertex,EdgeMode::OUT))
        {

            auto e = get(vertex,layer,neighbor,l);

            to_erase.insert(e);
        }
    }

    for (auto l: layers)
    {
        for (auto neighbor: *neighbors(layer,l,vertex,EdgeMode::IN))
        {
            auto e = get(neighbor,l,vertex,layer);

            to_erase.insert(e);
        }
    }


    for (auto e: to_erase)
    {
        erase(e);
    }
}*/

/*
void
MDMultiEdgeStore::
erase(
    const VCube* layer
)
{
    super::erase(layer);


    std::vector<const VCube*> layers;

    for (auto&& p: edges_)
    {
        layers.push_back(p.first);
    }

    for (auto l: layers)
    {
        cidx_edge_by_vertexes[l].erase(layer);
    }

    cidx_edge_by_vertexes.erase(layer);
}
*/

}
}
