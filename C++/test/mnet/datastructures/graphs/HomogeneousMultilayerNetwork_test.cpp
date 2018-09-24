#include "gtest/gtest.h"

#include "mnet/datastructures/graphs/HomogeneousMultilayerNetwork.h"
#include <tuple>


class mnet_datastructures_graphs_HomogeneousMultilayerNetwork_test : public ::testing::Test
{
  protected:

    virtual void
    SetUp()
    {
    }


};

TEST_F(mnet_datastructures_graphs_HomogeneousMultilayerNetwork_test, creation)
{

    // Creating an empty multiplex network

    auto net = uu::net::create_homogeneous_multilayer_network("a ml net");

    // Adding vertices

    const uu::net::Vertex* v1 = net->vertices()->add("miao");
    const uu::net::Vertex* v2 = net->vertices()->add("bau");

    // Adding layers

    auto ptr = uu::net::create_simple_graph("layer1", uu::net::EdgeDir::DIRECTED);
    uu::net::SimpleGraph* layer1 = net->layers()->add(std::move(ptr));

    ptr = uu::net::create_simple_graph("layer2", uu::net::EdgeDir::UNDIRECTED);
    uu::net::SimpleGraph* layer2 = net->layers()->add(std::move(ptr));

    ptr = uu::net::create_simple_graph("layer3", uu::net::EdgeDir::UNDIRECTED);
    uu::net::SimpleGraph* layer3 = net->layers()->add(std::move(ptr));

    // Adding "nodes", that is, vertices to layers

    layer1->vertices()->add(v1);
    layer2->vertices()->add(v1);

    layer1->vertices()->add(v2);
    layer3->vertices()->add(v2);

    // and edges

    layer1->edges()->add(v1, v2);

    // interlayer edges

    net->edges()->add(v1, layer1, v2, layer3);

    // Uncomment to print a summary of the network
    //std::cout << net->summary() << std::endl;

}

