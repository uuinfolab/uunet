#include "gtest/gtest.h"

#include "networks/time.hpp"

TEST(networks_test, temporal)
{

    auto dir = uu::net::EdgeDir::UNDIRECTED;
    auto loops = uu::net::LoopMode::ALLOWED;
    auto g = std::make_unique<uu::net::Network>("g", dir, loops);
    uu::net::make_temporal(g.get());

    // Adding vertices

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    // Adding edges

    auto e1 = g->edges()->add(v1, v2);
    auto e2 = g->edges()->add(v1, v3);

    // Attributes

    add_time(g.get(), e1, uu::core::epoch_to_time(15434));
    add_time(g.get(), e1, uu::core::epoch_to_time(154));
    EXPECT_EQ(uu::net::get_times(g.get(), e1).size(), (size_t) 2);
    EXPECT_EQ(uu::net::get_times(g.get(), e2).size(), (size_t) 0);
}
