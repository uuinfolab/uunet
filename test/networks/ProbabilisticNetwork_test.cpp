#include "gtest/gtest.h"

#include "networks/ProbabilisticNetwork.hpp"
#include "core/exceptions/WrongParameterException.hpp"

TEST(networks_test, ProbabilisticNetwork)
{

    auto g = std::make_unique<uu::net::ProbabilisticNetwork>("wnet", uu::net::EdgeDir::DIRECTED);

    // Adding vertices

    const uu::net::Vertex* v1 = g->vertices()->add("miao");
    const uu::net::Vertex* v2 = g->vertices()->add("bau");
    const uu::net::Vertex* v3 = g->vertices()->add("coucou");

    // Adding edges

    const uu::net::Edge* e1 = g->edges()->add(v1, v2);
    const uu::net::Edge* e2 = g->edges()->add(v1, v3);

    // Setting/getting probabilities

    EXPECT_THROW(g->set_prob(e1, -0.3), uu::core::WrongParameterException)
            << "Probability lower than 0";

    EXPECT_THROW(g->set_prob(e1, 1.1), uu::core::WrongParameterException)
            << "Probability higher than 1";

    g->set_prob(e1, 0.4);
    EXPECT_EQ(0.4, g->get_prob(e1).value);

    EXPECT_TRUE(g->get_prob(e2).null);

    // Propagation

    g->edges()->erase(e1);
    EXPECT_TRUE(g->get_prob(e1).null);

    // Checking graph properties

    EXPECT_TRUE(g->is_directed());

    EXPECT_FALSE(g->allows_multi_edges());

    EXPECT_FALSE(g->allows_loops());

    EXPECT_FALSE(g->is_weighted());

    EXPECT_TRUE(g->is_probabilistic());

    EXPECT_FALSE(g->is_temporal());

}
