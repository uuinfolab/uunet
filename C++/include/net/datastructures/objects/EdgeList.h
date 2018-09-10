/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_OBJECTS_EDGELIST_H_
#define UU_NET_DATASTRUCTURES_OBJECTS_EDGELIST_H_

#include <string>

namespace uu {
namespace net {

using EdgeList = core::SortedRandomSet<const Edge*>;

static const std::unique_ptr<EdgeList> kEMPTY_EDGE_LIST = std::make_unique<EdgeList>();


}
}

#endif
