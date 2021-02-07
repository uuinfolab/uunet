namespace uu {
namespace core {


template <typename OT>
AttributeStore<OT>::
AttributeStore()
{
}

template <typename OT>
std::string
AttributeStore<OT>::
summary(
) const
{
    size_t s = this->size();
    std::string summary = std::to_string(s) + ((s==1)?" attribute":" attributes");
    return summary;
}


template <typename OT>
void
AttributeStore<OT>::
notify_erase(
    const OT* object
)
{
    core::assert_not_null(object, "AttributeStore::notify_erase", "object");

    for (auto att: *this)
    {
        this->reset(object, att->name);
    }
}

template <typename OT>
void
AttributeStore<OT>::
notify_add(
    const OT* object
)
{
    core::assert_not_null(object, "AttributeStore::notify_add", "object");
}


template <typename OT>
void
AttributeStore<OT>::
read_attributes(
    const OT* v,
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
