/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */
#include "net/datastructures/stores/AttrVertexStore.h"

namespace uu {
namespace net {

std::unique_ptr<AttrVertexStore<>>
                                create_attributed_vertex_store()
{
    using A = AttributeStore<const Vertex>;
    using V = AttrVertexStore<>;

    std::unique_ptr<A> v_attr = std::make_unique<A>();
    return std::make_unique<V>(std::move(v_attr));
}
}
}

