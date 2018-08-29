/**
 * History:
 * - 2018.08.29 file created.
 */

#ifndef UU_PNET_MEASURES_BASIC_H_
#define UU_PNET_MEASURES_BASIC_H_

#include "core/exceptions/assert_not_null.h"

namespace uu {
namespace net {

/**
 * Returns the probability two vertices in a graph are neighbors.
 * @param g input graph
 * @param v1 input vertex
 * @param v2 input vertex
 * @param mode to select IN, OUT, or INOUT edge from v1 to v2
 * @return the probability that vertices v1 and v2 are neighbors in g
 */
template<typename G>
double
is_neighbor(
               const G* g,
               const Vertex* v1,
	       const Vertex* v2,
               const EdgeMode mode
);


/** DEFINITIONS */

template<typename G>
double
is_neighbor(
               const G* g,
               const Vertex* v1,
	       const Vertex* v2,
               const EdgeMode mode
)
{
    core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("this is not a probabilistic graphs");
    }


    for (auto i: *g->edges()->incident(v1,mode))
    {
        if (i->v2 == v2 || i->v1 == v2)
        {
            auto p = g->edges()->attr()->get_probability(i);
            return p.value;
        }
    }

    return 0;
}


}
}

#endif
