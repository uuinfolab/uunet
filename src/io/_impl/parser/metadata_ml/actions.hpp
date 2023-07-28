#ifndef PARSER_EXAMPLE_ACTIONS_HPP
#define PARSER_EXAMPLE_ACTIONS_HPP

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

// Actions

namespace x3 = boost::spirit::x3;
struct data;

struct version_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << attr << std::endl;
    }
};

struct type_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << attr << std::endl;
    }
};

struct layer_def_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << "layer def" << std::endl;
    }
};

struct actor_attr_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << "actor attr" << std::endl;
    }
};

struct vertex_attr_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << "vertex attr" << std::endl;
    }
};

struct edge_attr_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << "edge attr" << std::endl;
    }
};

struct actor_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << "actor" << std::endl;
    }
};

struct vertex_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << "vertex def" << std::endl;
    }
};

struct edge_act
{
    template <typename T, typename It, typename Ctx>
    inline void
    on_success(It const& first, It const& last, T& attr, Ctx const& ctx)
    {
        auto& meta = x3::get<data>(ctx).get();
        std::cout << "edge def" << std::endl;
    }
};

// Error handling

namespace x3 = boost::spirit::x3;

struct error_handler
{
    template <typename Iterator, typename Exception, typename Context>
    x3::error_handler_result
    on_error(
        Iterator& first,
        Iterator const& last,
        Exception const& x,
        Context const& context
    )
    {
        auto& error_handler = x3::get<x3::error_handler_tag>(context).get();
        std::string message = "Format error! Expecting " + x.which() + " here:";
        error_handler(x.where(), message);
        return x3::error_handler_result::fail;
    }
};

}
}
}
}

#endif
