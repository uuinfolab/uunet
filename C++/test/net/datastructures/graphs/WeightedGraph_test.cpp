#include "gtest/gtest.h"

#include "net/datastructures/graphs/WeightedGraph.h"

class net_datastructures_graphs_WeightedGraph_test : public ::testing::Test {
protected:
	virtual void SetUp() {
	}
    
	// virtual void TearDown() {}
};

TEST_F(net_datastructures_graphs_WeightedGraph_test, all_functions) {
    
    std::unique_ptr<uu::net::WeightedGraph> g = uu::net::create_weighted_graph("a graph", uu::net::EdgeDir::DIRECTED);
    
    // Adding vertices
    const uu::net::Vertex* v1 = g->vertices()->add(uu::net::Vertex::create("miao"));
    const uu::net::Vertex* v2 = g->vertices()->add(uu::net::Vertex::create("bau"));
    const uu::net::Vertex* v3 = g->vertices()->add(uu::net::Vertex::create("coucou"));
    
    
    // Adding edges
    const uu::net::Edge* e1 = g->edges()->add(uu::net::Edge::create(v1, v2, uu::net::EdgeDir::DIRECTED));
    const uu::net::Edge* e2 = g->edges()->add(uu::net::Edge::create(v1, v3, uu::net::EdgeDir::DIRECTED));
    
    
    // Setting/getting weights
    g->edges()->attr()->set_weight(e1, 3.4);
    EXPECT_EQ(3.4, g->edges()->attr()->get_weight(e1).value)
    << "Weight not set correctly";
    
    EXPECT_TRUE(g->edges()->attr()->get_weight(e2).null)
    << "Attribute should not be set";
    
    
    // Propagation
    g->edges()->erase(e1);
    EXPECT_TRUE(g->edges()->attr()->get_weight(e1).null)
    << "Vertex removal not propagated to its attributes";
    
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
    
    EXPECT_TRUE(g->is_weighted())
    << "Wrong graph type: should be weighter";
    
    // Uncomment the following line to print a summary of the graph
    //std::cout << g->summary() << std::endl;
    
}
