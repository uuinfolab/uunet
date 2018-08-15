#include "gtest/gtest.h"

#include "core/utils/math.h"

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

TEST_F(core_utils_math_test, s_intersection)
{
    EXPECT_EQ(2, uu::core::s_intersection(sets).size())
            << "Wrong intersection of multiple sets";
    EXPECT_EQ(3, uu::core::s_intersection(hs1, hs2).size())
            << "Wrong intersection of two sets";
}

TEST_F(core_utils_math_test, s_union)
{
    EXPECT_EQ(8, uu::core::s_union(sets).size())
            << "Wrong union of multiple sets";
    EXPECT_EQ(7, uu::core::s_union(hs1, hs2).size())
            << "Wrong union of two sets";
}


TEST_F(core_utils_math_test, mean)
{
    EXPECT_EQ(3.5, uu::core::mean(hs4.begin(), hs4.end()))
            << "Wrong mean";
}

TEST_F(core_utils_math_test, stdev)
{
    EXPECT_EQ(std::sqrt(5.0/4), uu::core::stdev(hs4.begin(), hs4.end()))
            << "Wrong standard deviation";
}
