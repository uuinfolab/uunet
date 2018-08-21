/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "net/io/read_common.h"
#include "core/exceptions/WrongParameterException.h"


namespace uu {
namespace net {

void
read_graph_type(
    const std::string& graph_type,
    GraphMetadata& meta,
    size_t line_number
)
{
    std::string feat = graph_type;
    to_upper_case(feat);

    if (feat=="MULTI")
    {
        meta.features.allows_multi_edges=true;
    }

    else if (feat=="SIMPLE")
    {
    }

    else if (feat=="DIRECTED")
    {
        meta.features.is_directed=true;
    }

    else if (feat=="UNDIRECTED")
    {
    }

    else if (feat=="WEIGHTED")
    {
        meta.features.is_weighted=true;
    }

    else if (feat=="PROBABILISTIC")
    {
        meta.features.is_probabilistic=true;
    }


    else if (feat=="UNWEIGHTED")
    {
    }

    else if (feat=="TEMPORAL")
    {
        meta.features.is_temporal=true;
    }

    else if (feat=="STATIC")
    {
    }

    else if (feat=="LOOPS")
    {
        meta.features.allows_loops=true;
    }

    else if (feat=="NO LOOPS")
    {
    }

    else
    {
        throw core::WrongParameterException("Line " +
                                            std::to_string(line_number) +
                                            ": " + graph_type);
    }
}

GraphMetadata
read_metadata(
    const std::string& infile,
    char separator
)
{

    GraphMetadata meta;

    // Set up CSV Reader

    core::CSVReader csv;
    csv.trim_fields(true);
    csv.set_field_separator(separator);
    csv.set_comment("--");

    std::string version;

    GraphIOFileSection section = GraphIOFileSection::DEFAULT;

    csv.open(infile);

    while (csv.has_next())
    {
        std::vector<std::string> fields = csv.get_next();
        std::string line = csv.get_current_raw_line();
        // remove trailing spaces
        line.erase(line.find_last_not_of(" \t")+1);
        line.erase(0,line.find_first_not_of(" \t"));

        if (line.size()==0)
        {
            continue;
        }


        if (new_section_start(line))
        {
            section = get_section(line);
            fields = csv.get_next();
            line = csv.get_current_raw_line();
            // remove trailing spaces
            line.erase(line.find_last_not_of(" \t")+1);
            line.erase(0,line.find_first_not_of(" \t"));
        }


        switch (section)
        {
        case GraphIOFileSection::VERSION:
        {
            version = read_version(line, csv.row_num());
            break;
        }

        case GraphIOFileSection::TYPE:
        {
            read_graph_type(line, meta, csv.row_num());
            break;
        }

        case GraphIOFileSection::VERTEX_ATTRIBUTES:
        {
            size_t from_idx = 0;
            core::Attribute vertex_att = read_attr_def(fields, from_idx, csv.row_num());
            meta.vertex_attributes.push_back(vertex_att);
            break;
        }

        case GraphIOFileSection::EDGE_ATTRIBUTES:
        {
            size_t from_idx = 0;
            core::Attribute edge_att = read_attr_def(fields, from_idx, csv.row_num());
            meta.edge_attributes.push_back(edge_att);
            break;
        }

        default:
            break;
        }
    }

    csv.close();
    return meta;
}


void
to_upper_case(std::string& s)
{
    /****************************/
    // C(++), I hate you...
    int (*touppercase)(int) = std::toupper;
    /****************************/
    std::transform(s.begin(),s.end(),s.begin(),touppercase);
}


bool
new_section_start(const std::string& line)
{
    if (!(line.find("#")==0))
    {
        return false;
    }

    std::string line_copy = line;
    to_upper_case(line_copy);

    if (
        line_copy=="#VERSION" ||
        line_copy=="#TYPE" ||
        line_copy=="#VERTEX ATTRIBUTES" ||
        line_copy=="#EDGE ATTRIBUTES" ||
        line_copy=="#VERTICES" ||
        line_copy=="#EDGES" ||
        // deprecated
        line_copy=="#VERTEXES" ||
        line_copy=="#ACTORS" ||
        line_copy=="#ACTOR ATTRIBUTES")

    {
        return true;
    }

    return false;
}



GraphIOFileSection
get_section(const std::string& line)
{
    std::string line_copy = line;
    to_upper_case(line_copy);

    if (line_copy=="#VERSION")
    {
        return GraphIOFileSection::VERSION;
    }

    if (line_copy=="#TYPE")
    {
        return GraphIOFileSection::TYPE;
    }

    if (line_copy=="#VERTEX ATTRIBUTES")
    {
        return GraphIOFileSection::VERTEX_ATTRIBUTES;
    }

    if (line_copy=="#EDGE ATTRIBUTES")
    {
        return GraphIOFileSection::EDGE_ATTRIBUTES;
    }

    if (line_copy=="#VERTICES")
    {
        return GraphIOFileSection::VERTICES;
    }

    if (line_copy=="#EDGES")
    {
        return GraphIOFileSection::EDGES;
    }

    // DEPRECATED
    if (line_copy=="#VERTEXES")
    {
        std::cerr << "[WARNING] usage of #VERTEXES deprecated. Use #VERTICES instead." << std::endl;
        return GraphIOFileSection::VERTICES;
    }

    if (line_copy=="#ACTORS")
    {
        std::cerr << "[WARNING] usage of #ACTORS deprecated. Use #VERTICES instead." << std::endl;
        return GraphIOFileSection::VERTICES;
    }

    if (line_copy=="#ACTOR ATTRIBUTES")
    {
        std::cerr << "[WARNING] usage of #ACTOR deprecated. Use #VERTEX instead." << std::endl;
        return GraphIOFileSection::VERTEX_ATTRIBUTES;
    }

    return GraphIOFileSection::DEFAULT; // cannot get here
}


std::string
read_version(
    const std::string& line,
    size_t line_number
)
{

    std::string version = line;

    if (version != "1.0" && version != "2.0" && version != "2")
        throw core::WrongFormatException("Line " + std::to_string(line_number) +
                                         ": invalid version number "
                                         + line);

    // standardization
    if (version=="2")
    {
        version = "2.0";
    }

    return version;
}




core::Attribute
read_attr_def(
    const std::vector<std::string>& line,
    size_t from_idx,
    size_t line_number
)
{
    if (line.size()!=2+from_idx)
        throw core::WrongFormatException("Line " + std::to_string(line_number) +
                                         ": attribute name and type expected");

    std::string attr_name = line[from_idx+0];
    std::string attr_type_name = line[from_idx+1];
    to_upper_case(attr_type_name);
    core::AttributeType attr_type;

    if (attr_type_name=="NUMERIC")
    {
        attr_type = core::AttributeType::DOUBLE;    // back compatibility
    }

    else if (attr_type_name=="DOUBLE")
    {
        attr_type = core::AttributeType::DOUBLE;
    }

    else if (attr_type_name=="INT")
    {
        attr_type = core::AttributeType::INTEGER;
    }

    else if (attr_type_name=="STRING")
    {
        attr_type = core::AttributeType::STRING;
    }

    else if (attr_type_name == "TIME")
    {
        attr_type = core::AttributeType::TIME;
    }

    else throw core::WrongFormatException("Line " + std::to_string(line_number) +
                                              ": unsupported attribute type " + line[from_idx+1]);

    return core::Attribute(attr_name,attr_type);
}


}
}

