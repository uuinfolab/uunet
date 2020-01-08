#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_network.hpp"
#include "operations/test.hpp"

class operations_test_test : public ::testing::Test
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
        test_file << "v1p1,v2p2          " << std::endl;
        test_file << "v1p1,v3p2          " << std::endl;
        test_file << "v2p1,v3p2          " << std::endl;
        test_file << "v2p1,v4p2          " << std::endl;
        test_file << "v2p1,v5p2          " << std::endl;
        test_file << "v2p1,v6p2          " << std::endl;
        test_file << "v3p1,v5p2          " << std::endl;
        test_file << "v3p1,v6p2          " << std::endl;
        test_file << "v4p1,v5p2          " << std::endl;
        test_file << "v5p1,v6p2          " << std::endl;
        test_file << "v5p1,v7p2          " << std::endl;
        test_file << "v6p1,v7p2          " << std::endl;
        test_file << "v7p1,v8p2          " << std::endl;
        test_file << "v7p1,v9p2          " << std::endl;
        test_file << "v8p1,v9p2          " << std::endl;
        test_file.close();

        g = uu::net::read_network(test_file_name, "g", ',');

    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(operations_test_test, is_bipartite)
{
    bool test1 = uu::net::is_bipartite(g.get());
    EXPECT_EQ(true, test1);

    auto v1 = g->vertices()->get("v1p1");
    auto v2 = g->vertices()->get("v2p1");

    g->edges()->add(v1, v2);

    bool test2 = uu::net::is_bipartite(g.get());
    EXPECT_EQ(false, test2);
}
