#include "gtest/gtest.h"

#include <cstdio>
#include <memory>
#include <fstream>
#include <vector>

#include "mnet/datastructures/graphs/AttributedHomogeneousMultilayerNetwork.h"
#include "mnet/generation/PAEvolutionModel.h"
#include "mnet/generation/evolve.h"

class mnet_generation_evolve_test : public ::testing::Test
{


};

TEST_F(mnet_generation_evolve_test, pa)
{
    auto net = uu::net::create_attributed_homogeneous_multilayer_network("g");

    std::vector<double> pr_internal_event = {1,.8};
    std::vector<double> pr_external_event = {0,.1};
    std::vector<std::string> layer_names = {"layer1", "layer2"};
    std::vector<std::vector<double>> dependency = {{0,1},{1,0}};
    std::vector<uu::net::EvolutionModel<uu::net::AttributedHomogeneousMultilayerNetwork>*> evolution_models;
    auto pa = std::make_unique<uu::net::PAEvolutionModel<uu::net::AttributedHomogeneousMultilayerNetwork>>(2,2);
    evolution_models.push_back(pa.get());
    evolution_models.push_back(pa.get());


    auto ptr1 = uu::net::create_attributed_simple_graph("layer1", uu::net::EdgeDir::DIRECTED);
    net->layers()->add(std::move(ptr1));
    auto ptr2 = uu::net::create_attributed_simple_graph("layer2", uu::net::EdgeDir::DIRECTED);
    net->layers()->add(std::move(ptr2));

    for (int i=0; i<10; i++)
    {
        net->vertices()->add("a"+std::to_string(i));
    }

    uu::net::evolve(
        net.get(),
        layer_names,
        pr_internal_event, pr_external_event, dependency, evolution_models,
        100
    );
}

