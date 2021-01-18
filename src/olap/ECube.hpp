#ifndef UU_OLAP_ECUBE_H_
#define UU_OLAP_ECUBE_H_

#include <memory>
#include <string>
#include <unordered_map>
#include "networks/_impl/stores/MDSimpleEdgeStore.hpp"
#include "olap/VCube.hpp"
#include "olap/MLCube.hpp"
#include "objects/MLEdge2.hpp"

namespace uu {
namespace net {

/**
 * Similar to an edge store, but updates happen at cell level
 */
class
    ECube
{

  private:
    
    MLCube<MDSimpleEdgeStore> cube_;
    
    VCube* cube1_;
    VCube* cube2_;

    //std::string name_;
    
    typedef MLCube<MDSimpleEdgeStore> super;
    typedef MDSimpleEdgeStore EStore;
    typedef MDSimpleEdgeStore* entry_type;
    typedef const MLEdge2* element_type;

  public:

    // ECube(const std::vector<size_t>& dim);

    ECube(
        const std::string& name,
        VCube* cube1,
        VCube* cube2,
        EdgeDir dir = EdgeDir::UNDIRECTED,
        LoopMode loops = LoopMode::ALLOWED
    );

    ~ECube()
    {
    }
    
    /*
    std::unique_ptr<ECube>
    model(
        const std::vector<std::string>& dim,
        const std::vector<std::vector<std::string>>& members
    ) const;
*/
    
    /**
     * @brief Returns the nodes with an edge from/to the input vertex.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return the list of neighbors.
     **/
    const
    GenericObjectList<Vertex>*
    neighbors(
        const Vertex* vertex,
        const VCube* cube,
        EdgeMode mode = EdgeMode::INOUT
    ) const;

    
    const
    GenericObjectList<Vertex>*
    neighbors(
        const Vertex* vertex,
        EdgeMode mode = EdgeMode::INOUT
    ) const;
    
    
    /**
     * @brief Returns the nodes with an edge from/to the input vertex.
     * @param node pointer to the node.
     * @param mode IN, OUT or INOUT.
     * @return the list of neighbors.
     **/
    const
    GenericObjectList<MLEdge2>*
  incident(
          const Vertex* vertex,
          const VCube* cube,
          EdgeMode mode = EdgeMode::INOUT
  ) const;


      const
      GenericObjectList<MLEdge2>*
    incident(
            const Vertex* vertex,
            EdgeMode mode = EdgeMode::INOUT
    ) const;
    
    
    const VCube*
    vcube1(
    ) const;


    const VCube*
    vcube2(
    ) const;

    
    /**
     * Returns the number of elements in the cube.
     */
    size_t
    size(
    ) const;
    
    /**
     * Returns the order (number of dimensions) of this cube.
     */
    size_t
    order(
    ) const;

    /**
     * Returns the number of members for each dimension.
     */
    std::vector<size_t>
    dsize(
    ) const;

    /**
     * Returns the names of the dimensions of this cube.
     */
    const std::vector<std::string>&
    dimensions(
    ) const;
    
    /**
     * Returns the members of all dimensions.
     */
    const std::vector<std::vector<std::string>>&
    members(
    ) const;
    
    /**
     * Returns the members of a dimension.
     */
    const std::vector<std::string>&
    members(
        const std::string& dim
    ) const;
    
    /**
     * Returns the members of a dimension.
     */
    const std::vector<std::string>&
    members(
        size_t dim_idx
    ) const;
    
    /** Returns an iterator to the first object in the collection */
    typename MDSimpleEdgeStore::iterator
    begin(
    ) const;

    /** Returns an iterator after the last object in the collection */
    typename MDSimpleEdgeStore::iterator
    end(
    ) const;

    /**
     * Inserts a new object in the collection.
     * @return a pointer to the object
     */
    const MLEdge2 *
    add(
        const Vertex* vertex1,
        const VCube* cube1,
        const Vertex* vertex2,
        const VCube* cube2
    );
    
    /**
     * Inserts a new object in the collection.
     * @return a pointer to the object
     */
    const MLEdge2 *
    add(
        const MLEdge2* edge
    );
    
 
    /**
     * Creates a new object and adds it to the store.
     * @return a pointer to the object
     */
    const MLEdge2 *
     add(
         const Vertex* vertex1,
         const Vertex* vertex2
     );
     

    /** Returns true if an object with the input id is present in the collection */
    bool
    contains(
        const MLEdge2* e
    ) const;
    
    /** Returns true if the edge is present in the collection */
    bool
    contains(
    const Vertex* vertex1,
    const VCube* cube1,
    const Vertex* vertex2,
    const VCube* cube2
    ) const;
    
    
    /** Returns true if the edge is present in the collection */
    bool
    contains(
    const Vertex* vertex1,
    const Vertex* vertex2
    ) const;
    
    /** Returns the object with the input key if present in the collection, or nullptr */
    const MLEdge2 *
    get(
        const Vertex* vertex1,
        const VCube* cube1,
        const Vertex* vertex2,
        const VCube* cube2
    );
    
    const MLEdge2 *
    get(
        const Vertex* vertex1,
        const Vertex* vertex2
    );

    /** Returns the object at the given position in the collection.
     * @throw ElementNotFoundException if the index is outside the bounds on the set
     */
    const MLEdge2 *
    at(
        size_t pos
    ) const;

    /** Returns a random object, uniform probability */
    const MLEdge2 *
    get_at_random(
    ) const;

    /** Returns the position of the input value in the collection, or -1 */
    int
    index_of(
        const MLEdge2 * v
    ) const;

    /**
     * Erases obj from the cube, if present.
     * @return true if the object has been erased
     */
    bool
    erase(
        const MLEdge2 * obj
    );
    
    /**
     * Erases obj from the cube, if present.
     * @return true if the object has been erased
     */
    bool
    erase(
        const std::string& key
    );

    core::AttributeStore<const MLEdge2>*
    attr(
    ) const;

    /**
     * Adds a new dimension.
     */
    void
    add_dimension(
        const std::string& name,
        const std::vector<std::string>& members,
        std::vector<bool> (*discretize)(const Vertex*) = nullptr
    );
    
    /**
     * Adds a member to an existing dimension.
     */
    void
    add_member(
        const std::string& name,
        const std::string& member//,
        //bool (*copy)(const Vertex*) = nullptr
    );
    
    /**
     * Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    MDSimpleEdgeStore*
    cell(
        const std::vector<size_t>& index
    );

    /**
     * Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    const MDSimpleEdgeStore*
    cell(
        const std::vector<size_t>& index
    ) const;

    /**
     * Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    MDSimpleEdgeStore*
    cell(
        const std::vector<std::string>& index
    );

    /**
     * Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    const MDSimpleEdgeStore*
    cell(
        const std::vector<std::string>& index
    ) const;

    std::string
    to_string(
    ) const;

    void
    attach(
        core::Observer<const MLEdge2>* obs
    );

    bool
    is_directed(
    ) const;
    
    bool
    allows_loops(
    ) const;

    void
    erase(
    const VCube* vcube,
    const Vertex* vertex
    );
    
  protected:

    virtual
    MDSimpleEdgeStore*
    init(
        size_t pos
    );
    
     void
     init(
     );

    
    void
    reset(
          );
    
    /** Edge directionality */
    EdgeDir dir_;
    
    /** Loop mode (ALLOWED or DISALLOWED) */
    LoopMode loops_;
    

};



}
}

#endif
