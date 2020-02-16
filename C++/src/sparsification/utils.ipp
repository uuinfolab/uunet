/**
 * History:
 * - 2020.02.17 file created by Oskar
 **/

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {


double
sum_p_from_v
(
    ProbabilisticNetwork* g,
    const Vertex * v
)
{
    double sum = 0;
    auto v_string = v->to_string();
    auto vertex = g->vertices()->get(v_string);
    for ( auto neighbour: *g->edges()->incident(vertex))
    {
        sum += g->get_prob(neighbour).value;
    }
    return sum;
}




/**
 *  The entropy formula
 **/
double
entropy_formula
(
    double p
)
{
    double q = 1 - p;
    if (p == 0)
    {
        return (0 - (q) * log2(q));    
    } 
    else if (q == 0) 
    {
        return ((-p) * log2(p) - 0);
    } 
    else
    {
        return ((-p) * log2(p) - (1 - p) * log2(1-p));
    }
}


/**
 *  Calculates the entropy of the whole graph
 **/
double
entropy_of_graph
(
    ProbabilisticNetwork* g
)
{
    double sum = 0;
    for( auto edge: *g->edges())
    {
        sum += entropy_formula(g->get_prob(edge).value);
    }
    return sum;
}

/**
 *  Calculates the absolute discrepancy of v between graph and sparsified_graph
 **/
double
a_discrepancy
(
    ProbabilisticNetwork* graph,
    ProbabilisticNetwork* sparsified_graph,
    const Vertex * v
)
{
    return sum_p_from_v(graph, v) - sum_p_from_v(sparsified_graph, v);
}


/**
 *  Calculates the relative discrepancy of v between graph and sparsified_graph
 **/
double
r_discrepancy
(
    ProbabilisticNetwork* graph,
    ProbabilisticNetwork* sparsified_graph,
    const Vertex * v
)
{
    auto sum1 = sum_p_from_v(graph, v);
    auto sum2 = sum_p_from_v(sparsified_graph, v);
    return (sum1 - sum2) / sum1;
}


/**
 * Adds all edges and vertices from g2 into g1
 * Note, this modifies g1
 * @param g1 Graph to add edges to
 * @param g2 Graph to add edges from
 **/
void graph_union
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

    graph_union(newGraph.get(), g);
    return newGraph;
}



}
}