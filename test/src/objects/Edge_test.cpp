#include "gtest/gtest.h"

#include "objects/Edge.hpp"
#include "core/exceptions/NullPtrException.hpp"

TEST(objects_test, Edge)
{

    // Creating some vertices

    auto v1_ = std::make_unique<uu::net::Vertex>("v1");
    auto v1 = v1_.get();

    auto v2_ = std::make_unique<uu::net::Vertex>("v2");
    auto v2 = v2_.get();

    auto v3_ = std::make_unique<uu::net::Vertex>("v3");
    auto v3 = v3_.get();

    // Creating some edges

    auto und = uu::net::EdgeDir::UNDIRECTED;
    auto dir = uu::net::EdgeDir::DIRECTED;

    auto e1 = std::make_unique<uu::net::Edge>(v1, v2, und);
    auto e2 = std::make_unique<uu::net::Edge>(v2, v3, dir);
    auto e3 = std::make_unique<uu::net::Edge>(v2, v3, und);
    auto e4 = std::make_unique<uu::net::Edge>(v2, v3, und);

    auto edge_copy = e1.get();
    auto edge_copy2 = e1.get();

    EXPECT_THROW(std::make_unique<uu::net::Edge>(nullptr, v1, und), uu::core::NullPtrException);
    EXPECT_THROW(std::make_unique<uu::net::Edge>(v1, nullptr, und), uu::core::NullPtrException);

    // Accessing vertices

    ASSERT_EQ(e2->v1->name, "v2");
    ASSERT_EQ(e2->v2->name, "v3");

    // Testing equality

    ASSERT_EQ(edge_copy, edge_copy2);

    ASSERT_EQ(*edge_copy, *edge_copy2);

    // Different edges with the same end-vertices and directionality

    ASSERT_NE(e3, e4);

    ASSERT_NE(*e3, *e4);

}


