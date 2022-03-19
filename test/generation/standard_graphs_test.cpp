#include "gtest/gtest.h"

#include "generation/standard_graphs.hpp"

TEST(net_creation_test, null_graph)
{
    auto n = uu::net::null_graph(11);

    ASSERT_EQ(size_t(11), n->vertices()->size());
    ASSERT_EQ(size_t(0), n->edges()->size());
}

TEST(net_creation_test, null_multiplex)
{
    auto n = uu::net::null_multiplex(10, 3);

    ASSERT_EQ(size_t(10), n->actors()->size());

    for (auto layer: *n->layers())
    {
        ASSERT_EQ(size_t(10), layer->vertices()->size());
        ASSERT_EQ(size_t(0), layer->edges()->size());
    }

    ASSERT_EQ(size_t(3), n->layers()->size());
}


TEST(net_creation_test, complete_graph)
{
    auto n = uu::net::complete_graph(5);

    ASSERT_EQ(size_t(5), n->vertices()->size());
    ASSERT_EQ(size_t(10), n->edges()->size());
}


TEST(net_creation_test, complete_graph_directed)
{
    auto n = uu::net::complete_graph(5, uu::net::EdgeDir::DIRECTED);

    ASSERT_EQ(size_t(5), n->vertices()->size());
    ASSERT_EQ(size_t(20), n->edges()->size());
}


TEST(net_creation_test, complete_bipartite_graph)
{
    auto n = uu::net::complete_bipartite_graph(3, 4);

    ASSERT_EQ(size_t(7), n->vertices()->size());
    ASSERT_EQ(size_t(12), n->edges()->size());
}


TEST(net_creation_test, complete_bipartite_graph_directed)
{
    auto n = uu::net::complete_bipartite_graph(3, 4, uu::net::EdgeDir::DIRECTED);

    ASSERT_EQ(size_t(7), n->vertices()->size());
    ASSERT_EQ(size_t(24), n->edges()->size());
}


TEST(net_creation_test, path_graph_directed)
{
    auto n = uu::net::path_graph(3, uu::net::EdgeDir::DIRECTED);

    ASSERT_EQ(size_t(3), n->vertices()->size());
    ASSERT_EQ(size_t(2), n->edges()->size());
}


TEST(net_creation_test, cycle_graph_directed)
{
    auto n = uu::net::cycle_graph(3, uu::net::EdgeDir::DIRECTED);

    ASSERT_EQ(size_t(3), n->vertices()->size());
    ASSERT_EQ(size_t(3), n->edges()->size());
}


TEST(net_creation_test, wheel_graph)
{
    auto n = uu::net::wheel_graph(5);

    ASSERT_EQ(size_t(5), n->vertices()->size());
    ASSERT_EQ(size_t(8), n->edges()->size());
}
