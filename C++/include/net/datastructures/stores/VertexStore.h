/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_DATASTRUCTURES_STORES_VERTEXSTORE_H_
#define UU_NET_DATASTRUCTURES_STORES_VERTEXSTORE_H_

#include <memory>
#include <unordered_map>
//#include "core/datastructures/Container.h"
#include "net/datastructures/objects/Vertex.h"
#include "core/datastructures/observers/Observer.h"
#include "core/datastructures/observers/Subject.h"
#include "core/datastructures/containers/LabeledSharedPtrSortedRandomSet.h"

namespace uu {
namespace net {

/**
 * A VertexStore allows to create, store, retrieve and erase a set of vertices.
 *
 * A must be an attribute store, itself templatized to work with vertices.
 */
class
    VertexStore :
    public core::LabeledSharedPtrSortedRandomSet<const Vertex>,
    public core::Subject<const Vertex>
{

  private:

    typedef core::LabeledSharedPtrSortedRandomSet<const Vertex> super;

  public:
    VertexStore(
    );

    /**
     * Creates a new vertex store and returns a pointer to it.
     *
    static
    std::unique_ptr<VertexStore<A> >
    create(
           std::unique_ptr<A>& attr
           );*/

    using super::add;

    const Vertex *
    add(
        std::shared_ptr<const Vertex> vertex
    ) override;


    bool
    erase(
        const Vertex * const vertex
    ) override;


    /**
     * Returns a short string summary of this store, for example including
     * the number of vertices it contains.
     */
    virtual
    std::string
    summary(
    ) const;

  protected:

    /** Index: find vertex by name. */
    //std::unordered_map<std::string, Vertex const * const> cidx_vertex_by_name;

    /** Convenience object to return when the result is empty. */
    //std::shared_ptr<VertexList> empty_list;
    //std::set<std::shared_ptr<const Vertex>> owned_vertices;

};


std::unique_ptr<VertexStore>
create_vertex_store();

} // namespace net
} // namespace uu

#endif
