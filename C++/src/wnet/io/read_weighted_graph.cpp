/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "wnet/io/read_weighted_graph.h"


namespace uu {
namespace net {

std::unique_ptr<WeightedGraph>
read_weighted_graph(
    const std::string& infile,
    const std::string& name,
    char separator
)
{
    // Read metadata
    GraphMetadata meta = read_metadata(infile, ',');
    EdgeDir dir = meta.features.is_directed?EdgeDir::DIRECTED:EdgeDir::UNDIRECTED;

    // Check metadata consistency (@todo) & create graph
    auto g = create_weighted_graph(name, dir, meta.features.allows_loops);

    // Read data (vertices, edges, attribute values)
    read_data(g.get(),  meta, infile, separator);

    return g;

}


template <>
void
read_vertex(
    WeightedGraph* g,
    const std::vector<std::string>& fields,
    const std::vector<core::Attribute>& vertex_attributes,
    size_t line_number
)
{
    if (fields.size()>1)
    {
        throw core::WrongFormatException("Line " +
                                         std::to_string(line_number) +
                                         ": Only vertex name expected");
    }

    std::string vertex_name = fields[0];

    auto vertex = g->vertices()->add(vertex_name);

    if (!vertex)
    {
        vertex = g->vertices()->get(vertex_name);
    }

    /*
     size_t attr_idx = 1;
     for (auto att: vertex_attributes)
     {
     g->vertices()->attr()->set_as_string(vertex, att.name, fields[attr_idx]);
     attr_idx++;
     }*/
}


template <>
void
read_edge(
    WeightedGraph* g,
    const std::vector<std::string>& fields,
    const std::vector<core::Attribute>& edge_attributes,
    size_t line_number
)
{
    if (fields.size()!=3)
    {
        throw core::WrongFormatException("Line " +
                                         std::to_string(line_number) +
                                         ": From and To actor names and weight must " +
                                         "be specified for each edge");
    }

    std::string from_vertex = fields[0];
    std::string to_vertex = fields[1];
    std::string weight = fields[2];

    auto vertex1 = g->vertices()->add(from_vertex);

    if (!vertex1)
    {
        vertex1 = g->vertices()->get(from_vertex);
    }

    auto vertex2 = g->vertices()->add(to_vertex);

    if (!vertex2)
    {
        vertex2 = g->vertices()->get(to_vertex);
    }

    auto edge = g->edges()->add(vertex1,vertex2);

    if (!edge)
    {
        edge = g->edges()->get(vertex1,vertex2);
        throw core::DuplicateElementException("Line " +
                                              std::to_string(line_number) +
                                              ": duplicate edge " +
                                              edge->to_string());
    }

    g->edges()->attr()->set_weight(edge, core::to_double(weight));

    /*
     size_t attr_idx = 1;
     for (auto att: edge_attributes)
     {
     g->edges()->attr()->set_as_string(edge, att.name, fields[attr_idx]);
     attr_idx++;
     }
     */
}

}
}
