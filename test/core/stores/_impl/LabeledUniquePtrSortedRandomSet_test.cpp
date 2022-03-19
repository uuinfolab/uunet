#include "gtest/gtest.h"

#include "core/stores/_impl/LabeledUniquePtrSortedRandomSet.hpp"


TEST(core_stores_impl_test, LabeledUniquePtrSortedRandomSet)
{
    class Elem
    {
      public:
        std::string name;
        Elem(std::string name) : name(name) {}
    };

    uu::core::LabeledUniquePtrSortedRandomSet<const Elem> set;

    std::unique_ptr<const Elem> e1 = std::make_unique<Elem>("1");
    const Elem* e1_copy = e1.get();
    std::unique_ptr<const Elem> e2 = std::make_unique<Elem>("2");
    const Elem* e2_copy = e2.get();
    std::unique_ptr<const Elem> e3 = std::make_unique<Elem>("3");
    const Elem* e3_copy = e3.get();
    std::unique_ptr<const Elem> e4 = std::make_unique<Elem>("4");
    const Elem* e4_copy = e4.get();

    EXPECT_TRUE(set.add(std::move(e1)))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(std::move(e2)))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(std::move(e3)))
            << "Insertion of a new element should return true";

    EXPECT_EQ(set.size(), (size_t)3)
            << "Inserted 3 elements, but size != 3";


    EXPECT_TRUE(set.contains(e3_copy))
            << "contains method cannot find existing element";
    EXPECT_FALSE(set.contains(e4_copy))
            << "contains method finds non-existing element";

    EXPECT_EQ(e1_copy, set.at(set.index_of(e1_copy)))
            << "get_index and get_at_index not aligned";
    EXPECT_EQ(e2_copy, set.at(set.index_of(e2_copy)))
            << "get_index and get_at_index not aligned";
    EXPECT_EQ(e3_copy, set.at(set.index_of(e3_copy)))
            << "get_index and get_at_index not aligned";

    set.get_at_random(); // cannot test this, as it is random... :)

    EXPECT_FALSE(set.erase(e4_copy))
            << "Erasing a non-existing element should return false";
    EXPECT_TRUE(set.erase(e2_copy))
            << "Erasing an existing element should return true";

    EXPECT_EQ(set.size(), (size_t)2)
            << "Inserted 3 elements and erased 1, but size != 2";

    size_t number_of_elements = 0;

    for (const Elem* el: set)
    {
        EXPECT_TRUE(set.contains(el))
                << "Iterator returns something not in the set";

        number_of_elements++;
    }

    EXPECT_EQ(number_of_elements, (size_t)2)
            << "Iterator does not return the correct number of elements";

}

