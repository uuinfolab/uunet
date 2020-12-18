
#include "PreprocessNetwork.hpp"
namespace uu
{
namespace net
{
    void set_rw_probs(uu::net::WeightedNetwork *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>> &king_map, float p, float q, uu::net::EdgeMode edge_mode)
    {
        for (auto node_from : *net->vertices())
        {
            std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>> inner = std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>();
            std::vector<const uu::net::Vertex *> store_neighbs = std::vector<const uu::net::Vertex *>(net->edges()->neighbors(node_from, EdgeMode::OUT)->size());
            
            // Initial step probabilities
            std::vector<double> probabilities = std::vector<double>(net->edges()->neighbors(node_from, EdgeMode::OUT)->size());
            double scale = 0.0;
            for (auto neigh : *net->edges()->neighbors(node_from, EdgeMode::OUT))
            {
                double weight = net->get_weight(net->edges()->get(node_from, neigh)).value;
                scale += weight;
                probabilities.push_back(weight);
                store_neighbs.push_back(neigh);
            }
            if(scale!=0)
            {
                scale = 1.0 / scale;
            }
            for (auto &prob : probabilities)
            {
                prob = prob * scale;
            }
            AliasTable<uu::net::Vertex> table = AliasTable<uu::net::Vertex>(probabilities, store_neighbs);
            inner.insert({node_from, table});

            for (auto node_at : *net->edges()->neighbors(node_from, EdgeMode::OUT))
            {
                std::vector<double> probabilities = std::vector<double>(net->edges()->neighbors(node_at, EdgeMode::OUT)->size());
                std::vector<const uu::net::Vertex *> neighbors = std::vector<const uu::net::Vertex *>(net->edges()->neighbors(node_at, EdgeMode::OUT)->size());
                double scale = 0.0;
                for (auto node_to : *net->edges()->neighbors(node_at, EdgeMode::OUT))
                {
                    if (node_to == node_from)
                    {
                        double weight = net->get_weight(net->edges()->get(node_at, node_to)).value / p;
                        scale += weight;
                        neighbors.push_back(node_to);
                        probabilities.push_back(weight);
                    }
                    else if (std::find(store_neighbs.begin(), store_neighbs.end(), node_to) != store_neighbs.end()) 
                    {
                        double weight = net->get_weight(net->edges()->get(node_at, node_to)).value;
                        scale += weight;
                        neighbors.push_back(node_to);
                        probabilities.push_back(weight);
                    }
                    else
                    {
                        double weight = net->get_weight(net->edges()->get(node_at, node_to)).value / q;
                        scale += weight;
                        neighbors.push_back(node_to);
                        probabilities.push_back(weight);
                    }
                }
                scale = 1.0 / scale;
                for (auto &prob : probabilities)
                {
                    prob = prob * scale;
                }
                AliasTable<uu::net::Vertex> table = AliasTable<uu::net::Vertex>(probabilities, neighbors);
                
                inner.insert({node_at, table});
            }
            king_map.insert(std::make_pair(node_from, inner));
        }
    }

    void set_rw_probs(uu::net::Network *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>> &king_map, float p, float q, uu::net::EdgeMode edge_mode)
    {
        for (auto node_from : *net->vertices())
        {           
            std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>> inner = std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>();
            std::vector<const uu::net::Vertex *> store_neighbs = std::vector<const uu::net::Vertex *>(net->edges()->neighbors(node_from, EdgeMode::OUT)->size());
            
            // Initial step probabilities
            std::vector<double> probabilities = std::vector<double>(net->edges()->neighbors(node_from, EdgeMode::OUT)->size());
            double scale = 0.0;
            for (auto neigh : *net->edges()->neighbors(node_from, EdgeMode::OUT))
            {
                double weight = 1.0;
                scale += weight;
                probabilities.push_back(weight);
                store_neighbs.push_back(neigh);
            }
            scale = 1.0 / scale;
            for (auto &prob : probabilities)
            {
                prob = prob * scale;
            }
            AliasTable<uu::net::Vertex> table = AliasTable<uu::net::Vertex>(probabilities, store_neighbs);
            inner.insert({node_from, table});
            
            for (auto node_at : *net->edges()->neighbors(node_from, EdgeMode::OUT))
            {
                std::vector<double> probabilities = std::vector<double>(net->edges()->neighbors(node_at, EdgeMode::OUT)->size());
                std::vector<const uu::net::Vertex *> neighbors = std::vector<const uu::net::Vertex *>(net->edges()->neighbors(node_at, EdgeMode::OUT)->size());
                double scale = 0.0;
                for (auto node_to : *net->edges()->neighbors(node_at, EdgeMode::OUT))
                {
                    if (node_to == node_from)
                    {
                        double weight = 1.0 / p;
                        scale += weight;
                        neighbors.push_back(node_to);
                        probabilities.push_back(weight);
                    }
                    else if (std::find(store_neighbs.begin(), store_neighbs.end(), node_to) != store_neighbs.end())
                    {
                        double weight = 1.0;
                        scale += weight;
                        neighbors.push_back(node_to);
                        probabilities.push_back(weight);
                    }
                    else
                    {
                        double weight = 1.0 / q;
                        scale += weight;
                        neighbors.push_back(node_to);
                        probabilities.push_back(weight);
                    }
                }
                scale = 1.0 / scale;
                for (auto &prob : probabilities)
                {
                    prob = prob * scale;
                }
                AliasTable<uu::net::Vertex> table = AliasTable<uu::net::Vertex>(probabilities, neighbors);
                inner.insert({node_at, table});
            }
            king_map.insert(std::make_pair(node_from, inner));
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
                    case LayerSwapMetric::UNIFORM:
                    {    
                        double prob_metric = 1;
                        break;
                    }
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
                    case LayerSwapMetric::UNIFORM:
                    {    
                        double prob_metric = 1;
                        break;
                    }
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