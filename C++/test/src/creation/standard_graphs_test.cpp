#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "creation/standard_graphs.hpp"
#include "networks/Network.hpp"

TEST(net_creation_standardgraphs_test, null_graph)
{

    auto n = std::make_unique<uu::net::Network>("Net");
    uu::net::null_graph(n.get(), 11);

    ASSERT_EQ(size_t(11), n->vertices()->size());
    ASSERT_EQ(size_t(0), n->edges()->size());

}


TEST(net_creation_standardgraphs_test, null_graph_iterator)
{

    auto v1 = uu::net::Vertex::create("V1");
    auto v2 = uu::net::Vertex::create("V2");
    auto v3 = uu::net::Vertex::create("V3");

    std::vector<const uu::net::Vertex*> v;

    v.push_back(v1.get());
    v.push_back(v2.get());
    v.push_back(v3.get());

    auto n = std::make_unique<uu::net::Network>("Net");
    uu::net::null_graph(n.get(), v.begin(), v.end());

    ASSERT_EQ(size_t(3), n->vertices()->size());
    ASSERT_EQ(size_t(0), n->edges()->size());

}



TEST(net_creation_standardgraphs_test, complete_graph)
{

    auto n = std::make_unique<uu::net::Network>("Net");
    uu::net::complete_graph(n.get(), 5);

    ASSERT_EQ(size_t(5), n->vertices()->size());
    ASSERT_EQ(size_t(10), n->edges()->size());

}


TEST(net_creation_standardgraphs_test, complete_graph_directed)
{

    auto n = std::make_unique<uu::net::Network>("Net", uu::net::EdgeDir::DIRECTED);
    uu::net::complete_graph(n.get(), 5);

    ASSERT_EQ(size_t(5), n->vertices()->size());
    ASSERT_EQ(size_t(20), n->edges()->size());

}


TEST(net_creation_standardgraphs_test, complete_bipartite_graph)
{

    auto n = std::make_unique<uu::net::Network>("Net");
    uu::net::complete_bipartite_graph(n.get(), 3, 4);

    ASSERT_EQ(size_t(7), n->vertices()->size());
    ASSERT_EQ(size_t(12), n->edges()->size());

}


TEST(net_creation_standardgraphs_test, complete_bipartite_graph_directed)
{

    auto n = std::make_unique<uu::net::Network>("Net", uu::net::EdgeDir::DIRECTED);
    uu::net::complete_bipartite_graph(n.get(), 3, 4);

    ASSERT_EQ(size_t(7), n->vertices()->size());
    ASSERT_EQ(size_t(24), n->edges()->size());

}


TEST(net_creation_standardgraphs_test, path_graph_directed)
{

    auto n = std::make_unique<uu::net::Network>("Net", uu::net::EdgeDir::DIRECTED);
    uu::net::path_graph(n.get(), 3);

    ASSERT_EQ(size_t(3), n->vertices()->size());
    ASSERT_EQ(size_t(2), n->edges()->size());

}


TEST(net_creation_standardgraphs_test, cycle_graph_directed)
{

    auto n = std::make_unique<uu::net::Network>("Net", uu::net::EdgeDir::DIRECTED);
    uu::net::cycle_graph(n.get(), 3);

    ASSERT_EQ(size_t(3), n->vertices()->size());
    ASSERT_EQ(size_t(3), n->edges()->size());

}


TEST(net_creation_standardgraphs_test, wheel_graph_directed)
{

    auto n = std::make_unique<uu::net::Network>("Net", uu::net::EdgeDir::DIRECTED);
    uu::net::wheel_graph(n.get(), 5);

    ASSERT_EQ(size_t(5), n->vertices()->size());
    ASSERT_EQ(size_t(8), n->edges()->size());

}
