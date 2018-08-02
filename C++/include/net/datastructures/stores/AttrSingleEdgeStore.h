/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_ATTRSIMPLEEDGESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_ATTRSIMPLEEDGESTORE_H_

#include <unordered_set>
#include "net/datastructures/stores/EdgeStore.h"
#include "net/datastructures/stores/Attributed.h"
#include "net/datastructures/stores/AttributeStore.h"

namespace uu {
namespace net {


template <typename A = AttributeStore<const Edge>>
class AttrSingleEdgeStore :
    public EdgeStore,
    public Attributed<const Edge>
{

  public:

    /**
     * Constructor.
     */

    AttrSingleEdgeStore(
        EdgeDir dir,
        std::unique_ptr<A> attr
    );



};


template <typename A>
AttrSingleEdgeStore<A>::
AttrSingleEdgeStore(
    EdgeDir dir,
    std::unique_ptr<A> attr
) :
    EdgeStore<A>(dir),
    Attributed<A>(std::move(attr))
{
    attach(&this->attr());
}

} // namespace net
} // namespace uu

#endif
