#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>

#include "core/arules/eclat.hpp"
#include "core/arules/read_transactions.hpp"

TEST(core_arules_eclat, eclat)
{
    std::string test_file_name = "core_arules_eclat_file.tmp";
    
    std::ofstream test_file;
    test_file.open(test_file_name);
    if (!test_file.is_open())
    {
        FAIL()
                << "Could not create temporary file. Test not executed.";
    }
    test_file << "i1,i2,i3" << std::endl;
    test_file << "i4,i5,i2,i6" << std::endl;
    test_file << "i5,i1" << std::endl;
    test_file << "i6,i5,i1,i2" << std::endl;
    test_file << "i6,i5,i1,i2" << std::endl;
    test_file << "i6,i1" << std::endl;
    test_file << "i6,i5" << std::endl;
    test_file << "i2,i6" << std::endl;
    
    std::unordered_map<std::size_t,std::string> trans;
    std::unordered_map<std::size_t,std::string> items;
    std::vector<std::vector<std::size_t>> data;
    uu::core::read_transactions(test_file_name,trans,items,data);
    
    std::vector<uu::core::freq_itemset> freq;
    std::vector<uu::core::freq_itemset> closed;
    
    std::size_t eclat_min_sup = 2;
    std::size_t eclat_min_size = 1;
    uu::core::eclat(data, freq, closed, eclat_min_sup, eclat_min_size);
    
    EXPECT_EQ(freq.size(), (std::size_t)15);
    EXPECT_EQ(closed.size(), (std::size_t)11);
    
    std::size_t min_sup = 10;
    std::size_t min_size = 10;
    std::size_t max_sup = 0;
    std::size_t max_size = 0;
    for (auto e: freq) {
        // uu::core::print_freq_itemset(e);
        if (e.items.size() < min_size) min_size = e.items.size();
        if (e.items.size() > max_size) max_size = e.items.size();
        if (e.s < min_sup) min_sup = e.s;
        if (e.s > max_sup) max_sup = e.s;
    }
    EXPECT_EQ(min_sup, (std::size_t)2);
    EXPECT_EQ(max_sup, (std::size_t)6);
    EXPECT_EQ(min_size, (std::size_t)1);
    EXPECT_EQ(max_size, (std::size_t)4);
    
    eclat_min_size = 2;
    std::vector<uu::core::freq_itemset> freq2;
    std::vector<uu::core::freq_itemset> closed2;
    uu::core::eclat(data, freq2, closed2, eclat_min_sup, eclat_min_size);
    
    EXPECT_EQ(freq2.size(), (std::size_t)11);
    EXPECT_EQ(closed2.size(), (std::size_t)7);
    
    //for (auto e: closed) std::cout << e.to_string() << std::endl;
    std::remove(test_file_name.data());
}
