#include "gtest/gtest.h"

#include "core/stores/ObjectStore.hpp"
#include "objects/Vertex.hpp"
#include <map>


TEST(core_stores_test, ObjectStore)
{

    std::map<int, uu::core::ObjectStore<uu::net::Vertex>> map;

    auto v1_ = std::make_shared<uu::net::Vertex>("vertex 1");
    map[0].add(v1_.get());

    auto v2_ = std::make_shared<uu::net::Vertex>("vertex 2");
    map[0].add(v2_.get());

    size_t c = 0;


    for (auto pair: map)
    {
        auto set = pair.second;

        for (auto v: set)
        {
            (void)v;
            c++;
        }
    }

    EXPECT_EQ((size_t)2, c)
            << "First iteration";
    c = 0;

    for (auto pair: map)
    {
        auto set = pair.second;

        for (auto v: set)
        {
            (void)v;
            c++;
        }
    }

    EXPECT_EQ((size_t)2, c)
            << "Second iteration";

}
