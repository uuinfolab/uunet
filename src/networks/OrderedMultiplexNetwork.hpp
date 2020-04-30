/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_GRAPHS_ATTRIBUTEDORDEREDHOMOGENEOUSMULTILAYERNETWORK_H_
#define UU_MNET_DATASTRUCTURE_GRAPHS_ATTRIBUTEDORDEREDHOMOGENEOUSMULTILAYERNETWORK_H_

#include <memory>
#include <string>
#include "networks/_impl/stores/AttrVertexStore.hpp"
#include "networks/_impl/stores/UserDefinedAttrs.hpp"
#include "networks/_impl/stores/Attributed.hpp"
#include "networks/_impl/stores/Attributes.hpp"
#include "networks/_impl/stores/EmptyEdgeStore.hpp"
#include "objects/Vertex.hpp"
#include "networks/_impl/stores2/GenericSimpleEdgeStore.hpp"
#include "networks/Network.hpp"
#include "networks/_impl/stores/VertexOverlappingOrderedLayerStore.hpp"
#include "networks/_impl/TMultilayerNetwork.hpp"

namespace uu {
namespace net {

class
    OrderedMultiplexNetwork
    : public TMultilayerNetwork<
      AttrVertexStore,
      VertexOverlappingOrderedLayerStore<Network>,
      EmptyEdgeStore
      >
{

    typedef TMultilayerNetwork<
    AttrVertexStore,
    VertexOverlappingOrderedLayerStore<Network>,
    EmptyEdgeStore
    > super;

  public:

    typedef Network layer_type;
    typedef Vertex vertex_type;

    //using super::super;

    using super::interlayer_edges;

    OrderedMultiplexNetwork(
        const std::string& name,
        TMultilayerNetworkType t,

        std::unique_ptr<AttrVertexStore> v,
        std::unique_ptr<VertexOverlappingOrderedLayerStore<Network>> l,
        std::unique_ptr<EmptyEdgeStore> e);

    std::string
    summary(
    ) const;


    bool
    is_ordered() const
    {
        return true;
    }

};

/**
 * Creates a multilayer network.
 */
std::shared_ptr<OrderedMultiplexNetwork>
create_shared_ordered_multiplex_network(
    const std::string& name
);

/**
 * Creates a multilayer network.
 */
std::unique_ptr<OrderedMultiplexNetwork>
create_ordered_multiplex_network(
    const std::string& name
);

}
}

#endif
