#include "gtest/gtest.h"

#include "core/attributes/conversion.hpp"

TEST(core_attributes_test, conversion)
{

    EXPECT_EQ("3", uu::core::to_string(3))
            << "Wrong result: to_string(int)";

    EXPECT_EQ("3.2", uu::core::to_string(3.2))
            << "Wrong result: to_string(double)";

    EXPECT_EQ("3.2", uu::core::to_string("3.2"))
            << "Wrong result: to_string(string)";

    EXPECT_EQ("some text...", uu::core::to_string(uu::core::Text("some text...")))
            << "Wrong result: to_string(text)";

    // This depends on how the system decides to print the time zone,
    // so the string result may vary.
    // EXPECT_EQ("1970-01-01 01:01:07", uu::core::to_string(uu::core::epoch_to_time(3667)))
    // << "Wrong result: to_string(time)";

    EXPECT_EQ(3, uu::core::to_int("3"))
            << "Wrong result: to_int";

    EXPECT_EQ(3.2, uu::core::to_double("3.2"))
            << "Wrong result: to_double";

    EXPECT_EQ(uu::core::Text("some text..."), uu::core::to_text("some text..."))
            << "Wrong result: to_text";

    EXPECT_EQ(uu::core::epoch_to_time(3667), uu::core::to_time("1970-01-01 01:01:07+0000"))
            << "Wrong result: to_time(string)";

    EXPECT_EQ(uu::core::epoch_to_time(3667), uu::core::to_time("1970/01/01 01:01:07+0000", "%Y/%m/%d %H:%M:%S%z"))
            << "Wrong result: to_time(string, format)";

    EXPECT_EQ(uu::core::to_time("1970-01-01 01:01:07+0000"), uu::core::epoch_to_time(3667))
            << "Wrong result: epoch_to_time(long)";

    EXPECT_EQ(uu::core::to_time("1970-01-01 01:01:07+0000"), uu::core::epoch_to_time("3667"))
            << "Wrong result: epoch_to_time(string)";

}
