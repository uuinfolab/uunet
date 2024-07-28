#include "gtest/gtest.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "io/read_multilayer_network.hpp"

TEST(io_test, read_multilayer_network_aucs)
{
    // Subset of the AUCS net as released in the R and Python libraries.
    // Just checking that it can be parsed.
    
    // preparing a file to read
    
    std::string test_file_name = "net_io_read_graph_file.tmp";
    
    std::ofstream test_file;
    test_file.open(test_file_name);

    if (!test_file.is_open())
    {
        FAIL()
                << "Could not create temporary file. Test not executed.";
    }

    test_file << "#ACTOR ATTRIBUTES" << std::endl;
    test_file << "group,STRING" << std::endl;
    test_file << "role,STRING" << std::endl;
    test_file << "" << std::endl;
    test_file << "#VERTEX ATTRIBUTES" << std::endl;
    test_file << "" << std::endl;
    test_file << "#ACTORS" << std::endl;
    test_file << "U102,G1,Associate" << std::endl;
    test_file << "U139,G2,Postdoc" << std::endl;
    test_file << "U33,G2/G3,Admin" << std::endl;
    test_file << "U106,G4,PhD" << std::endl;
    test_file << "U107,G1,Postdoc" << std::endl;
    test_file << "U118,G3,Postdoc" << std::endl;
    test_file << "" << std::endl;
    test_file << "#EDGES" << std::endl;
    test_file << "U102,U139,lunch" << std::endl;
    test_file << "U102,U33,lunch" << std::endl;
    test_file << "U106,U107,facebook" << std::endl;
    test_file << "U106,U118,coauthor" << std::endl;
    test_file << "U106,U119,leisure" << std::endl;
    test_file << "                     " << std::endl;
    test_file.close();
    
    auto net = uu::net::read_multilayer_network(test_file_name, "g");
    
    // cleaning up

    std::remove(test_file_name.data());
}

TEST(io_test, read_multilayer_network)
{
    // preparing a file to read
    
    std::string test_file_name = "net_io_read_graph_file.tmp";
    
    std::ofstream test_file;
    test_file.open(test_file_name);

    if (!test_file.is_open())
    {
        FAIL()
                << "Could not create temporary file. Test not executed.";
    }

    test_file << "#TYPE                " << std::endl;
    test_file << "multilayer           " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#VERSION             " << std::endl;
    test_file << "3.0                  " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#LAYERS              " << std::endl;
    test_file << "l1,l1,UNDIRECTED     " << std::endl;
    test_file << "l2,l2,UNDIRECTED,LOOPS" << std::endl;
    test_file << "l1,l2,DIRECTED       " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#ACTOR ATTRIBUTES    " << std::endl;
    test_file << "ssn, string          " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#ACTORS              " << std::endl;
    test_file << "v1,1223/43 242"        << std::endl;
    test_file << "v3,\"122 3-4,3654\""   << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#VERTEX ATTRIBUTES   " << std::endl;
    test_file << "l2,day,string        " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#VERTICES            " << std::endl;
    test_file << "v6,l2,Monday         " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#EDGE ATTRIBUTES     " << std::endl;
    test_file << "l1,attr.name,numeric " << std::endl;
    test_file << "attr.name2,numeric   " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#EDGES               " << std::endl;
    test_file << "v1,l1,v2,l1,1,7"       << std::endl;
    test_file << "v1,l1,v5,l1,2,8"       << std::endl;
    test_file << "v2,l1,v5,l1,3,9"       << std::endl;
    test_file << "v2,l1,v3,l1,4,10"      << std::endl;
    test_file << "v2,l1,v4,l1,5,11"      << std::endl;
    test_file << "v3,l1,v4,l1,6,12"      << std::endl;
    test_file << "v1,l1,v4,l2,13"        << std::endl;
    test_file << "v2,l1,v3,l2,14"        << std::endl;
    test_file << "v2,l1,v4,l2,15"        << std::endl;
    test_file << "v3,l1,v3,l2,16"        << std::endl;
    test_file << "v3,l1,v4,l2,17"        << std::endl;
    test_file << "v1,l1,v2,l2,18"        << std::endl;
    test_file << "                     " << std::endl;
    test_file.close();
    
    auto net = uu::net::read_multilayer_network(test_file_name, "g");
    
    //std::cout << net->summary() << std::endl;
    auto l1 = net->layers()->get("l1");
    auto l2 = net->layers()->get("l2");
    auto vertices = l1->vertices();
    auto edges = l1->edges();
    auto v1 = vertices->get("v1");
    auto v2 = vertices->get("v2"); // @todo taking from l1, using on l2... change
    auto v3 = vertices->get("v3");
    auto v5 = vertices->get("v5");
    auto e = edges->get(v1, v5);
    double val1 = edges->attr()->get_double(e, "attr.name2").value;
    EXPECT_EQ(8.0, val1);
    
    std::string val2 = net->actors()->attr()->get_string(v1, "ssn").value;
    EXPECT_EQ("1223/43 242", val2);
    std::string val2b = net->actors()->attr()->get_string(v3, "ssn").value;
    EXPECT_EQ("122 3-4,3654", val2b);
    
    auto il_edges = net->interlayer_edges();
    auto il_e =
    il_edges->get(v1,l1,v2,l2);
    double val3 = il_edges->get(l1,l2)->attr()->get_double(il_e, "attr.name2").value;
    EXPECT_EQ(18.0, val3)
            << "wrong attribute value: interlayer edge";


    double dir = il_edges->is_directed(l1, l2);
    EXPECT_TRUE(dir)
            << "wrong interlayer edge directionality";
    
    // cleaning up

    std::remove(test_file_name.data());
}

TEST(io_test, read_multilayer_network_wrongformat1)
{
    // preparing a file to read
    
    std::string test_file_name = "net_io_read_graph_file.tmp";
    
    std::ofstream test_file;
    test_file.open(test_file_name);

    if (!test_file.is_open())
    {
        FAIL()
                << "Could not create temporary file. Test not executed.";
    }

    test_file << "#TYPE                " << std::endl;
    test_file << "multilayer           " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#LAYERS              " << std::endl;
    test_file << "l1,l1,UNDIRECTED     " << std::endl;
    test_file << "l2,l2,UNDIRECTED,LOOPS" << std::endl;
    test_file << "l1,l2,DIRECTED       " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#ACTOR ATTRIBUTES    " << std::endl;
    test_file << "ssn, string          " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#ACTORS              " << std::endl;
    test_file << "v1,122343242" << std::endl;
    test_file << "v3,122343654" << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#VERTEX ATTRIBUTES   " << std::endl;
    test_file << "l2,day,string        " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#VERTICES            " << std::endl;
    test_file << "v6,l2,Monday         " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#EDGE ATTRIBUTES     " << std::endl;
    test_file << "l1,attr.name,numeric " << std::endl;
    test_file << "attr.name2,numeric   " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#EDGES               " << std::endl;
    test_file << "v3,l1,v4,l1,12" << std::endl;
    test_file << "v1,l1,v4,l2,13" << std::endl;
    test_file << "                     " << std::endl;
    test_file.close();
    
    EXPECT_THROW(uu::net::read_multilayer_network(test_file_name, "g"), uu::core::WrongFormatException);

    std::remove(test_file_name.data());
}


TEST(io_test, read_multilayer_network_wrongformat2)
{
    // preparing a file to read
    
    std::string test_file_name = "net_io_read_graph_file.tmp";
    
    std::ofstream test_file;
    test_file.open(test_file_name);

    if (!test_file.is_open())
    {
        FAIL()
                << "Could not create temporary file. Test not executed.";
    }

    test_file << "#TYPE                " << std::endl;
    test_file << "multilayer           " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#LAYERS              " << std::endl;
    test_file << "l1,l1,UNDIRECTED     " << std::endl;
    test_file << "l2,l2,UNDIRECTED,LOOPS" << std::endl;
    test_file << "l1,l2,DIRECTED       " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#ACTOR ATTRIBUTES    " << std::endl;
    test_file << "ssn, string          " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#ACTORS              " << std::endl;
    test_file << "v1                   " << std::endl;
    test_file << "v3,122343654         " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#VERTEX ATTRIBUTES   " << std::endl;
    test_file << "l2,day,string        " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#VERTICES            " << std::endl;
    test_file << "v6,l2,Monday         " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#EDGE ATTRIBUTES     " << std::endl;
    test_file << "l1,attr.name,numeric " << std::endl;
    test_file << "attr.name2,numeric   " << std::endl;
    test_file << "                     " << std::endl;
    test_file << "#EDGES               " << std::endl;
    test_file << "v3,l1,v4,l1,8,12       " << std::endl;
    test_file << "v1,l1,v4,l2,13       " << std::endl;
    test_file << "                     " << std::endl;
    test_file.close();
    
    EXPECT_THROW(uu::net::read_multilayer_network(test_file_name, "g"), uu::core::WrongFormatException);

    std::remove(test_file_name.data());
}

