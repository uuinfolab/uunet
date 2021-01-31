#include "networks/_impl/stores/MDEdgeStore.hpp"

#include "networks/_impl/observers/NoLoopCheckObserver2.hpp"
#include "networks/_impl/observers/CheckVerticesExistObserver.hpp"
#include "networks/_impl/observers/VCubeObserver.hpp"

namespace uu {
namespace net {

MDEdgeStore::
MDEdgeStore(
    VCube* cube1,
    VCube* cube2,
    EdgeDir dir,
    LoopMode loops
) : cube1_(cube1), cube2_(cube2), dir_(dir), loops_(loops)
{

    core::assert_not_null(cube1, "MDEdgeStore", "cube1");
    core::assert_not_null(cube2, "MDEdgeStore", "cube2");

    edges_ = std::make_unique<core::ObjectStore<MLEdge2>>();

    sidx_neighbors_out[cube1][cube2];
    sidx_neighbors_in[cube1][cube2];
    sidx_neighbors_all[cube1][cube2];
    sidx_incident_out[cube1][cube2];
    sidx_incident_in[cube1][cube2];
    sidx_incident_all[cube1][cube2];

    sidx_neighbors_out[cube2][cube1];
    sidx_neighbors_in[cube2][cube1];
    sidx_neighbors_all[cube2][cube1];
    sidx_incident_out[cube2][cube1];
    sidx_incident_in[cube2][cube1];
    sidx_incident_all[cube2][cube1];

    // Register observers to react to updates
    
    // register an observer to check that the end vertices of a newly inserted edge exist
    auto obs1 = std::make_unique<CheckVerticesExistObserver>();
    attach(obs1.get());
    register_observer(std::move(obs1));
    
    // register an observer preventing loops
    if (loops == LoopMode::DISALLOWED)
    {
        auto obs = std::make_unique<NoLoopCheckObserver2>();
        attach(obs.get());
        register_observer(std::move(obs));
    }
}

MDEdgeStore::iterator
        MDEdgeStore::
        begin(
        ) const
{
    return edges_->begin();
}

MDEdgeStore::iterator
MDEdgeStore::
        end(
        ) const
{
    return edges_->end();
}


size_t
MDEdgeStore::
size(
) const
{
    return edges_->size();
}


const MLEdge2 *
MDEdgeStore::
add(
    const Vertex* vertex1,
    const VCube* cube1,
    const Vertex* vertex2,
    const VCube* cube2
)
{
    core::assert_not_null(vertex1, "add", "vertex1");
    core::assert_not_null(cube1, "add", "cube1");
    core::assert_not_null(vertex2, "add", "vertex2");
    core::assert_not_null(cube2, "add", "cube2");

    auto edge = std::make_shared<MLEdge2>(vertex1, cube1, vertex2, cube2, dir_);
    return add(edge);
}


const MLEdge2 *
MDEdgeStore::
add(
    const typename MLEdge2::key_type& key
)
{
    auto edge = std::make_shared<MLEdge2>(std::get<0>(key), std::get<1>(key), std::get<2>(key), std::get<3>(key), dir_);
    return add(edge);
}

const MLEdge2*
MDEdgeStore::
add(
    const MLEdge2* e
)
{
    auto edge = e->shared_from_this();
    return add(edge);
}

const MLEdge2*
MDEdgeStore::
add(
    std::shared_ptr<const MLEdge2> e
)
{
    core::assert_not_null(e.get(), "add", "e");

    if (e->dir != dir_)
    {
        throw core::OperationNotSupportedException("wrong edge directionality");
    }

    const MLEdge2* new_edge;
    if (edges_->add(e))
    {
        new_edge = e.get();
    }
    else
    {
        return nullptr;
    }

    if (sidx_neighbors_out[e->c1][e->c2].count(e->v1)==0)
    {
        sidx_neighbors_out[e->c1][e->c2][e->v1] = std::make_unique<GenericObjectList<Vertex>>();
        sidx_incident_out[e->c1][e->c2][e->v1] = std::make_unique<GenericObjectList<MLEdge2>>();
    }

    sidx_neighbors_out[e->c1][e->c2][e->v1]->add(e->v2);
    sidx_incident_out[e->c1][e->c2][e->v1]->add(new_edge);


    if (sidx_neighbors_in[e->c2][e->c1].count(e->v2)==0)
    {
        sidx_neighbors_in[e->c2][e->c1][e->v2] = std::make_unique<GenericObjectList<Vertex>>();
        sidx_incident_in[e->c2][e->c1][e->v2] = std::make_unique<GenericObjectList<MLEdge2>>();
    }

    sidx_neighbors_in[e->c2][e->c1][e->v2]->add(e->v1);
    sidx_incident_in[e->c2][e->c1][e->v2]->add(new_edge);


    if (sidx_neighbors_all[e->c1][e->c2].count(e->v1)==0)
    {
        sidx_neighbors_all[e->c1][e->c2][e->v1] = std::make_unique<GenericObjectList<Vertex>>();
        sidx_incident_all[e->c1][e->c2][e->v1] = std::make_unique<GenericObjectList<MLEdge2>>();
    }

    sidx_neighbors_all[e->c1][e->c2][e->v1]->add(e->v2);
    sidx_incident_all[e->c1][e->c2][e->v1]->add(new_edge);

    if (sidx_neighbors_all[e->c2][e->c1].count(e->v2)==0)
    {
        sidx_neighbors_all[e->c2][e->c1][e->v2] = std::make_unique<GenericObjectList<Vertex>>();
        sidx_incident_all[e->c2][e->c1][e->v2] = std::make_unique<GenericObjectList<MLEdge2>>();
    }

    sidx_neighbors_all[e->c2][e->c1][e->v2]->add(e->v1);
    sidx_incident_all[e->c2][e->c1][e->v2]->add(new_edge);


    if (e->dir == EdgeDir::UNDIRECTED)
    {

        if (sidx_neighbors_out[e->c2][e->c1].count(e->v2)==0)
        {
            sidx_neighbors_out[e->c2][e->c1][e->v2] = std::make_unique<GenericObjectList<Vertex>>();
            sidx_incident_out[e->c2][e->c1][e->v2] = std::make_unique<GenericObjectList<MLEdge2>>();
        }

        sidx_neighbors_out[e->c2][e->c1][e->v2]->add(e->v1);
        sidx_incident_out[e->c2][e->c1][e->v2]->add(new_edge);

        if (sidx_neighbors_in[e->c1][e->c2].count(e->v1)==0)
        {
            sidx_neighbors_in[e->c1][e->c2][e->v1] = std::make_unique<GenericObjectList<Vertex>>();
            sidx_incident_in[e->c1][e->c2][e->v1] = std::make_unique<GenericObjectList<MLEdge2>>();
        }

        sidx_neighbors_in[e->c1][e->c2][e->v1]->add(e->v2);
        sidx_incident_in[e->c1][e->c2][e->v1]->add(new_edge);

        /*
        if (sidx_neighbors_all[e->c2][e->c1].count(e->v2)==0)
        {
            sidx_neighbors_all[e->c2][e->c1][e->v2] = std::make_unique<GenericObjectList<Vertex>>();
            sidx_incident_all[e->c2][e->c1][e->v2] = std::make_unique<GenericObjectList<MLEdge2>>();
        }

        sidx_neighbors_all[e->c2][e->c1][e->v2]->add(e->v1);
        sidx_incident_all[e->c2][e->c1][e->v2]->add(new_edge);
         */
    }

    return new_edge;
}


bool
MDEdgeStore::
contains(
    const MLEdge2* v
) const
{
    return edges_->contains(v);
}

const MLEdge2*
MDEdgeStore::
at(
    size_t pos
) const
{
    return edges_->at(pos);
}

const MLEdge2*
MDEdgeStore::
get_at_random(
) const
{
    return edges_->get_at_random();
}


int
MDEdgeStore::
index_of(
    const MLEdge2* v
) const
{
    return edges_->index_of(v);
}



/*
GenericObjectList<MLEdge2>*
                                    MDEdgeStore::
                                    get(
                                        const VCube* cube1,
                                        const VCube* cube2
                                    ) const
{
    core::assert_not_null(cube1, "neighbors", "cube1");
    core::assert_not_null(cube2, "neighbors", "cube2");
    return edges_.get();
}
*/

const
GenericObjectList<Vertex>*
MDEdgeStore::
neighbors(
    const Vertex* vertex,
    const VCube* layer,
    EdgeMode mode
) const
{

    core::assert_not_null(layer, "neighbors", "layer");
    core::assert_not_null(vertex, "neighbors", "vertex");

    if (mode==EdgeMode::IN)
    {
        if (sidx_neighbors_in.at(layer).begin()->second.count(vertex)==0)
        {
            return GenericObjectList<Vertex>::empty.get();
        }

        return sidx_neighbors_in.at(layer).begin()->second.at(vertex).get();
    }

    else if (mode==EdgeMode::OUT)
    {
        if (sidx_neighbors_out.at(layer).begin()->second.count(vertex)==0)
        {
            return GenericObjectList<Vertex>::empty.get();
        }

        return sidx_neighbors_out.at(layer).begin()->second.at(vertex).get();
    }

    else if (mode==EdgeMode::INOUT)
    {
        if (sidx_neighbors_all.at(layer).begin()->second.count(vertex)==0)
        {
            return GenericObjectList<Vertex>::empty.get();
        }

        return sidx_neighbors_all.at(layer).begin()->second.at(vertex).get();
    }

    else
    {
        throw core::WrongParameterException("neighborhood mode");
    }
}



const
GenericObjectList<MLEdge2>*
                                      MDEdgeStore::
                                      incident(
                                              const Vertex* vertex,
                                              const VCube* layer,
                                              EdgeMode mode
                                      ) const
{

    core::assert_not_null(layer, "incident", "layer");
    core::assert_not_null(vertex, "incident", "vertex");

    if (mode==EdgeMode::IN)
    {
        if (sidx_incident_in.at(layer).begin()->second.count(vertex)==0)
        {
            return GenericObjectList<MLEdge2>::empty.get();
        }

        return sidx_incident_in.at(layer).begin()->second.at(vertex).get();
    }

    else if (mode==EdgeMode::OUT)
    {
        if (sidx_incident_out.at(layer).begin()->second.count(vertex)==0)
        {
            return GenericObjectList<MLEdge2>::empty.get();
        }

        return sidx_incident_out.at(layer).begin()->second.at(vertex).get();
    }

    else if (mode==EdgeMode::INOUT)
    {
        if (sidx_incident_all.at(layer).begin()->second.count(vertex)==0)
        {
            return GenericObjectList<MLEdge2>::empty.get();
        }

        return sidx_incident_all.at(layer).begin()->second.at(vertex).get();
    }

    else
    {
        throw core::WrongParameterException("neighborhood mode");
    }
}



bool
MDEdgeStore::
is_directed(
) const
{
    return dir_ == EdgeDir::DIRECTED?true:false;
}



/*
void
MDEdgeStore::
set_directed(
const VCube* cube1,
const VCube* cube2,
bool directed
)
{
core::assert_not_null(cube1, "set_directed", "cube1");
core::assert_not_null(cube2, "set_directed", "cube2");

if (edges_.at(cube1).at(cube2)->size() > 0)
{
    throw core::OperationNotSupportedException("cannot change directionality after edges have been inserted");
}

dir_.at(cube1).at(cube2) = directed?EdgeDir::DIRECTED:EdgeDir::UNDIRECTED;
dir_.at(cube2).at(cube1) = directed?EdgeDir::DIRECTED:EdgeDir::UNDIRECTED;
}
*/

// @todo What?...

void
MDEdgeStore::
erase(
const VCube* vcube,
const Vertex* vertex
)
{
    
    core::assert_not_null(vertex, "MDEdgeStore::erase", "MDEdgeStore::vertex");

    std::unordered_set<const MLEdge2*> to_erase;

    for (auto e: *incident(vertex, vcube, EdgeMode::INOUT))
    {
        to_erase.insert(e);
    }

    for (auto e: to_erase)
    {
        erase(e);
    }

}

}
}
