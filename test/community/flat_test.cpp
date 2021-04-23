#include "multilayer_community_algorithms_test.hpp"

#include <cstdio>
#include <iostream>

#include "community/flat.hpp"


TEST_F(multilayer_community_algorithms_test, flat_nw)
{
    auto c = uu::net::flat_nw(net.get());

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }
}

TEST_F(multilayer_community_algorithms_test, flat_ec)
{
    auto c = uu::net::flat_ec(net.get());

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }
}
