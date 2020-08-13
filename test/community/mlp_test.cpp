#include "multilayer_community_algorithms_test.hpp"

#include <cstdio>
#include <iostream>

#include "community/mlp.hpp"


TEST_F(multilayer_community_algorithms_test, mlp)
{
    auto c = uu::net::mlp(net.get());

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }

}

