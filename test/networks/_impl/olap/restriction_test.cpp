#include "gtest/gtest.h"

#include "./operators.hpp"

#include "networks/_impl/olap/restriction.hpp"


TEST_F(net_olap_operators_test, mrestrict)
{
    // v-cubes to restrict to
    std::vector<std::string> dimensions = {"d"};
    std::vector<std::vector<std::string>> members = {{"m1", "m2"}};
    std::vector<std::string> index_m1 = {"m1"};
    auto vs1 = std::make_unique<uu::net::VertexStore>();
    vs1->add(o1);
    auto vs2 = std::make_unique<uu::net::VertexStore>();
    vs2->add(o4);
    vs2->add(o6);

    auto out_cube = uu::net::mrestrict(ecube.get(), vs1.get(), vs2.get());

    std::vector<size_t> cell0 = {0};
    std::vector<size_t> cell1 = {1};

    EXPECT_EQ((size_t)2, (*out_cube)[cell0]->size());
    EXPECT_EQ((size_t)1, (*out_cube)[cell1]->size());

    auto out_cube1 = uu::net::mrestrict(ecube.get(), vs2.get(), vs1.get());

    EXPECT_EQ((size_t)0, (*out_cube1)[cell0]->size());
    EXPECT_EQ((size_t)0, (*out_cube1)[cell1]->size());
}

