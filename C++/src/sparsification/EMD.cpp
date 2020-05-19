/**
 * History:
 * - 2020.02.17 file created by Oskar
 **/

#include <set>
#include <limits>

#include "networks/ProbabilisticNetwork.hpp"
#include "sparsification/utils.hpp"
#include "sparsification/GDB.hpp"
#include "sparsification/EMD.hpp"


namespace uu {
namespace net {


struct comp
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		if (l.first == r.first)
			return l.second > r.second;

		return l.first > r.first;
	}
};


// A pair where first = value, and second = index of vertex
typedef std::pair<double, int> VertexDiscr;


/**
 * Inline helper function for EMD
 * Updates the heap by removing the pair <val, vertex index> and then inserting <updated val, vertex index>
 **/
inline void
heap_update
(
    std::set< VertexDiscr, comp > * max_heap,
    std::vector<double> & heap_table,
    ProbabilisticNetwork * uncertain_graph,
    const Vertex *vertex,
    double val
)
{
    int index = uncertain_graph->vertices()->index_of(vertex);   
    max_heap->erase(  std::make_pair(heap_table[index], index));
    heap_table[index] = val;
    max_heap->insert( std::make_pair(val, index));
}

/**
 * Inline helper function for EMD
 * Inserts <val, index of vertex> into a max_heap
 **/
inline void
heap_insert
(
    std::set< VertexDiscr, comp > * max_heap,
    std::vector<double> & heap_table,
    ProbabilisticNetwork * uncertain_graph,
    const Vertex *vertex,
    double val
)
{
    int index = uncertain_graph->vertices()->index_of(vertex);   
    heap_table[index] = val;
    max_heap->insert( std::make_pair(val, index));
}

/**
 * Inline helper function for EMD
 * Returns the vertex which has the maximum value in the max_heap
 **/
inline const Vertex *
heap_top_vertex
(
    std::set< VertexDiscr, comp > * max_heap,
    ProbabilisticNetwork * uncertain_graph
)
{
    auto test = *max_heap->begin();
    return uncertain_graph->vertices()->at(test.second);
}


double
gain_equation
(
    ProbabilisticNetwork * graph,
    ProbabilisticNetwork * other_graph,
    const Edge * edge, 
    double new_prob,
    bool use_absolute
)
{
    double p_e = graph->get_prob(edge).value;
    if (use_absolute){
        double disc = a_discrepancy(graph, other_graph, edge->v1);
        double disc2 = a_discrepancy(graph, other_graph, edge->v2);
        return pow(disc + p_e, 2) - pow(disc + p_e - new_prob , 2) + pow(disc2 + p_e, 2) - pow(disc2 + p_e - new_prob, 2);
    } else {
        double disc = r_discrepancy(graph, other_graph, edge->v1);
        double disc2 = r_discrepancy(graph, other_graph, edge->v2);
        return pow(disc + p_e, 2) - pow(disc + p_e - new_prob , 2) + pow(disc2 + p_e, 2) - pow(disc2 + p_e - new_prob, 2);
    }
}




/**
 * Generates a sparsified graph using the Expectation-Maximization Degree algorithm
 * @param uncertain_graph Original uncertain graph
 * @param backbone_graph Backbone graph generated from BGI
 * @param entropy_step_size The step size
 * @param improvement_threshold 
 * @param use_absolute Denotes if we should use the absolute discrepancy (true) or the relative discrepancy (false)
 **/
std::unique_ptr<ProbabilisticNetwork>
EMD
(
    ProbabilisticNetwork * uncertain_graph,
    Network * backbone_graph,
    double entropy_step_size,
    double improvement_threshold,
    bool use_absolute
)
{
    auto EMD =  std::make_unique<uu::net::ProbabilisticNetwork> 
                        ("Sparse probabilistic network", EdgeDir::UNDIRECTED, true);

    double v_size = uncertain_graph->vertices()->size();
    std::vector<double> abs_discrepancy (v_size);
    std::vector<double> heap_table (v_size);
	double Dcurrent;
    std::unique_ptr<uu::net::ProbabilisticNetwork> temp_graph = nullptr;
    std::unique_ptr<ProbabilisticNetwork> previous_graph = duplicate_graph(uncertain_graph);

    // Initialize abs_discrepancy with expected degrees
    for ( auto vertex: *uncertain_graph->vertices())
    {
        int index = uncertain_graph->vertices()->index_of( vertex );
        abs_discrepancy[ index ] = sum_p_from_v(uncertain_graph, vertex);
        // Also initialize EMD with all vertices
        EMD->vertices()->add(vertex);
    }

    // Add edges of backbone_graph to EMD, and remove the probability from abs_discrepancy
    for ( auto edge: *backbone_graph->edges())
    {
        double prob = uncertain_graph->get_prob(edge).value;
        int i_v1 = uncertain_graph->vertices()->index_of( edge->v1 );
        int i_v2 = uncertain_graph->vertices()->index_of( edge->v2 );
        EMD->edges()->add(edge);
        EMD->set_prob(edge, prob);
        abs_discrepancy[ i_v1 ]  = abs_discrepancy[ i_v1 ] - prob;
        abs_discrepancy[ i_v2 ]  = abs_discrepancy[ i_v2 ] - prob;
    }
    std::swap(previous_graph, temp_graph);

    int iteration = 1;
    // Main loop
	do {
        std::swap(previous_graph, temp_graph);
		Dcurrent = objective_function(previous_graph.get(), EMD.get(), use_absolute);
        
         std::cout << "\nEMD iteration: " << iteration << std::endl;
        if (iteration == 10)
        {
            std::cout << "EMD stopped due to too many iterations" << std::endl;
            break;
        }
        iteration++;

        // std::cout << "Edges before: " ;
        // for (auto el: *EMD->edges())
        // {
        //     std::cout << el->v1->to_string() << "-" << el->v2->to_string() << "  ";
        // }
        // std::cout << std::endl;

        // std::cout << "obj func before: " << Dcurrent << std::endl;
        std::set< VertexDiscr, comp > max_heap;
        for (auto vertex: *uncertain_graph->vertices())
        {
            double val = abs_discrepancy[ uncertain_graph->vertices()->index_of(vertex) ];
            heap_insert(&max_heap, heap_table, uncertain_graph, vertex, val);
        }

        
        temp_graph = duplicate_graph(EMD.get());
		for (auto edge: *temp_graph->edges())
        {
            // std::cout << "remove e: " << edge->to_string() << std::endl;
            auto u = edge->v1;
            auto v = edge->v2;
            int i_u = EMD->vertices()->index_of( u );
            int i_v = EMD->vertices()->index_of( v );
            double prob = uncertain_graph->get_prob(edge).value;
            
            auto SA_u = abs_discrepancy[i_u] + prob;
			auto SA_v = abs_discrepancy[i_v] + prob;
            abs_discrepancy[i_u] = SA_u;
            abs_discrepancy[i_v] = SA_v;


            //calculate gain for current edge as well
			EMD->set_prob(edge, prob);
            double w = stp(previous_graph.get(), EMD.get(), edge, entropy_step_size, use_absolute, true);
            double max_gain = gain_equation(previous_graph.get(), EMD.get(), edge, w, use_absolute);
            const Edge * max_gain_edge = edge;


			EMD->edges()->erase(edge);
            heap_update(&max_heap, heap_table, uncertain_graph, u, SA_u);
            heap_update(&max_heap, heap_table, uncertain_graph, v, SA_v);


            // std::cout << " disc: ";
            // for (auto el: abs_discrepancy)
            // {
            //     std::cout << el << ", ";
            // }
            // std::cout << std::endl;

			auto vertex_top = heap_top_vertex(&max_heap, uncertain_graph);
            // std::cout << " v_top: " << vertex_top->to_string() << std::endl;
			for (auto adjacent_edge: *uncertain_graph->edges()->incident( vertex_top ))
            {
                if (EMD->edges()->contains(adjacent_edge))
                    continue;

                EMD->edges()->add(adjacent_edge);
                EMD->set_prob(adjacent_edge, uncertain_graph->get_prob(adjacent_edge).value);

                double w = stp(previous_graph.get(), EMD.get(), adjacent_edge, entropy_step_size, use_absolute, true);
                double gain = gain_equation(previous_graph.get(), EMD.get(), adjacent_edge, w, use_absolute);
                
                // std::cout << "  adj_e: " << adjacent_edge->to_string() << ", p: "<< uncertain_graph->get_prob(adjacent_edge).value;
                // std::cout << ", w: " << w << ", g: " << gain << std::endl;

                EMD->edges()->erase(adjacent_edge);
                if (gain > max_gain)
                {
                    max_gain = gain;
                    max_gain_edge = adjacent_edge;

                }
            }

            

            // std::cout << " e_max: " << max_gain_edge->to_string() << std::endl;

			double p_max = uncertain_graph->get_prob(max_gain_edge).value;

			EMD->edges()->add(max_gain_edge);
            EMD->set_prob(max_gain_edge, p_max);

            auto u_max = max_gain_edge->v1;
            auto v_max = max_gain_edge->v2;
            int i_u_max = EMD->vertices()->index_of( u_max );
            int i_v_max = EMD->vertices()->index_of( v_max );
			double SA_u_max = abs_discrepancy[i_u_max] - p_max;
			double SA_v_max = abs_discrepancy[i_v_max] - p_max;
            abs_discrepancy[i_u_max] = SA_u_max;
            abs_discrepancy[i_v_max] = SA_v_max;
			heap_update(&max_heap, heap_table, uncertain_graph, u_max, SA_u_max);
            heap_update(&max_heap, heap_table, uncertain_graph, v_max, SA_v_max);
		}
        



        // std::cout << "Edges after: " ;
        // for (auto el: *EMD->edges())
        // {
        //     std::cout << el->v1->to_string() << "-" << el->v2->to_string() << "  ";
        // }
        // std::cout << std::endl;

		EMD = GDB(uncertain_graph, EMD.get(), entropy_step_size, improvement_threshold, use_absolute);
        // std::cout << "obj func after: " << objective_function(temp_graph.get(), EMD.get(), use_absolute) << std::endl;
        // std::cout << std::endl;
        
        


		
	} while (! ( fabs(  Dcurrent - objective_function(temp_graph.get(), EMD.get(), use_absolute) ) <= improvement_threshold) );

    return EMD;
}


}
}
