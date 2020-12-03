
#include "PreprocessNetwork.hpp"
namespace uu
{
    namespace net
    {
        void set_rw_probs(uu::net::WeightedNetwork *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>> &king_map, float p, float q, uu::net::EdgeMode edge_mode)
        {
            for (auto node : *net->vertices())
            {
                std::string map_key_first = node->name;
                const uu::net::Vertex *map_key_first_pointer = node;
                std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>> inner = std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>();
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
                    AliasTable<uu::net::Vertex> table = AliasTable<uu::net::Vertex>(probabilities, neighbors);
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

        void set_rw_probs(uu::net::Network *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>> &king_map, float p, float q, uu::net::EdgeMode edge_mode)
        {
            for (auto node : *net->vertices())
            {
                std::string map_key_first = node->name;
                const uu::net::Vertex *map_key_first_pointer = node;
                std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>> inner = std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>();
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
                    AliasTable<uu::net::Vertex> table = AliasTable<uu::net::Vertex>(probabilities, neighbors);
                    inner.insert({map_key_second_pointer, table});
                }
                king_map.insert(std::make_pair(map_key_first_pointer, inner));
            }
        }

        void set_interlayer_probs(uu::net::MultilayerNetwork *ml_net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>> &interlayer_map, LayerSwapMetric metric)
        {
            for (auto actor : *ml_net->actors())
            {
                auto inner_map = std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>();
                for (auto current_layer : *ml_net->layers())
                {
                    if (!current_layer->vertices()->contains(actor))
                    {
                        continue;
                    }
                    auto prob_vec = std::vector<double>();
                    auto layer_vec = std::vector<const uu::net::Network *>();
                    double normalization = 0;
                    for (auto other_layer : *ml_net->layers())
                    {
                        if (ml_net->layers()->index_of(current_layer) == ml_net->layers()->index_of(other_layer))
                        {
                            continue;
                        }
                        if (!other_layer->vertices()->contains(actor))
                        {
                            continue;
                        }
                        double node_intersection = 0;
                        double node_union, prob_metric;
                        switch (metric)
                        {
                        case LayerSwapMetric::LAYERS_JACC_SIM:
                        {
                            for (auto node : *current_layer->vertices())
                            {
                                if (other_layer->vertices()->contains(node))
                                {
                                    node_intersection += 1;
                                }
                            }
                            double node_union = current_layer->vertices()->size() + other_layer->vertices()->size() - node_intersection;
                            double prob_metric = node_intersection / node_union;
                            break;
                        }
                        case LayerSwapMetric::LAYERS_JACC_DIST:
                        {
                            double node_intersection = 0;
                            for (auto node : *current_layer->vertices())
                            {
                                if (other_layer->vertices()->contains(node))
                                {
                                    node_intersection += 1;
                                }
                            }
                            double node_union = current_layer->vertices()->size() + other_layer->vertices()->size() - node_intersection;
                            double prob_metric = 1.0 - (node_intersection / node_union);
                            break;
                        }
                        case LayerSwapMetric::NEIGH_JACC_SIM:
                        {
                            for (auto neighbor : *current_layer->edges()->neighbors(actor))
                            {
                                if (other_layer->edges()->neighbors(actor)->contains(neighbor))
                                {
                                    node_intersection += 1;
                                }
                            }
                            double node_union = current_layer->edges()->neighbors(actor)->size() + other_layer->edges()->neighbors(actor)->size() - node_intersection;
                            double prob_metric = node_intersection / node_union;
                            break;
                        }
                        case LayerSwapMetric::NEIGH_JACC_DIST:
                        {
                            for (auto neighbor : *current_layer->edges()->neighbors(actor))
                            {
                                if (other_layer->edges()->neighbors(actor)->contains(neighbor))
                                {
                                    node_intersection += 1;
                                }
                            }
                            double node_union = current_layer->edges()->neighbors(actor)->size() + other_layer->edges()->neighbors(actor)->size() - node_intersection;
                            double prob_metric = 1.0 - (node_intersection / node_union);
                            break;
                        }
                        }
                        normalization += prob_metric;
                        prob_vec.push_back(prob_metric);
                        layer_vec.push_back(other_layer);
                    }
                    for (auto &value : prob_vec)
                    {
                        value /= normalization;
                    }
                    AliasTable<uu::net::Network> table = AliasTable<uu::net::Network>(prob_vec, layer_vec);
                    inner_map.insert({current_layer, table});
                }
                interlayer_map.insert({actor, inner_map});
            }
        }

        void set_interlayer_probs_nor(uu::net::MultilayerNetwork *ml_net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>> &interlayer_map, LayerSwapMetric metric)
        {
            for (auto actor : *ml_net->actors())
            {
                auto inner_map = std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>();
                for (auto current_layer : *ml_net->layers())
                {
                    if (!current_layer->vertices()->contains(actor))
                    {
                        continue;
                    }
                    auto prob_vec = std::vector<double>();
                    auto layer_vec = std::vector<const uu::net::Network *>();
                    double normalization = 0;
                    for (auto other_layer : *ml_net->layers())
                    {
                        if (!other_layer->vertices()->contains(actor))
                        {
                            continue;
                        }
                        double node_intersection = 0;
                        double node_union, prob_metric;
                        switch (metric)
                        {
                        case LayerSwapMetric::LAYERS_JACC_SIM:
                        {
                            for (auto node : *current_layer->vertices())
                            {
                                if (other_layer->vertices()->contains(node))
                                {
                                    node_intersection += 1;
                                }
                            }
                            double node_union = current_layer->vertices()->size() + other_layer->vertices()->size() - node_intersection;
                            double prob_metric = node_intersection / node_union;
                            break;
                        }
                        case LayerSwapMetric::LAYERS_JACC_DIST:
                        {
                            double node_intersection = 0;
                            for (auto node : *current_layer->vertices())
                            {
                                if (other_layer->vertices()->contains(node))
                                {
                                    node_intersection += 1;
                                }
                            }
                            double node_union = current_layer->vertices()->size() + other_layer->vertices()->size() - node_intersection;
                            double prob_metric = 1.0 - (node_intersection / node_union);
                            break;
                        }
                        case LayerSwapMetric::NEIGH_JACC_SIM:
                        {
                            for (auto neighbor : *current_layer->edges()->neighbors(actor))
                            {
                                if (other_layer->edges()->neighbors(actor)->contains(neighbor))
                                {
                                    node_intersection += 1;
                                }
                            }
                            double node_union = current_layer->edges()->neighbors(actor)->size() + other_layer->edges()->neighbors(actor)->size() - node_intersection;
                            double prob_metric = node_intersection / node_union;
                            break;
                        }
                        case LayerSwapMetric::NEIGH_JACC_DIST:
                        {
                            for (auto neighbor : *current_layer->edges()->neighbors(actor))
                            {
                                if (other_layer->edges()->neighbors(actor)->contains(neighbor))
                                {
                                    node_intersection += 1;
                                }
                            }
                            double node_union = current_layer->edges()->neighbors(actor)->size() + other_layer->edges()->neighbors(actor)->size() - node_intersection;
                            double prob_metric = 1.0 - (node_intersection / node_union);
                            break;
                        }
                        }
                        normalization += prob_metric;
                        prob_vec.push_back(prob_metric);
                        layer_vec.push_back(other_layer);
                    }
                    for (auto &value : prob_vec)
                    {
                        value /= normalization;
                    }
                    AliasTable<uu::net::Network> table = AliasTable<uu::net::Network>(prob_vec, layer_vec);
                    inner_map.insert({current_layer, table});
                }
                interlayer_map.insert({actor, inner_map});
            }
        }

    } // namespace net
} // namespace uu