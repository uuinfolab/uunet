#include "gtest/gtest.h"

#include "core/stores/ObjectStore.hpp"
#include "objects/Vertex.hpp"
#include <map>


TEST(core_stores_test, ObjectStore)
{

    std::map<int, uu::core::ObjectStore<uu::net::Vertex>> map;

    auto v1_ = std::make_shared<uu::net::Vertex>("vertex 1");
    std::cout << "vertex: " << v1_.get() << std::endl;
    map[0].add(v1_.get());
    std::cout << "added" << std::endl;

    auto v2_ = std::make_shared<uu::net::Vertex>("vertex 2");
    std::cout << "vertex: " << v2_.get() << std::endl;
    map[0].add(v2_.get());
    std::cout << "added" << std::endl;

    size_t c = 0;

    std::cout << "it" << std::endl;

    for (auto pair: map)
    {
        std::cout << "assign" << std::endl;
        auto set = pair.second;
        std::cout << "s: " << set.size() << std::endl;

        for (auto v: set)
        {
            c++;
        }
    }

    EXPECT_EQ((size_t)2, c)
            << "First iteration";
    c = 0;

    for (auto pair: map)
    {
        auto set = pair.second;
        std::cout << "s: " << set.size() << std::endl;

        for (auto v: set)
        {
            c++;
        }
    }

    EXPECT_EQ((size_t)2, c)
            << "Second iteration";

}
