/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */
#include "mnet/datastructures/graphs/AttributedMultiplexNetwork.h"

namespace uu {
namespace net {

	
	AttributedMultiplexNetwork::
	AttributedMultiplexNetwork(
					 const std::string& name,
					 std::unique_ptr<AttributedVertexStore<Attributes<Vertex, UserDefinedAttrs<Vertex>>>> v,
					 std::unique_ptr<VertexOverlappingLayerStore<AttributedSimpleGraph>> l,
					 std::unique_ptr<EmptyEdgeStore> e
					 ) :
					super(name, std::move(v), std::move(l), std::move(e))
	{
	}
	
std::string
AttributedMultiplexNetwork::
summary(
) const
{
    size_t num_edges = 0;
    for (auto layer: *layers_)
    {
        num_edges += layer->edges()->size();
    }
    std::string summary =
        "MultiplexNetwork (" +
        vertices_->summary() + ", " +
    layers_->summary() + ", " +
    std::to_string(num_edges) + (num_edges==1?" edge)":" edges)");
    return summary;
}


    
std::unique_ptr<AttributedMultiplexNetwork>
create_attributed_multiplex_network(
    const std::string& name
)
{

    using VA = Attributes<Vertex, UserDefinedAttrs<Vertex>>;
    auto v_attr = std::make_unique<VA>();
    auto vs = std::make_unique<AttributedVertexStore<VA>>(std::move(v_attr));

    auto ls = std::make_unique<VertexOverlappingLayerStore<AttributedSimpleGraph>>();
    auto es = std::make_unique<EmptyEdgeStore>();

    // Add observers @todo

    return std::make_unique<AttributedMultiplexNetwork>(name, std::move(vs), std::move(ls), std::move(es));

}

}
}

