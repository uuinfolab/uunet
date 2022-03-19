/**
 * Different types of predefined networks
 */

#include "networks/Network.hpp"
#include "networks/MultiNetwork.hpp"
#include "networks/MultilayerNetwork.hpp"
#include "networks/OrderedMultiplexNetwork.hpp"
#include "networks/time.hpp"
#include "core/attributes/conversion.hpp"
#include "networks/weight.hpp"
#include "networks/probability.hpp"

int
main()
{

    auto dir = uu::net::EdgeDir::UNDIRECTED;
    auto und = uu::net::EdgeDir::UNDIRECTED;
    auto loops = uu::net::LoopMode::ALLOWED;
    auto no_loops = uu::net::LoopMode::DISALLOWED;
    
    auto g = std::make_unique<uu::net::Network>("g", und, no_loops);
    auto v1 = g->vertices()->add("v1"); // creating a new vertex v1
    auto v2 = g->vertices()->add("v2");
    g->edges()->add(v1, v2);
    g->edges()->contains(v2, v1); // true
    // g->edges()->add(v1, v1); // throws exception
    
    auto g2 = std::make_unique<uu::net::Network>("g", dir, loops);
    g2->vertices()->add(v1); // adding existing vertex v1
    g2->vertices()->add(v2);
    g2->edges()->add(v1, v2);
    g2->edges()->contains(v2, v1); // false
    g2->edges()->add(v1, v1);
    
    auto mg = std::make_unique<uu::net::MultiNetwork>("g", dir, loops);
    mg->vertices()->add(v1);
    mg->vertices()->add(v2);
    mg->edges()->add(v1, v2);
    mg->edges()->add(v1, v2);
    mg->edges()->get(v1, v2); // returns two edges
    
    auto e = g->edges()->add(v1, v2);
    
    uu::net::make_weighted(g.get());
    uu::net::is_weighted(g.get()); // true
    uu::net::set_weight(g.get(), e, 3.14);
    uu::net::get_weight(g.get(), e); // 3.14
    
    auto t1 = uu::core::epoch_to_time(17438);
    auto t2 = uu::core::epoch_to_time(17468);
    
    uu::net::make_temporal(g.get());
    uu::net::is_temporal(g.get()); // true
    uu::net::add_time(g.get(), e, t1);
    uu::net::add_time(g.get(), e, t2);
    uu::net::get_times(g.get(), e); // returns two times
    
    uu::net::make_probabilistic(g.get());
    uu::net::is_probabilistic(g.get()); // true
    // uu::net::set_prob(g.get(), e, 1.14); // throws exception
    uu::net::set_prob(g.get(), e, .14);
    uu::net::get_prob(g.get(), e); // .14
    
    auto mnet = std::make_unique<uu::net::MultilayerNetwork>("m");
    auto l1 = mnet->layers()->add("l1", dir, loops);
    auto l2 = mnet->layers()->add("l2", und, no_loops);
    
    l1->vertices()->add(v1); // adding existing vertex v1
    l2->vertices()->add(v1);
    // notice: l2->vertices()->add("v1"); would add a different vertex with the same name
    
    mnet->actors(); // {v1}
    
    mnet->interlayer_edges()->init(l1, l2, dir); 
    mnet->interlayer_edges()->add(v1, l1, v1, l2);
    
    return 0;
}

