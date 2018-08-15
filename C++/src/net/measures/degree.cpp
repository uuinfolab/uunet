/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include <algorithm>
#include "net/measures/degree.h"
#include "core/exceptions/assert.h"
#include "core/utils/Counter.h"


namespace uu {
namespace net {



template<typename G>
size_t
maximum_degree(
    const G* g,
    const EdgeMode mode
)
{
    core::assert(g, "maximum_degree", "g");
    size_t max = 0;
    size_t d;

    for (auto v: *g->vertices())
    {
        d=degree(g, v, mode);

        if (d > max)
        {
            max = d;
        }
    }

    return max;
}





template<typename G>
size_t
minimum_degree(
    const G* g,
    const EdgeMode mode
)
{
    core::assert(g, "minimum_degree", "g");
    size_t min = 0;
    size_t d;
    bool first = true;

    for (auto v: *g->vertices())
    {
        d=degree(g, v, mode);

        if (first)
        {
            min = d;
            first = false;
        }

        else if (d < min)
        {
            min = d;
        }
    }

    return min;
}




template<typename G>
std::vector<size_t>
degree_sequence(
    const G* g,
    const EdgeMode mode
)
{
    core::assert(g, "degree_sequence", "g");

    size_t order = g->vertices()->size();
    std::vector<size_t> res;
    res.reserve(order);

    size_t d;

    for (auto v: *g->vertices())
    {
        d=degree(g, v, mode);
        res.push_back(d);
    }

    std::sort(res.begin(), res.end());
    return res;
}




template<typename G>
std::vector<size_t>
degree_distribution(
    const G* g,
    const EdgeMode mode
)
{
    core::assert(g, "degree_distribution", "g");
    core::Counter<size_t> dd;

    size_t max = 0;
    size_t d;

    for (auto v: *g->vertices())
    {
        d = degree(g, v, mode);
        dd.inc(d);

        if (d > max)
        {
            max = d;
        }
    }

    std::vector<size_t> res;
    res.reserve(max+1);

    for (d = 0; d<=max; d++)
    {
        res.push_back(dd.count(d));
    }

    return res;
}



template<typename G>
size_t
degree(
    const G* g,
    const Vertex* v,
    const EdgeMode mode
)
{
    core::assert(g, "degree", "g");
    core::assert(g, "degree", "v");
    return g->edges()->neighbors(v, mode)->size();
}


}
}

