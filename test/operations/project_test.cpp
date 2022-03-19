#include "gtest/gtest.h"

#include "networks/MultilayerNetwork.hpp"
#include "operations/project.hpp"

TEST(operations_test, project)
{

    // creating a simple multilayer network

    auto net = std::make_unique<uu::net::MultilayerNetwork>("net");
    auto l1 = net->layers()->add("l1");
    auto l2 = net->layers()->add("l2");
    
    auto v1 = l1->vertices()->add("v1");
    auto v2 = l1->vertices()->add("v2");
    auto v3 = l1->vertices()->add("v3");
    
    auto o1 = l2->vertices()->add("o1");
    auto o2 = l2->vertices()->add("o2");
    
    net->interlayer_edges()->init(l1, l2);
    net->interlayer_edges()->add(v1, l1, o1, l2);
    net->interlayer_edges()->add(v2, l1, o1, l2);
    net->interlayer_edges()->add(v2, l1, o2, l2);
    net->interlayer_edges()->add(v3, l1, o2, l2);
    
    auto lf = net->layers()->add("flat");
    uu::net::project_unweighted(net.get(), l2, l1, lf);
    

    EXPECT_TRUE(lf->edges()->contains(v1, v2));
    EXPECT_TRUE(lf->edges()->contains(v2, v3));
    EXPECT_FALSE(lf->edges()->contains(v1, v3));
    
}
