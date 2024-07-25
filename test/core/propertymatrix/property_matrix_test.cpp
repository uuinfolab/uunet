#include "gtest/gtest.h"

#include "core/propertymatrix/PropertyMatrix.hpp"
#include "core/propertymatrix/summarization.hpp"

// @todo more tests can be added

class core_propertymatrix_test : public ::testing::Test
{
  protected:

    uu::core::PropertyMatrix<int,int,bool> P = uu::core::PropertyMatrix<int,int,bool>(4,2,true);

    void
    SetUp() override
    {

        // creating a property matrix
        P.set(0,0,false);
        P.set(2,1,false);
        P.set(3,0,false);
        P.set(3,1,false);

    }

};


TEST_F(core_propertymatrix_test, PropertyMatrix)
{
    
    // retrieving values
    EXPECT_EQ(P.get(0,0).value, false)
            << "Wrong value for field 0,0";
    EXPECT_EQ(P.get(2,1).value, false)
            << "Wrong value for field 2,1";
    EXPECT_EQ(P.get(0,1).value, true)
            << "Wrong default value for field 0,1";

    // metadata
    EXPECT_EQ(P.structures().size(), (size_t)3)
            << "Wrong number of structures";
    EXPECT_EQ(P.contexts().size(), (size_t)2)
            << "Wrong number of contexts";

}

TEST_F(core_propertymatrix_test, summarization)
{

    EXPECT_EQ(uu::core::russell_rao(P,0,1), 1.0/4)
            << "Wrong function: russell_rao";
    EXPECT_EQ(uu::core::coverage(P,0,1), 1.0/2)
            << "Wrong function: coverage";
    EXPECT_EQ(uu::core::jaccard(P,0,1), 1.0/3)
            << "Wrong function: jaccard";
    EXPECT_EQ(uu::core::kulczynski2(P,0,1), 1.0/2)
            << "Wrong function: kulczynski2";
    EXPECT_EQ(uu::core::simple_matching(P,0,1), 2.0/4)
            << "Wrong function: simple_matching";

}

