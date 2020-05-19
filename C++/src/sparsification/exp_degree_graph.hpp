/**
 * History:
 * - 2020.04.27 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_exp_degree_graph_H_
#define UU_NET_SPARSIFICATION_exp_degree_graph_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {

/**
 * Calculates the exp_degree_graph for every vertex in a probabilistic graph
 * @param graph input graph
 * @return a set of each vertex and their expected degree
  **/
std::vector< std::pair<double, std::string> >
exp_degree_graph(
    ProbabilisticNetwork * graph
);

}
}

#endif
