#include "gtest/gtest.h"

#include "olap/ECube.hpp"
#include "olap/VCube.hpp"

class olap_ECube_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::net::VCube> vc1, vc2;
    std::unique_ptr<uu::net::ECube> E;
    std::shared_ptr<const uu::net::Vertex> v1, v2;
    //const uu::net::Vertex *v1, *v2, *v3, *v4, *v5, *v6;
    //const uu::net::Network2 *l1, *l2;
    
    void
    SetUp() override
    {
        vc1 = std::make_unique<uu::net::VCube>("V1");
        vc2 = std::make_unique<uu::net::VCube>("V2");
        
        v1 = std::make_shared<const uu::net::Vertex>("v1");
        v2 = std::make_shared<const uu::net::Vertex>("v2");
        
        vc1->add(v1);
        vc1->add(v2);
        
        vc2->add(v1);
        vc2->add(v2);

        auto dir = uu::net::EdgeDir::DIRECTED;
        E = std::make_unique<uu::net::ECube>("E", vc1.get(), vc2.get(), dir);
    }
};

TEST_F(olap_ECube_test, ECube)
{
    E->add_dimension("d", {"m"});

    E->add(v1.get(), vc1.get(), v1.get(), vc2.get());
    E->add(v1.get(), vc1.get(), v2.get(), vc2.get());
    
    EXPECT_EQ(E->size(), (size_t) 2);

}

TEST_F(olap_ECube_test, set_functionality)
{
    auto e1 = E->add(v1.get(), vc1.get(), v1.get(), vc2.get());
    EXPECT_EQ(E->size(), (size_t) 1);
    EXPECT_EQ(E->contains(e1), true);
    EXPECT_EQ(E->contains(v1.get(), vc1.get(), v1.get(), vc2.get()), true);
    EXPECT_EQ(E->get(v1.get(), vc1.get(), v1.get(), vc2.get()), e1);
    EXPECT_EQ(E->get_at_random(), e1);
    EXPECT_EQ(E->at(0), e1);
    EXPECT_EQ(E->index_of(e1), 0);
    EXPECT_EQ(E->erase(e1), true);
    
    auto e2_sharedptr = std::make_shared<const uu::net::MLEdge2>(v1.get(), vc1.get(), v1.get(), vc2.get(), uu::net::EdgeDir::DIRECTED);
    auto e2 = e2_sharedptr.get();
    EXPECT_EQ(E->add(e2), e2);
    EXPECT_EQ(E->size(), (size_t) 1);
}

/*
TEST_F(olap_ECube_test, attribute_functionality)
{
    auto V = std::make_unique<uu::net::VCube>("V");
    
    auto v = E->add("vertex"); // v has type const Vertex*
    
    auto attr = E->attr();
    attr->add("A", uu::core::AttributeType::DOUBLE);
    attr->set_double(v, "A", 3.14);
    auto val = attr->get_double(v, "A"); // val has type Value<double>
    EXPECT_EQ(val.null, false);
    EXPECT_EQ(val.value, 3.14);

    E->erase(v);
    val = attr->get_double(v, "A");
    EXPECT_EQ(val.null, true) << "vertex removal not propagated to the attribute store";
}


TEST_F(olap_ECube_test, cube_functionality)
{
    auto V = std::make_unique<uu::net::VCube>("V");
    
    E->add("v1");
    
    // Cube functionality
    
    EXPECT_EQ(E->order(), (size_t) 0);
    EXPECT_EQ(E->dsize(), std::vector<size_t>({}));
    EXPECT_EQ(E->dimensions(), std::vector<std::string>({}));
    EXPECT_EQ(E->members(), std::vector<std::vector<std::string>>({}));
    
    // "vertex" should be added to all the new cells, as no discretization function is passed
    E->add_dimension("d1", {"m11", "m12", "m13"});
    E->add_dimension("d2", {"m21", "m22"});
    
    EXPECT_EQ(E->order(), (size_t) 2);
    EXPECT_EQ(E->dsize(), std::vector<size_t> ({3, 2}));
    EXPECT_EQ(E->dimensions(), std::vector<std::string>({"d1", "d2"}));
    std::vector<std::vector<std::string>> m;
    m.push_back(std::vector<std::string>({"m11", "m12", "m13"}));
    m.push_back(std::vector<std::string>({"m21", "m22"}));
    EXPECT_EQ(E->members(), m);
    
    auto index = std::vector<std::string>({"m12", "m21"});
    E->cell(index)->add("v2");
    E->cell(index)->add("v3");
    EXPECT_EQ(E->size(), (size_t) 3);
    
    auto v4 = E->add("v4"); // (added to all cells)
    EXPECT_EQ(E->cell(index)->size(), (size_t) 4); // (i.e., v1, v2, v3, v4)
    EXPECT_EQ(E->erase(v4), true); // (erased from all cells)
    EXPECT_EQ(E->cell(index)->size(), (size_t) 3); // (i.e., v1, v2, v3)
}


TEST_F(olap_ECube_test, discretization)
{
    // from 0 to 1 cell, no discretization
    
    auto V = std::make_unique<uu::net::VCube>("V");
    E->add("v1");
    
    E->add_dimension("d0", {"m0"});
    EXPECT_EQ(E->size(), (size_t) 1);
    
    // from 0 to 1 cell, discretization, false
    
    V = std::make_unique<uu::net::VCube>("V");
    E->add("v1");
    
    auto d1 = [](const uu::net::Vertex* v) {
        (void)v;
        return std::vector<bool>({false});
    };
    
    E->add_dimension("d0", {"m0"}, d1);
    EXPECT_EQ(E->size(), (size_t) 0);
    
    // from 0 to 1 cell, discretization, true
    
    V = std::make_unique<uu::net::VCube>("V");
    E->add("v1");
    
    auto d2 = [](const uu::net::Vertex* v) {
        (void)v;
        return std::vector<bool>({true});
    };
    
    E->add_dimension("d0", {"m0"}, d2);
    EXPECT_EQ(E->size(), (size_t) 1);
    
    // ORDER 2
    
    V = std::make_unique<uu::net::VCube>("V");
    E->add_dimension("d0", {"m0"});
    E->add("v1");
    E->add("v2");
    E->add("v3");
    EXPECT_EQ(E->size(), (size_t) 3);
    
    auto d3 = [](const uu::net::Vertex* v) {
        if (v->name == "v1") return std::vector<bool>({false, true});
        else if (v->name == "v2") return std::vector<bool>({true, true});
        else return std::vector<bool>({false, false});
    };
    
    E->add_dimension("d1", {"m0", "m1"}, d3);
    
    std::vector<std::string> m00 = {"m0","m0"};
    std::vector<std::string> m01 = {"m0","m1"};
    
    EXPECT_EQ(E->size(), (size_t) 2);
    EXPECT_EQ(E->cell(m00)->size(), (size_t) 1);
    EXPECT_EQ(E->cell(m01)->size(), (size_t) 2);
    
    // ORDER 3
    
    E->add_dimension("d2", {"m0", "m1"}, d3);

    std::vector<std::string> m000 = {"m0","m0","m0"};
    std::vector<std::string> m001 = {"m0","m0","m1"};
    std::vector<std::string> m010 = {"m0","m1","m0"};
    std::vector<std::string> m011 = {"m0","m1","m1"};
    
    EXPECT_EQ(E->size(), (size_t) 2);
    EXPECT_EQ(E->cell(m000)->size(), (size_t) 1);
    EXPECT_EQ(E->cell(m001)->size(), (size_t) 1);
    EXPECT_EQ(E->cell(m010)->size(), (size_t) 1);
    EXPECT_EQ(E->cell(m011)->size(), (size_t) 2);
    
    E->cell(m011)->add("v4");
    EXPECT_EQ(E->size(), (size_t) 3);
}
*/

