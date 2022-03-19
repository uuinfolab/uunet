#include "gtest/gtest.h"

#include "networks/MultilayerNetwork.hpp"
#include "networks/weight.hpp"
#include "operations/flatten.hpp"

TEST(operations_test, flatten)
{

    // creating a simple multilayer network

    auto net = std::make_unique<uu::net::MultilayerNetwork>("net");
    auto l1 = net->layers()->add("l1");
    auto l2 = net->layers()->add("l2");
    
    auto v1 = l1->vertices()->add("v1");
    auto v2 = l1->vertices()->add("v2");
    auto v3 = l1->vertices()->add("v3");
    l2->vertices()->add(v1);
    l2->vertices()->add(v2);
    l2->vertices()->add(v3);
    
    l1->edges()->add(v1,v2);
    l1->edges()->add(v2,v3);
    l2->edges()->add(v2,v3);
    
    auto l = {l1, l2};
    auto lf1 = net->layers()->add("flat");
    uu::net::flatten_unweighted(l.begin(), l.end(), lf1);
    
    EXPECT_TRUE(lf1->edges()->contains(v1, v2));
    EXPECT_TRUE(lf1->edges()->contains(v2, v3));
    EXPECT_FALSE(lf1->edges()->contains(v1, v3));
    
    auto lf2 = net->layers()->add("w_flat");
    uu::net::make_weighted(lf2);
    uu::net::flatten_weighted(l.begin(), l.end(), lf2);
    
    EXPECT_TRUE(lf2->edges()->contains(v1, v2));
    EXPECT_TRUE(lf2->edges()->contains(v2, v3));
    EXPECT_FALSE(lf2->edges()->contains(v1, v3));
    auto e1 = lf2->edges()->get(v1, v2);
    auto e2 = lf2->edges()->get(v2, v3);
    EXPECT_EQ(uu::net::get_weight(lf2, e1), 1.0);
    EXPECT_EQ(uu::net::get_weight(lf2, e2), 2.0);
    
}
