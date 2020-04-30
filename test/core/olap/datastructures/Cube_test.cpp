#include "gtest/gtest.h"

#include "core/olap/datastructures/Cube.hpp"


TEST(core_olap_test, Cube)
{

    uu::core::Cube<int> c({5,2});

    std::vector<size_t> index1 = {0,0};
    c[index1] = 1;
    std::vector<size_t> index2 = {1,1};
    c[index2] = 2;

    EXPECT_EQ(c[index2], 2)
            << "Could not retrieve previously inserted element";

    size_t pos = 0;

    for (auto entry: c)
    {
        if (pos == 0)
        {
            EXPECT_EQ(entry, 1)
                    << "Could not retrieve previously inserted element with iterator (index [0,0])";
        }

        if (pos == 6)
        {
            EXPECT_EQ(entry, 2)
                    << "Could not retrieve previously inserted element with iterator (index [2,2])";
        }

        pos++;
    }

    EXPECT_EQ(c.order(), (size_t)2)
            << "Wrong order";

    auto size = c.size();
    EXPECT_EQ(size.at(0), (size_t)5)
            << "Wrong size, first dimension";
    EXPECT_EQ(size.at(1), (size_t)2)
            << "Wrong size, second dimension";

}
