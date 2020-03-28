
#include "net/community/glouvain_utils.hpp"

#include <chrono>
#include <unordered_map>
#include <vector>
#include "community/CommunityStructure.hpp"
#include "community/Community.hpp"
#include "objects/EdgeMode.hpp"
#include "objects/Vertex.hpp"
#include "measures/degree.hpp"

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
    
    std::map<std::pair<const Vertex*, const Network*>, size_t> deg;
    std::map<std::pair<const Vertex*, const Network*>, size_t> ome;
    std::map<const Network*, size_t> m;
    
    
    
    auto net = std::make_unique<WeightedNetwork>("w");

    size_t v_id = 0;
    size_t mu = 0;
    
    for (auto l: *g->layers())
    {
        m[l] = size(l);
    }
    for (auto v: *g->vertices())
    {
        for (auto l1: *g->layers())
        {
            if (!l1->vertices()->contains(v))
                continue;
            auto iv1 = std::make_pair(v, l1);
            auto d = degree(l1, v);
            deg[iv1] = d;
            mu += d/2.0;
            for (auto l2: *g->layers())
            {
                if (l1>=l2)
                    continue;
                if (!l2->vertices()->contains(v))
                    continue;
                auto omega_iv1 = ome.find(iv1);
                if (omega_iv1 != ome.end())
                {
                    ome[iv1] = omega;
                }
                else
                {
                    omega_iv1->second += omega;
                }
                
                auto iv2 = std::make_pair(v, l2);
                auto omega_iv2 = ome.find(iv2);
                if (omega_iv2 != ome.end())
                {
                    ome[iv2] = omega;
                }
                else
                {
                    omega_iv2->second += omega;
                }
                mu += omega;
            }
        }
    }
    
    for (auto l: *g->layers())
    {
        for (auto v: *l->vertices())
        {
            auto metavertex = net->vertices()->add(std::to_string(v_id++));
            auto intralayer_vertex = std::make_pair(v,l);
            mapping[intralayer_vertex] = metavertex;
            reverse_mapping[metavertex] = intralayer_vertex;
            //std::cout << "adding " << (*v) << "@" << l->name <<
            //" as " << (*metavertex) << std::endl;
        }

        for (auto e: *l->edges())
        {
            auto iv1 = std::make_pair(e->v1, l);
            auto iv2 = std::make_pair(e->v2, l);
            auto v1 = mapping.at(iv1);
            auto v2 = mapping.at(iv2);
            auto edge = net->edges()->add(v1, v2);
            auto weight = 1.0 - deg[iv1]*deg[iv2]/2.0/m[l] + (deg[iv1] + ome[iv1])*(deg[iv2] + ome[iv2])/2.0/mu;
            net->set_weight(edge, weight);
            
            //std::cout << "adding " << (*v1) << "--" << (*v2) << std::endl;
        }
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
                
                auto iv1 = std::make_pair(v, l1);
                auto iv2 = std::make_pair(v, l2);
                auto v1 = mapping.at(iv1);
                auto v2 = mapping.at(iv2);
                
                auto e = net->edges()->add(v1, v2);
                double weight = omega + (deg[iv1] + ome[iv1])*(deg[iv2] + ome[iv2])/2.0/mu;
                net->set_weight(e, weight);
                
                //std::cout << "adding " << (*v1) << "--" << (*v2) <<  " " << factor << std::endl;
            }
        }
    }
    //std::cout << "conversion done!" << std::endl;
    
    
    return std::make_pair(std::move(net), reverse_mapping);
}


}
}

