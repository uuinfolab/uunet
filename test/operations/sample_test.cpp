#include "gtest/gtest.h"

#include "operations/sample.hpp"

TEST(net_operations_test, sample)
{

    // creating a probabilistic graph

    auto dir = uu::net::EdgeDir::DIRECTED;
    auto g = std::make_unique<uu::net::ProbabilisticNetwork>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    auto e1 = g->edges()->add(v1, v2);
    g->set_prob(e1, .5);
    auto e2 = g->edges()->add(v2, v3);
    g->set_prob(e2, .5);

    // sample

    auto sample = uu::net::sample(g.get());

    size_t n = sample->vertices()->size();
    size_t m = sample->edges()->size();

    std::cout << n << " " << m << std::endl;

}


TEST(net_operations_test, graph_sample_exceptions)
{
    EXPECT_THROW(
        uu::net::sample((uu::net::ProbabilisticNetwork*)nullptr),
        uu::core::NullPtrException
    );
}
