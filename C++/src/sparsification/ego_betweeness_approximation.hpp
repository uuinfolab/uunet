/**
 * History:
 * - 2020.04.27 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_EGO_BETWEENESS_APPROXIMATION_H_
#define UU_NET_SPARSIFICATION_EGO_BETWEENESS_APPROXIMATION_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {


/**
 * ego_betweeness_approximation
 * An approximation of ego betweeness on a probabilistic network
 * @param graph input graph
 * @return A vector of ego betweeness for each vertex in the graph
  **/
std::vector<std::pair<double, std::string>>
ego_betweeness_approximation(
    ProbabilisticNetwork * graph
);


}
}

#endif
