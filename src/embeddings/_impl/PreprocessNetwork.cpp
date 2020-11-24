
#include "PreprocessNetwork.hpp"
namespace uu
{
    namespace net
    {

        void set_rw_probs(uu::net::WeightedNetwork *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable>> &king_map, float p, float q, uu::net::EdgeMode edge_mode)
        {
            for (auto node : *net->vertices())
            {
                std::string map_key_first = node->name;
                const uu::net::Vertex *map_key_first_pointer = node;
                std::unordered_map<const uu::net::Vertex *, AliasTable> inner = std::unordered_map<const uu::net::Vertex *, AliasTable>();
                for (auto first_neigh : *net->edges()->neighbors(node, edge_mode))
                {

                    std::vector<const uu::net::Vertex *> store_neighbs = std::vector<const uu::net::Vertex *>();
                    for (auto neigh : *net->edges()->neighbors(node, edge_mode))
                    {
                        store_neighbs.push_back(neigh);
                    }
                    std::string map_key_first = first_neigh->name;
                    const uu::net::Vertex *map_key_second_pointer = first_neigh;
                    std::vector<double> probabilities;
                    std::vector<const uu::net::Vertex *> neighbors;
                    double scale = 0.0;
                    for (auto second_neigh : *net->edges()->neighbors(first_neigh, edge_mode))
                    {
                        if (second_neigh == node)
                        {
                            double weight = net->get_weight(net->edges()->get(first_neigh, second_neigh)).value / p;
                            scale += weight;
                            neighbors.push_back(second_neigh);
                            probabilities.push_back(weight);
                        }
                        else if (std::find(store_neighbs.begin(), store_neighbs.end(), second_neigh) != store_neighbs.end())
                        {
                            double weight = net->get_weight(net->edges()->get(first_neigh, second_neigh)).value;
                            scale += weight;
                            neighbors.push_back(second_neigh);
                            probabilities.push_back(weight);
                        }
                        else
                        {
                            double weight = net->get_weight(net->edges()->get(first_neigh, second_neigh)).value / q;
                            scale += weight;
                            neighbors.push_back(second_neigh);
                            probabilities.push_back(weight);
                        }
                    } // For all neighbours of a node
                    scale = 1 / scale;
                    for (auto &prob : probabilities)
                    {
                        prob = prob * scale;
                    }
                    AliasTable table = AliasTable(probabilities, neighbors);
                    //king_map.insert
                    //king_map.insert({map_key_first_pointer,});
                    //king_map[map_key_first_pointer][map_key_second_pointer] = table;

                    //inner.insert(std::make_pair(map_key_second_pointer, table));
                    inner.insert({map_key_second_pointer, table});

                    //std::cout << "second key: " <<  map_key_second_pointer->name << std::endl;
                }
                king_map.insert(std::make_pair(map_key_first_pointer, inner));
                //std::cout << "first key: " <<  map_key_first_pointer->name << std::endl;
            }
        }

        void set_rw_probs(uu::net::Network *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable>> &king_map, float p, float q, uu::net::EdgeMode edge_mode)
        {
            for (auto node : *net->vertices())
            {
                std::string map_key_first = node->name;
                const uu::net::Vertex *map_key_first_pointer = node;
                std::unordered_map<const uu::net::Vertex *, AliasTable> inner = std::unordered_map<const uu::net::Vertex *, AliasTable>();
                for (auto first_neigh : *net->edges()->neighbors(node, edge_mode))
                {

                    std::vector<const uu::net::Vertex *> store_neighbs = std::vector<const uu::net::Vertex *>();
                    for (auto neigh : *net->edges()->neighbors(node, edge_mode))
                    {
                        store_neighbs.push_back(neigh);
                    }
                    std::string map_key_first = first_neigh->name;
                    const uu::net::Vertex *map_key_second_pointer = first_neigh;
                    std::vector<double> probabilities;
                    std::vector<const uu::net::Vertex *> neighbors;
                    double scale = 0.0;
                    for (auto second_neigh : *net->edges()->neighbors(first_neigh, edge_mode))
                    {
                        if (second_neigh == node)
                        {
                            double weight = 1.0 / p;
                            scale += weight;
                            neighbors.push_back(second_neigh);
                            probabilities.push_back(weight);
                        }
                        else if (std::find(store_neighbs.begin(), store_neighbs.end(), second_neigh) != store_neighbs.end())
                        {
                            double weight = 1.0;
                            scale += weight;
                            neighbors.push_back(second_neigh);
                            probabilities.push_back(weight);
                        }
                        else
                        {
                            double weight = 1.0 / q;
                            scale += weight;
                            neighbors.push_back(second_neigh);
                            probabilities.push_back(weight);
                        }
                    } // For all neighbours of a node
                    scale = 1 / scale;
                    for (auto &prob : probabilities)
                    {
                        prob = prob * scale;
                    }
                    AliasTable table = AliasTable(probabilities, neighbors);
                    inner.insert({map_key_second_pointer, table});
                }
                king_map.insert(std::make_pair(map_key_first_pointer, inner));
            }
        }
    } // namespace net
} // namespace uu