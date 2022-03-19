#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "generation/evolve.hpp"
#include "generation/PAModel.hpp"
#include "generation/ERModel.hpp"
#include "measures/size.hpp"
#include "measures/order.hpp"
#include "networks/MultilayerNetwork.hpp"
#include "core/utils/NameIterator.hpp"

TEST(net_creation_test, evolution)
{
    
    auto und = uu::net::EdgeDir::UNDIRECTED;
    auto loops = uu::net::LoopMode::ALLOWED;
    auto ml = std::make_unique<uu::net::MultilayerNetwork>("ml");
    auto l1 = ml->layers()->add("l1", und, loops);
    auto l2 = ml->layers()->add("l2", und, loops);
    
    
    std::vector<std::string> layer_names = {"l1", "l2"};
    std::vector<double> pr_internal_event = {.8, .5};
    std::vector<double> pr_external_event = {0, .5};
    std::vector<std::vector<double>> dependency = {{0, 1}, {1, 0}};
    std::vector<uu::net::EvolutionModel<uu::net::MultilayerNetwork>*> evolution_model;
    auto pa = std::make_unique<uu::net::PAModel<uu::net::MultilayerNetwork>>(3, 2);
    auto er = std::make_unique<uu::net::ERModel<uu::net::MultilayerNetwork>>(25);
    evolution_model.push_back(pa.get());
    evolution_model.push_back(er.get());
    long num_of_steps = 50;
    
    evolve(ml.get(), 100, layer_names, pr_internal_event, pr_external_event,
           dependency, evolution_model,  num_of_steps);
    
    // this is stochastic, so not much we can test
    EXPECT_TRUE(uu::net::order(l1) > 0);
    EXPECT_TRUE(uu::net::order(l2) > 0);
    EXPECT_TRUE(uu::net::size(l1) > 0);
    EXPECT_TRUE(uu::net::size(l2) > 0);
}

