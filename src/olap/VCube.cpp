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
    const std::string& key
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
    const std::vector<std::string>& members
)
{
    auto tot = UniformDiscretization<Vertex>(members.size());
    return cube_->add_dimension(name, members, this, tot);
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
    return cube_->init(get_store());
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
 
core::UnionObserver<VertexStore, const Vertex>*
VCube::
register_obs(
)
{
    return cube_->register_obs();
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

