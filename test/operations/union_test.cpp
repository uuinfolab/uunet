#include "gtest/gtest.h"

#include "networks/Network.hpp"
#include "operations/union.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/exceptions/NullPtrException.hpp"

TEST(operations_test, graph_union)
{

    // creating some simple graphs

    auto g1 = std::make_unique<uu::net::Network>("g1", uu::net::EdgeDir::DIRECTED);
    auto g2 = std::make_unique<uu::net::Network>("g2", uu::net::EdgeDir::DIRECTED);

    auto v1 = g1->vertices()->add("v1");
    auto v2 = g1->vertices()->add("v2");
    auto v3 = g1->vertices()->add("v3");

    g2->vertices()->add(v2);
    g2->vertices()->add(v3);

    g1->edges()->add(v1, v2);
    g1->edges()->add(v2, v3);

    g2->edges()->add(v2, v3);
    g2->edges()->add(v3, v2);

    // union

    auto u_graph = uu::net::graph_union(g1.get(), g2.get());

    size_t n = u_graph->vertices()->size();
    size_t m = u_graph->edges()->size();
    ASSERT_EQ(n, (size_t) 3);
    ASSERT_EQ(m, (size_t) 3);

    // Exception handling

    /* multiple edges with same end-vertices

    g1->edges()->add(v3, v2);

    EXPECT_THROW(
        uu::net::graph_union(g1.get(), g2.get()),
        uu::core::OperationNotSupportedException
    );
     */

    // null parameters

    EXPECT_THROW(
        uu::net::graph_union((uu::net::Network*)nullptr, g2.get()),
        uu::core::NullPtrException
    );

    EXPECT_THROW(
        uu::net::graph_union(g1.get(), (uu::net::Network*)nullptr),
        uu::core::NullPtrException
    );

}
