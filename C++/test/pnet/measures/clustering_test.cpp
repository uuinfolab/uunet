#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "pnet/io/read_probabilistic_graph.h"
#include "pnet/measures/clustering.h"



class pnet_measures_clustering_test : public ::testing::Test
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


TEST_F(pnet_measures_clustering_test, expected_clustering_coefficient)
{
    double x = 0;
    auto v0 = g->vertices()->get("v0");
    double c0 = uu::net::expected_clustering_coefficient(g.get(), v0);
    EXPECT_EQ(x, c0)
            << "wrong expected clustering coefficient, vertex v0";

    x = 0.1;
    auto v1 = g->vertices()->get("v1");
    double c1 = uu::net::expected_clustering_coefficient(g.get(), v1);
    EXPECT_EQ(x, c1)
            << "wrong expected clustering coefficient, vertex v1";

    x = 0.4/6;
    auto v6 = g->vertices()->get("v6");
    double c6 = uu::net::expected_clustering_coefficient(g.get(), v6);
    EXPECT_EQ(x, c6)
            << "wrong expected clustering coefficient, vertex v6";

    //x = 0.05;
    //auto v2 = g->vertices()->get("v2");
    //double c2 = uu::net::expected_clustering_coefficient(g.get(), v2);
    //EXPECT_EQ(x, c2)
    //    << "wrong clustering coefficient, vertex v2";    
}

TEST_F(pnet_measures_clustering_test, average_expected_clustering_coefficient)
{
    double x = 0.0666667;
    double avgc = uu::net::average_expected_clustering_coefficient(g.get());
    EXPECT_EQ(x, avgc)
            << "wrong average expected clustering coefficient";
}

