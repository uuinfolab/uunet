#include "gtest/gtest.h"

#include "core/stores/ObjectStore.hpp"
#include "core/olap/datastructures/CCube.hpp"

class Obj :
    public std::enable_shared_from_this<Obj>
{
  public:
    typedef int key_type;
    Obj(int val) : key(val), val(val) {}
    const key_type key;
    int val;
};

class ObjStore :
    public uu::core::ObjectStore<Obj>,
    public std::enable_shared_from_this<ObjStore>
{
};

using CONTAINER = ObjStore;

class core_olap_operators_test_resize : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::core::CCube<CONTAINER>> c;

    virtual void
    SetUp()
    {
        auto o1 = std::make_shared<Obj>(1);
        auto o2 = std::make_shared<Obj>(2);

        std::vector<std::string> dimensions = {"d1", "d2"};
        std::vector<std::vector<std::string>> members = {{"m1","m2"}, {"m1","m2"}};


        std::vector<std::shared_ptr<CONTAINER>> init;

        for (size_t i = 0; i < 4; i++)
        {
            init.push_back(std::make_shared<CONTAINER>());
        }

        c = std::make_unique<uu::core::CCube<CONTAINER>>(dimensions, members, init.begin(), init.end());

        // @todo add easier iteration
        std::vector<std::string> index1 = {"m1","m1"};
        std::vector<std::string> index2 = {"m2","m1"};
        (*c)[index1]->add(o1);
        (*c)[index2]->add(o2);

    }
};


TEST_F(core_olap_operators_test_resize, resize)
{

    std::vector<std::shared_ptr<CONTAINER>> new_containers;

    for (size_t i = 0; i < 2; i++)
    {
        new_containers.push_back(std::make_shared<CONTAINER>());
    }

    c->resize("d1", "m3", new_containers.begin(), new_containers.end());

    /*
    for (auto cell: *c)
    {
        std::cout << cell->size() << std::endl;
    }
    */
}


