/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_GRAPHS_GRAPHTYPE_H_
#define UU_NET_DATASTRUCTURES_GRAPHS_GRAPHTYPE_H_

namespace uu {
namespace net {

struct GraphType
{

    bool is_directed = false;
    bool is_weighted = false;
    bool is_temporal = false;
    bool is_attributed = false;
    bool allows_multi_edges = false;
    bool allows_loops = false;

};

}
}

#endif
