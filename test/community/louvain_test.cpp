#include "algo_test.hpp" // defines the input network
#include "community/louvain.hpp"

TEST_F(community_algo_test, louvain)
{

    auto communities = uu::net::louvain(net.get());

    for (auto com: *communities)
    {
        EXPECT_EQ((size_t) 3, com->size());
    }
}

TEST_F(community_algo_test, weighted_louvain)
{

    auto communities = uu::net::louvain(wnet.get());

    for (auto com: *communities)
    {
        // Not a 100% test of correctness, but it tests that the weights are considered
        EXPECT_EQ((size_t) 2, com->size());
    }
}
