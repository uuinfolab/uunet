#include "./measures_ml.hpp"

#include "measures/neighborhood.hpp"

#include <vector>


TEST_F(net_measures_ml_test, neighborhood)
{
    size_t n = uu::net::neighbors(net->layers()->begin(), net->layers()->end(), v1).size();
    EXPECT_EQ(n, (size_t) 3);
}

TEST_F(net_measures_ml_test, xneighborhood)
{
    std::vector<const uu::net::Network*> l = {l1};
    size_t n = uu::net::xneighbors(net.get(), l.begin(), l.end(), v2).size();
    EXPECT_EQ(n, (size_t) 2);
}
