/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURE_GRAPHS_GRAPH_H_
#define UU_NET_DATASTRUCTURE_GRAPHS_GRAPH_H_

#include <memory>
#include <string>
#include "core/exceptions/ElementNotFoundException.h"
//#include "core/datastructures/Factory.h"
#include "core/datastructures/observers/Observer.h"
#include "net/datastructures/objects/Edge.h"
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/observers/EdgeVertexObserver.h"

namespace uu {
namespace net {

/**
 * Graph is a generic class that can be instantiated into several specific types of network.
 *
 * A Graph is instantiated by specifying a VertexStore (V) and an EdgeStore (E).
 */
template<typename V, typename E>
class Graph
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
     * Creates a new graph and returns a shared pointer to it.
     *
     * This should be used when we want to specify directionality at compilation time.
     *
    static
    std::shared_ptr<Graph<V,E>>
    create(
           std::unique_ptr<V>& v,
           std::unique_ptr<E>& e
    );*/

    /**
     * Returns a pointer to the graph's vertex store.
     */
    V&
    vertices(
    );

    /**
     * Returns a pointer to the graph's (const) vertex store.
     */
    const V&
    vertices(
    ) const;


    /**
     * Returns a pointer to the graph's edge store.
     */
    E&
    edges(
    );


    /**
     * Returns a pointer to the graph's (const) edge store.
     */
    const E&
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

    /** ... */
    std::unique_ptr<EdgeVertexObserver<V,V,E>> obs_;

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

    obs_ = std::make_unique<EdgeVertexObserver<V,V,E>>(vertices_.get(), vertices_.get(), edges_.get());
    vertices_->attach(obs_.get());
    edges_->attach(obs_.get());
}

/*
template<typename V, typename E>
std::shared_ptr<Graph<V,E> >
Graph<V,E>::
create(
   std::unique_ptr<V>& v,
   std::unique_ptr<E>& e
)
{
std::shared_ptr<Graph<V,E>> g = std::shared_ptr<Graph<V,E>>(new Graph<V,E>(v,e));

// observe
//g->vertices()->attach(this);
//g->edges()->attach(this);

return g;
}
*/

template<typename V, typename E>
V&
Graph<V,E>::
vertices(
)
{
    return *vertices_.get();
}


template<typename V, typename E>
const V&
Graph<V,E>::
vertices(
) const
{
    return *vertices_.get();
}


template<typename V, typename E>
E&
Graph<V,E>::
edges(
)
{
    return *edges_.get();
}


template<typename V, typename E>
const E&
Graph<V,E>::
edges(
) const
{
    return *edges_.get();
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


} // namespace net
} // namespace uu

#endif
