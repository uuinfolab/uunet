#ifndef PEPROCESSNETWORK__H
#define PEPROCESSNETWORK__H

#include <string>

#include "io/read_multilayer_network.hpp"
#include "networks/WeightedNetwork.hpp"
#include "operations/flatten.hpp"

#include "AliasTable.hpp"
#include "include/word2vec.hpp"
#include "LayerSwapMetric.hpp"

namespace uu
{
    namespace net
    {

        void set_rw_probs(uu::net::WeightedNetwork *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>> &king_map, float p, float q, uu::net::EdgeMode edge_mode = uu::net::EdgeMode::INOUT);

        void set_rw_probs(uu::net::Network *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>> &king_map, float p, float q, uu::net::EdgeMode edge_mode = uu::net::EdgeMode::INOUT);

        void set_interlayer_probs(uu::net::MultilayerNetwork *ml_net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>> &interlayer_map, LayerSwapMetric metric);

        void set_interlayer_probs_nor(uu::net::MultilayerNetwork *ml_net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>> &interlayer_map, LayerSwapMetric metric);

    } // namespace net
} // namespace uu

#endif // WORD2VEC_HUFFMANTREE_H
