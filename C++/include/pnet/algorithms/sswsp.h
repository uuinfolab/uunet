/**
 * History:
 * - 2018.08.29 file created.
 */

#ifndef UU_PNET_ALGORITHMS_SSWSP_H_
#define UU_PNET_ALGORITHMS_SSWSP_H_

#include <unordered_set>
#include <queue>
#include <cmath>
#include "core/exceptions/assert_not_null.h"
#include "net/measures/basic.h"
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeMode.h"
#include "pnet/measures/basic.h"


namespace uu {
namespace net {

/**
 * Returns the weighted shortest path length from an input vertex to all other vertices,
 * where the length is expressed as the sum of the weights of edges in the path.
 */
template<typename G>
    std::vector<double> single_source_weighted_path_length(
        const G* g,
        const Vertex* v,
        EdgeMode mode = EdgeMode::OUT
    );






    template<typename G>
    std::vector<double> single_source_weighted_path_length(
            const G* g,
            const Vertex* v,
            EdgeMode mode
    )
    {
    assert_not_null(g, "single_source_shortest_path", "g");
    assert_not_null(v, "single_source_shortest_path", "v");
    
    std::queue<const Vertex*> queue;
    std::vector<double> path_probabilities(order(g), 1000000);   //make inf better

    int vertex_position = g->vertices()->get_index(v);
    path_probabilities.at(vertex_position) = 0;        
    queue.push(v);

    while (queue.size() > 0)
    {
        const Vertex* current_vertex = queue.front();
        queue.pop();
                
        for (auto n: *g->edges()->neighbors(current_vertex, mode))
        {

            double w = -log10(is_neighbor(g,current_vertex,n,uu::net::EdgeMode::INOUT));

            if (path_probabilities.at(g->vertices()->get_index(n)) > path_probabilities.at(g->vertices()->get_index(current_vertex))+w)
            {   
                path_probabilities.at(g->vertices()->get_index(n)) = path_probabilities.at(g->vertices()->get_index(current_vertex))+w;
                queue.push(n);
            }
        }
    }

    for(unsigned int i = 0; i < order(g); i++)
    {
        path_probabilities.at(i) = std::pow(10,-path_probabilities.at(i));
    }
    
    return path_probabilities;
}


}
}

#endif
