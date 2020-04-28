/**
 * History:
 * - 2020.04.27 file created by Oskar
 **/

#include "networks/ProbabilisticNetwork.hpp"
#include "measures/exp_degree.hpp"
#include "sparsification/pagerank.hpp"

namespace uu {
namespace net {


/**
 * Calculates the pagerank for every vertex in a probabilistic graph
 * @param graph input graph
 * @return a set of each vertex and their expected degree
  **/
std::set< cutsize_vertex, pagerank_comp >
pagerank(
    ProbabilisticNetwork * graph
)
{
    std::set< cutsize_vertex, pagerank_comp > vCutsizes;

    for (auto vertex: *graph->vertices())
    {
        double cut_size = exp_degree(graph, vertex, uu::net::EdgeMode::INOUT);
        vCutsizes.insert( std::make_pair(cut_size, vertex->to_string()));
    }
    return vCutsizes;
}






}
}
