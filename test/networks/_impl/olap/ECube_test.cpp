#include "gtest/gtest.h"

#include "stores.hpp"
#include "networks/_impl/olap/ECube.hpp"

TEST_F(net_datastructures_stores, ECube)
{
    std::vector<std::string> dimensions = {"d"};
    std::vector<std::vector<std::string>> members = {{"m1", "m2"}};
    std::vector<std::string> index_m1 = {"m1"};
    std::vector<std::string> index_m2 = {"m2"};

    auto vc1 = std::make_unique<uu::net::VertexStore>();
    vc1->add(v1);
    vc1->add(v2);
    auto vc2 = std::make_unique<uu::net::VertexStore>();
    vc2->add(v1);
    vc2->add(v2);

    uu::net::ECube ecube(vc1.get(), vc2.get(), uu::net::EdgeDir::DIRECTED, dimensions, members);
    ecube.init();

    // Basic cube info

    EXPECT_EQ(ecube.order(), (size_t)1);

    EXPECT_EQ(ecube.dim().size(), (size_t)1);

    EXPECT_EQ(ecube.dim().at(0), "d");

    EXPECT_EQ(ecube.members("d").size(), (size_t)2);

    EXPECT_EQ(ecube.members("d").at(0), "m1");
    EXPECT_EQ(ecube.members("d").at(1), "m2");

    ecube[index_m1]->add(v1.get(),vc1.get(),v2.get(),vc2.get());
    ecube.at(index_m1)->add(v1.get(),vc2.get(),v2.get(),vc1.get());

    EXPECT_EQ(ecube[index_m1]->size(), (size_t)2);
    EXPECT_EQ(ecube[index_m2]->size(), (size_t)0);

    EXPECT_EQ(ecube.edges()->size(), (size_t)2);

}

