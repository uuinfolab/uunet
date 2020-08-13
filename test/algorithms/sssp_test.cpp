#include "gtest/gtest.h"
#include "algorithms_test.hpp" // defines graph g
#include "algorithms/sssp.hpp"

TEST_F(net_algorithms_test, sssp)
{

    auto spl = uu::net::single_source_path_length(g, v2);

    size_t pos_v1 = g->vertices()->index_of(v1);
    size_t pos_v2 = g->vertices()->index_of(v2);
    size_t pos_v3 = g->vertices()->index_of(v3);
    size_t pos_v4 = g->vertices()->index_of(v4);
    size_t pos_v7 = g->vertices()->index_of(v7);
    size_t pos_v8 = g->vertices()->index_of(v8);

    EXPECT_EQ(spl.at(pos_v1), -1);
    EXPECT_EQ(spl.at(pos_v2), 0);
    EXPECT_EQ(spl.at(pos_v3), 2);
    EXPECT_EQ(spl.at(pos_v4), 1);
    EXPECT_EQ(spl.at(pos_v7), 3);
    EXPECT_EQ(spl.at(pos_v8), -1);
}

