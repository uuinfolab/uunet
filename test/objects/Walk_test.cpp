#include "gtest/gtest.h"

#include "objects/Walk.hpp"
#include "objects/EdgeDir.hpp"
#include "core/exceptions/NullPtrException.hpp"
#include "core/exceptions/WrongParameterException.hpp"


class net_datastructures_connectivity_Walk : public ::testing::Test
{
  protected:

    // Some edges and vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1_, v2_, v3_;
    std::shared_ptr<const uu::net::Edge> v2_v1_d_, v2_v1_ud_, v2_v3_d_;

    const uu::net::Vertex* v1;
    const uu::net::Vertex* v2;
    const uu::net::Vertex* v3;
    const uu::net::Edge* v2_v1_d;
    const uu::net::Edge* v2_v1_ud;
    const uu::net::Edge* v2_v3_d;

    virtual void
    SetUp()
    {
        v1_ = uu::net::Vertex::create("v1");
        v1 = v1_.get();
        v2_ = uu::net::Vertex::create("v2");
        v2 = v2_.get();
        v3_ = uu::net::Vertex::create("v3");
        v3 = v3_.get();

        v2_v1_d_ = uu::net::Edge::create(v2, v1, uu::net::EdgeDir::DIRECTED);
        v2_v1_d = v2_v1_d_.get();
        v2_v1_ud_ = uu::net::Edge::create(v2, v1, uu::net::EdgeDir::UNDIRECTED);
        v2_v1_ud = v2_v1_ud_.get();
        v2_v3_d_ = uu::net::Edge::create(v2, v3, uu::net::EdgeDir::DIRECTED);
        v2_v3_d = v2_v3_d_.get();
    }
};


TEST_F(net_datastructures_connectivity_Walk, extension)
{
    uu::net::Walk w(v1);

    auto v = w.extend(v2_v1_ud);

    EXPECT_EQ(v2, v)
            << "wrong last vertex after walk extension";

    w.extend(v2_v3_d);

}


TEST_F(net_datastructures_connectivity_Walk, exceptions)
{
    uu::net::Walk w(v1);

    EXPECT_THROW(w.extend(v2_v1_d), uu::core::WrongParameterException)
            << "edge not starting from last vertex not caught";

    EXPECT_THROW(w.extend(nullptr), uu::core::NullPtrException)
            << "null pointer not caught";

}

