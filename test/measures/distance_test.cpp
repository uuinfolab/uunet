#include "./measures_ml.hpp"

#include "measures/distance.hpp"

#include <vector>


TEST_F(net_measures_ml_test, distance)
{
    auto dist = uu::net::pareto_distance(net.get(), v1);

    EXPECT_EQ(dist[v2].size(), (std::size_t) 2);
    for (auto d: dist[v2])
    {
        if (d.length() == 1)
        {
            EXPECT_EQ(d.length(l1), (std::size_t) 1);
            EXPECT_EQ(d.length(l2), (std::size_t) 0);
        }
        else
        {
            EXPECT_EQ(d.length(), (std::size_t) 2);
            EXPECT_EQ(d.length(l1), (std::size_t) 0);
            EXPECT_EQ(d.length(l2), (std::size_t) 2);
        }
        
    }
}
