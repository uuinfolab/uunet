/**
 * History:
 * - 2018.03.09 file created, with code taken from other existing files.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_EMPTYATTRIBUTESTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_EMPTYATTRIBUTESTORE_H_

namespace uu {
namespace net {

/**
 * An attribute store that does not allow attributes.
 *
 * To be used in the definition of non-attributed graphs.
 *
 * OT can currently be Vertex or Edge.
 */
template <typename OT>
class EmptyAttributeStore :
    public core::Observer<OT>
{

  public:

    /**
     * Constructor.
     */
    EmptyAttributeStore();

    void
    notify_erase(
        OT* o
    );


    void
    notify_add(
        OT* o
    );

    /**
     * Associates a list of attribute values to an object.
     *
     * @param obj object to which the attribute values are associated
     * @param fields vector from which the attribute values are read
     * @param offset attribute values are read starting from this offset
     * @param attributes attribute definitions, to interpret the read values
     * @param line_number line number in the file where the values are read from
     *
    virtual
    void
    read_attributes(
        std::shared_ptr<OT>& obj,
        const std::vector<std::string>& fields,
        size_t offset,
        const std::vector<core::Attribute>& attributes,
        size_t line_number
    );*/

};


template <typename OT>
EmptyAttributeStore<OT>::
EmptyAttributeStore()
{
}

template <typename OT>
void
EmptyAttributeStore<OT>::
notify_erase(
    OT* object
)
{
}

template <typename OT>
void
EmptyAttributeStore<OT>::
notify_add(
    OT* object
)
{
}

/*
template <typename OT>
std::string
EmptyAttributeStore<OT>::
summary(
) const
{
std::string summary = "0 attributes";
return summary;
}*/

} // namespace net
} // namespace uu

#endif
