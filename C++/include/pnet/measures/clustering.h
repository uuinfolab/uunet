/**
 * History:
 * - 2018.08.16 file created.
 */

#ifndef UU_PNET_MEASURES_CLUSTERING_H_
#define UU_PNET_MEASURES_CLUSTERING_H_

#include <vector>
#include <algorithm>

#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/EdgeMode.h"
#include "core/exceptions/assert_not_null.h"
#include "core/utils/Counter.h"
#include "pnet/measures/basic.h"


namespace uu {
namespace net {

/**
 * Returns the expected clustering coefficient of a vertex in graph. This measure has been introduced in  (J. J. Pfeiffer and J. Neville. Methods to determine node centrality and clustering in graphs with uncertain structure. In 5th International AAAI Conference on Weblogs and Social Media, 2011).
 * @param g input graph
 * @param v input vertex
 * @return the expected clustering coefficient of the vertex in g
 */
template<typename G>
double                                                              
expected_clustering_coefficient(
               const G* g,
	       const Vertex* v
);


/**
 * Returns the average of the expected clustering coefficients in graph.
 * @param g input graph
 * @return the the average of the expected clustering coefficients in g
 */
template<typename G>
double
average_expected_clustering_coefficient_distribution(
               const G* g
);



/**
 * Returns the distribution of the expected clustering coefficient in graph.
 * @param g input graph
 * @return the the distribution of the expected clustering coefficient in g
 */
/*
template<typename G>
std::vector<double>
expected_clustering_coefficient_distribution(
               const G* g,
	       const Vertex* v,
               //const EdgeMode mode                                             
);
*/




/* Definitions */

template<typename G>
double                                                              
expected_clustering_coefficient(
               const G* g,
	       const Vertex* v
)
{
    using namespace std;
    core::assert_not_null(g, "degree", "g");
    core::assert_not_null(g, "degree", "v");

    
    // neighbors of v
    auto nghb = g->edges()->neighbors(v,uu::net::EdgeMode::INOUT);
    if(nghb->size()==0 || nghb->size()==1)
    {
        return 0;
    }


    double denominator = 0;             // expected number of coexisting pairs
    double nominator =0;                // expected number of triangles
    double p;

    for (unsigned int i = 0 ; i < nghb->size() ; i++)
    {
        for (unsigned int j = i+1 ; j < nghb->size() ; j++)
        {
            denominator += is_neighbor(g,v,nghb->get_at_index(i),uu::net::EdgeMode::INOUT)*is_neighbor(g,v,nghb->get_at_index(j),uu::net::EdgeMode::INOUT);
            p = is_neighbor(g,nghb->get_at_index(i),nghb->get_at_index(j),uu::net::EdgeMode::INOUT);
            if (p)
            {	
                nominator += is_neighbor(g,v,nghb->get_at_index(i),uu::net::EdgeMode::INOUT)*is_neighbor(g,v,nghb->get_at_index(j),uu::net::EdgeMode::INOUT)*p;
            }
        }
    }
    
    return nominator/denominator;
}


template<typename G>
double
average_expected_clustering_coefficient(
               const G* g
)
{
    core::assert_not_null(g, "degree", "g");              

    if (!g->is_probabilistic())
    {
        throw core::WrongParameterException("Expected Degree can only be computed on probabilistic graphs");
    }

    double i = 0;
    double avg = 0;
    for (auto vertex: *g->vertices())
    {
	auto e = expected_clustering_coefficient(g,vertex);
        avg += e;
        i++;
    }


    return avg/i;

}



}
}

#endif
