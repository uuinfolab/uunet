#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/_impl/read_common.hpp"
#include "io/_impl/read_ml_common.hpp"

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
        test_file << "3.0                  " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#LAYERS              " << std::endl;
        test_file << "l1, DIRECTED         " << std::endl;
        test_file << "l2, UNDIRECTED       " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#ACTOR ATTRIBUTES    " << std::endl;
        test_file << "a1,string            " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#VERTEX ATTRIBUTES   " << std::endl;
        test_file << "l1,a1,string         " << std::endl;
        test_file << "l2,a1,double         " << std::endl;
        test_file << "l3,a1,double         " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#EDGE ATTRIBUTES     " << std::endl;
        test_file << "a,string            " << std::endl;
        test_file << "l1,a1,string         " << std::endl;
        test_file << "l2,a1,double         " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#VERTICES            " << std::endl;
        test_file << "v6,l2                " << std::endl;
        test_file << "                     " << std::endl;
        test_file << "#EDGES               " << std::endl;
        test_file << "v1,v2,l1,a,b         " << std::endl;
        test_file << "v1,v5,l1,a,b         " << std::endl;
        test_file << "v2,v5,l1,a,b         " << std::endl;
        test_file << "v2,v3,l1,a,b         " << std::endl;
        test_file << "v2,v4,l1,a,b         " << std::endl;
        test_file << "v3,v4,l1,a,b         " << std::endl;
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
     */
    ASSERT_EQ((size_t)3, meta.layers.size())
            << "wrong number of layers read";

    EXPECT_TRUE(meta.layers.at("l1").is_directed)
            << "wrong layer feature: DIRECTED";
    EXPECT_FALSE(meta.layers.at("l2").is_directed)
            << "wrong layer feature: UNDIRECTED";
    EXPECT_FALSE(meta.layers.at("l3").is_directed)
            << "wrong layer feature: UNDIRECTED";

    EXPECT_EQ((size_t)1, meta.vertex_attributes.size())
            << "wrong number of vertex attributes read";
    //EXPECT_EQ(1, meta.edge_attributes.size())
    //        << "wrong number of vertex attributes read";
    EXPECT_EQ((size_t)2, meta.intralayer_edge_attributes.at("l1").size())
            << "wrong number of edge attributes read";



}

