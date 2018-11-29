#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "mnet/community/glouvain.h"
#include "mnet/community/abacus.h"
#include "mnet/community/infomap.h"
#include "mnet/community/ml-cpm.h"
#include "mnet/io/read_multiplex.h"

class mnet_community_test : public ::testing::Test
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
        //test_file << "#VERTICES            " << std::endl;
        //test_file << "v6,l2                " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#EDGES               " << std::endl;
        test_file << "v1,v2,l1             " << std::endl;
        test_file << "v1,v3,l1             " << std::endl;
        test_file << "v2,v3,l1             " << std::endl;
        //test_file << "v3,v6,l1             " << std::endl;
        test_file << "v4,v5,l1             " << std::endl;
        test_file << "v4,v6,l1             " << std::endl;
        test_file << "v5,v6,l1             " << std::endl;
        test_file << "v1,v2,l2             " << std::endl;
        test_file << "v1,v3,l2             " << std::endl;
        test_file << "v2,v3,l2             " << std::endl;
        //test_file << "v2,v4,l2             " << std::endl;
        test_file << "v4,v5,l2             " << std::endl;
        test_file << "v4,v6,l2             " << std::endl;
        test_file << "v5,v6,l2             " << std::endl;
        test_file.close();
    }

    template <typename C>
    void
    print(const C* communities)
    {
        for (auto c: *communities)
        {
            std::cout << "COMMUNITY" << std::endl;

            for (auto p: *c)
            {
                std::cout << p.first->name << "@" << p.second->name << std::endl;
            }
        }
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(mnet_community_test, generalized_louvain)
{
    auto net = uu::net::read_multiplex(test_file_name, "g", ',');
    auto com_struct = uu::net::generalized_louvain<uu::net::MultiplexNetwork, uu::net::SimpleGraph>(net.get(), 1, 1, 100);

    print(com_struct.get());
}


TEST_F(mnet_community_test, infomap)
{
    auto net = uu::net::read_multiplex(test_file_name, "g", ',');
    auto com_struct = uu::net::infomap<uu::net::MultiplexNetwork>(net.get(), false);

    print(com_struct.get());
}

TEST_F(mnet_community_test, abacus)
{
    auto net = uu::net::read_multiplex(test_file_name, "g", ',');
    auto pillar_com_struct = uu::net::abacus<uu::net::MultiplexNetwork, uu::net::SimpleGraph>(net.get(), 2, 3);
    auto com_struct = to_vertex_layer_community_structure(pillar_com_struct.get());
    print(com_struct.get());
}


TEST_F(mnet_community_test, cpm)
{
    auto net = uu::net::read_multiplex(test_file_name, "g", ',');
    auto com_struct = uu::net::mlcpm<uu::net::MultiplexNetwork>(net.get(), 3, 1);
    print(com_struct.get());
}
