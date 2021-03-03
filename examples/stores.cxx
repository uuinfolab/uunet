/**
 * Storing and retrieving objects and attribute values
 */

#include "core/stores/ObjectStore.hpp"
#include "Person.hpp"

int
main()
{
    
    // Creating an ObjectStore
    uu::core::ObjectStore<Person> store;
    
    // Creating some objects (type Person defined in Person.hpp)
    auto p1 = std::make_shared<Person>("0001", "Alice");
    auto p2 = std::make_shared<Person>("0002", "Hatter");
    
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
    
    

    return 0;
}

