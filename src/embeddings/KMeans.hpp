#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <include/word2vec.hpp>
#include "io/read_multilayer_network.hpp"
#include "community/CommunityStructure.hpp"
namespace uu
{
    namespace net
    {
        class KMeans
        {

        public:
            
            class Point
            {
            public:
                std::string name;
                Point();
                Point(const std::string &_name);
            };

            class Cluster
            {
            public:
                int cluster_size;
                int dimensions;
                std::default_random_engine *generator;
                std::vector<float> cluster_mean;
                std::vector<Point *> points_within;
                std::vector<Point> my_points;

                // Basic constructor
                // initializes an empty cluster with random mean
                Cluster(int dims, std::default_random_engine *gen);
                void add(Point &p);
                void randomize_mean();
                void reset_points();
            };

            std::unique_ptr<uu::net::CommunityStructure<uu::net::MultilayerNetwork>> communities;
            std::vector<std::shared_ptr<Cluster>> K_clusters_best;
            KMeans(int k_min,int k_max, uu::net::MultilayerNetwork * ml_net, int iterations, const std::unordered_map<std::string, w2v::vector_t> &input_map, std::string metric = "Euclidian");
            
            
            void print_clusters();
            void print_cluster_data_to_file(std::string output_file_name);

        private:
            std::vector<std::unique_ptr<Point>> all_points;
            int dimensions, num_of_points;
            std::default_random_engine generator = std::default_random_engine();
            const std::unordered_map<std::string, w2v::vector_t> &point_map;
            std::vector<std::shared_ptr<KMeans::Cluster>> create_clustering(int,int,std::string metric = "Euclidian");

            float distance(Point &point, Cluster *target);
            float distance_cos(Point &point, Cluster *target);

            const w2v::vector_t get_position(Point &point);

            void find_join_nearest(Point &point, std::vector<std::shared_ptr<Cluster>> &clusters);
            void find_join_nearest_cos(Point &point, std::vector<std::shared_ptr<Cluster>> &clusters);

            void initialize_means(std::vector<std::shared_ptr<uu::net::KMeans::Cluster>>& K_clusters, int K);
            void initialize_means_cos(std::vector<std::shared_ptr<uu::net::KMeans::Cluster>>& K_clusters, int K);

            void update_mean(Cluster *cluster);
            void update_mean_cos(Cluster *cluster);

            float distance(Point &point, Point &point_1);
            float distance_cos(Point &point,Point &point_1);

            float silhouette_score(std::vector<std::shared_ptr<KMeans::Cluster>> & K_clusters, int K);
            float silhouette_score_cos(std::vector<std::shared_ptr<KMeans::Cluster>> & K_clusters, int K);
        };
    } // namespace net
} // namespace uu
