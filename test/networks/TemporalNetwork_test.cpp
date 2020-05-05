#include "gtest/gtest.h"

#include "networks/TemporalNetwork.hpp"

TEST(networks_test, TemporalNetwork)
{

    auto g = std::make_unique<uu::net::TemporalNetwork>("tnet.hpp", uu::net::EdgeDir::DIRECTED);

    // Adding vertices

    const uu::net::Vertex* v1 = g->vertices()->add("miao");
    const uu::net::Vertex* v2 = g->vertices()->add("bau");
    const uu::net::Vertex* v3 = g->vertices()->add("coucou");

    // Adding edges

    const uu::net::Edge* e1 = g->edges()->add(v1, v2);
    const uu::net::Edge* e2 = g->edges()->add(v1, v3);
    const uu::net::Edge* e3 = g->edges()->add(v1, v2);

    // Setting/getting times

    g->set_time(e1, uu::core::epoch_to_time(1365));
    EXPECT_EQ(uu::core::epoch_to_time(1365), g->get_time(e1).value)
            << "Weight not set correctly";

    EXPECT_TRUE(g->get_time(e2).null)
            << "Attribute should not be set";

    EXPECT_TRUE(g->get_time(e3).null)
            << "Attribute should not be set";

    // Propagation

    g->edges()->erase(e1);
    EXPECT_TRUE(g->get_time(e1).null)
            << "Vertex removal not propagated to its attributes";

    // Checking graph properties

    EXPECT_TRUE(g->is_directed());

    EXPECT_TRUE(g->allows_multi_edges());

    EXPECT_TRUE(g->allows_loops());

    EXPECT_FALSE(g->is_weighted());

    EXPECT_FALSE(g->is_probabilistic());

    EXPECT_TRUE(g->is_temporal());

}
