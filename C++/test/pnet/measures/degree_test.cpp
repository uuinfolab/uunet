#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "pnet/io/read_probabilistic_graph.h"
#include "pnet/measures/degree.h"
#include "net/measures/degree.h"

class pnet_measures_degree_test : public ::testing::Test
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


TEST_F(pnet_measures_degree_test, expected_degree)
{
    auto v0 = g->vertices()->get("v0");
    double e0 = uu::net::expected_degree(g.get(), v0, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(0, e0)
            << "wrong expected degree, vertex v0";

    auto v1 = g->vertices()->get("v1");
    double e1 = uu::net::expected_degree(g.get(), v1, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(0.2, e1)
            << "wrong expected degree, vertex v1";

    auto v2 = g->vertices()->get("v2");
    double e2 = uu::net::expected_degree(g.get(), v2, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(0.5, e2)
            << "wrong expecte degree, vertex v1";
}


TEST_F(pnet_measures_degree_test,maximum_expected_degree)
{
    double e = uu::net::maximum_expected_degree(g.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ(0.5, e)
            << "wrong maximum expected degree";
}


TEST_F(pnet_measures_degree_test,minimum_expected_degree)
{
    double e = uu::net::minimum_expected_degree(g.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ(0, e)
            << "wrong minimum expected degree";
}



TEST_F(pnet_measures_degree_test,vertex_degree_distribution)
{
    std::vector<double> ans;
    ans.push_back(0.81);
    ans.push_back(0.18);
    ans.push_back(0.01);

    auto v1 = g->vertices()->get("v1");
    auto e1 = uu::net::vertex_degree_distribution(g.get(), v1, uu::net::EdgeMode::INOUT);

    EXPECT_EQ(ans, e1)
            << "wrong degree distribution";
}

TEST_F(pnet_measures_degree_test,eta_degree)
{
    auto v1 = g->vertices()->get("v1");
    auto d =  uu::net::eta_degree(g.get(), v1, 0.04, uu::net::EdgeMode::INOUT);

    EXPECT_EQ(1, d)
            << "wrong eta degree";
}


TEST_F(pnet_measures_degree_test,maximum_eta_degree)
{
    auto d =  uu::net::maximum_eta_degree(g.get(), 0.04, uu::net::EdgeMode::INOUT);

    EXPECT_EQ(2, d)
            << "wrong maximum eta degree";
}


TEST_F(pnet_measures_degree_test,minimum_eta_degree)
{
    auto d =  uu::net::minimum_eta_degree(g.get(), 0.04, uu::net::EdgeMode::INOUT);

    EXPECT_EQ(0, d)
            << "wrong minimum eta degree";
}


TEST_F(pnet_measures_degree_test,eta_degree_distribution)
{
    std::vector<int> ans;
    ans.push_back(1);
    ans.push_back(4);
    ans.push_back(5);

    auto edd = uu::net::eta_degree_distribution(g.get(), 0.04, uu::net::EdgeMode::INOUT);

    EXPECT_EQ(ans, edd)
            << "wrong eta degree distribution";
}


TEST_F(pnet_measures_degree_test,average_eta_degree)
{
    double ans = 1.4;
    auto avgeta1 = uu::net::average_eta_degree(g.get(), 0.04, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(ans, avgeta1)
            << "wrong average eta degree";

    ans = 0;
    auto avgeta2 = uu::net::average_eta_degree(g.get(), 0.5, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(ans, avgeta2)
            << "wrong average eta degree";
}

TEST_F(pnet_measures_degree_test,average_expected_degree)
{
    double ans = 0.3;
    auto avgexp = uu::net::average_expected_degree(g.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ(ans, avgexp)
            << "wrong average expected degree";
}

TEST_F(pnet_measures_degree_test,average_degree)
{
    int ans = 3;
    auto avgdeg = uu::net::average_degree(g.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ(ans, avgdeg)
            << "wrong average degree";
}


