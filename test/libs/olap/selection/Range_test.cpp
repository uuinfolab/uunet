#include "gtest/gtest.h"

#include "olap/selection/Range.hpp"
#include "core/exceptions/OutOfBoundsException.hpp"

TEST(core_olap_selection_test, Range)
{

    uu::olap::sel::Range r(1,3);

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


TEST(core_olap_selection_test, Range_inverse)
{

    uu::olap::sel::Range r(3,1);

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
