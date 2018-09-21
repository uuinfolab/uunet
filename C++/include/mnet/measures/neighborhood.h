/**
 * Social Network Analysis measures for multiplex networks.
 *
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef MNET_MEASURES_NEIGHBORHOOD_H_
#define MNET_MEASURES_NEIGHBORHOOD_H_

#include <vector>
#include "core/exceptions/assert_not_null.h"
#include "core/utils/math.h"
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeMode.h"
#include "net/measures/degree.h"

namespace uu {
namespace net {

// TO BE COMPLETED

/**
 * Returns the vertices that are neighbors of the input on at least one of the input layers.
 * @param first, last iterators specifying a range of layers (first included, last not included)
 * @param v input vertex
 * @param mode to select IN, OUT, or INOUT degree
 * @return the sum of the degrees of v in the input layers
 */
template <typename LayerIterator>
std::unordered_set<const Vertex*>
neighbors(
    LayerIterator first,
    LayerIterator last,
    const Vertex* v,
    EdgeMode mode
);



// DEFINITIONS

template <typename LayerIterator>
std::unordered_set<const Vertex*>
neighbors(
    LayerIterator first,
    LayerIterator last,
    const Vertex* v,
    EdgeMode mode
)
{
    core::assert_not_null(v, "degree", "v");

    int degree = 0;

    for (auto layer=first; layer!=last; ++layer)
    {
        degree += degree(layer, v, EdgeMode);
    }

    return degree;
}



}
}

#endif
