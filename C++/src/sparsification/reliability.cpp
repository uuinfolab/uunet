/**
 * History:
 * - 2020.04.27 file created by Oskar
 **/

#include <ctime>  
#include "networks/ProbabilisticNetwork.hpp"
#include "algorithms/BFS.hpp"
#include "sparsification/utils.hpp"
#include "sparsification/reliability.hpp"

namespace uu {
namespace net {




bool
sample_edge(
    ProbabilisticNetwork * graph,
    const Edge * edge
)
{
    return (((double) rand() / (RAND_MAX)) <= graph->get_prob(edge).value);
}

std::pair<double, std::unique_ptr<ProbabilisticNetwork>>
sample_graph(
    ProbabilisticNetwork * graph
)
{
    // set up nano-seconds
    // struct timespec ts;
    // clock_gettime(CLOCK_MONOTONIC, &ts); // Might not work on windows systems
    // srand((time_t)ts.tv_nsec);

    double mulsum = 1;
    auto sampled_graph = duplicate_graph(graph);
    for (auto edge: *graph->edges())
    {
        if(sample_edge(graph, edge)){
            mulsum *= graph->get_prob(edge).value;
        } else {
            mulsum *= (1- graph->get_prob(edge).value);
            sampled_graph->edges()->erase(edge);
        }
    }

    return std::make_pair(mulsum, std::move(sampled_graph));
}



/**
 * Calculates the reliability to reach every other node from s in probabilistic networks
 * @param graph input graph
 * @param start start vertex
 * @param times_to_run amount of times to run
 * @return an array of sums of probabilities for each vertex
  **/
std::vector<double>
reliability_s_to_all(
    ProbabilisticNetwork * graph,
    const Vertex * start,
    int times_to_run
)
{
    int numV = graph->vertices()->size();
    std::vector<double> results (numV);

    for (auto vertex: *graph->vertices())
    {
        int curr_i = graph->vertices()->index_of(vertex);
        double vertexSum = 0;
        for (int i = 0; i < times_to_run; i++)
        {
            double sum = 0;
            auto sampled = sample_graph(graph);
            sum += sampled.first;
            uu::net::BFS<uu::net::ProbabilisticNetwork> bfs(sampled.second.get(), start, uu::net::EdgeMode::INOUT);
            const uu::net::Vertex* current_vertex = bfs.get_next();
            while(current_vertex != nullptr){
                sum += sampled.first;
                current_vertex = bfs.get_next();
            }
            vertexSum += sum; 
        }
        results[curr_i] = vertexSum;
    }
    return results;
}


/**
 * Calculates the reliability to reach t from s in probabilistic networks
 * @param graph input graph
 * @param start start vertex
 * @param target target vertex
 * @param times_to_run amount of times to run
 * @return the sum of probabilities
  **/
double
reliability_s_to_t(
    ProbabilisticNetwork * graph,
    const Vertex * start,
    const Vertex * target,
    int times_to_run
)
{
    double sum = 0;
    for (int i = 0; i < times_to_run; i++)
    {
        auto sampled = sample_graph(graph);
        uu::net::BFS<uu::net::ProbabilisticNetwork> bfs(sampled.second.get(), start, uu::net::EdgeMode::INOUT);
        const uu::net::Vertex* current_vertex = bfs.get_next();
        double finalProb = 0;
        while(current_vertex != nullptr){
            if(current_vertex == target){
                finalProb = sampled.first;
                break;
            }
            current_vertex = bfs.get_next();
        }
        sum += finalProb;
    }
    return sum;
}











}
}
