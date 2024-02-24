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
    
    //std::string test_file_name = "data/aucs.mpx";
    std::string test_file_name = "data/test_dup.txt";
    std::cout << "reading " << test_file_name << std::endl;
    auto net = uu::net::read_multilayer_network(test_file_name, "g");
    auto c_dup = uu::net::mlcpm(net.get(), 3, 1);
    std::cout << c->size() << std::endl;
}

