#ifndef UU_COMMUNITY_MIMAG_APPROXIMATION_MIMAG_APPROX_MCLPM_H_
#define UU_COMMUNITY_MIMAG_APPROXIMATION_MIMAG_APPROX_MCLPM_H_

#include <memory>
#include <unordered_set>
#include <vector>
#include "core/utils/math.hpp"
#include "core/utils/pretty_printing.hpp"
#include "community/MLCPMCommunity.hpp"
#include "community/ml-cpm.hpp"
#include "community/mimag_approximation/mimag_approx.hpp"
#include "community/CommunityStructure.hpp"

namespace uu {
namespace net {


/**
  * This method finds cliques using a mimag approximation
  * then builds communities using the mlcpm method
  *
  */

template <typename M>
std::unique_ptr<CommunityStructure<M>>
mimag_approx_mlcpm(
    const M* mnet,
    size_t k,
    size_t m,
    double gamma
);


}
}

#include "mimag_approx_mlcpm.ipp"

#endif
