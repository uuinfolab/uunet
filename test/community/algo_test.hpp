#ifndef UU_TEST_COMMUNITY_ALGORITHMS_H_
#define UU_TEST_COMMUNITY_ALGORITHMS_H_

#include "gtest/gtest.h"

#include <memory>

#include "networks/Network.hpp"
#include "community/CommunityStructure.hpp"

class community_algo_test : public ::testing::Test
{
  protected:

    // Input network for the tests
    // Contains two "clear" communities
    std::unique_ptr<uu::net::Network> net;

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

        //net->edges()->add(v1, v4);

    }

};

#endif
