/**
 * History:
 * - 2018.03.19 file created, with code taken from other existing files.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_TIMES_H_
#define UU_NET_DATASTRUCTURES_STORES_TIMES_H_

#include <memory>
#include "net/datastructures/stores/AttributeStore.h"
#include "core/exceptions/ElementNotFoundException.h"

namespace uu {
namespace net {


const
std::string
kDEFAULT_TIME_ATTRIBUTE_NAME = "uu::net::time";

template <typename OT>
class Times
{

  protected:

    /**
     * Constructor.
     */
    Times(AttributeStore<OT>* attr);

  public:

    /**
     *
     */
    void
    set_time(
        const OT* obj,
        core::Time val
    );

    /**
     *
     */
    core::Value<core::Time>
    get_time(
        const OT* obj
    ) const;

    /**
     * If the AttributeStore used by this class to store the times contains other attributes
     * of type Time, this function can be used so that subsequent calls to get_time and
     * set_time will get/set values from one of these attributes.
     * @param name the name of the attribute to be used from now on to set/get times
     * @throw ElementNotFoundException if a Time-typed attribute with that name does not exist
     */
    void
    set_time_attribute(
        const std::string& name
    );


  private:

    AttributeStore<OT>* attr_;
    std::string time_attribute_;

};



template <typename OT>
Times<OT>::
Times(AttributeStore<OT>* attr)
{
    attr_ = attr;
    time_attribute_ = kDEFAULT_TIME_ATTRIBUTE_NAME;
    attr_->add(time_attribute_, core::AttributeType::TIME);
}


template <typename OT>
void
Times<OT>::
set_time(
    const OT* obj,
    core::Time val
)
{
    attr_->set_time(obj, time_attribute_, val);
}


template <typename OT>
core::Value<core::Time>
Times<OT>::
get_time(
    const OT* obj
) const
{
    return attr_->get_time(obj, time_attribute_);
}


template <typename OT>
void
Times<OT>::
set_time_attribute(
    const std::string& name
)
{
    if (!attr_->get(name))
    {
        throw core::ElementNotFoundException("attribute " + name);
    }

    time_attribute_ = name;
}


}
}

#endif
