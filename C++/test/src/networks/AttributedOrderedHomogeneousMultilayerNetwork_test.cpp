#include "gtest/gtest.h"

#include "networks/OrderedMultiplexNetwork.hpp"
//#include <tuple>


class net_networks_OrderedMultiplexNetwork_test : public ::testing::Test
{
  protected:

    virtual void
    SetUp()
    {
    }


};

TEST_F(net_networks_OrderedMultiplexNetwork_test, creation)
{

    // Creating an empty multiplex network

    auto net = uu::net::create_ordered_multiplex_network("a ml net");

    // Adding vertices

    auto v1 = net->vertices()->add("miao");
    auto v2 = net->vertices()->add("bau");

    // Adding layers

    auto ptr = std::make_unique<uu::net::Network>("layer1", uu::net::EdgeDir::DIRECTED);
    net->layers()->push_back(std::move(ptr));

    ptr = std::make_unique<uu::net::Network>("layer2", uu::net::EdgeDir::UNDIRECTED);
    net->layers()->push_back(std::move(ptr));

    ptr = std::make_unique<uu::net::Network>("layer3", uu::net::EdgeDir::UNDIRECTED);
    net->layers()->push_back(std::move(ptr));

    // Adding "nodes", that is, vertices to layers

    auto layer1 = net->layers()->at(0);
    auto layer2 = net->layers()->at(1);
    auto layer3 = net->layers()->at(2);
    
    
    layer1->vertices()->add(v1);
    layer2->vertices()->add(v1);

    layer1->vertices()->add(v2);
    layer3->vertices()->add(v2);

    // and edges

    layer1->edges()->add(v1, v2);

    // Uncomment to print a summary of the network
    // std::cout << net->summary() << std::endl;
    
}

