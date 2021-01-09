#ifndef UU_NETWORKS_MULTILAYERNETWORK2_H_
#define UU_NETWORKS_MULTILAYERNETWORK2_H_

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "olap/VCube.hpp"
#include "olap/ECube.hpp"
#include "networks/Network2.hpp"
#include "networks/_impl/stores/LayerStore.hpp"
#include "networks/_impl/stores/MLECubeStore.hpp"

namespace uu {
namespace net {

/**
 * A generalized MultilayerNetwork2 is a Vertex Cube with N dimensions.
 * Each cell of the Vertex Cube has an Edge Cube defined on it, with one dimension.
 * Edge Cubes can also be added between pairs of Vertex Cells, allowing edges across layers.
 *
 * In generalized MultilayerNetwork2s, vertices are called actors, and the same actor can be
 * present in multiple layers.
 * A multilayer vertex (MLVertex) is a pair (actor,layer).
 * A multilayer edge (MLEdge) is an edge connecting multilayer vertices.
 */
class
    MultilayerNetwork2
{

    friend LayerStore;
    
  private:
    
    /** The actors, organized into N members on one dimension */
    std::unique_ptr<VCube> actors_;
    /** Layer Store */
    std::unique_ptr<LayerStore> layers_;
    /** Layer's vertices */
    //std::map<std::vector<std::string>, std::unique_ptr<VCube>> vertices_;
    /** Intralayer edges */
    //std::map<std::vector<std::string>, std::unique_ptr<ECube>> intra_edges_;
    /** Interlayer edges */
    std::unique_ptr<MLECubeStore> interlayer_edges_;
    
  public:

    const std::string name;

    //typedef Network layer_type;
    //typedef Vertex vertex_type;
    //typedef MLVertex<MultilayerNetwork2> community_element_type;

    /**
     * Creates an empty Network.
     */
    MultilayerNetwork2(
    const std::string& name
    );

    /**
     * Returns a pointer to the network's actors.
     */
    const VCube*
    actors(
    ) const;
    
    /**
     * Returns a pointer to the network's interlayer edges.
     */
    LayerStore*
    layers(
    );
    
    /**
     * Returns a pointer to the network's interlayer edges.
     */
    const LayerStore*
    layers(
    ) const;
    
    /**
     * Returns a pointer to the network's interlayer edges.
     */
    MLECubeStore*
    interlayer_edges(
    );
    
    /**
     * Returns a pointer to the network's interlayer edges.
     */
    const MLECubeStore*
    interlayer_edges(
    ) const;
    

    
};


}
}

#endif
