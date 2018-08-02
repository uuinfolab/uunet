/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_ATTRVERTEXSTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_ATTRVERTEXSTORE_H_

#include "net/datastructures/stores/Attributed.h"
#include "net/datastructures/stores/VertexStore.h"
#include "net/datastructures/stores/AttributeStore.h"

namespace uu {
namespace net {

/**
 * A VertexStore allows to create, store, retrieve and erase a set of vertices.
 *
 * A must be an attribute store, itself templatized to work with vertices.
 */
template <typename A = AttributeStore<const Vertex>>
class
    AttrVertexStore :
    public Attributed<A>,
    public VertexStore
{

  public:
    AttrVertexStore(
        std::unique_ptr<A> attr
    );

    /**
     * Returns a short string summary of this store, for example including
     * the number of vertices it contains.
     */
    virtual
    std::string
    summary(
    ) const;

};


template <typename A>
AttrVertexStore<A>::
AttrVertexStore(
    std::unique_ptr<A> attr
) :
    Attributed<A>(std::move(attr))
{
    attach(&this->attr());
}


template <typename A>
std::string
AttrVertexStore<A>::
summary(
) const
{
    size_t s = size();
    std::string summary =
        std::to_string(s) +
        (s==1?" vertex":" vertices") +
        ", ";// +
    //attributes_->summary();
    return summary;
}


std::unique_ptr<AttrVertexStore<>>
                                create_attributed_vertex_store();


} // namespace net
} // namespace uu

#endif
