/**
 * This file shows how to create and populate a weighted graph
 * from scratch.
 *
 * History: created on 2018-08-06.
 */

#include "net/datastructures/graphs/WeightedGraph.h"

int main()
{
    
    // Create an empty weighted graph
    
    std::unique_ptr<uu::net::WeightedGraph> g;
    g = uu::net::create_weighted_graph("a graph");
    // You can also set directionality:
    // g = uu::net::create_weighted_graph("a graph", uu::net::EdgeDir::DIRECTED);
    // and allow loops:
    // g = uu::net::create_weighted_graph("a graph", uu::net::EdgeDir::DIRECTED, true);
    
    // Adding vertices
    
    const uu::net::Vertex* v1 = g->vertices()->add("v1");
    const uu::net::Vertex* v2 = g->vertices()->add("v2");
    const uu::net::Vertex* v3 = g->vertices()->add("v3");
    // The pointers are valid at least until when the graph exists.
    // We can also create a vertex separately if needed, and add it to the store:
    // std::shared_ptr<const uu::net::Vertex> v3_;
    // v3_ = uu::net::Vertex::create("v3");
    // const uu::net::Vertex* v3 = g->vertices()->add(v3_);
    
    // Adding edges
    
    const uu::net::Edge* e1 = g->edges()->add(v1, v2);
    const uu::net::Edge* e2 = g->edges()->add(v1, v3);
    // std::shared_ptr<const Vertex> e3_;
    // e3_ = uu::net::Edge::create(v1, v3, uu::net::EdgeDir::DIRECTED)
    // const uu::net::Edge* e3 = g->edges()->add(e3_);
    
    // Setting weights
    
    g->edges()->attr()->set_weight(e1, 3.4);
    
    // Printing the graph
    
    std::cout << g->summary() << std::endl;
    
    std::cout << "VERTICES:" << std::endl;
    for (auto v: *g->vertices())
    {
        std::cout << *v << std::endl;
    }
    
    std::cout << "EDGES:" << std::endl;
    for (auto e: *g->edges())
    {
        std::cout << *e << " w:" << g->edges()->attr()->get_weight(e) << std::endl;
    }
    
    return 0;
}
