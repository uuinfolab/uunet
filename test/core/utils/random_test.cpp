#include "gtest/gtest.h"

#include "core/utils/random.hpp"

TEST(core_utils_test, random)
{
    auto vec = uu::core::get_k_uniform(10, 8);

    EXPECT_EQ((size_t)8, vec.size());

    std::set<size_t> el(vec.begin(), vec.end());

    EXPECT_EQ((size_t)8, el.size()) << "Duplicate elements selected";

    for (size_t i = 0; i < 10; i++)
    {
        size_t r = uu::core::irand(4);
        EXPECT_TRUE(0 <= r && r < 4);
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        double r = uu::core::drand();
        EXPECT_TRUE(0 <= r && r < 1.0);
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        EXPECT_TRUE(uu::core::test(1));
        EXPECT_FALSE(uu::core::test(0));
    }
    
    std::vector<double> probs = {0,0,0,.2,.8,0};
    for (size_t i = 0; i < 10; i++)
    {
        size_t r = uu::core::test(probs);
        EXPECT_TRUE(r == 3 || r == 4);
    }
}
