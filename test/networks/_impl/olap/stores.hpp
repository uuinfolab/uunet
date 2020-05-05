#ifndef UU_TEST_STORES_H_
#define UU_TEST_STORES_H_


#include "gtest/gtest.h"

#include <memory>
#include "objects/Vertex.hpp"

class net_datastructures_stores : public ::testing::Test
{
  protected:

    // Some vertices to be used in the tests
    std::shared_ptr<const uu::net::Vertex> v1, v2, v3, v1b;

    virtual void
    SetUp()
    {
        v1 = std::make_shared<uu::net::Vertex>("vertex 1");
        v2 = std::make_shared<uu::net::Vertex>("vertex 2");
        v3 = std::make_shared<uu::net::Vertex>("vertex 3");
        v1b = std::make_shared<uu::net::Vertex>("vertex 1");
    }
};

#endif
