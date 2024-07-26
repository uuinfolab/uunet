#ifndef UU_TEST_COMMUNITY_ALGORITHMS_H_
#define UU_TEST_COMMUNITY_ALGORITHMS_H_

#include "gtest/gtest.h"

#include <memory>

#include "networks/Network.hpp"
#include "community/CommunityStructure.hpp"
#include "networks/weight.hpp"

class community_algo_test : public ::testing::Test
{
  protected:

    // Input network for the tests
    // Contains two "clear" communities
    std::unique_ptr<uu::net::Network> net, wnet;

    void
    SetUp() override
    {

        net = std::make_unique<uu::net::Network>("net");

        // Adding vertices

        auto v1 = net->vertices()->add("v1");
        auto v2 = net->vertices()->add("v2");
        auto v3 = net->vertices()->add("v3");
        auto v4 = net->vertices()->add("v4");
        auto v5 = net->vertices()->add("v5");
        auto v6 = net->vertices()->add("v6");

        // Adding edges

        net->edges()->add(v1, v2);
        net->edges()->add(v1, v3);
        net->edges()->add(v2, v3);
        net->edges()->add(v4, v5);
        net->edges()->add(v4, v6);
        net->edges()->add(v5, v6);

        net->edges()->add(v1, v4);

        wnet = std::make_unique<uu::net::Network>("net");

        // Adding vertices

        auto wv1 = wnet->vertices()->add("v1");
        auto wv2 = wnet->vertices()->add("v2");
        auto wv3 = wnet->vertices()->add("v3");
        auto wv4 = wnet->vertices()->add("v4");
        auto wv5 = wnet->vertices()->add("v5");
        auto wv6 = wnet->vertices()->add("v6");

        // Adding edges

        auto we1 = wnet->edges()->add(wv1, wv2);
        auto we2 = wnet->edges()->add(wv1, wv3);
        auto we3 = wnet->edges()->add(wv2, wv3);
        auto we4 = wnet->edges()->add(wv4, wv5);
        auto we5 = wnet->edges()->add(wv4, wv6);
        auto we6 = wnet->edges()->add(wv5, wv6);
        
        auto we7 = wnet->edges()->add(wv1, wv4);

        auto wnetp = wnet.get();
        uu::net::make_weighted(wnetp);
        uu::net::set_weight(wnetp,we1,.1);
        uu::net::set_weight(wnetp,we2,.1);
        uu::net::set_weight(wnetp,we3,.1);
        uu::net::set_weight(wnetp,we4,.1);
        uu::net::set_weight(wnetp,we5,.1);
        uu::net::set_weight(wnetp,we6,.1);
        uu::net::set_weight(wnetp,we7,1.0);
    }

};

#endif
