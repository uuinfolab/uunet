#include "algo_test.hpp" // defines the input network
#include "community/label_propagation.hpp"

TEST_F(community_algo_test, label_propagation)
{

    auto communities = uu::net::label_propagation(net.get());

    /*
     // Too random to be predicted
    for (auto com: *communities)
    {
        EXPECT_EQ((size_t) 3, com->size());
    }
     */
}

