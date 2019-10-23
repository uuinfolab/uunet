#include "gtest/gtest.h"

#include "core/stores/ObjectStore.hpp"
#include "olap/datastructures/CCube.hpp"
#include "olap/operators/slice.hpp"

class Obj :
    public std::enable_shared_from_this<Obj>
{
  public:
    typedef int key_type;
    Obj(int val) : key(val), val(val) {}
    const key_type key;
    int val;
};

using CONTAINER = uu::core::ObjectStore<Obj>;

class core_olap_operators_test : public ::testing::Test
{
  protected:

    std::unique_ptr<uu::olap::CCube<CONTAINER>> c;

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

        c = std::make_unique<uu::olap::CCube<CONTAINER>>(dimensions, members, init.begin(), init.end());

        // @todo add easier iteration
        std::vector<std::string> index1 = {"m1","m1"};
        std::vector<std::string> index2 = {"m2","m1"};
        (*c)[index1]->add(o1);
        (*c)[index2]->add(o2);

    }
};


TEST_F(core_olap_operators_test, islice)
{
    // @todo make test
    std::vector<std::vector<size_t>> s = {{0}, {0,1}};

    for (auto e: islice(c.get(), s))
    {
        std::cout << "entry:" << std::endl;

        for (auto obj: *e)
        {
            std::cout << obj->val << std::endl;
        }
    }

}




TEST_F(core_olap_operators_test, vslice)
{


    std::vector<std::vector<size_t>> s = {{0}, {0,1}};

    /*
    auto slice = vslice(c.get(), s);

    for (auto e: islice(slice.get(), s))
    {
        std::cout << "entry:" << std::endl;

        for (auto obj: e)
        {
            std::cout << obj->val << std::endl;
        }
    }
    
    (*c)[{(size_t)0,(size_t)0}]->add(std::make_shared<Obj>(3));

    for (auto e: islice(slice.get(), s))
    {
        std::cout << "entry:" << std::endl;

        for (auto obj: e)
        {
            std::cout << obj->val << std::endl;
        }
    }


    std::cout << "All cube:" << std::endl;

    for (auto e: *c->elements())
    {
        std::cout << e->val << std::endl;
    }
     

    std::cout << "All slice:" << std::endl;

    for (auto e: *(slice->elements()))
    {
        std::cout << e->val << std::endl;
    }
     */
}

