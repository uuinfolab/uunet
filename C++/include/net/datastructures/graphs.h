/**
 * This module defines the main types of graphs (simple, multi, attributed, ...),
 * with functions to create them.
 *
 * To define a new graph:
 * (1) Define the graph in net/datastructures/graphs. This must contain
 * the typedef of the graph and a create_xxx_graph function (see for example
 * include/net/graphs/WeightedGraph.h).
 * (2) Define the create_xxx_graph function (see for example
 * src/net/datastructures/graphs/create_weighted_graph.cpp).
 * (3) Write the corresponding unit test (see for example
 * test/net/datastructures/graphs/WeigthedGraph_test.cpp).
 *
 * If you need a new type of store or of attributes, you must first define it (see
 * for example include/net/datastructures/stores/Weighted.h).
 *
 * Finally, you may want to create a read_xxx_graph function. See for example
 * include/net/io/read_weigthed_graph.h.
 *
 * History:
 * - 2018.03.20 file created
 */

#ifndef UU_NET_DATASTRUCTURES_GRAPHS_H_
#define UU_NET_DATASTRUCTURES_GRAPHS_H_

#include "net/datastructures/graphs/Graph.h"
#include "net/datastructures/graphs/SimpleGraph.h"
#include "net/datastructures/graphs/MultiGraph.h"
#include "net/datastructures/graphs/WeightedGraph.h"

#endif
