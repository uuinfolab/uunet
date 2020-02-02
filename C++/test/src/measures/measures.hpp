#ifndef UU_TEST_MEASURES_H_
#define UU_TEST_MEASURES_H_

#include "gtest/gtest.h"

#include "io/read_network.hpp"

class net_measures_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_graph_file.tmp";
    
    std::unique_ptr<uu::net::Network> g;
    const uu::net::Vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7, *v8, *v9;
    const uu::net::Edge *e1, *e2, *e3, *e4, *e5, *e6, *e7, *e8;

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
        test_file << "v1                 " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGES             " << std::endl;
        test_file << "v2,v4              " << std::endl;
        test_file << "v3,v4              " << std::endl;
        test_file << "v4,v5              " << std::endl;
        test_file << "v4,v6              " << std::endl;
        test_file << "v5,v7              " << std::endl;
        test_file << "v6,v7              " << std::endl;
        test_file << "v8,v9              " << std::endl;
        test_file.close();

        g = uu::net::read_network(test_file_name, "g", ',');

        v1 = g->vertices()->get("v1");
        v2 = g->vertices()->get("v2");
        v3 = g->vertices()->get("v3");
        v4 = g->vertices()->get("v4");
        v5 = g->vertices()->get("v5");
        v6 = g->vertices()->get("v6");
        v7 = g->vertices()->get("v7");
        v8 = g->vertices()->get("v8");
        v9 = g->vertices()->get("v9");
        
        e1 = g->edges()->get(v2, v4);
        e2 = g->edges()->get(v3, v4);
        e3 = g->edges()->get(v4, v5);
        e4 = g->edges()->get(v4, v6);
        e5 = g->edges()->get(v5, v7);
        e6 = g->edges()->get(v6, v7);
        e7 = g->edges()->get(v8, v9);
        
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

#endif
