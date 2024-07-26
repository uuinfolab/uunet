#ifndef UU_TEST_COMMUNITY_MLALGORITHMS_H_
#define UU_TEST_COMMUNITY_MLALGORITHMS_H_

#include "gtest/gtest.h"

#include <memory>

#include "networks/MultilayerNetwork.hpp"
#include "community/CommunityStructure.hpp"
#include "networks/weight.hpp"

class community_mlalgo_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::net::MultilayerNetwork> net, wnet;

    void
    SetUp() override
    {

        net = std::make_unique<uu::net::MultilayerNetwork>("net");

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
        
        
        wnet = std::make_unique<uu::net::MultilayerNetwork>("wnet");

        // Adding layers

        auto wl1 = wnet->layers()->add("l1");
        auto wl2 = wnet->layers()->add("l2");

        // Adding vertices to layers

        auto wv1 = wl1->vertices()->add("v1");
        auto wv2 = wl1->vertices()->add("v2");
        auto wv3 = wl1->vertices()->add("v3");
        auto wv4 = wl1->vertices()->add("v4");
        auto wv5 = wl1->vertices()->add("v5");
        auto wv6 = wl1->vertices()->add("v6");

        wl2->vertices()->add(wv1);
        wl2->vertices()->add(wv2);
        wl2->vertices()->add(wv3);
        wl2->vertices()->add(wv4);
        wl2->vertices()->add(wv5);
        wl2->vertices()->add(wv6);

        // Adding edges

        auto we11 = wl1->edges()->add(wv1, wv2);
        auto we12 = wl1->edges()->add(wv1, wv3);
        auto we13 = wl1->edges()->add(wv2, wv3);
        auto we14 = wl1->edges()->add(wv4, wv5);
        auto we15 = wl1->edges()->add(wv4, wv6);
        auto we16 = wl1->edges()->add(wv5, wv6);

        auto we17 = wl1->edges()->add(wv1, wv4);

        auto we21 = wl2->edges()->add(wv1, wv2);
        auto we22 = wl2->edges()->add(wv1, wv3);
        auto we23 = wl2->edges()->add(wv2, wv3);
        auto we24 = wl2->edges()->add(wv4, wv5);
        auto we25 = wl2->edges()->add(wv4, wv6);
        auto we26 = wl2->edges()->add(wv5, wv6);

        auto we27 = wl2->edges()->add(wv1, wv5);
        
        // Setting weights edges
        uu::net::make_weighted(wl1);
        uu::net::make_weighted(wl2);
        uu::net::set_weight(wl1, we11, .1);
        uu::net::set_weight(wl1, we12, .1);
        uu::net::set_weight(wl1, we13, .1);
        uu::net::set_weight(wl1, we14, .1);
        uu::net::set_weight(wl1, we15, .1);
        uu::net::set_weight(wl1, we16, .1);
        uu::net::set_weight(wl1, we17, 1);
        uu::net::set_weight(wl2, we21, .1);
        uu::net::set_weight(wl2, we22, .1);
        uu::net::set_weight(wl2, we23, .1);
        uu::net::set_weight(wl2, we24, .1);
        uu::net::set_weight(wl2, we25, .1);
        uu::net::set_weight(wl2, we26, .1);
        uu::net::set_weight(wl2, we27, 1);
        
    }

};

#endif
