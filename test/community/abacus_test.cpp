#include "algoml_test.hpp" // defines the input network
#include "community/abacus.hpp"


TEST_F(community_mlalgo_test, abacus)
{
    auto c = uu::net::abacus(net.get(), 3, 1);
/*
    for (auto com: *c)
    {
        EXPECT_EQ((size_t) 6, com->size());
    }
*/
}

