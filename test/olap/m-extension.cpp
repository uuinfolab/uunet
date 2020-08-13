#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/_impl/m-extension.hpp"


TEST_F(net_olap_operators_test, extend_members)
{

    // For the sake of testing, this function object assigns vertices to different
    // dimension members without using any information about them, but only
    // depending on the order in which they are passed to the function.
    class ARandomFunct
    {
        size_t num = 0;
        
    public:
        
        bool
        operator () (const uu::net::Vertex* v, size_t member_idx)
        {
            (void)v;
            (void)member_idx;
            std::vector<size_t> res;
            
            if (num++ % 2 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };

    // we already have two vertices in {"m1","m1","m1"}. We add two to {"m1","m1","m2"}.
    std::vector<std::string> index1 = {"m1","m1","m2"};
    (*vcube)[index1]->add(o3);
    (*vcube)[index1]->add(o4);
    
    auto out_cube = uu::net::extend_members(vcube.get(), "m", ARandomFunct());

    std::vector<std::string> dim = {"d1","d2","d3"};
    EXPECT_EQ(dim, out_cube->dim());
    std::vector<std::string> m_d3 = {"m1","m2","m"};
    EXPECT_EQ(m_d3, out_cube->members("d3"));

    std::vector<std::string> index = {"m1","m1","m"};
    EXPECT_EQ((size_t)2, (*out_cube)[index]->size());
    EXPECT_TRUE((*out_cube)[index]->contains(o1.get()) || (*out_cube)[index]->contains(o2.get()));
    EXPECT_TRUE((*out_cube)[index]->contains(o3.get()) || (*out_cube)[index]->contains(o4.get()));
    
}
