#ifndef UU_NET_DATASTRUCTURE_OBSERVERS_CHECKVERTICESEXISTOBSERVER_H_
#define UU_NET_DATASTRUCTURE_OBSERVERS_CHECKVERTICESEXISTOBSERVER_H_

#include "core/datastructures/observers/Observer.hpp"
#include "objects/MLEdge2.hpp"
#include "olap/VCube.hpp"

namespace uu {
namespace net {

/**
 * This observer checks if the vertices adjacent to new edges exist.
 */
class CheckVerticesExistObserver :
    public core::Observer<const MLEdge2>
{

  public:

    /**
     * Creates an observer with a pointer to the vertex store where vertices are expected to be.
     *
     */
    CheckVerticesExistObserver(
    );

    /**
     * Informs the observer that a vertex has been added to its vertex store.
     */
    void
    notify_add(
        const MLEdge2* e
    ) override;


    /**
     * Informs the observer that a vertex has been erased from its vertex store.
     */
    void
    notify_erase(
        const MLEdge2* e
    ) override;

};


}
}

#endif
