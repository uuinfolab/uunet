/**
 * History:
 * - 2018.03.09 file created, with code taken from other existing files.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_ATTRIBUTESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_ATTRIBUTESTORE_H_

#include <memory>
#include "core/attributes.h"
#include "core/datastructures/observers/Observer.h"

namespace uu {
namespace net {

/**
 * A class to handle attributes to be associated to objects of type OT.
 *
 * OT can currently be Vertex or Edge.
 */
template <typename OT>
class AttributeStore :
    public core::MainMemoryAttributeStore<const OT*>,
    public core::Observer<const OT>
{

  public:

    /**
     * Constructor.
     */
    AttributeStore();

    /**
     * Creates a new attribute store.
     *
    static
    std::shared_ptr<AttributeStore<OT> >
    create(
    );*/

    /**
     * Adds a new attribute to the store.
     *
     * If an attribute with the same name is already present, a DuplicateElementException is thrown.
     *
    void
    add(
        const std::string& attribute_name,
        core::AttributeType a_type
    );

    **
     * Returns all the attributes in the store.
     *
    std::vector<core::Attribute>
    get_all(
    );

    **
     * Returns an attribute by name, or nullptr if the attribute does not exist.
     *
    const std::shared_ptr<core::Attribute>
    get(
        const std::string& attribute_name
    ) const;

    **
     * Returns the number of attributes in the store.
     *
    size_t
    size(
    ) const;


    **
     * Sets a new value to an object for a specific attribute.
     *
    template <class AT>
    void
    set_value(
        const std::string& attribute_name,
        const std::shared_ptr<OT>& object,
        const AT& val
    ) const
    {
        core::AttributeSharedPtr att = get(attribute_name);
        attribute_store_->set<AT>(object->id, att->name(), val);
    }

    **
     * Sets a new value to an object for a specific attribute, by providing a
     * string representation of the value.
     *
    void
    set_as_string(
        const std::string& attribute_name,
        const std::shared_ptr<OT>& object,
        const std::string& value
    )
    {
        core::AttributeSharedPtr att = get(attribute_name);
        attribute_store_->set_as_string(object->id,att->name(),value);
    }

    **
     * Gets the value associated to an object for a specific attribute.
     *
     * If no value has been set for the object, the is_null flag of the
     * output value is set.
     *
    template <class AT>
    core::Value<AT>
    get_value(
        const std::string& attribute_name,
        const std::shared_ptr<OT>& object
    ) const
    {
        core::AttributeSharedPtr att = get(attribute_name);
        return attribute_store_->get<AT>(object->id,att->name());
    }

    **
     * Gets a string representation of the value associated to an object for a specific attribute.
     *
     * If no value has been set for the object, the is_null flag of the output value is set.
     *
    core::Value<std::string>
    get_as_string(
        const std::string& attribute_name,
        const std::shared_ptr<OT>& object
    ) const
    {
        core::AttributeSharedPtr att = get(attribute_name);
        return attribute_store_->get_as_string(object->id,att->name());
    }
    */
    /**
     * Returns a short summary of the store, indicating the number of attributes.
     */
    virtual
    std::string
    summary(
    ) const;

    /**
     * When an object no longer exists, this method must be called to erase its values from the store.
     */
    void
    notify_erase(
        const OT* const o
    );


    void
    notify_add(
        const OT* const o
    );


    /**
     *
     */
    virtual
    void
    read_attributes(
        const OT* v,
        const std::vector<std::string>& fields,
        size_t offset,
        const std::vector<core::Attribute>& attributes,
        size_t line_number);


  protected:

    /** Object storing the attribute values in this store. */
    //core::AttributeStoreSharedPtr attribute_store_;

    /* Metadata about the attributes. */
    //std::unordered_map<std::string, core::AttributeSharedPtr> attributes_;

};

template <typename OT>
AttributeStore<OT>::
AttributeStore()
{
}

/*
template <typename OT>
std::shared_ptr<AttributeStore<OT> >
AttributeStore<OT>::
create(
)
{
    return std::shared_ptr<AttributeStore<OT> >(new AttributeStore<OT>());
}




template <typename OT>
void
AttributeStore<OT>::
add(
    const std::string& attribute_name,
    core::AttributeType type)
{
    if (attributes_.count(attribute_name)>0)
    {
        throw core::DuplicateElementException("attribute " + attribute_name);
    }

    core::AttributeSharedPtr att = std::make_shared<core::Attribute>(attribute_name,type);

    attribute_store_->add_attribute(att->name(),att->type());
    attributes_[attribute_name] = att;
}

template <typename OT>
size_t
AttributeStore<OT>::
size(
) const
{
    return attributes_.size();
}

template <typename OT>
std::vector<core::Attribute>
AttributeStore<OT>::
get_all(
)
{
    std::vector<core::Attribute> result;

    for (auto att: attributes_)
    {
        result.push_back(core::Attribute(att.first,att.second->type()));
    }

    return result;
}


template <typename OT>
const core::AttributeSharedPtr
AttributeStore<OT>::
get(
    const std::string& attribute_name
) const
{
    if (attributes_.count(attribute_name)==0)
    {
        throw core::ElementNotFoundException("attribute " + attribute_name);
    }

    return attributes_.at(attribute_name);
}

 */

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
}


template <typename OT>
void
AttributeStore<OT>::
read_attributes(
    const OT* v,
    const std::vector<std::string>& fields,
    size_t offset,
    const std::vector<core::Attribute>& attributes,
    size_t line_number
)
{

    int idx = offset;

    if (offset+attributes.size()>fields.size())
        throw core::WrongFormatException("Line " +
                                         std::to_string(line_number) +
                                         ": not enough attribute values");

    for (core::Attribute attribute: attributes)
    {
        this->set_as_string(v, attribute.name, fields[idx]);
        idx++;
    }
}


} // namespace net
} // namespace uu

#endif
