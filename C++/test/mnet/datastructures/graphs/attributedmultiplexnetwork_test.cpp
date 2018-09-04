#include "gtest/gtest.h"

#include "mnet/datastructures/graphs/AttributedMultiplexNetwork.h"
#include <tuple>


class mnet_datastructures_graphs_AttributedMultiplexNetwork_test : public ::testing::Test
{
  protected:

    virtual void
    SetUp()
    {
    }


};

TEST_F(mnet_datastructures_graphs_AttributedMultiplexNetwork_test, creation)
{

    // Creating an empty multiplex network

    auto net = uu::net::create_attributed_multiplex_network("a mpx net");


    // Adding vertices

    const uu::net::Vertex* v1 = net->vertices()->add("miao");
    const uu::net::Vertex* v2 = net->vertices()->add("bau");

    // Interlayer Vertex Attributes

    net->vertices()->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    net->vertices()->attr()->set_double(v1, "a1", 3.4);
    EXPECT_EQ(3.4, net->vertices()->attr()->get_double(v1, "a1").value)
            << "Attribute value not set correctly (vertex)";

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

    auto e = layer1->edges()->add(v1, v2);

    // Intra-layer attributes

    layer1->vertices()->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    layer1->vertices()->attr()->set_double(v1, "a1", 3.4);
    EXPECT_EQ(3.4, layer1->vertices()->attr()->get_double(v1, "a1").value)
            << "Attribute value not set correctly (vertex)";

    layer1->edges()->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    layer1->edges()->attr()->set_double(e, "a1", 3.4);
    EXPECT_EQ(3.4, layer1->edges()->attr()->get_double(e, "a1").value)
            << "Attribute value not set correctly (edge)";

    // Uncomment to print network summary
    //std::cout << net->summary() << std::endl;

}

