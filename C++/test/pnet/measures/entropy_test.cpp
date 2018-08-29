#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "pnet/io/read_probabilistic_graph.h"
#include "pnet/measures/entropy.h"


class pnet_measures_entropy_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_graph_file.tmp";
    std::unique_ptr<uu::net::ProbabilisticGraph> g;

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
        test_file << "probabilistic      " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#VERTICES          " << std::endl;
        test_file << "v0                 " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGES             " << std::endl;
        test_file << "v1,v2,0.1           " << std::endl;
        test_file << "v1,v3,0.1           " << std::endl;
        test_file << "v2,v3,0.1           " << std::endl;
        test_file << "v2,v4,0.1           " << std::endl;
        test_file << "v2,v5,0.1           " << std::endl;
        test_file << "v2,v6,0.1           " << std::endl;
        test_file << "v3,v5,0.1           " << std::endl;
        test_file << "v3,v6,0.1           " << std::endl;
        test_file << "v4,v5,0.1           " << std::endl;
        test_file << "v5,v6,0.1           " << std::endl;
        test_file << "v5,v7,0.1           " << std::endl;
        test_file << "v6,v7,0.1           " << std::endl;
        test_file << "v7,v8,0.1           " << std::endl;
        test_file << "v7,v9,0.1           " << std::endl;
        test_file << "v8,v9,0.1           " << std::endl;
        test_file.close();

        g = uu::net::read_probabilistic_graph(test_file_name, "g", ',');

    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(pnet_measures_entropy_test, graph_entropy)
{
    double x = 15*(-(0.1)*log10(0.1)-(0.9)*log10(0.9));
    double e = uu::net::graph_entropy(g.get());
    EXPECT_NEAR(x,e,0.0000001)
            << "wrong entropy";

   
}



