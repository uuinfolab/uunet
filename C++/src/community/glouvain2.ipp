#include <unordered_map>
#include <vector>
#include "net/community/louvain_utils.hpp"
#include "community/louvain.hpp"

namespace uu {
namespace net {

    template <typename M>
    std::unique_ptr<CommunityStructure<VertexLayerCommunity<const typename M::layer_type>>>
    glouvain2(
              const M* g,
              double omega
              )
{

    auto multilayer_metanetwork = convert(g, omega);
    
    auto weighted = std::move(multilayer_metanetwork.first);
    auto mapping = multilayer_metanetwork.second;

    std::vector<std::unique_ptr<MetaNetwork>> passes;
    
    auto meta = pass(weighted.get());
    
    while (meta)
    {
        passes.push_back(std::move(meta));
        auto w = passes.back()->get();
        meta = pass(w);
    }
    
    auto c = communities(passes);

    auto communities = std::make_unique<CommunityStructure<VertexLayerCommunity<const typename M::layer_type>>>();
    
    for (auto meta_community: *c)
    {
        auto community = std::make_unique<VertexLayerCommunity<const typename M::layer_type>>();
        
        for (auto meta_vertex: *meta_community)
        {
            community->add(mapping.at(meta_vertex));
        }
        
        communities->add(std::move(community));
    }


    return communities;
}

}
}
