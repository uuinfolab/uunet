#include "gtest/gtest.h"

#include "olap/sel//Range.hpp"
#include "core/exceptions/OutOfBoundsException.hpp"

TEST(olap_selection_test, Range)
{

    uu::net::Range r(1,3);

    EXPECT_THROW(r.eval(3), uu::core::OutOfBoundsException)
            << "Out of bound exception not caught";

    r.eval(5);

    std::vector<size_t> vrange = {1, 2, 3};
    std::vector<size_t> res;

    while (r.has_next())
    {
        res.push_back(r.next());
    }

    EXPECT_EQ(vrange, res)
            << "Wrong range";

}


TEST(olap_selection_test, Range_inverse)
{

    uu::net::Range r(3,1);

    EXPECT_THROW(r.eval(3), uu::core::OutOfBoundsException)
            << "Out of bound exception not caught";

    r.eval(5);

    std::vector<size_t> vrange = {3, 2, 1};
    std::vector<size_t> res;

    while (r.has_next())
    {
        res.push_back(r.next());
    }

    EXPECT_EQ(vrange, res)
            << "Wrong range";

}
