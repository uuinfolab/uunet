#include "./measures_ml.hpp"

#include "measures/relevance.hpp"

#include <vector>


TEST_F(net_measures_ml_test, relevance)
{
    std::vector<const uu::net::Network*> l = {l1};
    double rel = uu::net::relevance(net.get(), l.begin(), l.end(), v1);
    EXPECT_EQ(rel, 2.0/3);
}

TEST_F(net_measures_ml_test, xrelevance)
{
    std::vector<const uu::net::Network*> l = {l1};
    double xrel = uu::net::xrelevance(net.get(), l.begin(), l.end(), v1);
    EXPECT_EQ(xrel, 2.0/3);
}
