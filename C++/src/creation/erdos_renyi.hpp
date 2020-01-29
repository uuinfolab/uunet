/**
 */

#ifndef UU_NET_GENERATION_ER_H_
#define UU_NET_GENERATION_ER_H_

namespace uu {
namespace net {

/**
 *
 **/
template <typename G>
void
erdos_renyi_nm(
    G* g,
    size_t n,
    size_t m
);


/**
 *
 **/
template <typename G>
void
erdos_renyi_np(
    G* g,
    size_t n,
    double p
);

}
}

#include "erdos_renyi.ipp"

#endif
