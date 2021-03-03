#ifndef UU_TEST_CORE_PERSON_H_
#define UU_TEST_CORE_PERSON_H_

/**
 * A class to create objects to test ObjectStore's.
 *
 * Objects to be stored in ObjectStore's must:
 * - define a typedef key_type (the type of the key used to identify the object in the store.
 * - provide a const member function key() returning the key value for the object
 * - inherit from std::enable_shared_from_this
 *
 * Notice that the key is guaranteed to be unique only inside an ObjectStore.
 * Different ObjectStore's can contain different objects with the same key.
 *
 * This specific class model a person, identified by ssn and also having a name.
 */
class
Person :
    public std::enable_shared_from_this<Person>
{
    
  public:
    
    const std::string ssn;
    const std::string name;
    
    typedef std::string key_type;
    key_type key() const {return ssn;}
    
    Person(const std::string& ssn, const std::string& name) : ssn(ssn), name(name) {};
};
        
#endif
