#include "olap/VCube.hpp"

#include "core/exceptions/ElementNotFoundException.hpp"

namespace uu {
namespace net {

VCube::
VCube(
    const std::string& name
) : name(name)
{
    cube_ = std::make_unique<MLCube<VertexStore>>(std::make_unique<VertexStore>());
}

/*
VCube::
VCube(
const std::string& cube_name,
    const std::vector<std::string>& dimensions,
    const std::vector<std::vector<std::string>>& members
)
: super(cube_name, std::make_unique<VertexStore>(), dimensions, members)
{
}*/


size_t
VCube::
size(
) const
{
    return cube_->size();
}


size_t
VCube::
order(
) const
{
    return cube_->order();
}


std::vector<size_t>
VCube::
dsize(
) const
{
    return cube_->dsize();
}


const std::vector<std::string>&
VCube::
dimensions(
) const
{
    return cube_->dimensions();
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


const std::vector<std::string>&
VCube::
members(
    size_t dim_idx
) const
{
    return cube_->members(dim_idx);
}


typename VertexStore::iterator
VCube::
begin(
) const
{
    return cube_->begin();
}


typename VertexStore::iterator
VCube::
end(
) const
{
    return cube_->end();
}


const Vertex*
VCube::
add(
    const std::shared_ptr<const Vertex>& v
)
{
    return cube_->add(v);
}


const Vertex*
VCube::
add(
    const Vertex* v
)
{
    return cube_->add(v);
}


const Vertex*
VCube::
add(
    const typename VertexStore::key_type& key
)
{
    return cube_->add(key);
}


bool
VCube::
contains(
    const Vertex* v
) const
{
    return cube_->contains(v);
}


bool
VCube::
contains(
    const typename VertexStore::key_type& key
) const
{
    return cube_->contains(key);
}



const Vertex*
VCube::
get(
    const typename VertexStore::key_type& key
) const
{
    return cube_->get(key);
}


const Vertex*
VCube::
at(
    size_t pos
) const
{
    return cube_->at(pos);
}


const Vertex*
VCube::
get_at_random(
) const
{
    return cube_->get_at_random();
}


int
VCube::
index_of(
    const Vertex* v
) const
{
    return cube_->index_of(v);
}


bool
VCube::
erase(
    const Vertex * obj
)
{
    return cube_->erase(obj);
}


bool
VCube::
erase(
    const std::string& key
)
{
    return cube_->erase(key);
}

core::AttributeStore<const Vertex>*
VCube::
attr(
) const
{
    return cube_->attr();
}


void
VCube::
add_dimension(
    const std::string& name,
    const std::vector<std::string>& members,
    std::vector<bool> (*discretize)(const Vertex*)
)
{
    return cube_->add_dimension(name, members, this, discretize);
}


void
VCube::
add_member(
    const std::string& name,
    const std::string& member//,
    //bool (*copy)(const Vertex*) = nullptr
)
{
    return cube_->add_member(name, member, this);
}


VertexStore*
VCube::
cell(
    const std::vector<size_t>& index
)
{
    return cube_->cell(index);
}


const VertexStore*
VCube::
cell(
    const std::vector<size_t>& index
) const
{
    return cube_->cell(index);
}


VertexStore*
VCube::
cell(
    const std::vector<std::string>& index
)
{
    return cube_->cell(index);
}


const VertexStore*
VCube::
cell(
    const std::vector<std::string>& index
) const
{
    return cube_->cell(index);
}


size_t
VCube::
num_cells(
) const
{
    return cube_->num_cells();
}


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
    cube_->elements_->attach(obs);
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

std::unique_ptr<VCube>
VCube::
skeleton(
    const std::string& name,
    const std::vector<std::string>& dimensions,
    const std::vector<std::vector<std::string>>& members
) const
{
    auto res = std::make_unique<VCube>(name);
    res->cube_ = std::make_unique<MLCube<VertexStore>>(dimensions, members);
    return res;
}


VertexStore*
VCube::
init(
)
{
    return cube_->init(std::make_shared<VertexStore>());
}

 VertexStore*
 VCube::
 init(
     const std::shared_ptr<VertexStore>& store
 )
 {
     return cube_->init(store);
 }
 
 VertexStore*
 VCube::
 init(
     const std::vector<size_t>& index,
     const std::shared_ptr<VertexStore>& store
 )
 {
     return cube_->init(index, store);
 }

 VertexStore*
 VCube::
 init(
     size_t pos,
     const std::shared_ptr<VertexStore>& store
 )
 {
     return cube_->init(pos, store);
 }
 
 VertexStore*
 VCube::
 init(
      const std::vector<size_t>& index
 )
 {
     return cube_->init(index, get_store());
 }
 
 VertexStore*
 VCube::
 init(
     size_t pos
 )
 {
     return cube_->init(pos, get_store());
 }
 
     void
     VCube::
     register_obs(
     const std::vector<size_t>& index
     )
     {
         cube_->register_obs(index);
     }
 
 void
 VCube::
     register_obs(
         size_t pos
     )
     {
         cube_->register_obs(pos);
     }
 

std::shared_ptr<VertexStore>
VCube::
get_store(
          ) const
{
    return std::make_shared<VertexStore>();
}

}
}

