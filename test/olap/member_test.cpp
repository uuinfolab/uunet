#include "gtest/gtest.h"

#include "olap/VCube.hpp"
#include "./TestDiscretization.hpp"
#include "olap/op/d-extension.hpp"

TEST(olap_operators_test, erase_member)
{

    auto V = std::make_unique<uu::net::VCube>("V");
    V->add("00");
    V->add("01");
    V->add("02");
    V->add("10");
    V->add("11");
    V->add("12");
    V->add("20");
    V->add("21");
    V->add("22");

    auto d1 = uu::net::TestDiscretization<uu::net::Vertex>(0, 3);
    uu::net::extend_dimension(V.get(), "d0", {"m0", "m1", "m2"}, d1);
    
    auto d2 = uu::net::TestDiscretization<uu::net::Vertex>(1, 3);
    uu::net::extend_dimension(V.get(), "d1", {"m0", "m1", "m2"}, d2);
    
    EXPECT_EQ(V->order(), (size_t) 2);
    EXPECT_EQ(V->size(), (size_t) 9);
    
    V->erase_member("d1");
    
    EXPECT_EQ(V->order(), (size_t) 2);
    EXPECT_EQ(V->size(), (size_t) 6);
    std::vector<std::string> test = {"m0", "m1"};
    EXPECT_EQ(V->members("d1"), test);
    
    V->erase_member("d0");
    
    EXPECT_EQ(V->order(), (size_t) 2);
    EXPECT_EQ(V->size(), (size_t) 4);
    EXPECT_EQ(V->members("d0"), test);
    
    auto idx00 = std::vector<std::string>({"m0", "m0"});
    auto idx01 = std::vector<std::string>({"m0", "m1"});
    EXPECT_EQ(V->cell(idx00)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(idx01)->size(), (size_t) 1);
    
    V->erase_member("d0");
    V->erase_member("d1");
    
    
    
}
