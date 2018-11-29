#include "gtest/gtest.h"

#include "mnet/datastructures/graphs/AttributedHomogeneousMultilayerNetwork.h"
#include <tuple>


class mnet_datastructures_graphs_AttributedHomogeneousMultilayerNetwork_test : public ::testing::Test
{
  protected:

    virtual void
    SetUp()
    {
    }


};

TEST_F(mnet_datastructures_graphs_AttributedHomogeneousMultilayerNetwork_test, creation)
{


    // Creating an empty multiplex network

    auto net = uu::net::create_attributed_homogeneous_multilayer_network("a ml net");

    // Adding vertices

    auto v1 = net->vertices()->add("miao");
    auto v2 = net->vertices()->add("bau");

    // Adding layers

    auto ptr = uu::net::create_attributed_simple_graph("layer1", uu::net::EdgeDir::DIRECTED);
    auto layer1 = net->layers()->add(std::move(ptr));

    ptr = uu::net::create_attributed_simple_graph("layer2", uu::net::EdgeDir::UNDIRECTED);
    auto layer2 = net->layers()->add(std::move(ptr));

    ptr = uu::net::create_attributed_simple_graph("layer3", uu::net::EdgeDir::UNDIRECTED);
    auto layer3 = net->layers()->add(std::move(ptr));

    // Adding "nodes", that is, vertices to layers

    layer1->vertices()->add(v1);
    layer2->vertices()->add(v1);

    layer1->vertices()->add(v2);
    layer3->vertices()->add(v2);

    // and edges

    layer1->edges()->add(v1, v2);

    // interlayer edges

    net->interlayer_edges()->add(v1, layer1, v2, layer3);

    EXPECT_EQ(nullptr, net->interlayer_edges()->add(v1, layer1, v2, layer3))
            << "duplicate edge insertion does not return nullptr";


    net->interlayer_edges()->set_directed(layer2, layer3, true);
    net->interlayer_edges()->add(v1, layer2, v2, layer3);


    // neighborhood

    EXPECT_EQ(1, net->interlayer_edges()->neighbors(layer1, layer3, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->neighbors(layer1, layer3, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->neighbors(layer1, layer3, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->neighbors(layer3, layer1, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->neighbors(layer3, layer1, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->neighbors(layer3, layer1, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->neighbors(layer2, layer3, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->neighbors(layer2, layer3, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->neighbors(layer2, layer3, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->neighbors(layer3, layer2, v2, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->neighbors(layer3, layer2, v2, uu::net::EdgeMode::IN)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->neighbors(layer3, layer2, v2, uu::net::EdgeMode::OUT)->size())
            << "wrong number of directed interlayer neighbors";

    EXPECT_EQ(1, net->interlayer_edges()->incident(layer1, layer3, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->incident(layer1, layer3, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->incident(layer1, layer3, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->incident(layer3, layer1, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->incident(layer3, layer1, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->incident(layer3, layer1, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->incident(layer2, layer3, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->incident(layer2, layer3, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->incident(layer2, layer3, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->incident(layer3, layer2, v2, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(1, net->interlayer_edges()->incident(layer3, layer2, v2, uu::net::EdgeMode::IN)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ(0, net->interlayer_edges()->incident(layer3, layer2, v2, uu::net::EdgeMode::OUT)->size())
            << "wrong number of directed interlayer neighbors";


    // Uncomment to print a summary of the network
    std::cout << net->summary() << " " << layer1->vertices()->size() << std::endl;
    bool rem = layer1->vertices()->erase(v1);
    EXPECT_EQ(0, net->interlayer_edges()->neighbors(layer3, layer1, v2, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of interlayer neighbors after vertex deletion";
    EXPECT_EQ(0, net->interlayer_edges()->incident(layer3, layer1, v2, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of interlayer incident edges after vertex deletion";

    // Uncomment to print a summary of the network
    std::cout << net->summary() << " " << layer1->vertices()->size() << " " << rem << std::endl;
    net->layers()->erase(layer2);

    // Uncomment to print a summary of the network
    std::cout << net->summary() << std::endl;
    net->vertices()->erase(v2);

    // Uncomment to print a summary of the network
    std::cout << net->summary() << std::endl;
}

