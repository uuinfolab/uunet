#include "gtest/gtest.h"

#include "operations/test.hpp"
#include "generation/standard_graphs.hpp"

TEST(operations_test, is_bipartite)
{

    auto n_5 = uu::net::null_graph(5);
    auto p_5 = uu::net::path_graph(5);
    auto c_5 = uu::net::cycle_graph(5);
    auto w_5 = uu::net::wheel_graph(5);
    auto k_5 = uu::net::complete_graph(5);
    auto k_3_2 = uu::net::complete_bipartite_graph(3, 2);

    bool test;

    test = uu::net::is_bipartite(n_5.get());
    EXPECT_EQ(true, test) << "Null graph";

    test = uu::net::is_bipartite(p_5.get());
    EXPECT_EQ(true, test) << "Path graph";

    test = uu::net::is_bipartite(c_5.get());
    EXPECT_EQ(false, test) << "Cycle graph (5 vertices)";

    test = uu::net::is_bipartite(w_5.get());
    EXPECT_EQ(false, test) << "Wheel graph";

    test = uu::net::is_bipartite(k_5.get());
    EXPECT_EQ(false, test) << "Complete graph";

    test = uu::net::is_bipartite(k_3_2.get());
    EXPECT_EQ(true, test) << "Complete bipartite graph";

}
