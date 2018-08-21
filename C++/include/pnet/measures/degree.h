/**
 * History:
 * - 2018.08.16 file created.
 */

#ifndef UU_PNET_MEASURES_DEGREE_H_
#define UU_PNET_MEASURES_DEGREE_H_

#include<iostream>
#include<complex>
#include<vector>
#include<cmath>

#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeMode.h"

namespace uu {
namespace net {

/**
 * Returns the maximum expected degree of a graph.
 * @param g input graph
 * @param mode to select IN, OUT, or INOUT expected degree
 * @return the expected degree of the vertex with the maximum expected degree in g
 */
template<typename G>
size_t
maximum_expected_degree(
               const G* g,
               const EdgeMode mode                                             
);


/**
 * Returns the minimum expected degree of a graph.
 * @param g input graph
 * @param mode to select IN, OUT, or INOUT expected degree
 * @return the expected degree of the vertex with the minimum expected degree in g
 */
template<typename G>
size_t
minimum_expected_degree(
               const G* g,
               const EdgeMode mode
);


/**
 * Returns the degree distribution of a spesific vertex in graph.
 * @param g input graph
 * @param v input vertex
 * @param mode to select IN, OUT, or INOUT expected degree
 * @return the degree distribution of the vertex v in g
 */
template<typename G>
std::vector<double>                                                                                                   // core::Prob
vertex_degree_distribution(
               const G* g,
               const Vertex* v,
               const EdgeMode mode
);


/**
 * Returns the expected degree distribution of a graph.
 * @param g input graph
 * @param mode to select IN, OUT, or INOUT expected degree
 * @return the expected degree distribution of graph g
 */
/*
template<typename G>
std::vector<size_t>
expected_degree_distribution(
               const G* g,
               const EdgeMode mode
);
*/

/**
 * Returns the expected degree of a vertex.
 * @param g input graph
 * @param v input vertex
 * @param mode to select IN, OUT, or INOUT expected degree
 * @return the (mode-)expected degree of v in g
 */
template<typename G>
double
expected_degree(
    const G* g,
    const Vertex* v,
    const EdgeMode mode
);



/**
 * Returns the (\eta)-degree of a vertex. This measure has been introduced in (F. Bonchi, F. Gullo, A. Kaltenbrunner, and Y. Volkovich. Core decomposition of uncertain graphs. In KDD , 2014.)
 * @param g input graph
 * @param v input vertex
 * @param eta input (\eta)
 * @param mode to select IN, OUT, or INOUT (\eta)-degree
 * @return the (mode-) (\eta)-degree of v in g
 */
template<typename G>
size_t
eta_degree(
    const G* g,
    const Vertex* v,
    const double eta,												                    // prob has to be defined as a datatype 0 < x <= 1
    const EdgeMode mode
);


/**
 * Returns the (\eta)-degree distribution of a graph. 
 * @param g input graph
 * @param eta input (\eta)
 * @param mode to select IN, OUT, or INOUT (\eta)-degree
 * @return the (mode-) (\eta)-degree distribution of g
 */
template<typename G>
std::vector<size_t>
eta_degree_distribution(
    const G* g,
    const double eta,												     
    const EdgeMode mode
);


/**
 * Returns the maximum (\eta)-degree of a graph.
 * @param g input graph
 * @param eta input (\eta)
 * @param mode to select IN, OUT, or INOUT (\eta)-degree
 * @return the (\eta)-degree of the vertex with the maximum expected degree in g
 */
template<typename G>
size_t
maximum_eta_degree(
               const G* g,
	       const double eta,												     
               const EdgeMode mode                                             
);


/**
 * Returns the minimum (\eta)-degree of a graph.
 * @param g input graph
 * @param eta input (\eta)
 * @param mode to select IN, OUT, or INOUT (\eta)-degree
 * @return the (\eta)-degree of the vertex with the minimum expected degree in g
 */
template<typename G>
size_t
minimum_eta_degree(
               const G* g,
	       const double eta,												     
               const EdgeMode mode                                             
);




/** DEFINITIONS */

/*
template<typename G>
double
expected_degree(
    const G* g,
    const Vertex* v,
    const EdgeMode mode
)
{
    core::assert_not_null(g, "degree", "g");              // to check the graph
    core::assert_not_null(g, "degree", "v");              // to check the vertex

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Expected Degree can only be computed on probabilistic graphs");
    }

    double e = 0;

    for (auto edge: *g->edges()->incident(v, mode))
    {
        auto p = g->edges()->attr()->get_probability(edge);

        if (!p.null)
        {
            e += p.value;
        }
    }

    return e;
}
*/


/*


template<typename G>
size_t
maximum_expected_degree(
               const G* g,
               const EdgeMode mode                                             
)
{
    core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Expected Degree can only be computed on probabilistic graphs");
    }

    double max_e = 0;
    for (auto vertex: *g->vertices())
    {
        double e = 0;
        for (auto edge: *g->edges()->incident(vertex, mode))
        {
            auto p = g->edges()->attr()->get_probability(edge);

            if (!p.null)
            {
                e += p.value;
            }
        }
        max_e = std::max(max_e,e);

    }

    return max_e;
}







template<typename G>
size_t
minimum_expected_degree(
               const G* g,
               const EdgeMode mode                                             
)
{
    core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Expected Degree can only be computed on probabilistic graphs");
    }

    double min_e = 1000000000;           // std::numeric_limits<double>::infinity()     (I have to check for C++14)
    for (auto vertex: *g->vertices())
    {
        double e = 0;
        for (auto edge: *g->edges()->incident(vertex, mode))
        {
            auto p = g->edges()->attr()->get_probability(edge);

            if (!p.null)
            {
                e += p.value;
            }
        }
        min_e = std::min(min_e,e);

    }

    return min_e;
}

*/

/*
template<typename G>
std::vector<double>                                                                                                  
vertex_degree_distribution(
               const G* g,
               const Vertex* v,
               const EdgeMode mode
)
{
    core::assert_not_null(g, "degree", "g");              // to check the graph
    core::assert_not_null(g, "degree", "v");              // to check the vertex

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Degree distribution can only be computed on probabilistic graphs");
    }


    auto i_edges = *g->edges()->incident(v, mode);
    auto n_edges = size(i_edges);
    double P[n_edges] = 0;


    for (int j = 0; j < n_edges ; j++)
    {
        if (!g->edges()->attr()->get_probability(i_edges[j]).null)
        {
            P[j] = g->edges()->attr()->get_probability(i_edges[j]);
        }
    }

    std::complex<double> dd[n_edges+1];
    std::complex<double> Nc = {n_edges+1,0};
    std::complex<double> PI = 3.14159265358979323846;

    for(int j = 0 ; j <= n_edges ; j++)        // initializing degree distribution
    {
	dd[j] = {0,0};
    } 


    for(int m = 0; m <= n_edges; m++)
    {   
        std::complex<double> mc = {m,0};
	for(int n = 0; n <= n_edges ; n++)
	{
            std::complex<double> nc = {n,0};
	    std::complex<double> T = 1;

	    for(int k = 0; k < n_edges; k++)
	    {
		T = T * (1 - P[k]+P[k]*exp((2i*PI*nc)/Nc));
	    }
	    dd[m] = dd[m] + T*exp((-2i*PI*nc*mc)/Nc);
	}
    }


    for(int j = 0 ; j <= n_edges ; j++)
    {
	dd[j] = dd[j]/Nc;
	dd[j] = abs(real(dd[j]));
        dd[j] = round(real(dd[j])*10000)/10000;
    }

    //std::vector<double> deg_dist;
    //deg_dist.insert(deg_dist.begin(),std::begin(dd),std::end(dd));

    return dd;
}
*/















}
}

#endif
