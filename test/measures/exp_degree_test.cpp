#include "./measures_p.hpp"

#include "measures/exp_degree.hpp"

TEST_F(net_measures_p_test, exp_degree)
{
    double s1 = uu::net::exp_degree(g.get(), v1);
    EXPECT_DOUBLE_EQ(s1, 0);

    double s2 = uu::net::exp_degree(g.get(), v2);
    EXPECT_DOUBLE_EQ(s2, .7);

    double s4 = uu::net::exp_degree(g.get(), v4);
    EXPECT_DOUBLE_EQ(s4, 1.9);
}

