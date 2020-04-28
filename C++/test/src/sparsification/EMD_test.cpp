#include "./sparsification.hpp"

#include "sparsification/BGI.hpp"
#include "sparsification/EMD.hpp"

TEST_F(net_sparsification_test, EMD)
{
	auto backbone = uu::net::BGI(g.get(), spars, span);
    auto sparse_graph = uu::net::EMD(g.get(), backbone.get(), entropy, improve_threshold, abs);

	size_t vertices = sparse_graph->vertices()->size();
    size_t edges = sparse_graph->edges()->size();
	
    ASSERT_EQ(vertices, (size_t) 4);
    ASSERT_EQ(edges, (size_t) 3);

	auto sparse_e1_2 = sparse_graph->edges()->get(v1, v2);
	auto sparse_e1_4 = sparse_graph->edges()->get(v1, v4);
	auto sparse_e4_3 = sparse_graph->edges()->get(v4, v3);

	auto prob_e1_2 = sparse_graph->get_prob(sparse_e1_2).value;
	auto prob_e1_4 = sparse_graph->get_prob(sparse_e1_4).value;
	auto prob_e4_3 = sparse_graph->get_prob(sparse_e4_3).value;

	ASSERT_DOUBLE_EQ(prob_e1_2, 0.55);
	ASSERT_DOUBLE_EQ(prob_e1_4, 0.375);
	ASSERT_DOUBLE_EQ(prob_e4_3, 0.5125);
}
