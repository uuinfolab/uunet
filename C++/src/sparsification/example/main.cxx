#include <cmath>
#include <iostream>
#include <string>

#include "io/read_network.hpp"
#include "io/read_probabilistic_network.hpp"
#include "sparsification/BGI.hpp"

#include "networks/ProbabilisticNetwork.hpp"
#include "measures/size.hpp"







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

// Absolute
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


// relative
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



double
entropy_formula
(
    double p
)
{
    return ((-p) * log2(p) - (1 - p) * log2(1-p));
}


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


double get_prob
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




std::unique_ptr<ProbabilisticNetwork>
GDB(
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
    auto previous_graph = duplicate_graph(current_graph.get());
    auto next_graph = duplicate_graph(current_graph.get());

    bool first_run = true;

    
    do
    {
        // Reuse the old graphs so we dont have to create a new network for every iteration
        // previous iterations next_graph becomes the current_graph
        // and we reuse previous iterations current_graph as this iterations next_graph
        //      and overwrite its values with new ones
        std::swap(current_graph, previous_graph);
        std::swap(next_graph, current_graph);


        //TODO: Wrong, should maybe compare to original graph?
        if(first_run)
        {
            Dcurrent = objective_function(uncertain_graph, current_graph.get(), use_absolute);
        } else {
            Dcurrent = objective_function(previous_graph.get(), current_graph.get(), use_absolute);
        }
        std::cout << "obj func: " << Dcurrent << "\n" << std::endl;

        //TODO: Note: we're going through them in order of ID
        // Might be able to try different ordering methods


        for ( auto edge: *next_graph->edges())
        {
            auto p_e = get_prob(next_graph.get(), edge);
            auto u0 = edge->v1;
            auto v0 = edge->v2;

            auto pi_u = pi(next_graph.get(), u0, use_absolute);
            auto pi_v = pi(next_graph.get(), v0, use_absolute);

            double SA_v;
            double SA_u;

            if(first_run)
            {
                SA_v = a_discrepancy(uncertain_graph, next_graph.get(), v0);
                SA_u = a_discrepancy(uncertain_graph, next_graph.get(), u0);
            } else {
                SA_v = a_discrepancy(current_graph.get(), next_graph.get(), v0);
                SA_u = a_discrepancy(current_graph.get(), next_graph.get(), u0);
            }

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
            next_graph->set_prob(edge, prob_e);    
        }

        first_run = false;

        std::cout << "obj func: " << objective_function(uncertain_graph, next_graph.get(), use_absolute) << "\n" << std::endl;

    } while
    (
        ! abs(  Dcurrent - objective_function(next_graph.get(), previous_graph.get(), use_absolute) ) <= improvement_threshold
    );

    return next_graph;
}












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

}
}






void
testGDB(
    const std::string path,
    double spars,
    double span,
    double entropy,
    double improve_threshold,
    bool use_absolute
)
{
    auto graph = uu::net::read_probabilistic_network(path, "net", ',');

    //  Backbone
    //auto Gb = uu::net::generate_backbone(graph.get(), spars, span);
    // Doing manual backbone for testing
    auto Gb = uu::net::read_network("../inputBackbone.net", "backbone", ',');

    //  Print backbone
    std::cout << uu::net::size(Gb.get()) << std::endl;
    for (auto edge: *Gb->edges())
    {
        std::cout << edge->to_string() << std::endl;
    }
    std::cout << "\n" << std::endl;


    std::cout << "Doing GDB" << std::endl;
    std::cout  << std::endl;

    auto sparsified = GDB(graph.get(), Gb.get(), entropy, improve_threshold, use_absolute);

    std::cout << "\nGDB finished\n" << std::endl;


    std::cout << "sparsified net: \nedges: " << sparsified->edges()->size() << std::endl;
    for (auto edge: *sparsified->edges())
    {
        std::cout << edge->to_string() << ", " << sparsified->get_prob(edge) << std::endl;
    }

    std::cout << "Entropy original: " << entropy_of_graph(graph.get()) << 
                 ", sparsified: " << entropy_of_graph(sparsified.get()) << std::endl;

}


void
testBackbone()
{
    const std::string net_name = "../input.net";
    auto graph = uu::net::read_probabilistic_network(net_name, "net", ',');
    
    float sparsificationRatio = 0.8;
    float spanningRatio = 0.5;

    auto Gb = uu::net::generate_backbone(graph.get(), sparsificationRatio, spanningRatio);


    std::cout << uu::net::size(Gb.get()) << std::endl;
    for (auto edge: *Gb->edges())
    {
        std::cout << edge->to_string() << std::endl;
    }
    std::cout << "\n" << std::endl;
}


int
main(int argc, char *argv[])
{

    //  Default values
    std::string path = "../input4.net";
    double spars = 0.8;
    double span = 0.5;
    double entropy = 0.1;
    double improve_threshold = 0.1;
    bool abs = true;

    if (! (argc == 7 || argc == 1)){
        std::cout << "You need 6 input arguments: \n" <<
                     "  path to graph file, \n" <<
                     "  spanning ratio, \n" <<
                     "  sparsification ratio, \n" <<
                     "  entropy step size, \n" <<
                     "  improvement threshold, \n" <<
                     "  boolean use_absolute, \n" <<
                     std::endl;
        return(0);
    } else if (argc == 7)
    {
        path = argv[1];
        spars = std::stod(argv[2]);
        span = std::stod(argv[3]);
        entropy = std::stod(argv[4]);
        improve_threshold = std::stod(argv[5]);
        std::string t = "true";
        abs = (argv[6] == t);
    }


    //testBackbone();

    testGDB(path, spars, span, entropy, improve_threshold, abs);

    return 0;
}


