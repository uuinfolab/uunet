/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_MNET_DATASTRUCTURE_STORECREATION_H_
#define UU_MNET_DATASTRUCTURE_STORECREATION_H_

#include <memory>
#include <string>
#include "net/datastructures/stores/SimpleEdgeStore.h"
#include "mnet/datastructures/store_types.h"

namespace uu {
namespace net {

template <size_t N>
std::unique_ptr<SimpleMultilayerEdgeStore<N>>
        create_simple_multilayer_edge_store();


template <size_t N>
std::unique_ptr<SimpleMultilayerEdgeStore<N>>
        create_simple_multilayer_edge_store()
{

    std::array<std::unique_ptr<SimpleEdgeStore>,N*(N-1)/2> init;

    for (size_t i=0; i<init.size(); i++)
        // @todo fixme: dir
    {
        init.at(i) = create_simple_edge_store(EdgeDir::DIRECTED);
    }

    using A = EmptyAttributeStore<const Edge>;

    std::unique_ptr<A> attr = std::make_unique<A>();

    return std::make_unique<SimpleMultilayerEdgeStore<N>>(std::move(init), std::move(attr));
}


} // namespace net
} // namespace uu

#endif
