#include "gtest/gtest.h"

#include "core/stores/_impl/SharedPtrSortedRandomSet.hpp"


TEST(core_stores_impl_test, SharedPtrSortedRandomSet_ptr_to_elem)
{

    class Elem :
        public std::enable_shared_from_this<Elem>
    {
      public:
        int id;
        Elem(int id) : id(id) {}
    };

    uu::core::SharedPtrSortedRandomSet<const Elem> set;

    std::shared_ptr<Elem> e1 = std::make_shared<Elem>(1);
    std::shared_ptr<Elem> e2 = std::make_shared<Elem>(2);
    std::shared_ptr<Elem> e3 = std::make_shared<Elem>(3);
    std::shared_ptr<Elem> e4 = std::make_shared<Elem>(4);

    EXPECT_TRUE(set.add(e1))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(e2))
            << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(e3))
            << "Insertion of a new element should return true";
    EXPECT_FALSE(set.add(e2))
            << "Insertion of an already existing element should return false";
    EXPECT_FALSE(set.add(e3.get()))
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

    for (const Elem* el: set)
    {
        EXPECT_TRUE(set.contains(el))
                << "Iterator returns something not in the set";

        number_of_elements++;
    }

    EXPECT_EQ(number_of_elements, (size_t)2)
            << "Iterator does not return the correct number of elements";

}

