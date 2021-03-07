#ifndef UU_TEST_MEASURES_H_
#define UU_TEST_MEASURES_H_

#include "gtest/gtest.h"

#include "networks/MultilayerNetwork.hpp"

class net_measures_ml_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::net::MultilayerNetwork> net;
    const uu::net::Vertex *v1, *v2, *v3, *v4, *v5, *v6;
    uu::net::Network *l1, *l2;
    //const uu::net::Edge *e1, *e2, *e3, *e4, *e5, *e6, *e7, *e8;

    void
    SetUp() override
    {
       // auto und = uu::net::EdgeDir::UNDIRECTED;
        net = std::make_unique<uu::net::MultilayerNetwork>("net");
        l1 = net->layers()->add("l1");
        l2 = net->layers()->add("l2");
        
        v1 = l1->vertices()->add("v1");
        v2 = l1->vertices()->add("v2");
        v3 = l1->vertices()->add("v3");
        v4 = l1->vertices()->add("v4");
        v5 = l1->vertices()->add("v5");
        l2->vertices()->add(v1);
        l2->vertices()->add(v2);
        l2->vertices()->add(v3);
        l2->vertices()->add(v4);
        v6 = l2->vertices()->add("v6");

        l1->edges()->add(v1, v2);
        l1->edges()->add(v1, v5);
        l1->edges()->add(v2, v3);
        l1->edges()->add(v2, v4);
        l1->edges()->add(v2, v5);
        l1->edges()->add(v3, v4);
        l2->edges()->add(v1, v4);
        l2->edges()->add(v2, v3);
        l2->edges()->add(v2, v4);
        l2->edges()->add(v3, v4);
    }


};

#endif
