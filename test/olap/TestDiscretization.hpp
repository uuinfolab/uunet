#ifndef UU_TEST_OLAP_UNIFORMDISCRETIZATION_H_
#define UU_TEST_OLAP_UNIFORMDISCRETIZATION_H_

#include "olap/op/Discretization.hpp"

namespace uu {
namespace net {

template <class O>
class
    TestDiscretization
    : public Discretization<O>
{

  private:

    size_t pos_;
    size_t order_;

  public:

    TestDiscretization(
        size_t pos,
        size_t order // [1,10]
    ) : pos_(pos), order_(order)
    {}

    std::vector<bool>
    operator()(
        const O* obj
    ) const
    {
        auto res = std::vector<bool>(order_, false);
        size_t p = obj->name[pos_] - '0';
        if (p >= order_) return res;
        res[p] = true;
        return res;
    }


};


}
}

#endif
