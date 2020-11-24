
#include <string>
#include "io/read_multilayer_network.hpp"
#include "networks/WeightedNetwork.hpp"
#include "operations/flatten.hpp"
#include <random>
namespace uu
{
    namespace net
    {
        class AliasTable
        {
        private:
            std::vector<double> prob_table;
            std::vector<int> alias_table;
            std::vector<const Vertex *> nodes; //should be replaced by pointers to nodes inside
        public:
            AliasTable(std::vector<double> probabilities, std::vector<const uu::net::Vertex *> _nodes);
            const uu::net::Vertex *alias_sampling(std::default_random_engine *generator);
        };
    } // namespace net
} // namespace uu

