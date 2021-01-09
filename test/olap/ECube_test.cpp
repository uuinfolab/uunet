#include "gtest/gtest.h"

#include "olap/ECube.hpp"
#include "olap/VCube.hpp"

TEST(olap_test, ECube)
{
    auto vc1 = std::make_unique<uu::net::VCube>("V1");
    vc1->add_dimension("d", {"m"});
    auto vc2 = std::make_unique<uu::net::VCube>("V2");
    vc2->add_dimension("d", {"m"});

    auto v1 = std::make_shared<const uu::net::Vertex>("v1");
    auto v2 = std::make_shared<const uu::net::Vertex>("v2");
    
    vc1->add(v1);
    vc1->add(v2);
    
    vc2->add(v1);
    vc2->add(v2);

    uu::net::ECube ecube("E", vc1.get(), vc2.get(), uu::net::EdgeDir::DIRECTED);
    ecube.add_dimension("d", {"m"});

    ecube.add(v1.get(), vc1.get(), v1.get(), vc2.get());
    ecube.add(v1.get(), vc1.get(), v2.get(), vc2.get());
    
    EXPECT_EQ(ecube.size(), (size_t)2);

}

