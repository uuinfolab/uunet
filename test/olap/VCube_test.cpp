#include "gtest/gtest.h"
#include "discretization.hpp"

#include "olap/VCube.hpp"


TEST(olap_VCube_test, set_functionality)
{
    auto V = std::make_unique<uu::net::VCube>("V");
    auto v1 = V->add("v1"); // v1 has type const Vertex*
    EXPECT_EQ(V->size(), (size_t) 1);
    EXPECT_EQ(V->contains(v1), true);
    EXPECT_EQ(V->contains("v1"), true);
    EXPECT_EQ(V->get("v1"), v1);
    EXPECT_EQ(V->get_at_random(), v1);
    EXPECT_EQ(V->at(0), v1);
    EXPECT_EQ(V->index_of(v1), 0);
    EXPECT_EQ(V->erase(v1), true);
    EXPECT_EQ(V->erase("v1"), false);

    auto v2_sharedptr = std::make_shared<const uu::net::Vertex>("v2");
    auto v2 = v2_sharedptr.get();
    EXPECT_EQ(V->add(v2), v2);
    EXPECT_EQ(V->size(), (size_t) 1);
}

TEST(olap_VCube_test, attribute_functionality)
{
    auto V = std::make_unique<uu::net::VCube>("V");

    // we create an independent vertex, so that we can then erase it from the cube
    // without it being garbage collected
    auto v_sharedptr = std::make_shared<const uu::net::Vertex>("vertex");
    auto v = v_sharedptr.get(); // v has type const Vertex*
    V->add(v);

    auto attr = V->attr();
    attr->add("A", uu::core::AttributeType::DOUBLE);
    attr->set_double(v, "A", 3.14);
    auto val = attr->get_double(v, "A"); // val has type Value<double>
    EXPECT_EQ(val.null, false);
    EXPECT_EQ(val.value, 3.14);

    V->erase(v);
    val = attr->get_double(v, "A");
    EXPECT_EQ(val.null, true) << "vertex removal not propagated to the attribute store";
}


TEST(olap_VCube_test, cube_functionality)
{
    auto V = std::make_unique<uu::net::VCube>("V");

    V->add("v1");

    // Cube functionality

    EXPECT_EQ(V->order(), (size_t) 0);
    EXPECT_EQ(V->dsize(), std::vector<size_t>({}));
    EXPECT_EQ(V->dimensions(), std::vector<std::string>({}));
    EXPECT_EQ(V->members(), std::vector<std::vector<std::string>>({}));

    // notice that the initial vertex should be added to all the new cells, as no discretization function is passed
    V->add_dimension("d1", {"m11", "m12", "m13"});
    V->add_dimension("d2", {"m21", "m22"});

    EXPECT_EQ(V->order(), (size_t) 2);
    EXPECT_EQ(V->dsize(), std::vector<size_t> ({3, 2}));
    EXPECT_EQ(V->dimensions(), std::vector<std::string>({"d1", "d2"}));
    std::vector<std::vector<std::string>> m;
    m.push_back(std::vector<std::string>({"m11", "m12", "m13"}));
    m.push_back(std::vector<std::string>({"m21", "m22"}));
    EXPECT_EQ(V->members(), m);

    auto index = std::vector<std::string>({"m12", "m21"});
    V->cell(index)->add("v2");
    V->cell(index)->add("v3");
    EXPECT_EQ(V->size(), (size_t) 3);

    auto v4 = V->add("v4"); // (added to all cells)
    EXPECT_EQ(V->cell(index)->size(), (size_t) 4); // (i.e., v1, v2, v3, v4)
    EXPECT_EQ(V->erase(v4), true); // (erased from all cells)
    EXPECT_EQ(V->cell(index)->size(), (size_t) 3); // (i.e., v1, v2, v3)
}


TEST(olap_VCube_test, discretization)
{
    // from 0 to 1 cell, no discretization

    auto V = std::make_unique<uu::net::VCube>("V");
    V->add("v1");

    V->add_dimension("d0", {"m0"});
    EXPECT_EQ(V->size(), (size_t) 1);

    // from 0 to 1 cell, discretization, false

    V = std::make_unique<uu::net::VCube>("V");
    V->add("v1");

    auto d1 = uu::net::UniformDiscretization<uu::net::Vertex>(1, false);

    V->add_dimension("d0", {"m0"}, d1);
    EXPECT_EQ(V->size(), (size_t) 0);

    // from 0 to 1 cell, discretization, true

    V = std::make_unique<uu::net::VCube>("V");
    V->add("v1");


    auto d2 = uu::net::UniformDiscretization<uu::net::Vertex>(1, true);

    V->add_dimension("d0", {"m0"}, d2);
    EXPECT_EQ(V->size(), (size_t) 1);

    /* ORDER 2 */

    V = std::make_unique<uu::net::VCube>("V");
    V->add_dimension("d0", {"m0"});
    V->add("v1");
    V->add("v2");
    V->add("v3");
    EXPECT_EQ(V->size(), (size_t) 3);

    auto d3 = CustomVertexDiscretization();

    V->add_dimension("d1", {"m0", "m1"}, d3);

    std::vector<std::string> m00 = {"m0","m0"};
    std::vector<std::string> m01 = {"m0","m1"};

    EXPECT_EQ(V->size(), (size_t) 2);
    EXPECT_EQ(V->cell(m00)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(m01)->size(), (size_t) 2);

    /* ORDER 3 */

    V->add_dimension("d2", {"m0", "m1"}, d3);

    std::vector<std::string> m000 = {"m0","m0","m0"};
    std::vector<std::string> m001 = {"m0","m0","m1"};
    std::vector<std::string> m010 = {"m0","m1","m0"};
    std::vector<std::string> m011 = {"m0","m1","m1"};

    EXPECT_EQ(V->size(), (size_t) 2);
    EXPECT_EQ(V->cell(m000)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(m001)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(m010)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(m011)->size(), (size_t) 2);

    V->cell(m011)->add("v4");
    EXPECT_EQ(V->size(), (size_t) 3);
}

