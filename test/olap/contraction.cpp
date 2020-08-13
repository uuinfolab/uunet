#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/contraction.hpp"


TEST_F(net_olap_operators_test, contract)
{

    auto out_cube = uu::net::contract(vcube.get(), 1);

    std::vector<std::string> dim = {"d1","d3"};
    EXPECT_EQ(dim, out_cube->dim());
    std::vector<std::string> m_d1 = {"m1","m2","m3"};
    EXPECT_EQ(m_d1, out_cube->members("d1"));
    std::vector<std::string> m_d2 = {"m1","m2"};
    EXPECT_EQ(m_d2, out_cube->members("d3"));
}

