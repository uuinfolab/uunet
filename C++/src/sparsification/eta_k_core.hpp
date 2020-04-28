/**
 * History:
 * - 2020.03.11 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_ETA_K_CORE_H_
#define UU_NET_SPARSIFICATION_ETA_K_CORE_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {

/**
 * This function returns the (eta_k)-core value of all nodes in a probabilistic graph introduced in paper "Core Decomposition of Uncertain Graphs"
 * @param original_graph input probabilistic graph
 * @param eta_threshold eta threshold
 * @return the (eta,k)-core of a probabilistic graph
  **/
std::vector<int>
eta_k_core(
    ProbabilisticNetwork * original_graph,
    double eta_threshold
);

}
}

#endif
