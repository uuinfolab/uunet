#include "olap/ECube.hpp"

#include "core/exceptions/ElementNotFoundException.hpp"

namespace uu {
namespace net {

ECube::
ECube(
    //const std::string& name,
    const VCube* vc1,
    const VCube* vc2,
    EdgeDir dir

) : super(std::make_unique<EStore>(vc1, vc2, dir)), vc1(vc1), vc2(vc2), dir(dir)
{
    //name_ = "e-cube"; // @todo is name necessary?

    //dir = dir;

    /*std::vector<std::shared_ptr<MDSimpleEdgeStore<VCube>>> elements;
    size_t cube_size = 1;

    for (auto dim: members)
    {
        cube_size *= dim.size();
    }

    for (size_t i = 0; i < cube_size; i++)
    {
        elements.push_back(std::make_shared<MDSimpleEdgeStore<VCube>>(vc1, vc2, dir));
    }*/

    //auto elements = std::make_unique<MDSimpleEdgeStore<VCube>>(vc1, vc2, dir);
    //cube_ = std::make_unique<MLCube<MDSimpleEdgeStore<VCube>>>(std::move(elements), dimensions, members);
    //, elements.begin(), elements.end());
}

const MLEdge<Vertex,VCube> *
ECube::
add(
    const Vertex* vertex1,
    const VCube* layer1,
    const Vertex* vertex2,
    const VCube* layer2
)
{
    return elements_->add(vertex1, layer1, vertex2, layer2);
}

const MLEdge<Vertex,VCube> *
ECube::
add(
    const Vertex* vertex1,
    const Vertex* vertex2
)
{
    if (vc1 != vc2)
    {
        std::string err = "ending vertex cubes cannot be inferred and must be specified";
        throw core::OperationNotSupportedException(err);
    }
        
    return elements_->add(vertex1, vc1, vertex2, vc2);
}

const VCube*
ECube::
vcube1(
) const
{
    return vc1;
}


const VCube*
ECube::
vcube2(
) const
{
    return vc2;
}


std::string
ECube::
to_string(
) const
{
    return ""; // @TODO
}


bool
ECube::
is_directed(
) const
{
    return dir==EdgeDir::DIRECTED?true:false;
}


void
ECube::
attach(
    core::Observer<const MLEdge<Vertex, VCube>>* obs
)
{
    // @todo
    //cube_->elements()->attach(obs);
}

void
ECube::
reset(
)
{
    elements_ = std::make_unique<EStore>(vc1, vc2, dir);
    union_obs = std::make_unique<core::UnionObserver<EStore, typename EStore::value_type>>(elements_.get());
    
    for (size_t i = 0; i < data_.size(); i++)
    {
        data_[i] = std::make_shared<EStore>(vc1, vc2, dir);
        data_[i]->attach(union_obs.get());
    }
}

}
}

