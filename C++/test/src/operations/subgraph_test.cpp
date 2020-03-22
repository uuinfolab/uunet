#include "./operations.hpp"

#include "operations/subgraph.hpp"

#include <vector>

TEST_F(net_operations_test, vertex_induced_subgraph)
{
    std::vector<const uu::net::Vertex*> vertices = {v1, v2, v4, v5, v8};

    auto sub = uu::net::vertex_induced_subgraph(g.get(), vertices.begin(), vertices.end());

    size_t n = sub->vertices()->size();
    size_t m = sub->edges()->size();
    ASSERT_EQ(n, (size_t) 5);
    ASSERT_EQ(m, (size_t) 2);
}


TEST_F(net_operations_test, edge_induced_subgraph)
{
    std::vector<const uu::net::Edge*> edges = {e1, e3, e5, e7};

    auto sub = uu::net::edge_induced_subgraph(g.get(), edges.begin(), edges.end());

    size_t n = sub->vertices()->size();
    size_t m = sub->edges()->size();
    ASSERT_EQ(n, (size_t) 6);
    ASSERT_EQ(m, (size_t) 4);
}
