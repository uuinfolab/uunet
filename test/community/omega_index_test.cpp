#include "eval_test.hpp"

#include "community/omega_index.hpp"



TEST_F(community_eval_test, omega_index_equal)
{
    // testing {{1,2} {3,4}} vs. {{1,2} {3,4}}
    // N=6, A_0=4, A_1=2, N_01=4, N_02=4, N_11=2, N_12=2
    // Expected: obs = (4+2)/6, exp = (4x4 + 2x2)/(6x6), OI=1

    // Adding vertices to the community
    c1_1->add(v1);
    c1_1->add(v2); 
    c1_2->add(v3);
    c1_2->add(v4);
    c1->add(std::move(c1_1));
    c1->add(std::move(c1_2));

    c2_1->add(v1);
    c2_1->add(v2);
    c2_2->add(v3);
    c2_2->add(v4);
    c2->add(std::move(c2_1));
    c2->add(std::move(c2_2));

    EXPECT_EQ(1.0, uu::net::omega_index(c1.get(), c2.get(), 4));
}

TEST_F(community_eval_test, omega_index_equal_overlapping)
{
    // testing {{1,2,3} {2,3,4}} vs. {{1,2,3} {2,3,4}}
    // N=6, A_0=1, A_1=4, A_2=1, N_01=1, N_02=1, N_11=4, N_12=4, N_21=1, N_22=1
    // Expected: obs = (1+4+1)/6, exp = (1x1 + 4x4 + 1x1)/(6x6), OI=1

    // Adding vertices to the community
    c1_1->add(v1);
    c1_1->add(v2);
    c1_1->add(v3);
    c1_2->add(v2);
    c1_2->add(v3);
    c1_2->add(v4);
    c1->add(std::move(c1_1));
    c1->add(std::move(c1_2));

    c2_1->add(v1);
    c2_1->add(v2);
    c2_1->add(v3);
    c2_2->add(v2);
    c2_2->add(v3);
    c2_2->add(v4);
    c2->add(std::move(c2_1));
    c2->add(std::move(c2_2));
    
    EXPECT_EQ(1.0, uu::net::omega_index(c1.get(), c2.get(), 4));
}

TEST_F(community_eval_test, omega_index_nomatch)
{
    // testing {{1,2,3} {4}} vs. {{1,2} {3,4}}
    // N=6, A_0=2, A_1=1, N_01=3, N_02=4, N_11=3, N_12=2
    // Expected: obs = (2+1)/6, exp = (4x3 + 3x2)/(6x6), OI=0

    // Adding vertices to the community
    c1_1->add(v1);
    c1_1->add(v2);
    c1_1->add(v3);
    c1_2->add(v4);
    c1->add(std::move(c1_1));
    c1->add(std::move(c1_2));

    c2_1->add(v1);
    c2_1->add(v2);
    c2_2->add(v3);
    c2_2->add(v4);
    c2->add(std::move(c2_1));
    c2->add(std::move(c2_2));
    
    EXPECT_EQ(0, uu::net::omega_index(c1.get(), c2.get(), 4));
}

TEST_F(community_eval_test, omega_index_partialmatch)
{
    // testing {{1,2} {3,4}} vs. {{1,2} {3} {4}}}
    // N=6, A_0=4, A_1=1, N_01=4, N_02=5, N_11=2, N_12=1
    // Expected: obs = (4+1)/6, exp = (4x5 + 2x1)/(6x6), OI=0.57...

    // Adding vertices to the community
    c1_1->add(v1);
    c1_1->add(v2);
    c1_2->add(v3);
    c1_2->add(v4);
    c1->add(std::move(c1_1));
    c1->add(std::move(c1_2));

    c2_1->add(v1);
    c2_1->add(v2);
    c2_2->add(v3);
    c2_3->add(v4);
    c2->add(std::move(c2_1));
    c2->add(std::move(c2_2));
    c2->add(std::move(c2_3));
    
    EXPECT_NEAR(.571, uu::net::omega_index(c1.get(), c2.get(), 4), .001);
}

TEST_F(community_eval_test, omega_index_subset)
{
    // testing {{1,2,3,4}} vs. {{1,2} {3,4}}
    // N=6, A_0=0, A_1=2, N_01=0, N_02=4, N_11=6, N_12=2
    // Expected: obs = (0+2)/6, exp = (0x4 + 6x2)/(6x6), OI=0

    // Adding vertices to the community
    c1_1->add(v1);
    c1_1->add(v2);
    c1_1->add(v3);
    c1_1->add(v4);
    c1->add(std::move(c1_1));

    c2_1->add(v1);
    c2_1->add(v2);
    c2_2->add(v3);
    c2_2->add(v4);
    c2->add(std::move(c2_1));
    c2->add(std::move(c2_2));

    EXPECT_EQ(0, uu::net::omega_index(c1.get(), c2.get(), 4));
}

