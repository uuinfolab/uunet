#ifndef PARSER_EXAMPLE_GRAMMAR_HPP
#define PARSER_EXAMPLE_GRAMMAR_HPP

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/utility/error_reporting.hpp>
#include <boost/spirit/home/x3/support/utility/annotate_on_success.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

namespace uu {
namespace net {
namespace parser {
namespace metadata_ml {

using x3::int_;
using x3::double_;
using x3::alnum;
using x3::alpha;
using x3::lit;
using x3::eol;
using x3::lexeme;
using x3::skip;
using x3::blank;
using x3::ascii::space;
using boost::spirit::x3::ascii::char_;

// Associate actions to rules

class start_id : error_handler {};
class empty_line_id {};
class section_id {};
class version_id : version_act {};
class type_spec_id : type_act {};
class actor_attr_list_id {};
class vertex_attr_list_id {};
class edge_attr_list_id {};
class layer_list_id {};
class actor_list_id {};
class vertex_list_id {};
class edge_list_id {};
class actor_attr_id : actor_attr_act  {};
class vertex_attr_id : vertex_attr_act {};
class edge_attr_id : edge_attr_act {};
class layer_id : layer_def_act {};
class actor_id : actor_act {};
class vertex_id : vertex_act {};
class edge_id : edge_act {};
class id_id {};
class val_id {};

// Create rules

x3::rule<class start_id> const start = "start";
x3::rule<class section_id> const section = "section";
x3::rule<class empty_line_id> const empty_line = "empty_line";
x3::rule<class version_id, double> const version = "version";
x3::rule<class type_spec_id, std::vector<std::string>> const type_spec = "type_spec";
x3::rule<class actor_attr_list_id> const actor_attr_list = "actor_attr_list";
x3::rule<class vertex_attr_list_id> const vertex_attr_list = "vertex_attr_list";
x3::rule<class edge_attr_list_id> const edge_attr_list = "edge_attr_list";
x3::rule<class layer_list_id> const layer_list = "layer_list";
x3::rule<class actor_list_id> const actor_list = "actor_list";
x3::rule<class vertex_list_id> const vertex_list = "vertex_list";
x3::rule<class edge_list_id> const edge_list = "edge_list";
x3::rule<class actor_attr_id, std::vector<std::string>> const actor_attr = "actor_attr";
x3::rule<class vertex_attr_id, std::vector<std::string>> const vertex_attr = "vertex_attr";
x3::rule<class edge_attr_id, std::vector<std::string>> const edge_attr = "edge_attr";
x3::rule<class layer_id, std::vector<std::string>> const layer = "layer";
x3::rule<class actor_id, std::vector<std::string>> const actor = "actor";
x3::rule<class vertex_id, std::vector<std::string>> const vertex = "vertex";
x3::rule<class edge_id, std::vector<std::string>> const edge = "edge";
x3::rule<class id_id, std::string> const id = "id";
x3::rule<class val_id, std::string> const val = "val";

// Keywords

struct net_types_ : x3::symbols<std::string>
{
    net_types_()
    {
        add
        ("directed", "directed")
        ("undirected", "undirected")
        ("allow loops", "allow loops")
        ("no loops", "no loops")
        ("weighted",  "weighted")
        ("probabilistic",  "probabilistic")
        ("temporal", "temporal")
        ;
    }
};
const net_types_ net_t;

struct mlnet_types_ : x3::symbols<std::string>
{
    mlnet_types_()
    {
        add
        ("multiplex", "multiplex")
        ("multilayer", "multilayer")
        ;
    }
};
const mlnet_types_ mlnet_t;

struct attr_types_ : x3::symbols<std::string>
{
    attr_types_()
    {
        add
        ("integer", "integer")
        ("numeric", "double")
        ("double", "double")
        ("string",  "string")
        ("time",  "time")
        ("text",  "text")
        ("integeset", "integerset")
        ("doubleset", "doubleset")
        ("stringset",  "stringset")
        ("timeset",  "timeset")
        ;
    }
};
const attr_types_ attr_t;

// Define rules

auto const start_def =
    skip(blank)[
        +section
        |
        edge_list >
        *empty_line
    ];
auto const section_def =
    x3::no_case["#version"] > eol >
    version >
    *empty_line
    |
    x3::no_case["#type"] > eol >
    type_spec >
    *empty_line
    |
    x3::no_case["#actor attributes"] > eol >
    *empty_line >
    actor_attr_list >
    *empty_line
    |
    x3::no_case["#vertex attributes"] > eol >
    *empty_line >
    vertex_attr_list >
    *empty_line
    |
    x3::no_case["#edge attributes"] > eol >
    *empty_line >
    edge_attr_list >
    *empty_line
    |
    x3::no_case["#layers"] > eol >
    *empty_line >
    layer_list >
    *empty_line
    |
    x3::no_case["#actors"] > eol >
    *empty_line >
    actor_list >
    *empty_line
    |
    x3::no_case["#vertices"] > eol >
    *empty_line >
    vertex_list >
    *empty_line
    |
    x3::no_case["#edges"] > eol >
    *empty_line >
    edge_list >
    *empty_line
    ;
auto const empty_line_def =
    *blank >> eol
    ;
auto const version_def =
    double_ > eol
    ;
auto const type_spec_def =
    x3::no_case[mlnet_t] % ',' > eol
    ;
auto const actor_attr_list_def =
    +actor_attr
    ;
auto const vertex_attr_list_def =
    +vertex_attr
    ;
auto const edge_attr_list_def =
    +edge_attr
    ;
auto const layer_list_def =
    +layer
    ;
auto const actor_list_def =
    +actor
    ;
auto const vertex_list_def =
    +vertex
    ;
auto const edge_list_def =
    +edge
    ;

auto const actor_attr_def =
    id > ',' > x3::no_case[attr_t] > eol
    ;
auto const vertex_attr_def =
    id > ',' > id > ',' > x3::no_case[attr_t] > eol
    ;
auto const edge_attr_def =
    id >> ',' >> x3::no_case[attr_t] >> eol
    |
    id >> ',' >> id >> ',' >> x3::no_case[attr_t] >> eol
    |
    id >> ',' >> id >> ',' >> id >> ',' >> x3::no_case[attr_t] >> eol
    ;
auto const layer_def =
    id > *(',' > x3::no_case[net_t] % ',') > eol
    ;
auto const actor_def =
    id > *(',' > val % ',') > eol
    ;
auto const vertex_def =
    id > *(',' > val % ',') > eol
    ;
auto const edge_def =
    id > ',' > id > *(',' > val % ',') > eol
    ;
auto const id_def =
    char_("A-Za-z_") > *char_("A-Za-z0-9._")
    ;
auto const val_def =
    +char_("A-Za-z0-9._")
    ;

// Bind rules and their properties/definitions

BOOST_SPIRIT_DEFINE
(
    start, section, empty_line,
    version, type_spec,
    actor_attr_list, vertex_attr_list, edge_attr_list,
    layer_list, actor_list, vertex_list, edge_list,
    actor_attr, vertex_attr, edge_attr,
    layer, actor, vertex, edge,
    id, val
);

}
}
}
}

#endif
