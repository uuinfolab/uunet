#ifndef UU_TEST_COMMUNITY_EVAL_H_
#define UU_TEST_COMMUNITY_EVAL_H_

#include "gtest/gtest.h"

#include "community/CommunityStructure.hpp"
#include "networks/Network.hpp"


class community_eval_test : public ::testing::Test
{
  protected:
    std::unique_ptr<uu::net::Network> net;
    const uu::net::Vertex *v1, *v2, *v3, *v4;
    std::unique_ptr<uu::net::CommunityStructure<uu::net::Network>> c1, c2;
    std::unique_ptr<uu::net::Community<uu::net::Network>> c1_1, c1_2, c2_1, c2_2, c2_3;

    void
    SetUp() override
    {
        net = std::make_unique<uu::net::Network>("net");
        v1 = net->vertices()->add("v1");
        v2 = net->vertices()->add("v2");
        v3 = net->vertices()->add("v3");
        v4 = net->vertices()->add("v4");

        c1 = std::make_unique<uu::net::CommunityStructure<uu::net::Network>>();
        c1_1 = std::make_unique<uu::net::Community<uu::net::Network>>();
        c1_2 = std::make_unique<uu::net::Community<uu::net::Network>>();

        c2 = std::make_unique<uu::net::CommunityStructure<uu::net::Network>>();
        c2_1 = std::make_unique<uu::net::Community<uu::net::Network>>();
        c2_2 = std::make_unique<uu::net::Community<uu::net::Network>>();
        c2_3 = std::make_unique<uu::net::Community<uu::net::Network>>();
    }

};

#endif
