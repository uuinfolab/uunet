

#include "core/exceptions/assert_not_null.hpp"
#include "core/utils/pretty_printing.hpp"
#include "core/olap/selection/IndexIterator.hpp"

namespace uu {
namespace net {

template <typename C>
std::unique_ptr<C>
mrollup(
    const C* const cube,
    size_t dim_idx,
    const std::vector<std::string>& new_members,
    const std::vector<int>& partition
)
{
    // @todo check not null, dimensions, ...


    // new dimensions (@todo common code, put into utility function)

    auto dim_names = cube->dim();

    std::vector<std::vector<std::string>> members(dim_names.size());

    for (size_t i = 0; i < dim_names.size(); i++)
    {
        if (i == dim_idx)
        {
            for (auto name: new_members)
            {
                members[i].push_back(name);
            }
        }

        else
        {
            auto member_names = cube->members(dim_names.at(i));

            for (auto name: member_names)
            {
                members[i].push_back(name);
            }
        }
    }

    // output cube

    auto out_cube = cube->model(dim_names, members);

    // indexes in the new cube corresponding to the input indexes

    auto size = cube->size();

    std::vector<std::vector<size_t>> old_indexes;
    std::vector<std::vector<size_t>> new_indexes;

    for (size_t i=0; i<size.size(); i++)
    {
        if (i == dim_idx)
        {
            std::vector<size_t> old_members;
            std::vector<size_t> new_members;

            for (size_t j=0; j<size[i]; j++)
            {
                if (partition[j] != -1)
                {
                    old_members.push_back(j);
                    new_members.push_back(partition[j]);
                }
            }

            old_indexes.push_back(old_members);
            new_indexes.push_back(new_members);
        }

        else
        {
            std::vector<size_t> new_members;

            for (size_t j=0; j<size[i]; j++)
            {
                new_members.push_back(j);
            }

            old_indexes.push_back(new_members);
            new_indexes.push_back(new_members);
        }

    }

    core::IndexIterator in_idx(old_indexes);
    core::IndexIterator out_idx(new_indexes);

    //

    auto in_idx_iter = in_idx.begin();
    auto out_idx_iter = out_idx.begin();

    while (in_idx_iter != in_idx.end())
    {
        //std::cout << core::to_string(*in_idx_iter) << " -> " <<  core::to_string(*out_idx_iter) << std::endl;

        auto cell = cube->at(*in_idx_iter);


        auto out_cell = (*out_cube)[*out_idx_iter];

        if (!out_cell)
        {
            out_cell = out_cube->init(*out_idx_iter);
        }

        for (auto el: *cell)
        {
            out_cell->add(el);
        }

        ++in_idx_iter;
        ++out_idx_iter;
    }

    return out_cube;
}


}
}

