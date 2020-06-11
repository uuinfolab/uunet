#include "gtest/gtest.h"

#include "./operators.hpp"

#include "networks/_impl/olap/slice.hpp"


TEST_F(net_olap_operators_test, vslice)
{

    std::vector<std::vector<size_t>> s1 = {{1}, {0,1}, {0,1}};
    auto slice1 = uu::net::vslice(vcube.get(), s1);

    std::vector<size_t> cell011 = {0, 1, 1};
    EXPECT_EQ((size_t)3, (*slice1)[cell011]->size());
    EXPECT_EQ((size_t)4, slice1->vertices()->size());

    std::vector<size_t> cell111 = {1, 1, 1};
    (*vcube)[cell111]->add(o6);

    EXPECT_EQ((size_t)4, (*slice1)[cell011]->size());
    EXPECT_EQ((size_t)5, slice1->vertices()->size());

}

TEST_F(net_olap_operators_test, mslice)
{

    std::vector<std::vector<size_t>> s1 = {{1}, {0,1}, {0,1}};
    auto slice1 = uu::net::mslice(vcube.get(), s1);

    std::vector<size_t> cell011 = {0, 1, 1};
    EXPECT_EQ((size_t)3, (*slice1)[cell011]->size());
    EXPECT_EQ((size_t)4, slice1->vertices()->size());

    std::vector<size_t> cell111 = {1, 1, 1};
    (*vcube)[cell111]->add(o6);

    EXPECT_EQ((size_t)3, (*slice1)[cell011]->size());
    EXPECT_EQ((size_t)4, slice1->vertices()->size());

}
