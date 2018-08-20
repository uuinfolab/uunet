#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "wnet/io/read_weighted_graph.h"
#include "wnet/measures/strength.h"

class net_measures_strength_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_graph_file.tmp";
    std::unique_ptr<uu::net::WeightedGraph> g;

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
        test_file << "weighted           " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#VERTICES          " << std::endl;
        test_file << "v0                 " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGES             " << std::endl;
        test_file << "v1,v2,.5           " << std::endl;
        test_file << "v1,v3,.6           " << std::endl;
        test_file << "v2,v3,.7           " << std::endl;
        test_file << "v2,v4,.7           " << std::endl;
        test_file << "v2,v5,.7           " << std::endl;
        test_file << "v2,v6,.7           " << std::endl;
        test_file << "v3,v5,.2           " << std::endl;
        test_file << "v3,v6,.2           " << std::endl;
        test_file << "v4,v5,.2           " << std::endl;
        test_file << "v5,v6,.2           " << std::endl;
        test_file << "v5,v7,.2           " << std::endl;
        test_file << "v6,v7,.2           " << std::endl;
        test_file << "v7,v8,.2           " << std::endl;
        test_file << "v7,v9,.2           " << std::endl;
        test_file << "v8,v9,.2           " << std::endl;
        test_file.close();

        g = uu::net::read_weighted_graph(test_file_name, "g", ',');

    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_measures_strength_test, strength)
{
    auto v0 = g->vertices()->get("v0");
    double s0 = uu::net::strength(g.get(), v0, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(0, s0)
            << "wrong strength, vertex v0";


    auto v1 = g->vertices()->get("v1");
    double s1 = uu::net::strength(g.get(), v1, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(1.1, s1)
            << "wrong strength, vertex v1";


}

