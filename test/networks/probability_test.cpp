#include "gtest/gtest.h"

#include "networks/probability.hpp"
#include "core/exceptions/WrongParameterException.hpp"

TEST(networks_test, ProbabilisticNetwork)
{

    auto g = std::make_unique<uu::net::Network>("pnet", uu::net::EdgeDir::DIRECTED);
    uu::net::make_probabilistic(g.get());

    // Adding vertices

    const uu::net::Vertex* v1 = g->vertices()->add("miao");
    const uu::net::Vertex* v2 = g->vertices()->add("bau");
    const uu::net::Vertex* v3 = g->vertices()->add("coucou");

    // Adding edges

    auto e1 = g->edges()->add(v1, v2);
    auto e2 = g->edges()->add(v1, v3);

    // Setting/getting probabilities

    EXPECT_THROW(set_prob(g.get(), e1, -0.3), uu::core::WrongParameterException)
            << "probability lower than 0";

    EXPECT_THROW(set_prob(g.get(), e1, 1.1), uu::core::WrongParameterException)
            << "probability higher than 1";

    set_prob(g.get(), e1, 0.4);
    EXPECT_EQ(0.4, get_prob(g.get(), e1));

    EXPECT_EQ(1.0, get_prob(g.get(), e2));

    // Propagation

    g->edges()->erase(e1);
    EXPECT_THROW(get_prob(g.get(), e1), uu::core::ElementNotFoundException);

    EXPECT_TRUE(is_probabilistic(g.get()));

}
