#ifndef UU_CORE_ARULES_PRINTFREQUENTITEMSETS_H_
#define UU_CORE_ARULES_PRINTFREQUENTITEMSETS_H_

#include <string>
#include <unordered_map>
#include "core/arules/freq_itemset.hpp"

namespace uu {
namespace core {

void
print_freq_itemset(
    const freq_itemset& freq,
    const std::unordered_map<size_t,std::string>& trans,
    const std::unordered_map<size_t,std::string>& items
);

void
print_freq_itemset(
    const freq_itemset& freq
);

}
}

#endif
