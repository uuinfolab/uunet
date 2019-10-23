#include "gtest/gtest.h"

#include "networks/MultiNetwork.hpp"

class networks_test : public ::testing::Test
{
  protected:
    virtual void
    SetUp()
    {
    }

    // virtual void TearDown() {}
};

TEST_F(networks_test, MultiNetwork)
{

    auto g = std::make_unique<uu::net::MultiNetwork>("mnet", uu::net::EdgeDir::DIRECTED);

    // Adding vertices
    const uu::net::Vertex* v1 = g->vertices()->add(uu::net::Vertex::create("miao"));
    const uu::net::Vertex* v2 = g->vertices()->add(uu::net::Vertex::create("bau"));
    const uu::net::Vertex* v3 = g->vertices()->add(uu::net::Vertex::create("coucou"));


    // Adding edges
    g->edges()->add(uu::net::Edge::create(v1, v2, uu::net::EdgeDir::DIRECTED));
    g->edges()->add(uu::net::Edge::create(v1, v3, uu::net::EdgeDir::DIRECTED));
    g->edges()->add(uu::net::Edge::create(v1, v3, uu::net::EdgeDir::DIRECTED));

    // Here is a multi-edge
    EXPECT_EQ((size_t)2, g->edges()->get(v1, v3).size())
            << "Multi-edge not stored correctly";


    // Adding an edge to a vertex that is not in the graph produces an exception
    std::shared_ptr<const uu::net::Vertex> v = uu::net::Vertex::create("biribu");
    EXPECT_THROW(
        g->edges()->add(uu::net::Edge::create(v1, v.get(), uu::net::EdgeDir::DIRECTED)),
        uu::core::ElementNotFoundException
    );

    // The removal of a vertex propagates to the edges
    g->vertices()->erase(v1);
    EXPECT_EQ((size_t)0, g->edges()->size())
            << "Vertex removal was not propagated to the edges";

    // Checking graph properties

    EXPECT_TRUE(g->allows_multi_edges())
            << "Wrong graph type: should allow multi-edges";

    EXPECT_FALSE(g->allows_loops())
            << "Wrong graph type: should not allow loops";

    // Uncomment the following line to print a summary of the graph
    // std::cout << g->summary() << std::endl;

}
