#include "io/_impl/parser/metadata_ml/parser.hpp"

#include <boost/spirit/include/support_multi_pass.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>


namespace uu {
namespace net {
namespace parser {
namespace metadata_ml {

bool
parse(
    std::string const& file_name,
    MultilayerMetadata& meta)
{
    std::ifstream fin(file_name);
    
    if (!fin.is_open())
    {
        std::cout << "failed to open " << file_name << std::endl;
        exit(-1);
    }
    
    fin.unsetf(std::ios::skipws);
    
    typedef std::istreambuf_iterator<char> base_iterator_type;
    typedef boost::spirit::multi_pass<base_iterator_type> multipass_iterator_type;
    
    multipass_iterator_type iter =
    boost::spirit::make_default_multi_pass(base_iterator_type(fin));
    multipass_iterator_type end = boost::spirit::make_default_multi_pass(base_iterator_type());
    
    using boost::spirit::x3::ascii::space;
    
    using boost::spirit::x3::with;
    using boost::spirit::x3::error_handler_tag;
    using error_handler_type = boost::spirit::x3::error_handler<multipass_iterator_type>;
    
    // Our error handler
    error_handler_type error_handler(iter, end, std::cerr);
     
    auto const parser_err =
    with<parser::metadata_ml::data>(std::ref(meta))
    [
        with<error_handler_tag>(std::ref(error_handler))
        [
            parser::metadata_ml::start
        ]
    ];
    
    bool r = parse(iter, end, parser_err);
    
    return (r && iter == end);
}

}
}
}
}

