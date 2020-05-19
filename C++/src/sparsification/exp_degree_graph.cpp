/**
 * History:
 * - 2020.04.27 file created by Oskar
 **/

#include "networks/ProbabilisticNetwork.hpp"
#include "measures/exp_degree.hpp"
#include "sparsification/exp_degree_graph.hpp"

namespace uu {
namespace net {


/**
 * Calculates the exp_degree_graph for every vertex in a probabilistic graph
 * @param graph input graph
 * @return a set of each vertex and their expected degree
  **/
std::vector< std::pair<double, std::string> >
exp_degree_graph(
    ProbabilisticNetwork * graph
)
{
    std::vector< std::pair<double, std::string> > vCutsizes;

    for (auto vertex: *graph->vertices())
    {
        double cut_size = exp_degree(graph, vertex, uu::net::EdgeMode::INOUT);
        vCutsizes.push_back( std::make_pair(cut_size, vertex->to_string()));
    }
    return vCutsizes;
}






}
}
