#include "gtest/gtest.h"

#include "core/stores/AttributeStore.hpp"
#include "../Person.hpp"

TEST(core_stores_test, AttributeStore)
{
    // creating an attribute store whose objects are integers
    uu::core::AttributeStore<Person> attr;

    // some objects to associate values to
    auto p1 = std::make_shared<Person>("0001", "Alice");
    auto p2 = std::make_shared<Person>("0002", "Hatter");
    auto p3 = std::make_shared<Person>("0003", "Rabbit");
    auto p4 = std::make_shared<Person>("0004", "Cat");
    
    // a time to be set in the tests
    uu::core::Time t = uu::core::epoch_to_time(10243);
    
    // add attributes
    const uu::core::Attribute *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
    a0 = attr.add(std::make_unique<uu::core::Attribute>("s_att", uu::core::AttributeType::STRING));
    EXPECT_NE(nullptr, a0);
    a1 = attr.add(std::make_unique<uu::core::Attribute>("d_att", uu::core::AttributeType::DOUBLE));
    EXPECT_NE(nullptr, a1);
    a2 = attr.add(std::make_unique<uu::core::Attribute>("i_att", uu::core::AttributeType::INTEGER));
    EXPECT_NE(nullptr, a2);
    a3 = attr.add(std::make_unique<uu::core::Attribute>("t_att", uu::core::AttributeType::TIME));
    EXPECT_NE(nullptr, a3);
    a4 = attr.add(std::make_unique<uu::core::Attribute>("txt_att", uu::core::AttributeType::TEXT));
    EXPECT_NE(nullptr, a4);
    a5 = attr.add(std::make_unique<uu::core::Attribute>("s_satt", uu::core::AttributeType::STRINGSET));
    EXPECT_NE(nullptr, a5);
    a6 = attr.add(std::make_unique<uu::core::Attribute>("d_satt", uu::core::AttributeType::DOUBLESET));
    EXPECT_NE(nullptr, a6);
    a7 = attr.add(std::make_unique<uu::core::Attribute>("i_satt", uu::core::AttributeType::INTEGERSET));
    EXPECT_NE(nullptr, a7);
    a8 = attr.add(std::make_unique<uu::core::Attribute>("t_satt", uu::core::AttributeType::TIMESET));
    EXPECT_NE(nullptr, a8);
    
    // adding attributes that already exist
    EXPECT_EQ(nullptr,
              attr.add(std::make_unique<uu::core::Attribute>("s_att", uu::core::AttributeType::STRING)));

    EXPECT_EQ(nullptr,
              attr.add(std::make_unique<uu::core::Attribute>("s_att", uu::core::AttributeType::INTEGER)));

    // retrieving atttribute
    EXPECT_EQ((size_t) 9,
              attr.size());

    EXPECT_EQ(a1,
              attr.get("d_att"));

    // simple attribtue values

    attr.set_string(p1.get(), "s_att", "a string");
    attr.set_int(p1.get(), "i_att", 0);
    attr.set_double(p1.get(), "d_att", 0.0);
    attr.set_time(p1.get(), "t_att", t);

    EXPECT_EQ(std::string("a string"),
              attr.get_string(p1.get(), "s_att").value);
    EXPECT_EQ(0,
              attr.get_int(p1.get(), "i_att").value);
    EXPECT_EQ(0.0,
              attr.get_double(p1.get(), "d_att").value);
    EXPECT_EQ(uu::core::epoch_to_time(10243),
              attr.get_time(p1.get(), "t_att").value);

    // Exceptions

    EXPECT_THROW(attr.set_string(p1.get(), "w_att", "a value"),
                 uu::core::ElementNotFoundException);

    EXPECT_THROW(attr.get_string(p1.get(), "w_att"),
                 uu::core::ElementNotFoundException);

    // set-based attributes
    
    EXPECT_EQ(attr.get_strings(p1.get(), "s_satt").size(), (size_t) 0);
    EXPECT_EQ(attr.get_ints(p1.get(), "i_satt").size(), (size_t) 0);
    EXPECT_EQ(attr.get_doubles(p1.get(), "d_satt").size(), (size_t) 0);
    EXPECT_EQ(attr.get_times(p1.get(), "t_satt").size(), (size_t) 0);

    attr.add_string(p1.get(), "s_satt", "a string");
    attr.add_int(p1.get(), "i_satt", 0);
    attr.add_double(p1.get(), "d_satt", 0.0);
    attr.add_time(p1.get(), "t_satt", t);

    EXPECT_TRUE(attr.get_strings(p1.get(), "s_satt").count("a string"));
    EXPECT_TRUE(attr.get_ints(p1.get(), "i_satt").count(0));
    EXPECT_TRUE(attr.get_doubles(p1.get(), "d_satt").count(0.0));
    EXPECT_TRUE(attr.get_times(p1.get(), "t_satt").count(t));

    attr.add_string(p1.get(), "s_satt", "a string"); // duplicate
    EXPECT_EQ(attr.get_strings(p1.get(), "s_satt").size(), (size_t) 1);
    attr.add_string(p1.get(), "s_satt", "another string");
    EXPECT_EQ(attr.get_strings(p1.get(), "s_satt").size(), (size_t) 2);


    // Exceptions

    EXPECT_THROW(attr.add_index("s_satt"),
                 uu::core::OperationNotSupportedException);

    EXPECT_THROW(attr.set_as_string(p1.get(), "s_satt", "a string"),
                 uu::core::OperationNotSupportedException);

    // set as string

    attr.set_as_string(p1.get(), "s_att", "a string");
    attr.set_as_string(p1.get(), "i_att", "0");
    attr.set_as_string(p1.get(), "d_att", "0.0");
    attr.set_as_string(p1.get(), "t_att", "2018-01-01 23:12:03 +0000");

    // get as string

    EXPECT_EQ("a string",
              attr.get_as_string(p1.get(), "s_att").value);
    EXPECT_EQ("0",
              attr.get_as_string(p1.get(), "i_att").value);
    EXPECT_EQ("0",
              attr.get_as_string(p1.get(), "d_att").value);

    // Exceptions

    EXPECT_THROW(attr.set_as_string(p1.get(), "w_att", "t"),
                 uu::core::ElementNotFoundException);

    EXPECT_THROW(attr.set_as_string(p1.get(), "i_att", "not an int"),
                 uu::core::WrongFormatException);

    EXPECT_THROW(attr.get_as_string(p1.get(), "w_att"),
                 uu::core::ElementNotFoundException);

    
    // Minimum and maximum values

    attr.set_int(p1.get(), "i_att", 0);
    attr.set_int(p2.get(), "i_att", 1);
    attr.set_int(p3.get(), "i_att", 2);
    attr.set_int(p4.get(), "i_att", 3);

    EXPECT_EQ(0,
              attr.get_min_int("i_att").value);
    EXPECT_EQ(3,
              attr.get_max_int("i_att").value);

    // Exceptions

    EXPECT_THROW(attr.get_min_int("w_att"),
                 uu::core::ElementNotFoundException);

    EXPECT_THROW(attr.get_max_int("w_att"),
                 uu::core::ElementNotFoundException);

    std::vector<const Person*> test = {p2.get(), p3.get()};
    std::vector<const Person*> values = attr.range_query_int("i_att",1,2);
    std::sort(values.begin(), values.end());
    std::sort(test.begin(), test.end());
    EXPECT_TRUE(test == values);

    // Exceptions

    EXPECT_THROW(attr.range_query_int("w_att",1,2),
                 uu::core::ElementNotFoundException);

    // indexing

    EXPECT_TRUE(attr.add_index("i_att"));

    // Index already existing: operation not performed.
    EXPECT_FALSE(attr.add_index("i_att"));

    // Min/Max - the operation should be performed faster than without an index (not tested here)

    EXPECT_EQ(0,
              attr.get_min_int("i_att").value);
    EXPECT_EQ(3,
              attr.get_max_int("i_att").value);

    // Range queries - the operation should be performed faster than without an index (not tested here)

    values = attr.range_query_int("i_att",1,2);
    std::sort(values.begin(), values.end());
    EXPECT_TRUE(test == values);

    // reset values

    attr.set_string(p1.get(), "s_att", "a string");
    attr.set_int(p1.get(), "i_att", 0);
    attr.set_double(p1.get(), "d_att", 0.0);
    attr.set_time(p1.get(), "t_att", t);

    EXPECT_TRUE(attr.reset(p1.get(), "s_att"));
    EXPECT_TRUE(attr.reset(p1.get(), "i_att"));
    EXPECT_TRUE(attr.reset(p1.get(), "d_att"));
    EXPECT_TRUE(attr.reset(p1.get(), "t_att"));


    EXPECT_FALSE(attr.reset(p1.get(), "s_att"));
    EXPECT_FALSE(attr.reset(p1.get(), "i_att"));
    EXPECT_FALSE(attr.reset(p1.get(), "d_att"));
    EXPECT_FALSE(attr.reset(p1.get(), "t_att"));

    EXPECT_TRUE(attr.get_string(p1.get(), "s_att").null);
    EXPECT_TRUE(attr.get_int(p1.get(), "i_att").null);
    EXPECT_TRUE(attr.get_double(p1.get(), "d_att").null);
    EXPECT_TRUE(attr.get_time(p1.get(), "t_att").null);
}

