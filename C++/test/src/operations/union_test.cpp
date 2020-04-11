#include "gtest/gtest.h"

#include "networks/Network.hpp"
#include "operations/union.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/exceptions/NullPtrException.hpp"

TEST(net_operations_test, graph_union)
{

    // creating some simple graphs

    auto v1 = std::make_shared<const uu::net::Vertex>("v1");
    auto v2 = std::make_shared<const uu::net::Vertex>("v2");
    auto v3 = std::make_shared<const uu::net::Vertex>("v3");

    auto dir = uu::net::EdgeDir::DIRECTED;
    auto e1 = std::make_shared<const uu::net::Edge>(v1.get(), v2.get(), dir);
    auto e2 = std::make_shared<const uu::net::Edge>(v2.get(), v3.get(), dir);
    auto e3 = std::make_shared<const uu::net::Edge>(v3.get(), v2.get(), dir);
    auto e4 = std::make_shared<const uu::net::Edge>(v3.get(), v2.get(), dir);

    auto g1 = std::make_unique<uu::net::Network>("g1", dir);
    auto g2 = std::make_unique<uu::net::Network>("g2", dir);

    g1->vertices()->add(v1);
    g1->vertices()->add(v2);
    g1->vertices()->add(v3);

    g2->vertices()->add(v2);
    g2->vertices()->add(v3);

    g1->edges()->add(e1);
    g1->edges()->add(e2);

    g2->edges()->add(e2);
    g2->edges()->add(e3);

    // union

    auto u_graph = uu::net::graph_union(g1.get(), g2.get());

    size_t n = u_graph->vertices()->size();
    size_t m = u_graph->edges()->size();
    ASSERT_EQ(n, (size_t) 3);
    ASSERT_EQ(m, (size_t) 3);

    // Exception handling

    // multiple edges with same end-vertices

    g1->edges()->add(e4);

    EXPECT_THROW(
        uu::net::graph_union(g1.get(), g2.get()),
        uu::core::OperationNotSupportedException
    );

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
