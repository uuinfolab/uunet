#include "gtest/gtest.h"

#include "generation/sample.hpp"
#include "generation/standard_graphs.hpp"
#include "objects/MLVertex.hpp"
#include "measures/size.hpp"

TEST(net_creation_test, sample)
{
    std::vector<uu::net::EdgeDir> dir = {uu::net::EdgeDir::UNDIRECTED, uu::net::EdgeDir::UNDIRECTED};
    std::vector<uu::net::LoopMode> loops = {uu::net::LoopMode::ALLOWED, uu::net::LoopMode::ALLOWED};
    auto n = uu::net::null_multiplex(10, dir, loops);
    
    auto com = std::make_unique<uu::net::CommunityStructure<uu::net::MultilayerNetwork>>();
    auto c1 = std::make_unique<uu::net::Community<uu::net::MultilayerNetwork>>();
    auto c2 = std::make_unique<uu::net::Community<uu::net::MultilayerNetwork>>();

    auto l1 = n->layers()->at(0);
    auto l2 = n->layers()->at(1);

    for (size_t i=0; i<3; i++)
    {
        auto v = l1->vertices()->at(i);
        c1->add(uu::net::MLVertex(v,l1));
        c1->add(uu::net::MLVertex(v,l2));
    }

    for (size_t i=3; i<6; i++)
    {
        auto v = l1->vertices()->at(i);
        c2->add(uu::net::MLVertex(v,l1));
    }
    com->add(std::move(c1));
    com->add(std::move(c2));
    
    uu::net::sample(n.get(), com.get(), {.8, .8}, {.01, .01});
    
    // this is stochastic, so not much we can test
    EXPECT_TRUE(uu::net::size(l1) > 0);
    EXPECT_TRUE(uu::net::size(l2) > 0);
}

