/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "mnet/io/read_attributed_homogeneous_multilayer_network.h"
#include "net/io/read_attributed_simple_graph.h"


namespace uu {
namespace net {

std::unique_ptr<AttributedHomogeneousMultilayerNetwork>
read_attributed_homogeneous_multilayer_network(
    const std::string& infile,
    const std::string& name,
    char separator
)
{
    // Read metadata
    MultilayerMetadata meta = read_multilayer_metadata(infile, ',');
    //EdgeDir dir = meta.features.is_directed?EdgeDir::DIRECTED:EdgeDir::UNDIRECTED;

    // Check metadata consistency (@todo) & create graph & add attributes

    auto net = create_attributed_homogeneous_multilayer_network(name);

    for (auto attr: meta.vertex_attributes)
    {
        net->vertices()->attr()->add(attr.name, attr.type);
    }

    /*
    for (auto attr: meta.edge_attributes)
    {
        mpx->edges()->attr()->add(attr.name, attr.type);
    }
    */

    for (auto layer_attr: meta.intralayer_vertex_attributes)
    {
        std::string layer_name = layer_attr.first;

        for (auto attr: layer_attr.second)
        {
            net->layers()->get(layer_name)->vertices()->attr()->add(attr.name, attr.type);
        }
    }

    for (auto layer_attr: meta.intralayer_edge_attributes)
    {
        std::string layer_name = layer_attr.first;

        for (auto attr: layer_attr.second)
        {
            net->layers()->get(layer_name)->edges()->attr()->add(attr.name, attr.type);
        }
    }

    for (auto attr: meta.interlayer_edge_attributes)
    {
        net->interlayer_edges()->attr()->add(attr.name, attr.type);
    }

    // Read data (vertices, edges, attribute values)
    read_multilayer_data(net.get(),  meta, infile, separator);

    return net;

}


template <>
AttributedSimpleGraph*
read_layer(
    AttributedHomogeneousMultilayerNetwork* ml,
    const std::vector<std::string>& fields,
    size_t from_idx,
    size_t line_number
)
{
    std::string layer_name = fields.at(from_idx);

    auto layer = ml->layers()->get(layer_name);

    if (!layer)
    {
        auto ptr = uu::net::create_attributed_simple_graph(layer_name, uu::net::EdgeDir::UNDIRECTED);
        layer = ml->layers()->add(std::move(ptr));
    }

    return layer;
}

template <>
void
read_vertex(
    AttributedHomogeneousMultilayerNetwork* ml,
    const std::vector<std::string>& fields,
    const MultilayerMetadata& meta,
    size_t line_number
)
{
    assert_not_null(ml, "read_vertex", "ml");
    read_vertex(ml, fields, 0, line_number);
}

template <>
void
read_intralayer_vertex(
    AttributedHomogeneousMultilayerNetwork* ml,
    const std::vector<std::string>& fields,
    const MultilayerMetadata& meta,
    size_t line_number
)
{

    assert_not_null(ml, "read_intralayer_vertex", "ml");
    auto v = read_vertex(ml, fields, 0, line_number);
    auto l = read_layer<AttributedHomogeneousMultilayerNetwork, AttributedSimpleGraph>(ml, fields, 1, line_number);
    l->vertices()->add(v);
}

template <>
void
read_intralayer_edge(
    AttributedHomogeneousMultilayerNetwork* ml,
    const std::vector<std::string>& fields,
    const MultilayerMetadata& meta,
    size_t line_number
)
{
    assert_not_null(ml, "read_intralayer_edge", "ml");
    auto v1 = read_vertex(ml, fields, 0, line_number);
    auto v2 = read_vertex(ml, fields, 1, line_number);
    auto l = read_layer<AttributedHomogeneousMultilayerNetwork, AttributedSimpleGraph>(ml, fields, 2, line_number);

    l->vertices()->add(v1);
    l->vertices()->add(v2);
    l->edges()->add(v1,v2);

}


template <>
void
read_interlayer_edge(
    AttributedHomogeneousMultilayerNetwork* ml,
    const std::vector<std::string>& fields,
    const MultilayerMetadata& meta,
    size_t line_number
)
{
    assert_not_null(ml, "read_intralayer_edge", "ml");
    auto v1 = read_vertex(ml, fields, 0, line_number);
    auto l1 = read_layer<AttributedHomogeneousMultilayerNetwork, AttributedSimpleGraph>(ml, fields, 1, line_number);
    auto v2 = read_vertex(ml, fields, 2, line_number);
    auto l2 = read_layer<AttributedHomogeneousMultilayerNetwork, AttributedSimpleGraph>(ml, fields, 3, line_number);

    l1->vertices()->add(v1);
    l2->vertices()->add(v2);

    ml->interlayer_edges()->add(v1,l1,v2,l2);

}

}
}
