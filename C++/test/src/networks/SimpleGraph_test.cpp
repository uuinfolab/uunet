#include "gtest/gtest.h"

#include "networks/Network.hpp"
#include "core/exceptions/DuplicateElementException.hpp"
#include "core/exceptions/ElementNotFoundException.hpp"
#include "core/exceptions/WrongParameterException.hpp"

TEST(networks_test, SimpleGraph)
{

    auto g = std::make_unique<uu::net::Network>("g");

    // Checking graph properties

    EXPECT_FALSE(g->is_directed());

    EXPECT_FALSE(g->allows_loops());

    // Adding some vertices to be used in the tests

    const uu::net::Vertex* v1 = g->vertices()->add("v1");
    const uu::net::Vertex* v2 = g->vertices()->add("v2");

    // Exception handling: adding an edge between two adjacent vertices

    auto e = g->edges()->add(v1, v2);

    EXPECT_EQ(
        g->edges()->add(v1, v2),
        nullptr
    );

    EXPECT_EQ(
        g->edges()->size(),
        (size_t) 1
    );

    // Directionality

    EXPECT_EQ(
        g->edges()->get(v2, v1),
        e
    );

    // Exception handling: loops not allowed

    EXPECT_THROW(
        g->edges()->add(v1, v1),
        uu::core::WrongParameterException
    );

}
