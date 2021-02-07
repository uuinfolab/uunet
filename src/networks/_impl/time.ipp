namespace uu {
namespace net {

template <class STORE>
void
make_temporal(
    STORE& store
)
{
    store->attr()->add("t_", core::AttributeType::TIMESET);
}

template <class STORE>
void
add_time(
    STORE* store,
    typename STORE::value_type* obj,
    const core::Time& t
)
{
    store->attr()->add_time(obj, "t_", t);
}

template <class STORE>
std::set<core::Time>
get_times(
    STORE* store,
    typename STORE::value_type* obj
)
{
    return store->attr()->get_times(obj, "t_");
}

}
}

