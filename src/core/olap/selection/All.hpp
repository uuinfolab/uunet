#ifndef UU_OLAP_SEL_RANGE_H_
#define UU_OLAP_SEL_RANGE_H_

#include <cstddef>
#include <stddef.h>
#include "core/olap/selection/Indexes.hpp"

namespace uu {
namespace core {

class All
    : public Indexes
{

  public:

    All();

    /**  */
    virtual
    void
    eval(
        size_t size
    ) override;

    /**  */
    virtual
    bool
    has_next(
    ) const override;


    /**  */
    virtual
    size_t
    next(
    ) override;

  private:

    size_t max_;
    size_t current_;
    bool has_next_;

};

}
}

#endif
