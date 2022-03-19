#include "gtest/gtest.h"

#include "community/CommunityStructure.hpp"
#include "community/Community.hpp"
#include "networks/Network.hpp"
#include "networks/MultilayerNetwork.hpp"

TEST(net_community_test, Community)
{

    uu::net::Community<uu::net::Network> c;

    auto v1 = std::make_shared<uu::net::Vertex>("v1");
    auto v2 = std::make_shared<uu::net::Vertex>("v2");

    // Adding vertices to the community
    c.add(v1.get());
    c.add(v2.get());

    EXPECT_EQ((size_t)2, c.size());
}

TEST(net_community_test, CommunityStructure)
{
    // Creating some vertices to be used in the tests
    
    auto v1 = std::make_unique<uu::net::Vertex>("v1");
    auto v2 = std::make_unique<uu::net::Vertex>("v2");
    
    // Data structures
    
    auto com = std::make_unique<uu::net::CommunityStructure<uu::net::Network>>();
    
    auto c1 = std::make_unique<uu::net::Community<uu::net::Network>>();
    auto c2 = std::make_unique<uu::net::Community<uu::net::Network>>();

    // Adding vertices to the community
    
    c1->add(v1.get());
    c1->add(v2.get());
    c2->add(v2.get());
    
    EXPECT_EQ((size_t) 2, c1->size());
    EXPECT_EQ((size_t) 1, c2->size());
    
    // Adding communities to the community structure
    
    com->add(std::move(c1));
    com->add(std::move(c2));
    
    EXPECT_EQ((size_t) 2, com->size());
    
    // Communities for multilayer networks
    
    auto ml_com = std::make_unique<uu::net::CommunityStructure<uu::net::MultilayerNetwork>>();
    
    auto ml_c = std::make_unique<uu::net::Community<uu::net::MultilayerNetwork>>();
    
    
    // Creating some multilayer vertices to be used in the tests
    
    auto n = std::make_unique<uu::net::Network>("net");
    
    auto ml_v1 = uu::net::MLVertex(v1.get(), n.get());
    auto ml_v2 = uu::net::MLVertex(v2.get(), n.get());
    
    // Adding multilayer vertices to the community
    
    ml_c->add(ml_v1);
    ml_c->add(ml_v2);
    
    EXPECT_EQ((size_t) 2, ml_c->size());
    
    ml_com->add(std::move(ml_c));
    
    EXPECT_EQ((size_t) 1, ml_com->size());
}
