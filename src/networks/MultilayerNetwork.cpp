#include "networks/MultilayerNetwork.hpp"

//#include "networks/_impl/observers/PropagateObserver.hpp"
//#include "networks/_impl/observers/LayerObserver.hpp"
#include "core/utils/pretty_printing.hpp"
//#include "core/olap/operators/slice.hpp"
//#include "olap/_impl/d-extension.hpp"
//#include "olap/_impl/m-extension.hpp"
//#include "networks/_impl/observers/PropagateAddEraseObserver.hpp"

namespace uu {
namespace net {

MultilayerNetwork::
MultilayerNetwork(
    const std::string& name
)
    : name(name)
{

    //std::vector<std::string> dimensions = {};
    //std::vector<std::vector<std::string>> members = {};

    actors_ = std::make_unique<VCube>("A");
    //
    layers_ = std::make_unique<LayerStore>(actors_.get());

    interlayer_edges_ = std::make_unique<MLECubeStore>(layers_.get());

    //actors_->init();
    /*auto vs = std::make_unique<AttrVertexStore>();

    auto ls = std::make_unique<VertexOverlappingLayerStore<Network>>();

    using EA = Attributes<MLEdge<Vertex,Network>, UserDefinedAttrs<MLEdge<Vertex,Network>>>;
    auto e_attr = std::make_unique<EA>();
    auto es = std::make_unique<AttributedDynamicInterlayerSimpleEdgeStore<Vertex,Network,EA>>(std::move(e_attr));

    // @todo missing observer?

    // register an observer to propagate the removal of vertices to the layers
    auto obs1 = std::make_unique<PropagateObserver<VertexOverlappingLayerStore<Network>, const Vertex>>(ls.get());
    vs->attach(obs1.get());

    // register an observer to react to the addition/removal of layers
    auto obs2 = std::make_unique<LayerObserver<AttributedDynamicInterlayerSimpleEdgeStore<Vertex,Network,EA>, Network>>(es.get());
    ls->attach(obs2.get());

    TMultilayerNetworkType t;

    data_ = std::make_unique<TMultilayerNetwork<AttrVertexStore, MLLayerStore, MLSimpleEdgeStore>>(name, t, std::move(vs), std::move(ls), std::move(es));

    data_->register_observer(std::move(obs1));
    data_->register_observer(std::move(obs2));
     */
}

/*
void
MultilayerNetwork::
add_dimension(
    const std::string& name,
    const std::vector<std::string>& members
)
{
    actors_->add_dim(name, members);
    size_t pos = 0;
    for (auto m_name: members)
    {
        // @FIXME for more than 1 dimension
        // @FIXME add string indexing
        std::vector<std::string> s_index = {m_name};
        std::vector<std::vector<size_t>> i_index = {{pos++}};
        std::unique_ptr<VCube> cell = core::vslice(actors_.get(), i_index);

        std::vector<std::string> e_dim = {{name}};
        std::vector<std::vector<std::string>> e_index = {{m_name}};
        intra_edges_[s_index] = std::make_unique<ECube>(cell->vertices(), cell->vertices(),  EdgeDir::UNDIRECTED, e_dim, e_index);

        vertices_[s_index] = std::move(cell);
    }
}
*/

const VCube*
MultilayerNetwork::
actors(
) const
{
    return actors_.get();
}

VCube*
MultilayerNetwork::
actors(
)
{
    return actors_.get();
}

LayerStore*
MultilayerNetwork::
layers(
)
{
    return layers_.get();
}


const LayerStore*
MultilayerNetwork::
layers(
) const
{
    return layers_.get();
}

/*
AttrVertexStore*
MultilayerNetwork::
actors(
)
{
    return data_->vertices();
}


const AttrVertexStore*
MultilayerNetwork::
actors(
) const
{
    return data_->vertices();
}


MLLayerStore*
MultilayerNetwork::
layers(
)
{
    return data_->layers();
}


const MLLayerStore*
MultilayerNetwork::
layers(
) const
{
    return data_->layers();
}


MLSimpleEdgeStore*
MultilayerNetwork::
interlayer_edges(
)
{
    return data_->interlayer_edges();
}


const MLSimpleEdgeStore*
MultilayerNetwork::
interlayer_edges(
) const
{
    return data_->interlayer_edges();
}

std::string
MultilayerNetwork::
summary(
) const
{

    size_t num_intra_edges = 0;

    for (auto layer: *layers())
    {
        num_intra_edges += layer->edges()->size();
    }

    size_t num_inter_edges = interlayer_edges()->size();

    size_t num_actors = actors()->size();

    size_t num_layers = layers()->size();

    size_t num_nodes = 0;

    for (auto layer: *layers())
    {
        num_nodes += layer->vertices()->size();
    }

    size_t num_edges = num_intra_edges + num_inter_edges;

    std::string summary =
        "Multilayer Network [" +
        std::to_string(num_actors) + (num_actors==1?" actor, ":" actors, ") +
        std::to_string(num_layers) + (num_layers==1?" layer, ":" layers, ") +
        std::to_string(num_nodes) + (num_nodes==1?" vertex, ":" vertices, ") +
        std::to_string(num_edges) + (num_edges==1?" edge ":" edges ") +
        "(" + std::to_string(num_intra_edges) + "," +  std::to_string(num_inter_edges) + ")]";
    return summary;
}


bool
MultilayerNetwork::
is_ordered(
) const
{
    return false;
}

bool
MultilayerNetwork::
allows_interlayer_edges(
) const
{
    return false;
}

 */

const MLECubeStore*
MultilayerNetwork::
interlayer_edges(
) const
{

    return interlayer_edges_.get();
}

MLECubeStore*
MultilayerNetwork::
interlayer_edges(
)
{
    return interlayer_edges_.get();
}

/*
ECube*
MultilayerNetwork::
init(
     Network* layer1,
    Network* layer2,
     EdgeDir dir
)
{
    core::assert_not_null(layer1, "MultilayerNetwork::get", "layer1");
    core::assert_not_null(layer2, "MultilayerNetwork::get", "layer2");

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
        throw core::OperationNotSupportedException("cannot create interlayer edges on the same layer");
    }

    auto key = std::make_pair(std::min(layer1, layer2), std::max(layer1, layer2));
    std::string name = layer1->vertices()->name + "-" + layer2->vertices()->name;
    interlayer_edges_[key] = std::make_unique<ECube>(name, layer1->vertices(), layer2->vertices(), dir);
    return interlayer_edges_[key].get();
}
 */

}
}

