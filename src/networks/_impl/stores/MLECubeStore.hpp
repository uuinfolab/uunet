#ifndef UU_NET_DATASTRUCTURES_STORES_MLECUBESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_MLECUBESTORE_H_

#include <memory>
#include <unordered_map>
#include "objects/Edge.hpp"
#include "objects/EdgeDir.hpp"
#include "objects/EdgeMode.hpp"
#include "networks/Network.hpp"
#include "networks/_impl/stores/LayerStore.hpp"

namespace uu {
namespace net {


class
    MLECubeStore
//:
//    public core::SharedPtrSortedRandomSet<const Edge>,
//            public core::Subject<const Edge>
{

  private:

    std::map<std::pair<const Network*, const Network*>, std::unique_ptr<ECube>> interlayer_edges_;

    const LayerStore* layers_;

  public:

    MLECubeStore(
        const LayerStore* layers_
    );

    virtual
    ~MLECubeStore() {}

  public:

    //using super::size;
    //using super::add;
    //using super::erase;

    /*
    virtual
    const Edge*
    add(
        std::shared_ptr<const Edge> e
    ) override;
    */

    /**
     * Adds a new edge.
     * Multiple edges between the same pair of vertices are not allowed.
     * @param vertex1 a pointer to the "from" vertex if directed, or to one end of
     * the edge if undirected.
     * @param vertex2 a pointer to the "to" vertex if directed, or one end of the
     * edge if undirected.
     * @return a pointer to the new edge, or nullptr if the edge already exists.
     **/
    virtual
    const Edge *
    add(
        const Vertex* vertex1,
        const Network* layer1,
        const Vertex* vertex2,
        const Network* layer2
    );

    const Edge *
    get(
        const Vertex* vertex1,
        const Network* layer1,
        const Vertex* vertex2,
        const Network* layer2
    );

    bool
    erase(
        const Edge* e
    );


    const ECube*
    get(
        const Network* layer1,
        const Network* layer2
    ) const;


    /**
     * @brief Returns the nodes with an edge from/to the input vertex.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return the list of neighbors.
     **/
    const
    GenericObjectList<Vertex>*
    neighbors(
        const Network* layer1,
        const Network* layer2,
        const Vertex* vertex,
        EdgeMode mode
    ) const;

    /**
     * @brief Returns the nodes with an edge from/to the input vertex.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return the list of neighbors.
     **/
    const
    GenericObjectList<Edge>*
    incident(
        const Network* layer1,
        const Network* layer2,
        const Vertex* vertex,
        EdgeMode mode
    ) const;


    size_t
    size(
    ) const;

    ECube*
    init(
        Network* layer1,
        Network* layer2,
        EdgeDir dir
    );

    bool
    is_directed(
        const Network* layer1,
        const Network* layer2
    ) const;


    void
    set_directed(
        const Network* layer1,
        const Network* layer2,
        bool directed
    );


    virtual
    void
    add(
        const Network* layer
    );

    virtual
    void
    erase(
        const Network* layer
    );


    virtual
    void
    erase(
        const Network* layer,
        const Vertex* vertex
    );

  private:

    ECube*
    get(
        const Network* layer1,
        const Network* layer2
    );
};


}
}

#endif
