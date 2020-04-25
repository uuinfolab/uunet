#include "gtest/gtest.h"

#include "net/datastructures/stores/MultiEdgeStore.hpp"
#include "core/exceptions/NullPtrException.hpp"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class net_datastructures_stores_MultiEdgeStore_test : public ::testing::Test
{
  protected:

    // Some vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1_, v2_, v3_;
    const uu::net::Vertex* v1;
    const uu::net::Vertex* v2;
    const uu::net::Vertex* v3;

    virtual void
    SetUp()
    {
        v1_ = uu::net::Vertex::create("A vertex 1");
        v2_ = uu::net::Vertex::create("A vertex 2");
        v3_ = uu::net::Vertex::create("A vertex 3");

        v1 = v1_.get();
        v2 = v2_.get();
        v3 = v3_.get();
    }
};


TEST_F(net_datastructures_stores_MultiEdgeStore_test, undirected)
{

    std::unique_ptr<uu::net::MultiEdgeStore> store;
    store = std::make_unique<uu::net::MultiEdgeStore>(uu::net::EdgeDir::UNDIRECTED);

    // Adding new edges

    const uu::net::Edge* e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2)
            << "Could not insert a new edge";

    const uu::net::Edge* e2 = store->add(v1,v2);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v2)
            << "Could not insert a new edge";

    const uu::net::Edge* e3 = store->add(v1,v3);
    EXPECT_TRUE(e3->v1 == v1 && e3->v2 == v3)
            << "Could not insert a new edge";

    const uu::net::Edge* e4 = store->add(v3,v2);
    EXPECT_TRUE(e4->v1 == v3 && e4->v2 == v2)
            << "Could not insert a new edge";


    // Retrieving existing edges

    auto edges1 = store->get(v1,v2);
    EXPECT_EQ((size_t)2, edges1.size())
            << "Could not retrieve all edges among the two vertices";

    auto edges2 = store->get(v2,v1);
    EXPECT_EQ((size_t)2, edges2.size())
            << "Could not retrieve all edges inverting the two ends";

    // Retrieving all edges

    // Retrieving all edges
    size_t num_edges=0;
    std::unordered_set<const uu::net::Edge*> edges({e1, e2, e3, e4});

    for (auto edge: *store)
    {
        EXPECT_TRUE(edges.count(edge))
                << "Retrieved wrong edge via the iterator";
        num_edges++;
    }

    EXPECT_EQ((size_t)4, num_edges)
            << "Could not retrieve all edges";
    EXPECT_EQ((size_t)4, store->size())
            << "Wrong edge size";

    // Retrieving neighbors

    auto vertices1 = store->neighbors(v2, uu::net::EdgeMode::IN);
    EXPECT_EQ((size_t)2, vertices1->size())
            << "Could not retrieve all in-neighbors";

    auto vertices2 = store->neighbors(v2, uu::net::EdgeMode::OUT);
    EXPECT_EQ((size_t)2, vertices2->size())
            << "Could not retrieve all out-neighbors";

    auto vertices3 = store->neighbors(v2, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices3->size())
            << "Could not retrieve all neighbors";

    // testing directionality

    bool dir = store->is_directed();
    EXPECT_FALSE(dir)
            << "Wrong directionality";

    // Erasing an edge

    bool check = store->erase(e1);
    EXPECT_TRUE(check)
            << "Could not erase the edge";

    // v2 should still have two neighbors, because of e2

    auto vertices4 = store->neighbors(v2, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices4->size())
            << "Could not retrieve all neighbors";


    check = store->erase(e2);
    EXPECT_TRUE(check)
            << "Could not erase the second edge";

    // v2 should now only have one neighbor

    auto vertices5 = store->neighbors(v2, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)1, vertices5->size())
            << "Could not retrieve all neighbors";

    // Erasing a vertex

    store->erase(v3);

    size_t s = store->size();
    EXPECT_EQ((size_t)0, s)
            << "Erase failed";

    auto edges4 = store->get(v3,v2);
    EXPECT_EQ((size_t)0, edges4.size())
            << "The edge should no longer be there";

    // Uncomment to print a description of the store
    // std::cout << store->summary() << std::endl;

}

TEST_F(net_datastructures_stores_MultiEdgeStore_test, directed)
{
    std::unique_ptr<uu::net::MultiEdgeStore> store;
    store = std::make_unique<uu::net::MultiEdgeStore>(uu::net::EdgeDir::DIRECTED);

    // Adding new edges

    const uu::net::Edge* e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2)
            << "Could not insert a new edge";

    const uu::net::Edge* e2 = store->add(v1,v2);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v2)
            << "Could not insert a new edge";

    const uu::net::Edge* e3 = store->add(v1,v3);
    EXPECT_TRUE(e3->v1 == v1 && e3->v2 == v3)
            << "Could not insert a new edge";

    const uu::net::Edge* e4 = store->add(v3,v2);
    EXPECT_TRUE(e4->v1 == v3 && e4->v2 == v2)
            << "Could not insert a new edge";


    // Retrieving existing edges

    auto m_edges = store->get(v1,v2);
    EXPECT_EQ((size_t)2, m_edges.size())
            << "Could not retrieve all edges among the two vertices";

    m_edges = store->get(v2,v1);
    EXPECT_EQ((size_t)0, m_edges.size())
            << "Should not retrieve an edge by inverting its endings";

    // Retrieving all edges
    size_t num_edges=0;
    std::unordered_set<const uu::net::Edge*> edges({e1, e2, e3, e4});

    for (auto edge: *store)
    {
        EXPECT_TRUE(edges.count(edge))
                << "Retrieved wrong edge via the iterator";
        num_edges++;
    }

    EXPECT_EQ((size_t)4, num_edges)
            << "Could not retrieve all edges";
    EXPECT_EQ((size_t)4, store->size())
            << "Wrong edge size";

    // Retrieving neighbors

    auto vertices = store->neighbors(v3, uu::net::EdgeMode::IN);
    EXPECT_EQ((size_t)1, vertices->size())
            << "Could not retrieve all in-neighbors";

    vertices = store->neighbors(v3, uu::net::EdgeMode::OUT);
    EXPECT_EQ((size_t)1, vertices->size())
            << "Could not retrieve all out-neighbors";

    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices->size())
            << "Could not retrieve all neighbors";

    // testing directionality

    EXPECT_TRUE(store->is_directed())
            << "Wrong directionality";

    // Erasing an edge

    bool check = store->erase(e1);
    EXPECT_TRUE(check)
            << "Could not erase the edge";

    // v3 should still have two neighbors, because of e2

    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices->size())
            << "Could not retrieve all neighbors";

    check = store->erase(e2);
    EXPECT_TRUE(check)
            << "Could not erase the second edge";

    check = store->erase(e3);
    EXPECT_TRUE(check)
            << "Could not erase the second edge";

    // v3 should now only have one neighbor

    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)1, store->size())
            << "Could not retrieve all neighbors";

    // Erasing a vertex

    store->erase(v3);

    EXPECT_EQ((size_t)0, store->size())
            << "Erase failed";

    // Uncomment to print a description of the store
    // std::cout << store->summary() << std::endl;

}

