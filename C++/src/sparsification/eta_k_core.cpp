/**
 * History:
 * - 2020.03.11 file created by Oskar
 **/

#include "networks/ProbabilisticNetwork.hpp"
#include "sparsification/utils.hpp"
#include "sparsification/eta_k_core.hpp"
#include "measures/degree.hpp"


namespace uu {
namespace net {



/**
 * This function returns the eta value of a given probability density distribution
 * @param density_distribution probability density distribution
 * @param eta_threshold eta threshold
 * @return the eta value of probability density distribution
  **/
int
density_distribution_eta_value
(
    std::vector<double> density_distribution,
    double eta_threshold
)
{
    int len = density_distribution.size();
    if (len < 2)
    {
        len = 2;
    }

    std::vector<double> dd_ecdf(len);
    dd_ecdf[0] = 1;
    for (int i = 1; i < len; i++)
    {
        dd_ecdf[i] = dd_ecdf[i-1] - density_distribution[i-1];
    }
    int i = len;
    while (eta_threshold > dd_ecdf[i])
    {
        i = i-1;
    }
    if (i<=0)
    {
        i=0;
    } else {
        i = i-1;
    }
    return i;
}


/**
 * Adds newP to the distribution and rebalances it
 * @param density_distribution density diftribution
 * @param newP probability of an event to be added
 * @return probability density distribution
 **/
std::vector<double>
Poisson_Binomial_density_add_p
(
    std::vector<double> density_distribution,
    double newP
)
{
    double newQ = 1 - newP;
    int len = density_distribution.size();
    std::vector<double> new_density_distribution(len+1);
    new_density_distribution[0] = density_distribution[0] * newQ;
    int i = 1;
    while (i < len) {
        new_density_distribution[i] = density_distribution[i] * newQ + newP * density_distribution[i-1];
        i = i + 1;
    }
    new_density_distribution[len] = newP*density_distribution[len];
    return new_density_distribution;
}

/**
 * Removes the last element of the destribution
 * @param density_distribution density diftribution
 * @param oldP probability of an event to be removed
 * @return probability density distribution
 * @export
 **/
std::vector<double> 
Poisson_Binomial_density_delete_p
(
    std::vector<double> density_distribution,
    double oldP
)
{
    double oldQ = 1 - oldP;
    int len = density_distribution.size();
    std::vector<double> new_density_distribution(len-1);
    new_density_distribution[0] = (density_distribution[0] / oldQ);
    int i = 1;
    while (i < len - 1) {
        new_density_distribution[i] = ((density_distribution[i] - oldP * new_density_distribution[i-1]) / oldQ);
        i = i + 1;
    }
    return new_density_distribution;
}

/**
 * This function returns density function of a Poisson-Binomial distribution. 
 * It is an implementation of the algorithm proposed in "Closed-Form Expression for the Poisson-Binomial Probability Density Function".
 * @param success_prob probability of success in different trials
 * @return probability density function of a Poisson-Binomial distribution up to deg
 **/
std::vector<double>
efficient_Poisson_Binomial_density_function
(
    std::vector<double> success_prob
)
{
    int len = success_prob.size();
    std::vector<double> current_degree_distribution(len);
    current_degree_distribution[0] = ((double)1-success_prob[0]);
    if (len > 1)
    {
        current_degree_distribution[1] = (success_prob[0]);
    }
    for (int i = 1; i < len; i++)
    {
        current_degree_distribution = Poisson_Binomial_density_add_p( current_degree_distribution, success_prob[i] );
    }
    return current_degree_distribution;
}


/**
 * This function returns the (eta_k)-core value of all nodes in a probabilistic graph introduced in paper "Core Decomposition of Uncertain Graphs"
 * @param original_graph input probabilistic graph
 * @param eta_threshold eta threshold
 * @return the (eta,k)-core of a probabilistic graph
  **/
std::vector<int>
eta_k_core(
    ProbabilisticNetwork * original_graph,
    double eta_threshold
)
{
    // initialize
    auto probGraph = duplicate_graph(original_graph);
    int n = maximum_degree(probGraph.get());
    int dim = probGraph->vertices()->size();

    std::vector<std::string> stringAtIndex (dim);
    std::unordered_map<std::string, int> indexAtString; 
    std::vector<int> core(dim);
    std::vector<int> ddev(dim);
    std::vector<std::vector<double>> D(n);
    std::vector<std::vector<double>> densities(dim);

    for (auto vertex: *probGraph->vertices())
    {
        int index = probGraph->vertices()->index_of(vertex);
        std::string name = vertex->to_string();
        stringAtIndex[index] = name;
        indexAtString[name] = index;
    }

    // line 3 to 6
    for (auto vertex: *probGraph->vertices()){
       
        auto len = probGraph->edges()->incident(vertex)->size();
        int v_index = indexAtString[vertex->to_string()];
        std::vector<double> P;
        P.reserve(len);
        for (auto edge: *probGraph->edges()->incident(vertex))
        {
            P.push_back(probGraph->get_prob(edge).value);
        }
        auto dist_v = efficient_Poisson_Binomial_density_function(P);
        ddev[v_index] = density_distribution_eta_value(dist_v, eta_threshold);
        densities[v_index] = dist_v;
        D[ddev[v_index]].push_back(v_index);
    }

    // line 7 to 17
    for (int k = 0; k < n; k++)
    {
        while (D[k].size() > 0)
        {
            int candidate_node = D[ k ].back();
            D[k].pop_back();
            core[candidate_node] = k + 1;

            // line 11 to 15
            auto rem_node = probGraph->vertices()->get(stringAtIndex[candidate_node]);
            for(auto neighbor: *probGraph->edges()->neighbors(rem_node))
            {
                int neighbor_i = indexAtString[neighbor->to_string()];
                if (ddev[neighbor_i] > k + 1 ) 
                {
                    auto edge = probGraph->edges()->get(rem_node, neighbor);
                    double prob = probGraph->get_prob(edge).value;
                    auto u_new_dd = Poisson_Binomial_density_delete_p(densities[neighbor_i], prob);
                    densities[neighbor_i]= u_new_dd;
                    auto prev_deg_u = ddev[neighbor_i];
                    ddev[neighbor_i] = density_distribution_eta_value(u_new_dd, eta_threshold);
                    
                    // line 13
                    D[prev_deg_u].erase(std::remove(D[prev_deg_u].begin(), D[prev_deg_u].end(), neighbor_i), D[prev_deg_u].end());      
                    D[ddev[neighbor_i] ].push_back(neighbor_i);
                }
            }
            probGraph->vertices()->erase(rem_node);
        }
    }
    return core;
}


}
}
