/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_MEASURES_TEST_H_
#define UU_NET_MEASURES_TEST_H_


#include <unordered_set>
#include <queue>
#include "core/exceptions/assert_not_null.hpp"
#include "objects/Vertex.hpp"
#include "objects/EdgeMode.hpp"

namespace uu {
namespace net {

/**
 * Returns true is g is bipartite.
 * A bipartite graph is one for which its vertices can
 * be partitioned into two independent sets.
 * An independent set is a set of vertices V' in V where
 * for all a, b in V' a and b are not adjacent.
 * Complexity: O(n+m)
 */
template<typename G>
bool
is_bipartite(
    const G*  g
);

/**
 * Returns true is g1 and g2 are isomorphic.
 *
 * Complexity: non polynomial
 *
 * @todo NOT IMPLEMENTED
 */
template<typename G>
bool
are_isomorphic(
    const G*  g1,
    const G*  g2
);

    
// Implementations
    
template<typename G>
bool
is_bipartite(
    const G*  g
)
    {
        
        core::assert_not_null(g, "is_bipartite", "g");
        
        // Each vertex can be assigned to one of two partitions: A (represented by value true)
        // or B (represented by value false)
        std::unordered_map<const Vertex*, bool> partition;
        
        // We perform a BFS from each vertex, using a queue
        
        std::queue<const Vertex*> queue;
        
        for (auto v: *g->vertices())
        {
            auto p = partition.find(v);
            
            // We process vertex v only if it has not been assigned to any partition yet
            
            if (p == partition.end())
            {
                queue.push(v);
                partition[v] = true;
                
                while (queue.size()>0)
                {
                    auto u = queue.front();
                    queue.pop();
                    bool part_u = partition[u];
                    
                    // We try to assign all neighbors of u to the other partition (!part_u)
                    
                    for (auto n: *g->edges()->neighbors(u, EdgeMode::INOUT))
                    {
                        auto p_n = partition.find(n);
                        
                        if (p_n == partition.end())
                        {
                            // Vertex not assigned to any partition yet, so we assign it
                            
                            partition[n] = !part_u;
                            queue.push(n);
                        }
                        else
                        {
                            // Vertex already in a partition. We check if it is the right one.
                            bool part_n = p_n->second;
                            
                            if (part_n == part_u)
                            {
                                // Two neighbors in the same partition: test failed.
                                
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    
}
}

#endif
