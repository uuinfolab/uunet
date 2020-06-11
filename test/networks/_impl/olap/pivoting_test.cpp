#include "gtest/gtest.h"

#include "./operators.hpp"

#include "networks/_impl/olap/pivoting.hpp"


TEST_F(net_olap_operators_test, vpivot)
{

    std::vector<size_t> perm = {1, 2, 0};
    auto out_cube = uu::net::vpivot(vcube.get(), perm);


    // We modify the original cube to check that the new cube is also updated

    std::vector<size_t> cell100 = {1, 0, 0};
    (*vcube)[cell100]->add(o6);

    // Cell [0, 0, 1] in the output cube should correspond to cell [1, 0, 0] in the input cube.

    std::vector<size_t> cell001 = {0, 0, 1};
    EXPECT_EQ((size_t)3, (*out_cube)[cell001]->size());
    EXPECT_TRUE((*out_cube)[cell001]->contains(o2.get()));
    EXPECT_TRUE((*out_cube)[cell001]->contains(o3.get()));
    EXPECT_TRUE((*out_cube)[cell001]->contains(o6.get()));

    // Cell [3, 0, 0] in the output cube should correspond to cell [0, 3, 0] in the input cube.

    std::vector<size_t> cell300 = {3, 0, 0};
    EXPECT_EQ((size_t)2, (*out_cube)[cell300]->size());
    EXPECT_TRUE((*out_cube)[cell300]->contains(o2.get()));
    EXPECT_TRUE((*out_cube)[cell300]->contains(o4.get()));

}

TEST_F(net_olap_operators_test, mpivot)
{

    std::vector<size_t> perm = {1, 2, 0};
    auto out_cube = uu::net::mpivot(vcube.get(), perm);

    // We modify the original cube to check that the new cube is not affected

    std::vector<size_t> cell100 = {1, 0, 0};
    (*vcube)[cell100]->add(o6);

    // Cell [0, 0, 1] in the output cube should correspond to cell [1, 0, 0] in the input cube.

    std::vector<size_t> cell001 = {0, 0, 1};
    EXPECT_EQ((size_t)2, (*out_cube)[cell001]->size());
    EXPECT_TRUE((*out_cube)[cell001]->contains(o2.get()));
    EXPECT_TRUE((*out_cube)[cell001]->contains(o3.get()));

    // Cell [3, 0, 0] in the output cube should correspond to cell [0, 3, 0] in the input cube.

    std::vector<size_t> cell300 = {3, 0, 0};
    EXPECT_EQ((size_t)2, (*out_cube)[cell300]->size());
    EXPECT_TRUE((*out_cube)[cell300]->contains(o2.get()));
    EXPECT_TRUE((*out_cube)[cell300]->contains(o4.get()));
}
