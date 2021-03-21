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
#include "operations/flatten.hpp" // flatten_unweighted, flatten_weighted
#include "operations/project.hpp" // project_unweighted
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
    auto e9 = g->edges()->get(v10, v9);
    std::cout << "subdivide(G, (v8-v9), v10): " << uu::net::summary_short(g.get()) << std::endl;
    
    uu::net::edge_contraction(g.get(), e9, "v11");
    std::cout << "contraction(G, (v9-v10), v11): " << uu::net::summary_short(g.get()) << std::endl;
    
    // Multilayer operations (flattening)
    {
        
    auto mlnet = std::make_unique<uu::net::MultilayerNetwork>("net");
    auto l1 = mlnet->layers()->add("l1");
    auto l2 = mlnet->layers()->add("l2");
    
    auto v1 = l1->vertices()->add("v1");
    auto v2 = l1->vertices()->add("v2");
    auto v3 = l1->vertices()->add("v3");
    l2->vertices()->add(v1);
    l2->vertices()->add(v2);
    l2->vertices()->add(v3);
    
    l1->edges()->add(v1, v2);
    l1->edges()->add(v2, v3);
    l2->edges()->add(v2, v3);
    
    std::cout << "ML-Net: " << uu::net::summary_short(mlnet.get()) << std::endl;
    
    auto l = {l1, l2};
    auto lf1 = mlnet->layers()->add("flat");
    uu::net::flatten_unweighted(l.begin(), l.end(), lf1);
    
    std::cout << " - after flattening: " << uu::net::summary_short(mlnet.get()) << std::endl;
    
    auto lf2 = mlnet->layers()->add("w_flat");
    uu::net::make_weighted(lf2);
    uu::net::flatten_weighted(l.begin(), l.end(), lf2);
    
    std::cout << " - after weighted flattening: " << uu::net::summary_short(mlnet.get()) << std::endl;
    
    auto e1 = lf2->edges()->get(v1, v2);
    auto e2 = lf2->edges()->get(v2, v3);
    
    std::cout << " - weight of (v1, v2): " << uu::net::get_weight(lf2, e1) << std::endl;
    std::cout << " - weight of (v1, v2): " << uu::net::get_weight(lf2, e2) << std::endl;
    }

    // Projection
    {
    
    auto mlnet2 = std::make_unique<uu::net::MultilayerNetwork>("net");
    auto l1 = mlnet2->layers()->add("l1");
    auto l2 = mlnet2->layers()->add("l2");
    
    auto v1 = l1->vertices()->add("v1");
    auto v2 = l1->vertices()->add("v2");
    auto v3 = l1->vertices()->add("v3");
    
    auto o1 = l2->vertices()->add("o1");
    auto o2 = l2->vertices()->add("o2");
    
    mlnet2->interlayer_edges()->init(l1, l2);
    mlnet2->interlayer_edges()->add(v1, l1, o1, l2);
    mlnet2->interlayer_edges()->add(v2, l1, o1, l2);
    mlnet2->interlayer_edges()->add(v2, l1, o2, l2);
    mlnet2->interlayer_edges()->add(v3, l1, o2, l2);
    
    std::cout << "ML-Net: " << uu::net::summary_short(mlnet2.get()) << std::endl;
    
    auto lf = mlnet2->layers()->add("flat");
    uu::net::project_unweighted(mlnet2.get(), l2, l1, lf);
    
    std::cout << " - after projection: " << uu::net::summary_short(mlnet2.get()) << std::endl;
    
    }
    
    return 0;
}

