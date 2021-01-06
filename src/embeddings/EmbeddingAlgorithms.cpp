#include "EmbeddingAlgorithms.hpp"
namespace uu
{
    namespace net
    {

        std::unordered_map<std::string, w2v::vector_t> algo_1_MG(uu::net::MultilayerNetwork *ml_net, float p, float q, int size_of_embedding, int len_rand_walk, int numb_rand_walks, int clusters,
                                                                 int window, int cluster_iterations, std::string alpha, std::string sample,
                                                                 int iterations, int min_word_freq, int negative_sample, int threads)
        {
            std::unique_ptr<uu::net::WeightedNetwork> flat_net = std::make_unique<uu::net::WeightedNetwork>("flat_net",EdgeDir::UNDIRECTED,true);
            flatten_weighted(ml_net->layers()->begin(), ml_net->layers()->end(), flat_net.get());

            auto sampling_map_sl = std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<Vertex>>>();
            set_rw_probs(flat_net.get(), sampling_map_sl, p, q);

            std::default_random_engine generator;
            std::ofstream myfile;
            std::string trainFile = "word2vecinput.txt";
            std::string modelFile = "trained_nodes.w2v";
            myfile.open(trainFile);
            for (auto node : *flat_net.get()->vertices())
            {
                std::vector<std::string> some_random_walks = random_walks_sl(flat_net.get(), sampling_map_sl, generator, node, len_rand_walk, numb_rand_walks);
                for (auto sentence : some_random_walks)
                {
                    myfile << sentence;
                }
            }
            myfile.close();
            w2v::trainSettings_t trainSettings;
            trainSettings.size = static_cast<uint16_t>(size_of_embedding);
            trainSettings.window = static_cast<uint8_t>(window);
            trainSettings.sample = std::stof(sample);
            trainSettings.negative = static_cast<uint8_t>(negative_sample);
            trainSettings.threads = static_cast<uint8_t>(threads);
            trainSettings.iterations = static_cast<uint8_t>(iterations);
            trainSettings.minWordFreq = static_cast<uint16_t>(min_word_freq);
            trainSettings.alpha = std::stof(alpha);
            trainSettings.withSG = true;

            auto w2v_model = train_w2v(trainFile, modelFile, trainSettings);
            return w2v_model.map();
            //KMeans ktest = KMeans(clusters, cluster_iterations, size_of_embedding, ml_net->actors()->size(), w2v_model.map(), &generator);
            //ktest.run();
            //ktest.print_clusters();
            //ktest.summary();
        }
        std::unordered_map<std::string, w2v::vector_t> algo_2_MG(uu::net::MultilayerNetwork *ml_net, float p, float q, int size_of_embedding, int len_rand_walk, int numb_rand_walks, int clusters,
                                                                 int window, int cluster_iterations, std::string alpha, std::string sample,
                                                                 int iterations, int min_word_freq, int negative_sample, int threads)
        {
            w2v::trainSettings_t trainSettings;
            trainSettings.size = static_cast<uint16_t>(size_of_embedding);
            trainSettings.window = static_cast<uint8_t>(window);
            trainSettings.sample = std::stof(sample);
            trainSettings.negative = static_cast<uint8_t>(negative_sample);
            trainSettings.threads = static_cast<uint8_t>(threads);
            trainSettings.iterations = static_cast<uint8_t>(iterations);
            trainSettings.minWordFreq = static_cast<uint16_t>(min_word_freq);
            trainSettings.alpha = std::stof(alpha);
            trainSettings.withSG = true;

            std::default_random_engine generator;
            std::string trainFile = "word2vecinput.txt";
            std::string modelFile = "trained_nodes.w2v";
            std::ofstream myfile;
            auto w2v_embedding_map = std::unordered_map<std::string, w2v::vector_t>();

            for (auto actor : *ml_net->actors())
            {
                w2v_embedding_map.insert({actor->name, w2v::vector_t()});
                /*
            for(auto layer : *ml_net->layers()){
                if(!layer->vertices()->contains(actor)){
                    layer->vertices()->add(actor);
                }
            }*/
            }

            for (auto layer : *ml_net->layers())
            {
                auto sampling_map_sl = std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<Vertex>>>();
                set_rw_probs(layer, sampling_map_sl, p, q);

                myfile.open("word2vecinput.txt");
                for (auto node : *layer->vertices())
                {
                    std::vector<std::string> some_random_walk = random_walks_sl(layer, sampling_map_sl, generator, node, len_rand_walk, numb_rand_walks);
                    for (auto sentence : some_random_walk)
                    {
                        myfile << sentence;
                    }
                }
                myfile.close();
                auto w2v_model = train_w2v(trainFile, modelFile, trainSettings);
                for (auto node_in_layer : *layer->vertices())
                {
                    auto &temp1 = w2v_embedding_map.at(node_in_layer->name);
                    auto temp2 = w2v_model.vector(node_in_layer->name);
                    temp1.insert(temp1.end(), temp2->begin(), temp2->end());
                }

                /*
            for(auto actor : *ml_net->actors()){
                if(!layer->vertices()->contains(actor)){
                    auto & temp1=w2v_embedding_map.at(actor->name);
                    auto temp2=w2v::vector_t(size_of_embedding);
                    temp1.insert(temp1.end(), temp2.begin(), temp2.end());
                }
            }*/
            }
            //KMeans ktest = KMeans(clusters, cluster_iterations,
            // ml_net->layers()->size() * size_of_embedding, ml_net->actors()->size(),
            //w2v_embedding_map, &generator);
            //ktest.run();
            //ktest.print_clusters();
            return w2v_embedding_map;
            //ktest.run_cos();
            //ktest.print_clusters();
        }

        std::unordered_map<std::string, w2v::vector_t> algo_3_MG(uu::net::MultilayerNetwork *ml_net, float r, float p, float q, int size_of_embedding, int len_rand_walk, int numb_rand_walks, int clusters,
                                                                 int window, int cluster_iterations, std::string alpha, std::string sample,
                                                                 int iterations, int min_word_freq, int negative_sample, int threads)
        {
            auto sampling_map_ml = std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<Vertex>>>>();
            for (auto layer : *ml_net->layers())
            {
                auto sampling_map_sl = std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<Vertex>>>();
                set_rw_probs(layer, sampling_map_sl, p, q);
                sampling_map_ml.insert({layer, sampling_map_sl});
            }

            // Take the special multigraph random walk
            std::default_random_engine generator;
            auto random_walks = random_walks_ml(ml_net, sampling_map_ml, generator, r, len_rand_walk, numb_rand_walks);

            w2v::trainSettings_t trainSettings;
            trainSettings.size = static_cast<uint16_t>(size_of_embedding);
            trainSettings.window = static_cast<uint8_t>(window);
            trainSettings.sample = std::stof(sample);
            trainSettings.negative = static_cast<uint8_t>(negative_sample);
            trainSettings.threads = static_cast<uint8_t>(threads);
            trainSettings.iterations = static_cast<uint8_t>(iterations);
            trainSettings.minWordFreq = static_cast<uint16_t>(min_word_freq);
            trainSettings.alpha = std::stof(alpha);
            trainSettings.withSG = true;

            std::ofstream myfile;
            myfile.open("word2vecinput.txt");
            for (auto sentence : random_walks)
            {
                myfile << sentence;
            }
            myfile.close();

            std::string trainFile = "word2vecinput.txt";
            std::string modelFile = "trained_nodes.w2v";
            auto w2v_model = train_w2v(trainFile, modelFile, trainSettings);
            return w2v_model.map();
            //KMeans ktest = KMeans(clusters, cluster_iterations, size_of_embedding, ml_net->actors()->size(), w2v_model.map(), &generator);
            //ktest.run();
            //ktest.print_clusters();
            //ktest.summary();
        }

        std::unordered_map<std::string, w2v::vector_t> algo_3_MG_new(uu::net::MultilayerNetwork *ml_net, LayerSwapMetric lswap_metric, float r, float p, float q, int size_of_embedding, int len_rand_walk, int numb_rand_walks, int clusters,
                           int window, int cluster_iterations, std::string alpha, std::string sample,
                           int iterations, int min_word_freq, int negative_sample, int threads)
        {
            auto sampling_map_ml = std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>>();
            auto interlayer_map = std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Network *, AliasTable<uu::net::Network>>>();
            for (auto layer : *ml_net->layers())
            {
                auto sampling_map_sl = std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>();
                set_rw_probs(layer, sampling_map_sl, p, q);
                sampling_map_ml.insert({layer, sampling_map_sl});
            }

            set_interlayer_probs(ml_net, interlayer_map, lswap_metric);

            // Take the special multigraph random walk
            std::default_random_engine generator;
            auto random_walks = random_walks_ml_fancy(ml_net, sampling_map_ml, interlayer_map, generator, r, len_rand_walk, numb_rand_walks);

            w2v::trainSettings_t trainSettings;
            trainSettings.size = static_cast<uint16_t>(size_of_embedding);
            trainSettings.window = static_cast<uint8_t>(window);
            trainSettings.sample = std::stof(sample);
            trainSettings.negative = static_cast<uint8_t>(negative_sample);
            trainSettings.threads = static_cast<uint8_t>(threads);
            trainSettings.iterations = static_cast<uint8_t>(iterations);
            trainSettings.minWordFreq = static_cast<uint16_t>(min_word_freq);
            trainSettings.alpha = std::stof(alpha);
            trainSettings.withSG = true;

            std::ofstream myfile;
            myfile.open("word2vecinput.txt");
            for (auto sentence : random_walks)
            {
                myfile << sentence;
            }
            myfile.close();

            std::string trainFile = "word2vecinput.txt";
            std::string modelFile = "trained_nodes.w2v";
            auto w2v_model = train_w2v(trainFile, modelFile, trainSettings);
            return w2v_model.map();
        }

        std::unordered_map<std::string, w2v::vector_t> algo_3_MG_new_nor(uu::net::MultilayerNetwork *ml_net, LayerSwapMetric lswap_metric, float p ,float q , int size_of_embedding , int len_rand_walk, int numb_rand_walks , int clusters ,
                                int window , int cluster_iterations , std::string alpha ,  std::string sample ,
                                int iterations , int min_word_freq , int negative_sample, int threads ) {
            
        auto sampling_map_ml = std::unordered_map<const uu::net::Network *, std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>>();
        auto interlayer_map=std::unordered_map<const uu::net::Vertex *,std::unordered_map<const uu::net::Network*, AliasTable<uu::net::Network>>>();
        for (auto layer : *ml_net->layers())
        {
            auto sampling_map_sl = std::unordered_map<const uu::net::Vertex *, std::unordered_map<const uu::net::Vertex *, AliasTable<uu::net::Vertex>>>();
            set_rw_probs(layer, sampling_map_sl, p, q);
            sampling_map_ml.insert({layer, sampling_map_sl});
        }
        std::cout << "setting interlayer probs" << std::endl;
        set_interlayer_probs_nor(ml_net,interlayer_map, lswap_metric);
        std::cout << "interlayer probs set" << std::endl;
        
        std::cout << "randwalks start" << std::endl;
        // Take the special multigraph random walk
        std::default_random_engine generator;
        auto random_walks = random_walks_ml_nor(ml_net,sampling_map_ml,interlayer_map,generator,len_rand_walk,numb_rand_walks);
        std::cout << "randwalks done" << std::endl;

        w2v::trainSettings_t trainSettings;
        trainSettings.size = static_cast<uint16_t>(size_of_embedding);
        trainSettings.window = static_cast<uint8_t>(window);
        trainSettings.sample = std::stof(sample);
        trainSettings.negative = static_cast<uint8_t>(negative_sample);
        trainSettings.threads = static_cast<uint8_t>(threads);
        trainSettings.iterations = static_cast<uint8_t>(iterations);
        trainSettings.minWordFreq = static_cast<uint16_t>(min_word_freq);
        trainSettings.alpha = std::stof(alpha);
        trainSettings.withSG = true;

        
        std::ofstream myfile;
        myfile.open("word2vecinput.txt");
        for (auto sentence : random_walks)
        {
                myfile << sentence;
        }
        myfile.close();

        std::string trainFile = "word2vecinput.txt";
        std::string modelFile = "trained_nodes.w2v";
        auto w2v_model = train_w2v(trainFile, modelFile, trainSettings);
        return w2v_model.map();
        
    }
    } // namespace net
} // namespace uu
