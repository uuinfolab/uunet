/**
 * History:
 * - 2018.03.09 file created, following a restructuring of the previous library.
 */

#include "mnet/io/read_multiplex.h"


namespace uu {
namespace net {

std::unique_ptr<MultiplexNetwork>
read_multiplex(
    const std::string& infile,
    const std::string& name,
    char separator
)
{
    // Read metadata
    MultilayerMetadata meta = read_multilayer_metadata(infile, ',');
    //EdgeDir dir = meta.features.is_directed?EdgeDir::DIRECTED:EdgeDir::UNDIRECTED;

    // Check metadata consistency (@todo) & create graph
    
    auto mpx = create_multiplex_network(name);

    // @todo create layers
    
    // Read data (vertices, edges, attribute values)
    read_multilayer_data(mpx.get(),  meta, infile, separator);

    return mpx;

}



    template <>
    void
    read_vertex(
                MultiplexNetwork* ml,
                const std::vector<std::string>& fields,
                const MultilayerMetadata& meta,
                size_t line_number
                )
    {
        assert_not_null(ml, "read_vertex", "ml");
        std::cout << "vertex: " << fields.at(0) << std::endl;
    }
    
    template <>
    void
    read_intralayer_vertex(
                           MultiplexNetwork* ml,
                           const std::vector<std::string>& fields,
                           const MultilayerMetadata& meta,
                           size_t line_number
                           )
    {
        
        assert_not_null(ml, "read_intralayer_vertex", "ml");
        std::cout << "vertex: " << fields.at(0) << "::" << fields.at(1) << std::endl;
        
    }
    
    template <>
    void
    read_intralayer_edge(
                         MultiplexNetwork* ml,
                         const std::vector<std::string>& fields,
                         const MultilayerMetadata& meta,
                         size_t line_number
                         )
    {
        assert_not_null(ml, "read_intralayer_edge", "ml");
        std::cout << "vertex: " << fields.at(0) << "," << fields.at(1) << "::" << fields.at(2) << std::endl;
        
    }
    

}
}
