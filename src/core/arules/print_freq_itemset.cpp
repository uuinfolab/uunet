#include "core/arules/print_freq_itemset.hpp"
#include <unordered_map>
#include <iostream>

namespace uu {
namespace core {

void
print_freq_itemset(
    const freq_itemset& freq,
    const std::unordered_map<size_t,std::string>& trans,
    const std::unordered_map<size_t,std::string>& items
    )
{
    std::cout << "FreqItemSet:";
    for (auto el: freq.items)
    {
        std::cout << " " << items.at(el);
    }
    std::cout << " (";
    for (auto tid: freq.tids)
    {
        std::cout << " " << trans.at(tid);
    }
    std::cout << " ) - supp: " << freq.s << std::endl;
}

void
print_freq_itemset(
    const freq_itemset& freq
    )
{
    std::cout << "FreqItemSet:";
    for (auto el: freq.items)
    {
        std::cout << " " << el;
    }
    std::cout << " (";
    for (auto tid: freq.tids)
    {
        std::cout << " " << tid;
    }
    std::cout << " ) - supp: " << freq.s << std::endl;
}


}
}
