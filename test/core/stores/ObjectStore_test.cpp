#include "gtest/gtest.h"

#include "core/stores/ObjectStore.hpp"
#include "core/objects/NamedObject.hpp"
//#include <map>

TEST(core_stores_test, ObjectStore)
{

    class
    Person :
    //public uu::core::NamedObject,
        public std::enable_shared_from_this<Person>
    {
        
      public:
        
        typedef std::string key_type;
        const key_type key;
        
        const std::string ssn;
        const std::string name;
        
        
        Person(const std::string& ssn, const std::string& name) : key(ssn), ssn(ssn), name(name) {};
    };
        
    //std::map<int, uu::core::ObjectStore<uu::core::NamedObject>> map;

    uu::core::ObjectStore<Person> store;
    
    auto p1 = std::make_shared<Person>("0001", "Alice");
    auto p2 = std::make_shared<Person>("0002", "Hatter");
    //map[0].add(o1_.get());
    //map[0].add(o2_.get());
    store.add(p1.get());
    store.add(p2.get());
    
    store.size(); // 2
    store.contains(p1.get()); // true
    //store.contains("0001"); // true
    store.get("0002"); // p2
    store.get_at_random(); // p1 or p2
    store.at(0); // p1 or p2
    store.index_of(p1.get()); // 0 or 1
    store.erase(p1.get()); // true
    //store.erase("0001"); // false (already erased)
    
    /*
    size_t c = 0;


    for (auto pair: map)
    {
        auto set = pair.second;

        for (auto v: set)
        {
            (void)v;
            c++;
        }
    }

    EXPECT_EQ((size_t)2, c)
            << "First iteration";
    c = 0;

    for (auto pair: map)
    {
        auto set = pair.second;

        for (auto v: set)
        {
            (void)v;
            c++;
        }
    }

    EXPECT_EQ((size_t)2, c)
            << "Second iteration";
*/
}
