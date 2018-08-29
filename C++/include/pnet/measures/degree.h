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
#include "core/utils/Counter.h"

#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeMode.h"
#include "core/exceptions/assert_not_null.h"



namespace uu {
namespace net {

/**
 * Returns the maximum expected degree of a graph.
 * @param g input graph
 * @param mode to select IN, OUT, or INOUT expected degree
 * @return the expected degree of the vertex with the maximum expected degree in g
 */
template<typename G>
double                                                                              
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
double
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
std::vector<double>                                                                                      
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
int
eta_degree(
    const G* g,
    const Vertex* v,
    const double eta,												                    
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
std::vector<int>
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
int
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
int
minimum_eta_degree(
               const G* g,
	       const double eta,												     
               const EdgeMode mode                                             
);


/**
 * Returns the average expected degree of graph.
 * @param g input graph
 * @param mode to select IN, OUT, or INOUT expected degree
 * @return the average expected degree of g
 */
template<typename G>
double
average_expected_degree(
               const G* g,
               const EdgeMode mode
);


/**
 * Returns the average eta-degree of graph.
 * @param g input graph
 * @param eta input (\eta)
 * @param mode to select IN, OUT, or INOUT (\eta)-degree
 * @return the average eta degree of g
 */
template<typename G>
double
average_eta_degree(
               const G* g,
               const double eta,
               const EdgeMode mode
);






/** DEFINITIONS */


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



template<typename G>
double
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
double
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

    double min_e = 1000000000;           // std::numeric_limits<double>::infinity()       (I have to check for C++14)
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




template<typename G>
std::vector<double>                                                                                                  
vertex_degree_distribution(
               const G* g,
               const Vertex* v,
               const EdgeMode mode
)
{
    using namespace std;
    core::assert_not_null(g, "degree", "g");              
    core::assert_not_null(g, "degree", "v");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Degree distribution can only be computed on probabilistic graphs");
    }



    vector<double> P;
    for (auto edge: *g->edges()->incident(v, mode))
    {
        auto p = g->edges()->attr()->get_probability(edge);

        if (!p.null)
        {
            P.push_back(p.value);
        }
    }

    std::complex<double> dd[P.size()+1];
    std::complex<double> Nc = {P.size()+1,0};
    std::complex<double> PI = 3.14159265358979323846;

    for(unsigned int j = 0 ; j <= P.size() ; j++)        // initializing degree distribution
    {
	dd[j] = {0,0};
    } 


    for(unsigned m = 0; m <= P.size(); m++)
    {   
        std::complex<double> mc = {m,0};
	for(unsigned int n = 0; n <= P.size() ; n++)
	{
            std::complex<double> nc = {n,0};
	    std::complex<double> T = 1;

	    for(unsigned  int k = 0; k < P.size(); k++)
	    {
		T = T * (1 - P[k]+P[k]*exp((2i*PI*nc)/Nc));
	    }
	    dd[m] = dd[m] + T*exp((-2i*PI*nc*mc)/Nc);
	}
    }

    vector<double> DD;    
    for(unsigned int j = 0 ; j <= P.size() ; j++)
    {
	dd[j] = dd[j]/Nc;
	dd[j] = abs(real(dd[j]));
        DD.push_back(round(real(dd[j])*10000)/10000);
    }

    return DD;
}


template<typename G>
int
eta_degree(
    const G* g,
    const Vertex* v,
    const double eta,	
    const EdgeMode mode
)
{

   core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Expected Degree can only be computed on probabilistic graphs");
    }



    auto D = uu::net::vertex_degree_distribution(g,v,mode);
    int N = D.size();
    double sum = D[N-1];

    int k = N-2;
    while(sum < eta && k >= 0)
    {
        sum+=D[k];
        k--;
    }
    return ++k;
}


template<typename G>
int
maximum_eta_degree(
               const G* g,
	       const double eta,												     
               const EdgeMode mode                                             
)
{
    core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Expected Degree can only be computed on probabilistic graphs");
    }


    int max_e = 0;
    for (auto vertex: *g->vertices())
    {
	auto e = eta_degree(g,vertex,eta,mode);
        max_e = std::max(max_e,e);
    }

    return max_e;

}


template<typename G>
int
minimum_eta_degree(
               const G* g,
	       const double eta,												     
               const EdgeMode mode                                             
)
{
    core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Expected Degree can only be computed on probabilistic graphs");
    }


    int min_e = 1000000000;
    for (auto vertex: *g->vertices())
    {
	auto e = eta_degree(g,vertex,eta,mode);
        min_e = std::min(min_e,e);
    }

    return min_e;

}



template<typename G>
std::vector<int>
eta_degree_distribution(
    const G* g,
    const double eta,												     
    const EdgeMode mode
)
{
    core::assert_not_null(g, "degree_distribution", "g");  
    core::Counter<int> edd;

    int max = 0;
    int ed;

    for (auto v: *g->vertices())
    {
        ed = eta_degree(g, v, eta, mode);
        edd.inc(ed);

        if (ed > max)
        {
            max = ed;
        }
    }

    std::vector<int> res;
    res.reserve(max+1);

    for (ed = 0; ed <= max; ed++)
    {
        res.push_back(edd.count(ed));
    }

    return res;
}



template<typename G>
double
average_expected_degree(
               const G* g,
               const EdgeMode mode
)
{
    core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Expected Degree can only be computed on probabilistic graphs");
    }


    double avg = 0;
    for (auto vertex: *g->vertices())
    {
	auto e = expected_degree(g,vertex,mode);
        avg += e;
    }

    return avg/g->vertices()->size();

}




template<typename G>
double
average_eta_degree(
               const G* g,
               const double eta,
               const EdgeMode mode
)
{
    core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("eta Degree can only be computed on probabilistic graphs");
    }


    double avg = 0;
    for (auto vertex: *g->vertices())
    {
	auto e = eta_degree(g,vertex,eta,mode);
        avg += e;
    }

    return avg/g->vertices()->size();

}




}
}

#endif
