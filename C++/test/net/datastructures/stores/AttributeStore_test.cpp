#include "gtest/gtest.h"

#include "net/datastructures/stores/AttributeStore.h"
#include "net/datastructures/stores/Attributes.h"
#include "net/datastructures/stores/Weights.h"
#include "net/datastructures/objects/Vertex.h"
#include "core/exceptions/NullPtrException.h"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class net_datastructures_stores_AttributeStore_test : public ::testing::Test {
protected:
    
    // Some vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1_, v2_, v3_;
    const uu::net::Vertex* v1;
    const uu::net::Vertex* v2;
    const uu::net::Vertex* v3;
    
	virtual void SetUp() {
        v1_ = uu::net::Vertex::create("A vertex");
        v2_ = uu::net::Vertex::create("A vertex");
        v3_ = uu::net::Vertex::create("A vertex");
        
        v1 = v1_.get();
        v2 = v2_.get();
        v3 = v3_.get();
	}
};


TEST_F(net_datastructures_stores_AttributeStore_test, all_functions) {
    
    std::unique_ptr<uu::net::AttributeStore<uu::net::Vertex>> attr;
    attr = std::make_unique<uu::net::AttributeStore<uu::net::Vertex>>();
    
    // Adding (that is, creating) new attributes
    
    attr->add(uu::core::Attribute::create("name",uu::core::AttributeType::STRING));
    attr->add(uu::core::Attribute::create("#d",uu::core::AttributeType::DOUBLE));
    attr->add(uu::core::Attribute::create("#i",uu::core::AttributeType::INTEGER));
    attr->add(uu::core::Attribute::create("t", uu::core::AttributeType::TIME));
    
    EXPECT_EQ(
        nullptr,
        attr->add(uu::core::Attribute::create("#d",uu::core::AttributeType::STRING))
    ) << "Duplicate attribute insertion";
     
     // Setting values
    
     attr->set_string(v1, "name", "Gonzo");
     attr->set_as_string(v2, "name", "Kermit");
     attr->set_double(v1, "#d",37.4);
     attr->set_as_string(v2, "#d", "37.2");
     attr->set_int(v1, "#i",37);
     attr->set_as_string(v2, "#i", "39");
     attr->set_time(v1, "t", uu::core::epoch_to_time(1234));
    
    // Retrieving values
    
     EXPECT_EQ(attr->get_as_string(v1,"name").value, "Gonzo")
     << "Could not retrieve correct value for attribute name";
    EXPECT_EQ(attr->get_as_string(v2,"name").value, "Kermit")
    << "Could not retrieve correct value for attribute name";
    
     EXPECT_EQ(attr->get_as_string(v1,"#d").value, "37.4")
     << "Could not retrieve correct value for attribute #d";
     EXPECT_EQ(attr->get_double(v2,"#d").value,37.2)
     << "Could not retrieve correct value for attribute #d";
    
     EXPECT_EQ(attr->get_as_string(v1,"#i").value, "37")
     << "Could not retrieve correct value for attribute #i";
     EXPECT_EQ(attr->get_as_string(v2,"#i").value, "39")
     << "Could not retrieve correct value for attribute #i";
    
     EXPECT_EQ(attr->get_time(v1,"t").value, uu::core::epoch_to_time(1234))
     << "Could not retrieve correct value for attribute time";
     
     EXPECT_TRUE(attr->get_as_string(v2,"t").null)
     << "Could not retrieve null value";
    
    attr->notify_erase(v1);
    EXPECT_TRUE(attr->get_as_string(v1,"name").null)
    << "Could not erase attributes after notification of erased object";
    
     EXPECT_EQ(4,attr->size())
     << "Could not retrieve list of attributes";
    
}

