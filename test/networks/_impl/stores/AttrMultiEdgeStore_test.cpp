#include "gtest/gtest.h"

#include "networks/_impl/stores/AttrMultiEdgeStore.hpp"

TEST(networks_impl_stores_test, AttrMultiEdgeStore)
{

    auto store = std::make_unique<uu::net::AttrMultiEdgeStore>(uu::net::EdgeDir::DIRECTED);

    // AttributeStore's are tested in a dedicated unit test.
    // Here we only test that:
    // (1) attributes are accessible from the store
    // (2) the two stores are connected, that is, edge removals also affects the attributes.

    auto v1_ = std::make_shared<uu::net::Vertex>("vertex 1");
    auto v2_ = std::make_shared<uu::net::Vertex>("vertex 2");
    auto e = store->add(v1_.get(), v2_.get());

    store->attr()->add("a1", uu::core::AttributeType::DOUBLE);

    store->attr()->set_double(e, "a1", 3.4);

    EXPECT_EQ(3.4, store->attr()->get_double(e, "a1").value);

    // Propagation

    store->erase(e);

    EXPECT_TRUE(store->attr()->get_double(e, "a1").null);

}

