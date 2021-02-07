#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/exceptions/assert_not_null.hpp"

#include "networks/Network.hpp"
#include "networks/Network2.hpp"

namespace uu {
namespace net {

template<typename G>
std::unique_ptr<G>
empty_copy(
    const G* g,
    const std::string& name
)
{
    (void)g;
    (void)name;
    throw core::OperationNotSupportedException("Empty copy not supported for this network type");
}


template<>
inline std::unique_ptr<Network>
empty_copy(
    const Network* g,
    const std::string& name
)
{
    core::assert_not_null(g, "empty_copy", "g");

    EdgeDir dir = g->is_directed() ? EdgeDir::DIRECTED : EdgeDir::UNDIRECTED;
    bool loops = g->allows_loops();

    return std::make_unique<Network>(name, dir, loops);
}

template<>
inline std::unique_ptr<Network2>
empty_copy(
    const Network2* g,
    const std::string& name
)
{
    core::assert_not_null(g, "empty_copy", "g");

    EdgeDir dir = g->is_directed() ? EdgeDir::DIRECTED : EdgeDir::UNDIRECTED;
    LoopMode loops = g->allows_loops() ? LoopMode::ALLOWED : LoopMode::DISALLOWED;

    return std::make_unique<Network2>(name, dir, loops);
}

}
}

