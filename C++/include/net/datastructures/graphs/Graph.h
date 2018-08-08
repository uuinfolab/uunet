/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURE_GRAPHS_GRAPH_H_
#define UU_NET_DATASTRUCTURE_GRAPHS_GRAPH_H_

#include <memory>
#include <string>
#include "core/exceptions/ElementNotFoundException.h"
#include "core/datastructures/observers/ObserverStore.h"
#include "net/datastructures/observers/AdjVertexCheckObserver.h"
#include "net/datastructures/observers/PropagateObserver.h"
//#include "core/datastructures/observers/Subject.h"
//#include "net/datastructures/objects/Edge.h"
//#include "net/datastructures/objects/Vertex.h"

namespace uu {
namespace net {

/**
 * Graph is a generic class that can be instantiated into several specific types of network.
 *
 * A Graph is instantiated specifying a VertexStore (V) and an EdgeStore (E).
 */
template<typename V, typename E>
class Graph
    : public core::ObserverStore
{

  public:

    /**
     * Creates an empty graph.
     *
     * This is only used internally. Use:
     * - Graph::create() to create a new graph,
     * - an IO function available in the library to read a graph from file, or
     * - a graph generation function to generate a synthetic graph.
     *
     */
    Graph(
        const std::string& name,
        std::unique_ptr<V> v,
        std::unique_ptr<E> e
    );

    /**
     * Returns a pointer to the graph's vertex store.
     */
    V*
    vertices(
    );

    /**
     * Returns a pointer to the graph's (const) vertex store.
     */
    const V*
    vertices(
    ) const;


    /**
     * Returns a pointer to the graph's edge store.
     */
    E*
    edges(
    );


    /**
     * Returns a pointer to the graph's (const) edge store.
     */
    const E*
    edges(
    ) const;


    /**
     * Checks if the edges in this graph are directed.
     */
    bool
    is_directed(
    ) const;

    /**
     * Returns a string providing a summary of the graph structure.
     */
    std::string
    summary(
    ) const;

  public:

    const std::string name;

  private:
    /** Internal vertex store. */
    std::unique_ptr<V> vertices_;

    /** Internal edge store. */
    std::unique_ptr<E> edges_;

};



template<typename V, typename E>
Graph<V,E>::
Graph(
    const std::string& name,
    std::unique_ptr<V> v,
    std::unique_ptr<E> e
) : name(name)
{
    vertices_ = std::move(v);
    edges_ = std::move(e);
    
    // register an observer to propagate the removal of vertices to the edge store
    auto obs1 = std::make_unique<PropagateObserver<E, const Vertex>>(edges());
    vertices()->attach(obs1.get());
    register_observer(std::move(obs1));
    
    // register an observer to check that the end vertices of a newly inserted graph exist
    auto obs2 = std::make_unique<AdjVertexCheckObserver<V>>(vertices());
    edges()->attach(obs2.get());
    register_observer(std::move(obs2));
}

template<typename V, typename E>
V*
Graph<V,E>::
vertices(
)
{
    return vertices_.get();
}


template<typename V, typename E>
const V*
Graph<V,E>::
vertices(
) const
{
    return vertices_.get();
}


template<typename V, typename E>
E*
Graph<V,E>::
edges(
)
{
    return edges_.get();
}


template<typename V, typename E>
const E*
Graph<V,E>::
edges(
) const
{
    return edges_.get();
}


template<typename V, typename E>
bool
Graph<V,E>::
is_directed(
) const
{
    return edges_->is_directed();
}


template<typename V, typename E>
std::string
Graph<V,E>::
summary(
) const
{
    std::string summary =
        "Graph (" +
        vertices_->summary() + ", " +
        edges_->summary() + ")";
    return summary;
}


}
}

#endif
