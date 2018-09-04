/**
 * History:
 * - 2018.03.09 file created, with code taken from other existing files.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_ATTRIBUTES_H_
#define UU_NET_DATASTRUCTURES_STORES_ATTRIBUTES_H_

#include <memory>
#include "core/datastructures/observers/Observer.h"
#include "net/datastructures/stores/AttributeStoreWrapper.h"
#include "core/exceptions/NullPtrException.h"

namespace uu {
namespace net {

/**
 * A class to handle attributes to be associated to objects of type OT.
 *
 * OT can currently be Vertex or Edge.
 */
template <typename OT, typename ...Attrs>
class Attributes :
    public core::Observer<const OT>,
    private AttributeStoreWrapper<OT>,
    public Attrs...
{

  public:

    /**
     * Constructor.
     */
    Attributes();

    using AttributeStoreWrapper<OT>::attr_;

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



};

template <typename OT, typename ...Attrs>
Attributes<OT, Attrs...>::
Attributes() :
    AttributeStoreWrapper<OT>(std::make_unique<AttributeStore<OT>>()),
    Attrs(attr_.get())...
{
}


template <typename OT, typename ...Attrs>
std::string
Attributes<OT, Attrs...>::
summary(
) const
{
    size_t s = attr_->size();
    std::string summary = std::to_string(s) + ((s==1)?" attribute":" attributes");
    return summary;
}


template <typename OT, typename ...Attrs>
void
Attributes<OT, Attrs...>::
notify_erase(
    const OT* object
)
{
    if (!object)
    {
        throw core::NullPtrException("AttributeStore::notify_erase()");
    }

    for (auto att: *attr_)
    {
        attr_->reset(object, att->name);
    }
}

template <typename OT, typename ...Attrs>
void
Attributes<OT, Attrs...>::
notify_add(
    const OT* object
)
{
    if (!object)
    {
        throw core::NullPtrException("AttributeStore::notify_erase()");
    }
}

/*
template <typename OT, typename ...Attrs>
void
Attributes<OT, Attrs...>::
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
}*/


} // namespace net
} // namespace uu

#endif
