/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_IO_MULTILAYERMETADATA_H_
#define UU_NET_IO_MULTILAYERMETADATA_H_

#include <vector>
#include <unordered_map>
#include "core/attributes/Attribute.h"
#include "net/datastructures/graphs/GraphType.h"

namespace uu {
namespace net {

struct MultilayerMetadata
{
    GraphType features;
    
    std::unordered_map<std::string, GraphType> layers;
    
    std::vector<core::Attribute> vertex_attributes;
    std::vector<core::Attribute> edge_attributes;
    std::unordered_map<std::string, std::vector<core::Attribute>> intralayer_vertex_attributes;
    std::unordered_map<std::string, std::vector<core::Attribute>> intralayer_edge_attributes;
};

}
}

#endif
