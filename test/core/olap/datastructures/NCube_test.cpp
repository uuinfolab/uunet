#include "gtest/gtest.h"

#include "core/olap/datastructures/NCube.hpp"


TEST(core_olap_test, NCube)
{

    std::vector<std::string> dimensions = {"d1", "d2"};
    std::vector<std::vector<std::string>> members = {{"m1", "m2", "m3", "m4", "m5"}, {"m1", "m2"}};

    uu::core::NCube<int> c(dimensions, members);

    std::vector<std::string> index1 = {"m1","m1"};
    c[index1] = 1;
    std::vector<std::string> index2 = {"m2","m2"};
    c[index2] = 2;

    EXPECT_EQ(c[index2], 2)
            << "Could not retrieve previously inserted element";

    size_t pos = 0;

    for (auto entry: c)
    {
        if (pos == 0)
        {
            EXPECT_EQ(entry, 1)
                    << "Could not retrieve previously inserted element with iterator (index [m1,m1])";
        }

        if (pos == 6)
        {
            EXPECT_EQ(entry, 2)
                    << "Could not retrieve previously inserted element with iterator (index [m2,m2])";
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

    auto dim = c.dim();
    EXPECT_EQ(dim.at(0), "d1")
            << "Wrong dimension (first)";
    EXPECT_EQ(dim.at(1), "d2")
            << "Wrong dimension (second)";

}

