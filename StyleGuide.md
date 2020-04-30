# Style guide (C++)

This is a style guide to develop the _uunet_ library. The same style shall be used for all C++ code produced
by the Uppsala University Information Laboratory.

We currently use the C++14 standard.

Many of the following conventions can be automatically formatted using the astyle program:

    astyle -r -s4 -xn -A1 -xB -xD -xG -j -F -H -Y -n --recursive src/

## Structure

The code is contained in four main top-level folders:
 - `ext/` (external libraries)
 - `test/` (unit tests)
 - `examples/` (examples showing how to use the library)
 - `src/` (original library code)

The folder `src/` contains eleven folders, each providing some homogeneous set of classes and functions:

 - Basic non-network functionality:
   * `core/` (basic functionality such as exceptions, mathematical functions, CSV reading...)
 - Network data structures:
   * `networks/` (various types of networks such as Network, WeightedNetwork, MultilayerNetwork, ...)
   * `objects/` (parts of networks such as Vertex, Edge, Trail, Clique, ...)
 - Obtaining networks:
   * `io/` (functions to read and write networks from/to file)
   * `generation/` (functions to generate new networks from scratch such as ER, complete, ...)
 - Manipulating networks:
   * `operations/` (functions to manipulate networks such as union, contraction, slicing, projection, ...)
 - Analyzing networks:
   * `measures/` (functions to measure networks, such as degree, betweenness, ...)
   * `community/` (data structures, algorithms and measures for community detection such as Louvain, ...)
   * `algorithms/` (basic graph algorithms such as BFS, SSSP, ...)
 - Inspection/visualization:
   * `layout/` (functions to associate coordinates with network vertices)
   * `utils/` (printing functions)

Some code is included inside directories named `_impl`.  These contain code to implement the functions in
the library but not intended to be shared/used by external code. All the classes and functions not inside `_impl`
directories can be used in external software using _uunet_.

## Naming

Types: first capital, capital for each new word.

    class MultilayerNetwork
    
Variables and functions: lower case with _ between words.

    int num_actors;
    int get_actors();
    
Class data members: same as variables, with trailing _ if private/protected.

    private:
        int num_actors_;
    public:
        const std::string name;
    
Enumerations: all capital, with underscore if needed. They are used as: `AttributeType::TIME`.

    enum class AttributeType
    {
        STRING,
        NUMERIC,
        DOUBLE,
        INTEGER,
        TIME
    };
    
Constants: all capital, with underscores if needed, with small k at the beginning.

    const int kBUCKET_SIZE = 1024;
    
Macros: we do not use macros.

Files: if the file corresponds to a type, same name of the type (first capital, etc.). Otherwise, lower case, with or
without _ between words. Extensions: .cpp, .hpp (declarations) and .ipp (definitions for templates).

    MultilayerNetwork.hpp
    MultilayerNetwork.cpp
    exp_degree.hpp
    exp_degree.ipp

Define guards: UU + sequence of directories where the header file is located + the name of the header file + H,
with _ at the end, all capital.

    #ifndef UU_NETWORKS_TEMPORALNETWORK_H_

## Coding style

Indentation is done using four (4) spaces (option -s4 in astyle). Namespace declarations are not indented:

    namespace uu {
    namespace core {
    
    typedef long Time;
    ...

Access modifiers are half-indented (option -xG in astyle):

    class
    CSVReader
    {
      public:
        std::string get_next();
    };

Functions are written listing in separate lines:

1. `template` declarations, if present.
2. `virtual`, `static` if present.
3. return type (including `const` and `&` if present, option -xB and -xD in astyle).
4. class::, for member methods.
5. function name with open `(`
6. one line for each parameter
7. closed `)` (including `const`, `= 0`, `;`, `:` etc. if present)
8. one indented line for each initializer, for constructor initialization lists.

Braces are written on separate lines, also inside the function (option -A1 in astyle):

    const Vertex*
    get(
        const std::string& name
    ) const
    {
        if (true)
        {
            ...
        }
    }

    template <class STRUCTURE, class CONTEXT, class VALUE>
    VALUE
    PropertyMatrix<STRUCTURE,CONTEXT,VALUE>::
    get_default(
    ) const
    {
        return default_value;
    }
    
Exceptions are namespaces, where braces are on the same line (option -xn in astyle):
    
    namespace uu {
    
and initializers:

    std::vector<int> vec = {1, 2, 3};
  
Always use braces after `if`, `for` etc., even if the body consists of only one statement (option -j in astyle).

Line length should be max 120 chars.

In general, do not write too compact code. Pad empty lines around `for`, `while`, etc. blocks (option -F in astyle).
Put a space after `if`, `while`, etc. keywords (option -H in astyle).

## Comments

The general behavior of classes, class members, functions, etc. is documented in the header files.
The .cpp and .ipp files contain implementation-specific annotations.

If the header file contains one class, the documentation of the class is sufficient. If the header file has a more
complex structure, e.g., it lists many functions, add a brief description followed by an empty line and a longer
description (if necessary).

    /**
     * Brief description of the file content.
     *
     * Additional details, on
     * multiple lines if necessary.
     */

Do not indicate the author, because files can be updated by multiple people in time and details about
authorship are already available in the version control system if necessary.

Comment every class member with a comment above it. End the comment with a full stop.

    /** Name of the network. */
    std::string name;
    
    /** Returns the number of actors in this network. */
    int num_actors();
    
For multi-line comments, use:
    
    /**
     * Example of a comment
     * on multiple lines.
     */
    
Comments should be aligned with the code (option -Y in astyle).

When documenting functions, use the tags `@param`, `@return`, `@throw`, `@todo`, `@bug` when relevant.
`@todo` and `@bug` tags can also be used inside .cpp files if this makes the location of the todo/bug easier to find.
After a tag, start the comment with a small letter, and do *not* end it with a `.`.

    /**
     * Converts a generic type to a string representation of it.
     * @param val value to be converted
     * @return a string representation of the input
     */
    template <typename T>
    std::string
    to_string (
        const T& val
    )
    {
        ...
    }

However, do not over-document: if a function, parameter, etc. is self-understandable, no need to waste bits
and time. For example, no need to document the parameter or the return value in:

    /** Returns a string representation of the input network. */
    std::string
    to_string(
        const Network& net
    );
    
