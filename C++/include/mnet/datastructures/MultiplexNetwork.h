/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_MULTIPLEXNETWORK_H_
#define UU_MNET_DATASTRUCTURE_MULTIPLEXNETWORK_H_

#include <array>
#include <memory>
#include <string>
#include "core/exceptions/ElementNotFoundException.h"
#include "core/exceptions/WrongParameterException.h"
#include "net/datastructures/objects/Edge.h"
#include "net/datastructures/objects/Vertex.h"
#include "core/datastructures/observers/Observer.h"
//#include "mnet/datastructures/LayerObserver.h"
//#include "mnet/datastructures/MultilayerObserver.h"

namespace uu {
namespace net {

/**
 */
template<typename V, typename L>
class MultiplexNetwork :
    public core::Observer<const Vertex>//,
//public LayerObserver<Vertex>
{

  public:

    /**
     * Creates an empty multiplex network.
     *
     * This is only used internally. Use:
     * - MultiplexNetwork::create() to create a new graph,
     * - an IO function available in the library to read a multiplex network from file, or
     * - a multiplex network generation function to generate a synthetic graph.
     *
     * @param name name of the new multiplex network
     */
    MultiplexNetwork(
        const std::string& name,
        std::unique_ptr<V> v,
        std::unique_ptr<L> l
    );


    /** Name of the graph. */
    //const std::string name;

    /**
     * Creates a new graph and returns a shared pointer to it.
     *
     * @param name name of the new graph
     *
    static
    std::shared_ptr<MultiplexNetwork<V, L> >
    create(
        //const std::string& name
    );*/


    /**
     * Returns a pointer to the graph's vertex store.
     */
    V&
    vertices(
    );


    /**
     * Returns a const pointer to the graph's vertex store.
     */
    const V&
    vertices(
    ) const;

    /**
     * Returns a pointer to the graph's layer store.
     */
    L&
    layers(
    );


    /**
     * Returns a const pointer to the graph's layer store.
     */
    const L&
    layers(
    ) const;

    void
    notify_add(
        const Vertex* v
    ) override;

    void
    notify_erase(
        const Vertex* v
    ) override;

    /*
    void
    notify_add(
        const Vertex* v,
        size_t layer

    ) override;

    void
    notify_erase(
        const Vertex* v,
        size_t layer
    ) override;
    */

    /*
     void
     notify_add(
     const std::shared_ptr<Edge>& e,
     size_t layer1,
     size_t layer2
     ) override;

     void
     notify_erase(
     const std::shared_ptr<Edge>& e,
     size_t layer1,
     size_t layer2
     ) override;
     */

    /**
     * Returns a string providing a summary of the graph structure.
     */
    std::string
    summary(
    ) const;


  private:

    const std::string name;

    /** Internal vertex store. */
    std::unique_ptr<V> vertices_;

    /** Internal layer store. */
    std::unique_ptr<L > layers_;

};



template<typename V, typename L>
MultiplexNetwork<V, L>::
MultiplexNetwork(
    const std::string& name,
    std::unique_ptr<V> v,
    std::unique_ptr<L> l
    //const std::string& name
)
    : name(name)
{

    vertices_ = std::move(v);
    vertices_->attach(this);
    layers_ = std::move(l);
    layers_->attach(this);
}

/*
template<typename V, typename L>
std::shared_ptr<MultiplexNetwork<V, L> >
MultiplexNetwork<V, L>::
create(
    const std::string& name
)
{
    std::shared_ptr<MultiplexNetwork<V, L> > g;
    g = std::shared_ptr<MultiplexNetwork<V, L> >(new MultiplexNetwork<V, L>());
    /*
     auto v_obs = static_cast<std::shared_ptr<LayerObserver<Vertex> > >(g);
     g->layers()->attach(v_obs);
     auto e_obs = static_cast<std::shared_ptr<MultilayerObserver<Edge> > >(g);
     g->interlayer_edges()->attach(e_obs);

    return g;
}
*/

template<typename V, typename L>
std::string
MultiplexNetwork<V, L>::
summary(
) const
{
    std::string summary =
        "MultiplexNetwork (" +
        vertices_->summary() + ", " +
        layers_->summary() + ")";
    return summary;
}


template<typename V, typename L>
V&
MultiplexNetwork<V, L>::
vertices(
)
{
    return *vertices_.get();
}


template<typename V, typename L>
const V&
MultiplexNetwork<V, L>::
vertices(
) const
{
    return *vertices_.get();
}

/*
 template<typename V, typename L>
 std::shared_ptr<E>
 MultiplexNetwork<V, L>::
 interlayer_edges(
 )
 {
 return edges_;
 }


 template<typename V, typename L>
 const std::shared_ptr<E>
 MultiplexNetwork<V, L>::
 interlayer_edges(
 ) const
 {
 return edges_;
 }
 */

template<typename V, typename L>
L&
MultiplexNetwork<V, L>::
layers(
)
{
    return *layers_.get();
}


template<typename V, typename L>
const L&
MultiplexNetwork<V, L>::
layers(
) const
{
    return *layers_.get();
}

/*
 template<typename V, typename L>
 bool
 MultiplexNetwork<V, L>::
 is_directed(
 ) const
 {
 return true; // @todo edges_->is_directed();
 }
 */

/*
template<typename V, typename L>
void
MultiplexNetwork<V, L>::
notify_add(
    const Vertex* v,
    size_t layer
)
{
    if (!vertices_->contains(v))
    {
        throw core::ElementNotFoundException("vertex " + v->name);
    }
}


template<typename V, typename L>
void
MultiplexNetwork<V, L>::
notify_erase(
    const Vertex* v,
    size_t layer
)
{
}
*/

template<typename V, typename L>
void
MultiplexNetwork<V, L>::
notify_add(
    const Vertex* v
)
{
}


template<typename V, typename L>
void
MultiplexNetwork<V, L>::
notify_erase(
    const Vertex* v
)
{
    for (auto g: layers())
    {
        g->vertices().erase(v);
    }
}

/*
 template<typename V, typename L>
 void
 MultiplexNetwork<V, L>::
 notify_add(
 const std::shared_ptr<Edge>& e,
 size_t layer1,
 size_t layer2
 )
 {

 switch (layer1)
 {
 case 0:
 if (!layers()->template get<0>()->vertices()->contains(e->v1))
 {
 throw core::ElementNotFoundException("vertex " + e->v1->name + " in layer " + layers()->template get<0>()->name);
 }

 break;

 case 1:
 if (!layers_->template get<1>()->vertices()->contains(e->v1))
 {
 throw core::ElementNotFoundException("vertex " + e->v1->name + " in layer " + layers()->template get<1>()->name);
 }

 break;

 default:
 throw core::WrongParameterException("layer " + std::to_string(layer1));
 }


 switch (layer2)
 {
 case 0:
 if (!layers()->template get<0>()->vertices()->contains(e->v2))
 {
 throw core::ElementNotFoundException("vertex " + e->v2->name + " in layer " + layers()->template get<0>()->name);
 }

 break;

 case 1:
 if (!layers_->template get<1>()->vertices()->contains(e->v2))
 {
 throw core::ElementNotFoundException("vertex " + e->v2->name + " in layer " + layers()->template get<1>()->name);
 }

 break;

 default:
 throw core::WrongParameterException("layer " + std::to_string(layer1));
 }

 }


 template<typename V, typename L>
 void
 MultiplexNetwork<V, L>::
 notify_erase(
 const std::shared_ptr<Edge>& e,
 size_t layer1,
 size_t layer2
 )
 {
 // do nothing
 }
 */

} // namespace net
} // namespace uu

#endif

