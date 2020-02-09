/**
 * History:
 * - 2020.02.06 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_BGI_H_
#define UU_NET_SPARSIFICATION_BGI_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {

/**
 * Generates a Backbone graph
 * @return Backbone grap
 * @param original_graph Input graph to get the backbone graph from
 * @param sparsRatio Sparsification ratio
 * @param spanRatio Spanning ratio
 **/
std::unique_ptr<Network>
generate_backbone(
    ProbabilisticNetwork* original_graph,
    float sparsRatio,
    float spanRatio
);

}
}

#include "BGI.ipp"

#endif
