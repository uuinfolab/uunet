#include "core/stores/AttributeStore.hpp"
#include "core/exceptions/OutOfBoundsException.hpp"
#include "core/exceptions/WrongParameterException.hpp"
#include "core/exceptions/OutOfBoundsException.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/datastructures/containers/UnionSortedRandomSet.hpp"
#include "core/olap/datastructures/NCube.hpp"
#include "core/olap/selection/IndexIterator.hpp"
#include <string>
#include <unordered_map>
#include <vector>

namespace uu {
namespace net {

template <class STORE>
MLCube<STORE>::
MLCube(
    //const std::string& name,
    const std::shared_ptr<STORE>& el
    //const std::vector<std::string>& dim,
    //const std::vector<std::vector<std::string>>& members
) //: name(name)
{
    elements_ = el;

    size_ = {};
    //off_ = {};

    //union_obs = std::make_unique<core::UnionObserver<STORE, const typename STORE::value_type>>(elements_.get());

    // Element attributes
    attr_ = std::make_unique<core::AttributeStore<typename STORE::value_type>>();
    elements_->attach(attr_.get());
}

/*
template <class STORE>
MLCube<STORE>::
MLCube(
    const std::string& name,
    const std::shared_ptr<STORE>& el,
    const std::vector<std::string>& dim,
    const std::vector<std::vector<std::string>>& members
) : MLCube(name, std::move(el)) // @todo necessary to specify the move?
{

    // @todo add checks

    size_t length = 1;
    for (size_t d_idx = 0; d_idx < members.size(); d_idx++)
    {
        length *= members[d_idx].size();
        dim_idx_[dim[d_idx]] = d_idx;
        size_.push_back(members[d_idx].size());
        members_idx_.push_back(std::unordered_map<std::string, size_t>());
        for (size_t m_idx = 0; m_idx < members[d_idx].size(); m_idx++)
        {
            members_idx_[d_idx][members[d_idx][m_idx]] = m_idx;
        }
    }

    union_obs = std::make_unique<core::UnionObserver<STORE, const typename STORE::value_type>>(elements_.get());

    data_ = std::vector<std::shared_ptr<STORE>>(length);

}
*/

template <class STORE>
MLCube<STORE>::
MLCube(
    //const std::string& name,
    const std::vector<std::string>& dimensions,
    const std::vector<std::vector<std::string>>& members
)
{
    size_t length = 1;

    for (size_t d_idx = 0; d_idx < members.size(); d_idx++)
    {
        length *= members[d_idx].size();
        dim_.push_back(dimensions[d_idx]);
        dim_idx_[dimensions[d_idx]] = d_idx;
        size_.push_back(members[d_idx].size());
        members_.push_back(std::vector<std::string>());
        members_idx_.push_back(std::unordered_map<std::string, size_t>());

        for (size_t m_idx = 0; m_idx < members[d_idx].size(); m_idx++)
        {
            members_[d_idx].push_back(members[d_idx][m_idx]);
            members_idx_[d_idx][members[d_idx][m_idx]] = m_idx;
        }
    }

    data_ = std::vector<std::shared_ptr<STORE>>(length);

    attr_ = std::make_unique<core::AttributeStore<typename STORE::value_type>>();
}


template <class STORE>
size_t
MLCube<STORE>::
size(
) const
{
    return elements_->size();
}


template <class STORE>
size_t
MLCube<STORE>::
order(
) const
{
    return size_.size();
}


template <class STORE>
std::vector<size_t>
MLCube<STORE>::
dsize(
) const
{
    return size_;
}


template <class STORE>
const std::vector<std::string>&
MLCube<STORE>::
dimensions(
) const
{
    return dim_;
}


template <class STORE>
const std::vector<std::vector<std::string>>&
        MLCube<STORE>::
        members(
        ) const
{
    return members_;
}


template <class STORE>
const std::vector<std::string>&
MLCube<STORE>::
members(
    const std::string& dimension_name
) const
{
    auto f = dim_idx_.find(dimension_name);

    if (f != dim_idx_.end())
    {
        // no need to check bounds
        return members_[f->second];
    }

    else
    {
        throw core::ElementNotFoundException("dimension " + dimension_name);
    }
}

template <class STORE>
const std::vector<std::string>&
MLCube<STORE>::
members(
    size_t dim_idx
) const
{
    return members_.at(dim_idx);
}

template <class STORE>
typename STORE::iterator
MLCube<STORE>::
begin(
) const
{
    //    if (data_.size() == 0)
    //    {
    //        std::string err = "the cube has no cells";
    //        throw core::OperationNotSupportedException(err);
    //    }
    //    else if (data_.size() == 1)
    //    {
    //        return data_[0]->begin();
    //    }
    return elements_->begin();
}

template <class STORE>
typename STORE::iterator
MLCube<STORE>::
end(
) const
{
    //    if (data_.size() == 0)
    //    {
    //        std::string err = "the cube has no cells";
    //        throw core::OperationNotSupportedException(err);
    //    }
    //    else if (data_.size() == 1)
    //    {
    //        return data_[0]->end();
    //    }
    return elements_->end();
}

template <class STORE>
typename STORE::value_type*
MLCube<STORE>::
add(
    std::shared_ptr<typename STORE::value_type> v
)
{
    return add(v.get());
}


template <class STORE>
typename STORE::value_type*
MLCube<STORE>::
add(
    typename STORE::value_type* v
)
{
    if (data_.size() > 1)
    {
        for (size_t i = 0; i < data_.size(); i++)
        {
            data_[i]->add(v);
        }

        return v;
    }

    return elements_->add(v);
}


template <class STORE>
typename STORE::value_type*
MLCube<STORE>::
add(
    const typename STORE::key_type& key
)
{
    if (data_.size() > 1)
    {
        auto v = data_[0]->add(key);

        for (size_t i = 1; i < data_.size(); i++)
        {
            data_[i]->add(v);
        }

        return v;
    }

    return elements_->add(key);
}

template <class STORE>
bool
MLCube<STORE>::
contains(
    typename STORE::value_type* v
) const
{
    return elements_->contains(v);
}

template <class STORE>
bool
MLCube<STORE>::
contains(
    const typename STORE::key_type& key
) const
{
    return elements_->contains(key);

    //auto v = get(key);
    //if (v) return true;
    //else return false;
}



template <class STORE>
typename STORE::get_return_type
MLCube<STORE>::
get(
    const typename STORE::key_type& key
) const
{
    return elements_->get(key);
}

template <class STORE>
typename STORE::value_type*
MLCube<STORE>::
at(
    size_t pos
) const
{
    return elements_->at(pos);
}

template <class STORE>
typename STORE::value_type*
MLCube<STORE>::
get_at_random(
) const
{
    return elements_->get_at_random();
}


template <class STORE>
int
MLCube<STORE>::
index_of(
    typename STORE::value_type* v
) const
{
    return elements_->index_of(v);
}


template <class STORE>
bool
MLCube<STORE>::
erase(
    typename STORE::value_type * v
)
{
    if (data_.size() > 1)
    {
        bool erased = false;

        for (size_t i = 0; i < data_.size(); i++)
        {
            if (data_[i]->erase(v))
            {
                erased = true;
            }
        }

        return erased;
    }

    return elements_->erase(v);
}

template <class STORE>
bool
MLCube<STORE>::
erase(
    const typename STORE::key_type& key
)
{
    if (data_.size() > 1)
    {
        bool erased = false;

        for (size_t i = 0; i < data_.size(); i++)
        {
            if (data_[i]->erase(key))
            {
                erased = true;
            }
        }

        return erased;
    }

    return elements_->erase(key);
}
/*
template <class STORE>
void
MLCube<STORE>::
attach(
    core::Observer<typename STORE::value_type>* obs
)
{
    elements_->attach(obs);
}*/


template <class STORE>
core::AttributeStore<typename STORE::value_type>*
MLCube<STORE>::
attr(
) const
{
    return attr_.get();
}

/*
template <class STORE>
STORE*
MLCube<STORE>::
operator[](
    const std::vector<size_t>& index
)
{
    return data_[index].get();
}


template <class STORE>
STORE*
MLCube<STORE>::
operator[](
    const std::vector<std::string>& index
)
{
    return data_[index].get();
}

template <class STORE>
const STORE*
MLCube<STORE>::
operator[](
    const std::vector<size_t>& index
) const
{
    return data_[index].get();
}


template <class STORE>
const STORE*
MLCube<STORE>::
operator[](
    const std::vector<std::string>& index
) const
{
    return data_[index].get();
}
*/

template <class STORE>
STORE*
MLCube<STORE>::
cell(
    const std::vector<size_t>& index
)
{
    size_t idx = pos(index);
    return data_[idx].get();
}


template <class STORE>
STORE*
MLCube<STORE>::
cell(
    const std::vector<std::string>& index
)
{
    size_t idx = pos(index);
    return data_[idx].get();
}

template <class STORE>
const STORE*
MLCube<STORE>::
cell(
    const std::vector<size_t>& index
) const
{
    size_t idx = pos(index);
    return data_[idx].get();
}


template <class STORE>
const STORE*
MLCube<STORE>::
cell(
    const std::vector<std::string>& index
) const
{
    size_t idx = pos(index);
    return data_[idx].get();
}

template <class STORE>
size_t
MLCube<STORE>::
num_cells(
) const
{
    return data_.size();
}

/*
template <class STORE>
void
MLCube<STORE>::
init(
     )
{
    for (auto idx: sel::IndexIterator(size()))
    {
        init(idx);
    }
}


template <class STORE>
STORE*
MLCube<STORE>::
init(
     const std::vector<size_t>& index
     )
{
    if (at(index) != nullptr)
    {
        throw core::OperationNotSupportedException("cell already initialized");
    }
    auto cell = std::make_shared<STORE>();
    insert(cell, index);
    return cell.get();
}
*/

/* index of a dimension
template <class STORE>
size_t
MLCube<STORE>::
index_of(
    const std::string& dim
) const
{
    return data_.index_of(dim);
}

index of a member given a dimension
template <class STORE>
size_t
MLCube<STORE>::
index_of(
    const std::string& dim,
    const std::string& member
) const
{
    return data_.index_of(dim, member);
}


template <class STORE>
void
MLCube<STORE>::
insert(
       STORE* value,
       const std::vector<size_t>& index
       )
{
    value->attach(elements_.get());
    super::insert(value, index);
}

template <class STORE>
void
MLCube<STORE>::
insert(
       STORE* value,
       const std::vector<std::string>& index
       )
{
    value->attach(elements_.get());
    super::insert(value, index);
}

 */

template <class STORE>
STORE*
MLCube<STORE>::
init(
    const std::shared_ptr<STORE>& store
)
{
    elements_ = store;
    elements_->attach(attr_.get());
    return elements_.get();
}


template <class STORE>
STORE*
MLCube<STORE>::
init(
    size_t pos,
    const std::shared_ptr<STORE>& store
)
{
    if (data_[pos] != nullptr)
    {
        throw core::OperationNotSupportedException("cell already initialized");
    }

    for (auto el: *store)
    {
        union_obs->notify_add(el);
    }

    data_[pos] = store;
    return store.get();
}

template <class STORE>
STORE*
MLCube<STORE>::
init(
    const std::vector<size_t>& index,
    const std::shared_ptr<STORE>& store
)
{
    return init(pos(index), store);
}

/*
template <class STORE>
STORE*
MLCube<STORE>::
init(
    const std::vector<size_t>& index
)
{
    return init(pos(index));
}
*/

template <class STORE>
core::UnionObserver<STORE, const typename STORE::value_type>*
MLCube<STORE>::
register_obs(
)
{
    union_obs = std::make_unique<core::UnionObserver<STORE, const typename STORE::value_type>>(elements_.get());
    return union_obs.get();
}

template <class STORE>
void
MLCube<STORE>::
register_obs(
    size_t pos
)
{
    data_[pos]->attach(union_obs.get());
}

template <class STORE>
void
MLCube<STORE>::
register_obs(
    const std::vector<size_t>& index
)
{
    register_obs(pos(index));
}

/*
template <class STORE>
STORE*
MLCube<STORE>::
init(
    const std::vector<std::string>& index,
    const std::shared_ptr<STORE>& store
)
{
    // @todo reuse the index-based version of this instead of replicating the code
    if (at(index) != nullptr)
    {
        throw core::OperationNotSupportedException("cell already initialized");
    }

    //value->attach(elements_->get());
    for (auto el: *store)
    {
        union_obs->notify_add(el);
    }

    store->attach(union_obs.get());
    data_[index] = store;
    return store.get();
}


template <typename STORE>
template <typename Iterator>
void
MLCube<STORE>::
resize(
const std::string& dimension,
const std::string& new_member,
Iterator begin,
Iterator end
)
{
size_t dim_idx = index_of(dimension);

std::vector<std::vector<std::string>> new_members;

for (auto d: dim())
{
    new_members.push_back(std::vector<std::string>());

    for (auto m: members(d))
    {
        new_members.back().push_back(m);
    }
}

new_members.at(dim_idx).push_back(new_member);
size_t member_idx = new_members.at(dim_idx).size()-1;

auto new_size = size();
new_size.at(dim_idx)++;

uu::core::sel::IndexIterator idx(new_size);

std::vector<std::shared_ptr<STORE>> cells;

auto it = begin;

for (auto index: idx)
{
    if (index.at(dim_idx) == member_idx)
    {
        if (it==end)
        {
            throw core::OutOfBoundsException("too few new containers");
        }

        cells.push_back(*it);
        ++it;
    }

    else
    {
        auto container = at(index)->shared_from_this();
        cells.push_back(container);
    }
}

for (auto cont = begin; cont != end; ++cont)
{
    (*cont)->attach(union_obs.get());

    // Add all existing objects in the containers to the elements
    for (auto obj: *(*cont))
    {
        elements_->add(obj);
    }
}

data_ =
    NCube<std::shared_ptr<STORE>>(dim(), new_members, cells.begin(), cells.end());
}
*/

// SF is a pointer to an object with a function get_store(), returning a new store
template <class STORE>
template <class SF, class D>
void
MLCube<STORE>::
add_dimension(
    const std::string& name,
    const std::vector<std::string>& members,
    const SF& store_factory,
    const D& discretize
)
{

    // @todo see if it can be simplified

    if (members.size() == 0)
    {
        throw core::OperationNotSupportedException("new dimension must have at least one member");
    }

    core::IndexIterator old_indexes(size_);

    size_.push_back(members.size());
    dim_.push_back(name);
    dim_idx_[name] = 0;
    members_.resize(dim_.size());
    members_idx_.resize(dim_.size());

    for (auto m_name: members)
    {
        members_.back().push_back(m_name);
        members_idx_.back()[m_name] = members_.back().size() - 1;
    }

    if (data_.size() == 0 && members.size() == 1)
    {
        data_ = std::vector<std::shared_ptr<STORE>>(1);
        data_[0] = elements_;
        // If no discretization function is used, all the elements are preserved
        std::set<const typename STORE::value_type*> to_erase;

        for (auto el: *elements_)
        {
            std::vector<bool> to_add = discretize(el);

            if (!to_add[0]) // warning - not checking size
            {
                to_erase.insert(el);
            }

            for (auto v: to_erase)
            {
                elements_->erase(v);
            }
        }
    }

    else if (data_.size() == 0 && members.size() > 1)
    {
        auto old_elements_ = elements_;

        size_t new_num_cells = members.size();
        data_ = std::vector<std::shared_ptr<STORE>>(new_num_cells);

        init(store_factory->get_store()); // initialize elements_
        union_obs = std::make_unique<core::UnionObserver<STORE, const typename STORE::value_type>>(elements_.get());

        for (size_t p = 0; p < data_.size(); p++)
        {
            init(p, store_factory->get_store());
            register_obs(p);
        }

        // Copy elements from each cell in the previous cube to the new corresponding cells
        std::set<const typename STORE::value_type*> to_erase;

        for (auto el: *old_elements_)
        {
            std::vector<bool> to_add = discretize(el);

            for (size_t i = 0; i < to_add.size(); i++)
            {
                if (to_add[i])
                {
                    data_[i]->add(el);
                }
            }
        }

        for (auto el: *old_elements_)
        {
            if (!elements_->contains(el))
            {
                attr_->notify_erase(el);
            }
        }

    }

    else
    {
        // Temporarily saving current data

        auto old_elements_ = elements_;
        std::vector<std::shared_ptr<STORE>> old_data_ = data_;

        // Create new data

        size_t new_num_cells = data_.size() * members.size();
        data_ = std::vector<std::shared_ptr<STORE>>(new_num_cells);

        init(store_factory->get_store()); // initialize elements_
        union_obs = std::make_unique<core::UnionObserver<STORE, const typename STORE::value_type>>(elements_.get());

        for (size_t p = 0; p < data_.size(); p++)
        {
            init(p, store_factory->get_store());
            register_obs(p);
        }

        // Copy elements from each cell in the previous cube to the new corresponding cells

        size_t old_pos = 0;

        for (auto index: old_indexes)
        {
            for (auto el: *old_data_[old_pos++])
            {
                std::vector<bool> to_add = discretize(el);

                for (size_t i = 0; i < to_add.size(); i++)
                {
                    if (to_add[i])
                    {
                        index.push_back(i);
                        data_[pos(index)]->add(el);
                        index.pop_back();
                    }
                }

                for (auto el: *old_elements_)
                {
                    if (!elements_->contains(el))
                    {
                        attr_->notify_erase(el);
                    }
                }
            }
        }

    }

}

template <class STORE>
template <class SF>
void
MLCube<STORE>::
add_member(
    const std::string& dim_name,
    const std::string& memb_name,
    const SF& store_factory
    //bool (*copy)(typename STORE::value_type*)
)
{

    // Temporarily saving current data

    std::vector<std::shared_ptr<STORE>> old_data = data_;
    auto old_size = size_;


    auto dim = dim_idx_.find(dim_name);

    if (dim == dim_idx_.end())
    {
        throw core::ElementNotFoundException("dimension " + dim_name);
    }

    size_t d_idx = dim->second;

    size_[d_idx] += 1;
    members_[d_idx].push_back(memb_name);
    members_idx_[d_idx][memb_name] = members_[d_idx].size() - 1;


    if (data_.size() == 1)
    {
        data_ = std::vector<std::shared_ptr<STORE>>(2);
        init(store_factory->get_store()); // initialize elements_
        union_obs = std::make_unique<core::UnionObserver<STORE, const typename STORE::value_type>>(elements_.get());

        init(0, old_data[0]);
        register_obs(0);
        init(1, store_factory->get_store());
        register_obs(1);
    }

    else
    {
        // Create new data

        size_t new_num_cells = data_.size() / (size_[d_idx]-1) * (size_[d_idx]);
        data_ = std::vector<std::shared_ptr<STORE>>(new_num_cells);

        // Copy cells and elements

        core::IndexIterator old_indexes(old_size);

        for (auto index: old_indexes)
        {
            size_t pos_old_data = pos(index, old_size);
            init(index, old_data[pos_old_data]);
            register_obs(index);

            // @todo make more efficient

            std::vector<size_t> index_new_cell = index;
            index_new_cell[d_idx] = size_[d_idx] - 1;

            auto new_cell = cell(index_new_cell);

            if (!new_cell)
            {
                new_cell = init(index_new_cell, store_factory->get_store());
                register_obs(index_new_cell);
            }

            //
            //        if (!copy) continue;
            //
            //        for (auto el: *old_data[pos_old_data])
            //        {
            //            if (copy(el))
            //            {
            //                new_cell->add(el);
            //            }
            //        }
        }
    }



}


/*
template <class STORE>
void
MLCube<STORE>::
reset(
)
{
    elements_ = std::make_unique<STORE>();
    union_obs = std::make_unique<core::UnionObserver<STORE, typename STORE::value_type>>(elements_.get());

    for (size_t i = 0; i < data_.size(); i++)
    {
        data_[i] = std::make_shared<STORE>();
        data_[i]->attach(union_obs.get());
    }
}
*/
/*
template <class STORE>
void
MLCube<STORE>::
init(
    size_t pos
)
{
    data_[pos] = std::make_shared<STORE>();
    data_[pos]->attach(union_obs.get());
}*/


template <class STORE>
size_t
MLCube<STORE>::
pos(
    const std::vector<size_t>& index,
    const std::vector<size_t>& dimensions
) const
{
    if (index.size() != dimensions.size())
    {
        std::string err = "cell index must have the same number of elements as the order";
        throw core::OutOfBoundsException(err);
    }

    size_t idx = 0;
    size_t offset = 1;

    for (size_t i = 0; i < dimensions.size(); i++)
    {
        if (index[i] >= dimensions[i])
        {
            std::string err = "value in cell index (" +
                              std::to_string(index[i]) + ") higher than number of members (" +
                              std::to_string(dimensions[i]) + ")";
            throw core::OutOfBoundsException(err);
        }

        idx += index[i] * offset;
        offset *= dimensions[i];
    }

    return idx;
}


template <class STORE>
size_t
MLCube<STORE>::
pos(
    const std::vector<size_t>& index
) const
{
    return pos(index, size_);
}


template <class STORE>
size_t
MLCube<STORE>::
pos(
    const std::vector<std::string>& members
) const
{
    return pos(index_of(members));
}


template <class STORE>
std::vector<size_t>
MLCube<STORE>::
index_of(
    const std::vector<std::string>& members
) const
{

    if (dim_.size() != members.size())
    {
        throw core::WrongParameterException("parameter must have the same size as the cube order");
    }

    std::vector<size_t> res;

    for (size_t i = 0; i < members.size(); i++)
    {
        auto member = members[i];
        auto f = members_idx_[i].find(member);

        if (f != members_idx_[i].end())
        {
            res.push_back(f->second);
        }

        else
        {
            throw core::ElementNotFoundException("member " + member);
        }
    }

    return res;
}



}
}

