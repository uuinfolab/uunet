#include "gtest/gtest.h"

#include "olap/VCube.hpp"

TEST(olap_test, VCube)
{
    
    uu::net::VCube c("V");

    
    /* ORDER 0 */

    {
        
        // Set functionality
        
        auto V = std::make_unique<uu::net::VCube>("V");
        auto v1 = V->add("v1"); // v1 has type const Vertex*
        EXPECT_EQ(V->size(), (size_t) 1);
        EXPECT_EQ(V->contains(v1), true);
        EXPECT_EQ(V->contains("v1"), true);
        EXPECT_EQ(V->at(0), v1);
        EXPECT_EQ(V->get("v1"), v1);
        EXPECT_EQ(V->get_at_random(), v1);
        EXPECT_EQ(V->index_of(v1), 0);
        EXPECT_EQ(V->erase(v1), true);
        EXPECT_EQ(V->erase("v1"), false);
        
        auto v2_sharedptr = std::make_shared<const uu::net::Vertex>("v2");
        auto v2 = v2_sharedptr.get();
        EXPECT_EQ(V->add(v2), v2);
        V->erase(v2); // @todo check what happens without erasing this
        
        // Attribute functionality
        
        auto attr = V->attr(); // true
        attr->add("A", uu::core::AttributeType::DOUBLE);
        attr->set_double(v2, "A", 3.14);
        EXPECT_EQ(attr->get_double(v2, "A").value, 3.14);
        
        // Cube functionality
        
        EXPECT_EQ(V->order(), (size_t) 0);
        EXPECT_EQ(V->dsize(), std::vector<size_t>({}));
        EXPECT_EQ(V->dimensions(), std::vector<std::string>({}));
        EXPECT_EQ(V->members(), std::vector<std::vector<std::string>>({}));
        
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
        V->cell(index)->add("v3");
        V->cell(index)->add("v4");
        EXPECT_EQ(V->size(), (size_t) 2);
        
        EXPECT_THROW(V->add("v5"), uu::core::OperationNotSupportedException); // throws OperationNotSupportedException
    }
    
    // Basic cube info

    EXPECT_EQ(c.order(), (size_t)0);

    EXPECT_EQ(c.dimensions().size(), (size_t)0);

    
    /* ORDER 1, 1 cell */
    
    // Adding/retrieving/erasing some elements, created in different ways.
    // The cube has one cell, so we can do this directly on it.
    
    c.add_dimension("d0", {"m0"});
    
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
    
    
    /* ORDER 2 */
    
    auto discretize = [](const uu::net::Vertex* v) {
        if (v->name == "v1") return std::vector<bool>({false, true});
        else return std::vector<bool>({true, true});
    };
    
    c.add_dimension("d1", {"m0", "m1"}, discretize);
    
    EXPECT_EQ(c.order(), (size_t)2);
    
    std::vector<std::string> m0 = {"m0","m0"};
    std::vector<std::string> m1 = {"m0","m1"};
    
    EXPECT_EQ(c.size(), (size_t)2);
    EXPECT_EQ(c.cell(m0)->size(), (size_t)1);
    EXPECT_EQ(c.cell(m1)->size(), (size_t)2);
    
    /* ORDER 3 */
    
    c.add_dimension("d2", {"m0", "m1"}, discretize);
    
    EXPECT_EQ(c.order(), (size_t)3);
    
    std::vector<std::string> m00 = {"m0","m0","m0"};
    std::vector<std::string> m01 = {"m0","m0","m1"};
    std::vector<std::string> m10 = {"m0","m1","m0"};
    std::vector<std::string> m11 = {"m0","m1","m1"};
    
    EXPECT_EQ(c.size(), (size_t)2);
    EXPECT_EQ(c.cell(m00)->size(), (size_t)1);
    EXPECT_EQ(c.cell(m01)->size(), (size_t)1);
    EXPECT_EQ(c.cell(m10)->size(), (size_t)1);
    EXPECT_EQ(c.cell(m11)->size(), (size_t)2);
    
    c.cell(m11)->add("v4");
    EXPECT_EQ(c.size(), (size_t)3);
    
    /* ORDER 2 */
    
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

