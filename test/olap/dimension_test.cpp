#include "gtest/gtest.h"

#include "olap/VCube.hpp"
#include "./TestDiscretization.hpp"

#include "olap/op/d-extension.hpp"

TEST(olap_operators_test, dimension_change1)
{

    auto V = std::make_unique<uu::net::VCube>("V");
    V->add("000");
    V->add("001");
    V->add("011");
    V->add("112");

    // EXTENSIONS
    
    // A -> B, three vertices preserved
    auto d1 = uu::net::TestDiscretization<uu::net::Vertex>(0, 1);

    uu::net::extend_dimension(V.get(), "d0", {"m0"}, d1);

    EXPECT_EQ(V->order(), (size_t) 1);
    EXPECT_EQ(V->size(), (size_t) 3);
    
    // B -> B, two vertices preserved
    auto d2 = uu::net::TestDiscretization<uu::net::Vertex>(1, 1);

    uu::net::extend_dimension(V.get(), "d1", {"m0"}, d2);

    EXPECT_EQ(V->order(), (size_t) 2);
    EXPECT_EQ(V->size(), (size_t) 2);
    
    // B -> C, two vertices preserved
    auto d3 = uu::net::TestDiscretization<uu::net::Vertex>(2, 2);

    uu::net::extend_dimension(V.get(), "d2", {"m0", "m1"}, d3);

    EXPECT_EQ(V->order(), (size_t) 3);
    EXPECT_EQ(V->size(), (size_t) 2);
    auto idx30 = std::vector<std::string>({"m0", "m0", "m0"});
    auto idx31 = std::vector<std::string>({"m0", "m0", "m1"});
    EXPECT_EQ(V->cell(idx30)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(idx31)->size(), (size_t) 1);
    
    
    // C -> C, two vertices preserved
    uu::net::extend_dimension(V.get(), "d3", {"m0", "m1"}, d3);

    EXPECT_EQ(V->order(), (size_t) 4);
    EXPECT_EQ(V->size(), (size_t) 2);
    auto idx40 = std::vector<std::string>({"m0", "m0", "m0", "m0"});
    auto idx41 = std::vector<std::string>({"m0", "m0", "m1", "m1"});
    EXPECT_EQ(V->cell(idx40)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(idx41)->size(), (size_t) 1);

    // CONTRACTIONS
    
    // C -> C
    V->erase_dimension();

    EXPECT_EQ(V->order(), (size_t) 3);
    EXPECT_EQ(V->size(), (size_t) 2);
    EXPECT_EQ(V->cell(idx30)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(idx31)->size(), (size_t) 1);
    
    // C -> B
    V->erase_dimension();
    
    EXPECT_EQ(V->order(), (size_t) 2);
    EXPECT_EQ(V->size(), (size_t) 2);
    
    // B -> B
    V->erase_dimension();
    
    EXPECT_EQ(V->order(), (size_t) 1);
    EXPECT_EQ(V->size(), (size_t) 2);
    
    // B -> A
    V->erase_dimension();
    
    EXPECT_EQ(V->order(), (size_t) 0);
    EXPECT_EQ(V->size(), (size_t) 2);
}


TEST(olap_operators_test, dimension_change2)
{
    auto V = std::make_unique<uu::net::VCube>("V");
    V->add("000");
    V->add("001");
    V->add("011");
    V->add("112");
    
    // EXTENSION
    
    // A -> C, two vertices preserved
    auto d = uu::net::TestDiscretization<uu::net::Vertex>(2, 2);
    uu::net::extend_dimension(V.get(), "d1", {"m0", "m1"}, d);

    EXPECT_EQ(V->order(), (size_t) 1);
    EXPECT_EQ(V->size(), (size_t) 3);
    auto idx10 = std::vector<std::string>({"m0"});
    auto idx11 = std::vector<std::string>({"m1"});
    EXPECT_EQ(V->cell(idx10)->size(), (size_t) 1);
    EXPECT_EQ(V->cell(idx11)->size(), (size_t) 2);
    
    // CONTRACTION
    
    // C -> A
    V->erase_dimension();
    EXPECT_EQ(V->order(), (size_t) 0);
    EXPECT_EQ(V->size(), (size_t) 3);

}
