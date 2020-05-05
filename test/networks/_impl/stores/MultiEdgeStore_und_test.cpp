#include "gtest/gtest.h"

#include "networks/_impl/stores/MultiEdgeStore.hpp"
#include "core/exceptions/NullPtrException.hpp"


TEST(networks_impl_stores_test, MultiEdgeStore_und)
{

    std::unique_ptr<uu::net::MultiEdgeStore> store;
    store = std::make_unique<uu::net::MultiEdgeStore>(uu::net::EdgeDir::UNDIRECTED);

    // Adding new edges

    auto v1_ = std::make_shared<uu::net::Vertex>("vertex 1");
    auto v2_ = std::make_shared<uu::net::Vertex>("vertex 2");
    auto v3_ = std::make_shared<uu::net::Vertex>("vertex 3");
    auto v1 = v1_.get();
    auto v2 = v2_.get();
    auto v3 = v3_.get();

    auto e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2);

    auto e2 = store->add(v1,v2);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v2);

    auto e3 = store->add(v1,v3);
    EXPECT_TRUE(e3->v1 == v1 && e3->v2 == v3);

    auto e4 = store->add(v3,v2);
    EXPECT_TRUE(e4->v1 == v3 && e4->v2 == v2);


    // Retrieving existing edges

    auto edges1 = store->get(v1,v2);
    EXPECT_EQ((size_t)2, edges1.size());

    auto edges2 = store->get(v2,v1);
    EXPECT_EQ((size_t)2, edges2.size());

    // Retrieving all edges

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

    auto vertices1 = store->neighbors(v2, uu::net::EdgeMode::IN);
    EXPECT_EQ((size_t)2, vertices1->size());

    auto vertices2 = store->neighbors(v2, uu::net::EdgeMode::OUT);
    EXPECT_EQ((size_t)2, vertices2->size());

    auto vertices3 = store->neighbors(v2, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices3->size());

    // testing directionality

    bool dir = store->is_directed();
    EXPECT_FALSE(dir);

    // Erasing an edge

    bool check = store->erase(e1);
    EXPECT_TRUE(check);

    // v2 should still have two neighbors, because of e2

    auto vertices4 = store->neighbors(v2, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices4->size());


    check = store->erase(e2);
    EXPECT_TRUE(check);

    // v2 should now only have one neighbor

    auto vertices5 = store->neighbors(v2, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)1, vertices5->size());

    // Erasing a vertex

    store->erase(v3);

    size_t s = store->size();
    EXPECT_EQ((size_t)0, s);

    auto edges4 = store->get(v3,v2);
    EXPECT_EQ((size_t)0, edges4.size());

}
