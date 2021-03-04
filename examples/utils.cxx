/**
 * This example provides 
 */

#include "core/stores/ObjectStore.hpp"
#include "core/stores/AttributeStore.hpp"
#include "core/observers/UnionObserver.hpp"
#include "Person.hpp"

int
main()
{
    
    // Creating an ObjectStore
    uu::core::ObjectStore<Person> store;
    
    // Creating some objects (type Person defined in Person.hpp)
    auto p1 = std::make_shared<Person>("0001", "Alice");
    auto p2 = std::make_shared<Person>("0002", "Hatter");
    auto p3 = std::make_shared<Person>("0003", "Rabbit");
    
    // Store manipulation
    store.add(p1.get());
    store.add(p2.get());
    
    store.size(); // 2
    store.contains(p1.get()); // true
    store.contains("0001"); // true
    store.get("0002"); // p2
    store.get_at_random(); // p1 or p2
    store.at(0); // p1 or p2 (the store is a set, its positions are stable if the store is not
                 // modified but the order does not depend on insertion time)
    store.index_of(p1.get()); // 0 or 1
    store.erase(p1.get()); // true
    store.erase("0001"); // false (already erased)
    
    
    // Creating an AttributeStore
    uu::core::AttributeStore<Person> attr;

    // The supported attribute types are in core/attributes/AttributeType.hpp
    
    // simple types provide set and get functions:
    attr.add("A1", uu::core::AttributeType::DOUBLE); // const Attribute*
    attr.set_double(p1.get(), "A1", 3.14); // void
    attr.get_double(p1.get(), "A1"); // object of type Value<double> with field null = false
    attr.get_double(p3.get(), "A1"); // object of type Value<double> with field null = true
    
    // set types provide add and get functions:
    attr.add("A2", uu::core::AttributeType::DOUBLESET); // const Attribute*
    attr.add_double(p2.get(), "A2", 3.14); // void
    attr.get_doubles(p2.get(), "A2"); // object of type std::set<double> with size 1
    attr.get_doubles(p3.get(), "A2"); // object of type std::set<double> with size 0
    
    return 0;
}

