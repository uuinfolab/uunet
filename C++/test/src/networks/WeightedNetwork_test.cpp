#include "gtest/gtest.h"

#include "networks/WeightedNetwork.hpp"

TEST(networks_test, WeightedNetwork)
{

    auto g = std::make_unique<uu::net::WeightedNetwork>("wnet", uu::net::EdgeDir::DIRECTED);

    // Adding vertices
    const uu::net::Vertex* v1 = g->vertices()->add(uu::net::Vertex::create("miao"));
    const uu::net::Vertex* v2 = g->vertices()->add(uu::net::Vertex::create("bau"));
    const uu::net::Vertex* v3 = g->vertices()->add(uu::net::Vertex::create("coucou"));


    // Adding edges
    const uu::net::Edge* e1 = g->edges()->add(uu::net::Edge::create(v1, v2, uu::net::EdgeDir::DIRECTED));
    const uu::net::Edge* e2 = g->edges()->add(uu::net::Edge::create(v1, v3, uu::net::EdgeDir::DIRECTED));


    // Setting/getting weights
    g->set_weight(e1, 3.4);
    EXPECT_EQ(3.4, g->get_weight(e1).value)
            << "Weight not set correctly";

    EXPECT_TRUE(g->get_weight(e2).null)
            << "Attribute should not be set";


    // Propagation
    g->edges()->erase(e1);
    EXPECT_TRUE(g->get_weight(e1).null)
            << "Vertex removal not propagated to its attributes";

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

    EXPECT_FALSE(g->allows_multi_edges())
            << "Wrong graph type: should not allow multi-edges";

    EXPECT_FALSE(g->allows_loops())
            << "Wrong graph type: should not allow loops";

    EXPECT_TRUE(g->is_weighted())
            << "Wrong graph type: should be weighter";

    // Uncomment the following line to print a summary of the graph
    // std::cout << g->summary() << std::endl;

}
