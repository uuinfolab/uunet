#include "gtest/gtest.h"

#include "stores.hpp"
#include "olap/VCube.hpp"

TEST_F(net_datastructures_stores, VCube)
{

    // A vertex-cube with one dimension with two members
    std::vector<std::string> dimensions = {"d"};
    std::vector<std::vector<std::string>> members = {{"m1","m2"}};

    auto vcube = uu::net::VCube(dimensions, members);
    vcube.init();

    // Basic cube info

    EXPECT_EQ(vcube.order(), (size_t)1);

    EXPECT_EQ(vcube.dim().size(), (size_t)1);

    EXPECT_EQ(vcube.dim().at(0), "d");

    EXPECT_EQ(vcube.members("d").size(), (size_t)2)
            << "Wrong number of members for dimension d1";

    EXPECT_EQ(vcube.members("d").at(0), "m1");
    EXPECT_EQ(vcube.members("d").at(1), "m2");

    std::vector<std::string> index_m1 = {"m1"};
    std::vector<std::string> index_m2 = {"m2"};
    auto v1 = vcube[index_m1]->add("a vertex");
    vcube.at(index_m1)->add("another vertex");
    vcube[index_m2]->add(v1);

    EXPECT_EQ(vcube[index_m1]->size(), (size_t)2)
            << "Wrong size for first cell";
    EXPECT_EQ(vcube[index_m2]->size(), (size_t)1)
            << "Wrong size for second cell";

    EXPECT_EQ(vcube.vertices()->size(), (size_t)2);

}

