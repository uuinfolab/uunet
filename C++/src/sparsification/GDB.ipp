/**
 * History:
 * - 2020.02.17 file created by Oskar
 **/

#include "networks/ProbabilisticNetwork.hpp"
#include "sparsification/utils.hpp"


namespace uu {
namespace net {




/**
 *  Returns the probability of an edge of a different graph by using the name of its vertices
 **/
double get_prob_from_graph
(
    ProbabilisticNetwork* g,
    const Edge * e
)
{
    auto v1 = e->v1->to_string();
    auto v2 = e->v2->to_string();
    auto g_v1 = g->vertices()->get(v1);
    auto g_v2 = g->vertices()->get(v2);
    return g->get_prob( g->edges()->get(g_v1, g_v2)).value;
}


/**
 *  The objective function of GDB, returns the sum of discrepancies of the whole graph
 *  @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
double
objective_function
(
    ProbabilisticNetwork* graph, 
    ProbabilisticNetwork* sparsified_graph, 
    bool use_absolute
)
{
    double sum = 0;
    for( auto vertex: *graph->vertices())
    {
        if (use_absolute)
        {
            sum += pow(a_discrepancy(graph, sparsified_graph, vertex), 2);
        } else {
            sum += pow(r_discrepancy(graph, sparsified_graph, vertex), 2);
        }
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
 *  Generates a sparsified graph using the Gradient Descent Backbone algorithm
 *  @param uncertain_graph Original uncertain graph
 *  @param backbone_graph Backbone graph generated from BGI
 *  @param entropy_step_size The step size
 *  @param improvement_threshold 
 *  @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
std::unique_ptr<ProbabilisticNetwork>
GDB(
    ProbabilisticNetwork * uncertain_graph,
    Network * backbone_graph,
    double entropy_step_size,
    double improvement_threshold,
    bool use_absolute
)
{
    auto current_graph =  std::make_unique<ProbabilisticNetwork> 
                        ("Sparse probabilistic network", EdgeDir::UNDIRECTED, true);

    for ( auto edge: *backbone_graph->edges())
    {
        auto prob = get_prob_from_graph(uncertain_graph, edge);
        add_edge_to_graph(current_graph.get(), edge, prob);
    }

    double Dcurrent;
    std::unique_ptr<ProbabilisticNetwork> previous_graph = duplicate_graph(uncertain_graph);
    std::unique_ptr<ProbabilisticNetwork> previous_2_graph = nullptr;

    do
    {
        // Move current graph back to previous graph and so on
        std::swap(previous_graph, previous_2_graph);
        std::swap(current_graph, previous_graph);
 
        current_graph = duplicate_graph(previous_graph.get());

        Dcurrent = objective_function(previous_2_graph.get(), current_graph.get(), use_absolute);

        std::cout << "obj func: " << Dcurrent << "\n" << std::endl;

        for ( auto edge: *current_graph->edges())
        {
            auto p_e = get_prob_from_graph(current_graph.get(), edge);
            auto u0 = edge->v1;
            auto v0 = edge->v2;

            auto pi_u = pi(current_graph.get(), u0, use_absolute);
            auto pi_v = pi(current_graph.get(), v0, use_absolute);

            double SA_v;
            double SA_u;

            SA_v = a_discrepancy(previous_2_graph.get(), current_graph.get(), v0);
            SA_u = a_discrepancy(previous_2_graph.get(), current_graph.get(), u0);
        
            std::cout << v0->to_string() << ": " << SA_v << ", pi: " << pi_v << 
                 ",   " << u0->to_string() << ": " << SA_u << ", pi: " << pi_u << std::endl;

            auto stp = (pi_v * SA_u + pi_u * SA_v) / (pi_u + pi_v);

            auto prob_e = p_e + stp;
            std::cout << "p_edge: " << p_e << " + " << "stp: " << stp << " = " << prob_e << "\n" << std::endl;

            if (prob_e < 0){
                prob_e = 0;
            } else if ( prob_e > 1) {
                prob_e = 1;
            } else if ( entropy_formula(prob_e) > entropy_formula(p_e) ){
                prob_e = p_e + entropy_step_size * stp;
            }
            current_graph->set_prob(edge, prob_e);    
        }

        std::cout << "obj func: " << objective_function(previous_2_graph.get(), current_graph.get(), use_absolute) << "\n" << std::endl;
        std::cout << Dcurrent - objective_function(previous_2_graph.get(), current_graph.get(), use_absolute)  << std::endl;
        std::cout << fabs(  Dcurrent - objective_function(previous_2_graph.get(), current_graph.get(), use_absolute) )  << std::endl;
        std::cout << (fabs(  Dcurrent - objective_function(previous_2_graph.get(), current_graph.get(), use_absolute) ) <= improvement_threshold)  << std::endl;
        std::cout << improvement_threshold << std::endl;
        std::cout << "while: " <<(! abs(  Dcurrent - objective_function(previous_2_graph.get(), current_graph.get(), use_absolute) ) <= improvement_threshold) << std::endl;

    } while
    (
        ! (fabs(  Dcurrent - objective_function(previous_2_graph.get(), current_graph.get(), use_absolute) ) <= improvement_threshold)
    );

    return current_graph;
}



/**
// Different version of GDB where we save the new calculated values to a "next" graph so that the next edges in the same iterations don't use updated values prematurely

std::unique_ptr<ProbabilisticNetwork>
GDB_previous_values(
    ProbabilisticNetwork * uncertain_graph,
    Network * backbone_graph,
    double entropy_step_size,
    double improvement_threshold,
    bool use_absolute        // If true, use absolute discrepancy, if false, use relative discrepancy
)
{
    auto current_graph =  std::make_unique<ProbabilisticNetwork> 
                        ("Sparse probabilistic network", EdgeDir::UNDIRECTED, true);

    for ( auto edge: *backbone_graph->edges())
    {
        auto prob = get_prob(uncertain_graph, edge);
        add_edge_to_graph(current_graph.get(), edge, prob);
    }

    double Dcurrent;
    double previous_discrepancy [current_graph->vertices()->size()];
    auto next_graph = duplicate_graph(current_graph.get());
    bool first_run = true;

    
    do
    {
        //Calculate discrepancy between previous iteration and current
        for( auto vertex: *current_graph->vertices())
        {
            int i = current_graph->vertices()->index_of(vertex);
            double val;
            if(first_run)
            {
                val = a_discrepancy(uncertain_graph, next_graph.get(), vertex);
            } else {
                val = a_discrepancy(current_graph.get(), next_graph.get(), vertex);
            }
            std::cout << "discrepancy of " << vertex->to_string() << ": " << val << std::endl;
            previous_discrepancy[i] = val;
        }

        std::cout << std::endl;

        // Reuse the old graph so we dont have to create a new network for every iteration
        // previous iterations next_graph becomes the current_graph
        // and we reuse previous iterations current_graph as this iterations next_graph
        //      and overwrite its values with new ones
        std::swap(current_graph, next_graph);

        //TODO: Note: we're going through them in order of ID
        // Might be able to try different ordering methods

        Dcurrent = objective_function(uncertain_graph, current_graph.get(), use_absolute);
        std::cout << "obj func: " << Dcurrent << std::endl;

        for ( auto edge: *current_graph->edges())
        {
            auto p_e = get_prob(uncertain_graph, edge);
            auto u0 = edge->v1;
            auto v0 = edge->v2;


            auto pi_u = pi(current_graph.get(), u0, use_absolute);
            auto pi_v = pi(current_graph.get(), v0, use_absolute);


            double SA_v = previous_discrepancy[ current_graph->vertices()->index_of(v0)];
            double SA_u = previous_discrepancy[ current_graph->vertices()->index_of(u0)];
            


            std::cout << 
            u0->to_string() << " " << v0->to_string() << " " 
            << pi_v << " " << pi_u << " " << SA_u << " " << SA_v << std::endl;



            auto stp = (pi_v * SA_u + pi_u * SA_v) / (pi_u + pi_v);



            std::cout << "p_e + stp: " << p_e << " + " << stp << "\n" << std::endl;
            auto prob_e = p_e + stp;

            if (prob_e < 0){
                prob_e = 0;
            } else if ( prob_e > 1) {
                prob_e = 1;
            } else if ( entropy_formula(prob_e) > entropy_formula(p_e) ){
                prob_e = p_e + entropy_step_size * stp;
            }
            next_graph->set_prob(edge, prob_e);    
        }
    } while
    (
        ! abs(
            Dcurrent - objective_function(uncertain_graph, next_graph.get(), use_absolute)
        ) <= improvement_threshold
    );

    return next_graph;
}
*/


}
}
