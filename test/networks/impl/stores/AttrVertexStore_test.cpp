#include "gtest/gtest.h"

#include "networks/_impl/stores/AttrVertexStore.hpp"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class net_datastructures_stores_AttrVertexStore_test : public ::testing::Test
{
  protected:

    // Some vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1_;
    const uu::net::Vertex* v1;

    virtual void
    SetUp()
    {
        v1_ = uu::net::Vertex::create("A vertex");

        v1 = v1_.get();
    }
};


TEST_F(net_datastructures_stores_AttrVertexStore_test, access_attributes)
{

    auto store = std::make_unique<uu::net::AttrVertexStore>();

    // AttributeStore's are tested in a dedicated unit test.
    // Here we only test that:
    // (1) attributes are accessible from the vertex store
    // (2) the two stores are connected, that is, vertex removals also affects the attributes.

    store->add(v1);
    store->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    store->attr()->set_double(v1, "a1", 3.4);
    EXPECT_EQ(3.4, store->attr()->get_double(v1, "a1").value)
            << "Attribute value not set correctly";

    // Propagation
    store->erase(v1);
    EXPECT_TRUE(store->attr()->get_double(v1, "a1").null)
            << "Vertex removal not propagated to its attributes";

}

