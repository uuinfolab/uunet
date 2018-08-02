/**

 */

#ifndef UU_MNET_DATASTRUCTURES_VERTEXOVERLAPPINGLAYERSTORE_H_
#define UU_MNET_DATASTRUCTURES_VERTEXOVERLAPPINGLAYERSTORE_H_

#include <unordered_set>
#include "core/attributes.h"
#include "core/datastructures.h"
#include "core/datastructures/containers/LabeledUniquePtrSortedRandomSet.h"
#include "net/datastructures.h"
#include "mnet/datastructures/MultiplexNetwork.h"

namespace uu {
namespace net {

template <typename Graph, typename A>
class VertexOverlappingLayerStore :
    public core::Attributed<A>,
    public core::LabeledUniquePtrSortedRandomSet<Graph>,
    public core::Subject<const Vertex>
{


  private:

    typedef core::LabeledUniquePtrSortedRandomSet<Graph> super;

  public:

    VertexOverlappingLayerStore(
        std::unique_ptr<A> attr
    );

    //using VertexManager::erase;
    void
    notify_erase(const std::shared_ptr<Vertex>& vertex);

    using super::size;

    std::string
    summary(
    ) const
    {
        size_t s = size();
        return std::to_string(s) + (s==1?" layer":" layers");
    }

  protected:

    //std::shared_ptr<LayerList<Graph> > layers_;

    // Indexes to components (Component IDX):
    //std::unordered_map<std::string, std::shared_ptr<Graph > > layer_by_name;

    //std::unordered_map<NodeId, std::unordered_map<NodeId, std::shared_ptr<Edge>> > edge_by_nodes;


};

template <typename Graph, typename A>
VertexOverlappingLayerStore<Graph,A>::
VertexOverlappingLayerStore(
    std::unique_ptr<A> attr
)     :
    core::Attributed<A>(std::move(attr))
{
    //vertices_ = std::make_shared<VertexList>();

    //attributes_ = A::create();
    //auto obs = static_cast<std::shared_ptr<core::Observer<Vertex> > >(attributes_);

    //attach(&this->attr());
}

} // namespace net
} // namespace uu

#endif

