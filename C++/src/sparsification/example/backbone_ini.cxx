/**
 * This program shows how to read and print basic statistics about probabilistic networks.
 *
 * History: created on 2020-01-28.
 */

#include <iostream>

#include "io/read_probabilistic_network.hpp"
#include "measures/order.hpp"
#include "measures/size.hpp"
#include "measures/degree.hpp"
#include "measures/exp_degree.hpp"
#include "measures/betweenness.hpp"
#include "networks/ProbabilisticNetwork.hpp"

int
main()
{
     
    const std::string net_name = "../input.net";
    
    std::unique_ptr<uu::net::ProbabilisticNetwork>
    uncertainGraph = uu::net::read_probabilistic_network(net_name, "net", ',');

    float sparsificationRatio = 0.5;
    float spanningRatio = 0.3;

    std::unique_ptr<uu::net::Network> generate_backbone(uncertainGraph, sparsificationRatio, spanningRatio);


    return 0;
}


std::unique_ptr<uu::net::Network>
generate_backbone(std::unique_ptr<uu::net::ProbabilisticNetwork>G, float sparsRatio, float spanRatio){

    /* set up nano-seconds */
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* seed rand using nano-seconds */
    srand((time_t)ts.tv_nsec);


    //TODO: Copy main graph

    std::unique_ptr<uu::net::Network> Gb = maximum_spanning_tree(G);
    G->graph_remove(Gb);

    while (uu::net::size(Gb.get()) < spanRatio * uu::net::size(G.get()))
    {
        std::unique_ptr<uu::net::Network> F = maximum_spanning_forest(G);
        Gb->graph_add(F);
        G->graph_remove(F);
    }

    while (uu::net::size(Gb.get()) < sparsRatio * uu::net::size(G.get()))
    {
        auto e = G->edges()->get_at_random();
        
        double r = ((double) rand() / (RAND_MAX));
        if (G->get_prob(e).value > r)
        {
            Gb->edges()->add(e);
            G->edges()->erase(e);
        }
    }    
}