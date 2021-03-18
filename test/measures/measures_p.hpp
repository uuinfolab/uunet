#ifndef UU_TEST_MEASURES_P_H_
#define UU_TEST_MEASURES_P_H_

#include "gtest/gtest.h"

#include "networks/Network.hpp"
#include "networks/probability.hpp"

class net_measures_p_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::net::Network> g;
    const uu::net::Vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7, *v8, *v9;
    const uu::net::Edge *e1, *e2, *e3, *e4, *e5, *e6, *e7, *e8;

    void
    SetUp() override
    {

        g = std::make_unique<uu::net::Network>("net");

        v1 = g->vertices()->add("v1");
        v2 = g->vertices()->add("v2");
        v3 = g->vertices()->add("v3");
        v4 = g->vertices()->add("v4");
        v5 = g->vertices()->add("v5");
        v6 = g->vertices()->add("v6");
        v7 = g->vertices()->add("v7");
        v8 = g->vertices()->add("v8");
        v9 = g->vertices()->add("v9");

        e1 = g->edges()->add(v2, v4);
        e2 = g->edges()->add(v3, v4);
        e3 = g->edges()->add(v4, v5);
        e4 = g->edges()->add(v4, v6);
        e5 = g->edges()->add(v5, v7);
        e6 = g->edges()->add(v6, v7);
        e7 = g->edges()->add(v8, v9);

        uu::net::make_probabilistic(g.get());
        uu::net::set_prob(g.get(), e1, .7);
        uu::net::set_prob(g.get(), e2, .3);
        uu::net::set_prob(g.get(), e3, .3);
        uu::net::set_prob(g.get(), e4, .6);
        uu::net::set_prob(g.get(), e5, .2);
        uu::net::set_prob(g.get(), e6, .7);
        uu::net::set_prob(g.get(), e7, .9);
        
    }


};

#endif
