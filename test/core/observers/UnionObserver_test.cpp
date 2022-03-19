#include "gtest/gtest.h"

#include "core/observers/UnionObserver.hpp"
#include "core/stores/ObjectStore.hpp"
#include "../Person.hpp"

TEST(core_observers_test, UnionObserver)
{

    
    auto p1 = std::make_shared<Person>("0001", "Alice");
    auto p2 = std::make_shared<Person>("0002", "Hatter");

    uu::core::ObjectStore<Person> store1;
    uu::core::ObjectStore<Person> store2;
    uu::core::ObjectStore<Person> union_store;

    uu::core::UnionObserver<uu::core::ObjectStore<Person>> obs(&union_store);
    store1.attach(&obs);
    store2.attach(&obs);

    EXPECT_EQ(union_store.size(), (size_t)0);

    store1.add(p1);
    EXPECT_EQ(union_store.size(), (size_t)1);
    store1.add(p2);
    EXPECT_EQ(union_store.size(), (size_t)2);
    store2.add(p1);
    EXPECT_EQ(union_store.size(), (size_t)2);
    store1.erase(p2.get());
    EXPECT_EQ(union_store.size(), (size_t)1);
    store1.erase(p1.get());
    EXPECT_EQ(union_store.size(), (size_t)1);
    store2.erase(p1.get());
    EXPECT_EQ(union_store.size(), (size_t)0);
    store1.add(p2);
    EXPECT_EQ(union_store.size(), (size_t)1);
}


