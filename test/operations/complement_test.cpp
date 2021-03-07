#include "gtest/gtest.h"

#include "networks/Network.hpp"
#include "operations/complement.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/exceptions/NullPtrException.hpp"


TEST(operations_test, graph_complement_directed)
{

    // creating a simple graph

    auto dir = uu::net::EdgeDir::DIRECTED;
    auto g = std::make_unique<uu::net::Network>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    g->edges()->add(v1, v2);
    g->edges()->add(v2, v3);

    // complement

    auto c_graph = uu::net::graph_complement(g.get());

    size_t n = c_graph->vertices()->size();
    size_t m = c_graph->edges()->size();

    EXPECT_EQ(n, (size_t) 3);
    EXPECT_EQ(m, (size_t) 7);

    EXPECT_TRUE(c_graph->edges()->get(v2, v1) != nullptr);
    EXPECT_TRUE(c_graph->edges()->get(v3, v2) != nullptr);
    EXPECT_TRUE(c_graph->edges()->get(v1, v3) != nullptr);
    EXPECT_TRUE(c_graph->edges()->get(v3, v1) != nullptr);

}


TEST(operations_test, graph_complement_undirected)
{

    // creating a simple graph

    auto dir = uu::net::EdgeDir::UNDIRECTED;
    auto g = std::make_unique<uu::net::Network>("g", dir);

    auto v1 = g->vertices()->add("v1");
    auto v2 = g->vertices()->add("v2");
    auto v3 = g->vertices()->add("v3");

    g->edges()->add(v1, v2);
    g->edges()->add(v2, v3);

    // complement

    auto c_graph = uu::net::graph_complement(g.get());

    size_t n = c_graph->vertices()->size();
    size_t m = c_graph->edges()->size();

    EXPECT_EQ(n, (size_t) 3);
    EXPECT_EQ(m, (size_t) 4);

    EXPECT_TRUE(c_graph->edges()->get(v1, v3) != nullptr);

}


TEST(operations_test, graph_complement_exceptions)
{
    EXPECT_THROW(
        uu::net::graph_complement((uu::net::Network*)nullptr),
        uu::core::NullPtrException
    );
}
