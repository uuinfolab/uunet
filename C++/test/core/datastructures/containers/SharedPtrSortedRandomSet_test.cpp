#include "gtest/gtest.h"

#include "core/datastructures/containers/SharedPtrSortedRandomSet.h"

struct SharedPtrLT {
    bool operator() (const std::shared_ptr<const int>& x, const int*& y) const {return x.get()<y;}
};

struct SharedPtrEQ {
    bool operator() (const std::shared_ptr<const int>& x, const int*& y) const {return x.get()==y;}
};


TEST(core_datastructures_containers_SharedPtrSortedRandomSet_test, ptr_to_int)
{
    uu::core::SortedRandomSet<std::shared_ptr<const int>> set;
    
    std::shared_ptr<const int> e1 = std::make_shared<const int>(1);
    const int* e1_copy = e1.get();
    std::shared_ptr<const int> e2 = std::make_shared<const int>(2);
    const int* e2_copy = e2.get();
    std::shared_ptr<const int> e3 = std::make_shared<const int>(3);
    const int* e3_copy = e3.get();
    std::shared_ptr<const int> e4 = std::make_shared<const int>(4);
    const int* e4_copy = e4.get();
    
    
    EXPECT_TRUE(set.add(e1))
    << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(e2))
    << "Insertion of a new element should return true";
    EXPECT_TRUE(set.add(e3))
    << "Insertion of a new element should return true";
    EXPECT_FALSE(set.add(e3))
    << "Insertion of an already existing element should return false";
    
    EXPECT_EQ(set.size(), 3)
    << "Inserted 3 elements, but size != 3";
    
    bool res = set.contains<const int*,SharedPtrLT,SharedPtrEQ>(e3_copy);
    EXPECT_TRUE(res)
    << "contains method cannot find existing element";
    res = set.contains<const int*,SharedPtrLT,SharedPtrEQ>(e4_copy);
    EXPECT_FALSE(res)
    << "contains method finds non-existing element";
    
    int idx = set.get_index<const int*,SharedPtrLT,SharedPtrEQ>(e1_copy);
    EXPECT_EQ(e1_copy, set.get_at_index(idx).get())
    << "get_index and get_at_index not aligned";
    idx = set.get_index<const int*,SharedPtrLT,SharedPtrEQ>(e2_copy);
    EXPECT_EQ(e2_copy, set.get_at_index(idx).get())
    << "get_index and get_at_index not aligned";
    idx = set.get_index<const int*,SharedPtrLT,SharedPtrEQ>(e3_copy);
    EXPECT_EQ(e3_copy, set.get_at_index(idx).get())
    << "get_index and get_at_index not aligned";
    
    set.get_at_random().get(); // cannot test this, as it is random... :)
    
    res = set.erase<const int*,SharedPtrLT,SharedPtrEQ>(e4_copy);
    EXPECT_FALSE(res)
    << "Erasing a non-existing element should return false";
    res = set.erase<const int*,SharedPtrLT,SharedPtrEQ>(e2_copy);
    EXPECT_TRUE(res)
    << "Erasing an existing element should return true";
    
    EXPECT_EQ(set.size(), 2)
    << "Inserted 3 elements and erased 1, but size != 2";
    
    size_t number_of_elements = 0;
    for (const std::shared_ptr<const int>& el: set)
    {
        res = set.contains<const int*,SharedPtrLT,SharedPtrEQ>(el.get());
        EXPECT_TRUE(res)
        << "Iterator returns something not in the set";
        
        number_of_elements++;
    }
    
    EXPECT_EQ(number_of_elements, 2)
    << "Iterator does not return the correct number of elements";
    
}


TEST(core_datastructures_containers_SharedPtrSortedRandomSet_test, ptr_to_elem)
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
    
    EXPECT_EQ(set.size(), 3)
    << "Inserted 3 elements, but size != 3";
    
    EXPECT_TRUE(set.contains(e3.get()))
    << "contains method cannot find existing element";
    EXPECT_FALSE(set.contains(e4.get()))
    << "contains method finds non-existing element";
    
    EXPECT_EQ(e1.get(), set.get_at_index(set.get_index(e1.get())))
    << "get_index and get_at_index not aligned";
    EXPECT_EQ(e2.get(), set.get_at_index(set.get_index(e2.get())))
    << "get_index and get_at_index not aligned";
    EXPECT_EQ(e3.get(), set.get_at_index(set.get_index(e3.get())))
    << "get_index and get_at_index not aligned";
    
    set.get_at_random(); // cannot test this, as it is random... :)
    
    EXPECT_FALSE(set.erase(e4.get()))
    << "Erasing a non-existing element should return false";
    EXPECT_TRUE(set.erase(e2.get()))
    << "Erasing an existing element should return true";
    
    EXPECT_EQ(set.size(), 2)
    << "Inserted 3 elements and erased 1, but size != 2";
    
    size_t number_of_elements = 0;
    for (const Elem* el: set)
    {
        EXPECT_TRUE(set.contains(el))
        << "Iterator returns something not in the set";
        
        number_of_elements++;
    }
    
    EXPECT_EQ(number_of_elements, 2)
    << "Iterator does not return the correct number of elements";
    
}

