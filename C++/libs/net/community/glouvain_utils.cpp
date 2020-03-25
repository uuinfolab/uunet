
#include "net/community/glouvain_utils.hpp"

#include <chrono>
#include <unordered_map>
#include <vector>
#include "community/CommunityStructure.hpp"
#include "community/Community.hpp"
#include "objects/EdgeMode.hpp"
#include "objects/Vertex.hpp"

namespace uu {
namespace net {


std::pair<std::unique_ptr<WeightedNetwork>, std::map<const Vertex*, std::pair<const Vertex*, const Network*>>>
convert(
    const AttributedHomogeneousMultilayerNetwork* g,
        double omega
)
{
    std::map<std::pair<const Vertex*, const Network*>, const Vertex*> mapping;
    std::map<const Vertex*, std::pair<const Vertex*, const Network*>> reverse_mapping;
    std::map<std::pair<const Vertex*, const Network*>, size_t> degrees;
    
    
    auto net = std::make_unique<WeightedNetwork>("w");

    size_t v_id = 0;
    size_t mu = 0;
    
    for (auto l: *g->layers())
    {
        for (auto v: *l->vertices())
        {
            auto metavertex = net->vertices()->add(std::to_string(v_id++));
            auto intralayer_vertex = std::make_pair(v,l);
            mapping[intralayer_vertex] = metavertex;
            reverse_mapping[metavertex] = intralayer_vertex;
            degrees[intralayer_vertex] = l->edges()->neighbors(v)->size();
            std::cout << "adding " << (*v) << "@" << l->name <<
            " as " << (*metavertex) << std::endl;
        }

        for (auto e: *l->edges())
        {
            auto v1 = mapping.at(std::make_pair(e->v1, l));
            auto v2 = mapping.at(std::make_pair(e->v2, l));
            auto edge = net->edges()->add(v1, v2);
            net->set_weight(edge, 1.0);
            mu++;
            
            std::cout << "adding " << (*v1) << "--" << (*v2) << std::endl;
        }
    }
    
    // @todo: ORDERED VERSION
    mu += g->vertices()->size() * g->layers()->size() * (g->layers()->size()-1) / 2; // approximation
    
    for (auto p: mapping)
    {
        std::cout << "MAP: " << (*p.first.first) << "@" << p.first.second->name <<
        " -> " << (*p.second) << std::endl;
    }
    
    for (auto v: *g->vertices())
    {
        for (auto l1: *g->layers())
        {
            if (!l1->vertices()->contains(v))
                continue;
            for (auto l2: *g->layers())
            {
                if (l1>=l2)
                    continue;
                if (!l2->vertices()->contains(v))
                    continue;
                
                auto intralayer_vertex1 = std::make_pair(v, l1);
                auto intralayer_vertex2 = std::make_pair(v, l2);
                auto v1 = mapping.at(intralayer_vertex1);
                auto v2 = mapping.at(intralayer_vertex2);
                
                auto e = net->edges()->add(v1, v2);
                // omega - 1.0
                double factor = omega - 1.0 + degrees.at(intralayer_vertex1)*degrees.at(intralayer_vertex2)/2.0/mu;
                net->set_weight(e, factor);
                
                std::cout << "adding " << (*v1) << "--" << (*v2) <<  " " << factor << std::endl;
            }
        }
    }
    
    return std::make_pair(std::move(net), reverse_mapping);
}


}
}

