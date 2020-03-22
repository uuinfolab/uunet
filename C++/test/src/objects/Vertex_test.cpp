#include "gtest/gtest.h"

#include "objects/Vertex.hpp"

TEST(objects_test, Vertex)
{

    // Creating some vertices

    auto v1_ = std::make_unique<uu::net::Vertex>("v");
    auto v1 = v1_.get();

    auto v2_ = std::make_unique<uu::net::Vertex>("v");
    auto v2 = v2_.get();

    auto vertex_copy = v1;

    // Vertex name

    ASSERT_EQ(v1->name, "v");

    // Testing equality

    ASSERT_EQ(vertex_copy, v1);

    ASSERT_EQ(*vertex_copy, *v1);

    // Different vertices with the same name

    ASSERT_NE(v1, v2);

    ASSERT_NE(*v1, *v2);

}


