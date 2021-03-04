#include "gtest/gtest.h"

#include "core/stores/_impl/SortedRandomSet.hpp"


TEST(core_stores_impl_test, SortedRandomSet_integer_key)
{
    uu::core::SortedRandomSet<int> set;

    EXPECT_TRUE(set.add(1))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(2))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(3))
            << "Insertion of a new element should return true";
    EXPECT_FALSE(set.add(2))
            << "Insertion of an already existing element should return false";

    EXPECT_EQ(set.size(), (size_t)3)
            << "Inserted 3 elements, but size != 3";

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
    EXPECT_TRUE(set.erase(2))
            << "Erasing an existing element should return true";

    EXPECT_EQ(set.size(), (size_t)2)
            << "Inserted 3 elements and erased 1, but size != 2";

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



TEST(core_stores_impl_test, SortedRandomSet_raw_pointer_key)
{
    uu::core::SortedRandomSet<const int*> set;

    std::unique_ptr<const int> e1 = std::make_unique<const int>(1);
    std::unique_ptr<const int> e2 = std::make_unique<const int>(2);
    std::unique_ptr<const int> e3 = std::make_unique<const int>(3);
    std::unique_ptr<const int> e4 = std::make_unique<const int>(4);
    const int* e3_copy = e3.get();


    EXPECT_TRUE(set.add(e1.get()))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(e2.get()))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(e3.get()))
            << "Insertion of a new element should return true";
    EXPECT_FALSE(set.add(e2.get()))
            << "Insertion of an already existing element should return false";
    EXPECT_FALSE(set.add(e3_copy))
            << "Insertion of an already existing element should return false";

    EXPECT_EQ(set.size(), (size_t)3)
            << "Inserted 3 elements, but size != 3";

    EXPECT_TRUE(set.contains(e3.get()))
            << "contains method cannot find existing element";
    EXPECT_FALSE(set.contains(e4.get()))
            << "contains method finds non-existing element";

    EXPECT_EQ(e1.get(), set.at(set.index_of(e1.get())))
            << "get_index and get_at_index not aligned";
    EXPECT_EQ(e2.get(), set.at(set.index_of(e2.get())))
            << "get_index and get_at_index not aligned";
    EXPECT_EQ(e3.get(), set.at(set.index_of(e3.get())))
            << "get_index and get_at_index not aligned";

    set.get_at_random(); // cannot test this, as it is random... :)

    EXPECT_FALSE(set.erase(e4.get()))
            << "Erasing a non-existing element should return false";
    EXPECT_TRUE(set.erase(e2.get()))
            << "Erasing an existing element should return true";

    EXPECT_EQ(set.size(), (size_t)2)
            << "Inserted 3 elements and erased 1, but size != 2";

    size_t number_of_elements = 0;

    for (const int* el: set)
    {
        EXPECT_TRUE(set.contains(el))
                << "Iterator returns something not in the set";

        number_of_elements++;
    }

    EXPECT_EQ(number_of_elements, (size_t)2)
            << "Iterator does not return the correct number of elements";

}


