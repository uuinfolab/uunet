#ifndef UU_TEST_COMMUNITY_MLALGORITHMS_H_
#define UU_TEST_COMMUNITY_MLALGORITHMS_H_

#include "gtest/gtest.h"

#include <memory>

#include "networks/MultilayerNetwork.hpp"
#include "community/CommunityStructure.hpp"

class community_mlalgo_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::net::MultilayerNetwork> net;

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
    }

};

#endif
