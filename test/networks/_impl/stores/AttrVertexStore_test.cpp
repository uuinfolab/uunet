#include "gtest/gtest.h"

#include "networks/_impl/stores/AttrVertexStore.hpp"

TEST(networks_impl_stores_test, AttrVertexStore)
{

    auto store = std::make_unique<uu::net::AttrVertexStore>();

    // AttributeStore's are tested in a dedicated unit test.
    // Here we only test that:
    // (1) attributes are accessible from the vertex store
    // (2) the two stores are connected, that is, vertex removals also affect the attributes.

    auto v = store->add("a vertex");
    store->attr()->add("a1", uu::core::AttributeType::DOUBLE);
    store->attr()->set_double(v, "a1", 3.4);
    EXPECT_EQ(3.4, store->attr()->get_double(v, "a1").value);

    // Propagation

    store->erase(v);
    EXPECT_TRUE(store->attr()->get_double(v, "a1").null);

}

