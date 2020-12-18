#include "gtest/gtest.h"

#include "./operators.hpp"

#include "olap/extension.hpp"


TEST_F(net_olap_operators_test, extension)
{

    // For the sake of testing, this function object assigns vertices to different
    // dimension members without using any information about them, but only
    // depending on the order in which they are passed to the function.
    class ARandomFunct
    {
      public:

        std::set<size_t>
        operator () (const uu::net::Vertex* v)
        {
            std::set<size_t> res;

            if (v->name == "1")
            {
                res.insert(0);
                res.insert(1);
            }

            if (v->name == "2")
            {
                res.insert(0);
            }

            return res;
        }
    };

    std::string name = "new_dim";
    std::vector<std::string> memb = {"odd", "even"};
    auto out_cube = uu::net::extend(vcube.get(), name, memb, ARandomFunct());

    // Cell [0,0,0] in vcube contains two vertices. The first should be assigned
    // to members 0 and 1 in the new dimension, the second to member 0.

    std::vector<size_t> cell0000 = {0, 0, 0, 0};
    std::vector<size_t> cell0001 = {0, 0, 0, 1};

    EXPECT_EQ((size_t)2, (*out_cube)[cell0000]->size());
    EXPECT_EQ((size_t)1, (*out_cube)[cell0001]->size());

}
