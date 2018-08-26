#include "mnet/io/read_common.h"
#include "net/io/read_common.h"
//#include "core/exceptions.h"

//#include <algorithm>
//#include <cctype>
#include <iostream>
//#include <vector>

namespace uu {
namespace net {

/*
void
to_upper_case2(std::string& s)
{
/***************************
// C(++), I hate you...
int (*touppercase)(int) = std::toupper;
/***************************
std::transform(s.begin(),s.end(),s.begin(),touppercase);
}*/

bool
new_multilayer_section_start(const std::string& line)
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
        line_copy=="#LAYERS" ||
        line_copy=="#VERTICES" ||
        line_copy=="#INTRALAYER VERTICES" ||
        line_copy=="#INTRALAYER EDGES" ||
        line_copy=="#INTERLAYER EDGES" ||
        // alternative for: #INTRALAYER EDGES
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

MultilayerIOFileSection
get_multilayer_section(
    const std::string& line
)
{
    std::string line_copy = line;
    to_upper_case(line_copy);

    if (line_copy=="#VERSION")
    {
        return MultilayerIOFileSection::VERSION;
    }

    if (line_copy=="#TYPE")
    {
        return MultilayerIOFileSection::TYPE;
    }

    if (line_copy=="#VERTEX ATTRIBUTES")
    {
        return MultilayerIOFileSection::VERTEX_ATTRIBUTES;
    }

    if (line_copy=="#EDGE ATTRIBUTES")
    {
        return MultilayerIOFileSection::EDGE_ATTRIBUTES;
    }

    if (line_copy=="#LAYERS")
    {
        return MultilayerIOFileSection::LAYERS;
    }

    if (line_copy=="#VERTICES")
    {
        return MultilayerIOFileSection::VERTICES;
    }

    if (line_copy=="#INTRALAYER VERTICES")
    {
        return MultilayerIOFileSection::INTRALAYER_VERTICES;
    }

    if (line_copy=="#EDGES" || line_copy=="#INTRALAYER EDGES")
    {
        return MultilayerIOFileSection::INTRALAYER_EDGES;
    }

    if (line_copy=="#INTERLAYER EDGES")
    {
        return MultilayerIOFileSection::INTERLAYER_EDGES;
    }

    // DEPRECATED
    if (line_copy=="#VERTEXES")
    {
        std::cerr << "[WARNING] usage of #VERTEXES deprecated. Use #INTRALAYER VERTICES instead." << std::endl;
        return MultilayerIOFileSection::INTRALAYER_VERTICES;
    }

    if (line_copy=="#ACTORS")
    {
        std::cerr << "[WARNING] usage of #ACTORS deprecated. Use #VERTICES instead." << std::endl;
        return MultilayerIOFileSection::VERTICES;
    }

    if (line_copy=="#ACTOR ATTRIBUTES")
    {
        std::cerr << "[WARNING] usage of #ACTOR deprecated. Use #VERTEX instead." << std::endl;
        return MultilayerIOFileSection::VERTEX_ATTRIBUTES;
    }

    return MultilayerIOFileSection::DEFAULT; // cannot get here
}


/*

MultilayerMetadata
read_multilayer_metadata(
              const std::string& infile,
              char separator
              )
{

    MultilayerMetadata meta;

        // Set up CSV Reader

    core::CSVReader csv;
    csv.trim_fields(true);
    csv.set_field_separator(separator);
    csv.set_comment("--");

    std::string version;

    MultilayerIOFileSection section = MultilayerIOFileSection::DEFAULT;

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
            case MultilayerIOFileSection::VERSION:
            {
                version = read_version(line, csv.row_num());
                break;
            }

            case MultilayerIOFileSection::TYPE:
            {
                read_graph_type(line, meta, csv.row_num());
                break;
            }

            case MultilayerIOFileSection::VERTEX_ATTRIBUTES:
            {
                /*
                size_t from_idx = 0;
                core::Attribute vertex_att = read_attr_def(fields, from_idx, csv.row_num());
                meta.vertex_attributes.push_back(vertex_att);
                 *  /
                break;
            }

            case MultilayerIOFileSection::EDGE_ATTRIBUTES:
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
}*/

}
}
