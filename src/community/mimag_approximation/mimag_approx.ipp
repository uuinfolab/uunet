#include <vector>
#include <iostream>
#include <queue>
#include <typeinfo>
#include "measures/degree.hpp"
#include "operations/subgraph.hpp" // vertex_induced_subgraph
#include "utils/summary.hpp" // summary_short
#include <tuple>
#include <algorithm>


namespace uu{
namespace net{


/**
  * This function gets a layer (network)
  * when given a multilayer network
  *
  */

const uu::net::Network*
get_layer(
    const uu::net::MultilayerNetwork *mnet,
    int layer
)
{
    std::vector<const uu::net::Network*> list_of_layers;
    for (auto l: *mnet->layers())
    {
        list_of_layers.push_back(l);
    }
    return list_of_layers[layer];
}



/**
 * This function finds quasi-cliques in multi-layer networks
 * using an approximation of the best first algorithm MiMAG
 *
 */

template <typename M>
std::unordered_set<std::shared_ptr<MultiplexClique<M>>>
mimag_approx(
    const M* mnet,
    size_t k,
    size_t m
)
{
    // Step 1: create an empty result set
    std::unordered_set<std::shared_ptr<MultiplexClique<M>>> result;
    //auto result = std::make_unique<CommunityStructure<M>>();

    // Step 2: create queue of clusters and subtrees, initially only with root node

    std::priority_queue<uu::net::subtree, std::vector<uu::net::subtree>, CompareSubtree> queue_of_subtrees;

    // create root node for start of traversal
    uu::net::subtree root;

    // TODO: change to list of priority queues

    // list of vertices , i.e., vertex_layers
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers;

    // TODO: fix better vector less


    std::vector<std::priority_queue<uu::net::vertex_layer, std::vector<uu::net::vertex_layer>, CompareVertex>> ordered_list_of_vertex_layers;
    // create list of vertices elements
    int i = 0;
    for (auto l: *mnet->layers())
    {
      std::priority_queue<uu::net::vertex_layer, std::vector<uu::net::vertex_layer>, CompareVertex> row;

      uu::net::vertex_layer vertex;
      vertex.layer = i;
      i++;
      for (auto v: *l->vertices())
      {
        vertex.vertex = v;
        vertex.mnet = mnet;
        row.push(vertex);
      }
      ordered_list_of_vertex_layers.push_back(row);
    }

    for(int k = 0; k < ordered_list_of_vertex_layers.size(); k++){
        // extract from priority queue
        std::priority_queue<uu::net::vertex_layer, std::vector<uu::net::vertex_layer>, CompareVertex> vl_pq = ordered_list_of_vertex_layers[k];
        std::vector<uu::net::vertex_layer> row;
        while(vl_pq.size()!= 0)
        {
            row.push_back(vl_pq.top());
            vl_pq.pop();
        }

        list_of_vertex_layers.push_back(row);
    }



    // if subtree is empty and expand function uses the last layer and vertex then empty
    int vertex_layer_last_layer = list_of_vertex_layers.size()-1;
    int vertex_layer_last_index = list_of_vertex_layers[vertex_layer_last_layer].size();

    // add elements to root node
    root.vertex_set.push_back(list_of_vertex_layers[0][0]);
    root.active_dimensions = mnet->layers()->size();
    root.list_of_candidates = candidate_set(root.vertex_set.front(), list_of_vertex_layers);



    // add root node to queue of clusters and subtrees, i.e., the combined priority queue
    queue_of_subtrees.push(root);

    int vertex_count = 1;
    int layer_count = 0;

    // list of already expanded vertices

    std::vector<const uu::net::Vertex*> expanded_vertices;

    // Step 3: starting at root node, while queue is not empty, find clusters
    // using a best first search algorithm based on a quality function (starting at root node)
    while (list_of_vertex_layers.size()!= 0)
    {
        if (queue_of_subtrees.size()!=0)
        {

            // Step 4: select first object
            auto subtree_to_be_processed = queue_of_subtrees.top();
            queue_of_subtrees.pop();
            std::tuple<std::shared_ptr<MultiplexClique<M>>,bool,int> clique = find_clusters(mnet,subtree_to_be_processed,list_of_vertex_layers, k, m);
            std::shared_ptr<MultiplexClique<M>> multiplex_clique = std::get<0>(clique); //  result.insert(multiplex_clique);
            subtree_to_be_processed.is_cluster = std::get<1>(clique);

            // Step 5: if object is cluster

            //subtree_to_be_processed.is_cluster = true;
            if (isCluster(subtree_to_be_processed))
            {
                if (!isRedundantCluster(std::get<2>(clique), multiplex_clique, result))
                {
                    result.insert(multiplex_clique);
                    expanded_vertices.push_back(subtree_to_be_processed.vertex_set[0].vertex);
                }
            }
            if (queue_of_subtrees.size()==0)
            {

                std::vector<uu::net::subtree> new_candidates = expandSubtree(subtree_to_be_processed, list_of_vertex_layers, expanded_vertices, layer_count , vertex_count);
                for (uu::net::subtree x: new_candidates)
                {
                    queue_of_subtrees.push(x);
                }
                if (vertex_count < list_of_vertex_layers[layer_count].size()-1)
                {
                    vertex_count ++;
                }
                if (vertex_count == list_of_vertex_layers[layer_count].size()-1)
                {
                    if (layer_count < list_of_vertex_layers.size()-1)
                    {
                        layer_count += 1;
                        vertex_count = 0;
                    }
                    else
                    {
                        list_of_vertex_layers.clear();
                    }
                }

            }
        }

        else // Step 7: else object is subtree
        {

            // else start traversal at next branch
            uu::net::subtree new_subtree_branch= create_subtree(list_of_vertex_layers[layer_count][vertex_count], list_of_vertex_layers);
            queue_of_subtrees.push(new_subtree_branch);
            if (vertex_count < list_of_vertex_layers[layer_count].size()-1)
            {
                vertex_count++;
            }
            if (vertex_count == list_of_vertex_layers[layer_count].size()-1)
            {
                if (layer_count < list_of_vertex_layers.size()-1)
                {
                    layer_count +=1;
                    vertex_count = 0;
                }
                else
                {
                    list_of_vertex_layers.clear();
                }
            }
        }
      }

    // Step 11 -> return the result set
    //std::cout << layer_count << std::endl;

    //std::cout << result.size() << std::endl;
    return result;

}


/**
 * if cluster is found - add cluster to variable and update the orig
 * subtree field isCluster to true
 * @
 */

template <typename M>
std::tuple<std::shared_ptr<MultiplexClique<M>>,bool, int>
find_clusters(
    const M*mnet,
    uu::net::subtree root,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers,
    size_t k,
    size_t m
)
{
    // result
    std::shared_ptr<MultiplexClique<M>> result;

    // layers current root exists in
    std::vector<int> layers_root_exist_in;

    // neighbors of root that exist in same max layers
    std::vector<const uu::net::Vertex*> subgraph;

    // add the vertex being processed to final set
    subgraph.push_back(root.vertex_set.front().vertex);

    // get layers root is in
    auto v = root.vertex_set.front().vertex;
    for (int i = 0; i < list_of_vertex_layers.size(); i++)
    {
        if (get_layer(mnet, i)->vertices()->contains(v))
        {
            layers_root_exist_in.push_back(i);


        }
    }

    // if for every layer root exists in, a neighbor exists, add it to result set
    if (layers_root_exist_in.size() >=m)
    {
      for (auto v: root.list_of_candidates)
      {
        int count = 0;

        for (int j =0; j < layers_root_exist_in.size(); j++)
        {
            if (get_layer(mnet, layers_root_exist_in[j])->vertices()->contains(v))
            {
                count++;
            }
        }
        if (count == layers_root_exist_in.size())
        {
            subgraph.push_back(v);
        }
      }
    }


    // if subgraph contains at least k vertices which exist in at least m layers
    // and quasi clique
    if ((subgraph.size() >= k) && isQuasiClique(subgraph.size(), average_degree_all_layers(mnet, layers_root_exist_in, subgraph)))
    {
        // create multiplex clique
        std::unordered_set<const Vertex*> new_actors;
        std::unordered_set<const typename M::layer_type*> new_layers;


        for (int i = 0; i < subgraph.size(); i++)
        {
            new_actors.insert(subgraph[i]);
        }

        for (int i = 0; i < layers_root_exist_in.size(); i++)
        {
            new_layers.insert(get_layer(mnet,layers_root_exist_in[i]));
        }

        result = std::make_shared<MultiplexClique<M>>(new_actors,new_layers);

        return std::make_tuple(result, true, subgraph.size());
        //return result;
    }
    return std::make_tuple(result, false, 0);
    //return result;

}


/**
 * Create subtree
 * next subtree is the result of this funciton "after searching root, then create_subtree using
 * a vertex from the candidate set and this function"
 */

uu::net::subtree
create_subtree(
    uu::net::vertex_layer current_vertex,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers
)
{
    uu::net::subtree subtree;
    subtree.vertex_set.push_back(current_vertex);
    subtree.active_dimensions = current_vertex.mnet->layers()->size();
    subtree.list_of_candidates = candidate_set(current_vertex, list_of_vertex_layers);
    subtree.is_cluster = false;

    return subtree;
}




/**
 * Adds candidate vectors to list of candidates
 *
 * @
 */

//std::priority_queue<uu::net::vertex_layer, std::vector<uu::net::vertex_layer>, CompareVertex>
std::vector<const uu::net::Vertex*>
candidate_set(
    uu::net::vertex_layer vertex,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers
)
{
    // result
    std::priority_queue<uu::net::vertex_layer, std::vector<uu::net::vertex_layer>, CompareVertex> result;
    // layer
    int layer = vertex.layer;
    // neighbors of root
    auto neigh = get_layer(vertex.mnet, vertex.layer)->edges()->neighbors(vertex.vertex);
    // neighbors in vector for traversal
    std::vector<const uu::net::Vertex*> vertices;

    // add to vector for traversal
    for (auto v: *neigh)
    {
        vertices.push_back(v);
    }
    // TODO: make efficient

    // list_of_vertex_layers[layer].erase(list_of_vertex_layers[layer].begin()+3); // deletes a vertex_layer

    for (int i = 0; i < list_of_vertex_layers[layer].size(); i++)
    {
        for (int j = 0; j < vertices.size(); j++)
        {
            if (list_of_vertex_layers[layer][i].vertex == vertices[j])
            {
              result.push(list_of_vertex_layers[layer][i]);
              vertices.erase(vertices.begin());
            }
        }
    }

    std::vector<const uu::net::Vertex*> candidate_list;

    while (result.size()!=0)
    {
        auto x = result.top().vertex;
        candidate_list.push_back(x);
        result.pop();
    }

    return candidate_list;
}

/**
 * Determines average degree across all layers
 *
 * @
 */


template <typename M>
double
average_degree_all_layers(
    const M* mnet,
    std::vector<int> layers_root_exist_in,
    std::vector<const uu::net::Vertex*> subgraph
)
{
    double degree_in_layers = 0;
    double average_degree_across_all_layers = 0;
    for (int i = 0; i < layers_root_exist_in.size(); i++)
    {
        auto layer = get_layer(mnet, layers_root_exist_in[i]);
        auto v_subgraph = uu::net::vertex_induced_subgraph(layer, subgraph.begin(), subgraph.end());
        auto avg_deg = uu::net::average_degree(v_subgraph.get());
        degree_in_layers = degree_in_layers + avg_deg;

    }
    average_degree_across_all_layers = (degree_in_layers / layers_root_exist_in.size());
    return average_degree_across_all_layers;
}


/**
 * Determines if a quasi_clique
 *
 * @
 */

bool
isQuasiClique(
  double number_of_layers,
  double average_degree
)
{
    int x = 0.5*(number_of_layers-1);

    if (average_degree >= x)
    {
        return true;
    }
    return false;
}


/**
 * Determines if a subtree is a cluster
 *
 * @
 */


bool
isCluster(
    uu::net::subtree cluster_candidate
)
{
    if (cluster_candidate.is_cluster == true)
    {
        return true;
    }
    return false;
};



/**
 * check if redundant
 *
 * @
 */

template <typename M>
bool
isRedundantCluster(
    int subgraph_size,
    std::shared_ptr<MultiplexClique<M>> multiplex_clique,
    std::unordered_set<std::shared_ptr<MultiplexClique<M>>> result
)
{
    int result_set_size = result.size();
    // if result set is empty add first clique
    if (result_set_size == 0)
    {
        for (auto v :multiplex_clique->actors)
        {
            std::cout << *v << std::endl;

        }
        return false;
    }

    std::vector<const uu::net::Vertex*> new_actors;
    std::vector<const uu::net::Network*> new_layers;

    for (auto v: multiplex_clique->actors)
    {
        new_actors.push_back(v);
    }

    for (auto l: multiplex_clique->layers)
    {
        new_layers.push_back(l);
    }

    //std::cout << "size of new clique: " << new_actors.size() << std::endl;
    // if new clique is equal to any clique in the result set then disregard
    for (std::shared_ptr<MultiplexClique<M>> c: result)
    {


        // if layers are the same , then delete if smaller
        /*
        if( (c->layers.size() == new_layers.size()) && (new_actors.size() < c->actors.size()))
        {


          std::vector<const uu::net::Network*> existing_layers;
          for (auto l: c->layers)
          {
              existing_layers.push_back(l);
          }

          std::vector<const uu::net::Vertex*> existing_actors;
          for (auto v: c->actors)
          {
              existing_actors.push_back(v);
          }


          if(existing_layers == new_layers)
          {
              std::cout << "same layers" << std::endl;
              int count = 0;

              for (int i = 0; i < new_actors.size(); i++)
              {
                  if (std::find(existing_actors.begin(), existing_actors.end(), new_actors[i]) != existing_actors.end())
                  {
                    count++;
                  }

                  if (count == new_actors.size())
                  {
                      std::cout << "new actors size : " << new_actors.size() << std::endl;

                      std::cout << "plz man" << std::endl;
                      return true;
                  }
              }
              count = 0;
          }

        }
        */



        // if same size check if equal
        if (c->actors.size() == new_actors.size() && c->layers.size() == new_layers.size())
        {
            std::vector<const uu::net::Vertex*> existing_actors;
            std::vector<const uu::net::Network*> existing_layers;

            for (auto v: c->actors)
            {
                existing_actors.push_back(v);
            }
            for (auto l: c->layers)
            {
                existing_layers.push_back(l);
            }
            if (existing_actors == new_actors && existing_layers == new_layers)
            {   // find me
                new_actors.clear();
                new_layers.clear();
                return true;
            }
        }


        // if new clique is smaller than old clique
        if (new_actors.size() < c->actors.size())
        {
            std::vector<const uu::net::Vertex*> existing_actors;
            std::vector<const uu::net::Network*> existing_layers;

            for (auto v: c->actors)
            {
                existing_actors.push_back(v);
            }
            for (auto l: c->layers)
            {
                existing_layers.push_back(l);
            }

            // if the layers are the same and new vector is smaller:
            if (existing_layers == new_layers)
            {

                int count = 0;
                for (auto v: new_actors)
                {

                  if (std::find(existing_actors.begin(), existing_actors.end(), v)!=existing_actors.end())
                  {
                      count++;
                  }
                }

                if (count == new_actors.size() || count == (new_actors.size()-1))
                {

                    count = 0;
                    // find me

                    new_actors.clear();
                    new_layers.clear();

                    return true;
                }

            }

        }


        // if new clique is smaller and has most elements then remove

        if (new_actors.size() < c->actors.size() && c->layers.size() == new_layers.size())
        {
            std::vector<const uu::net::Vertex*> existing_actors;
            std::vector<const uu::net::Network*> existing_layers;


            for (auto v: c->actors)
            {
                existing_actors.push_back(v);
            }
            for (auto l: c->layers)
            {
                existing_layers.push_back(l);
            }


            int count_l = 0;

            // if layers the same
            for (auto l: new_layers)
            {
                if (std::find(existing_layers.begin(), existing_layers.end(), l)!=existing_layers.end())
                {
                    count_l++;
                }
            }

            // and all actors in old clique exist in new clique then delete
            int count_v = 0;
            for (auto v: existing_actors)
            {
                if (std::find(new_actors.begin(), new_actors.end(), v)!=new_actors.end())
                {
                    count_v++;
                }
            }

            // if more vertices including all vertices in c and same layers, then delete c
            if ((count_v == new_actors.size()) && count_l == new_layers.size())
            {   //
              // find me
                new_actors.clear();
                new_layers.clear();

                return true;
            }

        }




        // if new clique is bigger and has most? eleemtns of old clique and more - then replace
        if (c->actors.size() < new_actors.size() && c->layers.size() == new_layers.size())
        {
            std::vector<const uu::net::Vertex*> existing_actors;
            std::vector<const uu::net::Network*> existing_layers;

            for (auto v: c->actors)
            {
                existing_actors.push_back(v);
            }
            for (auto l: c->layers)
            {
                existing_layers.push_back(l);
            }

            int count_l = 0;

            // if layers the same
            for (auto l: existing_layers)
            {
                if (std::find(new_layers.begin(), new_layers.end(), l)!=new_layers.end())
                {
                    count_l++;
                }
            }

            // and all actors in old clique exist in new clique then delete
            int count_v = 0;
            for (auto v: existing_actors)
            {
                if (std::find(new_actors.begin(), new_actors.end(), v)!=new_actors.end())
                {
                    count_v++;
                }
            }

            // if more vertices including all vertices in c and same layers, then delete c
            if (count_v == (c->actors.size()-1) && count_l == (c->layers.size()-1))
            {   //
                // remove
                result.erase(c);

                // not redundant
                // find me
                new_actors.clear();
                new_layers.clear();
                return false;
            }
        }


        // check for redundant cliques if the layers are already contained in old results
        if (new_layers.size() < c->layers.size())
        {

            std::vector<const uu::net::Network*> existing_layers;

            for (auto l: c->layers)
            {
                existing_layers.push_back(l);
            }

            int count_l = 0;
            // for layers in new layers, if they exist in old one then count should equal its orig size
            for (auto l: new_layers)
            {
                if (std::find(existing_layers.begin(), existing_layers.end(), l)!=existing_layers.end())
                {
                    count_l++;
                }
            }
            // if all layers in smaller are in bigger then check for redundancy
            if (count_l == new_layers.size())
            {
              //std::cout << "if all layers of the smaller one are in the current one" << std::endl;
              std::vector<const uu::net::Vertex*> existing_actors;

              for (auto v: c->actors)
              {
                  existing_actors.push_back(v);
              }

              int count_v = 0;
              for (auto v: new_actors)
              {
                  if (std::find(existing_actors.begin(), existing_actors.end(), v)!=existing_actors.end())
                  {
                      count_v++;
                  }
              }

              if (count_v > 0)
              {
                  if ((c->actors.size() % count_v) > 2)
                  {
                    // find me
                      new_actors.clear();
                      new_layers.clear();
                      return true;
                  }
              }

            }


        }

        // TODO : add better redundancy checks



    }

    // if they pass checks and not redundant then add
    new_actors.clear();
    new_layers.clear();
    return false;
}




/**
 * Slow way to check if vertex already searched
 *
 */
bool
has_been_expanded(
    const uu::net::Vertex* vertex,
    std::vector<const uu::net::Vertex*> expanded_vertices
)
{
    if (std::find(expanded_vertices.begin(), expanded_vertices.end(), vertex)!=expanded_vertices.end())
    {
        return true;
    }
    return false;
}



/**
 * Determines the most promising subtree out of two given
 *
 */


bool
most_promising_subtree(
  uu::net::subtree a,
  uu::net::subtree b,
  std::vector<const uu::net::Vertex*> expanded_vertices
)
{

    if (has_been_expanded(a.vertex_set[0].vertex, expanded_vertices))
    {
        return false;
    }

    if (has_been_expanded(b.vertex_set[0].vertex, expanded_vertices))
    {
        return false;
    }

    if (b.list_of_candidates.size() < a.list_of_candidates.size())
    {
        return true;
    }
    return false;
}



int
neighboring_vertex_layer(
    uu::net::subtree root,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers,
    const uu::net::Vertex* vertex
)
{
    int count = 0;
    int layer = root.vertex_set[0].layer;
    for (int i =0; i < list_of_vertex_layers[layer].size(); i++)
    {
        if (list_of_vertex_layers[layer][i].vertex == vertex)
        {
            return count;
        }
        count++;
    }
    return -1;
}


/**
 * Expands the represented set O by one neighbouring vertex u
 * new clusters and subtrees added to the queue,
 * candidate sets are reduced using pruning techniques
 */
// 12 -> Expand
std::vector<uu::net::subtree>
expandSubtree(
    //std::priority_queue<uu::net::subtree, std::vector<uu::net::subtree>, CompareSubtree> queue_of_subtrees,
    uu::net::subtree root,
    std::vector<std::vector<uu::net::vertex_layer>> list_of_vertex_layers,
    std::vector<const uu::net::Vertex*> expanded_vertices,
    int layer_count,
    int vertex_count
)
{
    std::vector<uu::net::subtree> new_candidates;
    while (root.list_of_candidates.size() !=0)
    {
        int pos = neighboring_vertex_layer(root, list_of_vertex_layers, root.list_of_candidates.front());
        uu::net::subtree neighbor_candidate = create_subtree(list_of_vertex_layers[root.vertex_set[0].layer][pos], list_of_vertex_layers);
        uu::net::subtree rest_of_tree_candidate = create_subtree(list_of_vertex_layers[layer_count][vertex_count], list_of_vertex_layers);

        if (most_promising_subtree(neighbor_candidate, rest_of_tree_candidate, expanded_vertices))
        {
            new_candidates.push_back(neighbor_candidate);
            root.list_of_candidates.erase(root.list_of_candidates.begin());
        }
        else //if (most_promising_subtree(rest_of_tree_candidate, ))
        {
            if(has_been_expanded(rest_of_tree_candidate.vertex_set[0].vertex, expanded_vertices))
            {
                root.list_of_candidates.clear();
            }
            else
            {
                new_candidates.push_back(rest_of_tree_candidate);
                root.list_of_candidates.clear();
            }
        }
    }
    return new_candidates;
};


}
}
