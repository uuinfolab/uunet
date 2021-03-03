#include "gtest/gtest.h"

#include "core/observers/UnionObserver.hpp"
#include "core/stores/ObjectStore.hpp"

TEST(core_olap_impl_test, UnionObserver)
{

    class Obj :
        public std::enable_shared_from_this<Obj>
    {
      public:
        
        int val;
        
        typedef int key_type;
        key_type key() const {return val;};
        
        Obj(int val) : val(val) {}
    };
    auto o1 = std::make_shared<Obj>(1);
    auto o2 = std::make_shared<Obj>(2);

    uu::core::ObjectStore<Obj> store1;
    uu::core::ObjectStore<Obj> store2;
    uu::core::ObjectStore<Obj> union_store;

    uu::core::UnionObserver<uu::core::ObjectStore<Obj>, const Obj> obs(&union_store);
    store1.attach(&obs);
    store2.attach(&obs);

    EXPECT_EQ(union_store.size(), (size_t)0);

    store1.add(o1);
    EXPECT_EQ(union_store.size(), (size_t)1);
    store1.add(o2);
    EXPECT_EQ(union_store.size(), (size_t)2);
    store2.add(o1);
    EXPECT_EQ(union_store.size(), (size_t)2);
    store1.erase(o2.get());
    EXPECT_EQ(union_store.size(), (size_t)1);
    store1.erase(o1.get());
    EXPECT_EQ(union_store.size(), (size_t)1);
    store2.erase(o1.get());
    EXPECT_EQ(union_store.size(), (size_t)0);
    store1.add(o2);
    EXPECT_EQ(union_store.size(), (size_t)1);
}


