#include "gtest/gtest.h"

#include "networks/Network.hpp"
#include "community/louvain.hpp"
#include "core/exceptions/DuplicateElementException.hpp"
#include "core/exceptions/ElementNotFoundException.hpp"
#include "core/exceptions/WrongParameterException.hpp"

TEST(networks_test, Network)
{

    auto dir = uu::net::EdgeDir::UNDIRECTED;
    auto loops = uu::net::LoopMode::DISALLOWED;
    auto g = std::make_unique<uu::net::Network>("g", dir, loops);

    // Adding vertices

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    // Adding edges

    auto e = g->edges()->add(v1, v2);
    g->edges()->add(v1, v3);

    // Attributes

    g->vertices()->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    g->vertices()->attr()->set_double(v1, "a1", 3.4);
    auto vertex_attr_value = g->vertices()->attr()->get_double(v1, "a1");
    EXPECT_EQ(3.4, vertex_attr_value.value);

    g->edges()->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    g->edges()->attr()->set_double(e, "a1", 3.4);
    auto edge_attr_value = g->edges()->attr()->get_double(e, "a1");
    EXPECT_EQ(3.4, edge_attr_value.value);

    // Exception handling: adding a vertex with the same name of a vertex already in the network

    auto v3_bis = std::make_shared<uu::net::Vertex>("v3");

    EXPECT_EQ(
        g->vertices()->add("v3"),
        nullptr
    );

    EXPECT_EQ(
        g->vertices()->add(v3_bis),
        nullptr
    );

    // Exception handling: adding an edge to a vertex that is not in the network

    EXPECT_THROW(
        g->edges()->add(v1, v3_bis.get()),
        uu::core::ElementNotFoundException
    );

    // Exception handling: loops not allowed

    EXPECT_THROW(
        g->edges()->add(v1, v1),
        uu::core::WrongParameterException
    );

    // The removal of a vertex propagates to the edges

    g->vertices()->erase(v1);

    EXPECT_EQ((size_t)0, g->edges()->size())
            << "Vertex removal was not propagated to the edges";

}


TEST(networks_test, Network_from_cubes)
{
        // @todo 
}
