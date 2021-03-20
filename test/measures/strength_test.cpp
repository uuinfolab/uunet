#include "./measures_w.hpp"

#include "measures/strength.hpp"

/* ONLY STRENGTH DEFINED SO FAR
TEST_F(net_measures_w_test, minimum_strength)
{
    double min = uu::net::minimum_strength(g.get());
    EXPECT_EQ(min, 0);
}


TEST_F(net_measures_w_test, maximum_strength)
{
    size_t max = uu::net::maximum_strength(g.get());
    EXPECT_EQ(max, 1.9);
}


TEST_F(net_measures_w_test, average_strength)
{
    double avg = uu::net::average_strength(g.get());
    EXPECT_EQ(avg, 7.4 / 9.0);
}


TEST_F(net_measures_w_test, strength_sequence)
{
    std::vector<double> seq = uu::net::strength_sequence(g.get());
    std::vector<double> true_seq = {4, 2, 2, 2, 1, 1, 1, 1, 0};
    EXPECT_EQ(seq, true_seq);
}
*/

TEST_F(net_measures_w_test, strength)
{
    double s1 = uu::net::strength(g.get(), v1);
    EXPECT_DOUBLE_EQ(s1, 0);

    double s2 = uu::net::strength(g.get(), v2);
    EXPECT_DOUBLE_EQ(s2, .7);

    double s4 = uu::net::strength(g.get(), v4);
    EXPECT_DOUBLE_EQ(s4, 1.9);
}

