#include "RandomWalks.hpp"

namespace uu
{
    namespace net
    {
        std::vector<std::string> random_walks_sl(uu::net::Network *single_net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>> &sampling_map_sl, std::default_random_engine &generator, const uu::net::Vertex *node_second, int len_rand_walk, int numb_rand_walks)
        {
            const uu::net::Vertex *node_start = node_second;
            std::vector<std::string> output = std::vector<std::string>();
            if (len_rand_walk == 0 || numb_rand_walks == 0)
            {
                return output;
            }
            for (int i = 0; i < numb_rand_walks; ++i)
            {
                node_second = node_start;
                auto node_sentence = std::string();
                if (single_net->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->size() == 0)
                {
                    output.push_back(node_second->name + ". ");
                    //return output;
                    continue;
                }
                else
                {
                    auto node_first = single_net->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->get_at_random();
                    if (len_rand_walk == 1)
                    {
                        output.push_back(node_second->name + ". ");
                    }
                    else
                    {
                        node_sentence.append(node_second->name);
                        for (int j = 0; j < (len_rand_walk - 1); ++j)
                        {
                            auto node_tmp = sampling_map_sl.at(node_first).at(node_second).alias_sampling(&generator);
                            node_sentence.append(" " + node_tmp->name);
                            node_first = node_second;
                            node_second = node_tmp;
                        }
                        node_sentence += ". ";
                        output.push_back(node_sentence);
                    }
                }
            }
            return output;
        }

        std::vector<std::string> random_walks_ml(uu::net::MultilayerNetwork *multi_net, std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>> &sampling_map_ml,
                                                 std::default_random_engine &generator, double r, int len_rand_walk, int numb_rand_walks)
        {
            std::vector<std::string> output = std::vector<std::string>();
            std::uniform_real_distribution<double> distribution(0.0, 1.0);
            double x = 1.0;
            if (len_rand_walk == 0 || numb_rand_walks == 0)
            {
                return output;
            }
            for (int i = 0; i < numb_rand_walks; ++i)
            {

                auto node_second = multi_net->actors()->get_at_random();
                auto layer = multi_net->layers()->get_at_random();
                while (!layer->vertices()->contains(node_second))
                {
                    layer = multi_net->layers()->get_at_random();
                }

                
                if (layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->size() == 0) {        //Guarantees node is not isolated maybe
                    output.push_back(node_second->name + ". ");
                    continue;
                }

                auto node_first = layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->get_at_random();

                auto node_sentence = std::string();

                if (len_rand_walk == 1)
                {
                    output.push_back(node_second->name + ". ");
                }
                else
                {
                    node_sentence.append(node_second->name);
                    for (int j = 0; j < (len_rand_walk-1); ++j)
                    {
                        if (distribution(generator) < r)
                        {
                            while (!layer->vertices()->contains(node_second))
                            {
                                layer = multi_net->layers()->get_at_random(); //quite inefficient for certain problems
                            }
                            if (layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->size() == 0) {  
                                node_sentence.append(" " + node_second->name);      //Guarantees node is not isolated maybe
                                break;
                            }
                            node_first = layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->get_at_random();
                        }
        
                        //if (layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->size() == 0) {  
                          //  node_sentence.append(" " + node_second->name);      //Guarantees node is not isolated maybe
                            //break;
                        //}

                        auto node_tmp = sampling_map_ml.at(layer).at(node_first).at(node_second).alias_sampling(&generator);
                        node_first = node_second;
                        node_second = node_tmp;
                        node_sentence.append(" " + node_second->name);
                        //node_sentence.append(" " + node_second->name);
                    }
                    node_sentence += ". ";
                    output.push_back(node_sentence);
                }
            }
            return output;
        }

        std::vector<std::string> random_walks_ml_fancy(uu::net::MultilayerNetwork *multi_net, std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>> &sampling_map_ml,
                                                       std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>> &interlayer_map, std::default_random_engine &generator, double r, int len_rand_walk, int numb_rand_walks)
        {
            std::vector<std::string> output = std::vector<std::string>();
            std::uniform_real_distribution<double> distribution(0.0, 1.0);

            double x = 1.0;
            if (len_rand_walk == 0 || numb_rand_walks == 0)
            {
                return output;
            }
            for (int i = 0; i < numb_rand_walks; ++i)
            {
                auto node_second = multi_net->actors()->get_at_random();
                const uu::net::Network *layer = multi_net->layers()->get_at_random();
                while (!layer->vertices()->contains(node_second))
                {
                    layer = multi_net->layers()->get_at_random();
                }
                auto node_first = layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->get_at_random();

                auto node_sentence = std::string();

                if (len_rand_walk == 1)
                {
                    output.push_back(node_second->name + ". ");
                }
                else
                {
                    node_sentence.append(node_second->name);
                    for (int j = 0; j < (len_rand_walk-1); ++j)
                    {

                        if (interlayer_map.at(node_second).at(layer).size() != 0 && distribution(generator) < r)
                        {
                            layer = interlayer_map.at(node_second).at(layer).alias_sampling(&generator);
                            node_first = layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->get_at_random();
                        }

                        auto node_tmp = sampling_map_ml.at(layer).at(node_first).at(node_second).alias_sampling(&generator);
                        node_first = node_second;
                        node_second = node_tmp;
                        node_sentence.append(" " + node_second->name);
                    }
                    node_sentence += ". ";
                    output.push_back(node_sentence);
                }
            }
            return output;
        }

        std::vector<std::string> random_walks_ml_nor(uu::net::MultilayerNetwork *multi_net, std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>> &sampling_map_ml,
                                                     std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>> &interlayer_map, std::default_random_engine &generator, int len_rand_walk, int numb_rand_walks)
        {
            std::vector<std::string> output = std::vector<std::string>();
            std::uniform_real_distribution<double> distribution(0.0, 1.0);

            double x = 1.0;
            if (len_rand_walk == 0 || numb_rand_walks == 0)
            {
                return output;
            }
            for (int i = 0; i < numb_rand_walks; ++i)
            {
                auto node_second = multi_net->actors()->get_at_random();
                const uu::net::Network *layer = multi_net->layers()->get_at_random();
                while (!layer->vertices()->contains(node_second))
                {
                    layer = multi_net->layers()->get_at_random();
                }
                auto node_first = layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->get_at_random();

                auto node_sentence = std::string();

                if (len_rand_walk == 1)
                {
                    output.push_back(node_first->name + ". ");
                }
                else
                {
                    node_sentence.append(node_first->name);
                    for (int j = 0; j < (len_rand_walk - 1); ++j)
                    {

                        //std::cout << node_second->name << "inner mapsize " << interlayer_map.at(node_second).size() << std::endl;
                        layer = interlayer_map.at(node_second).at(layer).alias_sampling(&generator);

                        node_first = layer->edges()->neighbors(node_second, uu::net::EdgeMode::INOUT)->get_at_random();

                        auto node_tmp = sampling_map_ml.at(layer).at(node_first).at(node_second).alias_sampling(&generator);
                        node_first = node_second;
                        node_sentence.append(" " + node_first->name);
                        node_second = node_tmp;
                        node_sentence.append(" " + node_first->name);
                    }
                    node_sentence += ". ";
                    output.push_back(node_sentence);
                }
            }
            return output;
        }
    } // namespace net
} // namespace uu