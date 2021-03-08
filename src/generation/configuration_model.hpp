#ifndef UU_GENERATION_CONFIGURATION_MODEL_H
#define UU_GENERATION_CONFIGURATION_MODEL_H

#include "networks/Network.hpp"
#include "core/utils/random.hpp"
#include <numeric>

namespace uu {
namespace net {

bool
is_graphic(
    const std::vector<size_t> &deg_seq,
    bool is_sorted = false
);

bool
is_digraphic(
    const std::vector<size_t> &in_deg_seq,
    const std::vector<size_t> &out_deg_seq,
    bool is_sorted = false
);

void
from_degree_sequence(
    const std::vector<size_t> &deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &vertices,
    Network *g
);

void
from_degree_sequence(
    const std::vector<size_t> &in_deg_seq,
    const std::vector<size_t> &out_deg_seq,
    const std::vector<std::shared_ptr<Vertex>> &vertices,
    Network *g
);

}
}

#endif
