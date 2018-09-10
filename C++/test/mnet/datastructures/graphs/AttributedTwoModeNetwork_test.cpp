#include "gtest/gtest.h"

#include "mnet/datastructures/graphs/AttributedTwoModeNetwork.h"
#include <tuple>


class mnet_datastructures_graphs_AttributedTwoModeNetwork_test : public ::testing::Test
{
  protected:

    virtual void
    SetUp()
    {
    }


};

TEST_F(mnet_datastructures_graphs_AttributedTwoModeNetwork_test, creation)
{

    // Creating an empty multiplex network

    auto net = uu::net::create_attributed_twomode_network("a 2-mode net", uu::net::EdgeDir::UNDIRECTED);


    // Adding vertices to the top partition

    const uu::net::Vertex* g1 = net->top()->vertices()->add("group1");
    const uu::net::Vertex* g2 = net->top()->vertices()->add("group2");


    const uu::net::Vertex* a1 = net->bottom()->vertices()->add("actor1");
    const uu::net::Vertex* a2 = net->bottom()->vertices()->add("actor2");
    const uu::net::Vertex* a3 = net->bottom()->vertices()->add("actor3");

    // Adding edges

    net->interlayer_edges()->add(a1, g1);
    net->interlayer_edges()->add(a1, g2);
    net->interlayer_edges()->add(a2, g1);
    net->interlayer_edges()->add(a3, g2);

    // Uncomment to print network summary
    std::cout << net->summary() << std::endl;

}

