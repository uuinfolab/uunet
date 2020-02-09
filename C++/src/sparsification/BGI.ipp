/**
 * History:
 * - 2020.02.06 file created by Oskar
 */

#include <list>
#include "networks/ProbabilisticNetwork.hpp"
#include "measures/size.hpp"


namespace uu {
namespace net {
/**
 * Checks if the two edges have the same vertice names (Doesnt check their probabilities)
 **/
bool
edge_equals(
    const Edge *e1,
    const Edge *e2
)
{
    auto v11 = e1->v1->to_string();
    auto v12 = e1->v2->to_string();

    auto v21 = e2->v1->to_string();
    auto v22 = e2->v2->to_string();

    return ( v11 == v21 && v12 == v22 ) || ( v11 == v22 && v12 == v21);
}

/**
 * Removes the intersection of g1 and g2 from g1
 * @param g1 Graph to remove the intersection from
 * @param g2 Second graph to get the intersection
 **/
void 
remove_intersection(
    ProbabilisticNetwork* g1, 
    ProbabilisticNetwork* g2
)
{
    for (auto edge: *g1->edges())
    {
        for (auto edge2: *g2->edges())
        {    
            if(edge_equals(edge, edge2))
            {
                g1->edges()->erase(edge);
            }
        }        
    }
}

/**
 * Adds an edges and its vertices into g
 * @param g1 Graph to add edge to
 * @param e The edge to add
 * @param p The probability of the edge
 **/
void add_edge_to_graph
(
    ProbabilisticNetwork* g,
    const Edge * e,
    double p
)
{
    auto v1 = e->v1->to_string();
    auto v2 = e->v2->to_string();

    g->vertices()->add(v1);
    g->vertices()->add(v2);

    auto g_v1 = g->vertices()->get(v1);
    auto g_v2 = g->vertices()->get(v2);

    auto newEdge = Edge::create(g_v1, g_v2, EdgeDir::UNDIRECTED);

    g->edges()->add(newEdge);
    
    g->set_prob( g->edges()->get(g_v1, g_v2), p );
}


/**
 * Adds all edges and vertices from g2 into g1 (Union)
 * @param g1 Graph to add edges to
 * @param g2 Graph to add edges from
 **/
void add_graphs
(
    ProbabilisticNetwork* g1, 
    ProbabilisticNetwork* g2
)
{
    for (auto edge: *g2->edges())
    {    
        add_edge_to_graph(g1, edge, g2->get_prob(edge).value);
    }        
}


/**
 * Duplicates a probabilistic graph to a new object
 * @return The duplicated graph
 * @param g The graph to copy from
 **/
std::unique_ptr<ProbabilisticNetwork>
duplicate_graph
(
    ProbabilisticNetwork* g
)
{
    std::string name = "Copy of " + g->name;
    auto newGraph =  std::make_unique<ProbabilisticNetwork> (name, EdgeDir::UNDIRECTED, true);

    add_graphs(newGraph.get(), g);
    return newGraph;
}

/**
 * Helper function for Maximum Spanning Tree
 * Gets the edge with highest probability in the currentEdges list
 **/
const Edge *
getHighestEdge
(
    ProbabilisticNetwork* g,
    std::list< const Edge *>* currentEdges
)
{
    double highestValue = 0;
    const Edge * highestEdge = nullptr;
    for (auto edge: *currentEdges)
    {
        if (g->get_prob(edge).value > highestValue)
        {
            highestValue = g->get_prob(edge).value;
            highestEdge = edge;
        }
    }

    currentEdges->remove(highestEdge);
    return highestEdge;
}

/**
 * Helper function for Maximum Spanning Tree
 * Sets the vertex that the edge e is connected to as visited
 **/
const Vertex *
set_visited(
    ProbabilisticNetwork* g,
    bool visited[],
    const Edge * e
)
{
    const Vertex * temp = nullptr;
    if(!visited[ g->vertices()->index_of(e->v1) ])
    {  
        temp = e->v1;
        visited[ g->vertices()->index_of(e->v1) ] = true;
    } else {
        temp = e->v2;
        visited[ g->vertices()->index_of(e->v2) ] = true;
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
    bool visited[],
    const Edge * e
)
{
    return (
        visited[ g->vertices()->index_of(e->v1) ]
        &&
        visited[ g->vertices()->index_of(e->v2) ]
    );
}

/**
 * Creates a Maximum Spanning Tree using Prims algorithm
 * @return Maximum Spanning Tree
 * @param g Input graph to get the spanning tree from
 **/
std::unique_ptr<ProbabilisticNetwork>
maximum_spanning_tree
(
    ProbabilisticNetwork* g,
    std::string name = "Maximum Spanning tree"
)
{    

    // Initialize
    auto MST =  std::make_unique<ProbabilisticNetwork> (name, EdgeDir::UNDIRECTED, true);
    bool visited [g->vertices()->size()] = { false };
    int amountVisited = 0;
    int amountVertices = g->vertices()->size();
    std::list< const Edge *> currentEdges;

    //Initially choose a random vertex.
    auto firstV = g->vertices()->get_at_random();
    visited[g->vertices()->index_of(firstV)] = true;
    amountVisited++;

    

    // Push all edges connected to first vertex
    for (auto edge: *g->edges()->incident(firstV, EdgeMode::INOUT))
    {
        currentEdges.push_front(edge);
    }
 
    // Loop through untill all vertices are visited
    //while (amountVisited < amountVertices)
    while (currentEdges.size() > 0)
    {
        auto e = getHighestEdge(g, &currentEdges);
        if (!is_visited(g, visited, e))
        {
            auto v = set_visited(g, visited, e);
            amountVisited++;
            add_edge_to_graph(MST.get(), e, g->get_prob(e).value);

            // Add all edges from current vertice unless they are visited already
            for (auto currentEdge: *g->edges()->incident(v, EdgeMode::INOUT))
            {
                
                if (is_visited(g, visited, currentEdge))
                    continue;
                
                currentEdges.push_front(currentEdge);
            }
        }
    }

    // Done, return Maximum Spanning Tree
    return MST;
}

/**
 * Generates a Backbone graph
 * @return Backbone grap
 * @param original_graph Input graph to get the backbone graph from
 * @param sparsRatio Sparsification ratio
 * @param spanRatio Spanning ratio
 **/
std::unique_ptr<Network>
generate_backbone(
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

    while (size(Gb.get()) < spanRatio * size(original_graph))
    {
        auto F = maximum_spanning_tree(Gcopy.get());
        add_graphs(Gb.get(), F.get());      // can be optimized, dont need to set probabilities
                                           // and can add checks for if the edge alraedy exists
        remove_intersection(Gcopy.get(), F.get());
    }
    
    while (size(Gb.get()) < sparsRatio * size(original_graph))
    {
        auto e = Gcopy->edges()->get_at_random();
        
        double r = ((double) rand() / (RAND_MAX));
        if (Gcopy->get_prob(e).value > r)
        {
            add_edge_to_graph(Gb.get(), e, Gcopy->get_prob(e).value);
            Gcopy->edges()->erase(e);
        }
    } 

    return Gb;
}

}
}
