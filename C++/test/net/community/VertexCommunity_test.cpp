#include "gtest/gtest.h"

#include "net/community/VertexCommunity.h"
#include "net/datastructures/objects/Vertex.h"

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

    auto v1 = uu::net::Vertex::create("v1");
    auto v2 = uu::net::Vertex::create("v2");

    // Adding vertices to the community
    c.add(v1.get());
    c.add(v2.get());

    EXPECT_EQ(2, c.size())
            << "Wrong community size";
}

