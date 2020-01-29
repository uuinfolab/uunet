
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/utils/random.hpp"
#include "creation/standard_graphs.hpp"
#include "creation/utils.hpp"

namespace uu {
namespace net {

template <typename G>
void
erdos_renyi_nm(
    G* g,
    size_t n,
    size_t m
)
{
    null_graph(g, n);

    auto edge_ids = core::get_k_uniform(n*(n-1)/2, m);

    for (auto edge_id:  edge_ids)
    {
        size_t v_id1 = 0;

        while (edge_id >= n - v_id1 - 1)
        {
            edge_id -= n - v_id1 - 1;
            v_id1++;
        }

        size_t v_id2 = edge_id + v_id1 + 1;

        auto v1 = g->vertices()->at(v_id1);
        auto v2 = g->vertices()->at(v_id2);

        g->edges()->add(v1, v2);
    }
}



template <typename G>
void
erdos_renyi_np(
    G* g,
    size_t n,
    double p
)
{
    if (g->is_directed())
    {
        throw core::OperationNotSupportedException("G(n,p) model only supports undirected graphs");
    }

    size_t max_edges = n*(n-1)/2;
    size_t m = core::get_binomial(max_edges, p);
    erdos_renyi_nm(g, n, m);

}


}
}

