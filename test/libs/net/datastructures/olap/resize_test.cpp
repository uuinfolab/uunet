#include "gtest/gtest.h"

#include "net/datastructures/olap/VCube.hpp"
#include "net/datastructures/olap/resize.hpp"

TEST(net_datastructures_olap, resize)
{
    std::vector<std::string> dimensions = {"d1"};
    std::vector<std::vector<std::string>> members = {{"m1", "m2"}};
    auto c = uu::net::VCube("a vcube", dimensions, members);

    // Basic cube info

    resize(&c, "d1", "m3");

    EXPECT_EQ(c.members("d1").size(), (size_t)3);

    // Iterating over the containers
    /*for (auto cont: c)
    {
        std::cout << cont->size() << std::endl;
    }*/
}

