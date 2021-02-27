#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/d-extension.hpp"

TEST_F(net_olap_operators_test, extend_dimension)
{

    auto V = std::make_unique<uu::net::VCube>("V");
    V->add("v1");

    auto V1 = std::make_unique<uu::net::VCube>(*V);
    auto d = uu::net::UniformDiscretization<uu::net::Vertex>(1, true);

    uu::net::extend_dimension(V1.get(), "d0", {"m0"}, d);

    EXPECT_EQ(V1->order(), (size_t) 1);
    EXPECT_EQ(V1->size(), (size_t) 1);


}
