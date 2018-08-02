/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_MULTILAYERNETWORK_H_
#define UU_MNET_DATASTRUCTURE_MULTILAYERNETWORK_H_

#include <memory>
#include <string>
#include <unordered_set>
#include "core/exceptions/ElementNotFoundException.h"
//#include "core/datastructures/Factory.h"
#include "core/datastructures/observers/Observer.h"
#include "net/datastructures/objects/Edge.h"
#include "net/datastructures/objects/Vertex.h"

namespace uu {
namespace net {

/**
 * MultilayerNetwork is a generic class that can be instantiated into several specific types of network.
 *
 * A MultilayerNetwork is instantiated by specifying a VertexStore (V) and an EdgeStore (E).
 */
template <typename V, typename L, typename E>
class MultilayerNetwork
{

  public:
    /**
     * Creates an empty graph.
     *
     * This is only used internally. Use:
     * - MultilayerNetwork::create() to create a new graph,
     * - an IO function available in the library to read a graph from file, or
     * - a graph generation function to generate a synthetic graph.
     *
     */
    MultilayerNetwork(
        const std::string& name,
        std::unique_ptr<V> v,
        std::unique_ptr<L> l,
        std::unique_ptr<E> e
    );

    /**
     * Creates a new graph and returns a shared pointer to it.
     *
     * This should be used when we want to specify directionality at compilation time.
     *
     static
     std::shared_ptr<MultilayerNetwork<V,L,E>>
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
    L&
    layers(
    );


    /**
     * Returns a pointer to the graph's (const) edge store.
     */
    const L&
    layers(
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

    void
    register_observer(
        std::unique_ptr<core::GenericObserver>
    );

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

    /** Internal layer store. */
    std::unique_ptr<L> layers_;

    /** Internal edge store. */
    std::unique_ptr<E> edges_;

    /** ... */
    std::unordered_set<std::unique_ptr<core::GenericObserver>> obs_;

};



template <typename V, typename L, typename E>
MultilayerNetwork<V,L,E>::
MultilayerNetwork(
    const std::string& name,
    std::unique_ptr<V> v,
    std::unique_ptr<L> l,
    std::unique_ptr<E> e
) : name(name)
{
    vertices_ = std::move(v);
    layers_ = std::move(l);
    edges_ = std::move(e);

    /*
    obs_ = std::make_unique<EdgeVertexObserver<V,V,E>>(vertices_.get(), vertices_.get(), edges_.get());
    vertices_->attach(obs_.get());
    edges_->attach(obs_.get());
     */
}

/*
 template <typename V, typename L, typename E>
 std::shared_ptr<MultilayerNetwork<V,L,E> >
 MultilayerNetwork<V,L,E>::
 create(
 std::unique_ptr<V>& v,
 std::unique_ptr<E>& e
 )
 {
 std::shared_ptr<MultilayerNetwork<V,L,E>> g = std::shared_ptr<MultilayerNetwork<V,L,E>>(new MultilayerNetwork<V,L,E>(v,e));

 // observe
 //g->vertices()->attach(this);
 //g->edges()->attach(this);

 return g;
 }
 */

template <typename V, typename L, typename E>
V&
MultilayerNetwork<V,L,E>::
vertices(
)
{
    return *vertices_.get();
}


template <typename V, typename L, typename E>
const V&
MultilayerNetwork<V,L,E>::
vertices(
) const
{
    return *vertices_.get();
}


template <typename V, typename L, typename E>
E&
MultilayerNetwork<V,L,E>::
edges(
)
{
    return *edges_.get();
}


template <typename V, typename L, typename E>
const E&
MultilayerNetwork<V,L,E>::
edges(
) const
{
    return *edges_.get();
}


template <typename V, typename L, typename E>
L&
MultilayerNetwork<V,L,E>::
layers(
)
{
    return *layers_.get();
}


template <typename V, typename L, typename E>
const L&
MultilayerNetwork<V,L,E>::
layers(
) const
{
    return *layers_.get();
}


template <typename V, typename L, typename E>
void
MultilayerNetwork<V,L,E>::
register_observer(
    std::unique_ptr<core::GenericObserver> obs
)
{
    obs_.insert(std::move(obs));
}

template <typename V, typename L, typename E>
std::string
MultilayerNetwork<V,L,E>::
summary(
) const
{
    std::string summary =
        "MultilayerNetwork (" +
        vertices_->summary() + ", " +
        layers_->summary() + ", " +
        edges_->summary() + ")";
    return summary;
}


} // namespace net
} // namespace uu

#endif
