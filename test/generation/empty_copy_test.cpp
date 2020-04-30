#include "gtest/gtest.h"

#include "generation/empty_copy.hpp"

TEST(net_creation_test, empty_copy)
{
    auto pn = std::make_unique<uu::net::ProbabilisticNetwork>("probnet", uu::net::EdgeDir::DIRECTED, false);

    auto copy = uu::net::empty_copy(pn.get(), "copy");

    ASSERT_EQ(copy->is_directed(), true);
    ASSERT_EQ(copy->allows_loops(), false);
}

