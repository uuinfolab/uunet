/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURE_NOOPOBSERVER_H_
#define UU_NET_DATASTRUCTURE_NOOPOBSERVER_H_

#include "core/exceptions/OperationNotSupportedException.h"
#include "core/containers/Observer.h"

namespace uu {
namespace net {

/**
 *
 */
template<typename T>
class NoOpObserver :
    public core::Observer<T>
{

  public:

    /**
     * Informs the graph that a vertex has been added to its vertex store.
     */
    void
    notify_add(
        T* el
    ) override;


    /**
     * Informs the graph that a vertex has been erased from its vertex store.
     */
    void
    notify_erase(
        T* el
    ) override;

};


template<typename T>
void
NoOpObserver<T>::
notify_add(
    T* el
)
{
    throw core::OperationNotSupportedException("cannot add an element to this");
}


template<typename T>
void
NoOpObserver<T>::
notify_erase(
    T* el
)
{
    throw core::OperationNotSupportedException("cannot erase an element to this");
}


} // namespace net
} // namespace uu

#endif
