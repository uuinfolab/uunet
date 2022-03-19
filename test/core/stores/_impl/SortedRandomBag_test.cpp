#include "gtest/gtest.h"

#include "core/stores/_impl/SortedRandomBag.hpp"


TEST(core_stores_impl_test, SortedRandomBag_integer_key)
{
    uu::core::SortedRandomBag<int> set;

    EXPECT_TRUE(set.add(1))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(2))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(3))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(2))
            << "Insertion of an already existing element should return true";

    EXPECT_EQ(set.dsize(), (size_t)3)
            << "Inserted 3 distinct elements, but dsize != 3";

    EXPECT_EQ(set.size(), (size_t)4)
            << "Inserted 4 elements, but size != 4";

    EXPECT_TRUE(set.contains(3))
            << "contains method cannot find existing element";
    EXPECT_FALSE(set.contains(4))
            << "contains method finds non-existing element";

    EXPECT_EQ(1, set.at(set.index_of(1)))
            << "get_index and get_at_index not aligned";
    EXPECT_EQ(2, set.at(set.index_of(2)))
            << "get_index and get_at_index not aligned";
    EXPECT_EQ(3, set.at(set.index_of(3)))
            << "get_index and get_at_index not aligned";

    set.get_at_random(); // cannot test this, as it is random... :)

    EXPECT_FALSE(set.erase(4))
            << "Erasing a non-existing element should return false";
    EXPECT_TRUE(set.erase(3))
            << "Erasing an existing element should return true";

    EXPECT_EQ(set.size(), (size_t)3)
            << "Inserted 4 elements and erased 1, but size != 3";

    EXPECT_EQ(set.dsize(), (size_t)2)
            << "Inserted 4 elements and erased 1, with a duplicate, but size != 2";

    size_t number_of_elements = 0;

    for (int el: set)
    {
        EXPECT_TRUE(set.contains(el))
                << "Iterator returns something not in the set";

        number_of_elements++;
    }

    EXPECT_EQ(number_of_elements, (size_t)2)
            << "Iterator does not return the correct number of elements";

}


