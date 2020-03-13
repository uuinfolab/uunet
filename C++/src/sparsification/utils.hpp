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
 *  Calculates one step
 *  @param edge The edge to get the probability from and the vertices
 *  @param step_size The step size used for the formula
 *  @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 *  @param always_use_step_size if true then apply step_size instantly, otherwise only apply step_size if the condition entropy_formula(new_p) > entropy_formula(previous_p) is true
 **/
double
stp
(
    ProbabilisticNetwork * previous_graph,
    ProbabilisticNetwork * current_graph,
    const Edge * edge,
    double step_size,
    bool use_absolute,
    bool always_use_step_size
);



/**
 *  The objective function of GDB, returns the sum of discrepancies of the whole graph
 *  @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
double
objective_function
(
    ProbabilisticNetwork* graph, 
    ProbabilisticNetwork* sparsified_graph, 
    bool use_absolute
);


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
 *  Returns 1 if use_absolute is true, otherwise return the cut size of v
 *  @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
double
pi
(
    ProbabilisticNetwork * g,
    const Vertex * v,
    bool use_absolute 
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
    ProbabilisticNetwork* graph,
    ProbabilisticNetwork* sparsified_graph,
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
);


/**
 *  Adds all edges from source graph to target graph
 *  Note: this modifies the target graph
 **/
void
graph_add_2
(
    const Network * source,
    Network * target
);

/**
 *  Adds all edges and probabilities from source graph to target graph
 *  Note: this modifies the target graph
 **/
void
graph_add_prob
(
    const ProbabilisticNetwork * source,
    ProbabilisticNetwork * target
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


#endif
