#include "algoml_test.hpp" // defines the input network

#include "community/glouvain2.hpp"


TEST_F(community_mlalgo_test, glouvain2)
{

    auto c = uu::net::glouvain2(net.get(), 1.0);

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }
}

TEST_F(community_mlalgo_test, weighted_glouvain)
{
    auto c = uu::net::glouvain2(wnet.get(), 1.0);
    
    // Not a test of correctness
}
