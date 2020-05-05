#include "gtest/gtest.h"

#include "networks/_impl/stores/SimpleEdgeStore.hpp"
#include "core/exceptions/NullPtrException.hpp"


TEST(networks_impl_stores_test, SimpleEdgeStore_dir)
{

    auto store = std::make_unique<uu::net::SimpleEdgeStore>(uu::net::EdgeDir::DIRECTED);

    // Adding new edges

    auto v1_ = std::make_shared<uu::net::Vertex>("vertex 1");
    auto v2_ = std::make_shared<uu::net::Vertex>("vertex 2");
    auto v3_ = std::make_shared<uu::net::Vertex>("vertex 3");
    auto v1 = v1_.get();
    auto v2 = v2_.get();
    auto v3 = v3_.get();

    auto e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2);

    auto e2 = store->add(v1,v3);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v3);

    auto e3 = store->add(v3,v2);
    EXPECT_TRUE(e3->v1 == v3 && e3->v2 == v2);

    // Size
    EXPECT_EQ(store->size(), (size_t)3);

    // To be used for the following edge-retrieval tasks:
    const uu::net::Edge* e;

    // No duplicates allowed: the insertion should fail
    e = store->add(v1,v2);
    EXPECT_EQ(nullptr, e);

    // null pointers should be caught
    EXPECT_THROW(store->add(v1,nullptr), uu::core::NullPtrException);

    // Retrieving an existing edge
    e = store->get(v1,v2);
    EXPECT_EQ(e, e1);

    // Retrieving all edges
    size_t num_edges=0;
    std::unordered_set<const uu::net::Edge*> all_edges({e1, e2, e3});

    for (auto edge: *store)
    {
        EXPECT_TRUE(all_edges.count(edge))
                << "Retrieved wrong edge via the iterator";
        num_edges++;
    }

    EXPECT_EQ((size_t)3, num_edges)
            << "Could not retrieve all edges";
    EXPECT_EQ((size_t)3, store->size())
            << "Wrong edge size";


    // Retrieving neighbors & incident edges
    auto vertices = store->neighbors(v3, uu::net::EdgeMode::IN);
    EXPECT_EQ((size_t)1, vertices->size())
            << "Could not retrieve all in-neighbors";
    auto edges = store->incident(v3, uu::net::EdgeMode::IN);
    EXPECT_EQ((size_t)1, edges->size())
            << "Could not retrieve all in-incident edges";

    vertices = store->neighbors(v3, uu::net::EdgeMode::OUT);
    EXPECT_EQ((size_t)1, vertices->size())
            << "Could not retrieve all out-neighbors";
    edges = store->incident(v3, uu::net::EdgeMode::OUT);
    EXPECT_EQ((size_t)1, edges->size())
            << "Could not retrieve all out-incident edges";

    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices->size())
            << "Could not retrieve all neighbors";
    edges = store->incident(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, edges->size())
            << "Could not retrieve all incident edges";

    // testing directionality

    EXPECT_TRUE(store->is_directed())
            << "Wrong directionality";

    e = store->get(v2,v1);
    EXPECT_EQ(nullptr, e)
            << "Inverted edge should not be present in the store";

    // Erasing an edge

    bool check = store->erase(e1);
    EXPECT_TRUE(check)
            << "Could not erase the edge";


    // Erasing a vertex

    store->erase(v3);

    EXPECT_EQ((size_t)0, store->size())
            << "Erase failed";

    e = store->get(v3,v2);
    EXPECT_EQ(nullptr, e)
            << "The edge should no longer be there";

}

