/**
 * History:
 * - 2020.02.17 file created by Oskar
 **/

#include "networks/ProbabilisticNetwork.hpp"
#include "sparsification/utils.hpp"
#include "sparsification/GDB.hpp"


namespace uu {
namespace net {



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
    std::unique_ptr<ProbabilisticNetwork> previous_2_graph = nullptr;
    do
    {
        // Move current graph back to previous graph and so on
        std::swap(previous_graph, previous_2_graph);
        std::swap(current_graph, previous_graph);
        current_graph = duplicate_graph(previous_graph.get());
        Dcurrent = objective_function(previous_2_graph.get(), current_graph.get(), use_absolute);
        //std::cout << "Current net: " << current_graph->name << std::endl; 
        //std::cout << "obj func: " << Dcurrent << std::endl;
        for ( auto edge: *current_graph->edges())
        {
            double new_prob = stp(previous_2_graph.get(), current_graph.get(), edge, entropy_step_size, use_absolute, false);
            current_graph->set_prob(edge, new_prob);    
        }
        // std::cout << "obj func after: " << objective_function(previous_graph.get(), current_graph.get(), use_absolute) << "\n" << std::endl;
        // for (auto el: *current_graph->edges())
        // {
        //     std::cout << el->v1->to_string() << "-" << current_graph->get_prob(el).value << "-" << el->v2->to_string() << "  ";
        // }
        // std::cout << std::endl;
    } while
    (
        ! (fabs(  Dcurrent - objective_function(previous_graph.get(), current_graph.get(), use_absolute) ) <= improvement_threshold)
    );

    return current_graph;
}



// Different version of GDB where we save the new calculated values to a "next" graph so that the next edges in the same iterations don't use updated values prematurely
std::unique_ptr<ProbabilisticNetwork>
GDB_2(
    ProbabilisticNetwork * uncertain_graph,
    Network * backbone_graph,
    double entropy_step_size,
    double improvement_threshold,
    bool use_absolute        // If true, use absolute discrepancy, if false, use relative discrepancy
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
    std::unique_ptr<ProbabilisticNetwork> previous_2_graph = nullptr;
    do
    {
        // Move current graph back to previous graph and so on
        std::swap(previous_graph, previous_2_graph);
        std::swap(current_graph, previous_graph);
        current_graph = duplicate_graph(previous_graph.get());
        Dcurrent = objective_function(previous_2_graph.get(), previous_graph.get(), use_absolute);
        // std::cout << "Current net: " << current_graph->name << std::endl; 
        // std::cout << "obj func: " << Dcurrent << "\n" << std::endl;
        for ( auto edge: *previous_graph->edges())
        {
            double new_prob = stp(previous_2_graph.get(), previous_graph.get(), edge, entropy_step_size, use_absolute, false);
            current_graph->set_prob(edge, new_prob);    
        }
        // std::cout << "obj func: " << objective_function(previous_graph.get(), current_graph.get(), use_absolute) << "\n" << std::endl;
    } while
    (
        ! (fabs(  Dcurrent - objective_function(previous_graph.get(), current_graph.get(), use_absolute) ) <= improvement_threshold)
    );

    return current_graph;
}


}
}
