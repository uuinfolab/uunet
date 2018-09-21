#include "gtest/gtest.h"

#include "xnet/datastructures/graphs/TemporalTextNetwork.h"
#include "core/attributes/conversion.h"


class mnet_datastructures_graphs_TemporalTextNetwork_test : public ::testing::Test
{
  protected:

    virtual void
    SetUp()
    {
    }


};

TEST_F(mnet_datastructures_graphs_TemporalTextNetwork_test, creation)
{

    // Creating an empty multiplex network

    auto net = uu::net::create_temporal_text_network("a text net");

    // Adding messages

    auto m1 = net->messages()->vertices()->add("m1");
    net->messages()->vertices()->attr()->set_text(m1, uu::core::Text("some text..."));

    auto m2 = net->messages()->vertices()->add("m2");
    net->messages()->vertices()->attr()->set_text(m2, uu::core::Text("some other text..."));

    // Adding messages

    auto a1 = net->actors()->vertices()->add("actor1");
    auto a2 = net->actors()->vertices()->add("actor2");
    auto a3 = net->actors()->vertices()->add("actor3");

    // Adding edges

    // ... intra

    net->messages()->edges()->add(m1, m2);

    std::cout << "Message layer: " << std::endl;
    std::cout << net->messages()->summary() << std::endl;

    // ... inter

    net->interlayer_edges()->add(a1, m1);
    net->interlayer_edges()->add(m1, a2);
    net->interlayer_edges()->add(m1, a3);

    net->interlayer_edges()->add(a3, m2);
    auto e = net->interlayer_edges()->add(m2, a1);

    net->interlayer_edges()->attr()->set_time(e, uu::core::to_time("1232423"));

    // Uncomment to print network summary
    std::cout << net->summary() << std::endl;

}

