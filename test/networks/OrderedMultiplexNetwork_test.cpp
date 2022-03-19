#include "gtest/gtest.h"

#include "networks/OrderedMultiplexNetwork.hpp"

TEST(networks_test, OrderedMultiplexNetwork)
{

    // Creating an empty ordered multiplex network

    auto net = std::make_unique<uu::net::OrderedMultiplexNetwork>("a ml net");

    // Adding layers

    net->layers()->add("layer1", uu::net::EdgeDir::DIRECTED);
    net->layers()->add("layer2", uu::net::EdgeDir::UNDIRECTED);
    net->layers()->add("layer3", uu::net::EdgeDir::UNDIRECTED);

    // Adding actors

    auto v1 = net->actors()->add("miao");
    auto v2 = net->actors()->add("bau");


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

    // @todo Add removal tests

}

