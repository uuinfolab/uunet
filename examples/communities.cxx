/**
 * Discovery of communities
 */

#include "community/CommunityStructure.hpp"
#include "community/abacus.hpp"
#include "community/mlcpm.hpp"
#include "community/louvain.hpp"
#include "community/glouvain2.hpp"
#include "community/label_propagation.hpp"
#include "community/mlp.hpp"
#include "community/infomap.hpp"
#include "community/nmi.hpp"
#include "community/modularity.hpp"
#include "community/omega_index.hpp"
#include "measures/order.hpp"
#include "io/read_network.hpp"
#include "io/read_multilayer_network.hpp"

int
main()
{
    auto com = std::make_unique<uu::net::CommunityStructure<uu::net::Network>>();
    
    auto c1 = std::make_unique<uu::net::Community<uu::net::Network>>();
    auto c2 = std::make_unique<uu::net::Community<uu::net::Network>>();
    
    auto v1 = std::make_unique<uu::net::Vertex>("v1");
    auto v2 = std::make_unique<uu::net::Vertex>("v2");
    
    // Adding vertices to the community
    
    c1->add(v1.get());
    c1->add(v2.get());
    c2->add(v2.get());
    
    // Adding communities to the community structure
    
    com->add(std::move(c1));
    com->add(std::move(c2));
    
    // Communities for multilayer networks
    
    auto ml_com = std::make_unique<uu::net::CommunityStructure<uu::net::MultilayerNetwork>>();
    
    auto ml_c = std::make_unique<uu::net::Community<uu::net::MultilayerNetwork>>();
    
    
    // Creating some multilayer vertices
    
    auto n = std::make_unique<uu::net::Network>("net");
    
    auto ml_v1 = uu::net::MLVertex(v1.get(), n.get());
    auto ml_v2 = uu::net::MLVertex(v2.get(), n.get());
    
    // Adding multilayer vertices to the community
    
    ml_c->add(ml_v1);
    ml_c->add(ml_v2);
    
    ml_com->add(std::move(ml_c));
    
    // Reading input networks
    
    auto net = uu::net::read_network("data/simple.txt", "G", ',');
    auto mlnet = uu::net::read_multilayer_network("data/aucs.mpx", "M", ',');
    
    // Algorithms
    auto comm1 = uu::net::label_propagation(net.get());
    auto comm2 = louvain(net.get());
    
    std::cout << "NMI: " << uu::net::nmi(comm1.get(), comm2.get(), uu::net::order(net.get())) << std::endl;
    std::cout << "OI: " << uu::net::omega_index(comm1.get(), comm2.get(), uu::net::order(net.get())) << std::endl;
    
    auto mlcomm1 = uu::net::mlcpm(mlnet.get(), 3, 1);
    auto mlcomm2 = uu::net::abacus(mlnet.get(), 3, 1);
    auto mlcomm3 = uu::net::glouvain2(mlnet.get(), 1.0);
    auto mlcomm4 = uu::net::infomap(mlnet.get());
    auto mlcomm5 = uu::net::mlp(mlnet.get());
    
    
    std::cout << "MOD Louvain: " << uu::net::modularity(mlnet.get(), mlcomm3.get(), 1.0) << std::endl;
    std::cout << "MOD Infomap: " << uu::net::modularity(mlnet.get(), mlcomm4.get(), 1.0) << std::endl;
    std::cout << "MOD MLabPro: " << uu::net::modularity(mlnet.get(), mlcomm5.get(), 1.0) << std::endl;
    
    return 0;
}

