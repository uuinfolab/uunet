#ifndef UU_TEST_CORE_OLAP_OPERATIONS_H_
#define UU_TEST_CORE_OLAP_OPERATIONS_H_

#include "gtest/gtest.h"

#include "networks/_impl/olap/VCube.hpp"
#include "networks/_impl/olap/ECube.hpp"

class net_olap_operators_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::net::VCube> vcube;
    std::unique_ptr<uu::net::VertexStore> vs1, vs2;
    std::unique_ptr<uu::net::ECube> ecube;
    std::shared_ptr<const uu::net::Vertex> o1, o2, o3, o4, o5, o6;

    virtual void
    SetUp()
    {

        o1 = std::make_shared<const uu::net::Vertex>("1");
        o2 = std::make_shared<const uu::net::Vertex>("2");
        o3 = std::make_shared<const uu::net::Vertex>("3");
        o4 = std::make_shared<const uu::net::Vertex>("4");
        o5 = std::make_shared<const uu::net::Vertex>("5");
        o6 = std::make_shared<const uu::net::Vertex>("6");


        std::vector<std::string> dimensions = {"d1", "d2", "d3"};
        std::vector<std::vector<std::string>> members = {{"m1","m2","m3"}, {"m1","m2","m3","m4"}, {"m1","m2"}};


        vcube = std::make_unique<uu::net::VCube>(dimensions, members);
        vcube->init();

        std::vector<std::string> index1 = {"m1","m1","m1"};
        (*vcube)[index1]->add(o1);
        (*vcube)[index1]->add(o2);
        std::vector<std::string> index2 = {"m2","m2","m2"};
        (*vcube)[index2]->add(o1);
        (*vcube)[index2]->add(o3);
        (*vcube)[index2]->add(o4);
        std::vector<std::string> index3 = {"m2","m1","m1"};
        (*vcube)[index3]->add(o2);
        (*vcube)[index3]->add(o3);
        std::vector<std::string> index4 = {"m1","m2","m1"};
        (*vcube)[index4]->add(o2);
        (*vcube)[index4]->add(o3);
        std::vector<std::string> index5 = {"m1","m3","m1"};
        (*vcube)[index5]->add(o2);
        (*vcube)[index5]->add(o5);
        std::vector<std::string> index6 = {"m1","m4","m1"};
        (*vcube)[index6]->add(o2);
        (*vcube)[index6]->add(o4);


        std::vector<std::string> dimensions2 = {"d1"};
        std::vector<std::vector<std::string>> members2 = {{"m1","m2"}};
        std::vector<std::string> idx1 = {"m1"};
        std::vector<std::string> idx2 = {"m2"};

        vs1 = std::make_unique<uu::net::VertexStore>();
        vs1->add(o1);
        vs1->add(o2);
        vs1->add(o3);
        vs2 = std::make_unique<uu::net::VertexStore>();
        vs2->add(o4);
        vs2->add(o5);
        vs2->add(o6);

        ecube = std::make_unique<uu::net::ECube>(vs1.get(), vs2.get(), uu::net::EdgeDir::UNDIRECTED, dimensions2, members2);
        ecube->init();
        (*ecube)[idx1]->add(o1.get(), vs1.get(), o4.get(), vs2.get());
        (*ecube)[idx1]->add(o1.get(), vs1.get(), o5.get(), vs2.get());
        (*ecube)[idx1]->add(o1.get(), vs1.get(), o6.get(), vs2.get());
        (*ecube)[idx2]->add(o1.get(), vs1.get(), o4.get(), vs2.get());
        (*ecube)[idx2]->add(o1.get(), vs1.get(), o5.get(), vs2.get());
        (*ecube)[idx2]->add(o2.get(), vs1.get(), o5.get(), vs2.get());
        (*ecube)[idx2]->add(o2.get(), vs1.get(), o6.get(), vs2.get());




    }
};

#endif
