#include "networks/Network.hpp"

//#include "networks/_impl/observers/NoLoopCheckObserver.hpp"
//#include "networks/_impl/observers/VCubeObserver.hpp"

namespace uu {
namespace net {

Network::
Network(
    const std::string& name,
    EdgeDir dir,
    LoopMode loops
)
    : name(name)
{

    /*
    GraphType t;
    t.allows_loops = allows_loops;
    t.is_directed = dir==EdgeDir::DIRECTED ? true : false;
    t.is_weighted = false;
    */
    vertices_ = std::make_unique<VCube>("V");
    //vertices_->add_dimension("V", {"V"});
    edges_ = std::make_unique<ECube>("E", vertices_.get(), vertices_.get(), dir, loops);
    //edges_->add_dimension("E", {"E"});

    /*
    auto obs1 = std::make_unique<VCubeObserver<ECube>>(vertices_.get(), edges_.get());
    vertices_->attach(obs1.get());
    edges_->register_observer(std::move(obs1));

    if (!allows_loops)
    {
        auto obs = std::make_unique<NoLoopCheckObserver>();
        edges_->attach(obs.get());
        data_->register_observer(std::move(obs));
    }*/
}

Network::
Network(
    const std::string& name,
    std::unique_ptr<VCube> vertices,
    std::unique_ptr<ECube> edges
):
    name(name)
{
    core::assert_not_null(vertices.get(), "Network::Network2", "vertices");
    core::assert_not_null(edges.get(), "Network::Network2", "edges");

    if (edges->vcube1() != vertices.get() || edges->vcube2() != vertices.get())
    {
        std::string err = "edges must be defined on the vertices in the network";
        throw core::WrongParameterException(err);
    }

    vertices_ = std::move(vertices);
    edges_ = std::move(edges);

}

VCube*
Network::
vertices(
)
{
    return vertices_.get();
}



const VCube*
Network::
vertices(
) const
{
    return vertices_.get();
}


ECube*
Network::
edges(
)
{
    return edges_.get();
}


const ECube*
Network::
edges(
) const
{
    return edges_.get();
}


bool
Network::
is_directed(
) const
{
    return edges_->is_directed();
}

/*
bool
Network::
is_weighted(
) const
{
    return data_->is_weighted();
}


bool
Network::
is_probabilistic(
) const
{
    return data_->is_probabilistic();
}


bool
Network::
is_temporal(
) const
{
    return data_->is_temporal();
}


bool
Network::
is_attributed(
) const
{
    return data_->is_attributed();
}


bool
Network::
allows_multi_edges(
) const
{
    return data_->allows_multi_edges();
}


 */

bool
Network::
allows_loops(
) const
{
    return edges_->allows_loops();
}

}
}

