#include "algoml_test.hpp" // defines the input network

#include "community/infomap.hpp"


TEST_F(community_mlalgo_test, infomap)
{
    auto c = uu::net::infomap(net.get());

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }

}

