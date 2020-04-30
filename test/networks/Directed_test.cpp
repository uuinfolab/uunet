#include "gtest/gtest.h"

#include "networks/Network.hpp"

TEST(networks_test, Directed)
{

    auto g = std::make_unique<uu::net::Network>("g", uu::net::EdgeDir::DIRECTED);

    // Checking graph properties

    EXPECT_TRUE(g->is_directed());

    // Adding some vertices to be used in the tests

    const uu::net::Vertex* v1 = g->vertices()->add("v1");
    const uu::net::Vertex* v2 = g->vertices()->add("v2");

    // Directionality

    g->edges()->add(v1, v2);

    EXPECT_EQ(
        g->edges()->get(v2, v1),
        nullptr
    );

    g->edges()->add(v2, v1);

    EXPECT_EQ(
        g->edges()->size(),
        (size_t) 2
    );

}
