#include "gtest/gtest.h"

#include "core/utils/pretty_printing.hpp"
#include "core/olap/datastructures/Cube.hpp"
#include "core/olap/selection/EntryIterator.hpp"
#include "core/olap/selection/IndexIterator.hpp"
#include "core/olap/selection/Set.hpp"


TEST(core_olap_selection_test, EntryIterator)
{
    // @todo make test
    uu::core::Cube<int> c({3,3});

    uu::core::sel::IndexIterator index_it({{0,1,2}, {0,1,2}});
    int i = 0;

    for (auto index: index_it)
    {
        c[index] = i++;
    }

    uu::core::sel::EntryIterator<uu::core::Cube<int>> it(&c, {{1,2}, {0,2}});

    size_t iteration = 0;

    for (auto entry: it)
    {
        if (iteration == 0)
        {
            EXPECT_EQ(entry, 1)
                    << "Wrong index at iteration 0";
        }

        if (iteration == 1)
        {
            EXPECT_EQ(entry, 2)
                    << "Wrong index at iteration 1";
        }

        if (iteration == 2)
        {
            EXPECT_EQ(entry, 7)
                    << "Wrong index at iteration 2";
        }

        if (iteration == 3)
        {
            EXPECT_EQ(entry, 8)
                    << "Wrong index at iteration 3";
        }

        iteration++;
    }

}

