
#include <chrono>
#include <unordered_map>
#include <vector>
#include "community/CommunityStructure.hpp"
#include "community/Community.hpp"
#include "objects/EdgeMode.hpp"
#include "objects/Vertex.hpp"

namespace uu {
namespace net {


template <typename G>
void
expand(
    const std::vector<std::unique_ptr<MetaNetwork>>& levels,
    size_t i,
    const Vertex* v,
    Community<G>* com
)
{
    if (i==0)
    {
        for (auto original_vertex: levels.at(i)->mapping.at(v))
        {
            ////std::cout << "adding " << (*original_vertex) << std::endl;
            com->add(original_vertex);
        }
    }

    else
    {
        for (auto previous_vertex: levels.at(i)->mapping.at(v))
        {
            expand(levels, i-1, previous_vertex, com);
        }
    }
}


template <typename G>
std::unique_ptr<CommunityStructure<G>>
communities(
    const std::vector<std::unique_ptr<MetaNetwork>>& levels
)
{
    auto res = std::make_unique<CommunityStructure<G>>();

    size_t i = levels.size()-1;

    for (auto v: *levels.at(i)->get()->vertices())
    {
        auto community = std::make_unique<Community<G>>();

        expand(levels, i, v, community.get());

        res->add(std::move(community));
    }

    return res;
}

}
}

