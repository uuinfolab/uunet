#include "gtest/gtest.h"

#include "networks/_impl/stores/SimpleEdgeStore.hpp"
#include "core/exceptions/NullPtrException.hpp"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class net_datastructures_stores_SimpleEdgeStore_test : public ::testing::Test
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



TEST_F(net_datastructures_stores_SimpleEdgeStore_test, directed)
{

    std::unique_ptr<uu::net::SimpleEdgeStore> store;
    store = std::make_unique<uu::net::SimpleEdgeStore>(uu::net::EdgeDir::DIRECTED);

    // Adding new edges

    const uu::net::Edge* e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2)
            << "Could not insert a new edge";

    const uu::net::Edge* e2 = store->add(v1,v3);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v3)
            << "Could not insert a new edge";

    const uu::net::Edge* e3 = store->add(v3,v2);
    EXPECT_TRUE(e3->v1 == v3 && e3->v2 == v2)
            << "Could not insert a new edge";

    // To be used for the following edge-retrieval tasks:
    const uu::net::Edge* e;

    // No duplicates allowed: the insertion should fail
    e = store->add(v1,v2);
    EXPECT_EQ(nullptr, e)
            << "Adding an existing edge should return a nullptr";

    // null pointers should be caught
    EXPECT_THROW(store->add(v1,nullptr), uu::core::NullPtrException)
            << "Should throw an exception when a nullptr is passed";

    // Retrieving an existing edge
    e = store->get(v1,v2);
    EXPECT_EQ(e, e1)
            << "Could not retrieve the edge";

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


    // Uncomment to print a description of the store
    // std::cout << store->summary() << std::endl;
}




TEST_F(net_datastructures_stores_SimpleEdgeStore_test, undirected)
{
    std::unique_ptr<uu::net::SimpleEdgeStore> store;
    store = std::make_unique<uu::net::SimpleEdgeStore>(uu::net::EdgeDir::UNDIRECTED);

    // Adding new edges

    const uu::net::Edge* e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2)
            << "Could not insert a new edge";

    const uu::net::Edge* e2 = store->add(v1,v3);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v3)
            << "Could not insert a new edge";

    const uu::net::Edge* e3 = store->add(v3,v2);
    EXPECT_TRUE(e3->v1 == v3 && e3->v2 == v2)
            << "Could not insert a new edge";

    // To be used for the following edge-retrieval tasks:
    const uu::net::Edge* e;

    // No duplicates allowed: the insertion should fail
    e = store->add(v1,v2);
    EXPECT_EQ(nullptr, e)
            << "Adding an existing edge should return a nullptr";

    // null pointers should be caught
    EXPECT_THROW(store->add(v1,nullptr), uu::core::NullPtrException)
            << "Should throw an exception when a nullptr is passed";

    // Retrieving an existing edge

    e = store->get(v1,v2);
    EXPECT_EQ(e, e1)
            << "Could not retrieve the edge";

    e = store->get(v2,v1);
    EXPECT_EQ(e, e1)
            << "Could not retrieve the edge inverting the two ends";

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

    // Retrieving neighbors and incident edges

    auto vertices = store->neighbors(v3, uu::net::EdgeMode::IN);
    EXPECT_EQ((size_t)2, vertices->size())
            << "Could not retrieve all in-neighbors";
    auto edges = store->incident(v3, uu::net::EdgeMode::IN);
    EXPECT_EQ((size_t)2, edges->size())
            << "Could not retrieve all in-incident edges";


    vertices = store->neighbors(v3, uu::net::EdgeMode::OUT);
    EXPECT_EQ((size_t)2, vertices->size())
            << "Could not retrieve all out-neighbors";
    edges = store->incident(v3, uu::net::EdgeMode::OUT);
    EXPECT_EQ((size_t)2, edges->size())
            << "Could not retrieve all out-incident edges";

    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, vertices->size())
            << "Could not retrieve all neighbors";
    edges = store->incident(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ((size_t)2, edges->size())
            << "Could not retrieve all incident edges";

    // testing directionality

    EXPECT_FALSE(store->is_directed())
            << "Wrong directionality";

    e = store->add(v2,v1);
    EXPECT_EQ(nullptr, e)
            << "Adding an existing edge (with swapped endings) should return a nullptr";

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

    // Uncomment to print a description of the store
    // std::cout << store->summary() << std::endl;

}

