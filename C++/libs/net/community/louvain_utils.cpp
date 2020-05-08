
#include "net/community/louvain_utils.hpp"

#include <chrono>
#include <unordered_map>
#include <vector>
#include "community/CommunityStructure.hpp"
#include "community/Community.hpp"
#include "objects/EdgeMode.hpp"
#include "objects/Vertex.hpp"

namespace uu {
namespace net {


std::unique_ptr<MetaNetwork>
convert(
    const Network* g
)
{
    auto meta = std::make_unique<MetaNetwork>();

    for (auto v: *g->vertices())
    {
        meta->add(v);
        //std::cout << (*v) << " -> " << (*meta_v) << std::endl;
    }

    for (auto e: *g->edges())
    {
        meta->edge(e->v1, e->v2);
    }

    return meta;
}


std::unique_ptr<MetaNetwork>
aggregate(
    const WeightedNetwork* g,
    std::unordered_map<const Vertex*, size_t> community
)
{
    auto meta = std::make_unique<MetaNetwork>();

    std::unordered_map<size_t, std::set<const Vertex*>> vertices;

    for (auto pair: community)
    {
        vertices[pair.second].insert(pair.first);
        /*
         auto it = vertices.find(pair->second);
         if (it == vertices.end())
         {
         improvement[neighbor_community] += contribution;
         }
         else {
         it->second += contribution;
         }
         */
    }


    for (auto pair: vertices)
    {
        meta->add(pair.second.begin(), pair.second.end());

        /*for (auto v: pair.second)
         {
         std::cout << (*v) << " -> " << (*meta_v) << std::endl;
         }*/
    }

    for (auto e: *g->edges())
    {
        meta->edge(e->v1, e->v2);
    }

    return meta;
}


void
expand(
    const std::vector<std::unique_ptr<MetaNetwork>>& levels,
    size_t i,
    const Vertex* v,
    Community<const Vertex*>* com
)
{
    if (i==0)
    {
        for (auto original_vertex: levels.at(i)->mapping.at(v))
        {
            //std::cout << "adding " << (*original_vertex) << std::endl;
            com->add(original_vertex);
        }
    }

    else
    {
        for (auto previous_vertex: levels.at(i)->mapping.at(v))
        {
            expand(levels, i-1, previous_vertex, com);
        }
    }
}

std::unique_ptr<CommunityStructure<Community<const Vertex*>>>
communities(
    const std::vector<std::unique_ptr<MetaNetwork>>& levels
)
{
    auto res = std::make_unique<CommunityStructure<Community<const Vertex*>>>();

    size_t i = levels.size()-1;

    for (auto v: *levels.at(i)->get()->vertices())
    {
        auto community = std::make_unique<Community<const Vertex*>>();

        expand(levels, i, v, community.get());

        res->add(std::move(community));
    }

    return res;
}

std::unique_ptr<MetaNetwork>
pass(
    const WeightedNetwork* g
)
{
    //std::cout << "PASS" << std::endl;

    size_t m2 = size(g);

    std::unordered_map<const Vertex*, size_t> community;
    std::unordered_map<const Vertex*, double> w_degree;
    size_t comm_id = 0;

    for (auto v: *g->vertices())
    {
        //std::cout << (*v) << ": " << comm_id << std::endl;
        community[v] = comm_id++;
        w_degree[v] = strength(g, v);
    }

    bool change = false;
    bool improved = false;

    do
    {
        change = false;

        for (auto v: *g->vertices())
        {
            auto current_community = community.at(v);
            w_degree[v] = strength(g, v);

            std::unordered_map<size_t, double> improvement;

            double loss = 0; // price of leaving current community

            for (auto n: *g->edges()->neighbors(v))
            {

                double contribution = 1.0 - w_degree.at(v)*w_degree.at(n)/m2/2;

                auto neighbor_community = community.at(n);

                if (neighbor_community == current_community)
                {
                    loss += contribution;
                    continue;
                }

                auto it = improvement.find(neighbor_community);

                if (it == improvement.end())
                {
                    improvement[neighbor_community] += contribution;
                }

                else
                {
                    it->second += contribution;
                }
            }

            // best choice
            auto new_community = current_community;
            double current_improvement = 0;

            for (auto pair: improvement)
            {
                if (pair.second - loss > current_improvement)
                {
                    new_community = pair.first;
                    current_improvement = pair.second - loss;
                }
            }

            if (new_community != current_community)
            {
                change = true;
                improved = true;
                community.at(v) = new_community;
                //std::cout << (*v) << " from " << current_community << " to " << new_community << std::endl;
            }
        }
    }
    while (change);

    /*for (auto pair: community)
     {
     std::cout << (*pair.first) << ": " << pair.second << std::endl;
     }*/

    if (!improved)
    {
        return nullptr;
    }

    auto meta = aggregate(g, community);

    return meta;
}


}
}
