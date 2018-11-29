#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "mnet/io/read_attributed_homogeneous_multilayer_network.h"

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
        test_file << "multiplex                     " << std::endl;
        test_file << "#VERSION             " << std::endl;
        test_file << "2.0                  " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#LAYERS              " << std::endl;
        test_file << "l1, UNDIRECTED       " << std::endl;
        test_file << "l2, UNDIRECTED       " << std::endl;
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
        test_file << "                     " << std::endl;
        test_file << "#EDGES               " << std::endl;
        test_file << "v1,v2,l1,0           " << std::endl;
        test_file << "v1,v5,l1,0           " << std::endl;
        test_file << "v2,v5,l1,0           " << std::endl;
        test_file << "v2,v3,l1,0           " << std::endl;
        test_file << "v2,v4,l1,1           " << std::endl;
        test_file << "v3,v4,l1,1           " << std::endl;
        test_file << "v1,v4,l2             " << std::endl;
        test_file << "v2,v3,l2             " << std::endl;
        test_file << "v2,v4,l2             " << std::endl;
        test_file << "v3,v4,l2             " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#INTERLAYER EDGES    " << std::endl;
        test_file << "v1,l1,v2,l2          " << std::endl;
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
    std::cout << net->summary() << std::endl;

}

