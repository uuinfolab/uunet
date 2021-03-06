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

