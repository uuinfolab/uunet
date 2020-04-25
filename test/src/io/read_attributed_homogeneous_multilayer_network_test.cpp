#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_multilayer_network.hpp"

class net_io_read_attributed_homogeneous_multilayer_network_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_graph_file.tmp";

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

        test_file << "#TYPE                " << std::endl;
        test_file << "multilayer           " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#VERSION             " << std::endl;
        test_file << "3.0                  " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#LAYERS              " << std::endl;
        test_file << "l1,l1,UNDIRECTED     " << std::endl;
        test_file << "l2,l2,UNDIRECTED,LOOPS" << std::endl;
        test_file << "l1,l2,DIRECTED       " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#ACTOR ATTRIBUTES    " << std::endl;
        test_file << "ssn, string          " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#ACTORS              " << std::endl;
        test_file << "v1,122343242         " << std::endl;
        test_file << "v3,122343654         " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#VERTEX ATTRIBUTES   " << std::endl;
        test_file << "l2,day,string        " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#VERTICES            " << std::endl;
        test_file << "v6,l2,Monday         " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#EDGE ATTRIBUTES     " << std::endl;
        test_file << "l1,attr.name,numeric " << std::endl;
        test_file << "attr.name2,numeric   " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#EDGES               " << std::endl;
        test_file << "v1,l1,v2,l1,1,7      " << std::endl;
        test_file << "v1,l1,v5,l1,2,8      " << std::endl;
        test_file << "v2,l1,v5,l1,3,9      " << std::endl;
        test_file << "v2,l1,v3,l1,4,10     " << std::endl;
        test_file << "v2,l1,v4,l1,5,11     " << std::endl;
        test_file << "v3,l1,v4,l1,6,12     " << std::endl;
        test_file << "v1,l1,v4,l2,13       " << std::endl;
        test_file << "v2,l1,v3,l2,14       " << std::endl;
        test_file << "v2,l1,v4,l2,15       " << std::endl;
        test_file << "v3,l1,v3,l2,16       " << std::endl;
        test_file << "v3,l1,v4,l2,17       " << std::endl;
        test_file << "v1,l1,v2,l2,18       " << std::endl;
        test_file << "                     " << std::endl;
        test_file.close();
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_io_read_attributed_homogeneous_multilayer_network_test, read)
{
    auto net = uu::net::read_attributed_homogeneous_multilayer_network(test_file_name, "g", ',');

    //std::cout << net->summary() << std::endl;
    auto l1 = net->layers()->get("l1");
    auto l2 = net->layers()->get("l2");
    auto vertices = l1->vertices();
    auto edges = l1->edges();
    auto v1 = vertices->get("v1");
    auto v2 = vertices->get("v2"); // @todo taking from l1, using on l2... change
    auto v5 = vertices->get("v5");
    auto e = edges->get(v1, v5);
    double val1 = edges->attr()->get_double(e, "attr.name2").value;
    EXPECT_EQ(8.0, val1)
            << "wrong attribute value: edge on layer";

    auto il_edges = net->interlayer_edges();
    auto il_e = il_edges->get(v1,l1,v2,l2);
    double val2 = il_edges->attr()->get_double(il_e, "attr.name2").value;
    EXPECT_EQ(18.0, val2)
            << "wrong attribute value: interlayer edge";


    double dir = il_edges->is_directed(l1, l2);
    EXPECT_TRUE(dir)
            << "wrong interlayer edge directionality";


    //std::cout << net->summary() << std::endl;

}

