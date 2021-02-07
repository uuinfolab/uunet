#ifndef UU_CORE_STORES_ATTRIBUTESTORE_H_
#define UU_CORE_STORES_ATTRIBUTESTORE_H_

#include <memory>
#include "core/attributes/MainMemoryAttributeValueMap.hpp"
#include "core/datastructures/observers/Observer.hpp"
#include "core/exceptions/assert_not_null.hpp"

namespace uu {
namespace core {

/**
 * A class to handle attributes to be associated to objects of type OT.
 */
template <typename OT>
class AttributeStore :
    public MainMemoryAttributeValueMap<const OT*>,
    public Observer<const OT>
{

  public:

    /**
     * Constructor.
     */
    AttributeStore();

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
        const std::vector<Attribute>& attributes,
        size_t line_number);

};


}
}

#include "AttributeStore.ipp"

#endif
