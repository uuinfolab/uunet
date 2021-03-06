#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_probabilistic_network.hpp"

TEST(io_test, read_probabilistic_network)
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
    test_file << "probabilistic      " << std::endl;
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
    test_file << "v1,v2,1,2.3      " << std::endl;
    test_file << "v1,v3,1,4         " << std::endl;
    test_file << "v2,v1,.97,3         " << std::endl;
    test_file << "v1,v4,.23,4.2       " << std::endl;
    test_file.close();

    // tests
       
    auto g = uu::net::read_probabilistic_network(test_file_name, "g", ',');

    EXPECT_TRUE(uu::net::is_probabilistic(g.get()));
    
    auto v1 = g->vertices()->get("v1");
    ASSERT_TRUE(v1);
    auto v2 = g->vertices()->get("v2");
    ASSERT_TRUE(v2);
    auto e = g->edges()->get(v2,v1);
    ASSERT_TRUE(e);
    double val = g->edges()->attr()->get_double(e, "a1").value;
    EXPECT_EQ(val, 3.0);
    
    EXPECT_EQ(uu::net::get_prob(g.get(), e), .97);
    
    // cleaning up

    std::remove(test_file_name.data());
}

