#include "gtest/gtest.h"

#include "core/objects/Object.hpp"


TEST(core_objects_test, Object)
{

    uu::core::Object o1;
    uu::core::Object o2;

    EXPECT_TRUE(o1 == o1) << "Wrong object equality";
    EXPECT_FALSE(o1 == o2) << "Wrong object equality";
    EXPECT_TRUE(o1 != o2) << "Wrong object disequality";
    EXPECT_FALSE(o1 != o1) << "Wrong object disequality";
    EXPECT_TRUE((o1 < o2) != (o1 > o2)) << "Wrong object less-than";

    // Uncomment to print the object
    // std::cout << o1 << " - " << o1.to_string() << std::endl;
}
