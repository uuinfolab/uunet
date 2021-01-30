#ifndef UU_OLAP_VCUBE_H_
#define UU_OLAP_VCUBE_H_

#include <memory>
#include <string>
#include <unordered_map>
#include "olap/MLCube.hpp"
#include "networks/_impl/stores/VertexStore.hpp"


namespace uu {
namespace net {

template <typename C>
std::unique_ptr<C>
vslice(
const std::string& cube_name,
    C* cube,
    const std::vector<std::vector<size_t>>& indexes
);

/**
 * Similar to a vertex store, but updates happen at cell level
 */
class
    VCube
{

private:
    
    std::unique_ptr<MLCube<VertexStore>> cube_;
    
    public:
    
    const std::string name;
    
    VCube(
    const std::string& name
    );
    
    virtual
    ~VCube()
    {
    }
    
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
    typename VertexStore::iterator
    begin(
    ) const;

    /** Returns an iterator after the last object in the collection */
    typename VertexStore::iterator
    end(
    ) const;

    /**
     * Inserts a new object in the collection.
     * @return a pointer to the object
     */
    const Vertex*
    add(
        const std::shared_ptr<const Vertex>& v
    );

    /**
     * Inserts a new object in the collection.
     * @return a pointer to the object
     */
    const Vertex*
    add(
        const Vertex* v
    );

    /**
     * Creates a new object and adds it to the store.
     * @return a pointer to the object
     */
    const Vertex*
    add(
        const std::string& key
    );

    /** Returns true if an object with the input id is present in the collection */
    bool
    contains(
        const Vertex* v
    ) const;
    
    /** Returns true if an object with the input key is present in the collection */
    bool
    contains(
        const std::string& key
    ) const;
    
    /** Returns the object with the input key if present in the collection, or nullptr */
    const Vertex*
    get(
        const std::string& key
    ) const;

    /** Returns the object at the given position in the collection.
     * @throw ElementNotFoundException if the index is outside the bounds on the set
     */
    const Vertex*
    at(
        size_t pos
    ) const;

    /** Returns a random object, uniform probability */
    const Vertex*
    get_at_random(
    ) const;

    /** Returns the position of the input value in the collection, or -1 */
    int
    index_of(
        const Vertex* v
    ) const;

    /**
     * Erases obj from the cube, if present.
     * @return true if the object has been erased
     */
    bool
    erase(
        const Vertex * obj
    );
    
    /**
     * Erases obj from the cube, if present.
     * @return true if the object has been erased
     */
    bool
    erase(
        const std::string& key
    );

    /**
     * Returns the attribute store associated to this cube
     */
    core::AttributeStore<const Vertex>*
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
    VertexStore*
    cell(
        const std::vector<size_t>& index
    );

    /**
     * Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    const VertexStore*
    cell(
        const std::vector<size_t>& index
    ) const;

    /**
     * Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    VertexStore*
    cell(
        const std::vector<std::string>& index
    );

    /**
     * Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    const VertexStore*
    cell(
        const std::vector<std::string>& index
    ) const;

    
    size_t
    num_cells(
    ) const;
    
    /**
     * Returns a string representation of the cube.
     */
    std::string
    to_string(
    ) const;

    void
    attach(
        core::Observer<const Vertex>* obs
    );
    
    
    
    std::shared_ptr<VertexStore>
    get_store(
              ) const;
    
    friend
    std::unique_ptr<VCube>
    vslice<VCube>(
    const std::string& cube_name,
        VCube* cube,
        const std::vector<std::vector<size_t>>& indexes
           );
    
  protected:
    
    std::unique_ptr<VCube>
    skeleton(
        const std::string& name,
        const std::vector<std::string>& dimensions,
        const std::vector<std::vector<std::string>>& members
    )  const;
    
    /*
    VCube(
    const std::string& cube_name,
        const std::vector<std::string>& dim,
        const std::vector<std::vector<std::string>>& members
    );
    */
    
    VertexStore*
    init(
    );
    
    VertexStore*
    init(
        const std::shared_ptr<VertexStore>& store
    );
    
    VertexStore*
    init(
        const std::vector<size_t>& index,
        const std::shared_ptr<VertexStore>& store
    );

    VertexStore*
    init(
        size_t pos,
        const std::shared_ptr<VertexStore>& store
    );
    
    VertexStore*
    init(
         const std::vector<size_t>& index
    );
    
    VertexStore*
    init(
        size_t pos
    );
    
    
    core::UnionObserver<VertexStore, const typename VertexStore::value_type>*
        register_obs(
        );
    
        void
        register_obs(
        const std::vector<size_t>& index
        );
    
    void
        register_obs(
            size_t pos
        );
    
    
    /*
    void
    init(
    );
    
    virtual
    void
    reset(
    );
    */
    
};



}
}

#endif
