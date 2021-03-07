#include "networks/Network.hpp" // Network
#include "io/read_network.hpp" // read_network
#include "io/read_multilayer_communities.hpp" // read_network
#include "generation/standard_graphs.hpp" // null_graph, path_graph, cycle_graph, etc.
#include "generation/erdos_renyi.hpp" // erdos_renyi_nm, erdos_renyi_np
#include "generation/EREvolutionModel.hpp"
#include "generation/PAEvolutionModel.hpp"
#include "generation/evolve.hpp"
#include "generation/sample.hpp"
#include "core/utils/names.hpp" // NameIterator
#include "utils/summary.hpp" // summary_short

int
main()
{
    
    // Constructing a network from an empty one
    
    std::string name = "net";
    auto dir = uu::net::EdgeDir::DIRECTED;
    auto und = uu::net::EdgeDir::UNDIRECTED;
    auto loops = uu::net::LoopMode::ALLOWED; // or: DISALLOW
    
    auto g_empty = std::make_unique<uu::net::Network>(name, dir, loops);
    
    auto v1 = g_empty->vertices()->add("v1");
    auto v2 = g_empty->vertices()->add("v2");
    g_empty->edges()->add(v1, v2);
    
    std::cout << "Manually constructed: ";
    std::cout << uu::net::summary_short(g_empty.get()) << std::endl;
    
    // Standard graphs
    
    auto n_5 = uu::net::null_graph(5);
    std::cout << "Null graph: ";
    std::cout << uu::net::summary_short(n_5.get()) << std::endl;
    
    auto p_5 = uu::net::path_graph(5);
    std::cout << "Path graph: ";
    std::cout << uu::net::summary_short(p_5.get()) << std::endl;
    
    auto c_5 = uu::net::cycle_graph(5);
    std::cout << "Cycle graph: ";
    std::cout << uu::net::summary_short(c_5.get()) << std::endl;
    
    auto w_5 = uu::net::wheel_graph(5);
    std::cout << "Wheel graph: ";
    std::cout << uu::net::summary_short(w_5.get()) << std::endl;
    
    auto k_5 = uu::net::complete_graph(5);
    std::cout << "Complete graph: ";
    std::cout << uu::net::summary_short(k_5.get()) << std::endl;
    
    auto k_5_d = uu::net::complete_graph(5, uu::net::EdgeDir::DIRECTED);
    std::cout << "Complete directed graph: ";
    std::cout << uu::net::summary_short(k_5_d.get()) << std::endl;
    
    auto k_3_2 = uu::net::complete_bipartite_graph(3, 2);
    std::cout << "Complete bipartite graph: ";
    std::cout << uu::net::summary_short(k_3_2.get()) << std::endl;
    
    auto k_3_2_d = uu::net::complete_bipartite_graph(3, 2, uu::net::EdgeDir::DIRECTED);
    std::cout << "Complete directed bipartite graph: ";
    std::cout << uu::net::summary_short(k_3_2_d.get()) << std::endl;
    
    // Reading a network from file
    
    const std::string network_file = "data/simple.txt";
    auto g_io = uu::net::read_network(network_file, "G");
    
    std::cout << "From file: ";
    std::cout << uu::net::summary_short(g_io.get()) << std::endl;
    
    // Random graph generation
    
    auto er_nm = uu::net::erdos_renyi_nm(10, 4);
    std::cout << "ER(n, m): " << uu::net::summary_short(er_nm.get()) << std::endl;
    
    auto er_np = uu::net::erdos_renyi_np(10, .2);
    std::cout << "ER(n, p): " << uu::net::summary_short(er_np.get()) << std::endl;

    
    // Coevolution
    
    auto ml = std::make_unique<uu::net::MultilayerNetwork>("ml");
    ml->layers()->add("l1", dir, loops);
    ml->layers()->add("l2", dir, loops);
    for (auto actor: uu::core::NameIterator("A", 100))
    {
        ml->actors()->add(actor); // Provide pool of actors in advance?
    }
    
    
    std::vector<std::string> layer_names = {"l1", "l2"};
    std::vector<double> pr_internal_event = {.8, .5};
    std::vector<double> pr_external_event = {0, .5};
    std::vector<std::vector<double>> dependency = {{0, 1}, {1, 0}};
    std::vector<uu::net::EvolutionModel<uu::net::MultilayerNetwork>*> evolution_model;
    auto pa = std::make_unique<uu::net::PAEvolutionModel<uu::net::MultilayerNetwork>>(3, 2);
    auto er = std::make_unique<uu::net::EREvolutionModel<uu::net::MultilayerNetwork>>(50);
    evolution_model.push_back(pa.get());
    evolution_model.push_back(er.get());
    long num_of_steps = 100;
    
    evolve(ml.get(), layer_names, pr_internal_event, pr_external_event,
           dependency, evolution_model,  num_of_steps);
    
    // Community based
    
    std::vector<uu::net::EdgeDir> dir_v = {und, und};
    std::vector<uu::net::LoopMode> loops_v = {loops, loops};
    auto cml = uu::net::null_multiplex(6, dir_v, loops_v);
    auto com = uu::net::read_multilayer_communities("data/com_ml.txt", cml.get());
    uu::net::sample(cml.get(), com.get(), {.5, .5}, {.01, .01});
    
    return 0;
}

