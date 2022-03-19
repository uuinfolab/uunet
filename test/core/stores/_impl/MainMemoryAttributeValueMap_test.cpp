#include "core/stores/_impl/MainMemoryAttributeValueMap.hpp"

#include "gtest/gtest.h"

class core_stores_impl_attr_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::core::AttributeValueMap<int>> att_store;
    const uu::core::Attribute *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
    int id0=0, id1=1, id2=2, id3=3;
    virtual void
    SetUp()
    {
        att_store = std::make_unique<uu::core::MainMemoryAttributeValueMap<int>>();

        // add attributes
        a0 = att_store->add(std::make_unique<uu::core::Attribute>("s_att", uu::core::AttributeType::STRING));
        a1 = att_store->add(std::make_unique<uu::core::Attribute>("d_att", uu::core::AttributeType::DOUBLE));
        a2 = att_store->add(std::make_unique<uu::core::Attribute>("i_att", uu::core::AttributeType::INTEGER));
        a3 = att_store->add(std::make_unique<uu::core::Attribute>("t_att", uu::core::AttributeType::TIME));
        a4 = att_store->add(std::make_unique<uu::core::Attribute>("txt_att", uu::core::AttributeType::TEXT));
        a5 = att_store->add(std::make_unique<uu::core::Attribute>("s_satt", uu::core::AttributeType::STRINGSET));
        a6 = att_store->add(std::make_unique<uu::core::Attribute>("d_satt", uu::core::AttributeType::DOUBLESET));
        a7 = att_store->add(std::make_unique<uu::core::Attribute>("i_satt", uu::core::AttributeType::INTEGERSET));
        a8 = att_store->add(std::make_unique<uu::core::Attribute>("t_satt", uu::core::AttributeType::TIMESET));
    }
};

TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_add_attributes)
{
    // Trying to add attributes that already exist.
    EXPECT_EQ(nullptr,
              att_store->add(std::make_unique<uu::core::Attribute>("s_att", uu::core::AttributeType::STRING)));

    EXPECT_EQ(nullptr,
              att_store->add(std::make_unique<uu::core::Attribute>("s_att", uu::core::AttributeType::INTEGER)));
}

TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_get_attributes)
{
    EXPECT_EQ((size_t) 9,
              att_store->size());

    EXPECT_EQ(a1,
              att_store->get("d_att"));

}

TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_set_get)
{
    // Set values

    att_store->set_string(id0, "s_att", "a string");
    att_store->set_int(id0, "i_att", 0);
    att_store->set_double(id0, "d_att", 0.0);
    uu::core::Time t = uu::core::epoch_to_time(10243);
    att_store->set_time(id0, "t_att", t);

    // Get values
    EXPECT_EQ(std::string("a string"),
              att_store->get_string(id0, "s_att").value);
    EXPECT_EQ(0,
              att_store->get_int(id0, "i_att").value);
    EXPECT_EQ(0.0,
              att_store->get_double(id0, "d_att").value);
    EXPECT_EQ(uu::core::epoch_to_time(10243),
              att_store->get_time(id0, "t_att").value);

    // Exceptions

    EXPECT_THROW(att_store->set_string(id0, "w_att", "a value"),
                 uu::core::ElementNotFoundException);

    EXPECT_THROW(att_store->get_string(id0, "w_att"),
                 uu::core::ElementNotFoundException);

}


TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_add_get)
{
    // No results
    EXPECT_EQ(att_store->get_strings(id0, "s_satt").size(), (size_t) 0);
    EXPECT_EQ(att_store->get_ints(id0, "i_satt").size(), (size_t) 0);
    EXPECT_EQ(att_store->get_doubles(id0, "d_satt").size(), (size_t) 0);
    EXPECT_EQ(att_store->get_times(id0, "t_satt").size(), (size_t) 0);

    // Add first value
    att_store->add_string(id0, "s_satt", "a string");
    att_store->add_int(id0, "i_satt", 0);
    att_store->add_double(id0, "d_satt", 0.0);
    uu::core::Time t = uu::core::epoch_to_time(10243);
    att_store->add_time(id0, "t_satt", t);

    // Get values
    EXPECT_TRUE(att_store->get_strings(id0, "s_satt").count("a string"));
    EXPECT_TRUE(att_store->get_ints(id0, "i_satt").count(0));
    EXPECT_TRUE(att_store->get_doubles(id0, "d_satt").count(0.0));
    EXPECT_TRUE(att_store->get_times(id0, "t_satt").count(t));

    // More values
    att_store->add_string(id0, "s_satt", "a string"); // duplicate
    EXPECT_EQ(att_store->get_strings(id0, "s_satt").size(), (size_t) 1);
    att_store->add_string(id0, "s_satt", "another string");
    EXPECT_EQ(att_store->get_strings(id0, "s_satt").size(), (size_t) 2);


    // Exceptions

    EXPECT_THROW(att_store->add_index("s_satt"),
                 uu::core::OperationNotSupportedException);

    EXPECT_THROW(att_store->set_as_string(id0, "s_satt", "a string"),
                 uu::core::OperationNotSupportedException);

}


TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_set_get_as_string)
{
    // Set as string

    att_store->set_as_string(id0, "s_att", "a string");
    att_store->set_as_string(id0, "i_att", "0");
    att_store->set_as_string(id0, "d_att", "0.0");
    att_store->set_as_string(id0, "t_att", "2018-01-01 23:12:03 +0000");

    // Get as string

    EXPECT_EQ("a string",
              att_store->get_as_string(id0, "s_att").value);
    EXPECT_EQ("0",
              att_store->get_as_string(id0, "i_att").value);
    EXPECT_EQ("0",
              att_store->get_as_string(id0, "d_att").value);

    // The result depends on the locale
    // EXPECT_EQ("2018-01-01 23:12:03 +0000",
    //          att_store->get_as_string(id0, "t_att").value);

    // Exceptions

    EXPECT_THROW(att_store->set_as_string(id0, "w_att", "t"),
                 uu::core::ElementNotFoundException);

    EXPECT_THROW(att_store->set_as_string(id0, "i_att", "not an int"),
                 uu::core::WrongFormatException);

    EXPECT_THROW(att_store->get_as_string(id0, "w_att"),
                 uu::core::ElementNotFoundException);
}

TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_min_max)
{
    // Set values

    att_store->set_int(id0, "i_att", 0);
    att_store->set_int(id1, "i_att", 1);
    att_store->set_int(id2, "i_att", 2);
    att_store->set_int(id3, "i_att", 3);

    // Min/Max

    EXPECT_EQ(0,
              att_store->get_min_int("i_att").value);
    EXPECT_EQ(3,
              att_store->get_max_int("i_att").value);

    // Exceptions

    EXPECT_THROW(att_store->get_min_int("w_att"),
                 uu::core::ElementNotFoundException);

    EXPECT_THROW(att_store->get_max_int("w_att"),
                 uu::core::ElementNotFoundException);

}


TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_range_queries)
{
    // Set values

    att_store->set_int(id0, "i_att", 0);
    att_store->set_int(id1, "i_att", 1);
    att_store->set_int(id2, "i_att", 2);
    att_store->set_int(id3, "i_att", 3);

    // Range queries

    std::vector<int> test = {id1, id2};
    std::vector<int> values = att_store->range_query_int("i_att",1,2);
    std::sort(values.begin(), values.end());
    EXPECT_TRUE(test == values);

    // Exceptions

    EXPECT_THROW(att_store->range_query_int("w_att",1,2),
                 uu::core::ElementNotFoundException);

}


TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_indexing)
{
    att_store->set_int(id0, "i_att", 0);
    att_store->set_int(id1, "i_att", 1);
    att_store->set_int(id2, "i_att", 2);
    att_store->set_int(id3, "i_att", 3);

    EXPECT_TRUE(att_store->add_index("i_att"));

    // Index already existing: operation not performed.
    EXPECT_FALSE(att_store->add_index("i_att"));

    // Min/Max - the operation should be performed faster than without an index (not tested here)

    EXPECT_EQ(0,
              att_store->get_min_int("i_att").value);
    EXPECT_EQ(3,
              att_store->get_max_int("i_att").value);

    // Range queries - the operation should be performed faster than without an index (not tested here)

    std::vector<int> test = {id1, id2};
    std::vector<int> values = att_store->range_query_int("i_att",1,2);
    EXPECT_TRUE(test == values);

}


TEST_F(core_stores_impl_attr_test, MainMemoryAttributeValueMap_reset)
{
    // Set values

    att_store->set_string(id0, "s_att", "a string");
    att_store->set_int(id0, "i_att", 0);
    att_store->set_double(id0, "d_att", 0.0);
    uu::core::Time t = uu::core::epoch_to_time(10243);
    att_store->set_time(id0, "t_att", t);

    // Erase

    EXPECT_TRUE(att_store->reset(id0, "s_att"));
    EXPECT_TRUE(att_store->reset(id0, "i_att"));
    EXPECT_TRUE(att_store->reset(id0, "d_att"));
    EXPECT_TRUE(att_store->reset(id0, "t_att"));


    EXPECT_FALSE(att_store->reset(id0, "s_att"));
    EXPECT_FALSE(att_store->reset(id0, "i_att"));
    EXPECT_FALSE(att_store->reset(id0, "d_att"));
    EXPECT_FALSE(att_store->reset(id0, "t_att"));

    // Get values

    EXPECT_TRUE(att_store->get_string(id0, "s_att").null);
    EXPECT_TRUE(att_store->get_int(id0, "i_att").null);
    EXPECT_TRUE(att_store->get_double(id0, "d_att").null);
    EXPECT_TRUE(att_store->get_time(id0, "t_att").null);
}

