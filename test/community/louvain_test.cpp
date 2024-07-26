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
    
    // Not a test of correctness
    
}
