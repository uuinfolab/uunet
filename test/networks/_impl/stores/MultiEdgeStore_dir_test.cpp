#include "gtest/gtest.h"

#include "networks/_impl/stores/MultiEdgeStore.hpp"
#include "core/exceptions/NullPtrException.hpp"


TEST(networks_impl_stores_test, MultiEdgeStore_dir)
{
    std::unique_ptr<uu::net::MultiEdgeStore> store;
    store = std::make_unique<uu::net::MultiEdgeStore>(uu::net::EdgeDir::DIRECTED);

    // Adding new edges

    auto v1_ = std::make_shared<uu::net::Vertex>("vertex 1");
    auto v2_ = std::make_shared<uu::net::Vertex>("vertex 2");
    auto v3_ = std::make_shared<uu::net::Vertex>("vertex 3");
    auto v1 = v1_.get();
    auto v2 = v2_.get();
    auto v3 = v3_.get();

    const uu::net::Edge* e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2);

    const uu::net::Edge* e2 = store->add(v1,v2);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v2);

    const uu::net::Edge* e3 = store->add(v1,v3);
    EXPECT_TRUE(e3->v1 == v1 && e3->v2 == v3);

    const uu::net::Edge* e4 = store->add(v3,v2);
    EXPECT_TRUE(e4->v1 == v3 && e4->v2 == v2);


    // Retrieving existing edges

    auto m_edges = store->get(v1,v2);
    EXPECT_EQ((size_t)2, m_edges.size());

    m_edges = store->get(v2,v1);
    EXPECT_EQ((size_t)0, m_edges.size());

    // Retrieving all edges
    size_t num_edges=0;
    std::unordered_set<const uu::net::Edge*> edges({e1, e2, e3, e4});

    for (auto edge: *store)
    {
        EXPECT_TRUE(edges.count(edge));
        num_edges++;
    }

    EXPECT_EQ((size_t)4, num_edges);
    EXPECT_EQ((size_t)4, store->size());

    // Retrieving neighbors

    auto vertices = store->neighbors(v3, uu::net::EdgeMode::IN);
    EXPECT_EQ((size_t)1, vertices->size());

    vertices = store->neighbors(v3, uu::net::EdgeMode::OUT);
    EXPECT_EQ((size_t)1, vertices->size());

    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices->size());

    // testing directionality

    EXPECT_TRUE(store->is_directed());

    // Erasing an edge

    bool check = store->erase(e1);
    EXPECT_TRUE(check);

    // v3 should still have two neighbors, because of e2

    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices->size());

    check = store->erase(e2);
    EXPECT_TRUE(check);

    check = store->erase(e3);
    EXPECT_TRUE(check);

    // v3 should now only have one neighbor

    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)1, store->size());

    // Erasing a vertex

    store->erase(v3);

    EXPECT_EQ((size_t)0, store->size());

}

