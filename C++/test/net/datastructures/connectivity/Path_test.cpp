#include "gtest/gtest.h"

#include "net/datastructures/connectivity/Path.h"
#include "net/datastructures/objects/EdgeDir.h"
#include "core/exceptions/NullPtrException.h"
#include "core/exceptions/WrongParameterException.h"


class net_datastructures_connectivity_Path : public ::testing::Test
{
  protected:

    // Some edges and vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1_, v2_, v3_;
    std::shared_ptr<const uu::net::Edge> v1_v2_d_, v2_v3_d_, v3_v2_d_;

    const uu::net::Vertex* v1;
    const uu::net::Vertex* v2;
    const uu::net::Vertex* v3;
    const uu::net::Edge* v1_v2_d;
    const uu::net::Edge* v2_v3_d;
    const uu::net::Edge* v3_v2_d;

    virtual void
    SetUp()
    {
        v1_ = uu::net::Vertex::create("v1");
        v1 = v1_.get();
        v2_ = uu::net::Vertex::create("v2");
        v2 = v2_.get();
        v3_ = uu::net::Vertex::create("v3");
        v3 = v3_.get();

        v1_v2_d_ = uu::net::Edge::create(v1, v2, uu::net::EdgeDir::DIRECTED);
        v1_v2_d = v1_v2_d_.get();
        v2_v3_d_ = uu::net::Edge::create(v2, v3, uu::net::EdgeDir::DIRECTED);
        v2_v3_d = v2_v3_d_.get();
        v3_v2_d_ = uu::net::Edge::create(v3, v2, uu::net::EdgeDir::DIRECTED);
        v3_v2_d = v3_v2_d_.get();
    }
};


TEST_F(net_datastructures_connectivity_Path, extension)
{
    uu::net::Path p(v1);

    p.extend(v1_v2_d);
    p.extend(v2_v3_d);

    EXPECT_THROW(p.extend(v3_v2_d);, uu::core::WrongParameterException)
            << "duplicate vertex not detected";


}


TEST_F(net_datastructures_connectivity_Path, cycle)
{
    uu::net::Path p(v2);

    p.extend(v2_v3_d);

    EXPECT_FALSE(p.is_cycle())
            << "cycle uncorrectly detected";

    p.extend(v3_v2_d);

    EXPECT_TRUE(p.is_cycle())
            << "cycle not detected";


}
