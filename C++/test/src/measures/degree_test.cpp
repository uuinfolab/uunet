#include "./measures.hpp"

#include "measures/degree.hpp"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>


TEST_F(net_measures_test, minimum_degree)
{
    size_t min_d = uu::net::minimum_degree(g.get());
    EXPECT_EQ(min_d, (size_t) 0);
}


TEST_F(net_measures_test, maximum_degree)
{
    size_t max_d = uu::net::maximum_degree(g.get());
    EXPECT_EQ(max_d, (size_t) 4);
}


TEST_F(net_measures_test, average_degree)
{
    double avg_d = uu::net::average_degree(g.get());
    EXPECT_EQ(avg_d, 14.0 / 9.0);
}


TEST_F(net_measures_test, degree_sequence)
{
    std::vector<size_t> seq = uu::net::degree_sequence(g.get());
    std::vector<size_t> true_seq = {0, 1, 1, 1, 1, 2, 2, 2, 4};
    EXPECT_EQ(seq, true_seq);
}

TEST_F(net_measures_test, degree_distribution)
{
    std::vector<size_t> dist = uu::net::degree_distribution(g.get());
    std::vector<size_t> true_dist = {1, 4, 3, 0, 1};
    EXPECT_EQ(dist, true_dist);
}

TEST_F(net_measures_test, degree)
{
    size_t deg1 = uu::net::degree(g.get(), v1);
    EXPECT_EQ(deg1, (size_t) 0);

    size_t deg2 = uu::net::degree(g.get(), v2);
    EXPECT_EQ(deg2, (size_t) 1);

    size_t deg4 = uu::net::degree(g.get(), v4);
    EXPECT_EQ(deg4, (size_t) 4);
}

