/**
 * @file
 * @brief Huffman encoding tree implementation based on std::priority_queue
 * @author Max Fomichev
 * @date 19.12.2016
 * @copyright Apache License v.2 (http://www.apache.org/licenses/LICENSE-2.0)
*/

#ifndef PEPROCESSNETWORK__H
#define PEPROCESSNETWORK__H

#include <string>

#include "io/read_multilayer_network.hpp"
#include "networks/WeightedNetwork.hpp"
#include "operations/flatten.hpp"

#include "AliasTable.hpp"
#include "include/word2vec.hpp"

namespace uu
{
    namespace net
    {

        void set_rw_probs(uu::net::WeightedNetwork *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable>> &king_map, float p, float q, uu::net::EdgeMode edge_mode = uu::net::EdgeMode::INOUT);

        void set_rw_probs(uu::net::Network *net, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable>> &king_map, float p, float q, uu::net::EdgeMode edge_mode = uu::net::EdgeMode::INOUT);

    } // namespace net
} // namespace uu

#endif // WORD2VEC_HUFFMANTREE_H
