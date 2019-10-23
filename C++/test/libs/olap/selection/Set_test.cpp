#include "gtest/gtest.h"

#include "olap/selection/Set.hpp"
#include "core/exceptions/OutOfBoundsException.hpp"

TEST(core_olap_selection_test, Set)
{

    uu::olap::sel::Set s({1,3});

    EXPECT_THROW(s.eval(3), uu::core::OutOfBoundsException)
            << "Out of bound exception not caught";

    s.eval(5);

    std::vector<size_t> vset = {1, 3};
    std::vector<size_t> res;

    while (s.has_next())
    {
        res.push_back(s.next());
    }

    EXPECT_EQ(vset, res)
            << "Wrong set";

}

