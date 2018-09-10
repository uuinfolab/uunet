#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "tnet/io/read_temporal_network.h"

class net_io_temporal_network_test : public ::testing::Test
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
        test_file << "temporal           " << std::endl;
        test_file << "directed           " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGES             " << std::endl;
        test_file << "v1,v2,14232        " << std::endl;
        test_file << "v1,v3,14234        " << std::endl;
        test_file << "v2,v1,41432        " << std::endl;
        test_file << "v1,v4,23423        " << std::endl;
        test_file.close();
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_io_temporal_network_test, read)
{
    auto g = uu::net::read_temporal_network(test_file_name, "g", ',');
    std::cout << g->summary() << std::endl;

}

