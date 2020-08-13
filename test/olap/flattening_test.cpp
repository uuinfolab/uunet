#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/flattening.hpp"


TEST_F(net_olap_operators_test, flatten)
{

    
    // we already have two vertices in {"m1","m1","m1"}. We add two to {"m1","m1","m2"}.
    std::vector<std::string> index1 = {"m1","m1","m2"};
    (*vcube)[index1]->add(o3);
    (*vcube)[index1]->add(o4);
    
    std::set<size_t> to_flatten1 = {0, 1};
    auto out_cube1 = uu::net::flatten(vcube.get(), 2, "m", to_flatten1);

    std::vector<std::string> dim = {"d1","d2","d3"};
    EXPECT_EQ(dim, out_cube1->dim());
    std::vector<std::string> m_d3 = {"m1","m2","m"};
    EXPECT_EQ(m_d3, out_cube1->members("d3"));

    std::vector<std::string> index = {"m1","m1","m"};
    EXPECT_EQ((size_t)4, (*out_cube1)[index]->size());
    EXPECT_TRUE((*out_cube1)[index]->contains(o1.get()));
    EXPECT_TRUE((*out_cube1)[index]->contains(o2.get()));
    EXPECT_TRUE((*out_cube1)[index]->contains(o3.get()));
    EXPECT_TRUE((*out_cube1)[index]->contains(o4.get()));
    
    std::set<size_t> to_flatten2 = {1};
    auto out_cube2 = uu::net::flatten(vcube.get(), 2, "m", to_flatten2);
    
    EXPECT_EQ(dim, out_cube2->dim());
    EXPECT_EQ(m_d3, out_cube2->members("d3"));
    
    EXPECT_EQ((size_t)2, (*out_cube2)[index]->size());
    EXPECT_TRUE((*out_cube2)[index]->contains(o3.get()));
    EXPECT_TRUE((*out_cube2)[index]->contains(o4.get()));
    
}
