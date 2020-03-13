/**
 * History:
 * - 2020.02.14 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_GDB_H_
#define UU_NET_SPARSIFICATION_GDB_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {

/**
 * Generates a sparsified graph using the Gradient Descent Backbone algorithm
 * @param uncertain_graph Original uncertain graph
 * @param backbone_graph Backbone graph generated from BGI
 * @param entropy_step_size The step size
 * @param improvement_threshold 
 * @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
std::unique_ptr<ProbabilisticNetwork>
GDB(
    ProbabilisticNetwork * uncertain_graph,
    Network * backbone_graph,
    double entropy_step_size,
    double improvement_threshold,
    bool use_absolute
);



/**
 * Generates a sparsified graph using the Gradient Descent Backbone algorithm
 * This version saves the new probablities for each edge in a "next" graph, so that the calculations are independant on the edge order
 * @param uncertain_graph Original uncertain graph
 * @param backbone_graph Backbone graph generated from BGI
 * @param entropy_step_size The step size
 * @param improvement_threshold 
 * @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
std::unique_ptr<ProbabilisticNetwork>
GDB_2(
    ProbabilisticNetwork * uncertain_graph,
    Network * backbone_graph,
    double entropy_step_size,
    double improvement_threshold,
    bool use_absolute
);

}
}

#endif
