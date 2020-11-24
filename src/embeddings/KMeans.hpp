#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <include/word2vec.hpp>
namespace uu
{
    namespace net
    {
        class KMeans
        {

        public:
            int K, num_of_iterations;
            int dimensions, num_of_points;
            std::default_random_engine *generator;
            const std::unordered_map<std::string, w2v::vector_t> &point_map;

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

            std::vector<std::unique_ptr<Cluster>> K_clusters;
            std::vector<std::unique_ptr<Point>> all_points;

            KMeans(int K, int iterations, int vec_dimensions, int num_points, const std::unordered_map<std::string, w2v::vector_t> &input_map,
                   std::default_random_engine *gen);
            void run();
            void run_cos();
            void print_means();
            void print_cluster(int k);
            void print_clusters();
            void summary();

        private:
            float distance(Point &point, Cluster *target);
            float distance_cos(Point &point, Cluster *target);
            const w2v::vector_t get_position(Point &point);
            void find_join_nearest(Point &point, std::vector<std::unique_ptr<Cluster>> &clusters);
            void find_join_nearest_cos(Point &point, std::vector<std::unique_ptr<Cluster>> &clusters);
            void initialize_mean(Cluster *cluster);
            void update_mean(Cluster *cluster);  
        };
    } // namespace net
} // namespace uu
