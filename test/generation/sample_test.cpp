#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "community/CommunityStructure.hpp"
#include "generation/sample.hpp"
#include "generation/standard_graphs.hpp"
#include "objects/MLVertex.hpp"
#include "utils/summary.hpp"

TEST(net_creation_test, sample)
{
    std::vector<uu::net::EdgeDir> dir = {uu::net::EdgeDir::UNDIRECTED, uu::net::EdgeDir::UNDIRECTED};
    std::vector<uu::net::LoopMode> loops = {uu::net::LoopMode::ALLOWED, uu::net::LoopMode::ALLOWED};
    auto n = uu::net::null_multiplex(10, dir, loops);

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

    std::cout << summary_short(n.get()) << std::endl;
}

