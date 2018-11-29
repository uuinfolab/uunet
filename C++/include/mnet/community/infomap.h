#ifndef UU_MNET_COMMUNITY_INFOMAP_H_
#define UU_MNET_COMMUNITY_INFOMAP_H_

#ifndef NS_INFOMAP
#define NS_INFOMAP
#endif

//#include "infomap.h"
#include <cstddef> // to prevent '::max_align_t' has not been declared error
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include "io/Config.h"
#include "infomap/InfomapContext.h"
#include "core/exceptions/ExternalLibException.h"
#include "mnet/community/infomap_utils.h"
#include "mnet/community/VertexLayerCommunity.h"
#include "net/community/CommunityStructure.h"

namespace uu {
namespace net {

/*  */
template <typename M>
std::unique_ptr<CommunityStructure<VertexLayerCommunity<const typename M::layer_type>>>
infomap(const M* net,
        bool overlapping=false,
        bool directed=false,
        bool include_self_links=true
       );



template <typename M>
std::unique_ptr<CommunityStructure<VertexLayerCommunity<const typename M::layer_type>>>
infomap(const M* net,
        bool overlapping,
        bool directed,
        bool include_self_links
       )
{

    try
    {

        // configure infomap

        infomap::Config config;
        config.inputFormat = "multiplex";
        config.printClu = true;
        config.zeroBasedNodeNumbers = false;
        config.silent = true;

        if (!overlapping)
        {
            config.hardPartitions = true;
        }

        if (directed)
        {
            config.directed = true;
        }

        if (!include_self_links)
        {
            config.includeSelfLinks = false;
        }

        config.adaptDefaults();

        //std::vector<infomap::ParsedOption> parsedFlags =
        //infomap::getConfig(config, ext_flags, true);

        /*for (auto o: parsedFlags)
        {
            std::cout << o << std::endl;
        }*/


        // execute infomap

        infomap::MultiplexNetwork network(config);

        multinet_to_infomap(net, network);


        multinet_to_infomap(net, "dummy.net");

        infomap::HierarchicalNetwork resultNetwork(config);

        infomap::InfomapContext context(config);

        context.getInfomap()->run(network, resultNetwork);

        resultNetwork.writeClu("dummy");

        return to_communities(net, resultNetwork);
    }

    catch (std::exception& e)
    {
        throw core::ExternalLibException(std::string(e.what()));
    }

    return nullptr;

}


}
}

#endif
