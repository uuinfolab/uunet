/**
 * History:
 * - 2020.04.27 file created by Oskar
 **/

#include <time.h>  
#include "networks/ProbabilisticNetwork.hpp"
#include "algorithms/BFS.hpp"
#include "creation/empty_copy.hpp"
#include "sparsification/utils.hpp"
#include "sparsification/reliability.hpp"

namespace uu {
namespace net {





/**
 * Calculates the reliability to reach every other node from s in probabilistic networks
 * @param graph input graph
 * @param start start vertex
 * @param times_to_run amount of times to run
 * @return an array of sums of probabilities for each vertex
  **/
std::map<std::string, double>
reliability_s_to_all(
    ProbabilisticNetwork * graph,
    const Vertex * start,
    int times_to_run
)
{
    // Initiate random seed using time
    srand(time(NULL));
    std::map<std::string, double> results;
    
    // Run times_to_run times
    for (int i = 0; i < times_to_run; i++)
    {
        std::vector<int> visited (graph->vertices()->size(), 0);
        std::vector<const Vertex *> vertexQueue;

        // Add start vertex
        vertexQueue.push_back(start);
        visited[graph->vertices()->index_of(start)] = 1;

        // Work through the queue until it's empty
        while(!vertexQueue.empty()){
            auto current = vertexQueue.back();
            vertexQueue.pop_back();
            results[current->to_string()] += 1;
            for (auto neighbor: *graph->edges()->neighbors(current))
            {
                int neighbor_i = graph->vertices()->index_of(neighbor);
                // If it's visited then skip
                if (visited[neighbor_i]) 
                    continue;

                auto edge = graph->edges()->get(current, neighbor);
                // Sample edge
                double randomProb = ((double) rand() / (RAND_MAX));
                if( randomProb <= graph->get_prob(edge).value)
                {
                    visited[neighbor_i] = 1;
                    vertexQueue.push_back(neighbor);
                }
            }
        }
    }
    
    // Calculate the avarage for each vertex
    for (auto vertex: *graph->vertices())
    {
        results[vertex->to_string()] = results[vertex->to_string()] / (double)times_to_run;
    }

    // Set starting node to -1
    // Maybe better to set it to 1 since it can always find itself?
    results[start->to_string()] = -1;
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
   // Initiate random seed using time
    srand(time(NULL));
    double result;
    
    // Run times_to_run times
    for (int i = 0; i < times_to_run; i++)
    {
        std::vector<int> visited (graph->vertices()->size(), 0);
        std::vector<const Vertex *> vertexQueue;

        // Add start vertex
        vertexQueue.push_back(start);
        visited[graph->vertices()->index_of(start)] = 1;

        // Work through the queue until it's empty
        while(!vertexQueue.empty()){
            auto current = vertexQueue.back();
            vertexQueue.pop_back();
            
            // If we've found the target, increment result and break the current iteration
            if (current == target)
            {
                result += 1;
                break;
            }

            for (auto neighbor: *graph->edges()->neighbors(current))
            {
                int neighbor_i = graph->vertices()->index_of(neighbor);
                // If it's visited then skip
                if (visited[neighbor_i]) 
                    continue;

                auto edge = graph->edges()->get(current, neighbor);
                // Sample edge
                double randomProb = ((double) rand() / (RAND_MAX));
                if( randomProb <= graph->get_prob(edge).value)
                {
                    visited[neighbor_i] = 1;
                    vertexQueue.push_back(neighbor);
                }
            }
        }
    }
    
    // Return avaraged result
    return result / (double)times_to_run;
}











}
}
