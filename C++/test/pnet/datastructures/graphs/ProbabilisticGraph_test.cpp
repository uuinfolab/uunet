#include "gtest/gtest.h"                                                                             // I could not find this file (but it is not important)

#include "pnet/datastructures/graphs/ProbabilisticGraph.h"                                           // changed

class net_datastructures_graphs_ProbabilisticGraph_test : public ::testing::Test                     // changed
{
  protected:
    virtual void
    SetUp()
    {
    }

    // virtual void TearDown() {}
};

TEST_F(net_datastructures_graphs_ProbabilisticGraph_test, all_functions)                             // changed
{

    std::unique_ptr<uu::net::ProbabilisticGraph> g = uu::net::create_probabilistic_graph("a graph", uu::net::EdgeDir::DIRECTED);                      // not              uu::pnet::ProbabilisticGraph?

    // Adding vertices
    const uu::net::Vertex* v1 = g->vertices()->add(uu::net::Vertex::create("miao"));
    const uu::net::Vertex* v2 = g->vertices()->add(uu::net::Vertex::create("bau"));
    const uu::net::Vertex* v3 = g->vertices()->add(uu::net::Vertex::create("coucou"));


    // Adding edges
    const uu::net::Edge* e1 = g->edges()->add(uu::net::Edge::create(v1, v2, uu::net::EdgeDir::DIRECTED));
    const uu::net::Edge* e2 = g->edges()->add(uu::net::Edge::create(v1, v3, uu::net::EdgeDir::DIRECTED));


    // Setting/getting Probabilities
    g->edges()->attr()->set_probability(e1, 0.6);
    EXPECT_EQ(0.6, g->edges()->attr()->get_probability(e1).value)
            << "Probability not set correctly";

    EXPECT_TRUE(g->edges()->attr()->get_probability(e2).null)                                      // shouldn't be 0 or 1?
            << "Attribute (probability) should not be set";


    // Propagation
    g->edges()->erase(e1);
    EXPECT_TRUE(g->edges()->attr()->get_probability(e1).null)
            << "Vertex removal not propagated to its attributes (probability)";

    // Adding an edge to a vertex that is not in the graph produces an exception
    std::shared_ptr<const uu::net::Vertex> v = uu::net::Vertex::create("biribu");
    EXPECT_THROW(
        g->edges()->add(uu::net::Edge::create(v1, v.get(), uu::net::EdgeDir::DIRECTED)),
        uu::core::ElementNotFoundException
    );

    // The removal of a vertex propagates to the edges
    g->vertices()->erase(v1);
    EXPECT_EQ(0, g->edges()->size())
            << "Vertex removal was not propagated to the edges";


    // Checking graph properties

    EXPECT_FALSE(g->allows_multi_edges())
            << "Wrong graph type: should not allow multi-edges";

    EXPECT_FALSE(g->allows_loops())
            << "Wrong graph type: should not allow loops";

    EXPECT_TRUE(g->is_probabilistic())
            << "Wrong graph type: should be Probabilistic";

    // Uncomment the following line to print a summary of the graph
    //std::cout << g->summary() << std::endl;

}
