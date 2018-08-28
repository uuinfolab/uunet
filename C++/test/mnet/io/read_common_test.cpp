#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "mnet/io/read_common.h"

class mnet_io_read_common_test : public ::testing::Test
{
  protected:

    std::string test_file_name = "net_io_read_common_test_file.tmp";

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

TEST_F(mnet_io_read_common_test, read_metadata)
{
    uu::net::MultilayerMetadata meta = uu::net::read_multilayer_metadata(test_file_name, ',');

    /*
    EXPECT_TRUE(meta.features.is_directed)
            << "wrong feature: DIRECTED";
    EXPECT_TRUE(meta.features.is_weighted)
            << "wrong feature: WEIGHTED";
    EXPECT_EQ(2, meta.vertex_attributes.size())
            << "wrong number of vertex attributes read";
    EXPECT_EQ(2, meta.edge_attributes.size())
            << "wrong number of vertex attributes read";
     */
    
}

