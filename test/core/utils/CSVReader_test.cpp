#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>

#include "core/utils/CSVReader.hpp"

TEST(core_utils_test, CSVReader)
{

    // Preparation for the tests: create a csv file
    std::string test_file_name = "core_utils_CSVReader_test_file.tmp";

    std::ofstream test_file;
    test_file.open(test_file_name);

    if (!test_file.is_open())
    {
        FAIL()
                << "Could not create temporary file. Test not executed.";
    }

    test_file << "a, b ,c" << std::endl;
    test_file << "a, b ,c" << std::endl;
    test_file << "" << std::endl;
    test_file << "d,e,f" << std::endl;
    test_file << "d;e;f" << std::endl;
    test_file << "\"a; b; c\"" << std::endl;
    test_file << "\"a; b; \"\"c\"\"\"" << std::endl;
    test_file << "\"a; b; c\";d" << std::endl;
    test_file << "-- a comment" << std::endl;
    test_file << "last line" << std::endl;
    test_file.close();
    
    // tests start here
    
    uu::core::CSVReader csv;

    csv.open(test_file_name);
    csv.set_comment("--");

    EXPECT_TRUE(csv.has_next())
            << "Wrong has_next";
    EXPECT_EQ(0, csv.row_num())
            << "Wrong row number at the beginning";

    std::vector<std::string> line = csv.get_next();
    EXPECT_EQ(1, csv.row_num())
            << "Wrong row number after get_next";
    EXPECT_EQ(" b ", line.at(1))
            << "Wrong data read by get_next";

    csv.trim_fields(true);
    line = csv.get_next();
    EXPECT_EQ("b", line.at(1))
            << "No effect of trim_fields setting";

    std::string raw_line;
    raw_line = csv.get_current_raw_line();
    EXPECT_EQ("a, b ,c", raw_line)
            << "Wrong data read by get_current_raw_line";

    raw_line = csv.get_next_raw_line();
    EXPECT_EQ(4, csv.row_num())
            << "Wrong row number after get_next_raw_line: empty line not skipped";
    EXPECT_EQ("d,e,f", raw_line)
            << "Wrong data read by get_next_raw_line";

    csv.set_field_separator(';');
    line = csv.get_next();
    EXPECT_EQ("e", line.at(1))
            << "No effect of set_field_separator";

    csv.set_quote('"');
    line = csv.get_next();
    EXPECT_EQ("a; b; c", line.at(0))
            << "Quotation not detected";

    line = csv.get_next();
    EXPECT_EQ("a; b; \"c\"", line.at(0))
            << "Escaped quotation character not detected";

    line = csv.get_next();
    // I don't think the following should be allowed...
    //EXPECT_EQ("a; b; \"c", line.at(0))
    //        << "Singleton quotation character not detected";

    raw_line = csv.get_next_raw_line();
    ASSERT_EQ("last line", raw_line)
            << "Comment line not skipped";
    EXPECT_EQ(10, csv.row_num())
            << "Wrong row number";
    EXPECT_FALSE(csv.has_next())
            << "Wrong has_next at end-of-file";

    csv.close();
    
    std::remove(test_file_name.data());
}

