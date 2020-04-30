#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/_impl/read_common.hpp"

class net_io_read_common_test : public ::testing::Test
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

        test_file << "#VERSION           " << std::endl;
        test_file << "2.0                " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#TYPE              " << std::endl;
        test_file << "weighted           " << std::endl;
        test_file << "directed           " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#VERTEX ATTRIBUTES " << std::endl;
        test_file << "a1, int            " << std::endl;
        test_file << "a2, string         " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGE ATTRIBUTES   " << std::endl;
        test_file << "a1, double         " << std::endl;
        test_file << "a2, time           " << std::endl;
        test_file << "                   " << std::endl;
        test_file << "#EDGES             " << std::endl;
        test_file << "v1,v2,.45          " << std::endl;
        test_file << "v1,v3,.553          " << std::endl;
        test_file << "v2,v1,.35          " << std::endl;
        test_file << "v1,v4,.519          " << std::endl;
        test_file.close();
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(net_io_read_common_test, read_metadata)
{
    uu::net::GraphMetadata meta = uu::net::read_metadata(test_file_name, ',');

    EXPECT_TRUE(meta.features.is_directed)
            << "wrong feature: DIRECTED";
    EXPECT_TRUE(meta.features.is_weighted)
            << "wrong feature: WEIGHTED";
    EXPECT_EQ((size_t)2, meta.vertex_attributes.size())
            << "wrong number of vertex attributes read";
    EXPECT_EQ((size_t)2, meta.edge_attributes.size())
            << "wrong number of vertex attributes read";
}

