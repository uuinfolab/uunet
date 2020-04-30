#include "gtest/gtest.h"

#include "stores.hpp"

#include "networks/_impl/stores/VertexStore.hpp"
#include "core/exceptions/NullPtrException.hpp"

TEST_F(net_datastructures_stores, VertexStore)
{

    std::unique_ptr<uu::net::VertexStore> vs;
    vs = std::make_unique<uu::net::VertexStore>();

    // Adding a new vertex
    const uu::net::Vertex* v1_ = vs->add(v1);

    // We can also add a vertex by name, letting the store create it for us
    // This also returns a const uu::net::Vertex* pointing at the newly created vertex
    vs->add("Another vertex name");

    // null pointers should be caught
    EXPECT_THROW(vs->add(nullptr), uu::core::NullPtrException)
            << "Should throw an exception when a nullptr is passed";

    // No duplicate names: the insertion should fail
    const uu::net::Vertex* v3_ = vs->add(v1b);
    EXPECT_EQ(nullptr, v3_)
            << "Adding a vertex with an existing name should return a nullptr";

    // Retrieving a vertex
    const uu::net::Vertex* v4_ = vs->get("vertex 1");
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

