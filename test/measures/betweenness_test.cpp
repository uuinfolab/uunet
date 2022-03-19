#include "./measures.hpp"

#include "measures/betweenness.hpp"

TEST_F(net_measures_test, betweenness)
{
    auto C_b = uu::net::betweenness(g.get());

    EXPECT_EQ(C_b[v1], 0.0);
    EXPECT_EQ(C_b[v4], 7.5);
    EXPECT_EQ(C_b[v6], 1.5);
    EXPECT_EQ(C_b[v8], 0.0);
}
