#include "gtest/gtest.h"

#include "networks/MultiNetwork.hpp"
#include "core/exceptions/ElementNotFoundException.hpp"

TEST(networks_test, MultiNetwork)
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

    // Checking network properties
    
    EXPECT_TRUE(g->is_directed());
    
    EXPECT_TRUE(g->allows_multi_edges());
    
    EXPECT_TRUE(g->allows_loops());
    
    EXPECT_FALSE(g->is_weighted());
    
    EXPECT_FALSE(g->is_probabilistic());
    
    EXPECT_FALSE(g->is_temporal());

}
