#ifndef UU_TEST_MULTILAYERCOMMUNITYALGORITHMS_H_
#define UU_TEST_MULTILAYERCOMMUNITYALGORITHMS_H_

#include "gtest/gtest.h"

#include <memory>

#include "networks/MultilayerNetwork.hpp"
#include "community/CommunityStructure.hpp"

class multilayer_community_algorithms_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::net::MultilayerNetwork> net;
    const uu::net::Vertex *v1, *v2, *v3, *v4, *v5, *v6;
    const uu::net::Network *l1, *l2;
    
    void
    SetUp() override
    {
        
        net = std::make_unique<uu::net::MultilayerNetwork>("net");
         // Adding actors

           auto v1 = net->actors()->add("v1");
           auto v2 = net->actors()->add("v2");
           auto v3 = net->actors()->add("v3");
           auto v4 = net->actors()->add("v4");
           auto v5 = net->actors()->add("v5");
           auto v6 = net->actors()->add("v6");

           // Adding layers

           auto l1 = net->layers()->add(std::make_unique<uu::net::Network>("l1"));
           auto l2 = net->layers()->add(std::make_unique<uu::net::Network>("l2"));

           // Adding vertices to layers

            for (auto actor: *net->actors())
            {
                l1->vertices()->add(actor);
                l2->vertices()->add(actor);
            }
        
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
