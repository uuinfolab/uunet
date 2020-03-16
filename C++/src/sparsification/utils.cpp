/**
 * History:
 * - 2020.02.17 file created by Oskar
 **/

#include "networks/ProbabilisticNetwork.hpp"
#include "sparsification/utils.hpp"

namespace uu {
namespace net {


/**
 *  Calculates one step
 *  @param edge The edge to get the probability from and the vertices
 *  @param step_size The step size used for the formula
 *  @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 *  @param always_use_step_size if true then apply step_size instantly, otherwise only apply step_size if the condition entropy_formula(new_p) > entropy_formula(previous_p) is true
 **/
double
stp
(
    ProbabilisticNetwork * previous_graph,
    ProbabilisticNetwork * current_graph,
    const Edge * edge,
    double step_size,
    bool use_absolute,
    bool always_use_step_size
)
{
    auto previous_p = current_graph->get_prob(edge).value;
    auto u0 = edge->v1;
    auto v0 = edge->v2;
    auto pi_u = pi(current_graph, u0, use_absolute);
    auto pi_v = pi(current_graph, v0, use_absolute);
    double SA_v = a_discrepancy(previous_graph, current_graph, v0);
    double SA_u = a_discrepancy(previous_graph, current_graph, u0);
    double delta = ((pi_v * SA_u + pi_u * SA_v) / (pi_u + pi_v));

    //std::cout << v0->to_string() << ": " << SA_v << ", pi: " << pi_v << ",   " << u0->to_string() << ": " << SA_u << ", pi: " << pi_u << std::endl;

    double new_p;
    if (always_use_step_size)
    {
        new_p = previous_p + step_size * delta;
    } else
    {
        new_p = previous_p + delta;
        if (new_p < 0){
            new_p = 0;
        } else if ( new_p > 1) {
            new_p = 1;
        }
        if ( entropy_formula(new_p) > entropy_formula(previous_p) ){
            new_p = previous_p + step_size * delta;
        }
    }

    if (new_p < 0){
        new_p = 0;
    } else if ( new_p > 1) {
        new_p = 1;
    }
    return new_p;
}


/**
 *  The objective function of GDB, returns the sum of discrepancies of the whole graph
 *  @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
double
objective_function
(
    ProbabilisticNetwork* graph, 
    ProbabilisticNetwork* modified_graph, 
    bool use_absolute
)
{
    double sum = 0;
    for( auto vertex: *graph->vertices())
    {
        if (use_absolute)
        {
            sum += pow(a_discrepancy(graph, modified_graph, vertex), 2);
        } else {
            sum += pow(r_discrepancy(graph, modified_graph, vertex), 2);
        }
    }
    return sum;
}

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
 *  Returns 1 if use_absolute is true, otherwise return the cut size of v
 *  @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
double
pi
(
    ProbabilisticNetwork * g,
    const Vertex * v,
    bool use_absolute 
)
{
    if(use_absolute)
    {
        return 1;
    } else {
        return sum_p_from_v(g, v);
    }
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
 *  Calculates the absolute discrepancy of v between graph and modified_graph
 **/
double
a_discrepancy
(
    ProbabilisticNetwork* graph,
    ProbabilisticNetwork* modified_graph,
    const Vertex * v
)
{
    return sum_p_from_v(graph, v) - sum_p_from_v(modified_graph, v);
}


/**
 *  Calculates the relative discrepancy of v between graph and modified_graph
 **/
double
r_discrepancy
(
    ProbabilisticNetwork* graph,
    ProbabilisticNetwork* modified_graph,
    const Vertex * v
)
{
    auto sum1 = sum_p_from_v(graph, v);
    auto sum2 = sum_p_from_v(modified_graph, v);
    return (sum1 - sum2) / sum1;
}


/**
 *  Adds all edges from source graph to target graph
 *  Note: this modifies the target graph
 **/
void
graph_add_2
(
    const Network * source,
    Network * target
)
{
    for (auto vertex: *source->vertices())
    {
        target->vertices()->add(vertex);
    }
    for (auto edge: *source->edges())
    {
        target->edges()->add(edge);
    }
}

/**
 *  Adds all edges and probabilities from source graph to target graph
 *  Note: this modifies the target graph
 **/
void
graph_add_prob
(
    const ProbabilisticNetwork * source,
    ProbabilisticNetwork * target
)
{
    for (auto vertex: *source->vertices())
    {
        target->vertices()->add(vertex);
    }
    for (auto edge: *source->edges())
    {
        target->edges()->add(edge);
        target->set_prob(edge, source->get_prob(edge).value);
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
    std::string name = g->name + '*';
    auto newGraph =  std::make_unique<ProbabilisticNetwork> (name, EdgeDir::UNDIRECTED, true);
    graph_add_prob(g, newGraph.get());
    return newGraph;
}



}
}