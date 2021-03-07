#include "./measures_ml.hpp"

#include "measures/degree_ml.hpp"

#include <vector>


TEST_F(net_measures_ml_test, degree)
{
    std::vector<const uu::net::Network*> l = {l1, l2};
    size_t degree = uu::net::degree(l.begin(), l.end(), v2);
    EXPECT_EQ(degree, (size_t) 6);
}

