#include "gtest/gtest.h"

#include "core/attributes/conversion.h"

TEST(core_attributes_conversion_test, to_string)
{
    
    EXPECT_EQ("3", uu::core::to_string(3))
    << "Wrong result: to_string(int)";
    
    EXPECT_EQ("3.2", uu::core::to_string(3.2))
    << "Wrong result: to_string(double)";
    
    EXPECT_EQ("3.2", uu::core::to_string("3.2"))
    << "Wrong result: to_string(string)";
    
    EXPECT_EQ("some text...", uu::core::to_string(uu::core::Text("some text...")))
    << "Wrong result: to_string(text)";
    
    EXPECT_EQ("2536-06-06 16:03:07", uu::core::to_string(uu::core::Time(17874835387)))
    << "Wrong result: to_string(time)";
    
}


TEST(core_attributes_conversion_test, from_string)
{
    
    EXPECT_EQ(3, uu::core::to_int("3"))
    << "Wrong result: to_int";

    EXPECT_EQ(3.2, uu::core::to_double("3.2"))
    << "Wrong result: to_double";
    
    EXPECT_EQ(uu::core::Text("some text..."), uu::core::to_text("some text..."))
    << "Wrong result: to_text";
    
    EXPECT_EQ(uu::core::Time(17874835387), uu::core::to_time("2536-06-06 16:03:07"))
    << "Wrong result: to_time(string)";
    
    EXPECT_EQ(uu::core::Time(17874835387), uu::core::to_time("2536/06/06 16:03:07", "%Y/%m/%d %H:%M:%S"))
    << "Wrong result: to_time(string, format)";
    
}


TEST(core_attributes_conversion_test, epoch_to_time)
{
    
    EXPECT_EQ(uu::core::Time(17874835387), uu::core::epoch_to_time(17874835387))
    << "Wrong result: epoch_to_time(long)";
    
    EXPECT_EQ(uu::core::Time(17874835387), uu::core::epoch_to_time("17874835387"))
    << "Wrong result: epoch_to_time(string)";
    
}
