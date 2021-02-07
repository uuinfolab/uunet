#ifndef UU_NETWORKS_IMPL_TIME_H_
#define UU_NETWORKS_IMPL_TIME_H_

#include "core/attributes/Time.hpp"

namespace uu {
namespace net {

template <class STORE>
void
make_temporal(
    STORE& store
);

template <class STORE>
void
add_time(
    STORE* store,
    typename STORE::value_type*,
    const core::Time& t
);

template <class STORE>
std::set<core::Time>
get_times(
    STORE* store,
    typename STORE::value_type*
);

}
}

#include "time.ipp"

#endif
