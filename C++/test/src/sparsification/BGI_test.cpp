#include "./sparsification.hpp"

#include "sparsification/BGI.hpp"

TEST_F(net_sparsification_test, BGI)
{
    auto backbone = uu::net::BGI(g.get(), spars, span);

	size_t vertices = backbone->vertices()->size();
    size_t edges = backbone->edges()->size();

    ASSERT_EQ(vertices, (size_t) 4);
    ASSERT_EQ(edges, (size_t) 3);

	auto backbone_e1_2 = backbone->edges()->get(v1, v2);
	auto backbone_e1_4 = backbone->edges()->get(v1, v4);
	auto backbone_e4_3 = backbone->edges()->get(v4, v3);

	ASSERT_EQ(backbone_e1_2->to_string(), e1_2->to_string());
	ASSERT_EQ(backbone_e1_4->to_string(), e1_4->to_string());
	ASSERT_EQ(backbone_e4_3->to_string(), e4_3->to_string());
}
