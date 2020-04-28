#include "./sparsification.hpp"

#include "sparsification/eta_k_core.hpp"

TEST_F(net_sparsification_test, eta_k_core)
{
	auto k_core = uu::net::eta_k_core( g.get(), 0.2 );
	int k0 = k_core[0];
	int k1 = k_core[1];
	int k2 = k_core[2];
	int k3 = k_core[3];

	ASSERT_EQ(k0, 2);
	ASSERT_EQ(k1, 1);
	ASSERT_EQ(k2, 1);
	ASSERT_EQ(k3, 1);
}
