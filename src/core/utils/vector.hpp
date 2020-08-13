/**
 * This header defines:
 * basic mathematical/statistical functions (mean, standard deviation, intersection, union).
 *
 * History:
 * - 2018.01.01 file imported from version 1.0 of the multinet library
 */

#ifndef UU_CORE_UTILS_VECTOR_H_
#define UU_CORE_UTILS_VECTOR_H_

#include <vector>

namespace uu {
namespace core {

/**
 * Moves the element at position from to position to, shifting the other elements accordingly
 */
    template <typename E>
    void
    move(
         std::vector<E>& vec,
         size_t from,
         size_t to
         );

    
    std::vector<size_t>
    seq(
         size_t from,
        size_t to
        );
    
}
}

#include "vector.ipp"

#endif
