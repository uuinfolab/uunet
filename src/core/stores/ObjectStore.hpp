/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_CORE_STORES_OBJECTSTORE_H_
#define UU_CORE_STORES_OBJECTSTORE_H_

#include <memory>
#include <map>
#include "core/stores/_impl/SharedPtrSortedRandomSet.hpp"
#include "core/observers/Observer.hpp"
#include "core/observers/Subject.hpp"

namespace uu {
namespace core {

/**
 * A ObjectStore allows to create, store, retrieve and erase a set of elements.
 *
 * OBJECT_TYPE must have:
 * a typedef key_type, to specify the input to create the objects used as keys by the store
 */
template <typename OBJECT_TYPE>
class
    ObjectStore :
    public core::SharedPtrSortedRandomSet<const OBJECT_TYPE>,
    public core::Subject<const OBJECT_TYPE>
{

  private:

    typedef core::SharedPtrSortedRandomSet<const OBJECT_TYPE> super;

  public:

    typedef OBJECT_TYPE value_type;
    typedef typename OBJECT_TYPE::key_type key_type;
    typedef typename super::iterator iterator;

    ObjectStore(
    );

    virtual
    ~ObjectStore() {}

    using super::add;
    using super::size;
    using core::Subject<const OBJECT_TYPE>::observers;

    const OBJECT_TYPE *
    add(
        std::shared_ptr<const OBJECT_TYPE> v
    ) override;

    /** Creates a new object and adds it to the store.
    const OBJECT_TYPE *
    add(
        const typename OBJECT_TYPE::key_type& key
    );
     */

    const OBJECT_TYPE *
    get(
        const typename OBJECT_TYPE::key_type& key
    ) const;

    bool
    erase(
        const OBJECT_TYPE * v
    ) override;

    /**
     * Returns a short string summary of this store, for example including
     * the number of objects it contains.
     
    virtual
    std::string
    summary(
    ) const;*/


  protected:

    /** Index: find element by key. */
    std::map<typename OBJECT_TYPE::key_type, const OBJECT_TYPE*> cidx_element_by_name;

};

}
}

#include "ObjectStore.ipp"

#endif
