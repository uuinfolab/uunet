#include "gtest/gtest.h"

#include "./operators.hpp"

#include "networks/_impl/olap/projection.hpp"


TEST_F(net_olap_operators_test, project)
{

    auto out_cube = uu::net::project(ecube.get());

    EXPECT_EQ(ecube->vcube1(), ecube->vcube1());

    std::vector<size_t> cell0 = {0};
    std::vector<size_t> cell1 = {1};

    EXPECT_EQ((size_t)3, (*out_cube)[cell0]->size());
    EXPECT_EQ((size_t)2, (*out_cube)[cell1]->size());

}

