
namespace uu {
namespace core {


template <typename OBJECT_TYPE>
ObjectStore<OBJECT_TYPE>::
ObjectStore(
)
{
}


template <typename OBJECT_TYPE>
const OBJECT_TYPE *
ObjectStore<OBJECT_TYPE>::
add(
    std::shared_ptr<const OBJECT_TYPE> v
)
{

    core::assert_not_null(v.get(), "add", "v");

    // Notify the observers.
    for (auto obs: observers)
    {
        obs->notify_add(v.get());
    }

    // Return false if a vertex with this key exists.
    auto search = cidx_element_by_name.find(v->key);

    if (search != cidx_element_by_name.end())
    {
        return nullptr;
    }

    const OBJECT_TYPE* res = super::add(v);

    // Indexing.
    cidx_element_by_name[v->key] = v.get();

    return res;
}


/*
template <typename OBJECT_TYPE>
const OBJECT_TYPE *
ObjectStore<OBJECT_TYPE>::
add(
    const typename OBJECT_TYPE::key_type& key
)
{
    if (!get(key))
    {
        return add(OBJECT_TYPE::create(key));
    }

    else
    {
        return nullptr;
    }
}
*/

template <typename OBJECT_TYPE>
const OBJECT_TYPE *
ObjectStore<OBJECT_TYPE>::
get(
    const typename OBJECT_TYPE::key_type& key
) const
{
    auto search = cidx_element_by_name.find(key);

    if (search != cidx_element_by_name.end())
    {
        return search->second;
    }

    else
    {
        return nullptr;
    }
}

template <typename OBJECT_TYPE>
bool
ObjectStore<OBJECT_TYPE>::
erase(
    const OBJECT_TYPE * v
)
{
    core::assert_not_null(v, "erase", "v");


    // Notify the observers.
    for (auto obs: observers)
    {
        obs->notify_erase(v);
    }

    auto search = cidx_element_by_name.find(v->key);

    if (search != cidx_element_by_name.end())
    {
        cidx_element_by_name.erase(search);
        super::erase(v);
        return true;
    }

    else
    {
        return false;
    }
}

/*
template <typename OBJECT_TYPE>
std::string
ObjectStore<OBJECT_TYPE>::
summary(
) const
{
    size_t s = size();
    std::string summary =
        std::to_string(s) +
        (s==1?" object":" objects");
    return summary;
}
*/
}
}
