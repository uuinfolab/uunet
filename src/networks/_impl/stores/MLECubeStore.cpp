#include "networks/_impl/stores/MLECubeStore.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/exceptions/WrongParameterException.hpp"
#include "core/exceptions/assert_not_null.hpp"

namespace uu {
namespace net {



MLECubeStore::
MLECubeStore(
    const LayerStore* layers_
) : layers_(layers_)
{}

size_t
MLECubeStore::
size(
) const
{
    size_t res = 0;

    for (auto&& pair: interlayer_edges_)
    {
        res += pair.second->size();
    }

    return res;
}

const Edge *
MLECubeStore::
add(
    const Vertex* vertex1,
    const Network* layer1,
    const Vertex* vertex2,
    const Network* layer2
)
{
    core::assert_not_null(vertex1, "MLECubeStore::add", "vertex1");
    core::assert_not_null(layer1, "MLECubeStore::add", "layer1");
    core::assert_not_null(vertex2, "MLECubeStore::add", "vertex2");
    core::assert_not_null(layer2, "MLECubeStore::add", "layer2");

    return get(layer1, layer2)->add(vertex1, layer1->vertices(), vertex2, layer2->vertices());
}

const Edge *
MLECubeStore::
get(
    const Vertex* vertex1,
    const Network* layer1,
    const Vertex* vertex2,
    const Network* layer2
)
{
    core::assert_not_null(vertex1, "MLECubeStore::add", "vertex1");
    core::assert_not_null(layer1, "MLECubeStore::add", "layer1");
    core::assert_not_null(vertex2, "MLECubeStore::add", "vertex2");
    core::assert_not_null(layer2, "MLECubeStore::add", "layer2");

    return get(layer1, layer2)->get(vertex1, layer1->vertices(), vertex2, layer2->vertices());
}


const ECube*
MLECubeStore::
get(
    const Network* layer1,
    const Network* layer2
) const
{
    core::assert_not_null(layer1, "MLECubeStore::get", "layer1");
    core::assert_not_null(layer2, "MLECubeStore::get", "layer2");

    if (!layers_->contains(layer1))
    {
        throw core::ElementNotFoundException("layer " + layer1->name);
    }

    if (!layers_->contains(layer2))
    {
        throw core::ElementNotFoundException("layer " + layer2->name);
    }

    auto key = std::make_pair(std::min(layer1, layer2), std::max(layer1, layer2));
    auto f = interlayer_edges_.find(key);

    if (f == interlayer_edges_.end())
    {
        throw core::OperationNotSupportedException("interlayer edges between " + layer1->name + " and " + layer2->name + " not initialized");
    }

    return f->second.get();
}

ECube*
MLECubeStore::
get(
    const Network* layer1,
    const Network* layer2
)
{
    core::assert_not_null(layer1, "MLECubeStore::get", "layer1");
    core::assert_not_null(layer2, "MLECubeStore::get", "layer2");

    if (!layers_->contains(layer1))
    {
        throw core::ElementNotFoundException("layer " + layer1->name);
    }

    if (!layers_->contains(layer2))
    {
        throw core::ElementNotFoundException("layer " + layer2->name);
    }

    auto key = std::make_pair(std::min(layer1, layer2), std::max(layer1, layer2));
    auto f = interlayer_edges_.find(key);

    if (f == interlayer_edges_.end())
    {
        throw core::OperationNotSupportedException("interlayer edges between " + layer1->name + " and " + layer2->name + " not initialized");
    }

    return f->second.get();
}

const
GenericObjectList<Vertex>*
MLECubeStore::
neighbors(
    const Network* layer1,
    const Network* layer2,
    const Vertex* vertex,
    EdgeMode mode
) const
{

    core::assert_not_null(layer1, "MLECubeStore::neighbors", "layer1");
    core::assert_not_null(layer2, "MLECubeStore::neighbors", "layer2");
    core::assert_not_null(vertex, "MLECubeStore::neighbors", "vertex");

    return get(layer1, layer2)->neighbors(vertex, layer1->vertices(), mode);
}



const
GenericObjectList<Edge>*
MLECubeStore::
incident(
    const Network* layer1,
    const Network* layer2,
    const Vertex* vertex,
    EdgeMode mode
) const
{

    core::assert_not_null(layer1, "MLECubeStore::incident", "layer1");
    core::assert_not_null(layer2, "MLECubeStore::incident", "layer2");
    core::assert_not_null(vertex, "MLECubeStore::incident", "vertex");

    return get(layer1, layer2)->incident(vertex, layer1->vertices(), mode);
}



bool
MLECubeStore::
is_directed(
    const Network* layer1,
    const Network* layer2
) const
{
    core::assert_not_null(layer1, "MLECubeStore::is_directed", "layer1");
    core::assert_not_null(layer2, "MLECubeStore::is_directed", "layer2");

    return get(layer1, layer2)->is_directed();
}

ECube*
MLECubeStore::
init(
    Network* layer1,
    Network* layer2,
    EdgeDir dir
)
{
    core::assert_not_null(layer1, "MLECubeStore::set_directed", "layer1");
    core::assert_not_null(layer2, "MLECubeStore::set_directed", "layer2");

    if (!layers_->contains(layer1))
    {
        throw core::ElementNotFoundException("layer " + layer1->name);
    }

    if (!layers_->contains(layer2))
    {
        throw core::ElementNotFoundException("layer " + layer2->name);
    }

    if (layer1 == layer2)
    {
        throw core::OperationNotSupportedException("cannot process interlayer edges on the same layer");
    }

    auto key = std::make_pair(std::min(layer1, layer2), std::max(layer1, layer2));
    std::string name = layer1->vertices()->name + "-" + layer2->vertices()->name;
    interlayer_edges_[key] = std::make_unique<ECube>(name, layer1->vertices(), layer2->vertices(), dir);
    return interlayer_edges_[key].get();
}

void
MLECubeStore::
set_directed(
    const Network* layer1,
    const Network* layer2,
    bool directed
)
{
    (void)layer1;
    (void)layer2;
    (void)directed;
    throw core::OperationNotSupportedException("directionality must be set at init time");

}




void
MLECubeStore::
add(
    const Network* layer
)
{
    core::assert_not_null(layer, "MLECubeStore::add", "layer");

    // @todo
}




void
MLECubeStore::
erase(
    const Network* layer
)
{
    core::assert_not_null(layer, "MLECubeStore::erase", "layer");

    // @todo
}




void
MLECubeStore::
erase(
    const Network* layer,
    const Vertex* vertex
)
{
    core::assert_not_null(layer, "MLECubeStore::erase", "layer");
    core::assert_not_null(vertex, "MLECubeStore::erase", "vertex");

    // @todo
    std::vector<const Network*> layers;

}
}
}
