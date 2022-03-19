#include "gtest/gtest.h"

#include "core/utils/string.hpp"

TEST(io_utils_test, string)
{

    std::string s = "An <example> &";

    uu::core::to_upper_case(s);
    EXPECT_EQ(s, "AN <EXAMPLE> &");
    
    uu::core::to_xml(s);
    EXPECT_EQ(s, "AN &lt;EXAMPLE&gt; &amp;");
}
