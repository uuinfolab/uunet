/**
 * History:
 * - 2020.04.27 file created by Oskar
 **/

#include <ctime>  

#include "networks/ProbabilisticNetwork.hpp"
#include "measures/order.hpp"
#include "sparsification/ego_betweeness_approximation.hpp"

namespace uu {
namespace net {




/* temp, will be implemented into library later, use that instead */
std::vector<std::vector<double>>
to_adjacency_matrix(
    const uu::net::ProbabilisticNetwork* net
)
{
    std::vector<std::vector<double>> A;
    size_t order = uu::net::order(net);
    
    // initialize A to a null matrix
    for (size_t row = 0; row < order; row++)
    {
        A.push_back(std::vector<double>(order, 0.0));
    }
    
    auto vertices = net->vertices();
    bool directed = net->is_directed();
    for (auto e: *net->edges())
    {
        size_t row = vertices->index_of(e->v1);
        size_t col = vertices->index_of(e->v2);
        auto attr_value = net->get_prob(e);
        
        double p = attr_value.null ? 0.0 : attr_value.value;
        A[row][col] = p;
        
        if (!directed)
        {
            A[col][row] = p;
        }
    }
    
    return A;
}



/**
 * An approximation of ego betweeness on a probabilistic network
 * @param graph input graph
 * @return A vector of ego betweeness for each vertex in the graph
  **/
std::vector<std::pair<double, std::string>>
ego_betweeness_approximation(
    ProbabilisticNetwork * graph
)
{
    auto adjMatrix = to_adjacency_matrix(graph);
    int numV = graph->vertices()->size();
    std::vector<std::pair<double, std::string>> approxEgoBtw;
    //for (int v = 0; v < numV; v++){
    for (auto vertex: *graph->vertices())
    {
        double v = graph->vertices()->index_of(vertex);
        double curr_v = 0;
        for (int i = 0; i < numV-1; i++){
            auto curr_i = adjMatrix[v][i];
            if (curr_i == 0)
                continue;
            for (int j = (i+1); j < numV; j++){
                if (adjMatrix[v][j] == 0)
                    continue;
                if (i == j)
                    continue;
                curr_v += curr_i * adjMatrix[v][j] * (1 - adjMatrix[i][j]);
            }
        }
        approxEgoBtw.push_back(std::make_pair(curr_v, vertex->to_string()));
    }

    return approxEgoBtw;
}

/**
 * An approximation of ego betweeness on a probabilistic network
 * @param graph input graph
 * @return A vector of ego betweeness for each vertex in the graph
  **/
std::vector<double>
slow_ego_betweeness_approximation(
    ProbabilisticNetwork * graph
){
    auto adjMatrix = to_adjacency_matrix(graph);
    int numV = graph->vertices()->size();
    std::vector<double> approxEgoBtw (numV);
    for (int v = 0; v < numV; v++){
        for (int i = 0; i < numV-1; i++){
            for (int j = (i+1); j < numV; j++){
                approxEgoBtw[v] = approxEgoBtw[v] + adjMatrix[v][i] * adjMatrix[v][j] * (1 - adjMatrix[i][j]);
            }
        }
    }
    return approxEgoBtw;
}



}
}
