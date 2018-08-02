/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "net/datastructures/stores/EdgeStore.h"

namespace uu {
namespace net {

EdgeStore::
EdgeStore(
    EdgeDir dir
)
//:    core::Attributed<A>(std::move(attr))
{
    edge_directionality = dir;

    //auto obs = static_cast<std::shared_ptr<core::Observer<Edge> > >(attributes_);

    //attach(&this->attr());
}



const Edge *
EdgeStore::
add(
    std::shared_ptr<const Edge> e
)
{
    if (e->directionality != edge_directionality)
    {
        throw core::OperationNotSupportedException("wrong edge directionality");
    }

    const Edge* new_edge = core::SharedPtrSortedRandomSet<const Edge>::add(e);

    if (!new_edge) // edge already existing
    {
        return nullptr;
    }

    if (sidx_neighbors_out.count(e->v1->id)==0)
    {
        sidx_neighbors_out[e->v1->id] = std::make_unique<VertexList>();
    }

    sidx_neighbors_out[e->v1->id]->add(e->v2);

    if (sidx_neighbors_in.count(e->v2->id)==0)
    {
        sidx_neighbors_in[e->v2->id] = std::make_unique<VertexList>();
    }

    sidx_neighbors_in[e->v2->id]->add(e->v1);

    if (sidx_neighbors_all.count(e->v1->id)==0)
    {
        sidx_neighbors_all[e->v1->id] = std::make_unique<VertexList>();
    }

    sidx_neighbors_all[e->v1->id]->add(e->v2);

    if (sidx_neighbors_all.count(e->v2->id)==0)
    {
        sidx_neighbors_all[e->v2->id] = std::make_unique<VertexList>();
    }

    sidx_neighbors_all[e->v2->id]->add(e->v1);

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
    if (mode==EdgeMode::IN)
    {
        if (sidx_neighbors_in.count(vertex->id)==0)
        {
            return *empty_vertex_list;
        }

        return *sidx_neighbors_in.at(vertex->id);
    }

    else if (mode==EdgeMode::OUT)
    {
        if (sidx_neighbors_out.count(vertex->id)==0)
        {
            return *empty_vertex_list;
        }

        return *sidx_neighbors_out.at(vertex->id);
    }

    else if (mode==EdgeMode::INOUT)
    {
        if (sidx_neighbors_all.count(vertex->id)==0)
        {
            return *empty_vertex_list;
        }

        return *sidx_neighbors_all.at(vertex->id);
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
                          (s==1?" edge":" edges");// +
    //", " +
    //attributes_->summary();
    return summary;
}

/*

 std::string EdgeStore::to_string() const {
 std::string summary =
 "Network (\"" + name + "\": " +
 std::to_string(get_vertexs()->size()) + " vertexs, " +
 std::to_string(get_all()->size()) + " edges)";
 return summary;
 }

 std::string EdgeStore::to_long_string() const {
 std::string summary =
 "Network (\"" + name + "\": " +
 std::to_string(get_vertexs()->size()) + " vertexs, " +
 std::to_string(get_all()->size()) + " edges)\n";
 int num_attributes = 0;
 std::string attributes = "";
 for (auto a: vertex_attributes_) {
 attributes += "- " + a.first + " (vertex, " + core::to_string(a.second->type()) + ")\n";
 num_attributes++;
 }
 for (auto a: edge_attributes_) {
 attributes += "- " + a.first + " (edge: " + core::to_string(a.second->type()) + ")\n";
 num_attributes++;
 }
 if (num_attributes>0)
 summary = summary + "Attributes:\n" + attributes + "\n";
 return summary;
 }
 */


}
}
