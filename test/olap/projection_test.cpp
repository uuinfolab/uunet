#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/edge-projection.hpp"


TEST_F(net_olap_operators_test, project)
{

    auto out_cube = uu::net::project(ecube.get());

    EXPECT_EQ(out_cube->vcube1(), out_cube->vcube2());

    std::vector<size_t> cell0 = {0};
    std::vector<size_t> cell1 = {1};

    EXPECT_EQ((size_t)3, (*out_cube)[cell0]->size());
    EXPECT_EQ((size_t)2, (*out_cube)[cell1]->size());

}

