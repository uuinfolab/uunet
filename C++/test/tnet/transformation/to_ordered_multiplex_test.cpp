#include "gtest/gtest.h"

#include "tnet/transformation/to_ordered_multiplex.h"
#include "mnet/community/glouvain.h"

class tnet_transformation_to_ordered_multiplex_test : public ::testing::Test
{
  protected:
    virtual void
    SetUp()
    {
    }

    // virtual void TearDown() {}
};

TEST_F(tnet_transformation_to_ordered_multiplex_test, all_functions)
{

    std::unique_ptr<uu::net::TemporalNetwork> g = uu::net::create_temporal_network("a graph", uu::net::EdgeDir::DIRECTED);

    // Adding vertices
    const uu::net::Vertex* v1 = g->vertices()->add(uu::net::Vertex::create("miao"));
    const uu::net::Vertex* v2 = g->vertices()->add(uu::net::Vertex::create("bau"));
    const uu::net::Vertex* v3 = g->vertices()->add(uu::net::Vertex::create("coucou"));


    // Adding edges
    const uu::net::Edge* e1 = g->edges()->add(uu::net::Edge::create(v1, v2, uu::net::EdgeDir::DIRECTED));
    const uu::net::Edge* e2 = g->edges()->add(uu::net::Edge::create(v1, v3, uu::net::EdgeDir::DIRECTED));
    const uu::net::Edge* e3 = g->edges()->add(uu::net::Edge::create(v1, v2, uu::net::EdgeDir::DIRECTED));
    const uu::net::Edge* e4 = g->edges()->add(uu::net::Edge::create(v1, v3, uu::net::EdgeDir::DIRECTED));


    // Setting/getting weights
    g->edges()->attr()->set_time(e1, uu::core::epoch_to_time(1365));
    g->edges()->attr()->set_time(e2, uu::core::epoch_to_time(1380));
    g->edges()->attr()->set_time(e3, uu::core::epoch_to_time(1395));
    g->edges()->attr()->set_time(e4, uu::core::epoch_to_time(1395));

    auto mpx = uu::net::to_ordered_multiplex(g.get(), 3);

    // Uncomment the following lines to print a summary of the graphs
    std::cout << g->summary() << std::endl;
    std::cout << mpx->summary() << std::endl;

}
