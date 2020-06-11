
#include "core/exceptions/assert_not_null.hpp"
#include "core/utils/pretty_printing.hpp"
#include "core/olap/selection/IndexIterator.hpp"

namespace uu {
namespace net {

template <typename C, typename DiscretizationFunction>
std::unique_ptr<C>
embed(
    const C* const cube,
    const std::string& dim_name,
    const std::vector<std::string>& dim_members,
    DiscretizationFunction f
)
{
    core::assert_not_null(cube, "embed", "cube");


    // @todo check not null, dimensions, ...

    // new dimensions (@todo common code, put into utility function)

    auto dim_names = cube->dim();

    std::vector<std::vector<std::string>> members(dim_names.size());

    for (size_t i = 0; i < dim_names.size(); i++)
    {
        auto member_names = cube->members(dim_names.at(i));

        for (auto name: member_names)
        {
            members[i].push_back(name);
        }
    }

    dim_names.push_back(dim_name);
    members.push_back(dim_members);

    // output cube
    auto out_cube = cube->model(dim_names, members);

    // for each cell in the input cube compute the corresponding cell in the output cube
    // and copy it.

    core::IndexIterator in_idx(cube->size());
    auto in_idx_iter = in_idx.begin();

    while (in_idx_iter != in_idx.end())
    {
        // we process cell at in_index in the input cube
        auto in_index = *in_idx_iter;

        // init corresponding cells in out cube
        for (size_t i=0; i<dim_members.size(); i++)
        {
            in_index.push_back(i);
            out_cube->init(in_index);
            in_index.pop_back();
        }

        // distribute the elements in in_cube[in_index] to the out_cube based on f()
        auto cell = cube->at(in_index);

        for (auto el: *cell)
        {
            for (auto idx: f(el))
            {
                in_index.push_back(idx);
                out_cube->operator[](in_index)->add(el);
                in_index.pop_back();
            }
        }

        ++in_idx_iter;
    }

    return out_cube;
}



}
}

