#include "gtest/gtest.h"
#include "algorithms_test.hpp" // defines graph g
#include "algorithms/components.hpp"

TEST_F(net_algorithms_test, components)
{
    std::vector<int> comp_id = uu::net::components(g);

    size_t pos_v1 = g->vertices()->index_of(v1);
    size_t pos_v2 = g->vertices()->index_of(v2);
    size_t pos_v3 = g->vertices()->index_of(v3);
    size_t pos_v8 = g->vertices()->index_of(v8);
    size_t pos_v9 = g->vertices()->index_of(v9);

    EXPECT_NE(comp_id.at(pos_v1), comp_id.at(pos_v2));
    EXPECT_NE(comp_id.at(pos_v1), comp_id.at(pos_v3));
    EXPECT_NE(comp_id.at(pos_v1), comp_id.at(pos_v8));
    EXPECT_NE(comp_id.at(pos_v1), comp_id.at(pos_v9));

    EXPECT_NE(comp_id.at(pos_v2), comp_id.at(pos_v8));
    EXPECT_NE(comp_id.at(pos_v2), comp_id.at(pos_v9));
    EXPECT_NE(comp_id.at(pos_v3), comp_id.at(pos_v8));
    EXPECT_NE(comp_id.at(pos_v3), comp_id.at(pos_v9));

    EXPECT_EQ(comp_id.at(pos_v2), comp_id.at(pos_v3));
    EXPECT_EQ(comp_id.at(pos_v8), comp_id.at(pos_v9));
}
