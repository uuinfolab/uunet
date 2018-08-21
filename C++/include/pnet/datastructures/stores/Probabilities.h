/**
 * History:
 * - 2018.08.16 file created, with code taken from other existing files.
 */

#ifndef UU_PNET_DATASTRUCTURES_STORES_PROBABILITIES_H_                              // ok
#define UU_PNET_DATASTRUCTURES_STORES_PROBABILITIES_H_                              // ok

#include <memory>
#include "net/datastructures/stores/AttributeStore.h"                               
#include "core/exceptions/ElementNotFoundException.h"

namespace uu {
namespace net {                                                                     // ok     


const
std::string
kDEFAULT_PROBABILITY_ATTRIBUTE_NAME = "uu::net::probability";                       // ok

template <typename OT>
class Probabilities                                                                  // ok
{

  protected:

    /**
     * Constructor.
     */
    Probabilities(AttributeStore<OT>* attr);

  public:

    /**
     *
     */
    void
    set_probability(
        const OT* obj,
        double val                                                                  // I will change it later to PROB datatype
    );

    /**
     *
     */
    core::Value<double>
    get_probability(
        const OT* obj
    ) const;



    /**
     * If the AttributeStore used by this class to store the probabilities contains other attributes
     * of type double, this function can be used so that subsequent calls to get_weight and
     * set_weight will get/set values from one of these attributes.
     * @param name the name of the attribute to be used from now on to set/get weights
     * @throw ElementNotFoundException if a double-typed attribute with that name does not exist
     */
    
    /*void
    set_weight_attribute(
        const std::string& name
    );
    */



  private:

    AttributeStore<OT>* attr_;
    std::string probability_attribute_;                                            // double?

};



template <typename OT>
Probabilities<OT>::
Probabilities(AttributeStore<OT>* attr)
{
    attr_ = attr;
    probability_attribute_ = kDEFAULT_PROBABILITY_ATTRIBUTE_NAME;
    attr_->add(core::Attribute::create(probability_attribute_, core::AttributeType::DOUBLE));
}


template <typename OT>
void
Probabilities<OT>::
set_probability(
    const OT* obj,
    double probability
)
{
    attr_->set_double(obj, probability_attribute_, probability);
}


template <typename OT>
core::Value<double>
Probabilities<OT>::
get_probability(
    const OT* obj
) const
{
    return attr_->get_double(obj, probability_attribute_);
}


/*template <typename OT>
void
Probabilities<OT>::
set_probability_attribute(
    const std::string& name
)


{
    if (!attr_->get(name))
    {
        throw core::ElementNotFoundException("attribute " + name);
    }

    probability_attribute_ = name;
}*/


}
}

#endif

