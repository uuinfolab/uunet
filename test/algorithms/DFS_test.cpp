#include "gtest/gtest.h"
#include "algorithms_test.hpp"
#include "algorithms/DFS.hpp"
#include <string>

TEST_F(net_algorithms_test, DFS)
{
    uu::net::DFS<uu::net::Network> dfs(g, v7, uu::net::EdgeMode::INOUT);

    auto it = dfs.begin();
    EXPECT_EQ((*it)->name, "v7");

    std::string vname;

    vname = (*++it)->name; // prefix++: vname should of the next vertex
    EXPECT_TRUE(vname=="v5" || vname=="v6");

    vname = (*++it)->name; // prefix++: vname should of the next vertex
    EXPECT_EQ((*it)->name, "v4");

    EXPECT_EQ((*it++)->name, "v4");

    vname = (*it++)->name;
    EXPECT_TRUE(vname=="v2" || vname=="v3");

    vname = (*it++)->name;
    EXPECT_TRUE(vname=="v2" || vname=="v3");

    vname = (*it++)->name;
    EXPECT_TRUE(vname=="v5" || vname=="v6");

    EXPECT_EQ(it, dfs.end());
}


