#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/_impl/m-contraction.hpp"


TEST_F(net_olap_operators_test, contract_members)
{

    auto out_cube = uu::net::contract_members(vcube.get());

    std::vector<std::string> dim = {"d1","d2","d3"};
    EXPECT_EQ(dim, out_cube->dim());
    std::vector<std::string> m_d1 = {"m1","m2","m3"};
    EXPECT_EQ(m_d1, out_cube->members("d1"));
    std::vector<std::string> m_d2 = {"m1","m2","m3","m4"};
    EXPECT_EQ(m_d2, out_cube->members("d2"));
    std::vector<std::string> m_d3 = {"m1"};
    EXPECT_EQ(m_d3, out_cube->members("d3"));
}

