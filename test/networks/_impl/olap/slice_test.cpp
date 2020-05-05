#include "gtest/gtest.h"

#include "networks/_impl/olap/VCube.hpp"
#include "networks/_impl/olap/slice.hpp"

TEST(net_datastructures_olap, slice)
{
    std::vector<std::string> dimensions = {"d1"};
    std::vector<std::vector<std::string>> members = {{"m1", "m2"}};
    auto c = uu::net::VCube("a vcube", dimensions, members);

    // Basic cube info

    std::vector<std::vector<size_t>> idx = {{1}};


    auto c2 = vslice(&c, idx, "slice");

    EXPECT_EQ(c2->members("d1").size(), (size_t)1);


    // Iterating over the containers
    /*
    for (auto cont: c)
    {
        std::cout << cont->size() << std::endl;
    }*/
}

