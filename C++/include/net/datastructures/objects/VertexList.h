/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_OBJECTS_VERTEXLIST_H_
#define UU_NET_DATASTRUCTURES_OBJECTS_VERTEXLIST_H_

#include <string>
#include "core/datastructures/containers/SortedRandomSet.h"
#include "net/datastructures/objects/Vertex.h"

namespace uu {
namespace net {

using VertexList = core::SortedRandomSet<Vertex const *>;

static const std::unique_ptr<VertexList> kEMPTY_VERTEX_LIST = std::make_unique<VertexList>();

}
}

#endif
