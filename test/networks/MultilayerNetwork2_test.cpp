#include "gtest/gtest.h"

#include "networks/MultilayerNetwork2.hpp"

TEST(networks_test, MultilayerNetwork2)
{

    // Creating an empty multilayer network

    auto net = std::make_unique<uu::net::MultilayerNetwork2>("a ml net");

    // Creating actors

    auto v1_sharedptr = std::make_shared<uu::net::Vertex>("miao");
    auto v1 = v1_sharedptr.get();
    auto v2_sharedptr = std::make_shared<uu::net::Vertex>("bau");
    auto v2 = v2_sharedptr.get();
    
    // Adding layers
    auto layer1 = net->layers()->add("layer1", uu::net::EdgeDir::DIRECTED);
    
    auto layer2 = net->layers()->add("layer2", uu::net::EdgeDir::UNDIRECTED);
    
    auto layer3 = net->layers()->add("layer3", uu::net::EdgeDir::UNDIRECTED);

    // Adding "nodes", that is, vertices to layers
    layer1->vertices()->add(v1);
    layer2->vertices()->add(v1);

    layer1->vertices()->add(v2);
    layer3->vertices()->add(v2);
    
    // and edges

    layer1->edges()->add(v1, v2);

    // interlayer edges
    
    net->interlayer_edges()->init(layer1, layer3, uu::net::EdgeDir::UNDIRECTED);
    net->interlayer_edges()->add(v1, layer1, v2, layer3);

    EXPECT_EQ(nullptr, net->interlayer_edges()->add(v1, layer1, v2, layer3))
            << "duplicate edge insertion does not return nullptr";

    net->interlayer_edges()->init(layer2, layer3, uu::net::EdgeDir::DIRECTED);
    net->interlayer_edges()->add(v1, layer2, v2, layer3);

    // neighborhood

    EXPECT_EQ((size_t)1, net->interlayer_edges()->neighbors(layer1, layer3, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->neighbors(layer1, layer3, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->neighbors(layer1, layer3, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->neighbors(layer3, layer1, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->neighbors(layer3, layer1, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->neighbors(layer3, layer1, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->neighbors(layer2, layer3, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->neighbors(layer2, layer3, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->neighbors(layer2, layer3, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->neighbors(layer3, layer2, v2, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->neighbors(layer3, layer2, v2, uu::net::EdgeMode::IN)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->neighbors(layer3, layer2, v2, uu::net::EdgeMode::OUT)->size())
            << "wrong number of directed interlayer neighbors";

    EXPECT_EQ((size_t)1, net->interlayer_edges()->incident(layer1, layer3, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->incident(layer1, layer3, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->incident(layer1, layer3, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->incident(layer3, layer1, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->incident(layer3, layer1, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->incident(layer3, layer1, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of undirected interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->incident(layer2, layer3, v1, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->incident(layer2, layer3, v1, uu::net::EdgeMode::IN)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->incident(layer2, layer3, v1, uu::net::EdgeMode::OUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->incident(layer3, layer2, v2, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)1, net->interlayer_edges()->incident(layer3, layer2, v2, uu::net::EdgeMode::IN)->size())
            << "wrong number of directed interlayer neighbors";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->incident(layer3, layer2, v2, uu::net::EdgeMode::OUT)->size())
            << "wrong number of directed interlayer neighbors";

    /*
    layer1->vertices()->erase(v1);
    EXPECT_EQ((size_t)0, net->interlayer_edges()->neighbors(layer3, layer1, v2, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of interlayer neighbors after vertex deletion";
    EXPECT_EQ((size_t)0, net->interlayer_edges()->incident(layer3, layer1, v2, uu::net::EdgeMode::INOUT)->size())
            << "wrong number of interlayer incident edges after vertex deletion";
   */
    // @todo More removal tests
}
