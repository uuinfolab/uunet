#include "gtest/gtest.h"

#include "olap/MLCube.hpp"
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
    auto o3 = std::make_shared<Obj>(3);

    std::vector<std::string> dimensions = {"d1"};
    std::vector<std::vector<std::string>> members = {{"m1", "m2"}};

    using CONTAINER = uu::core::ObjectStore<Obj>;

    //auto init = {std::make_shared<CONTAINER>(), std::make_shared<CONTAINER>()};
    //uu::core::CCube<CONTAINER> c(dimensions, members, init.begin(), init.end());
    auto el = std::make_unique<CONTAINER>();
    uu::net::MLCube<CONTAINER> c(std::move(el), dimensions, members);
    std::vector<size_t> idx = {0};
    c.init(idx, std::make_shared<CONTAINER>());
    idx[0] = 1;
    c.init(idx, std::make_shared<CONTAINER>());

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

    std::vector<std::string> m1 = {"m1"};
    c[m1]->add(o1);
    c.at(m1)->add(o2);
    std::vector<std::string> m2 = {"m2"};
    c[m2]->add(o2);
    c.at(m2)->add(o3);

    EXPECT_EQ(c[m1]->size(), (size_t)2);
    EXPECT_EQ(c[m2]->size(), (size_t)2);

    EXPECT_EQ(c.elements()->size(), (size_t)3);

}

