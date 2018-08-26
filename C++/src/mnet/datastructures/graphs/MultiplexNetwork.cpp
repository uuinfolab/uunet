/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */
#include "mnet/datastructures/graphs/MultiplexNetwork.h"

namespace uu {
namespace net {

std::string
MultiplexNetwork::
summary(
) const
{
    std::string summary =
        "MultiplexNetwork (" +
        vertices_->summary() + ", " +
        layers_->summary() + ")";
    return summary;
}

std::unique_ptr<MultiplexNetwork>
create_multiplex_network(
    const std::string& name
)
{

    auto vs = std::make_unique<VertexStore>();
    auto ls = std::make_unique<VertexOverlappingLayerStore<SimpleGraph>>();
    auto es = std::make_unique<EmptyEdgeStore>();

    // Add observers @todo

    return std::make_unique<MultiplexNetwork>(name, std::move(vs), std::move(ls), std::move(es));

}

}
}

