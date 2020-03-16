/**
 * History:
 * - 2020.03.16 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_EMD_H_
#define UU_NET_SPARSIFICATION_EMD_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {

/**
 * Generates a sparsified graph using the Expectation-Maximization Degree algorithm
 * @param uncertain_graph Original uncertain graph
 * @param backbone_graph Backbone graph generated from BGI
 * @param entropy_step_size The step size
 * @param improvement_threshold 
 * @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
std::unique_ptr<ProbabilisticNetwork>
EMD(
    ProbabilisticNetwork * uncertain_graph,
    Network * backbone_graph,
    double entropy_step_size,
    double improvement_threshold,
    bool use_absolute
);

}
}

#endif
