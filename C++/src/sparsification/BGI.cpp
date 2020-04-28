/**
 * History:
 * - 2020.02.06 file created by Oskar
 */

#include <set>
#include "networks/ProbabilisticNetwork.hpp"
#include "sparsification/utils.hpp"
#include "sparsification/BGI.hpp"


namespace uu {
namespace net {


struct multiset_comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        return l.first > r.first;
    }
};

typedef std::pair<double, const Edge *> prob_edge;
typedef std::multiset< prob_edge, multiset_comp > multiset_edge_pair;

/**
 * Removes the intersection of g1 and g2 from g1
 * @param g1 Graph to remove the intersection from
 * @param g2 Second graph to get the intersection
 **/
void 
remove_intersection(
    Network* g1, 
    Network* g2
)
{
    for (auto edge: *g1->edges())
    {
        for (auto edge2: *g2->edges())
        {    
            if(edge == edge2)
            {
                g1->edges()->erase(edge);
            }
        }        
    }
}


/**
 * Helper function for Maximum Spanning Tree
 * Gets the edge with highest probability in the currentEdges list
 **/
const Edge *
popHighestEdge
(
    multiset_edge_pair *currentEdges
)
{
    auto edgepair = *currentEdges->begin();
    currentEdges->erase(edgepair);
    return edgepair.second;
}

/**
 * Helper function for Maximum Spanning Tree
 * Sets the vertex that the edge e is connected to as visited
 **/
const Vertex *
set_visited(
    ProbabilisticNetwork* g,
    std::vector<int> *visited,
    const Edge * e
)
{
    const Vertex * temp = nullptr;
    if(!(*visited)[ g->vertices()->index_of(e->v1) ])
    {  
        temp = e->v1;
        (*visited)[ g->vertices()->index_of(e->v1) ] = 1;
    } else {
        temp = e->v2;
        (*visited)[ g->vertices()->index_of(e->v2) ] = 1;
    }
    return temp;
}


/**
 * Helper function for Maximum Spanning Tree
 * Checks if either vertex from the edge e is visited
 **/
bool
is_visited(
    ProbabilisticNetwork* g,
    std::vector<int> *visited,
    const Edge * e
)
{
    return (
        (*visited)[ g->vertices()->index_of(e->v1) ]
        &&
        (*visited)[ g->vertices()->index_of(e->v2) ]
    );
}

/**
 * Creates a Maximum Spanning Tree using Prims algorithm
 * @return Maximum Spanning Tree
 * @param g Input graph to get the spanning tree from
 **/
std::unique_ptr<Network>
maximum_spanning_tree
(
    ProbabilisticNetwork* g,
    std::string name = "Maximum Spanning tree"
)
{    

    // Initialize
    auto MST =  std::make_unique<Network> (name, EdgeDir::UNDIRECTED, true);
    for (auto vertex: *g->vertices())
    {
        MST->vertices()->add(vertex);
    }
    std::vector<int> visited (g->vertices()->size(), 0);
    int amountVisited = 0;
    multiset_edge_pair currentEdges;

    //Initially choose a random vertex.
    auto firstV = g->vertices()->get_at_random();
    visited[g->vertices()->index_of(firstV)] = 1;
    amountVisited++;

    // Push all edges connected to first vertex
    for (auto edge: *g->edges()->incident(firstV, EdgeMode::INOUT))
    {   
        currentEdges.insert( std::make_pair( g->get_prob(edge).value, edge) );
    }
 
    // Loop through untill all vertices are visited
    while (currentEdges.size() > 0)
    {
        auto e = popHighestEdge(&currentEdges);
        if (!is_visited(g, &visited, e))
        {
            auto v = set_visited(g, &visited, e);
            amountVisited++;
            MST->edges()->add( e );

            // Add all edges from current vertice unless they are visited already
            for (auto currentEdge: *g->edges()->incident(v, EdgeMode::INOUT))
            {
                if (is_visited(g, &visited, currentEdge))
                    continue;
                
                currentEdges.insert( std::make_pair( g->get_prob(currentEdge).value, currentEdge) );
            }
        }
    }

    // Done, return Maximum Spanning Tree
    return MST;
}

/**
 * Generates a Backbone graph
 * @return Backbone graph
 * @param original_graph Input graph to get the backbone graph from
 * @param sparsRatio Sparsification ratio
 * @param spanRatio Spanning ratio
 **/
std::unique_ptr<Network>
BGI(
    ProbabilisticNetwork* original_graph,
    float sparsRatio,
    float spanRatio
)
{
    // set up nano-seconds
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    // seed rand using nano-seconds
    srand((time_t)ts.tv_nsec);

    auto Gcopy = duplicate_graph(original_graph);
    
    std::string name = "Backbone Graph";
    auto Gb = maximum_spanning_tree(Gcopy.get(), name);
    remove_intersection(Gcopy.get(), Gb.get());

    while (Gb->edges()->size() < spanRatio * original_graph->edges()->size())
    {
        auto F = maximum_spanning_tree(Gcopy.get());
        graph_add_2(F.get(), Gb.get());
        remove_intersection(Gcopy.get(), F.get());
    }
    
    while (Gb->edges()->size() < sparsRatio * original_graph->edges()->size())
    {
        auto e = Gcopy->edges()->get_at_random();
        
        double r = ((double) rand() / (RAND_MAX));
        if (Gcopy->get_prob(e).value > r)
        {
            Gb->edges()->add( e );
            Gcopy->edges()->erase(e);
        }
    } 
    return Gb;
}

}
}
