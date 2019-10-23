#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_network.hpp"
#include "measures/degree.hpp"

class net_measures_degree_test : public ::testing::Test
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

        g = uu::net::read_network(test_file_name, "g", ',');

    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_measures_degree_test, min_degree)
{
    size_t min_d = uu::net::minimum_degree(g.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)0, min_d)
            << "wrong minimum degree";
}

TEST_F(net_measures_degree_test, max_degree)
{
    size_t max_d = uu::net::maximum_degree(g.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)5, max_d)
            << "wrong maximum degree";
}


TEST_F(net_measures_degree_test, degree_sequence)
{
    std::vector<size_t> seq = uu::net::degree_sequence(g.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)10, seq.size())
            << "wrong degree sequence leng.hpp";
    EXPECT_EQ((size_t)0, seq.at(0))
            << "wrong degree sequence value at pos 0";
    EXPECT_EQ((size_t)2, seq.at(1))
            << "wrong degree sequence value at pos 1";
    EXPECT_EQ((size_t)5, seq.at(9))
            << "wrong degree sequence value at pos 9";
}

TEST_F(net_measures_degree_test, degree_distribution)
{
    std::vector<size_t> dist = uu::net::degree_distribution(g.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)6, dist.size())
            << "wrong degree distribution size";
    EXPECT_EQ((size_t)1, dist.at(0))
            << "wrong degree distribution value for degree 0";
    EXPECT_EQ((size_t)0, dist.at(1))
            << "wrong degree distribution value for degree 1";
    EXPECT_EQ((size_t)4, dist.at(2))
            << "wrong degree distribution value for degree 2";
}

TEST_F(net_measures_degree_test, degree)
{
    auto v0 = g->vertices()->get("v0");
    size_t d0 = uu::net::degree(g.get(), v0, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)0, d0)
            << "wrong degree, vertex v0";


    auto v1 = g->vertices()->get("v1");
    size_t d1 = uu::net::degree(g.get(), v1, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, d1)
            << "wrong degree, vertex v1";


    auto v2 = g->vertices()->get("v2");
    size_t d2 = uu::net::degree(g.get(), v2, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)5, d2)
            << "wrong degree, vertex v2";


    auto v3 = g->vertices()->get("v3");
    size_t d3 = uu::net::degree(g.get(), v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)4, d3)
            << "wrong degree, vertex v3";
}

