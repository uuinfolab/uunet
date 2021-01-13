#include "networks/Network2.hpp"

#include "networks/_impl/observers/NoLoopCheckObserver.hpp"
#include "networks/_impl/observers/VCubeObserver.hpp"

namespace uu {
namespace net {

Network2::
Network2(
    const std::string& name,
    EdgeDir dir,
    LoopMode loops)
:
name(name)
{

    /*
    GraphType t;
    t.allows_loops = allows_loops;
    t.is_directed = dir==EdgeDir::DIRECTED ? true : false;
    t.is_weighted = false;
*/
    vertices_ = std::make_unique<VCube>("V");
    vertices_->add_dimension("V", {"V"});
    edges_ = std::make_unique<ECube>("E", vertices_.get(), vertices_.get(), dir, loops);
    edges_->add_dimension("V", {"V"});

    auto obs1 = std::make_unique<VCubeObserver<ECube>>(vertices_.get(), edges_.get());
    vertices_->attach(obs1.get());
    edges_->register_observer(std::move(obs1));
    
    /* @TODO push down to EdgeStore
    if (!allows_loops)
    {
        auto obs = std::make_unique<NoLoopCheckObserver>();
        edges_->attach(obs.get());
        data_->register_observer(std::move(obs));
    }*/
}

Network2::
Network2(
    const std::string& name,
    std::unique_ptr<VCube> vertices,
    std::unique_ptr<ECube> edges
):
name(name)
{
    vertices_ = std::move(vertices);
    edges_ = std::move(edges);
    
    auto obs1 = std::make_unique<VCubeObserver<ECube>>(vertices_.get(), edges_.get());
    vertices_->attach(obs1.get());
    edges_->register_observer(std::move(obs1));
}

VCube*
Network2::
vertices(
)
{
    return vertices_.get();
}



const VCube*
Network2::
vertices(
) const
{
    return vertices_.get();
}


ECube*
Network2::
edges(
)
{
    return edges_.get();
}


const ECube*
Network2::
edges(
) const
{
    return edges_.get();
}


bool
Network2::
is_directed(
) const
{
    return edges_->is_directed();
}

/*
bool
Network2::
is_weighted(
) const
{
    return data_->is_weighted();
}


bool
Network2::
is_probabilistic(
) const
{
    return data_->is_probabilistic();
}


bool
Network2::
is_temporal(
) const
{
    return data_->is_temporal();
}


bool
Network2::
is_attributed(
) const
{
    return data_->is_attributed();
}


bool
Network2::
allows_multi_edges(
) const
{
    return data_->allows_multi_edges();
}


 */

bool
Network2::
allows_loops(
) const
{
    return edges_->allows_loops();
}

}
}
