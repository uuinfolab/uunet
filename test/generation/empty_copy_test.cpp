#include "gtest/gtest.h"

#include "generation/empty_copy.hpp"

TEST(net_creation_test, empty_copy)
{
    auto net = std::make_unique<uu::net::Network>("net", uu::net::EdgeDir::DIRECTED, uu::net::LoopMode::DISALLOWED);

    auto copy = uu::net::empty_copy(net.get(), "copy");

    ASSERT_EQ(copy->is_directed(), true);
    ASSERT_EQ(copy->allows_loops(), false);
}

