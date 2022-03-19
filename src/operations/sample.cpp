#include "operations/sample.hpp"
#include "core/exceptions/assert_not_null.hpp"
#include "core/utils/random.hpp"

namespace uu {
namespace net {

std::unique_ptr<Network>
sample(
       const ProbabilisticNetwork* g
       ) {
    
    core::assert_not_null(g, "sample", "g");
    
    auto dir = g->is_directed() ? EdgeDir::DIRECTED : EdgeDir::UNDIRECTED;
    auto loops = g->allows_loops();
    
    auto res = std::make_unique<Network>(g->name, dir, loops);

    for (auto vertex: *g->vertices())
    {
        res->vertices()->add(vertex);
    }

    for (auto e: *g->edges())
    {
        auto p = g->get_prob(e);
        
        if (!p.null && core::test(p.value))
        {
            res->edges()->add(e->v1, e->v2);
        }
    }

    return res;
}

}
}

