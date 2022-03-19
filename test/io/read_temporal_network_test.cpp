#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_temporal_network.hpp"

TEST(io_test, read_temporal_network)
{
    // preparing a file to read

    std::string test_file_name = "net_io_read_graph_file.tmp";

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
    test_file << "directed           " << std::endl;
    test_file << "temporal           " << std::endl;
    test_file << "                   " << std::endl;
    test_file << "#VERTEX ATTRIBUTES " << std::endl;
    test_file << "a1,string          " << std::endl;
    test_file << "                   " << std::endl;
    test_file << "#EDGE ATTRIBUTES   " << std::endl;
    test_file << "a1,double          " << std::endl;
    test_file << "                   " << std::endl;
    test_file << "#VERTICES          " << std::endl;
    test_file << "v1,a_value         " << std::endl;
    test_file << "v2,another_value   " << std::endl;
    test_file << "v4,one_more_value  " << std::endl;
    test_file << "                   " << std::endl;
    test_file << "#EDGES             " << std::endl;
    test_file << "v1,v2,10000000,2.3 " << std::endl;
    test_file << "v1,v3,10000000,4   " << std::endl;
    test_file << "v2,v1,10000000,3   " << std::endl;
    test_file << "v1,v4,10000000,4.2 " << std::endl;
    test_file.close();

    // tests
    
    auto g = uu::net::read_temporal_network(test_file_name, "g", ',');
    EXPECT_TRUE(uu::net::is_temporal(g.get()));
    
    // cleaning up

    std::remove(test_file_name.data());
}

