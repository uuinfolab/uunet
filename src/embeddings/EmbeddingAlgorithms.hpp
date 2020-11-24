

#ifndef EMBEDDING_H
#define EMBEDDING_H

#include "io/read_multilayer_network.hpp"
#include "networks/WeightedNetwork.hpp"
#include "operations/flatten.hpp"

#include "_impl/RandomWalks.hpp"
#include "_impl/TrainHelper.hpp"
#include "KMeans.hpp"

namespace uu
{
  namespace net
  {

    std::unordered_map<std::string, w2v::vector_t>  algo_1_MG(uu::net::MultilayerNetwork *ml_net, float p = 0.5, float q = 0.5, int size_of_embedding = 20, int len_rand_walk = 80, int numb_rand_walks = 20, int clusters = 8,
                   int window = 5, int cluster_iterations = 50, std::string alpha = "0.05", std::string sample = "1e-3",
                   int iterations = 5, int min_word_freq = 1, int negative_sample = 5, int threads = 8);

    std::unordered_map<std::string, w2v::vector_t>  algo_2_MG(uu::net::MultilayerNetwork *ml_net, float p = 0.5, float q = 0.5, int size_of_embedding = 5, int len_rand_walk = 80, int numb_rand_walks = 20, int clusters = 2,
                   int window = 5, int cluster_iterations = 50, std::string alpha = "0.05", std::string sample = "1e-3",
                   int iterations = 5, int min_word_freq = 1, int negative_sample = 5, int threads = 8);

    std::unordered_map<std::string, w2v::vector_t>  algo_3_MG(uu::net::MultilayerNetwork *ml_net, float r = 0.5, float p = 0.5, float q = 0.5, int size_of_embedding = 20, int len_rand_walk = 80, int numb_rand_walks = 1000, int clusters = 8,
                   int window = 40, int cluster_iterations = 50, std::string alpha = "0.05", std::string sample = "1e-3",
                   int iterations = 5, int min_word_freq = 1, int negative_sample = 5, int threads = 8);

  } // namespace net
} // namespace uu

#endif // WORD2VEC_HUFFMANTREE_H
