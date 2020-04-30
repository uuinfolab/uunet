#include "gtest/gtest.h"

#include "core/olap/datastructures/CCube.hpp"
#include "core/stores/ObjectStore.hpp"

TEST(core_olap_test, CCube)
{
    class Obj :
        public std::enable_shared_from_this<Obj>
    {
      public:
        typedef int key_type;
        Obj(int val) : key(val), val(val) {}
        const key_type key;
        int val;
    };
    auto o1 = std::make_shared<Obj>(1);
    auto o2 = std::make_shared<Obj>(2);

    std::vector<std::string> dimensions = {"d1"};
    std::vector<std::vector<std::string>> members = {{"m1", "m2"}};

    using CONTAINER = uu::core::ObjectStore<Obj>;

    auto init = {std::make_shared<CONTAINER>(), std::make_shared<CONTAINER>()};
    uu::core::CCube<CONTAINER> c(dimensions, members, init.begin(), init.end());

    // Basic cube info

    EXPECT_EQ(c.order(), (size_t)1)
            << "Wrong order (number of dimensions)";

    EXPECT_EQ(c.dim().size(), (size_t)1)
            << "Wrong number of dimensions";

    EXPECT_EQ(c.dim().at(0), "d1")
            << "Wrong dimension name";

    EXPECT_EQ(c.size().at(0), (size_t)2)
            << "Wrong number of members for dimension d1";

    EXPECT_EQ(c.members("d1").size(), (size_t)2)
            << "Wrong number of members for dimension d1";

    EXPECT_EQ(c.members("d1").at(0), "m1")
            << "Wrong member name";

    std::vector<std::string> index = {"m1"};
    c[index]->add(o1);
    c.at(index)->add(o2);

    EXPECT_EQ(c[index]->size(), (size_t)2);

    EXPECT_EQ(c.elements()->size(), (size_t)2);

    // Iterating over the containers
    /*
    for (auto cont: c)
    {
        std::cout << cont->size() << std::endl;
    }
     */
}

