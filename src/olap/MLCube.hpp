#ifndef UU_NETWORKS_IMPL_OLAP_MLCUBE_H_
#define UU_NETWORKS_IMPL_OLAP_MLCUBE_H_

#include "core/stores/AttributeStore.hpp"
#include "core/exceptions/OutOfBoundsException.hpp"
#include "core/exceptions/WrongParameterException.hpp"
#include "core/exceptions/OutOfBoundsException.hpp"
#include "core/exceptions/OperationNotSupportedException.hpp"
#include "core/datastructures/containers/UnionSortedRandomSet.hpp"
#include "core/olap/datastructures/NCube.hpp"
#include "core/olap/selection/IndexIterator.hpp"
#include "core/datastructures/observers/UnionObserver.hpp"
#include <string>
#include <unordered_map>
#include <vector>

namespace uu {
namespace net {

template <class STORE>
class MLCube
{

  public:

    typedef STORE* entry_type;
    typedef STORE container_type;
    typedef const typename STORE::value_type value_type;

    /**
     * Creates a cube of order 0
     */
    MLCube(
        std::unique_ptr<STORE> el
        //const std::vector<std::string>& dim,
        //const std::vector<std::vector<std::string>>& members
    );


    virtual ~MLCube()
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
    dimensions(
    ) const;

    /**
     * Returns the names of the dimensions of this cube.
     */
    const std::vector<std::string>&
    dimension_names(
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
    
    /** Returns an iterator to the first object in the collection */
    typename STORE::iterator
    begin(
    ) const;

    /** Returns an iterator after the last object in the collection */
    typename STORE::iterator
    end(
    ) const;

    /**
     * Inserts a new object in the collection.
     * @ret
     */
    typename STORE::value_type*
    add(
        std::shared_ptr<typename STORE::value_type> v
    );

    /**
     * Inserts a new object in the collection.
     * @ret
     */
    typename STORE::value_type*
    add(
        typename STORE::value_type* v
    );


    /**
     * Creates a new vertex and adds it to the store.
     */
    typename STORE::value_type*
    add(
        const typename STORE::key_type& key
    );

    /** Returns true if an object with the input id is present in the collection */
    bool
    contains(
        typename STORE::value_type* v
    ) const;

    typename STORE::value_type*
    get(
        const typename STORE::key_type& key
    ) const;

    /** Returns the object at the given position in the collection.
     * @throw ElementNotFoundException if the index is outside the bounds on the set
     */
    typename STORE::value_type*
    at(
        size_t pos
    ) const;

    /** Returns a random object, uniform probability */
    typename STORE::value_type*
    get_at_random(
    ) const;


    /** Returns the position of the input value in the collection, or -1 */
    int
    index_of(
        typename STORE::value_type* v
    ) const;


    bool
    erase(
        typename STORE::value_type * v
    );

    void
    attach(
        core::Observer<typename STORE::value_type>* obs
    );

    core::AttributeStore<typename STORE::value_type>*
    attr(
    ) const;

    /** Returns a const iterator to the first object in the cube
    typename std::vector<std::shared_ptr<const STORE>>::const_iterator
            begin(
            ) const;*/

    /** Returns a const iterator after the last object in the cube
    typename std::vector<std::shared_ptr<const STORE>>::const_iterator
            end(
            ) const;*/

    /** Returns an iterator to the first object in the cube
    typename std::vector<std::shared_ptr<STORE>>::iterator
            begin(
            );*/

    /** Returns an iterator after the last object in the cube
    typename std::vector<std::shared_ptr<STORE>>::iterator
            end(
            ); */



    /**
     * Adds a new dimension.
     */
    void
    extend(
        const std::string& name,
        const std::vector<std::string>& members,
        std::vector<bool> (*discretize)(typename STORE::value_type*) 
    );
    
    /**
     * Returns the cell at the given position in the cube.
     
    STORE*
    operator[](
        const std::vector<size_t>& index
    );

    **
     * Returns the cell at the given position in the cube.
     
    const STORE*
    operator[](
        const std::vector<size_t>& index
    ) const;
    
    **
     * Returns the cell at the given position in the cube.
     *
    STORE*
    operator[](
        const std::vector<std::string>& index
    );

    **
     * Returns the cell at the given position in the cube.
     *
    const STORE*
    operator[](
        const std::vector<std::string>& index
    ) const;
*/

    /** Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    STORE*
    cell(
        const std::vector<size_t>& index
    );

    /** Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    const STORE*
    cell(
        const std::vector<size_t>& index
    ) const;

    /** Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    STORE*
    cell(
        const std::vector<std::string>& index
    );

    /** Returns the cell at the given position in the cube.
     * @throw OutOfBoundsException if the index is outside the bounds on the cube
     */
    const STORE*
    cell(
        const std::vector<std::string>& index
    ) const;

    /**
     * Creates a new container in the input cell.
     * @throw OutOfBoundsException if the index is outside the bounds of the cube
     * @throw OperationNotSupportedException
     */
    STORE*
    init(
        const std::vector<size_t>& index,
        const std::shared_ptr<STORE>& store
    );

    /**
     * Creates a new container in the input cell.
     * @throw OutOfBoundsException if the index is outside the bounds of the cube
     * @throw OperationNotSupportedException
     */
    STORE*
    init(
        const std::vector<std::string>& index,
        const std::shared_ptr<STORE>& store
    );

    /* index of a dimension
    size_t
    index_of(
        const std::string& dim
    ) const;

     index of a member given a dimension
    size_t
    index_of(
        const std::string& dim,
        const std::string& member
    ) const;

     computes a numerical index from a label-based index
    std::vector<size_t>
    index_of(
        const std::vector<std::string>& index
    ) const;

    // OPERATORS

    template <typename Iterator>
    void
    resize(
        const std::string& dimension,
        const std::string& member,
        Iterator begin,
        Iterator end
    );

    MLCube(
        const std::vector<std::string>& dim,
        const std::vector<std::vector<std::string>>& members
    );

    void
    insert(
        const std::shared_ptr<STORE>& value,
        const std::vector<size_t>& index
    );

    void
    insert(
        const std::shared_ptr<STORE>& value,
        const std::vector<std::string>& index
    );
    */
protected:
    
    std::vector<size_t>
    index_of(
        const std::vector<std::string>& members
             ) const;
    
      size_t
      pos(
          const std::vector<std::string>& index
      ) const;
  

    size_t
    pos(
        const std::vector<size_t>& index
    ) const;
    
    void
    reset(
    );
    
    void
    init(
        size_t pos
    );
    
  private:

    // A STORE containing all the elements in the cube.
    // If the cube has order 0, this is the only STORE.
    // If the cube has order > 0, this store cannot be directly modified but is automatically
    // updated to mirror all the elements contained in the cube's cells.
    std::unique_ptr<STORE> elements_;
    
    // The cells of the cube.
    std::vector<std::shared_ptr<STORE>> data_;

    // When the cube has order > 0, this observer makes sure that the STORE elements_
    // contains all the elements contained in the cube's cells.
    std::unique_ptr<core::UnionObserver<STORE, const typename STORE::value_type>> union_obs;

    // Dimensions (that is, number of members for each dimension)
    std::vector<size_t> size_;

    // Offsets
    std::vector<size_t> off_;

    // Dimension names
    std::vector<std::string> dim_;
    
    // Index of each dimension (by name)
    std::unordered_map<std::string,size_t> dim_idx_;

    // Members, for each dimension
    std::vector<std::vector<std::string>> members_;
    
    // Index of each member (by name), for each dimension
    std::vector<std::unordered_map<std::string, size_t>> members_idx_;
    
    // Element attributes
    std::unique_ptr<core::AttributeStore<typename STORE::value_type>> attr_;

};

}
}

#include "MLCube.ipp"

#endif

