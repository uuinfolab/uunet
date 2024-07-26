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

TEST_F(community_algo_test, louvain_weighted)
{

    auto communities = uu::net::louvain(wnet.get());
    
    // Not a test of correctness
    
}

TEST_F(community_algo_test, louvain_resolution)
{

    auto communities1 = uu::net::louvain(net.get(), 1.0);
    
    // Not a test of correctness
    /*
    std::cout << "Communities:" << std::endl;
    for (auto com: *communities1)
    {
        for (auto v: *com)
        {
            std::cout << v->name << " ";
        }
        std::cout << std::endl;
    }
    
    auto communities2 = uu::net::louvain(net.get(), .1);
    
    std::cout << "Communities:" << std::endl;
    for (auto com: *communities2)
    {
        for (auto v: *com)
        {
            std::cout << v->name << " ";
        }
        std::cout << std::endl;
    }
    
    auto communities3 = uu::net::louvain(net.get(), 10.0);
    
    std::cout << "Communities:" << std::endl;
    for (auto com: *communities3)
    {
        for (auto v: *com)
        {
            std::cout << v->name << " ";
        }
        std::cout << std::endl;
    }
    */
    
}
