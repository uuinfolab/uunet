#ifndef UU_NET_DATASTRUCTURE_OBSERVERS_NOLOOPCHECKOBSERVER2_H_
#define UU_NET_DATASTRUCTURE_OBSERVERS_NOLOOPCHECKOBSERVER2_H_

#include "core/datastructures/observers/Observer.hpp"
#include "objects/MLEdge2.hpp"

namespace uu {
namespace net {

/**
 * This observer checks that the vertices at the end of new edges are not the same (that is, there are no loops).
 */
class NoLoopCheckObserver2 :
    public core::Observer<const MLEdge2>
{

  public:

    /**
     * Creates an observer with a pointer to the vertex store where vertices are expected to be.
     *
     */
    NoLoopCheckObserver2();

    /**
     * Informs the observer that an edge has been added.
     */
    void
    notify_add(
        const MLEdge2* e
    ) override;


    /**
     * Informs the observer that an edge has been erased.
     */
    void
    notify_erase(
        const MLEdge2* e
    ) override;

};


}
}

#endif
