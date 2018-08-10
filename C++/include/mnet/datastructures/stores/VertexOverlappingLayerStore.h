/**

 */

#ifndef UU_MNET_DATASTRUCTURES_STORES_VERTEXOVERLAPPINGLAYERSTORE_H_
#define UU_MNET_DATASTRUCTURES_STORES_VERTEXOVERLAPPINGLAYERSTORE_H_

#include <unordered_set>
#include "core/attributes.h"
#include "core/datastructures.h"
#include "core/datastructures/containers/LabeledUniquePtrSortedRandomSet.h"
#include "net/datastructures.h"
#include "mnet/datastructures/MultiplexNetwork.h"

namespace uu {
namespace net {

template <typename Graph>
class VertexOverlappingLayerStore :
    public core::LabeledUniquePtrSortedRandomSet<Graph>
{


  private:

    typedef core::LabeledUniquePtrSortedRandomSet<Graph> super;

  public:

    VertexOverlappingLayerStore();

    using super::size;

    std::string
    summary(
    ) const
    {
        size_t s = size();
        return std::to_string(s) + (s==1?" layer":" layers");
    }

};

}
}

#endif

