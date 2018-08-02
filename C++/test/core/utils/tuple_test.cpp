#include "gtest/gtest.h"

#include "core/utils/tuple.h"

TEST(core_utils_tuple_test, no_test)
{

    std::tuple<int, double, std::string> t(42, 3.14, "Hello World!");
    
    //uu::core::for_each_in_tuple(t, uu::core::print_tuple_element());

    //uu::core::for_each_in_seq<2,3>(uu::core::print_pair());
    
}

