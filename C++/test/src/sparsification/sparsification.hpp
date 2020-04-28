#ifndef UU_TEST_SPARSIFICATION_H_
#define UU_TEST_SPARSIFICATION_H_

#include "gtest/gtest.h"

#include "io/read_probabilistic_network.hpp"

class net_sparsification_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_probabilistic_graph_file.tmp";
    
    std::unique_ptr<uu::net::ProbabilisticNetwork> g;
    const uu::net::Vertex *v1, *v2, *v3, *v4;
    const uu::net::Edge *e1_2, *e1_3, *e1_4, *e4_2, *e4_3;
    double spars, span, entropy, improve_threshold;
    bool abs;
    

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

        test_file << "v1,v2,.4           " << std::endl;
        test_file << "v1,v3,.2           " << std::endl;
        test_file << "v1,v4,.3           " << std::endl;
        test_file << "v4,v2,.1           " << std::endl;
        test_file << "v4,v3,.4           " << std::endl;
        test_file.close();

        g = uu::net::read_probabilistic_network(test_file_name, "g", ',');

        v1 = g->vertices()->get("v1");
        v2 = g->vertices()->get("v2");
        v3 = g->vertices()->get("v3");
        v4 = g->vertices()->get("v4");
        
        e1_2 = g->edges()->get(v1, v2);
        e1_3 = g->edges()->get(v1, v3);
        e1_4 = g->edges()->get(v1, v4);
        e4_2 = g->edges()->get(v4, v2);
        e4_3 = g->edges()->get(v4, v3);
        
        spars = 0.6;
        span = 0.3;
        entropy = 1;
        improve_threshold = 0.1;
        abs = true;
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

#endif
