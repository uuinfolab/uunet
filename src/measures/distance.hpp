#ifndef UU_MEASURES_DISTANCE_H_
#define UU_MEASURES_DISTANCE_H_

#include "objects/Vertex.hpp"
#include "objects/MLPathLength.hpp"

namespace uu {
namespace net {


template <typename M>
std::unordered_map<const Vertex*, std::set<MLPathLength<M>> >
        pareto_distance(
            const M* net,
            const Vertex* from
        );

}
}

#include "distance.ipp"

#endif
