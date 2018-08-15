/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#ifndef UU_NET_IO_READCOMMON_H_
#define UU_NET_IO_READCOMMON_H_

#include <string>
#include <vector>
#include "core/attributes/Attribute.h"
#include "core/attributes/AttributeStore.h"
#include "core/utils/CSVReader.h"
#include "core/datastructures/objects/Object.h"
#include "net/datastructures/graphs/Graph.h"
#include "net/datastructures/objects/Vertex.h"
#include "net/datastructures/objects/Edge.h"
#include "net/io/GraphMetadata.h"
#include "net/io/GraphIOFileSection.h"

namespace uu {
namespace net {

void
to_upper_case(std::string& s);

/** Default edge directionality (undirected). */
const EdgeDir kDEFAULT_EDGE_DIRECTIONALITY = EdgeDir::UNDIRECTED;

/**
 * Checks if the input line indicates the start of a new section.
 */
bool
new_section_start(
    const std::string& line
);

/**
 * Returns the new section starting on this input line.
 */
GraphIOFileSection
get_section(
    const std::string& line
);


    GraphMetadata
    read_metadata(
         const std::string& infile,
         char separator
        );

    
    template <typename G>
    void
    read_data(
               G* g,
               GraphMetadata meta,
               const std::string& infile,
               char separator
               )
    {
        
        // PASS 2: read the graph data
        
        core::CSVReader csv;
        csv.trim_fields(true);
        csv.set_field_separator(separator);
        csv.set_comment("--");
        csv.open(infile);
        
        GraphIOFileSection section = GraphIOFileSection::EDGES;
        
        while (csv.has_next())
        {
            std::vector<std::string> fields = csv.get_next();
            std::string line = csv.get_current_raw_line();
            // remove trailing spaces
            line.erase(line.find_last_not_of(" \t")+1);
            line.erase(0,line.find_first_not_of(" \t"));
            if (line.size()==0)
                continue;
            
            
            // if new section starts here, set the current section and proceed
            if (new_section_start(line))
            {
                section = get_section(line);
                fields = csv.get_next();
            }
            
            switch (section)
            {
                case GraphIOFileSection::VERTICES:
                {
                    read_vertex(g, fields, meta.vertex_attributes, csv.row_num());
                    break;
                }
                    
                case GraphIOFileSection::EDGES:
                {
                    read_edge(g, fields, meta.edge_attributes, csv.row_num());
                    break;
                }
                    
                default:
                    break;
            }
        }

    }

/**
 * Utility function to read ...
 * @param
 * @param fields a vector of strings where the attribute values are stores
 * @param line_number current line in the input file, for error management
 */
void
read_version(
    const std::vector<std::string>& fields,
    std::string& version,
    size_t line_number
);


/**
 * Utility function to read ...
 * @param graph_type...
 * @param line_number current line in the input file, for error management
 */
void
read_graph_type(
    const std::string& graph_type,
                GraphMetadata& meta,
    size_t line_number
);

/**
 * Utility function to read ...
 * @param
 * @param fields a vector of strings where the attribute values are stores
 * @param line_number current line in the input file, for error management
 */
void
get_directionality(
    const std::vector<GraphType>& graph_type,
    EdgeDir& dir
);

/**
 * Utility function to read attribute definitions.
 * @param store attribute store where the attribute values are saved
 * @param id identifier of the object for which the attributes should be read
 * @param attr_types vector with the expected types of attributes
 * @param attr_names vector with the expected names of attributes
 * @param line a vector of strings where the attribute values are stores
 * @param idx the index of the first attribute value in the line vector
 * @param line_number current line in the input file, for error management
 */
core::Attribute
read_attr_def(
              const std::vector<std::string>& line,
              size_t from_idx,
              size_t line_number);

/**
 * Utility function to write attribute definitions.
 * @param store attribute store where the attribute values are saved
 * @param id identifier of the object for which the attributes should be read
 * @param attr_types vector with the expected types of attributes
 * @param attr_names vector with the expected names of attributes
 * @param line a vector of strings where the attribute values are stores
 * @param idx the index of the first attribute value in the line vector
 * @param line_number current line in the input file, for error management
 *
void
write_attr_defs(std::ofstream& outfile,
                char separator,
                const core::AttributeStoreSharedPtr& store);

**
 * Utility function to read attribute values.
 * @param outfile output file
 * @param separator character to separate fields
 * @param store attribute store where the attribute values are saved
 *
void
read_attr_values(const core::AttributeStoreSharedPtr& store,
                 core::ObjectId id,
                 const std::vector<core::AttributeSharedPtr>& attributes,
                 const std::vector<std::string>& line,
                 size_t idx,
                 size_t line_number);

**
 * Utility function to write attribute values.
 * @param outfile output file
 * @param separator character to separate fields
 * @param store attribute store where the attribute values are saved
 * @param id identifier of the object for which the attributes should be written
 *
void
write_attr_values(
    std::ofstream& outfile,
    char separator,
    const core::AttributeStoreSharedPtr& store,
    core::ObjectId id);

 */
    
    
template <typename G>
void
read_vertex(
    G* g,
            const std::vector<std::string>& fields,
            const std::vector<core::Attribute>& vertex_attributes,
            size_t line_number
            );


template <typename G>
void
read_edge(
    G* g,
          const std::vector<std::string>& fields,
          const std::vector<core::Attribute>& edge_attributes,
          size_t line_number
          );



template <typename G>
void
read_vertex(
    G* g,
    const std::vector<std::string>& fields,
    const std::vector<core::Attribute>& vertex_attributes,
    size_t line_number
)
{
    throw core::OperationNotSupportedException("Graph type not supported (IO)");
}


template <typename G>
void
read_edge(
          G* g,
          const std::vector<std::string>& fields,
          const std::vector<core::Attribute>& edge_attributes,
          size_t line_number
          )
{
    throw core::OperationNotSupportedException("Graph type not supported (IO)");
}

/*
template <typename OT>
void
read_attributes(int from_idx, std::shared_ptr<AttributeStore<OT> >& as, std::shared_ptr<OT>& v, const std::vector<std::string>& fields, const std::vector<core::Attribute>& attributes,
                size_t line_number)
{
    int idx = from_idx;

    if (from_idx+attributes.size()>fields.size())
        throw core::WrongFormatException("Line " +
                                         std::to_string(line_number) +
                                         ": not enough attribute values");

    for (core::Attribute attribute: attributes)
    {
        as->set_as_string(attribute.name(),v,fields[idx]);
        idx++;
    }
}

template <typename OT>
void
read_attributes(int from_idx, std::shared_ptr<TemporalAttributeStore<OT> >& as, std::shared_ptr<OT>& v, const std::vector<std::string>& fields, const std::vector<core::Attribute>& attributes,
                size_t line_number)
{

    int idx = from_idx;

    if (from_idx+attributes.size()>fields.size())
        throw core::WrongFormatException("Line " +
                                         std::to_string(line_number) +
                                         ": not enough attribute values");

    for (core::Attribute attribute: attributes)
    {
        as->set_as_string(attribute.name(),v,fields[idx]);
        idx++;
    }
}
*/

}
}

#endif