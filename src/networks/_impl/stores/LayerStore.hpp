#ifndef UU_NETWORKS_IMPL_STORES_LAYERSTORE_H_
#define UU_NETWORKS_IMPL_STORES_LAYERSTORE_H_

#include <map>
#include <utility>
#include "networks/Network2.hpp"
#include "olap/VCube.hpp"

namespace uu {
namespace net {


class LayerStore
{
private:
    
    core::LabeledUniquePtrSortedRandomSet<Network2> store;
    
    VCube* actors_;
    
public:
    
    LayerStore(
               VCube* actors
               );
    
    Network2 *
    add(
        const std::string layer_name,
        EdgeDir dir = EdgeDir::UNDIRECTED,
        LoopMode loops = LoopMode::ALLOWED
        );

    bool
    contains(
             const Network2* layer
             ) const;
    
    bool
    get(
             const std::string& layer_name
        ) const;
    
};

}
}

#endif
