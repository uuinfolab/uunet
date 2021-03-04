#include "gtest/gtest.h"

#include "core/utils/vector.hpp"

TEST(core_utils_test, vector_seq)
{
    std::vector<size_t> vec1 = {2,3,4};
    auto res = uu::core::seq(2,4);
    EXPECT_EQ(vec1, res);

    std::vector<size_t> vec2 = {4,3,2};
    EXPECT_EQ(vec2, uu::core::seq(4,2));

}

TEST(core_utils_test, vector_move)
{
    std::vector<size_t> vec = {1,2,3,4,5};
    std::vector<size_t> vec1 = {1,3,4,5,2};
    std::vector<size_t> vec2 = {5,1,3,4,2};
    std::vector<size_t> vec3 = {1,3,5,4,2};

    uu::core::move(vec,1,4);
    EXPECT_EQ(vec1, vec);
    uu::core::move(vec,3,0);
    EXPECT_EQ(vec2, vec);
    uu::core::move(vec,0,2);
    EXPECT_EQ(vec3, vec);
}


