#include "gtest/gtest.h"

#include "networks/Network.hpp"
#include "operations/contraction.hpp"
#include "core/exceptions/NullPtrException.hpp"


TEST(operations_test, edge_contraction_directed)
{

    // creating a simple graph

    auto dir = uu::net::EdgeDir::DIRECTED;
    auto g = std::make_unique<uu::net::Network>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    auto e1 = g->edges()->add(v1, v2);
    g->edges()->add(v3, v1);
    g->edges()->add(v3, v2);

    // test

    auto new_vertex = uu::net::edge_contraction(g.get(), e1, "new_vertex");

    size_t n = g->vertices()->size();
    size_t m = g->edges()->size();

    EXPECT_EQ(n, (size_t) 2);
    EXPECT_EQ(m, (size_t) 1);

    EXPECT_TRUE(g->edges()->get(v3, new_vertex) != nullptr);

}



TEST(operations_test, edge_contraction_undirected)
{

    // creating a simple graph

    auto dir = uu::net::EdgeDir::UNDIRECTED;
    auto g = std::make_unique<uu::net::Network>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    auto e1 = g->edges()->add(v1, v2);
    g->edges()->add(v3, v1);
    g->edges()->add(v3, v2);

    // test

    auto new_vertex = uu::net::edge_contraction(g.get(), e1, "new_vertex");

    size_t n = g->vertices()->size();
    size_t m = g->edges()->size();

    EXPECT_EQ(n, (size_t) 2);
    EXPECT_EQ(m, (size_t) 1);

    EXPECT_TRUE(g->edges()->get(v3, new_vertex) != nullptr);

}



TEST(operations_test, edge_contraction_exceptions)
{

    // creating a simple graph

    auto dir = uu::net::EdgeDir::UNDIRECTED;
    auto g = std::make_unique<uu::net::Network>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");

    auto e1 = g->edges()->add(v1, v2);

    // test

    EXPECT_THROW(
        uu::net::edge_contraction(g.get(),
                                  (uu::net::Edge*)nullptr,
                                  "name"),
        uu::core::NullPtrException
    );


    EXPECT_THROW(
        uu::net::edge_contraction((uu::net::Network*)nullptr,
                                  e1,
                                  "name"),
        uu::core::NullPtrException
    );
}
