namespace uu {
namespace core {


template <typename OBJECT_TYPE>
AttributeStore<OBJECT_TYPE>::
AttributeStore()
{
}
/*
template <typename OBJECT_TYPE>
std::string
AttributeStore<OBJECT_TYPE>::
summary(
) const
{
    size_t s = this->size();
    std::string summary = std::to_string(s) + ((s==1)?" attribute":" attributes");
    return summary;
}
*/

template <typename OBJECT_TYPE>
void
AttributeStore<OBJECT_TYPE>::
notify_erase(
    const OBJECT_TYPE* const object
)
{
    core::assert_not_null(object, "AttributeStore::notify_erase", "object");

    for (auto att: *this)
    {
        this->reset(object, att->name);
    }
}

template <typename OBJECT_TYPE>
void
AttributeStore<OBJECT_TYPE>::
notify_add(
    const OBJECT_TYPE* const object
)
{
    core::assert_not_null(object, "AttributeStore::notify_add", "object");
}


template <typename OBJECT_TYPE>
void
AttributeStore<OBJECT_TYPE>::
read_attributes(
    const OBJECT_TYPE* const v,
    const std::vector<std::string>& fields,
    size_t offset,
    const std::vector<Attribute>& attributes,
    size_t line_number
)
{

    int idx = offset;

    if (offset+attributes.size()>fields.size())
        throw WrongFormatException("Line " +
                                   std::to_string(line_number) +
                                   ": not enough attribute values");

    for (Attribute attribute: attributes)
    {
        this->set_as_string(v, attribute.name, fields[idx]);
        idx++;
    }
}


}
}
