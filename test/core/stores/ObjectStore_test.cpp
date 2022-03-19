#include "gtest/gtest.h"

#include "core/stores/ObjectStore.hpp"
#include "../Person.hpp"

TEST(core_stores_test, ObjectStore)
{

    uu::core::ObjectStore<Person> store;
    
    auto p1 = std::make_shared<Person>("0001", "Alice");
    auto p2 = std::make_shared<Person>("0002", "Hatter");
    
    store.add(p1.get());
    store.add(p2.get());
    
    EXPECT_EQ(store.size(), (size_t) 2);
    EXPECT_EQ(store.contains(p1.get()), true);
    EXPECT_EQ(store.contains("0001"), true);
    EXPECT_EQ(store.get("0002"), p2.get());
    auto p = store.get_at_random();
    EXPECT_TRUE(p == p1.get() || p == p2.get());
    p = store.at(0);
    EXPECT_TRUE(p == p1.get() || p == p2.get());
    auto idx = store.index_of(p1.get());
    EXPECT_TRUE(idx == 0 || idx == 1);
    EXPECT_EQ(store.erase(p1.get()), true);
    EXPECT_EQ(store.erase("0001"), false);
    
    auto p3 = std::make_shared<Person>("0002", "Rabbit");
    EXPECT_FALSE(store.add(p3.get()));
    EXPECT_FALSE(store.contains(p3.get()));
    
    auto p4 = std::make_shared<Person>("0003", "Rabbit");
    idx = store.index_of(p4.get());
    EXPECT_TRUE(idx == -1);
    
    store.add(p1.get());
    store.add(p4.get());
    size_t count = 0;
    for (auto obj: store)
    {
        (void)obj;
        count++;
    }
    EXPECT_EQ(count, (size_t) 3);
    
}
