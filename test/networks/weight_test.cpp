#include "gtest/gtest.h"

#include "networks/weight.hpp"

TEST(networks_test, weighted)
{

    auto g = std::make_unique<uu::net::Network>("wnet", uu::net::EdgeDir::DIRECTED);
    uu::net::make_weighted(g.get());

    // Adding vertices

    const uu::net::Vertex* v1 = g->vertices()->add("miao");
    const uu::net::Vertex* v2 = g->vertices()->add("bau");
    const uu::net::Vertex* v3 = g->vertices()->add("coucou");

    // Adding edges

    auto e1 = g->edges()->add(v1, v2);
    auto e2 = g->edges()->add(v1, v3);

    // Setting/getting weights

    set_weight(g.get(), e1, 3.4);
    EXPECT_EQ(3.4, get_weight(g.get(), e1));
    EXPECT_EQ(1.0, get_weight(g.get(), e2)); // default

    // Propagation

    g->edges()->erase(e1);
    EXPECT_THROW(get_weight(g.get(), e1), uu::core::ElementNotFoundException);

    // Checking graph properties

    EXPECT_TRUE(g->is_directed());

    //EXPECT_FALSE(g->allows_multi_edges());

    //EXPECT_FALSE(g->allows_loops());

    EXPECT_TRUE(is_weighted(g.get()));

    //EXPECT_FALSE(is_probabilistic(g.get()));

    //EXPECT_FALSE(is_temporal(g.get()));

}
