#include "gtest/gtest.h"

#include <set>
#include "networks/_impl/stores/VertexStore.hpp"
#include "core/exceptions/NullPtrException.hpp"


TEST(networks_impl_stores_test, VertexStore)
{

    auto vs = std::make_unique<uu::net::VertexStore>();

    // Adding existing vertices (shared_ptr and *)
    auto v1_ = std::make_shared<uu::net::Vertex>("vertex 1");
    auto v1 = vs->add(v1_);

    auto v2_ = std::make_shared<uu::net::Vertex>("vertex 2");
    auto v2 = vs->add(v2_.get());

    // Adding a vertex by name, letting the store create it for us
    auto v3 = vs->add("vertex 3");

    // Size
    EXPECT_EQ(vs->size(), (size_t)3);

    // Null pointers should be caught
    EXPECT_THROW(vs->add(nullptr), uu::core::NullPtrException);

    // No duplicate names: the insertion should fail
    auto null_v = vs->add("vertex 3");
    EXPECT_EQ(nullptr, null_v);

    // Retrieving a vertex
    auto v4 = vs->get("vertex 1");
    EXPECT_EQ(v4, v1);

    // Checking if a vertex belongs to this store
    bool check1 = vs->contains(v1);
    EXPECT_TRUE(check1);

    // Iterators
    std::set<const uu::net::Vertex*> expected = {v1, v2, v3};
    std::set<const uu::net::Vertex*> found;
    auto it = vs->begin();
    found.insert(*it);
    it++;
    found.insert(*it);
    ++it;
    found.insert(*it);
    it++;
    EXPECT_TRUE(it == vs->end());
    EXPECT_EQ(expected, found);

    // Erasing a vertex
    bool check2 = vs->erase(v1);
    EXPECT_TRUE(check2);

    bool check3 = vs->erase(v1);
    EXPECT_FALSE(check3);

}

