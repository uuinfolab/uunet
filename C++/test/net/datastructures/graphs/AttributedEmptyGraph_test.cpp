#include "gtest/gtest.h"

#include "net/datastructures/graphs/AttributedEmptyGraph.h"

class net_datastructures_graphs_AttributedEmptyGraph_test : public ::testing::Test
{
  protected:
    virtual void
    SetUp()
    {
    }

    // virtual void TearDown() {}
};

TEST_F(net_datastructures_graphs_AttributedEmptyGraph_test, all_functions)
{

    std::unique_ptr<uu::net::AttributedEmptyGraph> g = uu::net::create_attributed_empty_graph("a graph");

    // Adding vertices
    const uu::net::Vertex* v1 = g->vertices()->add(uu::net::Vertex::create("miao"));
    g->vertices()->add(uu::net::Vertex::create("bau"));
    g->vertices()->add(uu::net::Vertex::create("coucou"));

    // Attributes

    g->vertices()->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    g->vertices()->attr()->set_double(v1, "a1", 3.4);
    EXPECT_EQ(3.4, g->vertices()->attr()->get_double(v1, "a1").value)
            << "Attribute value not set correctly (vertex)";

    // Checking graph properties

    EXPECT_FALSE(g->allows_multi_edges())
            << "Wrong graph type: should not allow multi-edges";

    EXPECT_FALSE(g->allows_loops())
            << "Wrong graph type: should not allow loops";

    // Uncomment the following line to print a summary of the graph

    std::cout << g->summary() << std::endl;

}
