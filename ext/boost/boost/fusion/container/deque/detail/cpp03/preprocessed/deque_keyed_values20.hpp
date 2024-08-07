/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/
namespace boost {
namespace fusion {
namespace detail {
template<typename Key, typename Value, typename Rest>
struct keyed_element;
struct nil_keyed_element;
template<typename N, typename T0 = void_, typename T1 = void_, typename T2 = void_, typename T3 = void_, typename T4 = void_, typename T5 = void_, typename T6 = void_, typename T7 = void_, typename T8 = void_, typename T9 = void_, typename T10 = void_, typename T11 = void_, typename T12 = void_, typename T13 = void_, typename T14 = void_, typename T15 = void_, typename T16 = void_, typename T17 = void_, typename T18 = void_, typename T19 = void_>
struct deque_keyed_values_impl;
template<typename N>
struct deque_keyed_values_impl<N, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_, void_>
{
    typedef nil_keyed_element type;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct()
    {
        return type();
    }
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_()
    {
        return type();
    }
};
template<typename N, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
struct deque_keyed_values_impl
{
    typedef mpl::int_<mpl::plus<N, mpl::int_<1> >::value> next_index;
    typedef typename deque_keyed_values_impl<
    next_index,
    T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19>::type tail;
    typedef keyed_element<N, T0, tail> type;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    >::construct());
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    >::forward_());
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1
                    >::construct(t1));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1
                    >::forward_(std::forward<T_1>( t1)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2
                    >::construct(t1, t2));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3
                    >::construct(t1, t2, t3));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4
                    >::construct(t1, t2, t3, t4));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5
                    >::construct(t1, t2, t3, t4, t5));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6
                    >::construct(t1, t2, t3, t4, t5, t6));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7
                    >::construct(t1, t2, t3, t4, t5, t6, t7));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11, typename detail::call_param<T12 >::type t12)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11, typename T_12>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11, T_12 && t12)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11, T_12
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11), std::forward<T_12>( t12)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11, typename detail::call_param<T12 >::type t12, typename detail::call_param<T13 >::type t13)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11, typename T_12, typename T_13>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11, T_12 && t12, T_13 && t13)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11, T_12, T_13
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11), std::forward<T_12>( t12), std::forward<T_13>( t13)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11, typename detail::call_param<T12 >::type t12, typename detail::call_param<T13 >::type t13, typename detail::call_param<T14 >::type t14)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11, typename T_12, typename T_13, typename T_14>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11, T_12 && t12, T_13 && t13, T_14 && t14)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11, T_12, T_13, T_14
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11), std::forward<T_12>( t12), std::forward<T_13>( t13), std::forward<T_14>( t14)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11, typename detail::call_param<T12 >::type t12, typename detail::call_param<T13 >::type t13, typename detail::call_param<T14 >::type t14, typename detail::call_param<T15 >::type t15)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11, typename T_12, typename T_13, typename T_14, typename T_15>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11, T_12 && t12, T_13 && t13, T_14 && t14, T_15 && t15)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11, T_12, T_13, T_14, T_15
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11), std::forward<T_12>( t12), std::forward<T_13>( t13), std::forward<T_14>( t14), std::forward<T_15>( t15)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11, typename detail::call_param<T12 >::type t12, typename detail::call_param<T13 >::type t13, typename detail::call_param<T14 >::type t14, typename detail::call_param<T15 >::type t15, typename detail::call_param<T16 >::type t16)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11, typename T_12, typename T_13, typename T_14, typename T_15, typename T_16>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11, T_12 && t12, T_13 && t13, T_14 && t14, T_15 && t15, T_16 && t16)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11, T_12, T_13, T_14, T_15, T_16
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11), std::forward<T_12>( t12), std::forward<T_13>( t13), std::forward<T_14>( t14), std::forward<T_15>( t15), std::forward<T_16>( t16)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11, typename detail::call_param<T12 >::type t12, typename detail::call_param<T13 >::type t13, typename detail::call_param<T14 >::type t14, typename detail::call_param<T15 >::type t15, typename detail::call_param<T16 >::type t16, typename detail::call_param<T17 >::type t17)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11, typename T_12, typename T_13, typename T_14, typename T_15, typename T_16, typename T_17>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11, T_12 && t12, T_13 && t13, T_14 && t14, T_15 && t15, T_16 && t16, T_17 && t17)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11, T_12, T_13, T_14, T_15, T_16, T_17
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11), std::forward<T_12>( t12), std::forward<T_13>( t13), std::forward<T_14>( t14), std::forward<T_15>( t15), std::forward<T_16>( t16), std::forward<T_17>( t17)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11, typename detail::call_param<T12 >::type t12, typename detail::call_param<T13 >::type t13, typename detail::call_param<T14 >::type t14, typename detail::call_param<T15 >::type t15, typename detail::call_param<T16 >::type t16, typename detail::call_param<T17 >::type t17, typename detail::call_param<T18 >::type t18)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11, typename T_12, typename T_13, typename T_14, typename T_15, typename T_16, typename T_17, typename T_18>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11, T_12 && t12, T_13 && t13, T_14 && t14, T_15 && t15, T_16 && t16, T_17 && t17, T_18 && t18)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11, T_12, T_13, T_14, T_15, T_16, T_17, T_18
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11), std::forward<T_12>( t12), std::forward<T_13>( t13), std::forward<T_14>( t14), std::forward<T_15>( t15), std::forward<T_16>( t16), std::forward<T_17>( t17), std::forward<T_18>( t18)));
    }
# endif
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    construct(typename detail::call_param<T0 >::type t0, typename detail::call_param<T1 >::type t1, typename detail::call_param<T2 >::type t2, typename detail::call_param<T3 >::type t3, typename detail::call_param<T4 >::type t4, typename detail::call_param<T5 >::type t5, typename detail::call_param<T6 >::type t6, typename detail::call_param<T7 >::type t7, typename detail::call_param<T8 >::type t8, typename detail::call_param<T9 >::type t9, typename detail::call_param<T10 >::type t10, typename detail::call_param<T11 >::type t11, typename detail::call_param<T12 >::type t12, typename detail::call_param<T13 >::type t13, typename detail::call_param<T14 >::type t14, typename detail::call_param<T15 >::type t15, typename detail::call_param<T16 >::type t16, typename detail::call_param<T17 >::type t17, typename detail::call_param<T18 >::type t18, typename detail::call_param<T19 >::type t19)
    {
        return type(t0,
                    deque_keyed_values_impl<
                    next_index
                    , T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19
                    >::construct(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19));
    }
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename T_0, typename T_1, typename T_2, typename T_3, typename T_4, typename T_5, typename T_6, typename T_7, typename T_8, typename T_9, typename T_10, typename T_11, typename T_12, typename T_13, typename T_14, typename T_15, typename T_16, typename T_17, typename T_18, typename T_19>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    static type
    forward_(T_0 && t0, T_1 && t1, T_2 && t2, T_3 && t3, T_4 && t4, T_5 && t5, T_6 && t6, T_7 && t7, T_8 && t8, T_9 && t9, T_10 && t10, T_11 && t11, T_12 && t12, T_13 && t13, T_14 && t14, T_15 && t15, T_16 && t16, T_17 && t17, T_18 && t18, T_19 && t19)
    {
        return type(std::forward<T_0>( t0),
                    deque_keyed_values_impl<
                    next_index
                    , T_1, T_2, T_3, T_4, T_5, T_6, T_7, T_8, T_9, T_10, T_11, T_12, T_13, T_14, T_15, T_16, T_17, T_18, T_19
                    >::forward_(std::forward<T_1>( t1), std::forward<T_2>( t2), std::forward<T_3>( t3), std::forward<T_4>( t4), std::forward<T_5>( t5), std::forward<T_6>( t6), std::forward<T_7>( t7), std::forward<T_8>( t8), std::forward<T_9>( t9), std::forward<T_10>( t10), std::forward<T_11>( t11), std::forward<T_12>( t12), std::forward<T_13>( t13), std::forward<T_14>( t14), std::forward<T_15>( t15), std::forward<T_16>( t16), std::forward<T_17>( t17), std::forward<T_18>( t18), std::forward<T_19>( t19)));
    }
# endif
};
template<typename T0 = void_, typename T1 = void_, typename T2 = void_, typename T3 = void_, typename T4 = void_, typename T5 = void_, typename T6 = void_, typename T7 = void_, typename T8 = void_, typename T9 = void_, typename T10 = void_, typename T11 = void_, typename T12 = void_, typename T13 = void_, typename T14 = void_, typename T15 = void_, typename T16 = void_, typename T17 = void_, typename T18 = void_, typename T19 = void_>
struct deque_keyed_values
    : deque_keyed_values_impl<mpl::int_<0>, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19>
{};
}
}
}
