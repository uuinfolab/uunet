#include "gtest/gtest.h"
#include "core/exceptions/WrongParameterException.h"
#include "mnet/datastructures/VertexDisjointLayerStore.h"
#include "mnet/datastructures/store_creation.h"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class MNETStoreTest : public ::testing::Test {
protected:
    /*
    // Some vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1, v2, v3;
    
	virtual void SetUp() {
        v1 = uu::net::Vertex::create("A vertex");
        v2 = uu::net::Vertex::create("A vertex");
        v3 = uu::net::Vertex::create("A vertex");
	}*/
};

TEST_F(MNETStoreTest, VertexDisjointLayerStore) {
    
    using LS = uu::net::VertexDisjointLayerStore<uu::net::SimpleGraph, uu::net::SimpleGraph>;
    
    std::unique_ptr<uu::net::SimpleGraph> g1 = uu::net::create_simple_graph("g1", uu::net::EdgeDir::DIRECTED);
    std::unique_ptr<uu::net::SimpleGraph> g2 = uu::net::create_simple_graph("g2", uu::net::EdgeDir::DIRECTED);
    //using AV = uu::net::AttributeStore<uu::net::Vertex>;
    //std::unique_ptr<AV> v_attr = std::make_unique<AV>();
    std::unique_ptr<LS> ls;
    ls = std::make_unique<LS>(std::move(g1), std::move(g2));
    
    std::cout << ls->get<0>()->name << std::endl;
    //std::cout << ls->pos("g2") << std::endl;
}


TEST_F(MNETStoreTest, MultilayerEdgeStore) {
    std::unique_ptr<uu::net::SimpleMultilayerEdgeStore<2>> store;
    store = uu::net::create_simple_multilayer_edge_store<2>();
    
    auto e01 = store->get<1,0>();
    
    std::cout << e01->size() << std::endl;
    
    try {
        store->get<1,1>();
        EXPECT_TRUE(false) << "did not throw exception";
    } catch (uu::core::WrongParameterException)
    {
        
    }
}

/*
TEST_F(StoreTest, UndirectedSimpleEdgeStore) {
    using A = uu::net::EmptyAttributeStore<uu::net::Edge>;
    using E = uu::net::UndirectedSimpleEdgeStore<A>;
    
    std::shared_ptr<E> store = E::create();
    
    // Adding new edges
    
    std::shared_ptr<uu::net::Edge> e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2)
    << "Could not insert a new edge";
    
    std::shared_ptr<uu::net::Edge> e2 = store->add(v1,v3);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v3)
    << "Could not insert a new edge";
    
    std::shared_ptr<uu::net::Edge> e3 = store->add(v3,v2);
    EXPECT_TRUE(e3->v1 == v3 && e3->v2 == v2)
    << "Could not insert a new edge";
    
    // To be used for the following edge-retrieval tasks:
    std::shared_ptr<uu::net::Edge> e;
    std::shared_ptr<uu::net::EdgeList> edges;
    std::shared_ptr<uu::net::VertexList> vertices;
    
    // No duplicates allowed: the insertion should fail
    
    e = store->add(v1,v2);
    EXPECT_EQ(nullptr, e)
    << "Adding an existing edge should return a nullptr";
    
    e = store->add(v2,v1);
    EXPECT_EQ(nullptr, e)
    << "Adding an existing edge (with swapped endings) should return a nullptr";
    
    // Retrieving an existing edge
    
    e = store->get(v1,v2);
    EXPECT_EQ(e, e1)
    << "Could not retrieve the edge";
    
    e = store->get(v2,v1);
    EXPECT_EQ(e, e1)
    << "Could not retrieve the edge inverting the two ends";
    
    // Retrieving all edges
    
    edges = store->get_all();
    EXPECT_EQ(3, edges->size())
    << "Could not retrieve all edges";
    
    
    // Retrieving neighbors
    
    vertices = store->neighbors(v3, uu::net::EdgeMode::IN);
    EXPECT_EQ(2, vertices->size())
    << "Could not retrieve all in-neighbors";
    
    vertices = store->neighbors(v3, uu::net::EdgeMode::OUT);
    EXPECT_EQ(2, vertices->size())
    << "Could not retrieve all out-neighbors";
    
    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(2, vertices->size())
    << "Could not retrieve all neighbors";
    
    // testing directionality
    
    EXPECT_FALSE(store->is_directed())
    << "Wrong directionality";
    
    // Erasing an edge
    
    bool check = store->erase(e1);
    EXPECT_TRUE(check)
    << "Could not erase the edge";
    
    check = store->erase(e1);
    EXPECT_FALSE(check)
    << "Erased edge is still present";
    
    // Erasing a vertex
    
    store->erase(v3);
    
    edges = store->get_all();
    EXPECT_EQ(0, edges->size())
    << "Erase failed";
    
    e = store->get(v3,v2);
    EXPECT_EQ(nullptr, e)
    << "The edge should no longer be there";
    
    // Uncomment to print a description of the store
    // std::cout << store->summary() << std::endl;
    
}




TEST_F(StoreTest, UndirectedMultiEdgeStore) {
    
    using EV = uu::net::AttributeStore<uu::net::Edge>;
    std::unique_ptr<EV> e_attr = std::make_unique<EV>();
    std::unique_ptr<uu::net::MultiEdgeStore<EV>> es;
    es = std::make_unique<uu::net::MultiEdgeStore<EV>>(uu::net::EdgeDir::UNDIRECTED, std::move(e_attr));
    
    // Adding new edges
    
    const uu::net::Edge* e1 = es->add(v1.get(),v2.get());
    EXPECT_TRUE(e1->v1 == v1.get() && e1->v2 == v2.get())
    << "Could not insert a new edge";
    
    const uu::net::Edge* e2 = es->add(v1.get(),v2.get());
    EXPECT_TRUE(e2->v1 == v1.get() && e2->v2 == v2.get())
    << "Could not insert a new edge";
    
    const uu::net::Edge* e3 = es->add(v1.get(),v3.get());
    EXPECT_TRUE(e3->v1 == v1.get() && e3->v2 == v3.get())
    << "Could not insert a new edge";
    
    const uu::net::Edge* e4 = es->add(v3.get(),v2.get());
    EXPECT_TRUE(e4->v1 == v3.get() && e4->v2 == v2.get())
    << "Could not insert a new edge";
    
    // To be used for the following edge-retrieval tasks:
    const uu::net::Edge* e;
    
    // Retrieving existing edges
    
    auto edges1 = es->get(v1.get(),v2.get());
    EXPECT_EQ(2, edges1.size())
    << "Could not retrieve all edges among the two vertices";
    
    auto edges2 = es->get(v2.get(),v1.get());
    EXPECT_EQ(2, edges2.size())
    << "Could not retrieve all edges inverting the two ends";
    
    // Retrieving all edges
    
    size_t s = es->size();
    EXPECT_EQ(4, s)
    << "Could not retrieve all edges";
    
    // Retrieving neighbors
    
    auto vertices1 = es->neighbors(v2.get(), uu::net::EdgeMode::IN);
    EXPECT_EQ(2, vertices1.size())
    << "Could not retrieve all in-neighbors";
    
    auto vertices2 = es->neighbors(v2.get(), uu::net::EdgeMode::OUT);
    EXPECT_EQ(2, vertices2.size())
    << "Could not retrieve all out-neighbors";
    
    auto vertices3 = es->neighbors(v2.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ(2, vertices3.size())
    << "Could not retrieve all neighbors";
    
    // testing directionality
    
    bool dir = es->is_directed();
    EXPECT_FALSE(dir)
    << "Wrong directionality";
    
    // Erasing an edge
    
    bool check = es->erase(e1);
    EXPECT_TRUE(check)
    << "Could not erase the edge";
    
    check = es->erase(e1);
    EXPECT_FALSE(check)
    << "Erased edge is still present";
    
    // v2 should still have two neighbors, because of e2
    
    auto vertices4 = es->neighbors(v2.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ(2, vertices4.size())
    << "Could not retrieve all neighbors";
    
    
    check = es->erase(e2);
    EXPECT_TRUE(check)
    << "Could not erase the second edge";
    
    // v2 should now only have one neighbor
    
    auto vertices5 = es->neighbors(v2.get(), uu::net::EdgeMode::INOUT);
    EXPECT_EQ(1, vertices5.size())
    << "Could not retrieve all neighbors";
    
    // Erasing a vertex
    
    es->erase(v3.get());
    
    s = es->size();
    EXPECT_EQ(0, s)
    << "Erase failed";
    
    auto edges4 = es->get(v3.get(),v2.get());
    EXPECT_EQ(0, edges4.size())
    << "The edge should no longer be there";
    
    // Uncomment to print a description of the store
    // std::cout << store->summary() << std::endl;
    
}
*/

/*

TEST_F(StoreTest, DirectedMultiEdgeStore) {
    using A = uu::net::EmptyAttributeStore<uu::net::Edge>;
    using E = uu::net::DirectedMultiEdgeStore<A>;
    
    std::shared_ptr<E> store = E::create();
    
    // Adding new edges
    
    std::shared_ptr<uu::net::Edge> e1 = store->add(v1,v2);
    EXPECT_TRUE(e1->v1 == v1 && e1->v2 == v2)
    << "Could not insert a new edge";
    
    std::shared_ptr<uu::net::Edge> e2 = store->add(v1,v2);
    EXPECT_TRUE(e2->v1 == v1 && e2->v2 == v2)
    << "Could not insert a new edge";
    
    std::shared_ptr<uu::net::Edge> e3 = store->add(v1,v3);
    EXPECT_TRUE(e3->v1 == v1 && e3->v2 == v3)
    << "Could not insert a new edge";
    
    std::shared_ptr<uu::net::Edge> e4 = store->add(v3,v2);
    EXPECT_TRUE(e4->v1 == v3 && e4->v2 == v2)
    << "Could not insert a new edge";
    
    // To be used for the following edge-retrieval tasks:
    std::shared_ptr<uu::net::Edge> e;
    std::shared_ptr<uu::net::EdgeList> edges;
    std::shared_ptr<uu::net::VertexList> vertices;
    
    // Retrieving existing edges
    
    edges = store->get(v1,v2);
    EXPECT_EQ(2, edges->size())
    << "Could not retrieve all edges among the two vertices";
    
    edges = store->get(v2,v1);
    EXPECT_EQ(0, edges->size())
    << "Should not retrieve an edge by inverting its endings";
    
    // Retrieving all edges
    
    edges = store->get_all();
    EXPECT_EQ(4, edges->size())
    << "Could not retrieve all edges";
    
    // Retrieving neighbors
    
    vertices = store->neighbors(v3, uu::net::EdgeMode::IN);
    EXPECT_EQ(1, vertices->size())
    << "Could not retrieve all in-neighbors";
    
    vertices = store->neighbors(v3, uu::net::EdgeMode::OUT);
    EXPECT_EQ(1, vertices->size())
    << "Could not retrieve all out-neighbors";
    
    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(2, vertices->size())
    << "Could not retrieve all neighbors";
    
    // testing directionality
    
    EXPECT_TRUE(store->is_directed())
    << "Wrong directionality";
    
    // Erasing an edge
    
    bool check = store->erase(e1);
    EXPECT_TRUE(check)
    << "Could not erase the edge";
    
    check = store->erase(e1);
    EXPECT_FALSE(check)
    << "Erased edge is still present";
    
    // v3 should still have two neighbors, because of e2
    
    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(2, vertices->size())
    << "Could not retrieve all neighbors";
    
    check = store->erase(e2);
    EXPECT_TRUE(check)
    << "Could not erase the second edge";
    
    check = store->erase(e3);
    EXPECT_TRUE(check)
    << "Could not erase the second edge";
    
    // v3 should now only have one neighbor
    
    vertices = store->neighbors(v3, uu::net::EdgeMode::INOUT);
    EXPECT_EQ(1, vertices->size())
    << "Could not retrieve all neighbors";
    
    // Erasing a vertex
    
    store->erase(v3);
    
    edges = store->get_all();
    EXPECT_EQ(0, edges->size())
    << "Erase failed";
    
    edges = store->get(v3,v2);
    EXPECT_EQ(0, edges->size())
    << "The edge should no longer be there";
    
    // Uncomment to print a description of the store
    // std::cout << store->summary() << std::endl;
    
}


TEST_F(StoreTest, AttributeStore) {
    
    std::shared_ptr<uu::net::AttributeStore<uu::net::Vertex> > attr;
    attr = uu::net::AttributeStore<uu::net::Vertex>::create();
    
    // Vertices to assign values
    
    
    // Adding (that is, creating) new attributes
    
    attr->add("name",uu::core::AttributeType::STRING);
    attr->add("#d",uu::core::AttributeType::DOUBLE);
    attr->add("#i",uu::core::AttributeType::INTEGER);
    attr->add("t", uu::core::AttributeType::TIME);
    
    EXPECT_THROW(
                 attr->add("#d",uu::core::AttributeType::STRING),
                 uu::core::DuplicateElementException)
     << "failed to prevent duplicate attribute insertion";
     
     // Setting values
    
     attr->set_value<std::string>("name",v1,"Gonzo");
     attr->set_as_string("name",v2,"Kermit");
     attr->set_value<double>("#d",v1,37.4);
     attr->set_as_string("#d",v2,"37.2");
     attr->set_value<int>("#i",v1,37);
     attr->set_as_string("#i",v2,"39");
     attr->set_value<uu::core::Time>("t", v1, uu::core::epoch_to_time(1234));
    
    // Retrieving values
    
     EXPECT_EQ(attr->get_as_string("name",v1).value,"Gonzo")
     << "could not retrieve correct value for attribute name";
    EXPECT_EQ(attr->get_as_string("name",v2).value,"Kermit")
    << "could not retrieve correct value for attribute name";
    
     EXPECT_EQ(attr->get_as_string("#d",v1).value,"37.4")
     << "could not retrieve correct value for attribute #d";
     EXPECT_EQ(attr->get_value<double>("#d",v2).value,37.2)
     << "could not retrieve correct value for attribute #d";
    
     EXPECT_EQ(attr->get_as_string("#i",v1).value,"37")
     << "could not retrieve correct value for attribute #i";
     EXPECT_EQ(attr->get_as_string("#i",v2).value,"39")
     << "could not retrieve correct value for attribute #i";
    
     EXPECT_EQ(attr->get_value<uu::core::Time>("t", v1).value, uu::core::epoch_to_time(1234))
     << "could not retrieve correct value for attribute time";
     
     EXPECT_TRUE(attr->get_as_string("t",v2).null)
     << "could not retrieve null value";
    
    attr->notify_erase(v1);
    EXPECT_TRUE(attr->get_as_string("name",v1).null)
    << "could not erase attributes after notification of erased object";
    
     EXPECT_EQ(4,attr->size())
     << "could not retrieve list of attributes";
    
}
*/
