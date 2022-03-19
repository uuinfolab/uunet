#include "gtest/gtest.h"

#include "networks/Network.hpp"
#include "operations/subdivision.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/exceptions/NullPtrException.hpp"


TEST(operations_test, edge_subdivision_directed)
{

    // creating a simple graph

    auto dir = uu::net::EdgeDir::DIRECTED;
    auto g = std::make_unique<uu::net::Network>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");

    auto e1 = g->edges()->add(v1, v2);

    // test

    auto new_vertex = uu::net::edge_subdivision(g.get(), e1, "new_vertex");

    size_t n = g->vertices()->size();
    size_t m = g->edges()->size();

    EXPECT_EQ(n, (size_t) 3);
    EXPECT_EQ(m, (size_t) 2);

    EXPECT_TRUE(g->edges()->get(v1, new_vertex) != nullptr);
    EXPECT_TRUE(g->edges()->get(new_vertex, v2) != nullptr);

}



TEST(operations_test, edge_subdivision_undirected)
{

    // creating a simple graph

    auto dir = uu::net::EdgeDir::UNDIRECTED;
    auto g = std::make_unique<uu::net::Network>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");

    auto e1 = g->edges()->add(v1, v2);

    // test

    auto new_vertex = uu::net::edge_subdivision(g.get(), e1, "new_vertex");

    size_t n = g->vertices()->size();
    size_t m = g->edges()->size();

    EXPECT_EQ(n, (size_t) 3);
    EXPECT_EQ(m, (size_t) 2);

    EXPECT_TRUE(g->edges()->get(new_vertex, v1) != nullptr);
    EXPECT_TRUE(g->edges()->get(new_vertex, v2) != nullptr);

}



TEST(operations_test, edge_subdivision_exceptions)
{

    // creating a simple graph

    auto dir = uu::net::EdgeDir::UNDIRECTED;
    auto g = std::make_unique<uu::net::Network>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");

    auto e1 = g->edges()->add(v1, v2);

    // test

    EXPECT_THROW(
        uu::net::edge_subdivision(g.get(),
                                  (uu::net::Edge*)nullptr,
                                  "name"),
        uu::core::NullPtrException
    );


    EXPECT_THROW(
        uu::net::edge_subdivision((uu::net::Network*)nullptr,
                                  e1,
                                  "name"),
        uu::core::NullPtrException
    );
}
