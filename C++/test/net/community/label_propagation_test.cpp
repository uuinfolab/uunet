#include "gtest/gtest.h"

#include "net/community/label_propagation.h"
#include "net/datastructures/graphs/SimpleGraph.h"

class net_community_label_propagation_test : public ::testing::Test
{
  protected:

};

TEST_F(net_community_label_propagation_test, algorithm)
{

    auto net = uu::net::create_simple_graph("g");

    auto v1 = net->vertices()->add("v1");
    auto v2 = net->vertices()->add("v2");
    auto v3 = net->vertices()->add("v3");
    auto v4 = net->vertices()->add("v4");
    auto v5 = net->vertices()->add("v5");
    auto v6 = net->vertices()->add("v6");

    net->edges()->add(v1,v2);
    net->edges()->add(v1,v3);
    net->edges()->add(v3,v2);
    net->edges()->add(v3,v4);
    net->edges()->add(v5,v4);
    net->edges()->add(v6,v4);
    net->edges()->add(v5,v6);

    auto com = uu::net::label_propagation(net.get());

    for (auto c: *com)
    {
        std::cout << "COM" << std::endl;

        for (auto v: *c)
        {
            std::cout << (*v) << std::endl;
        }
    }

}

