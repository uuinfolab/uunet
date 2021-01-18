#include "multilayer_community_algorithms_test.hpp"

#include <cstdio>
#include <iostream>

#include "community/glouvain2.hpp"
//#include "utils/summary.hpp"


TEST_F(multilayer_community_algorithms_test, glouvain2)
{

    
    std::cout << net->actors()->size() << std::endl;
    std::cout << net->layers()->get("l1")->vertices()->size() << std::endl;
    
    auto c = uu::net::glouvain2(net.get(), 1.0);

    for (auto com: *c)
    {
        EXPECT_EQ((size_t)6, com->size());
    }

}

