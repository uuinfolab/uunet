#ifndef UU_COMMUNITY_MIMAG_H_
#define UU_COMMUNITY_MIMAG_H_

#include <memory>
#include <unordered_set>
#include <vector>
#include <queue>
#include "core/utils/math.hpp"
#include "io/read_multilayer_network.hpp"
#include "io/read_network.hpp"
#include "community/MLCPMCommunity.hpp"
#include "community/CommunityStructure.hpp"
#include "objects/MultiplexClique.hpp"


namespace uu{
namespace net{

  /**
    * Find cliques of at least size k with m edge types
    *
    *
    */
template <typename M>
std::unordered_set<std::shared_ptr<MultiplexClique<M>>>
mimag_approx(
    const M* mnet,
    size_t k,
    size_t m,
    double gamma = .5
);


/**
  * Get layer given network
  *
  *
  */
const uu::net::Network*
get_layer(
    const uu::net::MultilayerNetwork *mnet,
    int layer
);



/**
  * Vertex and it's layer -> vertex_layer
  *
  *
  */
struct vertex_layer {
    const uu::net::Vertex* vertex;
    int layer;
    const uu::net::MultilayerNetwork* mnet;
};

/**
  * Compare vertex layer
  *
  *
  */
class CompareVertex
{
  public:
    bool operator()(uu::net::vertex_layer v1, uu::net::vertex_layer v2)
    {
        int i = 0;
        int j = 0;
        auto neighbor_v1 = get_layer(v1.mnet, v1.layer)->edges()->neighbors(v1.vertex);
        auto neighbor_v2 = get_layer(v2.mnet, v2.layer)->edges()->neighbors(v2.vertex);

        for (auto v: *neighbor_v1)
        {
            i++;
        }

        for (auto v: *neighbor_v2)
        {
            j++;
        }

        if (i < j)
        {
            return true;
        }

        if (j == i)
        {
            return true;
        }

        return false;
    }
};

/**
  * subtree
  *
  *
  */
struct subtree {
    std::vector<uu::net::vertex_layer> vertex_set; // TODO: - fix struct since vertex_set not needed anymore
    int active_dimensions; // TODO: update active dimensions if priority is changed
    std::vector<const uu::net::Vertex*> list_of_candidates; // TODO:  change priorities
    bool is_cluster = false;
};


/**
  * Compare subtree
  *
  *
  */
class CompareSubtree
{
  public:
    bool operator()(uu::net::subtree s1, uu::net::subtree s2)
    {

        // if subtree 1 is a cluster -> higher priority

        if (s1.is_cluster && !s2.is_cluster)
        {
            return true;
        }

        int i = 0;
        int j = 0;
        auto neighbor_v1 = get_layer(s1.vertex_set.front().mnet, s1.vertex_set.front().layer)->edges()->neighbors(s1.vertex_set.front().vertex);
        auto neighbor_v2 = get_layer(s2.vertex_set.front().mnet, s2.vertex_set.front().layer)->edges()->neighbors(s2.vertex_set.front().vertex);

        for (auto v: *neighbor_v1)
        {
            i++;
        }

        for (auto v: *neighbor_v2)
        {
            j++;
        }

        // if subtree 1 & subtree 2 are clusters, most neighbors -> higher priority
        if (s1.is_cluster && s2.is_cluster && i < j)
        {
            return true;
        }

        if (j < i)
        {
            return true;
        }

        return false;
    }
};




/**
 * Create subtree
 *
 * @
 */

uu::net::subtree
create_subtree(
    uu::net::vertex_layer current_vertex,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers
);






/**
 * Adds candidate vectors to list of candidates
 *
 * @
 */


std::vector<const uu::net::Vertex*>
//std::priority_queue<uu::net::vertex_layer, std::vector<uu::net::vertex_layer>, CompareVertex>
candidate_set(
    uu::net::vertex_layer vertex,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers
);




/**
 * Creates a cluster/ clique
 * returns a multiplex clique
 * if clique then sets the first vertex is_cluster field to true
 */


template <typename M>
std::tuple<std::shared_ptr<MultiplexClique<M>>,bool,int>
find_clusters(
    const M* mnet,
    uu::net::subtree root,
    std::vector<std::vector<uu::net::vertex_layer>>,
    size_t k,
    size_t m,
    double gamma
);



/**
  * Expands the represented set O by one neighbouring vertex u
  * new clusters and subtrees added to the queue,
  * candidate sets are reduced using pruning techniques
  */
std::vector<uu::net::subtree>
expandSubtree(
    uu::net::subtree root,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers,
    std::vector<const uu::net::Vertex*> expanded_vertices,
    int layer_count,
    int vertex_count
);

/**
  * Is a cluster redundant?
  *
  *
  */

template <typename M>
bool
isRedundantCluster(
    int subgraph_size,
    std::shared_ptr<MultiplexClique<M>> multiplex_clique,
    std::unordered_set<std::shared_ptr<MultiplexClique<M>>> result
);




/**
 * Determines if an object is a cluster
 *
 *
 */

 bool
 isCluster(
     uu::net::subtree cluster_candidate
 );


/**
  * Determines if 0.5 quasi clique
  *
  *
  */

template <typename M>
double
average_degree_all_layers(
    const M* mnet,
    std::vector<int> layers_root_exist_in,
    std::vector<const uu::net::Vertex*> subgraph
);




/**
  * Determines if a gamma-quasi clique
  *
  *
  */

bool
isQuasiClique(
    double number_of_layers,
    double average_degree,
    double gamma = .5
);


/**
 * Determines the most promising subtree out of two given
 *
 */


bool
most_promising_subtree(
  uu::net::subtree a,
  uu::net::subtree b,
  std::vector<const uu::net::Vertex*> expanded_vertices
);



/**
 * Determines a vertices vertex_layer
 *
 */

int
neighboring_vertex_layer(
    uu::net::subtree root,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers,
    const uu::net::Vertex* vertex
);



/**
 * Check if vertex has been expanded
 *
 */
bool
has_been_expanded(
    const uu::net::Vertex* vertex,
    std::vector<const uu::net::Vertex*> expanded_vertices
);


}
}




#include "mimag_approx.ipp"

#endif
