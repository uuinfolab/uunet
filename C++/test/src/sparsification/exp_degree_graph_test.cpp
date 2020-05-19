#include "./sparsification.hpp"

#include "sparsification/exp_degree_graph.hpp"

TEST_F(net_sparsification_test, exp_degree_graph)
{
	auto exp_degree_graph = uu::net::exp_degree_graph( g.get() );
	auto first_item = exp_degree_graph.begin();

	ASSERT_DOUBLE_EQ(first_item->first, 0.9);
	ASSERT_EQ(first_item->second, "v1");
}
