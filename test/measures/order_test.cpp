#include "./measures.hpp"

#include "measures/order.hpp"

TEST_F(net_measures_test, order)
{
    auto n = uu::net::order(g.get());
    ASSERT_EQ(n, (size_t) 9);
}
