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

/*
TEST_F(multilayer_community_algorithms_test, glouvain)
{
    auto c = uu::net::generalized_louvain<uu::net::MultilayerNetwork,uu::net::Network>(net.get(), 1.0, 1.0, 0);

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }
}
*/
