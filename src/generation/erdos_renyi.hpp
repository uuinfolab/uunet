#ifndef UU_GENERATION_ER_H_
#define UU_GENERATION_ER_H_

#include "networks/Network2.hpp"
#include <memory>

namespace uu {
namespace net {

/**
 *
 **/
std::unique_ptr<Network2>
erdos_renyi_nm(
    size_t n,
    size_t m
);


/**
 *
 **/
std::unique_ptr<Network2>
erdos_renyi_np(
    size_t n,
    double p
);

}
}

#endif
