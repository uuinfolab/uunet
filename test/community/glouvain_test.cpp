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

TEST_F(community_mlalgo_test, glouvain_weighted)
{
    auto c = uu::net::glouvain2(wnet.get(), 1.0);
    
    // Not a test of correctness
}

TEST_F(community_mlalgo_test, glouvain_resolution)
{
    auto communities1 = uu::net::glouvain2(net.get(), 1.0, 1.0);
    
    // Not a test of correctness
    /*
    std::cout << "Communities:" << std::endl;
    for (auto com: *communities1)
    {
        for (auto v: *com)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    
    auto communities2 = uu::net::glouvain2(net.get(), 1.0, .1);
    
    std::cout << "Communities:" << std::endl;
    for (auto com: *communities2)
    {
        for (auto v: *com)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    
    auto communities3 = uu::net::glouvain2(net.get(), 1.0, 10.0);
    
    std::cout << "Communities:" << std::endl;
    for (auto com: *communities3)
    {
        for (auto v: *com)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    */
}
