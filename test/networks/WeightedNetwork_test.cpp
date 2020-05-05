#include "gtest/gtest.h"

#include "networks/WeightedNetwork.hpp"

TEST(networks_test, WeightedNetwork)
{

    auto g = std::make_unique<uu::net::WeightedNetwork>("wnet", uu::net::EdgeDir::DIRECTED);

    // Adding vertices

    const uu::net::Vertex* v1 = g->vertices()->add("miao");
    const uu::net::Vertex* v2 = g->vertices()->add("bau");
    const uu::net::Vertex* v3 = g->vertices()->add("coucou");

    // Adding edges

    const uu::net::Edge* e1 = g->edges()->add(v1, v2);
    const uu::net::Edge* e2 = g->edges()->add(v1, v3);

    // Setting/getting weights

    g->set_weight(e1, 3.4);
    EXPECT_EQ(3.4, g->get_weight(e1).value)
            << "Weight not set correctly";

    EXPECT_TRUE(g->get_weight(e2).null)
            << "Attribute should not be set";

    // Propagation

    g->edges()->erase(e1);
    EXPECT_TRUE(g->get_weight(e1).null)
            << "Vertex removal not propagated to its attributes";

    // Checking graph properties

    EXPECT_TRUE(g->is_directed());

    EXPECT_FALSE(g->allows_multi_edges());

    EXPECT_FALSE(g->allows_loops());

    EXPECT_TRUE(g->is_weighted());

    EXPECT_FALSE(g->is_probabilistic());

    EXPECT_FALSE(g->is_temporal());

}
