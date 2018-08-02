/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURE_OBSERVERS_EDGEVERTEXOBSERVER_H_
#define UU_NET_DATASTRUCTURE_OBSERVERS_EDGEVERTEXOBSERVER_H_

#include <memory>
#include <string>
#include <iostream>
#include "core/exceptions/ElementNotFoundException.h"
#include "core/datastructures/observers/Observer.h"
#include "net/datastructures/objects/Edge.h"
#include "net/datastructures/objects/Vertex.h"

namespace uu {
namespace net {

/**
 * Graph is a generic class that can be instantiated into several specific types of network.
 *
 * A Graph is instantiated by specifying a VertexStore (V) and an EdgeStore (E).
 */
template<typename V1, typename V2, typename E>
class EdgeVertexObserver :
    public core::Observer<const Vertex>,
    public core::Observer<const Edge>
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
    EdgeVertexObserver(
        V1* v1,
        V2* v2,
        E* e
    );

    /**
     * Informs the graph that a vertex has been added to its vertex store.
     */
    void
    notify_add(
        const Vertex* v
    ) override;


    /**
     * Informs the graph that a vertex has been erased from its vertex store.
     */
    void
    notify_erase(
        const Vertex* v
    ) override;


    /**
     * Informs the graph that an edge has been added to its edge store.
     */
    void
    notify_add(
        const Edge* e
    ) override;


    /**
     * Informs the graph that an edge has been erased from its edge store.
     */
    void
    notify_erase(
        const Edge* e
    ) override;

  private:
    /** Internal vertex store. */
    V1* vertices1_;
    V2* vertices2_;

    /** Internal edge store. */
    E* edges_;

};



template<typename V1, typename V2, typename E>
EdgeVertexObserver<V1,V2,E>::
EdgeVertexObserver(
    V1* vertices1,
    V2* vertices2,
    E* edges) :
    vertices1_(vertices1),
    vertices2_(vertices2),
    edges_(edges)
{
}

template<typename V1, typename V2, typename E>
void
EdgeVertexObserver<V1,V2,E>::
notify_add(
    const Vertex* v
)
{
    // do nothing
}


template<typename V1, typename V2, typename E>
void
EdgeVertexObserver<V1,V2,E>::
notify_erase(
    const Vertex* v
)
{
    edges_->erase(v);
}


template<typename V1, typename V2, typename E>
void
EdgeVertexObserver<V1,V2,E>::
notify_add(
    const Edge* e
)
{
    if (!vertices1_->contains(e->v1))
    {
        throw core::ElementNotFoundException("vertex " + e->v1->name);
    }

    if (!vertices2_->contains(e->v2))
    {
        throw core::ElementNotFoundException("vertex " + e->v2->name);
    }
}


template<typename V1, typename V2, typename E>
void
EdgeVertexObserver<V1,V2,E>::
notify_erase(
    const Edge* e
)
{
    // do nothing
}


} // namespace net
} // namespace uu

#endif
