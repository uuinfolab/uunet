#include "gtest/gtest.h"

#include "core/datastructures/objects/NamedObject.hpp"

TEST(core_datastructures_objects_test, NamedObject)
{
    
    auto o1 = uu::core::NamedObject("n");
    auto o2 = uu::core::NamedObject("n");

    EXPECT_TRUE(o1 == o1) << "Wrong object equality";
    EXPECT_FALSE(o1 == o2) << "Wrong object equality";
    EXPECT_TRUE(o1 != o2) << "Wrong object disequality";
    EXPECT_FALSE(o1 != o1) << "Wrong object disequality";
    EXPECT_TRUE((o1 < o2) != (o1 > o2)) << "Wrong object less-than";
    
    EXPECT_TRUE(o1.name == "n") << "Wrong object name";
    
    // Uncomment to print the object
    // std::cout << o1 << " - " << o1.to_string() << std::endl;
}
