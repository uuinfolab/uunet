# Style guide (C++)

This is a style guide to be used when writing software in C++ at the Uppsala University Information Laboratory.
We currently use the C++14 standard.

Many of the following conventions are automatically formatted using the astyle program:

    astyle -r -s4 -xn -A1 -xB -xD -xG -j -F -H -Y -n --recursive src/

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

Braces are always written on separate lines - also inside the function (option -A1 in astyle):

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
    
except for namespaces (option -xn in astyle).

Always use braces around if, for etc., even if the body consists of only one statement (option -j in astyle).

Line length should be max 120 chars.

    namespace uu {

In general, do not write too compact code. Pad empty lines around for, while, etc. blocks (option -F in astyle).
Put a space after if, while, etc. keywords (option -H in astyle).

## Comments

The general behavior of classes, class members, functions, etc. is documented in the header files.
The .cpp files contain implementation-specific annotations.

Each header file should start with at least a history of *major* changes, such as relevant changes to the API.
There is no need to log every minor change: they are logged in the version control system.
For new files, start with the creation date.

    /**
     * History:
     * - 2018.01.01 file created
     */

If the header file contains one class, the documentation of the class is sufficient. If the header file as a more
complex structure, e.g., it lists many functions, add a brief description followed by an empty line and a longer
description (if necessary).

    /**
     * Brief description of the file content.
     *
     * Additional details, on
     * multiple lines if necessary.
     *
     * History:
     * - 2018.01.01 file created
     */

Do not indicate the author, because many files are updated by multiple people in time and details about
authorship are already available in the version control system if necessary.

Comment every class member with a comment above it.
End the comment with a full stop.

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
and time. For example, no need to document the parameter t or the return value in:

    /** Returns a string representation of the input network. */
    std::string
    to_string(
        const Network& t
    );
