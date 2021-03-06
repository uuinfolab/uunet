#include "gtest/gtest.h"

#include "olap/sel//IndexIterator.hpp"

TEST(olap_selection_test, IndexIterator)
{

    uu::net::IndexIterator idx({{1,2},{0,4},{2}});

    std::vector<size_t> vidx2 = {1, 4, 2};
    std::vector<size_t> vidx3 = {2, 4, 2};

    size_t iteration = 0;

    for (auto index: idx)
    {

        if (iteration == 2)
        {
            EXPECT_EQ(vidx2, index)
                    << "Wrong index at iteration 2";
        }


        if (iteration == 3)
        {
            EXPECT_EQ(vidx3, index)
                    << "Wrong index at iteration 3";
        }

        iteration++;

    }


}

