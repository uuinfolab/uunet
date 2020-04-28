/**
 * History:
 * - 2020.04.27 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_RELIABILITY_H_
#define UU_NET_SPARSIFICATION_RELIABILITY_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {


/**
 * Calculates the reliability to reach t from s in probabilistic networks
 * @param graph input graph
 * @param start start vertex
 * @param target target vertex
 * @param times_to_run amount of times to run
 * @return the sum of probabilities
  **/
double
reliability_s_to_t(
    ProbabilisticNetwork * graph,
    const Vertex * start,
    const Vertex * target,
    int times_to_run
);

/**
 * Calculates the reliability to reach every other node from s in probabilistic networks
 * @param graph input graph
 * @param start start vertex
 * @param times_to_run amount of times to run
 * @return an array of sums of probabilities for each vertex
  **/
std::vector<double>
reliability_s_to_all(
    ProbabilisticNetwork * graph,
    const Vertex * start,
    int times_to_run
);


}
}

#endif
