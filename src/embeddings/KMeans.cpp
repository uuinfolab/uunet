#include "KMeans.hpp"
namespace uu
{
    namespace net
    {
        KMeans::Point::Point()
        {
            name = std::string();
        }

        KMeans::Point::Point(const std::string &_name)
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

        void KMeans::Cluster::reset_points()
        {
            points_within.resize(0);
            my_points.resize(0);
            cluster_size = 0;
        }

        KMeans::KMeans(int k_min, int k_max, uu::net::MultilayerNetwork *ml_net, int iterations, const std::unordered_map<std::string, w2v::vector_t> &input_map, std::string metric) : point_map(input_map)
        {
            dimensions = input_map.begin()->second.size();
            num_of_points = ml_net->actors()->size();
            for (auto map_entry : point_map)
            {
                all_points.emplace_back(std::make_unique<Point>(map_entry.first));
            }
            float silhouette_score_current = -2; //magic number
            float silhouette_score_best = silhouette_score_current;
            int k_best = k_min;
            if (k_max > num_of_points)
            {
                std::cout << "kmax was bigger than number of points, changed it to number of points" << std::endl;
                k_max = num_of_points;
            }
            for (int i = k_min; i <= k_max; i++)
            {
                auto K_clusters_current = create_clustering(i, iterations, metric);
                if (metric == "Euclidian")
                {
                    silhouette_score_current = silhouette_score(K_clusters_current, i);
                }
                else if (metric == "Cosine")
                {
                    silhouette_score_current = silhouette_score_cos(K_clusters_current, i);
                }
                else
                {
                    throw "not a proper distance metric";
                }
                if (silhouette_score_current > silhouette_score_best)
                {
                    K_clusters_best.clear();
                    K_clusters_best = K_clusters_current;
                    silhouette_score_best = silhouette_score_current;
                    k_best = i;
                }
            }

            communities = std::make_unique<uu::net::CommunityStructure<uu::net::MultilayerNetwork>>();
            for (int i = 0; i < k_best; i++)
            {

                auto community = std::make_unique<uu::net::Community<uu::net::MultilayerNetwork>>();
                for (auto value : K_clusters_best[i]->my_points)
                {
                    for (auto layer : *ml_net->layers())
                    {
                        if (layer->vertices()->contains(ml_net->actors()->get(value.name)))
                        {
                            auto v = uu::net::MLVertex<uu::net::MultilayerNetwork>(ml_net->actors()->get(value.name), layer);
                            community->add(v);
                        }
                    }
                }
                communities->add(std::move(community));
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
            return std::sqrt(distance);
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
            float normalizing_const = std::sqrt(length_point * length_mean);

            float distance = 0;
            for (int i = 0; i < dimensions; i++)
            {
                distance += (get_position(point)[i]) * ((target->cluster_mean)[i]);
            }
            return 1.0 - distance / normalizing_const;
        }

        const w2v::vector_t KMeans::get_position(Point &point)
        {
            return point_map.at(point.name);
        }

        void KMeans::find_join_nearest(Point &point, std::vector<std::shared_ptr<Cluster>> &clusters)
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

        void KMeans::find_join_nearest_cos(Point &point, std::vector<std::shared_ptr<Cluster>> &clusters)
        {
            Cluster *target = clusters.at(0).get();
            float max_dist = distance_cos(point, target);
            for (auto &cluster : clusters)
            {
                float temp = distance_cos(point, cluster.get());
                if (temp > max_dist)
                {
                    max_dist = temp;
                    target = cluster.get();
                }
            }
            target->add(point);
        }

        void KMeans::initialize_means(std::vector<std::shared_ptr<uu::net::KMeans::Cluster>> &K_clusters, int K)
        {

            std::uniform_real_distribution<float> distribution(0, num_of_points - 1);

            std::set<int> init_index;
            while (init_index.size() < K)
            {
                int rand_index = std::round(distribution(generator));
                init_index.insert(rand_index);
            }
            for (int j = 0; j < K; j++)
            {
                auto index = *std::next(init_index.begin(), j);
                auto position = get_position(*all_points[index]);
                for (int i = 0; i < dimensions; i++)
                {
                    K_clusters.at(j)->cluster_mean[i] = position.at(i);
                }
            }
        }

        void KMeans::initialize_means_cos(std::vector<std::shared_ptr<uu::net::KMeans::Cluster>> &K_clusters, int K)
        {
            std::uniform_real_distribution<float> distribution(0, num_of_points - 1);
            std::set<int> init_index;
            while (init_index.size() < K)
            {
                int rand_index = std::round(distribution(generator));
                init_index.insert(rand_index);
            }
            for (int j = 0; j < K; j++)
            {
                auto index = *std::next(init_index.begin(), j);
                auto position = get_position(*all_points[index]);
                float normalizing_const = 0.0;
                for (int i = 0; i < dimensions; i++)
                {
                    normalizing_const += position.at(i) * position.at(i);
                }
                normalizing_const = std::sqrt(normalizing_const);
                for (int i = 0; i < dimensions; i++)
                {
                    K_clusters.at(j)->cluster_mean[i] = position.at(i) / normalizing_const;
                }
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

        void KMeans::update_mean_cos(Cluster *cluster)
        {
            if (cluster->cluster_size == 0)
            {
            }
            else
            {
                std::vector<float> temp(dimensions, 0);
                for (auto point : cluster->my_points)
                {
                    float normalizing_const = 0.0;
                    for (int i = 0; i < dimensions; i++)
                    {
                        normalizing_const += (get_position(point))[i] * (get_position(point))[i];
                    }
                    normalizing_const = std::sqrt(normalizing_const);
                    for (int i = 0; i < dimensions; i++)
                    {
                        temp[i] += (get_position(point))[i] / normalizing_const;
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

        std::vector<std::shared_ptr<KMeans::Cluster>> KMeans::create_clustering(int K, int iters, std::string metric)
        {
            auto K_clusters = std::vector<std::shared_ptr<Cluster>>();
            for (int i = 0; i < K; i++)
            {
                K_clusters.emplace_back(std::make_unique<Cluster>(dimensions, &generator));
            }
            if (metric == "Euclidian")
            {
                initialize_means(K_clusters, K);
                for (int i = 1; i <= iters; i++)
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
                return K_clusters;
            }
            else if (metric == "Cosine")
            {
                initialize_means_cos(K_clusters, K);

                for (int i = 1; i <= iters; i++)
                {
                    for (auto &point : all_points)
                    {
                        find_join_nearest_cos(*point, K_clusters);
                    }
                    for (auto &cluster : K_clusters)
                    {
                        update_mean_cos(cluster.get());
                        cluster->reset_points();
                    }
                }
                for (auto &point : all_points)
                {
                    find_join_nearest_cos(*point, K_clusters);
                }
                return K_clusters;
            }
            else
            {
                throw (std::string)"not a valid metric";
            }
        }

        float KMeans::distance(Point &point, Point &point_1)
        {
            float distance = 0;
            for (int i = 0; i < dimensions; i++)
            {
                float temp = get_position(point)[i] - get_position(point_1)[i];
                distance += (temp * temp);
            }
            return std::sqrt(distance);
        }

        float KMeans::distance_cos(Point &point, Point &point_1)
        {
            float length_point = 0;
            float length_point_1 = 0;
            for (int i = 0; i < dimensions; i++)
            {
                length_point += get_position(point)[i] * get_position(point)[i];
                length_point_1 += get_position(point_1)[i] * get_position(point_1)[i];
            }
            float normalizing_const = std::sqrt(length_point * length_point_1);

            float distance = 0;
            for (int i = 0; i < dimensions; i++)
            {
                distance += (get_position(point)[i]) * (get_position(point_1)[i]);
            }
            return 1.0 - distance / normalizing_const;
        }

        float KMeans::silhouette_score(std::vector<std::shared_ptr<KMeans::Cluster>> &K_clusters, int K)
        {
            std::vector<float> s_i = std::vector<float>(all_points.size());
            float a_i = 0;
            float b_i = 0;
            int index = 0;
            int cluster_counter = 0;
            for (auto &&c : K_clusters)
            {
                if (c->cluster_size == 1 && c->cluster_size == 0)
                {
                    s_i[index] = 0;
                    index++;
                }
                for (auto p : c->my_points)
                {
                    a_i = 0;
                    b_i = 0;
                    for (auto p_neighb : c->my_points)
                    {
                        a_i += distance(p, p_neighb);
                    }
                    a_i /= (c->cluster_size - 1);
                    auto dist = std::vector<float>(K - 1);
                    int local_cluster_counter = 0;
                    int local_index = 0;
                    for (auto &&c_other : K_clusters)
                    {
                        if (local_cluster_counter == cluster_counter)
                        {
                            local_cluster_counter++;
                            continue;
                        }
                        for (auto p_other_cluster : c_other->my_points)
                        {
                            dist[local_index] += distance(p, p_other_cluster);
                        }
                        local_cluster_counter++;
                        dist[local_index] /= c_other->cluster_size;
                        local_index++;
                    }
                    b_i = *min_element(dist.begin(), dist.end());
                    s_i[index] = (b_i - a_i) / std::max(b_i, a_i);
                    index++;
                }
                cluster_counter++;
            }
            return std::accumulate(s_i.begin(), s_i.end(), 0.0) / s_i.size();
        }

        float KMeans::silhouette_score_cos(std::vector<std::shared_ptr<KMeans::Cluster>> &K_clusters, int K)
        {
            std::vector<float> s_i = std::vector<float>(all_points.size());
            float a_i = 0;
            float b_i = 0;
            int index = 0;
            int cluster_counter = 0;
            for (auto &&c : K_clusters)
            {
                if (c->cluster_size == 1 && c->cluster_size == 0)
                {
                    s_i[index] = 0;
                    index++;
                }
                for (auto p : c->my_points)
                {
                    a_i = 0;
                    b_i = 0;

                    for (auto p_neighb : c->my_points)
                    {
                        a_i += distance_cos(p, p_neighb);
                    }
                    a_i /= (c->cluster_size - 1);
                    auto dist = std::vector<float>(K - 1);
                    int local_cluster_counter = 0;
                    int local_index = 0;
                    for (auto &&c_other : K_clusters)
                    {
                        if (local_cluster_counter == cluster_counter)
                        {
                            local_cluster_counter++;
                            continue;
                        }
                        for (auto p_other_cluster : c_other->my_points)
                        {
                            dist[local_index] += distance_cos(p, p_other_cluster);
                        }
                        local_cluster_counter++;
                        dist[local_index] /= c_other->cluster_size;
                        local_index++;
                    }
                    b_i = *min_element(dist.begin(), dist.end());
                    s_i[index] = (b_i - a_i) / std::max(b_i, a_i);
                    index++;
                }
                cluster_counter++;
            }
            return std::accumulate(s_i.begin(), s_i.end(), 0.0) / s_i.size();
        }

        void KMeans::print_clusters()
        {

            int cluster_clock = 1;

            for (auto cluster : K_clusters_best)
            {
                std::cout << "Cluster:" << cluster_clock << "\n";
                std::cout << "[ ";

                for (auto point : cluster->my_points)
                {
                    std::cout << point.name << " ";
                }
                std::cout << " Cluster mean: ";
                for (auto p : cluster->cluster_mean)
                {
                    std::cout << p << " ";
                }
                cluster_clock += 1;
                std::cout << "]\n";
            }
        }

        void KMeans::print_cluster_data_to_file(std::string output_file_name) {
            std::ofstream  output(output_file_name);

            int cluster_clock = 1;

            for (auto cluster : K_clusters_best) {
                for (auto point : cluster->my_points) {
                    output << cluster_clock << " " <<point.name  << " " << "Point coord.: ";
                    for (auto point_coord : point_map.at(point.name)) {
                        output << point_coord << " ";
                    }
                    output << "Cluster mean: ";
                    for (auto mean_coord : cluster->cluster_mean)
                    {
                        output << mean_coord << " ";
                    }
                    output << "\n";
                }
                cluster_clock += 1;
            }
            output.close();
        }

    } // namespace net
} // namespace uu
