#include "gtest/gtest.h"
#include "core/exceptions/WrongParameterException.h"
#include "mnet/datastructures/stores/VertexDisjointLayerStore.h"
#include "net/datastructures/graphs/SimpleGraph.h"
//#include "mnet/datastructures/store_creation.h"

/**
 * All the classes tested in this file are not supposed to be used directly,
 * but will be composed together to define more complex structures (graphs, ...).
 */
class MNETStoreTest : public ::testing::Test
{
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

TEST_F(MNETStoreTest, VertexDisjointLayerStore)
{

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


TEST_F(MNETStoreTest, MultilayerEdgeStore)
{
    /*
    std::unique_ptr<uu::net::SimpleMultilayerEdgeStore<2>> store;
    store = uu::net::create_simple_multilayer_edge_store<2>();

    auto e01 = store->get<1,0>();

    std::cout << e01->size() << std::endl;

    try {
        store->get<1,1>();
        EXPECT_TRUE(false) << "did not throw exception";
    } catch (uu::core::WrongParameterException)
    {

    }*/
}

