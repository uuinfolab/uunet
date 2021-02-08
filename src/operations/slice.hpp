#ifndef UU_TNET_TRANSFORMATION_SLICE_H_
#define UU_TNET_TRANSFORMATION_SLICE_H_

#include <memory>
#include "networks/time.hpp"
#include "networks/OrderedMultiplexNetwork2.hpp"

namespace uu {
namespace net {


/**
* @brief Transforms a temporal network into an ordered multiplex network.
* @param tnet pointer to a temporal network
* @param num_partitions number of time slices
* @return a pointer to an ordered multiplex network
**/
std::unique_ptr<OrderedMultiplexNetwork2>
slice_equal_time(
    const Network2* tnet,
    size_t num_partitions
);

}
}

#endif
