#include "gtest/gtest.h"

#include "olap/MLCube.hpp"
#include "networks/_impl/stores/VertexStore.hpp"

TEST(olap_test, MLCube)
{
    
    auto vstore = std::make_unique<uu::net::VertexStore>();

    uu::net::MLCube<uu::net::VertexStore> c(std::move(vstore));

    /* ORDER 0 */
    
    // Basic cube info

    EXPECT_EQ(c.order(), (size_t)0)
            << "Wrong order (number of dimensions)";

    EXPECT_EQ(c.dimensions().size(), (size_t)0)
            << "Wrong dimensions";

    // Adding/retrieving/erasing some elements, created in different ways.
    // The cube has order 0, so we can do this directly on it.
    
    auto v1 = c.add("v1");
    auto v2 = c.add(std::make_shared<uu::net::Vertex>("v2"));
    auto tmp = std::make_shared<uu::net::Vertex>("v3");
    auto v3 = c.add(tmp.get());
    
    EXPECT_EQ(c.size(), (size_t)3);
    EXPECT_EQ(c.get("v1"), v1);
    
    c.erase(v2);
    
    EXPECT_EQ(c.size(), (size_t)2);
    EXPECT_EQ(c.get("v2"), nullptr);
    
    EXPECT_NE(c.get_at_random(), nullptr);
    
    /*EXPECT_EQ(c.dim().at(0), "d1")
            << "Wrong dimension name";

    EXPECT_EQ(c.size().at(0), (size_t)2)
            << "Wrong number of members for dimension d1";

    EXPECT_EQ(c.members("d1").size(), (size_t)2)
            << "Wrong number of members for dimension d1";

    EXPECT_EQ(c.members("d1").at(0), "m1")
            << "Wrong member name";

    std::vector<std::string> m1 = {"m1"};
    c[m1]->add(o1);
    c.at(m1)->add(o2);
    std::vector<std::string> m2 = {"m2"};
    c[m2]->add(o2);
    c.at(m2)->add(o3);

    EXPECT_EQ(c[m1]->size(), (size_t)2);
    EXPECT_EQ(c[m2]->size(), (size_t)2);

    EXPECT_EQ(c.elements()->size(), (size_t)3);
*/
}

