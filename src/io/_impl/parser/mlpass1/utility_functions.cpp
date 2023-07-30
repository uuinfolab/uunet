#include "io/_impl/parser/mlpass1/utility_functions.hpp"
#include "core/utils/string.hpp"
#include "core/exceptions/WrongParameterException.hpp"
#include "core/exceptions/WrongFormatException.hpp"


namespace uu {
namespace net {
namespace parser {
namespace mlpass1 {

void
read_layer_type(
    const std::string& graph_type,
    GraphType& layer
)
{
    if (graph_type == "undirected")
        layer.is_directed = false;
    else if (graph_type == "directed")
        layer.is_directed = true;
    else if (graph_type == "loops")
        layer.allows_loops = true;
    else if (graph_type == "no loops")
        layer.allows_loops = false;
    else throw core::WrongFormatException("unsupported layer type: " + graph_type);
}


core::AttributeType
read_attr_type(
    const std::string& attr_type_name
)
{
    if (attr_type_name=="double")
    {
        return core::AttributeType::DOUBLE;
    }

    else if (attr_type_name=="integer")
    {
        return core::AttributeType::INTEGER;
    }

    else if (attr_type_name=="string")
    {
        return core::AttributeType::STRING;
    }

    else if (attr_type_name == "time")
    {
        return core::AttributeType::TIME;
    }

    else throw core::WrongFormatException("Unsupported attribute type: " + attr_type_name);

    return core::AttributeType::INTEGER; // Never here
}

/*
typename MultilayerNetwork::layer_type*
create_and_get_layer(
    MultilayerNetwork* net,
    const std::string& layer_name,
    const GraphType& layer_type
)
{
    std::string layer_name = layer_spec.at(0);

    auto dir = layer_type.is_directed ? EdgeDir::DIRECTED : EdgeDir::UNDIRECTED;
    auto loops = layer_type.allows_loops ? LoopMode::ALLOWED : LoopMode::DISALLOWED;
    auto res = net->layers()->add(layer_name, dir, loops);
    
    return res;
}
*/
/*

void
read_vertex(
    Network* g,
    const std::vector<std::string>& fields,
    const std::vector<core::Attribute>& vertex_attributes,
    size_t line_number
)
{


    if (fields.size()>1+vertex_attributes.size())
    {
        throw core::WrongFormatException("Line " +
                                         std::to_string(line_number) +
                                         ": wrong number of attributes");
    }

    auto v = read_vertex(g, fields, 0, line_number);


    read_attr_values(g->vertices()->attr(), v, vertex_attributes, fields, 1, line_number);


}



void
read_edge(
    Network* g,
    const std::vector<std::string>& fields,
    const std::vector<core::Attribute>& edge_attributes,
    size_t line_number
)
{

    if (fields.size()!=2+edge_attributes.size())
    {
        throw core::WrongFormatException("Line " +
                                         std::to_string(line_number) +
                                         ": wrong number of fields");
    }

    auto edge = read_edge(g, fields, 0, line_number);

    read_attr_values(g->edges()->attr(), edge, edge_attributes, fields, 2, line_number);

}
*/
}
}
}
}


