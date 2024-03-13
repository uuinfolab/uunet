#include "algoml_test.hpp" // defines the input network

#include "community/mlcpm.hpp"
#include "io/read_multilayer_network.hpp"


TEST_F(community_mlalgo_test, mlcpm)
{
    auto c = uu::net::mlcpm(net.get(), 3, 1);

    for (auto com: *c)
    {
        EXPECT_EQ((size_t) 6, com->size());
    }
    
    // Determinism test
    /*
    std::string test_file_name = "data/test_dup_small.txt";
    auto net = uu::net::read_multilayer_network(test_file_name, "g");
    
    auto c_dup = uu::net::mlcpm(net.get(), 3, 1);
    size_t num_comm = c_dup->size();
    
    size_t num_mistakes = 0;
    for (int i=0; i<100; i++)
    {
        net = uu::net::read_multilayer_network(test_file_name, "g");
        c_dup = uu::net::mlcpm(net.get(), 3, 1);
        if (num_comm != c_dup->size()) num_mistakes++;
    }
    ASSERT_EQ(0, num_mistakes);
    */
}

