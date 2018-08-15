#include "gtest/gtest.h"

#include "net/datastructures/stores/AttributedSimpleEdgeStore.h"
#include "net/datastructures/stores/Attributes.h"
#include "net/datastructures/stores/Weights.h"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class net_datastructures_stores_AttributedSimpleEdgeStore_test : public ::testing::Test
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


TEST_F(net_datastructures_stores_AttributedSimpleEdgeStore_test, access_attributes)
{

    using A = uu::net::Attributes<uu::net::Edge, uu::net::Weights<uu::net::Edge>>;
    std::unique_ptr<A> attr;
    attr = std::make_unique<A>();

    std::unique_ptr<uu::net::AttributedSimpleEdgeStore<A>> store;
    store = std::make_unique<uu::net::AttributedSimpleEdgeStore<A>>(uu::net::EdgeDir::DIRECTED, std::move(attr));

    // AttributeStore's are tested in a dedicated unit test.
    // Here we only test that:
    // (1) attributes are accessible from the store
    // (2) the two stores are connected, that is, edge removals also affects the attributes.

    const uu::net::Edge* e = store->add(v1,v2);
    store->attr()->set_weight(e, 3.4);
    EXPECT_EQ(3.4, store->attr()->get_weight(e).value)
            << "Weight not set correctly";

    // Propagation
    store->erase(e);
    EXPECT_TRUE(store->attr()->get_weight(e).null)
            << "Vertex removal not propagated to its attributes";

}

