/**
 * History:
 * - 2018.08.28 file created.
 */

#ifndef UU_PNET_MEASURES_ENTROPY_H_
#define UU_PNET_MEASURES_ENTROPY_H_

#include<iostream>
#include<complex>
#include<vector>
#include<cmath>
#include "core/utils/Counter.h"

#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeMode.h"

namespace uu {
namespace net {

/**
 * Returns the Entropy of graph.
 * @param g input graph
 * @return the Entropy of g
 */
template<typename G>
double
graph_entropy(
               const G* g
);


/** DEFINITIONS */

template<typename G>
double
graph_entropy(
               const G* g
)
{


    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Entropy can only be computed on probabilistic graphs");
    }


    double E = 0;      
    for (auto edge: *g->edges())
    {
        auto p = g->edges()->attr()->get_probability(edge);

        if (!p.null && p.value != 1)
        {
            E += -p.value*log10(p.value)-(1-p.value)*log10(1-p.value);
        }
        
    }

    return E;
}


}
}

#endif
