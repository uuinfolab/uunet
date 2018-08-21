/**
 *
 *
 * History:
 * - 2018.08.17 file created.
 */

#ifndef UU_PNET_IO_READPROBABILISTICGRAPH_H_
#define UU_PNET_IO_READPROBABILISTICGRAPH_H_

#include <string>
#include <memory>
#include "pnet/datastructures/graphs/ProbabilisticGraph.h"
#include "net/io/read_common.h"

namespace uu {
namespace net {

std::unique_ptr<ProbabilisticGraph>
read_probabilistic_graph(
    const std::string& infile,
    const std::string& name,
    char separator
);

template <>
void
read_vertex(
    ProbabilisticGraph* g,
    const std::vector<std::string>& fields,
    const std::vector<core::Attribute>& vertex_attributes,
    size_t line_number
);


template <>
void
read_edge(
    ProbabilisticGraph* g,
    const std::vector<std::string>& fields,
    const std::vector<core::Attribute>& edge_attributes,
    size_t line_number
);


}
}

#endif
