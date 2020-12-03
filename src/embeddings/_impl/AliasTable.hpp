
#include <string>
#include "io/read_multilayer_network.hpp"
#include "networks/WeightedNetwork.hpp"
#include "operations/flatten.hpp"
#include <random>
namespace uu
{
    namespace net
    {
        template<typename ObjType>
        class AliasTable
        {
        private:
            std::vector<double> prob_table;
            std::vector<int> alias_table;
            std::vector<const ObjType *> objects;
        public:
            //template <typename ObjType>
            AliasTable(std::vector<double> probabilities, std::vector<const ObjType *> _objects);
            //template <typename ObjType>
            const ObjType* alias_sampling(std::default_random_engine *generator);
            int size();
        };
    } // namespace net
} // namespace uu
#include "AliasTable.ipp"

