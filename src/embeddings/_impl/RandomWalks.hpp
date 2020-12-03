
#ifndef RANDOMWALKS_H
#define RANDOMWALKS_H
#include <vector>

//  #include <string>
// #include "io/read_multilayer_network.hpp"
#include "networks/WeightedNetwork.hpp"
// #include "operations/flatten.hpp"
//#include "AliasTable.cpp"
#include "PreprocessNetwork.hpp"
// #include "PreprocessNetwork.hpp"
// #include "word2vec.hpp"

namespace uu
{
    namespace net
    {

        std::vector<std::string> random_walks_sl(uu::net::Network *single_net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>> &sampling_map_sl, std::default_random_engine &generator, const uu::net::Vertex *node_second, int len_rand_walk, int numb_rand_walks);

        std::vector<std::string> random_walks_ml(uu::net::MultilayerNetwork *multi_net, std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>> &sampling_map_ml,
                                                 std::default_random_engine &generator, double r, int len_rand_walk, int numb_rand_walks);

        std::vector<std::string> random_walks_ml_fancy(uu::net::MultilayerNetwork *multi_net, std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>> &sampling_map_ml,
                                                       std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>> &interlayer_map, std::default_random_engine &generator, double r, int len_rand_walk, int numb_rand_walks);

        std::vector<std::string> random_walks_ml_nor(uu::net::MultilayerNetwork *multi_net, std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>> &sampling_map_ml,
                                                     std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>> &interlayer_map, std::default_random_engine &generator, int len_rand_walk, int numb_rand_walks);

    } // namespace net
} // namespace uu

#endif // WORD2VEC_HUFFMANTREE_H
