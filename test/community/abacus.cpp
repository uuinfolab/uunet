#include "multilayer_community_algorithms_test.hpp"

#include <cstdio>
#include <iostream>

#include "community/abacus.hpp"


TEST_F(multilayer_community_algorithms_test, abacus)
{
    auto c = uu::net::abacus(net.get(), 3, 1);

    /*
    for (auto com: *c)
    {
        for (auto v: *com)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    */
    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }

}

