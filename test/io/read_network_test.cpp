#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_network.hpp"

TEST(io_test, read_network)
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
    test_file << "v1,v2,2.3          " << std::endl;
    test_file << "v1,v3,NaN          " << std::endl;
    test_file << "v2,v1,3            " << std::endl;
    test_file << "v1,v4,4.2          " << std::endl;
    test_file.close();
    
    // tests
    
    auto g = uu::net::read_network(test_file_name, "g", ',');

    auto v1 = g->vertices()->get("v1");
    ASSERT_TRUE(v1);
    auto v2 = g->vertices()->get("v2");
    ASSERT_TRUE(v2);
    auto v3 = g->vertices()->get("v3");
    ASSERT_TRUE(v3);
    auto e = g->edges()->get(v2,v1);
    ASSERT_TRUE(e);
    double val = g->edges()->attr()->get_double(e, "a1").value;
    EXPECT_EQ(val, 3.0);
    auto e2 = g->edges()->get(v1,v3);
    ASSERT_TRUE(e2);
    uu::core::Value<double> val2 = g->edges()->attr()->get_double(e2, "a1");
    ASSERT_TRUE(val2.null);
    
    // cleaning up

    std::remove(test_file_name.data());
}

