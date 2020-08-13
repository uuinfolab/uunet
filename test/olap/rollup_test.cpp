#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/rollup.hpp"


TEST_F(net_olap_operators_test, mrollup)
{

    std::vector<std::string> memb = {"ma", "mb"};
    std::vector<int> part = {0, 1, -1, 1};
    auto roll = uu::net::mrollup(vcube.get(), 1, memb, part);

    std::vector<size_t> cell000 = {0, 0, 0};
    std::vector<size_t> cell010 = {0, 1, 0};

    EXPECT_EQ((size_t)2, (*roll)[cell000]->size());
    EXPECT_EQ((size_t)3, (*roll)[cell010]->size());
    EXPECT_EQ((size_t)4, roll->vertices()->size());

    (*vcube)[cell000]->add(o6);

    EXPECT_EQ((size_t)4, roll->vertices()->size());

}

TEST_F(net_olap_operators_test, vrollup)
{

}
