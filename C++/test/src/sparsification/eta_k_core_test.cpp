#include "./sparsification.hpp"

#include "sparsification/eta_k_core.hpp"

TEST_F(net_sparsification_test, eta_k_core)
{
	auto k_core = uu::net::eta_k_core( g.get(), 0.2 );
	int k0 = k_core[0];
	int k1 = k_core[1];
	int k2 = k_core[2];
	int k3 = k_core[3];

	ASSERT_EQ( k_core.size(), (size_t) 4);

	// eta_k_core depends on the order of edges, so can't test the values directly
	EXPECT_TRUE((k0 == 1) || (k0 == 2));
	EXPECT_TRUE((k1 == 1) || (k1 == 2));
	EXPECT_TRUE((k2 == 1) || (k2 == 2));
	EXPECT_TRUE((k3 == 1) || (k3 == 2));
}
