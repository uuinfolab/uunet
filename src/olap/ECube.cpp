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

) : super(name, std::make_unique<EStore>(cube1, cube2, dir, loops)), cube1_(cube1), cube2_(cube2), dir_(dir), loops_(loops)
{
    //name_ = "e-cube"; // @todo is name necessary?

    //dir = dir;

    /*std::vector<std::shared_ptr<MDSimpleEdgeStore>> elements;
    size_t cube_size = 1;

    for (auto dim: members)
    {
        cube_size *= dim.size();
    }

    for (size_t i = 0; i < cube_size; i++)
    {
        elements.push_back(std::make_shared<MDSimpleEdgeStore>(cube1_, cube2_, dir));
    }*/

    //auto elements = std::make_unique<MDSimpleEdgeStore>(cube1_, cube2_, dir);
    //cube_ = std::make_unique<MLCube<MDSimpleEdgeStore>>(std::move(elements), dimensions, members);
    //, elements.begin(), elements.end());
    // register an observer to propagate the removal of vertices to the edge store
    auto obs1 = std::make_unique<VCubeObserver<ECube>>(cube1_, this);
    cube1_->attach(obs1.get());
    register_observer(std::move(obs1));
    
    auto obs2 = std::make_unique<VCubeObserver<ECube>>(cube2_, this);
    cube2_->attach(obs2.get());
    register_observer(std::move(obs2));
    
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
    return elements_->add(vertex1, cube1, vertex2, cube2);
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
        
    return elements_->add(vertex1, cube1_, vertex2, cube2_);
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



const
GenericObjectList<Vertex>*
ECube::
neighbors(
    const Vertex* vertex,
    const VCube* cube,
    EdgeMode mode
) const
{
    return elements_->neighbors(vertex, cube, mode);
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
                                          return elements_->incident(vertex, cube, mode);
                                      }



void
ECube::
attach(
    core::Observer<const MLEdge2>* obs
)
{
    elements_->attach(obs);
}

MDSimpleEdgeStore*
ECube::
init(
    size_t pos
)
{
    return init(pos, std::make_shared<EStore>(cube1_, cube2_, dir_, loops_));
}

void
ECube::
init(
)
{
    elements_ = std::make_shared<EStore>(cube1_, cube2_, dir_, loops_);
}

void
ECube::
reset(
)
{
    elements_ = std::make_unique<EStore>(cube1_, cube2_, dir_, loops_);
    union_obs = std::make_unique<core::UnionObserver<EStore, typename EStore::value_type>>(elements_.get());
    
    for (size_t i = 0; i < data_.size(); i++)
    {
        data_[i] = std::make_shared<EStore>(cube1_, cube2_, dir_, loops_);
        data_[i]->attach(union_obs.get());
    }
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
        elements_->erase(vcube, vertex);
    }
    else
    {
        for (size_t i = 0; i < data_.size(); i++)
        {
            data_[i]->erase(vcube, vertex);
        }
    }
}

}
}

