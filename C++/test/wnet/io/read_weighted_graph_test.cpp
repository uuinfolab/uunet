#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "wnet/io/read_weighted_graph.h"

class net_io_weighted_graph_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_graph_file.tmp";

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
        test_file << "weighted           " << std::endl;
        test_file << "directed           " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#VERTEX ATTRIBUTES " << std::endl;
        test_file << "a1, int            " << std::endl;
        test_file << "a2, string         " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGE ATTRIBUTES   " << std::endl;
        test_file << "a1, double         " << std::endl;
        test_file << "a2, time           " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGES             " << std::endl;
        test_file << "v1,v2,.45          " << std::endl;
        test_file << "v1,v3,.553          " << std::endl;
        test_file << "v2,v1,.35          " << std::endl;
        test_file << "v1,v4,.519          " << std::endl;
        test_file.close();
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_io_weighted_graph_test, read)
{
    auto g = uu::net::read_weighted_graph(test_file_name, "g", ',');
    std::cout << g->summary() << std::endl;

}

