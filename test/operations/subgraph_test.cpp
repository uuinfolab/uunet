#include "gtest/gtest.h"

#include "operations/subgraph.hpp"

#include <vector>

TEST(operations_test, vertex_induced_subgraph)
{

    // creating a simple graph

    auto g = std::make_unique<uu::net::Network>("g");

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    g->edges()->add(v1, v2);
    g->edges()->add(v1, v3);
    g->edges()->add(v2, v3);

    // test

    std::vector<const uu::net::Vertex*> vertices = {v1, v2};

    auto v_sub = uu::net::vertex_induced_subgraph(g.get(), vertices.begin(), vertices.end());

    size_t n = v_sub->vertices()->size();
    size_t m = v_sub->edges()->size();
    EXPECT_EQ(n, (size_t) 2);
    EXPECT_EQ(m, (size_t) 1);

}


TEST(operations_test, edge_induced_subgraph)
{

    // creating a simple graph

    auto g = std::make_unique<uu::net::Network>("g");

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    auto e1 = g->edges()->add(v1, v2);
    g->edges()->add(v1, v3);
    g->edges()->add(v2, v3);

    // test

    std::vector<const uu::net::Edge*> edges = {e1};

    auto e_sub = uu::net::edge_induced_subgraph(g.get(), edges.begin(), edges.end());

    size_t n = e_sub->vertices()->size();
    size_t m = e_sub->edges()->size();
    EXPECT_EQ(n, (size_t) 2);
    EXPECT_EQ(m, (size_t) 1);

}
