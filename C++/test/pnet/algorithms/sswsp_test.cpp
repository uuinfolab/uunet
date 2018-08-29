#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "pnet/io/read_probabilistic_graph.h"
#include "pnet/algorithms/sswsp.h"

class pnet_algorithms_sswsp_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_graph_file.tmp";
    std::unique_ptr<uu::net::ProbabilisticGraph> g;

    void
    SetUp() override
    {
        // Create a test file
        std::ofstream test_file;
        test_file.open(test_file_name);

        if (!test_file.is_open())
        {
            FAIL()
                    << "Could not create temporary file. Test not executed.";
        }

        test_file << "#VERSION           " << std::endl;
        test_file << "2.0                " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#TYPE              " << std::endl;
        test_file << "undirected         " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#VERTICES          " << std::endl;
        test_file << "v0                 " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGES             " << std::endl;
        test_file << "v1,v2,0.2          " << std::endl;
        test_file << "v1,v3,0.2          " << std::endl;
        test_file << "v2,v3,0.2          " << std::endl;
        test_file << "v2,v4,0.2          " << std::endl;
        test_file << "v2,v5,0.2          " << std::endl;
        test_file << "v2,v6,0.2          " << std::endl;
        test_file << "v3,v5,0.2          " << std::endl;
        test_file << "v3,v6,0.2          " << std::endl;
        test_file << "v4,v5,0.2          " << std::endl;
        test_file << "v5,v6,0.2          " << std::endl;
        test_file << "v5,v7,0.2          " << std::endl;
        test_file << "v6,v7,0.2          " << std::endl;
        test_file << "v7,v8,0.2          " << std::endl;
        test_file << "v7,v9,0.2          " << std::endl;
        test_file << "v8,v9,0.2          " << std::endl;
        test_file.close();

        g = uu::net::read_probabilistic_graph(test_file_name, "g", ',');

    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(pnet_algorithms_sswsp_test, single_source_weighted_path_length)
{
    auto source = g->vertices()->get("v1");
    auto pos_source = g->vertices()->get_index(source);
    
    auto path_lengths = uu::net::single_source_weighted_path_length(g.get(), source);
    
    auto v2 = g->vertices()->get("v2");
    auto pos_v2 = g->vertices()->get_index(v2);
    auto v3 = g->vertices()->get("v3");
    auto pos_v3 = g->vertices()->get_index(v3);
    auto v4 = g->vertices()->get("v4");
    auto pos_v4 = g->vertices()->get_index(v4);
    auto v7 = g->vertices()->get("v7");
    auto pos_v7 = g->vertices()->get_index(v7);
    auto v9 = g->vertices()->get("v9");
    auto pos_v9 = g->vertices()->get_index(v9);
    auto v0 = g->vertices()->get("v0");
    auto pos_v0 = g->vertices()->get_index(v0);
    

    EXPECT_NEAR(1,path_lengths.at(pos_source),0.0000001)
    << "wrong shortest path length, vertex v1";
    EXPECT_NEAR(0.2,path_lengths.at(pos_v2),0.0000001)
    << "wrong shortest path length, vertex v2";
    EXPECT_NEAR(0.2,path_lengths.at(pos_v3),0.0000001)
    << "wrong shortest path length, vertex v3";
    EXPECT_NEAR(0.04,path_lengths.at(pos_v4),0.0000001)
    << "wrong shortest path length, vertex v4";
    EXPECT_NEAR(0.008,path_lengths.at(pos_v7),0.0000001)
    << "wrong shortest path length, vertex v7";
    EXPECT_NEAR(0.0016,path_lengths.at(pos_v9),0.0000001)
    << "wrong shortest path length, vertex v9";
    EXPECT_NEAR(0,path_lengths.at(pos_v0),0.0000001)
    << "wrong shortest path length, vertex v0";
  
}

