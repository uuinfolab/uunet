#ifndef UU_TEST_CORE_OLAP_OPERATIONS_H_
#define UU_TEST_CORE_OLAP_OPERATIONS_H_

#include "gtest/gtest.h"

#include "olap/VCube.hpp"
#include "olap/ECube.hpp"

class olap_operators_slice_test : public ::testing::Test
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


        vcube = std::make_unique<uu::net::VCube>("V");

        for (size_t i = 0; i < 3; i++)
        {
            vcube->add_dimension(dimensions[i], members[i]);
        }

        //vcube->init();

        std::vector<std::string> index1 = {"m1","m1","m1"};
        vcube->cell(index1)->add(o1);
        vcube->cell(index1)->add(o2);
        std::vector<std::string> index2 = {"m2","m2","m2"};
        vcube->cell(index2)->add(o1);
        vcube->cell(index2)->add(o3);
        vcube->cell(index2)->add(o4);
        std::vector<std::string> index3 = {"m2","m1","m1"};
        vcube->cell(index3)->add(o2);
        vcube->cell(index3)->add(o3);
        std::vector<std::string> index4 = {"m1","m2","m1"};
        vcube->cell(index4)->add(o2);
        vcube->cell(index4)->add(o3);
        std::vector<std::string> index5 = {"m1","m3","m1"};
        vcube->cell(index5)->add(o2);
        vcube->cell(index5)->add(o5);
        std::vector<std::string> index6 = {"m1","m4","m1"};
        vcube->cell(index6)->add(o2);
        vcube->cell(index6)->add(o4);


        /*
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
        ecube->cell(idx1)->add(o1.get(), vs1.get(), o4.get(), vs2.get());
        ecube->cell(idx1)->add(o1.get(), vs1.get(), o5.get(), vs2.get());
        ecube->cell(idx1)->add(o1.get(), vs1.get(), o6.get(), vs2.get());
        ecube->cell(idx2)->add(o1.get(), vs1.get(), o4.get(), vs2.get());
        ecube->cell(idx2)->add(o1.get(), vs1.get(), o5.get(), vs2.get());
        ecube->cell(idx2)->add(o2.get(), vs1.get(), o5.get(), vs2.get());
        ecube->cell(idx2)->add(o2.get(), vs1.get(), o6.get(), vs2.get());

        */


    }
};

#endif
