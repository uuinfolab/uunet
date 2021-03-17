#include "gtest/gtest.h"

#include "core/utils/Counter.hpp"


TEST(core_utils_test, Counter)
{

    uu::core::Counter<char> c;

    EXPECT_EQ((size_t) 0, c.count('a'))
            << "wrong count of new object";

    c.inc('a');
    EXPECT_EQ((size_t) 1, c.count('a'))
            << "wrong inc function";

    c.set('a',3);
    EXPECT_EQ((size_t) 3, c.count('a'))
            << "wrong set function";

    c.inc('b');
    c.inc('c');
    c.inc('c');
    
    EXPECT_EQ('a', c.max())
            << "wrong max function";

}

