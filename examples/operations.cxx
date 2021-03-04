/**
 * Basic graph operations.
 */

#include "io/read_network.hpp" // read_network (which includes networks/Network.hpp)
#include "operations/subgraph.hpp" // vertex_induced_subgraph
#include "operations/union.hpp" // graph_union
#include "operations/intersection.hpp" // graph_intersection
#include "operations/complement.hpp" // graph_complement
#include "operations/subdivision.hpp" // edge_subdivision
#include "operations/contraction.hpp" // edge_contraction
#include "utils/summary.hpp" // summary_short

int
main()
{
    
    // Reading a simple graph from file
    const std::string network_file = "data/simple.txt";
    
    auto g = uu::net::read_network(network_file, "simple graph", ',');
    
    std::cout << "G: " << uu::net::summary_short(g.get()) << std::endl;
    
    // Getting some vertices & edges used in the following operations
    
    auto v2 = g->vertices()->get("v2");
    auto v4 = g->vertices()->get("v4");
    auto v5 = g->vertices()->get("v5");
    auto v6 = g->vertices()->get("v6");
    auto v8 = g->vertices()->get("v8");
    auto v9 = g->vertices()->get("v9");

    auto e7 = g->edges()->get(v8, v9);
    
    // Operations
    
    std::vector<const uu::net::Vertex*> vertices = {v2, v4, v5};
    auto g_sub1 = uu::net::vertex_induced_subgraph(g.get(), vertices.begin(), vertices.end());
    std::cout << "G1 = sub(G, {v2, v4, v5}): " << uu::net::summary_short(g_sub1.get()) << std::endl;
    
    std::vector<const uu::net::Vertex*> vertices2 = {v4, v5, v6};
    auto g_sub2 = uu::net::vertex_induced_subgraph(g.get(), vertices2.begin(), vertices2.end());
    std::cout << "G2 = sub(G, {v4, v5, v6}): " << uu::net::summary_short(g_sub2.get()) << std::endl;
    
    auto g_union = uu::net::graph_union(g_sub1.get(), g_sub2.get());
    std::cout << "G3 = G1 union G2: " << uu::net::summary_short(g_union.get()) << std::endl;
    
    auto g_intersection = uu::net::graph_intersection(g_sub1.get(), g_sub2.get());
    std::cout << "G4 = G1 int G2: " << uu::net::summary_short(g_intersection.get()) << std::endl;

    auto g_complement = uu::net::graph_complement(g_sub1.get());
    std::cout << "complement(G1): " << uu::net::summary_short(g_sub1.get()) << std::endl;

    auto v10 = uu::net::edge_subdivision(g.get(), e7, "v10");
    auto e8 = g->edges()->get(v8, v10);
    auto e9 = g->edges()->get(v10, v9);
    std::cout << "subdivide(G, (v8-v9), v10): " << uu::net::summary_short(g.get()) << std::endl;
    
    uu::net::edge_contraction(g.get(), e9, "v11");
    std::cout << "contraction(G, (v9-v10), v11): " << uu::net::summary_short(g.get()) << std::endl;

    return 0;
}

