/**
 * This module defines functions to read/write weighted graphs from/to disk.
 *
 * This is the complete file format:
 *
 * -------------------------------------------
 * -- comment lines start with two dashes (--)
 *
 * #TYPE
 * -- Not case sensitive:
 * DIRECTED
 * -- Or: UNDIRECTED (default)
 * WEIGHTED
 * -- Or: UNWEIGHTED (default)
 * MULTI
 * -- Or: SIMPLE (default)
 * TEMPORAL
 * -- Or: STATIC (default)
 * LOOPS
 * -- Or: NO LOOPS (default)
 *
 * #VERTEX ATTRIBUTES
 * AttributeName,AttributeType
 * -- etc.
 *
 * #EDGE ATTRIBUTES
 * AttributeName,AttributeType
 * -- etc.
 *
 * #VERTICES
 * VertexName,AttributeValueList...
 * -- etc.
 *
 * #EDGES
 * VertexName,VertexName,AttributeValueList...
 * -------------------------------------------
 *
 * If #TYPE is not present, edges are by default undirected.
 *
 * If the #VERTEX ATTRIBUTES or #EDGE ATTRIBUTES sections are missing,
 * no attributes are created.
 *
 * The #VERTICES section is useful only if vertex attributes or vertices without
 * connections are present, otherwise it can be omitted.
 *
 * If no section is specified, #EDGES is the default.
 *
 * Therefore, a minimalistic undirected network file would look like this:
 * -------------------------------------------
 * Matteo,Luca
 * Matteo,Mark
 * ...
 * -------------------------------------------
 * Please notice that the AttributeValueList depends on the type of graph.
 * If the graph has special attributes, they do not need to be defined in a
 * #XXX ATTRIBUTES section. For example, if a graph is weighted, the library
 * will expect a double (representing the weight) as the first attribute of the
 * AttributeValueList.
 *
 * History:
 * - 2018.03.20 file created
 */

#ifndef UU_WNET_IO_H_
#define UU_WNET_IO_H_

#include "wnet/io/read_weighted_graph.h"

#endif
