#include "gtest/gtest.h"

#include "net/datastructures/stores/AttrMultiEdgeStore.hpp"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class net_datastructures_stores_AttrMultiEdgeStore_test : public ::testing::Test
{
  protected:

    // Some vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1_;
    const uu::net::Vertex* v1;
    std::shared_ptr<const uu::net::Vertex> v2_;
    const uu::net::Vertex* v2;

    virtual void
    SetUp()
    {
        v1_ = uu::net::Vertex::create("A vertex");
        v2_ = uu::net::Vertex::create("Another vertex");


        v1 = v1_.get();
        v2 = v2_.get();
    }
};


TEST_F(net_datastructures_stores_AttrMultiEdgeStore_test, access_attributes)
{

    auto store = std::make_unique<uu::net::AttrMultiEdgeStore>(uu::net::EdgeDir::DIRECTED);

    // AttributeStore's are tested in a dedicated unit test.
    // Here we only test that:
    // (1) attributes are accessible from the store
    // (2) the two stores are connected, that is, edge removals also affects the attributes.

    const uu::net::Edge* e = store->add(v1,v2);
    store->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    store->attr()->set_double(e, "a1", 3.4);
    EXPECT_EQ(3.4, store->attr()->get_double(e, "a1").value)
            << "Attribute value not set correctly";

    // Propagation
    store->erase(e);
    EXPECT_TRUE(store->attr()->get_double(e, "a1").null)
            << "Vertex removal not propagated to its attributes";

}

