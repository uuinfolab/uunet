#include "./sparsification.hpp"

#include "sparsification/ego_betweeness_approximation.hpp"

TEST_F(net_sparsification_test, ego_betweeness_approximation)
{

	auto ego = uu::net::ego_betweeness_approximation( g.get() );

	ASSERT_DOUBLE_EQ(ego[ g->vertices()->index_of(v1)], 0.224);
	ASSERT_DOUBLE_EQ(ego[ g->vertices()->index_of(v2)], 0.028);
	ASSERT_DOUBLE_EQ(ego[ g->vertices()->index_of(v3)], 0.056);
	ASSERT_DOUBLE_EQ(ego[ g->vertices()->index_of(v4)], 0.154);
    
    
}
