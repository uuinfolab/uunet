namespace uu {
namespace net {


template <typename M>
std::unique_ptr<CommunityStructure<M>>
mimag_approx_mlcpm(
    const M* mnet,
    size_t k,
    size_t m,
    double gamma
)
{
    // Step 1: find max-cliques
    auto cliques = mimag_approx(mnet,k,m,gamma);

    if (cliques.size()==0)
    {
        return std::make_unique<CommunityStructure<M>>();
    }

    // Step 2: bluid adjacency graph
    auto adjacency = build_max_adjacency_graph(cliques,k,m);

    // Step 3: extract communities
    auto comm = find_max_communities(adjacency,m);

    // Translate the result, so that it is compatible with the other clustering algorithms
    auto result = std::make_unique<CommunityStructure<M>>();

    for (auto c: comm)
    {
        result->add(std::move(c->to_community()));
    }

    return result;
}


}
}
