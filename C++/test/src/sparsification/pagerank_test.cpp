#include "./sparsification.hpp"

#include "sparsification/pagerank.hpp"

TEST_F(net_sparsification_test, pagerank)
{
	auto pagerank = uu::net::pagerank( g.get() );
	auto first_item = pagerank.begin();

	ASSERT_DOUBLE_EQ(first_item->first, 0.9);
	ASSERT_EQ(first_item->second, "v1");
}
