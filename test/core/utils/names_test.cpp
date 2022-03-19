#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "core/utils/NameIterator.hpp"

TEST(io_utils_test, names_iteration)
{

    auto names = uu::core::NameIterator("pre", 5);

    auto it = names.begin();

    auto n0 = *it;
    ASSERT_EQ("pre0", n0);

    auto n1 = *(++it);
    ASSERT_EQ("pre1", n1);

    auto n2 = *(it++);
    ASSERT_EQ("pre1", n2);

    auto n3 = *it;
    ASSERT_EQ("pre2", n3);

    for (size_t i = 0; i < 2; i++)
    {
        it++;
    }

    it++;
    ASSERT_TRUE(it == names.end());

}


TEST(io_utils_test, names_digits)
{

    auto names = uu::core::NameIterator("pre", 11);

    auto it = names.begin();

    auto n0 = *it;
    ASSERT_EQ("pre00", n0);

    for (size_t i = 0; i < 10; i++)
    {
        it++;
    }

    auto n1 = *it;
    ASSERT_EQ("pre10", n1);
}

