#include "gtest/gtest.h"

#include "community/VertexCommunity.hpp"
#include "objects/Vertex.hpp"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class net_community_VertexCommunity_test : public ::testing::Test
{
  protected:

};

TEST_F(net_community_VertexCommunity_test, VertexCommunity)
{

    uu::net::VertexCommunity c;

    auto v1 = std::make_shared<uu::net::Vertex>("v1");
    auto v2 = std::make_shared<uu::net::Vertex>("v2");

    // Adding vertices to the community
    c.add(v1.get());
    c.add(v2.get());

    EXPECT_EQ((size_t)2, c.size())
            << "Wrong community size";
}

