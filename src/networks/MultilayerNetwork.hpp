/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_GRAPHS_ATTRIBUTEDHOMOGENEOUSMULTILAYERNETWORK_H_
#define UU_MNET_DATASTRUCTURE_GRAPHS_ATTRIBUTEDHOMOGENEOUSMULTILAYERNETWORK_H_

#include <memory>
#include <string>
#include "networks/_impl/stores/AttrVertexStore.hpp"
#include "networks/_impl/stores/UserDefinedAttrs.hpp"
#include "networks/_impl/stores/Attributed.hpp"
#include "networks/_impl/stores/Attributes.hpp"
#include "objects/Vertex.hpp"
#include "networks/_impl/stores2/GenericSimpleEdgeStore.hpp"
#include "networks/Network.hpp"
#include "networks/_impl/stores/AttributedDynamicInterlayerSimpleEdgeStore.hpp"
#include "networks/_impl/TMultilayerNetwork.hpp"
#include "networks/_impl/stores/VertexOverlappingLayerStore.hpp"

namespace uu {
namespace net {

class
    MultilayerNetwork
    : public TMultilayerNetwork<
      AttrVertexStore,
      VertexOverlappingLayerStore<Network>,
      AttributedDynamicInterlayerSimpleEdgeStore<Vertex,Network,Attributes<InterlayerEdge<Vertex,Network>, UserDefinedAttrs<InterlayerEdge<Vertex,Network>>>>
      >
{

    typedef TMultilayerNetwork<
    AttrVertexStore,
    VertexOverlappingLayerStore<Network>,
    AttributedDynamicInterlayerSimpleEdgeStore<Vertex,Network,Attributes<InterlayerEdge<Vertex,Network>, UserDefinedAttrs<InterlayerEdge<Vertex,Network>>>>
    > super;

  public:

    typedef Network layer_type;
    typedef Vertex vertex_type;

    //using super::super;

    using super::interlayer_edges;

    MultilayerNetwork(
        const std::string& name,
        TMultilayerNetworkType t,

        std::unique_ptr<AttrVertexStore> v,
        std::unique_ptr<VertexOverlappingLayerStore<Network>> l,
        std::unique_ptr<AttributedDynamicInterlayerSimpleEdgeStore<Vertex,Network,Attributes<InterlayerEdge<Vertex,Network>, UserDefinedAttrs<InterlayerEdge<Vertex,Network>>>>> e);

    std::string
    summary(
    ) const;

    bool
    is_ordered() const
    {
        return false;
    }

};

/**
 * Creates a multilayer network.
 */
std::shared_ptr<MultilayerNetwork>
create_shared_attributed_homogeneous_multilayer_network(
    const std::string& name
);

/**
 * Creates a multilayer network.
 */
std::unique_ptr<MultilayerNetwork>
create_attributed_homogeneous_multilayer_network(
    const std::string& name
);



}
}

#endif
