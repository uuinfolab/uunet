#include "gtest/gtest.h"

#include "stores.hpp"
#include "net/datastructures/olap/ECube.hpp"

TEST_F(net_datastructures_stores, ECube)
{
    std::vector<std::string> dimensions = {"d1"};
    std::vector<std::vector<std::string>> members = {{"m1", "m2"}};

    auto vc1 = std::make_unique<uu::net::VCube>("a vcube", dimensions, members);
    auto vc2 = std::make_unique<uu::net::VCube>("a vcube", dimensions, members);
    
    uu::net::ECube c("an ecube", vc1.get(), vc2.get(), uu::net::EdgeDir::DIRECTED, dimensions, members);

    // Basic cube info
    
    EXPECT_EQ(c.order(), (size_t)1)
    << "Wrong order (number of dimensions)";
    
    EXPECT_EQ(c.dim().size(), (size_t)1)
    << "Wrong number of dimensions";
    
    EXPECT_EQ(c.dim().at(0), "d1")
    << "Wrong dimension name";
    
    EXPECT_EQ(c.members("d1").size(), (size_t)2)
    << "Wrong number of members for dimension d1";
    
    EXPECT_EQ(c.members("d1").at(0), "m1")
    << "Wrong member name";
    
    std::vector<std::string> index_m1 = {"m1"};
    std::vector<std::string> index_m2 = {"m2"};
    
    // populating the VCubes
    
    vc1->at(index_m1)->add(v1);
    vc1->at(index_m1)->add(v2);
    vc2->at(index_m1)->add(v1);
    vc2->at(index_m1)->add(v2);
    
    c[index_m1]->add(v1.get(),vc1.get(),v2.get(),vc2.get());
    c.at(index_m1)->add(v1.get(),vc2.get(),v2.get(),vc1.get());

    EXPECT_EQ(c[index_m1]->size(), (size_t)2)
    << "Wrong size for first cell";
    EXPECT_EQ(c[index_m2]->size(), (size_t)0)
    << "Wrong size for second cell";

    EXPECT_EQ(c.size(), (size_t)2);
    
    // Iterating over the containers
    /*for (auto cont: c)
    {
        std::cout << cont->size() << std::endl;
    }*/
}

