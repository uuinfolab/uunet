#include "KMeans.hpp"
namespace uu
{
    namespace net
    {
        KMeans::Point::Point()
        {
            name = std::string();
        }

        KMeans::Point::Point(const std::string & _name)
        {
            name = _name;
        }

        KMeans::Cluster::Cluster(int dims, std::default_random_engine *gen)
        {
            cluster_size = 0;
            dimensions = dims;
            generator = gen;
            cluster_mean = std::vector<float>(dimensions);
            points_within = std::vector<Point *>();
            my_points = std::vector<Point>();
        }

        void KMeans::Cluster::add(Point &p)
        {
            points_within.push_back(&p);
            my_points.push_back(p);
            cluster_size += 1;
        }

        void KMeans::Cluster::randomize_mean()
        {
            std::uniform_real_distribution<float> distribution(0.0, 2.0);
            for (auto &value : cluster_mean)
            {
                value = distribution(*generator) - 1.0;
            }
        }

        void KMeans::Cluster::reset_points()
        {
            points_within.resize(0);
            my_points.resize(0);
            cluster_size = 0;
        }

    

        KMeans::KMeans(int K, int iterations, int vec_dimensions, int num_points, const std::unordered_map<std::string, w2v::vector_t> &input_map,
               std::default_random_engine *gen) : point_map(input_map)
        {
            this->K = K;
            num_of_iterations = iterations;
            dimensions = vec_dimensions;
            num_of_points = num_points;
            generator = gen;
            for (int i = 0; i < K; i++)
            {
                K_clusters.emplace_back(std::make_unique<Cluster>(dimensions, generator));
            }
            for (auto map_entry : point_map)
            {
                all_points.emplace_back(std::make_unique<Point>(map_entry.first));
            }
        }

        float KMeans::distance(Point &point, Cluster *target)
        {
            float distance = 0;
            for (int i = 0; i < dimensions; i++)
            {
                float temp = get_position(point)[i] - (target->cluster_mean)[i];
                distance += (temp * temp);
            }
            return sqrt(distance);
        }

        float KMeans::distance_cos(Point &point, Cluster *target)
        {
            float length_point = 0;
            float length_mean = 0;
            for (int i = 0; i < dimensions; i++)
            {
                length_point += get_position(point)[i] * get_position(point)[i];
                length_mean += (target->cluster_mean)[i] * (target->cluster_mean)[i];
            }
            length_point = sqrt(length_point);
            length_mean = sqrt(length_mean);

            float distance = 0;
            for (int i = 0; i < dimensions; i++)
            {
                distance += (get_position(point)[i] / length_point) * ((target->cluster_mean)[i] / length_mean);
            }
            return sqrt(distance);
        }

        const w2v::vector_t KMeans::get_position(Point &point)
        {
            return point_map.at(point.name);
        }

        void KMeans::find_join_nearest(Point &point, std::vector<std::unique_ptr<Cluster>> &clusters)
        {
            Cluster *target = clusters.at(0).get();
            float min_dist = distance(point, target);
            for (auto &cluster : clusters)
            {
                float temp = distance(point, cluster.get());
                if (temp < min_dist)
                {
                    min_dist = temp;
                    target = cluster.get();
                }
            }
            target->add(point);
        }

        void KMeans::find_join_nearest_cos(Point &point, std::vector<std::unique_ptr<Cluster>> &clusters)
        {
            Cluster *target = clusters.at(0).get();
            float max_dist = distance_cos(point, target);
            for (auto &cluster : clusters)
            {
                float temp = distance(point, cluster.get());
                if (temp > max_dist)
                {
                    max_dist = temp;
                    target = cluster.get();
                }
            }
            target->add(point);
        }

        void KMeans::initialize_mean(Cluster *cluster)
        {
            std::uniform_real_distribution<float> distribution(0, num_of_points - 1);
            int rand_index = distribution(*generator);
            for (int i = 0; i < dimensions; i++)
            {
                cluster->cluster_mean[i] = get_position(*all_points[rand_index]).at(i);
            }
        }

        void KMeans::update_mean(Cluster *cluster)
        {
            if (cluster->cluster_size == 0)
            {
            }
            else
            {
                std::vector<float> temp(dimensions, 0);
                for (auto point : cluster->my_points)
                {
                    for (int i = 0; i < dimensions; i++)
                    {
                        temp[i] += (get_position(point))[i];
                    }
                }
                float norm_factor = 1.0 / cluster->cluster_size;
                for (int i = 0; i < dimensions; i++)
                {
                    temp[i] *= norm_factor;
                    (cluster->cluster_mean)[i] = temp[i];
                }
            }
        }

        void KMeans::run()
        {
            std::cout << std::endl
                 << "Running K-means, K=" << (K) << "," << (num_of_iterations) << " iterations.\n"
                 << std::endl;
            //cout << "Initializing clusters\n";
            for (auto &cluster : K_clusters)
            {
                initialize_mean(cluster.get());
            }
            //cout << "Initialized clusters\n";
            for (int i = 1; i <= num_of_iterations; i++)
            {
                for (auto &point : all_points)
                {
                    find_join_nearest(*point, K_clusters);
                }
                for (auto &cluster : K_clusters)
                {
                    update_mean(cluster.get());
                    cluster->reset_points();
                }
            }
            for (auto &point : all_points)
            {
                find_join_nearest(*point, K_clusters);
            }
        }

        void KMeans::run_cos()
        {
            std::cout << std::endl
                 << "Running K-means, K=" << (K) << "," << (num_of_iterations) << " iterations, cos distance.\n"
                 << std::endl;
            std::cout << "Initializing clusters\n";
            for (auto &cluster : K_clusters)
            {
                initialize_mean(cluster.get());
            }
            std::cout << "Initialized clusters\n";
            for (int i = 1; i <= num_of_iterations; i++)
            {
                for (auto &point : all_points)
                {
                    find_join_nearest_cos(*point, K_clusters);
                }
                for (auto &cluster : K_clusters)
                {
                    update_mean(cluster.get());
                    cluster->reset_points();
                }
            }
            for (auto &point : all_points)
            {
                find_join_nearest_cos(*point, K_clusters);
            }
            for (auto &cluster : K_clusters)
            {
                update_mean(cluster.get());
            }
        }

        void KMeans::print_means()
        {
            for (int i = 1; i <= K; i++)
            {
                std::cout << "Cluster:" << (i) << ", size:" << (K_clusters[i - 1]->cluster_size) << std::endl;
                std::cout << "Cluster:" << (i) << ", centroid: [";
                for (auto value : K_clusters[i - 1]->cluster_mean)
                {
                    std::cout << (value) << " ";
                }
                std::cout << "]\n";
            }
        }
        /*
        void KMeans::print_points()
        {
            std::cout << "ppoints\n";
            for (auto &point : all_points)
            {
                std::cout << "Point:" << point->name << " [";
                std::cout << "]\n";
            }
        } */

        void KMeans::print_cluster(int k)
        {
            std::cout << "Cluster:" << k << "\n";
            std::cout << "[ ";
            for (auto point : K_clusters[k]->my_points)
            {
                std::cout << point.name << " ";
            }
            std::cout << "]\n";
        }

        void KMeans::print_clusters()
        {
            for (int i = 0; i < K; i++)
            {
                print_cluster(i);
            }
        }

        void KMeans::summary()
        {
            std::cout << std::endl
                 << "K-means, K=" << (K) << "," << (num_of_iterations) << " iterations.\n"
                 << std::endl;
            print_means();
        }
    } // namespace net
} // namespace uu
