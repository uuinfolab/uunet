/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "core/exceptions/assert_not_null.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "creation/empty_copy.hpp"

namespace uu {
namespace net {

/**
 * Returns the intersection of two graphs.
 *
 * The operation is only allowed if both graphs are directed or both are undirected.
 *
 * Attributes are currently not supported.
 *
 * @param g1, g2 input graphs
 */
template<typename G>
std::unique_ptr<G>
graph_intersection(
    const G* g1,
    const G* g2,
    const std::string& name
)
{
    if (g1->is_directed() != g2->is_directed())
    {
        std::string err = "intersection between directed and undirected graphs";
        throw core::OperationNotSupportedException(err);
    }

    std::unique_ptr<G> res = empty_copy(g1, name);

    for (auto vertex: *g1->vertices())
    {
        if (g2->vertices()->contains(vertex))
        {
            res->vertices()->add(vertex);
        }
    }


    for (auto edge: *g1->edges())
    {
        if (g2->edges()->get(edge->v1, edge->v2))
        {
            res->edges()->add(edge->v1, edge->v2);
        }
    }

    return res;
}

}
}

