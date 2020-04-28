#include "./sparsification.hpp"

#include "sparsification/BGI.hpp"
#include "sparsification/GDB.hpp"

TEST_F(net_sparsification_test, GDB)
{
	auto backbone = uu::net::BGI(g.get(), spars, span);
    auto sparse_graph = uu::net::GDB(g.get(), backbone.get(), entropy, improve_threshold, abs);

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

	// GDB depends on the order of edges, so can't test the values directly
	EXPECT_TRUE((prob_e1_2 < 1) && (prob_e1_2 > 0));
	EXPECT_TRUE((prob_e1_4 < 1) && (prob_e1_4 > 0));
	EXPECT_TRUE((prob_e4_3 < 1) && (prob_e4_3 > 0));
}
