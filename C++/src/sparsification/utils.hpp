/**
 * History:
 * - 2020.02.06 file created by Oskar
 */

#ifndef UU_NET_SPARSIFICATION_UTILS_H_
#define UU_NET_SPARSIFICATION_UTILS_H_

#include "networks/ProbabilisticNetwork.hpp"

namespace uu {
namespace net {


/**
 * Cut size, aka exp degree
 **/
double
sum_p_from_v
(
    ProbabilisticNetwork* g,
    const Vertex * v
);





/**
 *  The entropy formula
 **/
double
entropy_formula
(
    double p
);

/**
 *  Calculates the entropy of the whole graph
 **/
double
entropy_of_graph
(
    ProbabilisticNetwork* g
);


/**
 *  Calculates the absolute discrepancy of v between graph and sparsified_graph
 **/
double
a_discrepancy
(
    const ProbabilisticNetwork* graph,
    const ProbabilisticNetwork* sparsified_graph,
    const Vertex * v
);

/**
 *  Calculates the relative discrepancy of v between graph and sparsified_graph
 **/
double
r_discrepancy
(
    ProbabilisticNetwork* graph,
    ProbabilisticNetwork* sparsified_graph,
    const Vertex * v
);;


/**
 * Adds all edges and vertices from g2 into g1
 * Note, this modifies g1
 * @param g1 Graph to add edges to
 * @param g2 Graph to add edges from
 **/
void graph_union
(
    ProbabilisticNetwork* g1, 
    ProbabilisticNetwork* g2
);


/**
 * Adds an edges and its vertices into g
 * @param g1 Graph to add edge to
 * @param e The edge to add
 * @param p The probability of the edge
 **/
void add_edge_to_graph
(
    ProbabilisticNetwork* g,
    const Edge * e,
    double p
);



/**
 * Duplicates a probabilistic graph to a new object
 * @return The duplicated graph
 * @param g The graph to copy from
 **/
std::unique_ptr<ProbabilisticNetwork>
duplicate_graph
(
    ProbabilisticNetwork* g
);

}
}

#include "utils.ipp"

#endif
