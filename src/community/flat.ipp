#include <unordered_map>
#include <vector>
#include "community/louvain.hpp"
#include "operations/flatten.hpp"

namespace uu {
namespace net {

/**
 * Maps back the communities found in the flattened network into multi-layer communities in the original multi-layer instance.
 * @param fComs the communities of the flattened graph
 * @param mnet the input multi-layer network instance
 * @return the mapping as actor communities on the multi-layer instance
*/
template <typename M>
std::unique_ptr<CommunityStructure<M>>
map_back_to_ml(
               const uu::net::CommunityStructure<typename M::layer_type>* fComs,
               const M* mnet
)
{

    auto ml_communities = std::make_unique<uu::net::CommunityStructure<M>>();

   //for each community in the flattened network
   for (auto single_community: *fComs)
   {
       auto ml_community = std::make_unique<uu::net::Community<M>>();

       //for each node in the current flattened network community
       for (auto actor: *single_community)
       {
           for (auto layer: *mnet->layers())
           {
               if (layer->vertices()->contains(actor))
               {
                   auto vertex = uu::net::MLVertex<M>(actor, layer);
                   ml_community->add(vertex);
               }
           }
       }
       // add this community to the list of communities to be returned
       ml_communities->add(std::move(ml_community));
   }

   return ml_communities;
}


template <typename M>
std::unique_ptr<CommunityStructure<M>>
flat_nw(
    const M* net
)
{
    auto fnet = std::make_unique<Network>("tmp", EdgeDir::UNDIRECTED, true);
    flatten_unweighted(net->layers()->begin(), net->layers()->end(), fnet.get());
    auto single_layer_communities = uu::net::louvain(fnet.get());
    return map_back_to_ml(single_layer_communities.get(), net);
}

template <typename M>
std::unique_ptr<CommunityStructure<M>>
flat_ec(
    const M* net
)
{
    auto fnet = std::make_unique<WeightedNetwork>("tmp", EdgeDir::UNDIRECTED, true);
    flatten_weighted(net->layers()->begin(), net->layers()->end(), fnet.get());
    auto single_layer_communities = uu::net::louvain(fnet.get());
    return map_back_to_ml(single_layer_communities.get(), net);
}

}
}
