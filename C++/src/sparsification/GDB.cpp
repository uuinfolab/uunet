/**
 * History:
 * - 2020.02.17 file created by Oskar
 **/

#include "networks/ProbabilisticNetwork.hpp"
#include "sparsification/utils.hpp"
#include "sparsification/GDB.hpp"


namespace uu {
namespace net {



void
copy_probabilities
(
    ProbabilisticNetwork * from,
    ProbabilisticNetwork * to
)
{
    for (auto edge: *from->edges())
    {
        to->set_prob(edge, from->get_prob(edge).value);
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
    auto current_graph =  std::make_unique<ProbabilisticNetwork> ("Sparse probabilistic network", EdgeDir::UNDIRECTED, true);
    for (auto vertex: *uncertain_graph->vertices())
    {
        current_graph->vertices()->add(vertex);
    }
    for ( auto edge: *backbone_graph->edges())
    {
        auto prob = uncertain_graph->get_prob(edge).value;
        current_graph->edges()->add(edge);
        current_graph->set_prob(edge, prob);
    }
    double Dcurrent;
    std::unique_ptr<ProbabilisticNetwork> previous_graph = duplicate_graph(uncertain_graph);
    std::unique_ptr<ProbabilisticNetwork> previous_2_graph = duplicate_graph(current_graph.get());

    bool usingOriginal = true;

    int current_iteration = 0;
    int amount_edges = current_graph->edges()->size();
    int ten_percent_edges = amount_edges/10;

    do
    {
        current_iteration++;
        if (current_iteration % 20 == 0){
            std::cout << "GDB iteration: " << current_iteration << std::endl;
            
            //Run at most 200 iterations
            if (current_iteration == 200){
                break;
            }
        }


        // Move current graph back to previous graph and so on
        std::swap(previous_graph, previous_2_graph);
        std::swap(current_graph, previous_graph);
        //current_graph = duplicate_graph(previous_graph.get());
        copy_probabilities(previous_graph.get(), current_graph.get());

        Dcurrent = objective_function(previous_2_graph.get(), current_graph.get(), use_absolute);
        for ( auto edge: *current_graph->edges())
        {
            double new_prob = stp(previous_2_graph.get(), current_graph.get(), edge, entropy_step_size, use_absolute, false);
            current_graph->set_prob(edge, new_prob);    
        }
        if (usingOriginal)
        {
            usingOriginal = false;
            previous_2_graph = duplicate_graph(current_graph.get());
        }
        

    } while
    (
        ! (fabs(  Dcurrent - objective_function(previous_graph.get(), current_graph.get(), use_absolute) ) <= improvement_threshold)
    );

    return current_graph;
}

}
}
