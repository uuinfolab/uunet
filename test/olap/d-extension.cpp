#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/_impl/d-extension.hpp"


TEST_F(net_olap_operators_test, extend_dimension)
{

    auto out_cube = uu::net::extend_dimension(vcube.get(), "d4", "m");

    std::vector<std::string> dim = {"d1","d2","d3","d4"};
    EXPECT_EQ(dim, out_cube->dim());
    std::vector<std::string> m_d4 = {"m"};
    EXPECT_EQ(m_d4, out_cube->members("d4"));

    std::vector<std::string> index = {"m1","m2","m1","m"};
    EXPECT_EQ((size_t)2, (*out_cube)[index]->size());
    EXPECT_TRUE((*out_cube)[index]->contains(o2.get()));
    EXPECT_TRUE((*out_cube)[index]->contains(o3.get()));
    
}
