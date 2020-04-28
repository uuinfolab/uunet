/**
 * History:
 * - 2020.04.27 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_PAGERANK_H_
#define UU_NET_SPARSIFICATION_PAGERANK_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {

struct pagerank_comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        if (l.first == r.first)
            return l.second > r.second;

        return l.first > r.first;
    }
};
typedef std::pair<double, std::string> cutsize_vertex;


/**
 * Calculates the pagerank for every vertex in a probabilistic graph
 * @param graph input graph
 * @return a set of each vertex and their expected degree
  **/
std::set< cutsize_vertex, pagerank_comp >
pagerank(
    ProbabilisticNetwork * graph
);

}
}

#endif
