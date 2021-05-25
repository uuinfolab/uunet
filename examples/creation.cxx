#include "networks/Network.hpp"
#include "io/read_network.hpp"
#include "io/read_multilayer_network.hpp"
#include "io/read_multilayer_communities.hpp"
#include "generation/standard_graphs.hpp" // null_graph, path_graph, cycle_graph, etc.
#include "generation/erdos_renyi.hpp" // erdos_renyi_nm, erdos_renyi_np
#include "generation/ERModel.hpp"
#include "generation/PAModel.hpp"
#include "generation/evolve.hpp"
#include "generation/sample.hpp"
#include "core/utils/NameIterator.hpp"
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
    
    std::cout << "From file (simple): ";
    std::cout << uu::net::summary_short(g_io.get()) << std::endl;
    
    const std::string ml_network_file = "data/aucs.mpx";
    auto m_io = uu::net::read_multilayer_network(ml_network_file, "M");
    
    std::cout << "From file (multilayer): ";
    std::cout << uu::net::summary_short(m_io.get()) << std::endl;
    
    // Random graph generation
    
    auto er_nm = uu::net::erdos_renyi_nm(10000, 5000000);
    std::cout << "ER(n, m): " << uu::net::summary_short(er_nm.get()) << std::endl;
    
    auto er_np = uu::net::erdos_renyi_np(10, .2);
    std::cout << "ER(n, p): " << uu::net::summary_short(er_np.get()) << std::endl;

    
    // Coevolution
    
    auto ml = std::make_unique<uu::net::MultilayerNetwork>("ml");
    ml->layers()->add("l1", dir, loops);
    ml->layers()->add("l2", dir, loops);
    
    std::vector<std::string> layer_names = {"l1", "l2"};
    std::vector<double> pr_internal_event = {.8, .0};
    std::vector<double> pr_external_event = {0, .0};
    std::vector<std::vector<double>> dependency = {{0, 1}, {1, 0}};
    std::vector<uu::net::EvolutionModel<uu::net::MultilayerNetwork>*> evolution_model;
    auto pa = std::make_unique<uu::net::PAModel<uu::net::MultilayerNetwork>>(3, 2);
    auto er = std::make_unique<uu::net::ERModel<uu::net::MultilayerNetwork>>(50);
    evolution_model.push_back(pa.get());
    evolution_model.push_back(er.get());
    size_t num_actors = 100;
    size_t num_of_steps = 100;
    
    evolve(ml.get(), num_actors, layer_names, pr_internal_event, pr_external_event,
           dependency, evolution_model,  num_of_steps);
           
    std::cout << "grown: " << uu::net::summary_short(ml.get()) << std::endl;
    
    // Community based
    
    std::vector<uu::net::EdgeDir> dir_v = {und, und};
    std::vector<uu::net::LoopMode> loops_v = {loops, loops};
    auto cml = uu::net::null_multiplex(6, dir_v, loops_v);
    auto com = uu::net::read_multilayer_communities("data/com_ml.txt", cml.get());
    uu::net::sample(cml.get(), com.get(), {.5, .5}, {.01, .01});
    
    std::cout << "sampled: " << uu::net::summary_short(cml.get()) << std::endl;
    
    return 0;
}

