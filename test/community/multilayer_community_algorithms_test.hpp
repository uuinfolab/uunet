#ifndef UU_TEST_MULTILAYERCOMMUNITYALGORITHMS_H_
#define UU_TEST_MULTILAYERCOMMUNITYALGORITHMS_H_

#include "gtest/gtest.h"

#include <memory>

#include "networks/MultilayerNetwork2.hpp"
#include "community/CommunityStructure.hpp"

class multilayer_community_algorithms_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::net::MultilayerNetwork2> net;
    //const uu::net::Vertex *v1, *v2, *v3, *v4, *v5, *v6;
    //const uu::net::Network2 *l1, *l2;
    
    void
    SetUp() override
    {
        
        net = std::make_unique<uu::net::MultilayerNetwork2>("net");
         // Adding actors

           // Adding layers

           auto l1 = net->layers()->add("l1");
           auto l2 = net->layers()->add("l2");

           // Adding vertices to layers
        
        auto v1 = l1->vertices()->add("v1");
        auto v2 = l1->vertices()->add("v2");
        auto v3 = l1->vertices()->add("v3");
        auto v4 = l1->vertices()->add("v4");
        auto v5 = l1->vertices()->add("v5");
        auto v6 = l1->vertices()->add("v6");
        
        l2->vertices()->add(v1);
        l2->vertices()->add(v2);
        l2->vertices()->add(v3);
        l2->vertices()->add(v4);
        l2->vertices()->add(v5);
        l2->vertices()->add(v6);
        
        // Adding edges
        
           l1->edges()->add(v1, v2);
           l1->edges()->add(v1, v3);
           l1->edges()->add(v2, v3);
           l1->edges()->add(v4, v5);
           l1->edges()->add(v4, v6);
           l1->edges()->add(v5, v6);
        
        l1->edges()->add(v1, v4);
        
           l2->edges()->add(v1, v2);
           l2->edges()->add(v1, v3);
           l2->edges()->add(v2, v3);
           l2->edges()->add(v4, v5);
           l2->edges()->add(v4, v6);
           l2->edges()->add(v5, v6);
        
        l2->edges()->add(v1, v5);
    }

    /*
     void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }
     */

};

#endif
