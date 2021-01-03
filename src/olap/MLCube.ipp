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
    std::unique_ptr<STORE> el
    //const std::vector<std::string>& dim,
    //const std::vector<std::vector<std::string>>& members
) //: data_(dim, members)
{
    elements_ = std::move(el);

    size_ = {};
    off_ = {};
    
    // union_obs = std::make_unique<core::UnionObserver<STORE, const typename STORE::value_type>>(elements_.get());

    // Element attributes
    attr_ = std::make_unique<core::AttributeStore<typename STORE::value_type>>();
    elements_->attach(attr_.get());
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
 dimensions(
 ) const
 {
     return size_;
 }


template <class STORE>
 const std::vector<std::string>&
 MLCube<STORE>::
 dimension_names(
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
typename STORE::iterator
MLCube<STORE>::
begin(
) const
{
    return elements_->begin();
}

template <class STORE>
typename STORE::iterator
MLCube<STORE>::
end(
) const
{
    return elements_->end();
}

template <class STORE>
typename STORE::value_type*
MLCube<STORE>::
add(
    std::shared_ptr<typename STORE::value_type> v
)
{
    if (order() > 0)
    {
        std::string err = "cube has order > 0, elements must be added to a cell";
        throw core::OperationNotSupportedException(err);
    }
    return elements_->add(v);
}


template <class STORE>
typename STORE::value_type*
MLCube<STORE>::
add(
    typename STORE::value_type* v
)
{
    if (order() > 0)
    {
        std::string err = "cube has order > 0, elements must be added to a cell";
        throw core::OperationNotSupportedException(err);
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
    if (order() > 0)
    {
        std::string err = "cube has order > 0, elements must be added to a cell";
        throw core::OperationNotSupportedException(err);
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
typename STORE::value_type*
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
    if (order() > 0)
    {
        std::string err = "cube has order > 0, elements must be erased from a cell";
        throw core::OperationNotSupportedException(err);
    }
    return elements_->erase(v);
}

template <class STORE>
void
MLCube<STORE>::
attach(
    core::Observer<typename STORE::value_type>* obs
)
{
    elements_->attach(obs);
}


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

/*
template <class STORE>
STORE*
MLCube<STORE>::
init(
    const std::vector<size_t>& index,
    const std::shared_ptr<STORE>& store
)
{
    if (at(index) != nullptr)
    {
        throw core::OperationNotSupportedException("cell already initialized");
    }

    for (auto el: *store)
    {
        union_obs->notify_add(el);
    }

    store->attach(union_obs.get());
    data_[index] = store;
    return store.get();
}

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


template <class STORE>
void
MLCube<STORE>::
extend(
    const std::string& name,
    const std::vector<std::string>& members,
    std::vector<bool> (*discretize)(typename STORE::value_type*)
)
{

    if (order() == 0)
    {
        // Temporarily saving current data
        
        std::unique_ptr<STORE> old_data_ = std::move(elements_);
        
        // Create new data
        
        size_t new_num_cells = members.size();
        data_ = std::vector<std::shared_ptr<STORE>>(new_num_cells);
        
        reset();
        
        off_.push_back(1);
        size_.push_back(members.size());
        dim_.push_back(name);
        dim_idx_[name] = 0;
        members_.resize(members_.size() + 1);
        members_idx_.resize(members_.size());
        for (auto m_name: members)
        {
            members_.back().push_back(m_name);
            members_idx_.back()[m_name] = members_.back().size() - 1;
        }
        
        // Copy elements from each cell in the previous cube to the new corresponding cells
        
        for (auto el: *old_data_)
        {
            std::vector<bool> new_cells = discretize(el);
            
            for (size_t i = 0; i < new_cells.size(); i++)
            {
                if (new_cells[i])
                {
                    std::vector<size_t> index = {i};
                    data_[pos(index)]->add(el);
                }
            }
        }
    }
    else
    {
        // Temporarily saving current data
        
        std::vector<std::shared_ptr<STORE>> old_data_ = data_;
        core::IndexIterator old_indexes(size_);
        
        // Create new data
        
        size_t new_num_cells = data_.size() * members.size();
        data_ = std::vector<std::shared_ptr<STORE>>(new_num_cells);
        
        reset();
        
        off_.push_back(off_.back() * size_.back());
        size_.push_back(members.size());
        dim_.push_back(name);
        dim_idx_[name] = dim_.size() - 1;
        members_.resize(members_.size() + 1);
        members_idx_.resize(members_.size());
        for (auto m_name: members)
        {
            members_.back().push_back(m_name);
            members_idx_.back()[m_name] = members_.back().size() - 1;
        }
        
        // Copy elements from each cell in the previous cube to the new corresponding cells
        
        size_t old_pos = 0;
        for (auto index: old_indexes)
        {
            for (auto el: *old_data_[old_pos++])
            {
                std::vector<bool> new_cells = discretize(el);
                
                for (size_t i = 0; i < new_cells.size(); i++)
                {
                    if (new_cells[i])
                    {
                        index.push_back(i);
                        data_[pos(index)]->add(el);
                        index.pop_back();
                    }
                }
            }
        }

    }
    
}

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

template <class STORE>
void
MLCube<STORE>::
init(
    size_t pos
)
{
    data_[pos] = std::make_shared<STORE>();
    data_[pos]->attach(union_obs.get());
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
size_t
MLCube<STORE>::
pos(
    const std::vector<size_t>& index
) const
{
    if (index.size() != order())
    {
        std::string err = "cell index must have the same number of elements as the order of the cube";
        throw core::OutOfBoundsException(err);
    }
    
    size_t idx = 0;
    for (size_t i = 0; i < size_.size(); i++)
    {
        if (index[i] >= size_[i])
        {
            std::string err = "value in cell index (" +
                std::to_string(index[i]) + ") higher than number of members (" +
                std::to_string(size_[i]) + ")";
            throw core::OutOfBoundsException(err);
        }
        idx += index[i] * off_[i];
    }
    return idx;
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

