/**
 * This file shows how to read a temporal network from file,
 * iterate through its elements, discretize it into an
 * ordered multiplex network and discover communities in it.
 *
 * History: created on 2018-09-10.
 */

#include "tnet/io/read_temporal_network.h"
#include "tnet/transformation/to_ordered_multiplex.h"
#include "mnet/community/glouvain.h"

int
main()
{

    // Read a temporal network from file

    std::unique_ptr<uu::net::TemporalNetwork> tnet;
    tnet = uu::net::read_temporal_network("test.tnt", "test", ',');

    // Inspect the network

    std::cout << tnet->summary() << std::endl;
    std::cout << "Directed:     " << tnet->is_directed() << std::endl;
    std::cout << "Temporal:     " << tnet->is_temporal() << std::endl;
    std::cout << "Allows loops: " << tnet->allows_loops() << std::endl;

    std::cout << "-- Vertices --" << std::endl;

    for (auto vertex: *tnet->vertices())
    {
        std::cout << (*vertex) << std::endl;
    }

    std::cout << "-- Edges --" << std::endl;

    for (auto edge: *tnet->edges())
    {
        auto time = tnet->edges()->attr()->get_time(edge);
        std::cout << (*edge) << " : " << time << std::endl;
    }

    std::cout << std::endl;

    // Discretize the network

    auto sliced_net = uu::net::to_ordered_multiplex(tnet.get(), 3);

    std::cout << sliced_net->summary() << std::endl;

    for (auto layer: *sliced_net->layers())
    {
        std::cout << "Layer " << layer->name << std::endl;

        for (auto edge: *layer->edges())
        {
            std::cout << (*edge) << std::endl;
        }
    }

    std::cout << std::endl;

    // Discover and print communities

    auto communities = uu::net::generalized_louvain<uu::net::OrderedMultiplexNetwork, uu::net::SimpleGraph>(sliced_net.get(), 1, 1, 100);

    for (auto c: *communities)
    {
        std::cout << "COMMUNITY" << std::endl;

        for (auto node: *c)
        {
            // "node" is a pair (actor,layer)
            std::cout << node.first->name << "@" << node.second->name << std::endl;
        }
    }

    return 0;
}
