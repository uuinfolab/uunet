#include "./measures_ml.hpp"

#include "measures/layer.hpp"
#include "io/read_multilayer_network.hpp"

#include <vector>


TEST_F(net_measures_ml_test, jaccard_edge)
{
    double val = uu::net::jaccard_edge(net.get(), l1, l1);
    EXPECT_DOUBLE_EQ(val, 1.0);
    
    val = uu::net::jaccard_edge(net.get(), l1, l2);
    EXPECT_DOUBLE_EQ(val, 3.0/7.0);
}

TEST_F(net_measures_ml_test, pearson_degree)
{
    double val = uu::net::pearson_degree(net.get(), l1, l1);
    EXPECT_DOUBLE_EQ(val, 1.0);
    
    val = uu::net::pearson_degree(net.get(), l1, l2);
    EXPECT_DOUBLE_EQ(val, 0.0);
    
}
