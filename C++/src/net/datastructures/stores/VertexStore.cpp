/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "net/datastructures/stores/VertexStore.h"

namespace uu {
namespace net {


VertexStore::
VertexStore(
)
{
}


const Vertex *
VertexStore::
add(
    std::shared_ptr<const Vertex> vertex
)
{
    // Notify the observers.
    for (auto obs: observers)
    {
        obs->notify_add(vertex.get());
    }

    // Return a nullptr if a vertex with this name exists.
    const Vertex * res = super::add(vertex);

    if (!res)
    {
        return nullptr;
    }



    return res;
}



bool
VertexStore::
erase(
    const Vertex * const vertex
)
{
    // Notify the observers.
    for (auto obs: observers)
    {
        obs->notify_erase(vertex);
    }

    // Return a nullptr if a vertex with this name exists.
    bool res = super::erase(vertex);

    if (!res)
    {
        return false;
    }


    return true;
}



std::string
VertexStore::
summary(
) const
{
    size_t s = size();
    std::string summary =
        std::to_string(s) +
        (s==1?" vertex":" vertices") +
        ", ";// +
    //attributes_->summary();
    return summary;
}


std::unique_ptr<VertexStore>
create_vertex_store()
{
    return std::make_unique<VertexStore>();
}


}
}

