#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_multilayer_network.hpp"
#include "community/glouvain2.hpp"

class community_glouvain_test : public ::testing::Test
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

        test_file << "v1,v2,l1             " << std::endl;
        test_file << "v1,v3,l1             " << std::endl;
        test_file << "v2,v3,l1             " << std::endl;
        test_file << "v3,v4,l1             " << std::endl;
        test_file << "v4,v5,l1             " << std::endl;
        test_file << "v4,v6,l1             " << std::endl;
        test_file << "v5,v6,l1             " << std::endl;
        test_file << "v1,v2,l2             " << std::endl;
        test_file << "v1,v3,l2             " << std::endl;
        test_file << "v2,v3,l2             " << std::endl;
        test_file << "v3,v4,l2             " << std::endl;
        test_file << "v4,v5,l2             " << std::endl;
        test_file << "v4,v6,l2             " << std::endl;
        test_file << "v5,v6,l2             " << std::endl;
        test_file.close();
    }

    void
    TearDown() override
    {
        std::remove(test_file_name.data());
    }

};

TEST_F(community_glouvain_test, read_metadata)
{
    auto n = uu::net::read_attributed_homogeneous_multilayer_network(test_file_name, "net", ',');

    auto c = uu::net::glouvain2<uu::net::AttributedHomogeneousMultilayerNetwork>(n.get(), 1.0);

    for (auto com: *c)
    {
        std::cout << "COM" << std::endl;

        for (auto vl: *com)
        {
            std::cout << (*vl.first) << "@" << (vl.second->name) << std::endl;
        }
    }

}

