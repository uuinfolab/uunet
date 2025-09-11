namespace uu {
namespace net {



template <typename M>
std::set<std::unique_ptr<PillarCommunity<M>>>
eclat_merge(
    const M* mnet,
    const std::unordered_map<const typename M::layer_type*, CommunityStructure<Network>*>& single_layer_communities,
    int min_actors,
    int min_layers
)
{

    std::unordered_map<int, std::vector<std::string> > transactions;

    for (auto pair: single_layer_communities)
    {
        std::string layer_str = std::to_string(mnet->layers()->index_of(pair.first));
        int community = 0;

        for (auto c: *pair.second)
        {
            std::string community_str = std::to_string(community);

            for (auto node: *c)
            {
                transactions[mnet->actors()->index_of(node)].push_back(community_str + ":" + layer_str);
            }

            community++;
        }

    }

    std::set<std::unique_ptr<PillarCommunity<M>>> result;
    
    if ((min_layers <= 0) || (min_actors <= 0))     /* check for at least one item */
    {
        return std::set<std::unique_ptr<PillarCommunity<M>>>();
    }


    return result;
}


template <typename M>
void
read_layers(
    const M* mnet,
    PillarCommunity<M>* com,
    FILE* file
)
{
    bool found_separator=false;
    bool reading_number=false;
    int c;
    int lid; // layer identifier

    //std::cout << "read layers" << std::endl;
    while (1)
    {
        c=getc(file);

        if (c=='\n' || c==EOF)
        {
            //std::cout << " ";
            if (reading_number)
            {
                //std::cout << "[([)" << lid << "])]";
                com->add_layer(mnet->layers()->at(lid));
                //std::cout << std::endl;
            }

            return;
        }

        if (!found_separator && c!=':')
        {
            continue;
        }

        else if (c==':')
        {
            //std::cout << ":";
            found_separator=true;
            continue;
        }

        if (c>='0' && c<='9')
        {
            //std::cout << (int)(c-'0');
            if (!reading_number)
            {
                lid=(int)(c-'0');
            }

            else
            {
                lid=lid*10+(int)(c-'0');
            }

            reading_number=true;
        }

        else if (c==' ')
        {
            if (reading_number)
            {
                //std::cout << "[[" << lid << "]]";
                com->add_layer(mnet->layers()->at(lid));
                //std::cout << std::endl;
            }

            reading_number=false;
            found_separator=false;
        }
    }
}

template <typename M>
int
read_actors(
    const M* mnet,
    PillarCommunity<M>* com,
    FILE* tidfile
)
{
    size_t id;
    int c;
    bool reading_number=false;

    //std::cout << "read actors" << std::endl;
    while (1)
    {
        c=getc(tidfile);

        if (c>='0' && c<='9')
        {
            //std::cout << (int)(c-'0');
            if (!reading_number)
            {
                id=(int)(c-'0');
            }

            else
            {
                id=id*10+(int)(c-'0');
            }

            reading_number=true;
        }

        else if (c==' ' || c=='\n' || c==EOF)
        {
            //std::cout << " ";
            if (reading_number)
            {
                //std::cout << "[[" << (id-1) << "]]";
                com->add_actor(mnet->actors()->at(id-1));
                //std::cout << std::endl;
            }

            reading_number=false;

            if (c==EOF)
            {
                return 0;
            }

            if (c=='\n')
            {
                return 1;
            }
        }
    }

}

template <typename M>
std::set<std::unique_ptr<PillarCommunity<M>>>
read_eclat_communities(
    const M* mnet,
    FILE* file,
    FILE* tidfile
)
{
    auto communities = std::set<std::unique_ptr<PillarCommunity<M>>>();
    auto current = std::make_unique<PillarCommunity<M>>();

    while (read_actors(mnet,current.get(),tidfile))
    {
        read_layers(mnet,current.get(),file);

        if (current->get_actors().size()>0)
        {
            communities.insert(std::move(current));
            current = std::make_unique<PillarCommunity<M>>();
        }
    }

    //communities.insert(std::move(current));
    return communities;
}

}
}

