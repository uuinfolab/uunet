#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "net/algorithms/components.h"
#include "net/io/read_simple_graph.h"

class net_measures_components_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_graph_file.tmp";
    std::unique_ptr<uu::net::SimpleGraph> g;

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

        g = uu::net::read_simple_graph(test_file_name, "g", ',');

    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_measures_components_test, membership)
{
    std::vector<int> comp_id = uu::net::components(g.get());

    auto v0 = g->vertices()->get("v0");
    size_t pos_v0 = g->vertices()->get_index(v0);

    auto v1 = g->vertices()->get("v1");
    size_t pos_v1 = g->vertices()->get_index(v1);

    auto v8 = g->vertices()->get("v8");
    size_t pos_v8 = g->vertices()->get_index(v8);

    EXPECT_NE(comp_id.at(pos_v0), comp_id.at(pos_v1))
            << "these vertices should be in two different components";

    EXPECT_EQ(comp_id.at(pos_v1), comp_id.at(pos_v8))
            << "these vertices should be in the same component";
}
