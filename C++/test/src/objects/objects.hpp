#ifndef UU_TEST_OBJECTS_H_
#define UU_TEST_OBJECTS_H_

#include "gtest/gtest.h"

#include "objects/Vertex.hpp"
#include "objects/Edge.hpp"

class objects_test : public ::testing::Test
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
        v1_ = std::make_shared<uu::net::Vertex>("v1");
        v1 = v1_.get();
        v2_ = std::make_shared<uu::net::Vertex>("v2");
        v2 = v2_.get();
        v3_ = std::make_shared<uu::net::Vertex>("v3");
        v3 = v3_.get();

        e1_ = std::make_shared<uu::net::Edge>(v1, v2, uu::net::EdgeDir::DIRECTED);
        e1 = v2_v1_d_.get();
        e2_ = std::make_shared<uu::net::Edge>(v2, v3, uu::net::EdgeDir::UNDIRECTED);
        e2 = v2_v1_ud_.get();
        e3_ = std::make_shared<uu::net::Edge>(v2, v3, uu::net::EdgeDir::DIRECTED);
        e3 = v2_v3_d_.get();
    }
};


#endif
