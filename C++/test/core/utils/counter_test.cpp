#include "gtest/gtest.h"

#include "core/utils/Counter.h"


TEST(core_utils_Counter_test, all_functions)
{
    
    uu::core::Counter<char> c;
    
    EXPECT_EQ(0, c.count('a'))
    << "wrong count of new object";
    
    c.inc('a');
    EXPECT_EQ(1, c.count('a'))
    << "wrong inc function";
    
    c.set('a',3);
    EXPECT_EQ(3, c.count('a'))
    << "wrong set function";
    
    c.inc('b');
    c.inc('c');
    c.inc('c');
    EXPECT_EQ('a', c.max())
    << "wrong max function";
    
}

