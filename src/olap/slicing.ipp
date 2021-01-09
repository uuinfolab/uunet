
/*#include <string>
#include "core/utils/pretty_printing.hpp"
#include "core/exceptions/assert_not_null.hpp"
#include "core/olap/selection/IndexIterator.hpp"
#include "core/utils/vector.hpp"*/
//#include "core/olap/selection/EntryIterator.hpp"
//#include "olap/_impl/d-sort.hpp"
//#include "olap/_impl/m-sort.hpp"
//#include "olap/_impl/m-contraction.hpp"

namespace uu {
namespace net {

template <typename C>
std::unique_ptr<C>
vslice(
const std::string& cube_name,
    C* cube,
    const std::vector<std::vector<size_t>>& indexes
)
{
    
   // @todo check not null, dimensions, ...
    size_t num_dimensions = indexes.size();
    auto dim_names = cube->dimension_names(); // slicing does not change dimensionality
    std::vector<std::vector<std::string>> new_members;
    for (size_t i = 0; i < num_dimensions; i++)
    {
        auto member_names = cube->members(dim_names[i]);
        
        std::vector<std::string> members;
        for (auto idx: indexes[i])
        {
            members.push_back(member_names.at(idx));
        }
        new_members.push_back(members);
    }

    // Generalize to work with all types of cubes
    auto out_cube = std::unique_ptr<C>(new C(cube_name, dim_names, new_members));

    // indexes in the new cube corresponding to the input indexes
    
    core::IndexIterator in_idx(indexes);
    core::IndexIterator out_idx(out_cube->dimensions());

    auto in_idx_iter = in_idx.begin();
    auto out_idx_iter = out_idx.begin();

    while (in_idx_iter != in_idx.end())
    {
        auto cell = cube->cell(*in_idx_iter)->shared_from_this();
        out_cube->init(*out_idx_iter, cell);
        ++in_idx_iter;
        ++out_idx_iter;
    }

    return out_cube;
}

}
}

