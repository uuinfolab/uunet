#include "gtest/gtest.h"

#include "algorithms_test.hpp"

#include <string>
#include "algorithms/BFS.hpp"

TEST_F(net_algorithms_test, BFS)
{

    uu::net::BFS<uu::net::Network> bfs(g, v2, uu::net::EdgeMode::INOUT);

    auto it = bfs.begin();
    EXPECT_EQ((*it)->name, "v2");

    EXPECT_EQ((*++it)->name, "v4");

    EXPECT_EQ((*it++)->name, "v4");

    std::string vname;

    vname = (*it++)->name;
    EXPECT_TRUE(vname=="v3" || vname=="v5" || vname=="v6");

    vname = (*it++)->name;
    EXPECT_TRUE(vname=="v3" || vname=="v5" || vname=="v6");

    vname = (*it++)->name;
    EXPECT_TRUE(vname=="v3" || vname=="v5" || vname=="v6");

    EXPECT_EQ((*it++)->name, "v7");

    EXPECT_EQ(it, bfs.end());
}

