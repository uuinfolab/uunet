#include "gtest/gtest.h"

#include "mnet/datastructures/graphs/MultiplexNetwork.h"
#include <tuple>


class mnet_datastructures_graphs_MultiplexNetwork_test : public ::testing::Test
{
  protected:

    virtual void
    SetUp()
    {
    }


};

TEST_F(mnet_datastructures_graphs_MultiplexNetwork_test, creation)
{
    /*
    // Creating an empty multiplex network

    auto net = uu::net::create_multiplex_network("a mpx net");

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

    std::cout << net->summary() << std::endl;
     */

}

TEST_F(mnet_datastructures_graphs_MultiplexNetwork_test, Bipartite)
{


    // Creating an empty multiplex net->work called "net->"
    /*
        auto net = uu::net::create_simple_bipartite_graph("bnet");

        //net->vertices().add(uu::net::Vertex::create("miao"));

        net->layers().template get<0>()->vertices().add(uu::net::Vertex::create("miao"));
        net->layers().template get<1>()->vertices().add(uu::net::Vertex::create("bau"));

        for (auto v: net->vertices())
        {
            std::cout << v->name << std::endl;
        }*/
}

/*
TEST_F(MultiplexNetworkTest, Order)
{
    // Creating an empty layer-ordered net->work
    uu::mnet->::OrderedMultiplexNetworkSharedPtr net-> = uu::mnet->::OrderedMultiplexNetwork::create("net->1");

    // Adding layers
    uu::mnet->::std::shared_ptr<uu::net::Layer> l1 = net->->add_layer("l1",uu::net::UNDIRECTED);
    uu::mnet->::std::shared_ptr<uu::net::Layer> l3 = net->->add_layer("l3",uu::net::UNDIRECTED);
    uu::mnet->::std::shared_ptr<uu::net::Layer> l2 = net->->add_layer("l2",uu::net::UNDIRECTED,1); // Ordered version
    uu::mnet->::std::shared_ptr<uu::net::Layer> l0 = net->->add_layer("l0",uu::net::UNDIRECTED,0); // Ordered version

    ASSERT_EQ(l3,net->->get_layer(3))
    << "could not retrieve layers in the correct order";

    net->->erase_layer(1);

    ASSERT_EQ(l2,net->->get_layer(1))
    << "could not retrieve layers in the correct order";

    check_layer_list(net->->get_layers(),net->,3,"wrong erase()");

}

TEST_F(MultiplexNetworkTest, Attributes)
{
    net->->add_actor_attribute("name",uu::core::AttributeType::STRING);
    net->->add_actor_attribute("#d",uu::core::AttributeType::DOUBLE);
    net->->add_actor_attribute("#i",uu::core::AttributeType::INTEGER);
    net->->add_actor_attribute("#t",uu::core::AttributeType::TIME);

    net->->add_edge_attribute("name",uu::core::AttributeType::STRING);
    net->->add_edge_attribute("#d",uu::core::AttributeType::DOUBLE);
    net->->add_edge_attribute("#i",uu::core::AttributeType::INTEGER);
    net->->add_edge_attribute("#t",uu::core::AttributeType::TIME);

    EXPECT_EQ(nullptr,net->->add_actor_attribute("name",uu::core::AttributeType::STRING))
    << "failed to prevent duplicate attribute insertion";

    net->->set_as_string("name",a1,"Gonzo");
    net->->set_as_string("name",e1,"Kermit");
    net->->set_as_string("#d",a1,"37.4");
    net->->set_as_string("#d",e1,"37.2");
    net->->set_as_string("#i",a1,"37");
    net->->set_as_string("#i",e1,"39");
    net->->set_as_string("#t",a1,uu::core::to_string(uu::core::epoch_to_time("14244")));
    //net->->set<uu::core::Time>("#t",a1,uu::core::epoch_to_time("14244"));
    net->->set_as_string("#t",e1,uu::core::to_string(uu::core::epoch_to_time("19434")));

    EXPECT_EQ(net->->get_as_string("name",a1).value,"Gonzo")
    << "could not retrieve correct value for actor attribute name";
    EXPECT_EQ(net->->get_as_string("#d",a1).value,"37.4")
    << "could not retrieve correct value for actor attribute #d";
    EXPECT_EQ(net->->get_as_string("#i",a1).value,"37")
    << "could not retrieve correct value for actor attribute #i";
    EXPECT_EQ(net->->get_as_string("#t",a1).value,uu::core::to_string(uu::core::epoch_to_time("14244")))
    //EXPECT_EQ(net->->get<uu::core::Time>("#t",a1).value,uu::core::epoch_to_time("14244"))
    << "could not retrieve correct value for actor attribute #t";

    EXPECT_EQ(net->->get_as_string("name",e1).value,"Kermit")
    << "could not retrieve correct value for edge attribute name";
    EXPECT_EQ(net->->get_as_string("#d",e1).value,"37.2")
    << "could not retrieve correct value for edge attribute #d";
    EXPECT_EQ(net->->get_as_string("#i",e1).value,"39")
    << "could not retrieve correct value for edge attribute #i";
    EXPECT_EQ(net->->get_as_string("#t",e1).value,uu::core::to_string(uu::core::epoch_to_time("19434")))
    << "could not retrieve correct value for actor attribute #t";

    EXPECT_EQ(net->->get_as_string("name",a2).null,true)
    << "could not retrieve null value";

    EXPECT_EQ(4,net->->get_actor_attributes().size())
    << "could not retrieve list of actor attributes";

    EXPECT_EQ(4,net->->get_edge_attributes().size())
    << "could not retrieve list of edge attributes";

    // test weights
    EXPECT_THROW(net->->set_weight(e1,31.5),uu::core::ElementNotFoundException)
    << "did not recognize that the weight attribute was not set";

    net->->set_weight_attribute("#d");
    net->->set_weight(e1,31.5);

    EXPECT_EQ(31.5,net->->get_weight(e1).value)
    << "could not retrieve correct edge weight";
}
 */
