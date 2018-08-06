#include "gtest/gtest.h"

#include "net/datastructures/stores/VertexStore.h"
#include "core/exceptions/NullPtrException.h"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class net_datastructures_stores_VertexStore : public ::testing::Test {
protected:
    
    // Some vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1, v2, v3;
    
	virtual void SetUp() {
        v1 = uu::net::Vertex::create("A vertex");
        v2 = uu::net::Vertex::create("A vertex");
        v3 = uu::net::Vertex::create("A vertex");
	}
};


TEST_F(net_datastructures_stores_VertexStore, all_functions) {
    
    std::unique_ptr<uu::net::VertexStore> vs;
    vs = std::make_unique<uu::net::VertexStore>();
    
    // Adding a new vertex
    const uu::net::Vertex* v1_ = vs->add(v1);
    
    // null pointers should be caught
    EXPECT_THROW(vs->add(nullptr), uu::core::NullPtrException)
    << "Should throw an exception when a nullptr is passed";
    
    // No duplicate names: the insertion should fail
    const uu::net::Vertex* v3_ = vs->add(v2);
    EXPECT_EQ(nullptr, v3_)
    << "Adding a vertex with an existing name should return a nullptr";
    
    // Retrieving a vertex
    const uu::net::Vertex* v4_ = vs->get("A vertex");
    EXPECT_EQ(v4_, v1_)
    << "Could not retrieve the vertex";
    
    // Checking if a vertex belongs to this store
    bool check1 = vs->contains(v1_);
    EXPECT_TRUE(check1)
    << "Vertex containment failed";
    
    // Erasing a vertex
    bool check2 = vs->erase(v1_);
    EXPECT_TRUE(check2)
    << "Could not erase vertex";
    bool check3 = vs->erase(v1_);
    EXPECT_FALSE(check3)
    << "Vertex was not deleted";
    
    // Uncomment to print a description of the store
    //std::cout << vs->summary() << std::endl;
}

