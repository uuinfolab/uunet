#ifndef PARSER_EXAMPLE_PARSER_HPP
#define PARSER_EXAMPLE_PARSER_HPP

#include "io/_impl/parser/metadata_ml/actions.hpp"
#include "io/_impl/parser/metadata_ml/grammar.hpp"

#include "io/_impl/MultilayerMetadata.hpp"

namespace uu {
namespace net {
namespace parser {
namespace metadata_ml {

bool
parse(
      std::string const& file_name,
      MultilayerMetadata& meta);

}
}
}
}

#endif
