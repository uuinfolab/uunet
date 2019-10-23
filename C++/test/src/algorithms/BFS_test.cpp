#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "algorithms/BFS.hpp"
#include "io/read_network.hpp"

class net_algorithms_BFS_test : public ::testing::Test
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
        test_file << "directed         " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#VERTICES          " << std::endl;
        test_file << "v6                 " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGES             " << std::endl;
        test_file << "v0,v1              " << std::endl;
        test_file << "v1,v3              " << std::endl;
        test_file << "v3,v2              " << std::endl;
        test_file << "v2,v1              " << std::endl;
        test_file << "v2,v4              " << std::endl;
        test_file << "v3,v5              " << std::endl;
        test_file << "v7,v8              " << std::endl;
        test_file << "v8,v7              " << std::endl;
        test_file.close();

        g = uu::net::read_network(test_file_name, "g", ',');

    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_algorithms_BFS_test, undirected)
{

    auto v0 = g->vertices()->get("v0");
    uu::net::BFS<uu::net::Network> bfs(g.get(), v0, uu::net::EdgeMode::INOUT);

    const uu::net::Vertex* current_vertex;

    current_vertex = bfs.get_next();
    EXPECT_EQ(current_vertex->name, "v0")
            << "wrong vertex";

    current_vertex = bfs.get_next();
    EXPECT_EQ(current_vertex->name, "v1")
            << "wrong vertex";

    current_vertex = bfs.get_next();

    if (current_vertex->name == "v2")
    {
        current_vertex = bfs.get_next();
        EXPECT_EQ(current_vertex->name, "v3")
                << "wrong vertex";

        current_vertex = bfs.get_next();
        EXPECT_EQ(current_vertex->name, "v4")
                << "wrong vertex";

        current_vertex = bfs.get_next();
        EXPECT_EQ(current_vertex->name, "v5")
                << "wrong vertex";

        EXPECT_EQ(nullptr, bfs.get_next())
                << "no more vertices should be returned";
    }

    else if (current_vertex->name == "v3")
    {
        current_vertex = bfs.get_next();
        EXPECT_EQ(current_vertex->name, "v2")
                << "wrong vertex";

        current_vertex = bfs.get_next();
        EXPECT_EQ(current_vertex->name, "v5")
                << "wrong vertex";

        current_vertex = bfs.get_next();
        EXPECT_EQ(current_vertex->name, "v4")
                << "wrong vertex";

        EXPECT_EQ(nullptr, bfs.get_next())
                << "no more vertices should be returned";
    }

    else
    {
        FAIL()
                << "wrong vertex: should be either v2 or v3, but was " << current_vertex->name;
    }

}


TEST_F(net_algorithms_BFS_test, directed_out1)
{
    auto v0 = g->vertices()->get("v0");
    uu::net::BFS<uu::net::Network> bfs(g.get(), v0, uu::net::EdgeMode::OUT);

    const uu::net::Vertex* current_vertex;

    current_vertex = bfs.get_next();
    EXPECT_EQ(current_vertex->name, "v0")
            << "wrong vertex";

    current_vertex = bfs.get_next();
    EXPECT_EQ(current_vertex->name, "v1")
            << "wrong vertex";

}

TEST_F(net_algorithms_BFS_test, directed_out2)
{
    auto v5 = g->vertices()->get("v5");
    uu::net::BFS<uu::net::Network> bfs(g.get(), v5, uu::net::EdgeMode::OUT);

    const uu::net::Vertex* current_vertex;

    current_vertex = bfs.get_next();
    EXPECT_EQ(current_vertex->name, "v5")
            << "wrong vertex";

    EXPECT_EQ(nullptr, bfs.get_next())
            << "no more vertices should be returned";

}



TEST_F(net_algorithms_BFS_test, directed_in1)
{
    auto v5 = g->vertices()->get("v5");
    uu::net::BFS<uu::net::Network> bfs(g.get(), v5, uu::net::EdgeMode::IN);

    const uu::net::Vertex* current_vertex;

    current_vertex = bfs.get_next();
    EXPECT_EQ(current_vertex->name, "v5")
            << "wrong vertex";

    current_vertex = bfs.get_next();
    EXPECT_EQ(current_vertex->name, "v3")
            << "wrong vertex";


}

TEST_F(net_algorithms_BFS_test, directed_in2)
{
    auto v0 = g->vertices()->get("v0");
    uu::net::BFS<uu::net::Network> bfs(g.get(), v0, uu::net::EdgeMode::IN);

    const uu::net::Vertex* current_vertex;

    current_vertex = bfs.get_next();
    EXPECT_EQ(current_vertex->name, "v0")
            << "wrong vertex";

    EXPECT_EQ(nullptr, bfs.get_next())
            << "no more vertices should be returned";

}
