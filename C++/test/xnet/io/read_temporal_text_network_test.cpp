#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "xnet/io/read_temporal_text_network.h"

class net_io_read_temporal_text_network_test : public ::testing::Test
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

        test_file << "#VERSION             " << std::endl;
        test_file << "2.0                  " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#INTRALAYER VERTICES " << std::endl;
        test_file << "m1,M,Some text       " << std::endl;
        test_file << "m2,M,Some otehr text " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#INTERLAYER EDGES    " << std::endl;
        test_file << "a1,A,m1,M,15432      " << std::endl;
        test_file << "m1,M,a2,A,15432      " << std::endl;
        test_file << "m1,M,a3,A,15632      " << std::endl;
        test_file << "a2,A,m2,M,15732      " << std::endl;
        test_file << "m2,M,a1,A,15832      " << std::endl;
        test_file.close();
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_io_read_temporal_text_network_test, read)
{
    auto net = uu::net::read_temporal_text_network(test_file_name, "g", ',');
    std::cout << net->summary() << std::endl;
}

