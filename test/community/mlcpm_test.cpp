#include "multilayer_community_algorithms_test.hpp"

#include <cstdio>
#include <iostream>

#include "community/ml-cpm.hpp"


TEST_F(multilayer_community_algorithms_test, mlcpm)
{
    auto c = uu::net::mlcpm(net.get(), 3, 1);

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }

}

