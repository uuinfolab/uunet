#include "net/datastructures/graphs/SimpleGraph.h"
#include "net/operations/subgraph.h"

#include "gtest/gtest.h"

class GraphTest : public ::testing::Test {
protected:
	virtual void SetUp() {
	}
    
	// virtual void TearDown() {}
};

TEST_F(GraphTest, DirectedGraph) {
    
    std::unique_ptr<uu::net::SimpleGraph> g = uu::net::create_simple_graph("a graph", uu::net::EdgeDir::DIRECTED);
    
    //uu::net::SimpleGraph::create("a simple graph", uu::net::EdgeDir::DIRECTED);
    // Adding vertices
    const uu::net::Vertex* v1 = (*g).vertices().add(uu::net::Vertex::create("miao"));
    const uu::net::Vertex* v2 = (*g).vertices().add(uu::net::Vertex::create("bau"));
    const uu::net::Vertex* v3 = (*g).vertices().add(uu::net::Vertex::create("coucou"));
    
    // SUBGRAPH - move to operations tests
    
    std::unique_ptr<uu::net::SimpleGraph> g2 = uu::net::create_simple_graph("a graph", uu::net::EdgeDir::DIRECTED);
    
    std::vector<const uu::net::Vertex*> ver({v1,v3});
    //uu::net::vertex_induced_subgraph((*g), ver.begin(), ver.end(), (*g)2);
    
    //for (auto vertex: g2.vertices())
    //    std::cout << vertex->name << std::endl;
    
    
    // Adding edges
    //const uu::net::Edge* e1 =
    (*g).edges().add(uu::net::Edge::create(v1, v2, uu::net::EdgeDir::DIRECTED));
    
    
    // Adding an edge to a vertex that is not in the graph produces an exception
    std::shared_ptr<const uu::net::Vertex> v = uu::net::Vertex::create("biribu");
    // @todo try with existing name
    EXPECT_THROW(
                 (*g).edges().add(uu::net::Edge::create(v1, v.get(), uu::net::EdgeDir::DIRECTED)),
                 uu::core::ElementNotFoundException
                 );

    
    /*
    (*g).vertices().attr().add(uu::core::Attribute::create("a1", uu::core::AttributeType::STRING));
    (*g).vertices().attr().set_string(v1, "a1", "miao");
    //std::cout << g.vertices().attr().get_string(v1, "a1").value << std::endl;
    */
    
    // The removal of a vertex propagates to the edges
    (*g).vertices().erase(v1);
    EXPECT_EQ(0,(*g).edges().size())
    << "Vertex removal was not propagated to the edges";
    
    // Uncomment the following line to print a summary of the graph
    // std::cout << g->summary() << std::endl;
}
