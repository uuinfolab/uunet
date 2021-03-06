#include "networks/_impl/stores/VertexStore.hpp"

#include <memory>

namespace uu {
namespace net {


VertexStore::
VertexStore(
)
{
    store_ = std::make_unique<core::ObjectStore<Vertex>>();
}

VertexStore::iterator
VertexStore::
begin(
) const
{
    return store_->begin();
}

VertexStore::iterator
VertexStore::
end(
) const
{
    return store_->end();
}

size_t
VertexStore::
size(
) const
{
    return store_->size();
}

const Vertex*
VertexStore::
add(
    std::shared_ptr<const Vertex> v
)
{
    if (store_->add(v))
    {
        return v.get();
    }

    else
    {
        return nullptr;
    }
}

const Vertex*
VertexStore::
add(
    const Vertex* v
)
{
    if (store_->add(v))
    {
        return v;
    }

    else
    {
        return nullptr;
    }
}


const Vertex*
VertexStore::
add(
    const std::string& vertex_name
)
{
    return store_->add(std::make_shared<Vertex>(vertex_name));
}

bool
VertexStore::
contains(
    const Vertex* v
) const
{
    return store_->contains(v);
}

bool
VertexStore::
contains(
    const std::string& key
) const
{
    auto v = store_->get(key);

    if (v)
    {
        return true;
    }

    else
    {
        return false;
    }
}

const Vertex*
VertexStore::
get(
    const std::string& vertex_name
) const
{
    return store_->get(vertex_name);
}

const Vertex*
VertexStore::
at(
    size_t pos
) const
{
    return store_->at(pos);
}

const Vertex*
VertexStore::
get_at_random(
) const
{
    return store_->get_at_random();
}


int
VertexStore::
index_of(
    const Vertex* v
) const
{
    return store_->index_of(v);
}


bool
VertexStore::
erase(
    const Vertex * v
)
{
    return store_->erase(v);
}

bool
VertexStore::
erase(
    const std::string& key
)
{
    auto v = store_->get(key);

    if (v)
    {
        return store_->erase(v);
    }

    else
    {
        return false;
    }
}

void
VertexStore::
attach(
    core::Observer<const Vertex>* obs
)
{
    store_->attach(obs);
}

std::string
VertexStore::
summary(
) const
{
    return "";
}


}
}

