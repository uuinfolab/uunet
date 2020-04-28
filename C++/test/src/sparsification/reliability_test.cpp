#include "./sparsification.hpp"

#include "sparsification/reliability.hpp"

TEST_F(net_sparsification_test, reliability)
{
	auto rel_s_to_all = uu::net::reliability_s_to_all( g.get(), v1, 1);

	EXPECT_TRUE((rel_s_to_all[0] <= 1) && (rel_s_to_all[0] >= 0));
}
