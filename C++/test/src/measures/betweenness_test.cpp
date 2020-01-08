#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_network.hpp"
#include "measures/betweenness.hpp"

class net_measures_betweenness_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_graph_file.tmp";
    std::unique_ptr<uu::net::Network> g;

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
        test_file << "v1,v2              " << std::endl;
        test_file << "v1,v3              " << std::endl;
        test_file << "v2,v3              " << std::endl;
        test_file << "v2,v4              " << std::endl;
        test_file << "v2,v5              " << std::endl;
        test_file << "v2,v6              " << std::endl;
        test_file << "v3,v5              " << std::endl;
        test_file << "v3,v6              " << std::endl;
        test_file << "v4,v5              " << std::endl;
        test_file << "v5,v6              " << std::endl;
        test_file << "v5,v7              " << std::endl;
        test_file << "v6,v7              " << std::endl;
        test_file << "v7,v8              " << std::endl;
        test_file << "v7,v9              " << std::endl;
        test_file << "v8,v9              " << std::endl;
        test_file.close();

        g = uu::net::read_network(test_file_name, "g", ',');

    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_measures_betweenness_test, betweenness)
{
    auto C_b = uu::net::betweenness(g.get());

    auto v0 = g->vertices()->get("v0");
    auto v2 = g->vertices()->get("v2");
    auto v3 = g->vertices()->get("v3");
    auto v7 = g->vertices()->get("v7");
    auto v8 = g->vertices()->get("v8");

    ASSERT_EQ(C_b[v0], 0.0);
    ASSERT_EQ(C_b[v2], 4.5);
    ASSERT_EQ(C_b[v3], 2.5);
    ASSERT_EQ(C_b[v7], 12.0);
    ASSERT_EQ(C_b[v8], 0.0);
}
