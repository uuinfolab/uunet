#include "gtest/gtest.h"

#include "olap/VCube.hpp"
#include "./TestDiscretization.hpp"
#include "olap/op/d-extension.hpp"

TEST(olap_operators_test, sort)
{

    auto V = std::make_unique<uu::net::VCube>("V");
    V->add("000");
    V->add("010");
    V->add("100");
    V->add("111");
    V->add("201");
    V->add("212");

    auto d1 = uu::net::TestDiscretization<uu::net::Vertex>(0, 3);
    uu::net::extend_dimension(V.get(), "d0", {"m0", "m1", "m2"}, d1);
    
    auto d2 = uu::net::TestDiscretization<uu::net::Vertex>(1, 2);
    uu::net::extend_dimension(V.get(), "d1", {"m0", "m1"}, d2);
    
    auto d3 = uu::net::TestDiscretization<uu::net::Vertex>(2, 3);
    uu::net::extend_dimension(V.get(), "d2", {"m0", "m1", "m2"}, d3);
    
    EXPECT_EQ(V->order(), (size_t) 3);
    EXPECT_EQ(V->size(), (size_t) 6);
    
    std::vector<size_t> srt = {0, 2, 1};
    V->sort("d0", srt);
    
    EXPECT_EQ(V->order(), (size_t) 3);
    EXPECT_EQ(V->size(), (size_t) 6);
    std::vector<size_t> test1 = {3, 2, 3};
    EXPECT_EQ(V->dsize(), test1);
    std::vector<std::string> test2 = {"m0", "m2", "m1"};
    EXPECT_EQ(V->members("d0"), test2);
    
    auto idx101 = std::vector<std::string>({"m1", "m0", "m1"});
    auto idx100 = std::vector<std::string>({"m1", "m0", "m0"});
    EXPECT_EQ(V->cell(idx101)->size(), (size_t) 0);
    EXPECT_EQ(V->cell(idx100)->size(), (size_t) 1);
    
    
}
