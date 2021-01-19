#include "olap/ECube.hpp"

#include "core/exceptions/ElementNotFoundException.hpp"
#include "networks/_impl/observers/VCubeObserver.hpp"

namespace uu {
namespace net {

ECube::
ECube(
    const std::string& name,
    VCube* cube1,
    VCube* cube2,
    EdgeDir dir,
    LoopMode loops

) : name(name), cube1_(cube1), cube2_(cube2), dir_(dir), loops_(loops)
{
    cube_ = std::make_unique<MLCube<MDSimpleEdgeStore>>( std::make_unique<EStore>(cube1, cube2, dir, loops));
    
    // register an observer to propagate the removal of vertices to the edge store
    auto obs1 = std::make_unique<VCubeObserver<ECube>>(cube1_, this);
    cube1_->attach(obs1.get());
    cube_->register_observer(std::move(obs1));
    
    auto obs2 = std::make_unique<VCubeObserver<ECube>>(cube2_, this);
    cube2_->attach(obs2.get());
    cube_->register_observer(std::move(obs2));
    
}


size_t
ECube::
size(
) const
{
    return cube_->size();
}


size_t
ECube::
order(
) const
{
    return cube_->order();
}


std::vector<size_t>
ECube::
dsize(
) const
{
    return cube_->dsize();
}


const std::vector<std::string>&
ECube::
dimensions(
) const
{
    return cube_->dimensions();
}


const std::vector<std::vector<std::string>>&
ECube::
members(
) const
{
    return cube_->members();
}


const std::vector<std::string>&
ECube::
members(
    const std::string& dim
) const
{
    return cube_->members(dim);
}


const std::vector<std::string>&
ECube::
members(
    size_t dim_idx
) const
{
    return cube_->members(dim_idx);
}


typename MDSimpleEdgeStore::iterator
ECube::
begin(
) const
{
    return cube_->begin();
}


typename MDSimpleEdgeStore::iterator
ECube::
end(
) const
{
    return cube_->end();
}


const MLEdge2 *
ECube::
add(
    const Vertex* vertex1,
    const VCube* cube1,
    const Vertex* vertex2,
    const VCube* cube2
)
{
    return cube_->elements_->add(vertex1, cube1, vertex2, cube2);
}


const MLEdge2 *
ECube::
add(
    const MLEdge2* e
)
{
    return cube_->elements_->add(e->v1, e->c1, e->v2, e->c2);
}


const MLEdge2 *
ECube::
add(
    const Vertex* vertex1,
    const Vertex* vertex2
)
{
    if (cube1_ != cube2_)
    {
        std::string err = "ending vertex cubes cannot be inferred and must be specified";
        throw core::OperationNotSupportedException(err);
    }
        
    return cube_->elements_->add(vertex1, cube1_, vertex2, cube2_);
}

const MLEdge2 *
ECube::
get(
    const Vertex* vertex1,
    const VCube* cube1,
    const Vertex* vertex2,
    const VCube* cube2
)
{
    return cube_->elements_->get(vertex1, cube1, vertex2, cube2);
}

const MLEdge2 *
ECube::
get(
    const Vertex* vertex1,
    const Vertex* vertex2
)
{
    if (cube1_ != cube2_)
    {
        std::string err = "ending vertex cubes cannot be inferred and must be specified";
        throw core::OperationNotSupportedException(err);
    }
        
    return cube_->elements_->get(vertex1, cube1_, vertex2, cube2_);
}

const VCube*
ECube::
vcube1(
) const
{
    return cube1_;
}


const VCube*
ECube::
vcube2(
) const
{
    return cube2_;
}

bool
ECube::
contains(
    const MLEdge2* e
) const
{
    return cube_->contains(e);
}


const MLEdge2*
ECube::
at(
    size_t pos
) const
{
    return cube_->at(pos);
}


const MLEdge2*
ECube::
get_at_random(
) const
{
    return cube_->get_at_random();
}


int
ECube::
index_of(
    const MLEdge2* e
) const
{
    return cube_->index_of(e);
}

core::AttributeStore<const MLEdge2>*
ECube::
attr(
) const
{
    return cube_->attr();
}


void
ECube::
add_dimension(
    const std::string& name,
    const std::vector<std::string>& members,
    std::vector<bool> (*discretize)(const MLEdge2*)
)
{
    return cube_->add_dimension(name, members, this, discretize);
}


void
ECube::
add_member(
    const std::string& name,
    const std::string& member//,
    //bool (*copy)(const Vertex*) = nullptr
)
{
    return cube_->add_member(name, member, this);
}


MDSimpleEdgeStore*
ECube::
cell(
    const std::vector<size_t>& index
)
{
    return cube_->cell(index);
}


const MDSimpleEdgeStore*
ECube::
cell(
    const std::vector<size_t>& index
) const
{
    return cube_->cell(index);
}


MDSimpleEdgeStore*
ECube::
cell(
    const std::vector<std::string>& index
)
{
    return cube_->cell(index);
}


const MDSimpleEdgeStore*
ECube::
cell(
    const std::vector<std::string>& index
) const
{
    return cube_->cell(index);
}


size_t
ECube::
num_cells(
) const
{
    return cube_->num_cells();
}


std::string
ECube::
to_string(
) const
{
    return "E(" + name + ")";
}


bool
ECube::
is_directed(
) const
{
    return dir_==EdgeDir::DIRECTED?true:false;
}


bool
ECube::
allows_loops(
) const
{
    return loops_==LoopMode::ALLOWED?true:false;
}


const
GenericObjectList<Vertex>*
ECube::
neighbors(
    const Vertex* vertex,
    const VCube* cube,
    EdgeMode mode
) const
{
    return cube_->elements_->neighbors(vertex, cube, mode);
}


const
GenericObjectList<Vertex>*
ECube::
neighbors(
    const Vertex* vertex,
    EdgeMode mode
) const
{
    if (cube1_ != cube2_)
    {
        std::string err = "ending vertex cubes cannot be inferred and must be specified";
        throw core::OperationNotSupportedException(err);
    }
    
    return cube_->elements_->neighbors(vertex, cube1_, mode);
}


const
GenericObjectList<MLEdge2>*
ECube::
incident(
      const Vertex* vertex,
      const VCube* cube,
      EdgeMode mode
) const
{
  return cube_->elements_->incident(vertex, cube, mode);
}


const
GenericObjectList<MLEdge2>*
ECube::
incident(
      const Vertex* vertex,
      EdgeMode mode
) const
{
    if (cube1_ != cube2_)
    {
        std::string err = "ending vertex cubes cannot be inferred and must be specified";
        throw core::OperationNotSupportedException(err);
    }
    
  return cube_->elements_->incident(vertex, cube1_, mode);
}

void
ECube::
attach(
    core::Observer<const MLEdge2>* obs
)
{
    cube_->elements_->attach(obs);
}


MDSimpleEdgeStore*
ECube::
init(
)
{
    return cube_->init(get_store());
}

 MDSimpleEdgeStore*
 ECube::
 init(
     const std::shared_ptr<MDSimpleEdgeStore>& store
 )
 {
     return cube_->init(store);
 }
 
 MDSimpleEdgeStore*
 ECube::
 init(
     const std::vector<size_t>& index,
     const std::shared_ptr<MDSimpleEdgeStore>& store
 )
 {
     return cube_->init(index, store);
 }

 MDSimpleEdgeStore*
 ECube::
 init(
     size_t pos,
     const std::shared_ptr<MDSimpleEdgeStore>& store
 )
 {
     return cube_->init(pos, store);
 }
 
 MDSimpleEdgeStore*
 ECube::
 init(
      const std::vector<size_t>& index
 )
 {
     return cube_->init(index, get_store());
 }
 
 MDSimpleEdgeStore*
 ECube::
 init(
     size_t pos
 )
 {
     return cube_->init(pos, get_store());
 }
 
     void
     ECube::
     register_obs(
     const std::vector<size_t>& index
     )
     {
         cube_->register_obs(index);
     }
 
 void
 ECube::
     register_obs(
         size_t pos
     )
     {
         cube_->register_obs(pos);
     }
 
std::shared_ptr<MDSimpleEdgeStore>
ECube::
get_store(
          ) const
{
    return std::make_shared<MDSimpleEdgeStore>(cube1_, cube2_, dir_, loops_);
}

void
ECube::
erase(
const VCube* vcube,
const Vertex* vertex
)
{
    if (order() == 0)
    {
        cube_->elements_->erase(vcube, vertex);
    }
    else
    {
        for (size_t i = 0; i < cube_->data_.size(); i++)
        {
            cube_->data_[i]->erase(vcube, vertex);
        }
    }
}

}
}

