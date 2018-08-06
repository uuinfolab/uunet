/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "net/datastructures/stores/EdgeStore.h"
#include "core/exceptions/NullPtrException.h"

namespace uu {
namespace net {

EdgeStore::
EdgeStore(
    EdgeDir dir
)
{
    edge_directionality = dir;
}



const Edge *
EdgeStore::
add(
    std::shared_ptr<const Edge> e
)
{
    if (!e.get()) throw core::NullPtrException("edge added to vertex store");
    
    if (e->dir != edge_directionality)
    {
        throw core::OperationNotSupportedException("wrong edge directionality");
    }

    const Edge* new_edge = core::SharedPtrSortedRandomSet<const Edge>::add(e);

    if (!new_edge) // edge already existing
    {
        return nullptr;
    }

    if (sidx_neighbors_out.count(e->v1)==0)
    {
        sidx_neighbors_out[e->v1] = std::make_unique<VertexList>();
    }

    sidx_neighbors_out[e->v1]->add(e->v2);

    if (sidx_neighbors_in.count(e->v2)==0)
    {
        sidx_neighbors_in[e->v2] = std::make_unique<VertexList>();
    }

    sidx_neighbors_in[e->v2]->add(e->v1);

    if (sidx_neighbors_all.count(e->v1)==0)
    {
        sidx_neighbors_all[e->v1] = std::make_unique<VertexList>();
    }

    sidx_neighbors_all[e->v1]->add(e->v2);

    if (sidx_neighbors_all.count(e->v2)==0)
    {
        sidx_neighbors_all[e->v2] = std::make_unique<VertexList>();
    }

    sidx_neighbors_all[e->v2]->add(e->v1);

    return new_edge;
}



const
VertexList&
EdgeStore::
neighbors(
    const Vertex* vertex,
    EdgeMode mode
) const
{
    if (!vertex) throw core::NullPtrException("input vertex, to find its neighbors");
    
    if (mode==EdgeMode::IN)
    {
        if (sidx_neighbors_in.count(vertex)==0)
        {
            return *kEMPTY_VERTEX_LIST;
        }

        return *sidx_neighbors_in.at(vertex);
    }

    else if (mode==EdgeMode::OUT)
    {
        if (sidx_neighbors_out.count(vertex)==0)
        {
            return *kEMPTY_VERTEX_LIST;
        }

        return *sidx_neighbors_out.at(vertex);
    }

    else if (mode==EdgeMode::INOUT)
    {
        if (sidx_neighbors_all.count(vertex)==0)
        {
            return *kEMPTY_VERTEX_LIST;
        }

        return *sidx_neighbors_all.at(vertex);
    }

    else
    {
        throw core::WrongParameterException("neighborhood mode");
    }
}


bool
EdgeStore::
is_directed(
)
{
    return edge_directionality==EdgeDir::DIRECTED?true:false;
}



std::string
EdgeStore::
summary(
) const
{
    size_t s = size();

    std::string summary = std::to_string(s) +
                          (s==1?" edge":" edges");
    return summary;
}

}
}
