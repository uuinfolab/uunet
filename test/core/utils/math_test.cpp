#include "gtest/gtest.h"

#include "core/utils/math.hpp"

class core_utils_math_test : public ::testing::Test
{
  protected:

    std::unordered_set<int> hs1;
    std::unordered_set<int> hs2;
    std::unordered_set<int> hs3;
    std::unordered_set<int> hs4;
    std::vector<std::unordered_set<int>> sets;


    void
    SetUp() override
    {
        hs1 = {1, 2, 3, 4, 5};
        hs2 = {3, 4, 5, 6, 7};
        hs3 = {1, 3, 5, 8};
        hs4 = {2, 3, 4, 5};
        sets = {hs1, hs2, hs3};
    }

};

TEST(core_utils_test, math)
{
    std::unordered_set<int> hs1 = {1, 2, 3, 4, 5};
    std::unordered_set<int> hs2 = {3, 4, 5, 6, 7};
    std::unordered_set<int> hs3 = {1, 3, 5, 8};
    std::unordered_set<int> hs4 = {2, 3, 4, 5};
    std::vector<std::unordered_set<int>> sets = {hs1, hs2, hs3};
        
    EXPECT_EQ((size_t)2, uu::core::s_intersection(sets).size());
    EXPECT_EQ((size_t)3, uu::core::s_intersection(hs1, hs2).size());

    EXPECT_EQ((size_t)8, uu::core::s_union(sets).size());
    EXPECT_EQ((size_t)7, uu::core::s_union(hs1, hs2).size());
    
    EXPECT_EQ((double)2/8, uu::core::jaccard_similarity(sets));
    
    EXPECT_EQ(3.5, uu::core::mean(hs4.begin(), hs4.end()));

    EXPECT_EQ(std::sqrt(5.0/4), uu::core::stdev(hs4.begin(), hs4.end()));
    
}
