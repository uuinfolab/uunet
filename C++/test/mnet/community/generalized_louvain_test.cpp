#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "mnet/community/glouvain.h"
#include "mnet/io/read_multiplex.h"

class mnet_community_generalized_louvain_test : public ::testing::Test
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

        test_file << "#VERSION             " << std::endl;
        test_file << "2.0                  " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#LAYERS              " << std::endl;
        test_file << "l1, UNDIRECTED       " << std::endl;
        test_file << "l2, UNDIRECTED       " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#INTRALAYER VERTICES " << std::endl;
        test_file << "v6,l2                " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#EDGES               " << std::endl;
        test_file << "v1,v2,l1             " << std::endl;
        test_file << "v1,v5,l1             " << std::endl;
        test_file << "v2,v5,l1             " << std::endl;
        test_file << "v2,v3,l1             " << std::endl;
        test_file << "v2,v4,l1             " << std::endl;
        test_file << "v3,v4,l1             " << std::endl;
        test_file << "v1,v4,l2             " << std::endl;
        test_file << "v2,v3,l2             " << std::endl;
        test_file << "v2,v4,l2             " << std::endl;
        test_file << "v3,v4,l2             " << std::endl;
        test_file.close();
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(mnet_community_generalized_louvain_test, read)
{
    auto net = uu::net::read_multiplex(test_file_name, "g", ',');
    auto com_struct = uu::net::generalized_louvain<uu::net::MultiplexNetwork, uu::net::SimpleGraph>(net.get(), 1, 1, 100);
    
    // DEBUG ONLY
    for (auto c: *com_struct)
    {
        std::cout << "COMMUNITY" << std::endl;
        for (auto p: *c)
        {
            std::cout << p.first->name << "@" << p.second->name << std::endl;
        }
    }

}

