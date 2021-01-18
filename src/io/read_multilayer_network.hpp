#ifndef UU_IO_READMULTILAYERNETWORK_H_
#define UU_IO_READMULTILAYERNETWORK_H_

#include <string>
#include <memory>
#include "networks/MultilayerNetwork2.hpp"
#include "io/_impl/read_ml_common.hpp"

namespace uu {
namespace net {

std::unique_ptr<MultilayerNetwork2>
read_multilayer_network(
    const std::string& infile,
    const std::string& name,
    char separator,
    bool align = false
);


template <>
Network2*
read_layer(
    MultilayerNetwork2* ml,
    const std::vector<std::string>& fields,
    size_t from_idx,
    size_t line_number
);

template <>
void
read_vertex(
    MultilayerNetwork2* ml,
    const std::vector<std::string>& fields,
    const MultilayerMetadata& meta,
    size_t line_number
);

template <>
void
read_intralayer_vertex(
    MultilayerNetwork2* ml,
    const std::vector<std::string>& fields,
    const MultilayerMetadata& meta,
    size_t line_number
);

template <>
void
read_intralayer_edge(
    MultilayerNetwork2* ml,
    const std::vector<std::string>& fields,
    const MultilayerMetadata& meta,
    size_t line_number
);


template <>
void
read_interlayer_edge(
    MultilayerNetwork2* ml,
    const std::vector<std::string>& fields,
    const MultilayerMetadata& meta,
    size_t line_number
);

}
}

#endif
