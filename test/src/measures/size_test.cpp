#include "./measures.hpp"

#include "measures/size.hpp"

TEST_F(net_measures_test, size)
{
    auto m = uu::net::size(g.get());
    ASSERT_EQ(m, (size_t) 7);
}
