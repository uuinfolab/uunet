#include "olap/VCube.hpp"

#include "core/exceptions/ElementNotFoundException.hpp"

namespace uu {
namespace net {

VCube::
VCube(
    const std::string& name
    //const std::vector<std::string>& dimensions,
    //const std::vector<std::vector<std::string>>& members
) : super(name, std::make_unique<VertexStore>())
{
    //name_ = "v-cube"; // @todo is name needed?

    /*std::vector<std::shared_ptr<VertexStore>> elements;
    size_t cube_size = 1;

    for (auto dim: members)
    {
        cube_size *= dim.size();
    }

    for (size_t i = 0; i < cube_size; i++)
    {
        elements.push_back(std::make_shared<VertexStore>());
    }*/

    //auto elements = std::make_unique<VertexStore>();
    //cube_ = std::make_unique<MLCube<VertexStore>>(std::move(elements), dimensions, members);
}

VCube::
VCube(
const std::string& cube_name,
    const std::vector<std::string>& dimensions,
    const std::vector<std::vector<std::string>>& members
)
: super(cube_name, std::make_unique<VertexStore>(), dimensions, members)
{
}

/*
std::unique_ptr<VCube>
VCube::
model(
    const std::vector<std::string>& dim,
    const std::vector<std::vector<std::string>>& members
) const
{
    return std::make_unique<VCube>(dim, members);
}

template <typename Iterator>
VCube::
VCube(
    const std::string& name,
    const std::vector<std::string>& dimensions,
    const std::vector<std::vector<std::string>>& members,
    Iterator begin,
    Iterator end
)
{
    // @todo check Iterator type

    name_ = name;

    //cube_ = std::make_unique<core::CCube<VertexStore>>(dim, members, begin, end);

    std::vector<std::shared_ptr<VertexStore>> elements;
    size_t cube_size = 1;

    for (auto dim: members)
    {
        cube_size *= dim.size();
    }

    for (size_t i = 0; i < cube_size; i++)
    {
        elements.push_back(std::make_shared<VertexStore>());
    }

    cube_ = std::make_unique<core::CCube<VertexStore>>(dimensions, members, begin, end);
}


const VertexStore*
VCube::
vertices(
) const
{
    return cube_->elements();
}


void
VCube::
add_dim(
    const std::string& name,
    const std::vector<std::string>& members
)
{
    auto iter = core::IndexIterator(size());
    
    cube_->add_dim(name, members);
    
    if (cube_->order() == 1)
    {
        std::vector<size_t> index = {0};
        for (size_t m = 0; m < members.size(); m++)
        {
            auto new_store = std::make_shared<VertexStore>();
            index.back() = m;
            cube_->init(index, new_store);
        }
    }
    else for (auto index: iter)
    {
        std::vector<size_t> ext_index = index;
        ext_index.resize(ext_index.size() + 1);
        for (size_t m = 0; m < members.size(); m++)
        {
            auto new_store = std::make_shared<VertexStore>();
            ext_index.back() = m;
            cube_->init(ext_index, new_store);
        }
    }
}

VertexStore*
VCube::
operator[](
    const std::vector<size_t>& index
)
{
    return (*cube_)[index];
}


VertexStore*
VCube::
operator[](
    const std::vector<std::string>& index
)
{
    return (*cube_)[index];
}

const VertexStore*
VCube::
operator[](
    const std::vector<size_t>& index
) const
{
    return (*cube_)[index];
}

const VertexStore*
VCube::
operator[](
    const std::vector<std::string>& index
) const
{
    return (*cube_)[index];
}

VertexStore*
VCube::
at(
    const std::vector<size_t>& index
)
{
    return cube_->at(index);
}


VertexStore*
VCube::
at(
    const std::vector<std::string>& index
)
{
    return cube_->at(index);
}


const VertexStore*
VCube::
at(
    const std::vector<size_t>& index
) const
{
    return cube_->at(index);
}

const VertexStore*
VCube::
at(
    const std::vector<std::string>& index
) const
{
    return cube_->at(index);
}


VertexStore::iterator
VCube::
begin(
) const
{
return cube_->elements()->begin();
}

VertexStore::iterator
VCube::
end(
) const
{
return cube_->elements()->end();
}


std::vector<size_t>
VCube::
size(
) const
{
    return cube_->size();
}
 
 * Creates a new container in the input cell.
 * @throw OperationNotSupportedException
 
void
VCube::
init(
)
{
    auto iter = core::IndexIterator(size());

    for (auto index: iter)
    {
        auto new_store = std::make_shared<VertexStore>();
        cube_->init(index, new_store);
    }
}
 
 * Creates a new container in the input cell.
 * @throw OutOfBoundsException if the index is outside the bounds of the cube
 * @throw OperationNotSupportedException

 
VertexStore*
VCube::
init(
    const std::vector<size_t>& index
)
{
    auto new_store = std::make_shared<VertexStore>();
    return cube_->init(index, new_store);
}


 * Creates a new container in the input cell.
 * @throw OutOfBoundsException if the index is outside the bounds of the cube
 * @throw OperationNotSupportedException

 
VertexStore*
VCube::
init(
    const std::vector<size_t>& index,
    std::shared_ptr<VertexStore> cell
)
{
    return cube_->init(index, cell);
}


bool
VCube::
contains(
const Vertex* v
) const
{
return cube_->elements()->contains(v);
}


const Vertex*
VCube::
get(
const std::string& key
) const
{
return cube_->elements()->get(key);
}

const Vertex*
VCube::
at(
size_t pos
) const
{
return cube_->elements()->at(pos);
}

const Vertex*
VCube::
get_at_random(
) const
{
return cube_->elements()->get_at_random();
}


int
VCube::
index_of(
const Vertex* v
) const
{
return cube_->elements()->index_of(v);
}
*/

/*
 
core::AttributeStore<Vertex>*
VCube::
attr(
)
{
    return cube_->attr();
}


const core::AttributeStore<Vertex>*
VCube::
attr(
) const
{
    return cube_->attr();
}


size_t
VCube::
order(
) const
{
    return cube_->order();
}


const std::vector<std::string>&
VCube::
dim(
) const
{
    return cube_->dim();
}

const std::vector<std::vector<std::string>>&
        VCube::
        members(
        ) const
{
    return cube_->members();
}

const std::vector<std::string>&
VCube::
members(
    const std::string& dim
) const
{
    return cube_->members(dim);
}

*/

std::string
VCube::
to_string(
) const
{
    return "V(" + name + ")";
}

void
VCube::
attach(
    core::Observer<const Vertex>* obs
)
{
    // @todo
    elements_->attach(obs);
}

/*
std::unique_ptr<VCube>
VCube::
create(
const std::string& name,
const std::vector<std::string>& dim,
const std::vector<std::vector<std::string>>& members
)
{
size_t num_entries = 1;

for (auto m: members)
{
    num_entries *= m.size();
}

std::vector<const std::shared_ptr<VertexStore>> stores;

for (size_t i = 0; i < num_entries; i++)
{
    stores.push_back(std::make_shared<VertexStore>());
}

return std::make_unique<VCube>(name, dim, members, stores.begin(), stores.end());
}
*/

/*
void
VCube::
resize(
    const std::string& dimension,
    const std::string& member
)
{
    std::vector<std::shared_ptr<VertexStore>> elements;
    size_t num_new_elements = 1;

    for (auto d: dim())
    {
        if (d == dimension)
        {
            continue;
        }

        num_new_elements *= members(d).size();
    }

    for (size_t i = 0; i < num_new_elements; i++)
    {
        elements.push_back(std::make_shared<VertexStore>());
    }

    cube_->resize(dimension, member, elements.begin(), elements.end());
}


std::unique_ptr<VCube>
VCube::
vslice(
    const std::string& name,
    const std::vector<std::vector<size_t>>& indexes
)
{

    // get dimensions and members of the new cube

    auto dim_names = dim();

    std::vector<std::vector<std::string>> member_names(dim_names.size());

    for (size_t i = 0; i < dim_names.size(); i++)
    {
        auto m = members(dim_names.at(i));

        for (auto idx: indexes[i])
        {
            member_names[i].push_back(m.at(idx));

        }
    }


    auto iter = core::sel::IndexIterator(indexes);

    std::vector<std::shared_ptr<VertexStore>> elements;

    for (auto idx: iter)
    {
        auto vs = at(idx);
        elements.push_back(vs->shared_from_this());
    }

    auto res = std::make_unique<VCube>(name, dim_names, member_names, elements.begin(), elements.end());

    return res;

}
*/

VertexStore*
VCube::
init(
    size_t pos
)
{
    return init(pos, std::make_shared<VertexStore>());
}

void
VCube::
init(
)
{
    elements_ = std::make_shared<VertexStore>();
}

void
VCube::
reset(
)
{
    elements_ = std::make_unique<VertexStore>();
    union_obs = std::make_unique<core::UnionObserver<VertexStore, typename VertexStore::value_type>>(elements_.get());
    
    for (size_t i = 0; i < data_.size(); i++)
    {
        data_[i] = std::make_shared<VertexStore>();
        data_[i]->attach(union_obs.get());
    }
}

}
}

