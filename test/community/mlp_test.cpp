#include "algoml_test.hpp" // defines the input network

#include "community/mlp.hpp"


TEST_F(community_mlalgo_test, mlp)
{
    auto c = uu::net::mlp(net.get());

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }

}

