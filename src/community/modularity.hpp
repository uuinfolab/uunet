#ifndef UU_MNET_COMMUNITY_MODULARITY_H_
#define UU_MNET_COMMUNITY_MODULARITY_H_

#include <unordered_map>
#include <numeric>
#include <utility>
#include "objects/EdgeMode.hpp"
#include "networks/ProbabilisticNetwork.hpp"

#undef CS

namespace uu {
namespace net {

template <typename G, typename CS>
double
modularity(const G* g, const CS* communities)
{

    double res = 0;
    size_t m = g->edges()->size();
    if (m==0) return 0;

    for (auto community: *communities)
    {
        for (auto i: *community)
        {
            for (auto j: *community)
            {
                int k_i = g->edges()->neighbors(i,EdgeMode::OUT)->size();
                int k_j = g->edges()->neighbors(j,EdgeMode::IN)->size();
                int a_ij = g->edges()->get(i, j) ? 1 : 0;
                res += a_ij - (double)k_i * k_j / (2.0*m);
                //std::cout << i->name << " " << j->name << " " << a_ij << " " << k_i << " " <<  k_j << " " <<  m << std::endl;
                //std::cout << "  ->" << res << std::endl;
            }
        }
    }

    return res / (2.0*m);
}

template <typename CS>
double
modularity(const ProbabilisticNetwork* g, const CS* communities)
{

    double res = 0;
    double m = 0;
    for (auto e: *g->edges())
    {
        auto p = g->get_prob(e);
        if (!p.null) m += p.value;
    }
    if (m==0) return 0;

    for (auto community: *communities)
    {
        for (auto i: *community)
        {
            for (auto j: *community)
            {
                double k_i = exp_degree(g, i);
                double k_j = exp_degree(g, j);
                auto e = g->edges()->get(i, j);
                double a_ij = 0;
                if (e) {
                    auto p = g->get_prob(e);
                    if (!p.null) a_ij = p.value;
                }
                res += a_ij - (double)k_i * k_j / (2*m);
                //std::cout << i->name << " " << j->name << " " << k_i << " " <<  k_j << " " <<  m << std::endl;
                //std::cout << "->" << res << std::endl;
            }
        }
    }

    return res / (2*m);
}


template <typename M, typename CS>
double
modularity(const M* mnet, const CS* communities, double omega)
{

    double res = 0;
    double mu = 0;

    std::unordered_map<std::string,int> m_s;

    for (auto s: *mnet->layers())
    {
        double m = s->edges()->size();

        if (!s->is_directed())
        {
            m *= 2;
        }

        // FIX TO THE ORIGINAL EQUATION WHEN THERE ARE NO EDGES
        if (m == 0)
        {
            m = 1;    // no effect on the formula
        }

        m_s[s->name] = m;
        mu += m;
    }

    for (auto community: *communities)
    {
        for (auto i: *community)
        {
            for (auto j: *community)
            {
                if (i==j)
                {
                    continue;    // not in the original definition - we do this assuming to deal with simple graphs
                }

                //std::cout << i->to_string() << " " << groups.count(i) << std::endl;
                //std::cout << j->to_string() << " " << groups.count(j) << std::endl;

                // same layer
                if (i.l==j.l)
                {
                    //std::cout << "Same group!" << std::endl;
                    //if (mnet.getNetwork(net)->containsEdge(*v_i,*v_j))
                    //    std::cout << "Edge" << std::endl;
                    long k_i = i.l->edges()->neighbors(i.v,EdgeMode::OUT)->size();
                    long k_j = j.l->edges()->neighbors(j.v,EdgeMode::IN)->size();
                    int a_ij = i.l->edges()->get(i.v, j.v)? 1.0 : 0.0;
                    res += a_ij - (double)k_i * k_j / (m_s.at(i.l->name));
                    //std::cout << i->actor->name << " " << j->actor->name << " " << i->layer->name << " "<< k_i << " " <<  k_j << " " <<  m_s.at(i->layer) << std::endl;
                    //std::cout << "->" << res << std::endl;
                }

                if (i.v==j.v)
                {
                    res += omega;
                }
            }
        }

        //std::cout << "->" << m_net << std::endl;
    }

    //std::cout << "same" << std::endl;

    //std::cout << mu << std::endl;
    int num_layers = mnet->layers()->size();

    for (auto actor: *mnet->actors())
    {
        mu+=num_layers*(num_layers-1)*omega; // unclear if we should multiply by c
    }

    //std::cout << mu << std::endl;

    return 1 / mu * res;
}



template <typename M, typename CS>
double
ordered_modularity(const M* mnet, const CS* communities, double omega)
{



    double res = 0;
    double mu = 0;

    std::unordered_map<std::string,int> m_s;

    for (auto s: *mnet->layers())
    {
        double m = s->edges()->size();

        if (!s->is_directed())
        {
            m *= 2;
        }

        // FIX TO THE ORIGINAL EQUATION WHEN THERE ARE NO EDGES
        if (m == 0)
        {
            m = 1;    // no effect on the formula
        }

        m_s[s->name] = m;
        mu += m;
    }

    // quick fix
    std::map<const uu::net::Network*,size_t> layer_index; // FIX ME!!

    for (size_t l_idx=0; l_idx<mnet->layers()->size(); l_idx++)
    {
        layer_index[mnet->layers()->at(l_idx)] = l_idx;
    }

    for (auto community: *communities)
    {
        for (auto i: *community)
        {
            for (auto j: *community)
            {
                if (i==j)
                {
                    continue;    // not in the original definition - we do this assuming to deal with simple graphs
                }

                //std::cout << i->to_string() << " " << groups.count(i) << std::endl;
                //std::cout << j->to_string() << " " << groups.count(j) << std::endl;

                // same layer
                if (i.l==j.l)
                {
                    //std::cout << "Same group!" << std::endl;
                    //if (mnet.getNetwork(net)->containsEdge(*v_i,*v_j))
                    //    std::cout << "Edge" << std::endl;
                    long k_i = i.l->edges()->neighbors(i.v,EdgeMode::OUT)->size();
                    long k_j = j.l->edges()->neighbors(j.v,EdgeMode::IN)->size();
                    int a_ij = i.l->edges()->get(i.v, j.v)? 1.0 : 0.0;
                    res += a_ij - (double)k_i * k_j / (m_s.at(i.l->name));
                    //std::cout << i->actor->name << " " << j->actor->name << " " << i->layer->name << " "<< k_i << " " <<  k_j << " " <<  m_s.at(i->layer) << std::endl;
                    //std::cout << "->" << res << std::endl;
                }

                if (i.v==j.v)
                {
                    if (std::abs((int)(layer_index[i.l]-layer_index[j.l]))<2)
                    {
                        res += omega;
                    }
                }
            }
        }

        //std::cout << "->" << m_net << std::endl;
    }

    //std::cout << "same" << std::endl;

    //std::cout << mu << std::endl;
    int num_layers = mnet->layers()->size();
    int num_actors = mnet->actors()->size();

    mu += 2*(num_layers-1)*num_actors*omega; // unclear if we should multiply by c


    //std::cout << mu << std::endl;

    return 1 / mu * res;
}


}
}


#endif
