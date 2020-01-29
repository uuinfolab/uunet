#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "creation/erdos_renyi.hpp"
#include "networks/Network.hpp"

TEST(net_creation_test, erdos_renyi_nm)
{

    auto n = std::make_unique<uu::net::Network>("Net");
    uu::net::erdos_renyi_nm(n.get(), 10, 4);

    ASSERT_EQ(size_t(10), n->vertices()->size());
    ASSERT_EQ(size_t(4), n->edges()->size());

}


TEST(net_creation_test, erdos_renyi_np)
{

    auto n = std::make_unique<uu::net::Network>("Net");
    uu::net::erdos_renyi_np(n.get(), 10, .2);
    
    ASSERT_EQ(size_t(10), n->vertices()->size());
    
    // unknown number of edges, cannot be tested
    // std::cout << n->edges()->size() << std::endl;
    
}

