#include "gtest/gtest.h"

#include "core/utils/random.hpp"

TEST(core_utils_random_test, get_k_uniform)
{
    auto vec = uu::core::get_k_uniform(10, 8);
    
    ASSERT_EQ((size_t)8, vec.size());
    
    std::set<size_t> el(vec.begin(), vec.end());
    
    ASSERT_EQ((size_t)8, el.size())
    << "Duplicate elements extracted";
    
}
