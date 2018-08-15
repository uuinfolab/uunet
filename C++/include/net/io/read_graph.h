/**
 * net/io.h
 *
 * Author: Matteo Magnani <matteo.magnani@it.uu.se>
 * Created: 2017-09-26
 *
 * Methods to read/write a network from/to file.
 *
 * This is the complete file format:
 *
 * -------------------------------------------
 * -- comment lines start with two dashes (--)
 *
 * #TYPE
 * UNDIRECTED
 * -- Or: DIRECTED
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
 * ActorName,AttributeValueList...
 * -- etc.
 *
 * #EDGES
 * ActorName,ActorName,AttributeValueList...
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
 */

#ifndef UU_NET_IO_READGRAPH_H_
#define UU_NET_IO_READGRAPH_H_

#include <string>
#include <vector>
#include "core/attributes/Attribute.h"
#include "net/io/read_common.h"


namespace uu {
namespace net {

}
}


#endif
