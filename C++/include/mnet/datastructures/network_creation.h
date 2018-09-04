/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_NETWORKCREATION_H_
#define UU_MNET_DATASTRUCTURE_NETWORKCREATION_H_

#include <memory>
#include <string>
#include "mnet/datastructures/network_types.h"
#include "mnet/datastructures/store_creation.h"
#include "mnet/datastructures/UnionVertexStore.h"
//#include "net/datastructures/NoOpObserver.h"

namespace uu {
namespace net {

/**
 * Creates an empty graph.
 *
 * This is only used internally. Use:
 * - Graph::create() to create a new graph,
 * - an IO function available in the library to read a graph from file, or
 * - a graph generation function to generate a synthetic graph.
 *
 */





std::unique_ptr<SimpleUnionVertexStore>
create_simple_union_vertex_store()
{
    using V = UnionVertexStore;

    return std::make_unique<V>();
}


std::unique_ptr<SimpleBipartiteGraph>
create_simple_bipartite_graph(
    const std::string& name
)
{

    using LS = uu::net::VertexDisjointLayerStore<uu::net::SimpleGraph, uu::net::SimpleGraph>;

    std::unique_ptr<uu::net::SimpleGraph> g1 = uu::net::create_simple_graph("P0", uu::net::EdgeDir::DIRECTED);
    std::unique_ptr<uu::net::SimpleGraph> g2 = uu::net::create_simple_graph("P1", uu::net::EdgeDir::DIRECTED);
    //using AV = uu::net::AttributeStore<uu::net::Vertex>;
    //std::unique_ptr<AV> v_attr = std::make_unique<AV>();
    std::unique_ptr<LS> ls;
    ls = std::make_unique<LS>(std::move(g1), std::move(g2));

    std::unique_ptr<SimpleBipartiteGraph> net;

    net = std::make_unique<SimpleBipartiteGraph>(
              name,
              create_simple_union_vertex_store(),
              std::move(ls),
              create_simple_multilayer_edge_store<2>());

    /*
    std::unique_ptr<NoOpObserver<const Vertex>> o1 = std::make_unique<NoOpObserver<const Vertex>>();
    net->vertices().attach(o1.get());
    net->register_observer(std::unique_ptr<core::GenericObserver>(std::move(o1)));
    */

    std::unique_ptr<UnionObserver<const Vertex, SimpleUnionVertexStore>> o1 = std::make_unique<UnionObserver<const Vertex, SimpleUnionVertexStore>>(&net->vertices());
    net->layers().template get<0>()->vertices().attach(o1.get());
    net->layers().template get<1>()->vertices().attach(o1.get());
    net->register_observer(std::unique_ptr<core::GenericObserver>(std::move(o1)));

    return net;
}

} // namespace net
} // namespace uu

#endif
