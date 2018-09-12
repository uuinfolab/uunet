#include "rcpp_utils.h"
#include <algorithm>

std::vector<const uu::net::AttributedSimpleGraph*>
resolve_layers(
               const uu::net::AttributedMultiplexNetwork* mnet,
               const Rcpp::CharacterVector& names
               )
{
    int result_size = names.size()?names.size():mnet->layers()->size();
	std::vector<const uu::net::AttributedSimpleGraph*> res(result_size);
    
	if (names.size()==0) {
		int i=0;
		for (auto layer: *mnet->layers()) {
			res[i] = layer;
			i++;
		}
	}
	else {
		for (int i=0; i<names.size(); ++i)
        {
			auto layer = mnet->layers()->get(std::string(names[i]));
			if (!layer) Rcpp::stop("cannot find layer " + std::string(names[i]));
			res[i] = layer;
		}
	}
	return res;
}

std::unordered_set<const uu::net::AttributedSimpleGraph*>
resolve_layers_unordered(
                         const uu::net::AttributedMultiplexNetwork* mnet,
                         const Rcpp::CharacterVector& names
                         )
{
	std::unordered_set<const uu::net::AttributedSimpleGraph*> res;
    
	if (names.size()==0) {
		for (auto layer: *mnet->layers())
        {
			res.insert(layer);
		}
	}
	else
    {
		for (int i=0; i<names.size(); ++i)
        {
			auto layer = mnet->layers()->get(std::string(names[i]));
			if (!layer) Rcpp::stop("cannot find layer " + std::string(names[i]));
			res.insert(layer);
		}
	}
	return res;
}


std::vector<const uu::net::Vertex*>
resolve_actors(
               const uu::net::AttributedMultiplexNetwork* mnet,
               const Rcpp::CharacterVector& names
               )
{
    int result_size = names.size()?names.size():mnet->layers()->size();
    std::vector<const uu::net::Vertex*> res(result_size);
    
    if (names.size()==0)
    {
        int i = 0;
        for (auto actor: *mnet->vertices())
        {
            res[i] = actor;
            i++;
        }
    }
    else {
        for (int i=0; i<names.size(); ++i)
        {
            auto actor = mnet->vertices()->get(std::string(names[i]));
            if (!actor) Rcpp::stop("cannot find actor " + std::string(names[i]));
            res[i] = actor;
        }
    }
    return res;
}

std::unordered_set<const uu::net::Vertex*>
resolve_actors_unordered(
                         const uu::net::AttributedMultiplexNetwork* mnet,
                         const Rcpp::CharacterVector& names
                         )
{
    std::unordered_set<const uu::net::Vertex*> res;
    
    if (names.size()==0)
    {
        for (auto actor: *mnet->vertices())
        {
            res.insert(actor);
        }
    }
    else
    {
        for (int i=0; i<names.size(); ++i)
        {
            auto actor = mnet->vertices()->get(std::string(names[i]));
            if (!actor) Rcpp::stop("cannot find actor " + std::string(names[i]));
            res.insert(actor);
        }
    }
    return res;
}

/*
std::vector<NodeSharedPtr>
resolve_nodes(
              const uu::net::AttributedMultiplexNetwork* mnet,
              const Rcpp::DataFrame& node_matrix
              )
{
	std::vector<NodeSharedPtr> res(nodes.nrow());
    CharacterVector a = nodes(0);
    CharacterVector l = nodes(1);
    
    for (int i=0; i<nodes.nrow(); i++) {
        ActorSharedPtr actor = mnet->actors->get(std::string(a(i)));
        if (!actor) Rcpp::stop("cannot find actor " + std::string(a(i)));
        LayerSharedPtr layer = mnet->layers()->get(std::string(l(i)));
        if (!layer) Rcpp::stop("cannot find layer " + std::string(l(i)));
        NodeSharedPtr node = mnet->get_node(actor,layer);
        if (!node) Rcpp::stop("cannot find actor " + actor->name + " on layer " + layer->name);
        res[i] = node;
    }
	return res;
}
*/

std::vector<const uu::net::Edge*>
resolve_edges(
              const uu::net::AttributedMultiplexNetwork* mnet,
              const Rcpp::DataFrame& edges
              )
{
    std::vector<const uu::net::Edge*> res(edges.nrow());
    CharacterVector a_from = edges(0);
    CharacterVector l_from = edges(1);
    CharacterVector a_to = edges(2);
    CharacterVector l_to = edges(3);
    
    for (int i=0; i<edges.nrow(); i++)
    {
        auto actor1 = mnet->vertices()->get(std::string(a_from(i)));
        if (!actor1) Rcpp::stop("cannot find actor " + std::string(a_from(i)));
        
        auto actor2 = mnet->vertices()->get(std::string(a_to(i)));
        if (!actor2) Rcpp::stop("cannot find actor " + std::string(a_to(i)));
        
        auto layer1 = mnet->layers()->get(std::string(l_from(i)));
        if (!layer1) Rcpp::stop("cannot find layer " + std::string(l_from(i)));
        
        auto layer2 = mnet->layers()->get(std::string(l_to(i)));
        if (!layer2) Rcpp::stop("cannot find layer " + std::string(l_to(i)));
        
        if (layer1 == layer2)
        {
            auto edge = layer1->edges()->get(actor1, actor2);
            if (!edge) Rcpp::stop("cannot find edge from " + actor1->to_string() + " to " + actor2->to_string());
            
            res[i] = edge;
        }
        else
        {
            // @todo
            Rcpp::stop("interlayer edges not currently supported");
        }
    }
    return res;
}



uu::net::EdgeMode
resolve_mode(
             std::string mode
             )
{
    if (mode=="all")
        return uu::net::EdgeMode::INOUT;
    else if (mode=="in")
    	return uu::net::EdgeMode::IN;
    else if (mode=="out")
    	return uu::net::EdgeMode::OUT;
    
    Rcpp::stop("unexpected value: edge mode " + mode);

	return uu::net::EdgeMode::INOUT; // never reaches here
}

Rcpp::DataFrame
to_dataframe(
             uu::net::CommunityStructure<uu::net::VertexLayerCommunity<uu::net::AttributedSimpleGraph>> cs
             )
{
    
    Rcpp::CharacterVector actor, layer;
    Rcpp::NumericVector community_id;
    
    int comm_id=0;
    for (auto com: cs)
    {
        for (auto pair: *com)
        {
            actor.push_back(pair.first->name);
            layer.push_back(pair.second->name);
            community_id.push_back(comm_id);
        }
        comm_id++;
    }
    return Rcpp::DataFrame::create(
                             _("actor")=actor,
                             _("layer")=layer,
                             _("cid")=community_id
                             );
}
