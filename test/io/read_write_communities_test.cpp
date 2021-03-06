#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_multilayer_communities.hpp"
#include "io/write_multilayer_communities.hpp"
#include "networks/MultilayerNetwork.hpp"

TEST(io_communities_test, multilayer)
{
    typedef uu::net::MultilayerNetwork M;

    std::string test_file_name = "net_io_read_graph_file.tmp";


    auto g = std::make_unique<M>("g");
    auto l1_ptr = g->layers()->add("l1");
    auto l2_ptr = g->layers()->add("l2");
    auto a1 = g->actors()->add("a1");
    auto a2 = g->actors()->add("a2");
    //auto l1 = std::make_unique<uu::net::Network>("l1");
    l1_ptr->vertices()->add(a1);
    l1_ptr->vertices()->add(a2);
    //auto l2 = std::make_unique<uu::net::Network>("l2");
    l2_ptr->vertices()->add(a1);
    l2_ptr->vertices()->add(a2);

    auto communities = std::make_unique<uu::net::CommunityStructure<M>>();
    auto c1 = std::make_unique<uu::net::Community<M>>();
    c1->add(uu::net::MLVertex(a1,l1_ptr));
    c1->add(uu::net::MLVertex(a1,l2_ptr));
    c1->add(uu::net::MLVertex(a2,l2_ptr));
    auto c2 = std::make_unique<uu::net::Community<M>>();
    c2->add(uu::net::MLVertex(a1,l1_ptr));
    communities->add(std::move(c1));
    communities->add(std::move(c2));

    uu::net::write_multilayer_communities(communities.get(), test_file_name);

    auto communities2 = uu::net::read_multilayer_communities(test_file_name, g.get());

    EXPECT_EQ((size_t)2, communities2->size());
    EXPECT_TRUE(communities2->at(0)->size()==1 || communities2->at(1)->size()==1);
    EXPECT_TRUE(communities2->at(0)->size()==3 || communities2->at(1)->size()==3);

    std::remove(test_file_name.data());
}

