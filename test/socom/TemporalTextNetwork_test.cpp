#include "gtest/gtest.h"

#include "socom/TemporalTextNetwork.hpp"

TEST(temporal_text_network_test, basic)
{
    auto net = std::make_unique<uu::socom::TemporalTextNetwork>("name");

    ASSERT_EQ(uu::socom::TTNType::PURE, net->type());

    auto actor = net->add_actor("hola");
    net->add_actor("pepe");
    net->add_actor("como estas");

    net->add_actors({"holas", "adioses"});

    std::cout << "Actor name: " << (*actor)->name << std::endl;

}
