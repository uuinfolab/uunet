/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_IO_GRAPHIOFILESECTION_H_
#define UU_NET_IO_GRAPHIOFILESECTION_H_

namespace uu {
namespace net {

enum class GraphIOFileSection
{
    DEFAULT,
    VERSION,
    TYPE,
    VERTEX_ATTRIBUTES,
    EDGE_ATTRIBUTES,
    VERTICES,
    EDGES
};


}
}

#endif
