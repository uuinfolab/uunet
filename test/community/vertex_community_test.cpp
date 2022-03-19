#include "gtest/gtest.h"

#include "community/Community.hpp"
#include "networks/Network.hpp"


TEST(net_community_test, VertexCommunity)
{

    uu::net::Community<uu::net::Network> c;

    auto v1 = std::make_shared<uu::net::Vertex>("v1");
    auto v2 = std::make_shared<uu::net::Vertex>("v2");

    // Adding vertices to the community
    c.add(v1.get());
    c.add(v2.get());

    EXPECT_EQ((size_t)2, c.size())
            << "Wrong community size";
}

