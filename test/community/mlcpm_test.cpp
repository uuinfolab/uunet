#include "algoml_test.hpp" // defines the input network

#include "community/mlcpm.hpp"


TEST_F(community_mlalgo_test, mlcpm)
{
    auto c = uu::net::mlcpm(net.get(), 3, 1);

    for (auto com: *c)
    {
        EXPECT_EQ((size_t) 6, com->size());
    }

}

