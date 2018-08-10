/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_IO_GRAPHMETADATA_H_
#define UU_NET_IO_GRAPHMETADATA_H_

#include <string>
#include <vector>
#include "core/attributes/Attribute.h"
#include "net/datastructures/objects/EdgeDir.h"
#include "net/datastructures/graphs/GraphType.h"

namespace uu {
namespace net {

struct GraphMetadata
{
    GraphType type = GraphType::SIMPLE;
    EdgeDir dir = EdgeDir::UNDIRECTED;
    std::vector<core::Attribute> vertex_attributes;
    std::vector<core::Attribute> edge_attributes;
};

}
} 

#endif
