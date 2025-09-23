#include "gtest/gtest.h"

#include <vector>
#include "generation/communities.hpp"

TEST(net_creation_test, communities_pep)
{
    std::size_t layers = 5;
    std::size_t actors = 50;
    std::size_t communities = 10;
    std::vector<double> pi = {.4, .4, .4, .4, .4};
    std::vector<double> pe = {.01, .01, .01, .01, .01};
    
    auto pair = uu::net::generate_pep(layers, actors, communities, pi, pe);

    ASSERT_EQ(std::size_t(50), pair.first->actors()->size());
    ASSERT_EQ(std::size_t(5), pair.first->layers()->size());
    ASSERT_EQ(std::size_t(10), pair.second->size());
}


TEST(net_creation_test, communities_sep)
{
    std::size_t layers = 3;
    std::size_t actors = 50;
    std::size_t communities = 10;
    std::vector<double> pi = {.4, .4, .4};
    std::vector<double> pe = {.01, .01, .01};
    
    auto pair = uu::net::generate_sep(layers, actors, communities, pi, pe);
    
    ASSERT_EQ(std::size_t(50), pair.first->actors()->size());
    ASSERT_EQ(std::size_t(3), pair.first->layers()->size());
    ASSERT_EQ(std::size_t(10), pair.second->size());
}


TEST(net_creation_test, communities_peo)
{
    std::size_t layers = 3;
    std::size_t actors = 50;
    std::size_t communities = 10;
    std::size_t overlap = 3;
    std::vector<double> pi = {.4, .4, .4};
    std::vector<double> pe = {.01, .01, .01};
    
    auto pair = uu::net::generate_peo(layers, actors, communities, overlap, pi, pe);
    
    ASSERT_EQ(std::size_t(50), pair.first->actors()->size());
    ASSERT_EQ(std::size_t(3), pair.first->layers()->size());
    ASSERT_EQ(std::size_t(10), pair.second->size());
}


TEST(net_creation_test, communities_seo)
{
    std::size_t layers = 3;
    std::size_t actors = 50;
    std::size_t communities = 10;
    std::size_t overlap = 3;
    std::vector<double> pi = {.4, .4, .4};
    std::vector<double> pe = {.01, .01, .01};
    
    auto pair = uu::net::generate_seo(layers, actors, communities, overlap, pi, pe);
    
    ASSERT_EQ(std::size_t(50), pair.first->actors()->size());
    ASSERT_EQ(std::size_t(3), pair.first->layers()->size());
    ASSERT_EQ(std::size_t(10), pair.second->size());
}

