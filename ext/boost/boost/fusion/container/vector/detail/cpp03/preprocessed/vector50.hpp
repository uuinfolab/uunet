/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/
namespace boost {
namespace fusion {
struct vector_tag;
struct fusion_sequence_tag;
struct random_access_traversal_tag;
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40>
struct vector_data41
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data41()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data41(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data41(
        vector_data41&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data41(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data41(
        vector_data41 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data41&
    operator=(vector_data41 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data41
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        return vector_data41(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data41
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        return vector_data41(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40>
struct vector41
    : vector_data41<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40>
    , sequence_base<vector41<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40> >
{
    typedef vector41<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40> this_type;
    typedef vector_data41<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40> base_type;
    typedef mpl::vector41<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<41> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector41() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector41(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector41(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector41(vector41&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector41(vector41 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector41&
    operator=(vector41 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector41&
    operator=(vector41&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector41(
        vector41<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector41(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector41(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector41&
    operator=(vector41<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41>
struct vector_data42
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data42()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data42(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data42(
        vector_data42&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data42(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data42(
        vector_data42 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data42&
    operator=(vector_data42 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data42
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        return vector_data42(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data42
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        return vector_data42(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41>
struct vector42
    : vector_data42<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41>
    , sequence_base<vector42<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41> >
{
    typedef vector42<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41> this_type;
    typedef vector_data42<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41> base_type;
    typedef mpl::vector42<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<42> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector42() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector42(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector42(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector42(vector42&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector42(vector42 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector42&
    operator=(vector42 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector42&
    operator=(vector42&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector42(
        vector42<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector42(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector42(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector42&
    operator=(vector42<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42>
struct vector_data43
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data43()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41(), m42() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data43(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)), m42(std::forward<U42>( arg42)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data43(
        vector_data43&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)), m42(std::forward<T42>( other.m42)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data43(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41), m42(arg42) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data43(
        vector_data43 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41), m42(other.m42) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data43&
    operator=(vector_data43 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data43
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        return vector_data43(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data43
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        return vector_data43(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
    T42 m42;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42>
struct vector43
    : vector_data43<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42>
    , sequence_base<vector43<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42> >
{
    typedef vector43<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42> this_type;
    typedef vector_data43<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42> base_type;
    typedef mpl::vector43<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<43> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector43() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector43(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector43(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41), std::forward<U42>( arg42)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector43(vector43&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector43(vector43 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector43&
    operator=(vector43 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector43&
    operator=(vector43&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        this->m42 = std::forward< T42>(vec.m42);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector43(
        vector43<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41, vec.m42) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector43(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector43(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector43&
    operator=(vector43<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        this->m42 = *i42;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T42>::type at_impl(mpl::int_<42>)
    {
        return this->m42;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T42>::type>::type at_impl(mpl::int_<42>) const
    {
        return this->m42;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43>
struct vector_data44
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data44()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41(), m42(), m43() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data44(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)), m42(std::forward<U42>( arg42)), m43(std::forward<U43>( arg43)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data44(
        vector_data44&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)), m42(std::forward<T42>( other.m42)), m43(std::forward<T43>( other.m43)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data44(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41), m42(arg42), m43(arg43) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data44(
        vector_data44 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41), m42(other.m42), m43(other.m43) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data44&
    operator=(vector_data44 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data44
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        return vector_data44(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data44
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        return vector_data44(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
    T42 m42;
    T43 m43;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43>
struct vector44
    : vector_data44<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43>
    , sequence_base<vector44<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43> >
{
    typedef vector44<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43> this_type;
    typedef vector_data44<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43> base_type;
    typedef mpl::vector44<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<44> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector44() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector44(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector44(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41), std::forward<U42>( arg42), std::forward<U43>( arg43)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector44(vector44&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector44(vector44 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector44&
    operator=(vector44 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector44&
    operator=(vector44&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        this->m42 = std::forward< T42>(vec.m42);
        this->m43 = std::forward< T43>(vec.m43);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector44(
        vector44<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41, vec.m42, vec.m43) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector44(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector44(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector44&
    operator=(vector44<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        this->m42 = *i42;
        this->m43 = *i43;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T42>::type at_impl(mpl::int_<42>)
    {
        return this->m42;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T42>::type>::type at_impl(mpl::int_<42>) const
    {
        return this->m42;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T43>::type at_impl(mpl::int_<43>)
    {
        return this->m43;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T43>::type>::type at_impl(mpl::int_<43>) const
    {
        return this->m43;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44>
struct vector_data45
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data45()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41(), m42(), m43(), m44() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data45(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)), m42(std::forward<U42>( arg42)), m43(std::forward<U43>( arg43)), m44(std::forward<U44>( arg44)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data45(
        vector_data45&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)), m42(std::forward<T42>( other.m42)), m43(std::forward<T43>( other.m43)), m44(std::forward<T44>( other.m44)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data45(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41), m42(arg42), m43(arg43), m44(arg44) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data45(
        vector_data45 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41), m42(other.m42), m43(other.m43), m44(other.m44) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data45&
    operator=(vector_data45 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data45
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        return vector_data45(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data45
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        return vector_data45(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
    T42 m42;
    T43 m43;
    T44 m44;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44>
struct vector45
    : vector_data45<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44>
    , sequence_base<vector45<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44> >
{
    typedef vector45<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44> this_type;
    typedef vector_data45<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44> base_type;
    typedef mpl::vector45<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<45> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector45() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector45(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43, arg44) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector45(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41), std::forward<U42>( arg42), std::forward<U43>( arg43), std::forward<U44>( arg44)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector45(vector45&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector45(vector45 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector45&
    operator=(vector45 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector45&
    operator=(vector45&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        this->m42 = std::forward< T42>(vec.m42);
        this->m43 = std::forward< T43>(vec.m43);
        this->m44 = std::forward< T44>(vec.m44);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector45(
        vector45<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41, vec.m42, vec.m43, vec.m44) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector45(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector45(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector45&
    operator=(vector45<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        this->m42 = *i42;
        this->m43 = *i43;
        this->m44 = *i44;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T42>::type at_impl(mpl::int_<42>)
    {
        return this->m42;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T42>::type>::type at_impl(mpl::int_<42>) const
    {
        return this->m42;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T43>::type at_impl(mpl::int_<43>)
    {
        return this->m43;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T43>::type>::type at_impl(mpl::int_<43>) const
    {
        return this->m43;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T44>::type at_impl(mpl::int_<44>)
    {
        return this->m44;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T44>::type>::type at_impl(mpl::int_<44>) const
    {
        return this->m44;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45>
struct vector_data46
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data46()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41(), m42(), m43(), m44(), m45() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data46(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)), m42(std::forward<U42>( arg42)), m43(std::forward<U43>( arg43)), m44(std::forward<U44>( arg44)), m45(std::forward<U45>( arg45)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data46(
        vector_data46&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)), m42(std::forward<T42>( other.m42)), m43(std::forward<T43>( other.m43)), m44(std::forward<T44>( other.m44)), m45(std::forward<T45>( other.m45)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data46(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41), m42(arg42), m43(arg43), m44(arg44), m45(arg45) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data46(
        vector_data46 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41), m42(other.m42), m43(other.m43), m44(other.m44), m45(other.m45) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data46&
    operator=(vector_data46 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data46
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        return vector_data46(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data46
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        return vector_data46(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
    T42 m42;
    T43 m43;
    T44 m44;
    T45 m45;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45>
struct vector46
    : vector_data46<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45>
    , sequence_base<vector46<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45> >
{
    typedef vector46<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45> this_type;
    typedef vector_data46<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45> base_type;
    typedef mpl::vector46<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<46> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector46() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector46(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43, arg44, arg45) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector46(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41), std::forward<U42>( arg42), std::forward<U43>( arg43), std::forward<U44>( arg44), std::forward<U45>( arg45)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector46(vector46&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector46(vector46 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector46&
    operator=(vector46 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector46&
    operator=(vector46&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        this->m42 = std::forward< T42>(vec.m42);
        this->m43 = std::forward< T43>(vec.m43);
        this->m44 = std::forward< T44>(vec.m44);
        this->m45 = std::forward< T45>(vec.m45);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector46(
        vector46<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41, vec.m42, vec.m43, vec.m44, vec.m45) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector46(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector46(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector46&
    operator=(vector46<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        this->m42 = *i42;
        this->m43 = *i43;
        this->m44 = *i44;
        this->m45 = *i45;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T42>::type at_impl(mpl::int_<42>)
    {
        return this->m42;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T42>::type>::type at_impl(mpl::int_<42>) const
    {
        return this->m42;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T43>::type at_impl(mpl::int_<43>)
    {
        return this->m43;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T43>::type>::type at_impl(mpl::int_<43>) const
    {
        return this->m43;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T44>::type at_impl(mpl::int_<44>)
    {
        return this->m44;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T44>::type>::type at_impl(mpl::int_<44>) const
    {
        return this->m44;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T45>::type at_impl(mpl::int_<45>)
    {
        return this->m45;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T45>::type>::type at_impl(mpl::int_<45>) const
    {
        return this->m45;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46>
struct vector_data47
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data47()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41(), m42(), m43(), m44(), m45(), m46() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data47(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45, U46 && arg46
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)), m42(std::forward<U42>( arg42)), m43(std::forward<U43>( arg43)), m44(std::forward<U44>( arg44)), m45(std::forward<U45>( arg45)), m46(std::forward<U46>( arg46)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data47(
        vector_data47&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)), m42(std::forward<T42>( other.m42)), m43(std::forward<T43>( other.m43)), m44(std::forward<T44>( other.m44)), m45(std::forward<T45>( other.m45)), m46(std::forward<T46>( other.m46)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data47(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45, typename detail::call_param<T46 >::type arg46)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41), m42(arg42), m43(arg43), m44(arg44), m45(arg45), m46(arg46) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data47(
        vector_data47 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41), m42(other.m42), m43(other.m43), m44(other.m44), m45(other.m45), m46(other.m46) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data47&
    operator=(vector_data47 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        this->m46 = vec.m46;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data47
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        return vector_data47(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45, *i46);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data47
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        return vector_data47(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45, *i46);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
    T42 m42;
    T43 m43;
    T44 m44;
    T45 m45;
    T46 m46;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46>
struct vector47
    : vector_data47<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46>
    , sequence_base<vector47<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46> >
{
    typedef vector47<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46> this_type;
    typedef vector_data47<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46> base_type;
    typedef mpl::vector47<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<47> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector47() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector47(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45, typename detail::call_param<T46 >::type arg46)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43, arg44, arg45, arg46) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector47(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45, U46 && arg46)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41), std::forward<U42>( arg42), std::forward<U43>( arg43), std::forward<U44>( arg44), std::forward<U45>( arg45), std::forward<U46>( arg46)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector47(vector47&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector47(vector47 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector47&
    operator=(vector47 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector47&
    operator=(vector47&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        this->m42 = std::forward< T42>(vec.m42);
        this->m43 = std::forward< T43>(vec.m43);
        this->m44 = std::forward< T44>(vec.m44);
        this->m45 = std::forward< T45>(vec.m45);
        this->m46 = std::forward< T46>(vec.m46);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector47(
        vector47<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41, vec.m42, vec.m43, vec.m44, vec.m45, vec.m46) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector47(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector47(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector47&
    operator=(vector47<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        this->m46 = vec.m46;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        this->m42 = *i42;
        this->m43 = *i43;
        this->m44 = *i44;
        this->m45 = *i45;
        this->m46 = *i46;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T42>::type at_impl(mpl::int_<42>)
    {
        return this->m42;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T42>::type>::type at_impl(mpl::int_<42>) const
    {
        return this->m42;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T43>::type at_impl(mpl::int_<43>)
    {
        return this->m43;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T43>::type>::type at_impl(mpl::int_<43>) const
    {
        return this->m43;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T44>::type at_impl(mpl::int_<44>)
    {
        return this->m44;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T44>::type>::type at_impl(mpl::int_<44>) const
    {
        return this->m44;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T45>::type at_impl(mpl::int_<45>)
    {
        return this->m45;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T45>::type>::type at_impl(mpl::int_<45>) const
    {
        return this->m45;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T46>::type at_impl(mpl::int_<46>)
    {
        return this->m46;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T46>::type>::type at_impl(mpl::int_<46>) const
    {
        return this->m46;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47>
struct vector_data48
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data48()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41(), m42(), m43(), m44(), m45(), m46(), m47() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data48(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45, U46 && arg46, U47 && arg47
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)), m42(std::forward<U42>( arg42)), m43(std::forward<U43>( arg43)), m44(std::forward<U44>( arg44)), m45(std::forward<U45>( arg45)), m46(std::forward<U46>( arg46)), m47(std::forward<U47>( arg47)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data48(
        vector_data48&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)), m42(std::forward<T42>( other.m42)), m43(std::forward<T43>( other.m43)), m44(std::forward<T44>( other.m44)), m45(std::forward<T45>( other.m45)), m46(std::forward<T46>( other.m46)), m47(std::forward<T47>( other.m47)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data48(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45, typename detail::call_param<T46 >::type arg46, typename detail::call_param<T47 >::type arg47)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41), m42(arg42), m43(arg43), m44(arg44), m45(arg45), m46(arg46), m47(arg47) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data48(
        vector_data48 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41), m42(other.m42), m43(other.m43), m44(other.m44), m45(other.m45), m46(other.m46), m47(other.m47) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data48&
    operator=(vector_data48 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        this->m46 = vec.m46;
        this->m47 = vec.m47;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data48
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        return vector_data48(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45, *i46, *i47);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data48
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        return vector_data48(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45, *i46, *i47);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
    T42 m42;
    T43 m43;
    T44 m44;
    T45 m45;
    T46 m46;
    T47 m47;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47>
struct vector48
    : vector_data48<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47>
    , sequence_base<vector48<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47> >
{
    typedef vector48<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47> this_type;
    typedef vector_data48<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47> base_type;
    typedef mpl::vector48<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<48> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector48() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector48(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45, typename detail::call_param<T46 >::type arg46, typename detail::call_param<T47 >::type arg47)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43, arg44, arg45, arg46, arg47) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector48(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45, U46 && arg46, U47 && arg47)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41), std::forward<U42>( arg42), std::forward<U43>( arg43), std::forward<U44>( arg44), std::forward<U45>( arg45), std::forward<U46>( arg46), std::forward<U47>( arg47)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector48(vector48&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector48(vector48 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector48&
    operator=(vector48 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector48&
    operator=(vector48&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        this->m42 = std::forward< T42>(vec.m42);
        this->m43 = std::forward< T43>(vec.m43);
        this->m44 = std::forward< T44>(vec.m44);
        this->m45 = std::forward< T45>(vec.m45);
        this->m46 = std::forward< T46>(vec.m46);
        this->m47 = std::forward< T47>(vec.m47);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector48(
        vector48<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41, vec.m42, vec.m43, vec.m44, vec.m45, vec.m46, vec.m47) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector48(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector48(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector48&
    operator=(vector48<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        this->m46 = vec.m46;
        this->m47 = vec.m47;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        this->m42 = *i42;
        this->m43 = *i43;
        this->m44 = *i44;
        this->m45 = *i45;
        this->m46 = *i46;
        this->m47 = *i47;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T42>::type at_impl(mpl::int_<42>)
    {
        return this->m42;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T42>::type>::type at_impl(mpl::int_<42>) const
    {
        return this->m42;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T43>::type at_impl(mpl::int_<43>)
    {
        return this->m43;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T43>::type>::type at_impl(mpl::int_<43>) const
    {
        return this->m43;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T44>::type at_impl(mpl::int_<44>)
    {
        return this->m44;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T44>::type>::type at_impl(mpl::int_<44>) const
    {
        return this->m44;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T45>::type at_impl(mpl::int_<45>)
    {
        return this->m45;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T45>::type>::type at_impl(mpl::int_<45>) const
    {
        return this->m45;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T46>::type at_impl(mpl::int_<46>)
    {
        return this->m46;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T46>::type>::type at_impl(mpl::int_<46>) const
    {
        return this->m46;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T47>::type at_impl(mpl::int_<47>)
    {
        return this->m47;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T47>::type>::type at_impl(mpl::int_<47>) const
    {
        return this->m47;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47, typename T48>
struct vector_data49
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data49()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41(), m42(), m43(), m44(), m45(), m46(), m47(), m48() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data49(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45, U46 && arg46, U47 && arg47, U48 && arg48
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)), m42(std::forward<U42>( arg42)), m43(std::forward<U43>( arg43)), m44(std::forward<U44>( arg44)), m45(std::forward<U45>( arg45)), m46(std::forward<U46>( arg46)), m47(std::forward<U47>( arg47)), m48(std::forward<U48>( arg48)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data49(
        vector_data49&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)), m42(std::forward<T42>( other.m42)), m43(std::forward<T43>( other.m43)), m44(std::forward<T44>( other.m44)), m45(std::forward<T45>( other.m45)), m46(std::forward<T46>( other.m46)), m47(std::forward<T47>( other.m47)), m48(std::forward<T48>( other.m48)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data49(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45, typename detail::call_param<T46 >::type arg46, typename detail::call_param<T47 >::type arg47, typename detail::call_param<T48 >::type arg48)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41), m42(arg42), m43(arg43), m44(arg44), m45(arg45), m46(arg46), m47(arg47), m48(arg48) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data49(
        vector_data49 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41), m42(other.m42), m43(other.m43), m44(other.m44), m45(other.m45), m46(other.m46), m47(other.m47), m48(other.m48) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data49&
    operator=(vector_data49 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        this->m46 = vec.m46;
        this->m47 = vec.m47;
        this->m48 = vec.m48;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data49
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        typedef typename result_of::next< I47>::type I48;
        I48 i48 = fusion::next(i47);
        return vector_data49(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45, *i46, *i47, *i48);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data49
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        typedef typename result_of::next< I47>::type I48;
        I48 i48 = fusion::next(i47);
        return vector_data49(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45, *i46, *i47, *i48);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
    T42 m42;
    T43 m43;
    T44 m44;
    T45 m45;
    T46 m46;
    T47 m47;
    T48 m48;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47, typename T48>
struct vector49
    : vector_data49<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48>
    , sequence_base<vector49<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48> >
{
    typedef vector49<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48> this_type;
    typedef vector_data49<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48> base_type;
    typedef mpl::vector49<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<49> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector49() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector49(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45, typename detail::call_param<T46 >::type arg46, typename detail::call_param<T47 >::type arg47, typename detail::call_param<T48 >::type arg48)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43, arg44, arg45, arg46, arg47, arg48) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector49(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45, U46 && arg46, U47 && arg47, U48 && arg48)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41), std::forward<U42>( arg42), std::forward<U43>( arg43), std::forward<U44>( arg44), std::forward<U45>( arg45), std::forward<U46>( arg46), std::forward<U47>( arg47), std::forward<U48>( arg48)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector49(vector49&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector49(vector49 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector49&
    operator=(vector49 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector49&
    operator=(vector49&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        this->m42 = std::forward< T42>(vec.m42);
        this->m43 = std::forward< T43>(vec.m43);
        this->m44 = std::forward< T44>(vec.m44);
        this->m45 = std::forward< T45>(vec.m45);
        this->m46 = std::forward< T46>(vec.m46);
        this->m47 = std::forward< T47>(vec.m47);
        this->m48 = std::forward< T48>(vec.m48);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector49(
        vector49<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41, vec.m42, vec.m43, vec.m44, vec.m45, vec.m46, vec.m47, vec.m48) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector49(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector49(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector49&
    operator=(vector49<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        this->m46 = vec.m46;
        this->m47 = vec.m47;
        this->m48 = vec.m48;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        typedef typename result_of::next< I47>::type I48;
        I48 i48 = fusion::next(i47);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        this->m42 = *i42;
        this->m43 = *i43;
        this->m44 = *i44;
        this->m45 = *i45;
        this->m46 = *i46;
        this->m47 = *i47;
        this->m48 = *i48;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T42>::type at_impl(mpl::int_<42>)
    {
        return this->m42;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T42>::type>::type at_impl(mpl::int_<42>) const
    {
        return this->m42;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T43>::type at_impl(mpl::int_<43>)
    {
        return this->m43;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T43>::type>::type at_impl(mpl::int_<43>) const
    {
        return this->m43;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T44>::type at_impl(mpl::int_<44>)
    {
        return this->m44;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T44>::type>::type at_impl(mpl::int_<44>) const
    {
        return this->m44;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T45>::type at_impl(mpl::int_<45>)
    {
        return this->m45;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T45>::type>::type at_impl(mpl::int_<45>) const
    {
        return this->m45;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T46>::type at_impl(mpl::int_<46>)
    {
        return this->m46;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T46>::type>::type at_impl(mpl::int_<46>) const
    {
        return this->m46;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T47>::type at_impl(mpl::int_<47>)
    {
        return this->m47;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T47>::type>::type at_impl(mpl::int_<47>) const
    {
        return this->m47;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T48>::type at_impl(mpl::int_<48>)
    {
        return this->m48;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T48>::type>::type at_impl(mpl::int_<48>) const
    {
        return this->m48;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47, typename T48, typename T49>
struct vector_data50
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data50()
        : m0(), m1(), m2(), m3(), m4(), m5(), m6(), m7(), m8(), m9(), m10(), m11(), m12(), m13(), m14(), m15(), m16(), m17(), m18(), m19(), m20(), m21(), m22(), m23(), m24(), m25(), m26(), m27(), m28(), m29(), m30(), m31(), m32(), m33(), m34(), m35(), m36(), m37(), m38(), m39(), m40(), m41(), m42(), m43(), m44(), m45(), m46(), m47(), m48(), m49() {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data50(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45, U46 && arg46, U47 && arg47, U48 && arg48, U49 && arg49
                  , typename boost::enable_if<is_convertible<U0, T0> >::type* = 0
                 )
        : m0(std::forward<U0>( arg0)), m1(std::forward<U1>( arg1)), m2(std::forward<U2>( arg2)), m3(std::forward<U3>( arg3)), m4(std::forward<U4>( arg4)), m5(std::forward<U5>( arg5)), m6(std::forward<U6>( arg6)), m7(std::forward<U7>( arg7)), m8(std::forward<U8>( arg8)), m9(std::forward<U9>( arg9)), m10(std::forward<U10>( arg10)), m11(std::forward<U11>( arg11)), m12(std::forward<U12>( arg12)), m13(std::forward<U13>( arg13)), m14(std::forward<U14>( arg14)), m15(std::forward<U15>( arg15)), m16(std::forward<U16>( arg16)), m17(std::forward<U17>( arg17)), m18(std::forward<U18>( arg18)), m19(std::forward<U19>( arg19)), m20(std::forward<U20>( arg20)), m21(std::forward<U21>( arg21)), m22(std::forward<U22>( arg22)), m23(std::forward<U23>( arg23)), m24(std::forward<U24>( arg24)), m25(std::forward<U25>( arg25)), m26(std::forward<U26>( arg26)), m27(std::forward<U27>( arg27)), m28(std::forward<U28>( arg28)), m29(std::forward<U29>( arg29)), m30(std::forward<U30>( arg30)), m31(std::forward<U31>( arg31)), m32(std::forward<U32>( arg32)), m33(std::forward<U33>( arg33)), m34(std::forward<U34>( arg34)), m35(std::forward<U35>( arg35)), m36(std::forward<U36>( arg36)), m37(std::forward<U37>( arg37)), m38(std::forward<U38>( arg38)), m39(std::forward<U39>( arg39)), m40(std::forward<U40>( arg40)), m41(std::forward<U41>( arg41)), m42(std::forward<U42>( arg42)), m43(std::forward<U43>( arg43)), m44(std::forward<U44>( arg44)), m45(std::forward<U45>( arg45)), m46(std::forward<U46>( arg46)), m47(std::forward<U47>( arg47)), m48(std::forward<U48>( arg48)), m49(std::forward<U49>( arg49)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data50(
        vector_data50&& other)
        : m0(std::forward<T0>( other.m0)), m1(std::forward<T1>( other.m1)), m2(std::forward<T2>( other.m2)), m3(std::forward<T3>( other.m3)), m4(std::forward<T4>( other.m4)), m5(std::forward<T5>( other.m5)), m6(std::forward<T6>( other.m6)), m7(std::forward<T7>( other.m7)), m8(std::forward<T8>( other.m8)), m9(std::forward<T9>( other.m9)), m10(std::forward<T10>( other.m10)), m11(std::forward<T11>( other.m11)), m12(std::forward<T12>( other.m12)), m13(std::forward<T13>( other.m13)), m14(std::forward<T14>( other.m14)), m15(std::forward<T15>( other.m15)), m16(std::forward<T16>( other.m16)), m17(std::forward<T17>( other.m17)), m18(std::forward<T18>( other.m18)), m19(std::forward<T19>( other.m19)), m20(std::forward<T20>( other.m20)), m21(std::forward<T21>( other.m21)), m22(std::forward<T22>( other.m22)), m23(std::forward<T23>( other.m23)), m24(std::forward<T24>( other.m24)), m25(std::forward<T25>( other.m25)), m26(std::forward<T26>( other.m26)), m27(std::forward<T27>( other.m27)), m28(std::forward<T28>( other.m28)), m29(std::forward<T29>( other.m29)), m30(std::forward<T30>( other.m30)), m31(std::forward<T31>( other.m31)), m32(std::forward<T32>( other.m32)), m33(std::forward<T33>( other.m33)), m34(std::forward<T34>( other.m34)), m35(std::forward<T35>( other.m35)), m36(std::forward<T36>( other.m36)), m37(std::forward<T37>( other.m37)), m38(std::forward<T38>( other.m38)), m39(std::forward<T39>( other.m39)), m40(std::forward<T40>( other.m40)), m41(std::forward<T41>( other.m41)), m42(std::forward<T42>( other.m42)), m43(std::forward<T43>( other.m43)), m44(std::forward<T44>( other.m44)), m45(std::forward<T45>( other.m45)), m46(std::forward<T46>( other.m46)), m47(std::forward<T47>( other.m47)), m48(std::forward<T48>( other.m48)), m49(std::forward<T49>( other.m49)) {}
# endif
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector_data50(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45, typename detail::call_param<T46 >::type arg46, typename detail::call_param<T47 >::type arg47, typename detail::call_param<T48 >::type arg48, typename detail::call_param<T49 >::type arg49)
        : m0(arg0), m1(arg1), m2(arg2), m3(arg3), m4(arg4), m5(arg5), m6(arg6), m7(arg7), m8(arg8), m9(arg9), m10(arg10), m11(arg11), m12(arg12), m13(arg13), m14(arg14), m15(arg15), m16(arg16), m17(arg17), m18(arg18), m19(arg19), m20(arg20), m21(arg21), m22(arg22), m23(arg23), m24(arg24), m25(arg25), m26(arg26), m27(arg27), m28(arg28), m29(arg29), m30(arg30), m31(arg31), m32(arg32), m33(arg33), m34(arg34), m35(arg35), m36(arg36), m37(arg37), m38(arg38), m39(arg39), m40(arg40), m41(arg41), m42(arg42), m43(arg43), m44(arg44), m45(arg45), m46(arg46), m47(arg47), m48(arg48), m49(arg49) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data50(
        vector_data50 const& other)
        : m0(other.m0), m1(other.m1), m2(other.m2), m3(other.m3), m4(other.m4), m5(other.m5), m6(other.m6), m7(other.m7), m8(other.m8), m9(other.m9), m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14), m15(other.m15), m16(other.m16), m17(other.m17), m18(other.m18), m19(other.m19), m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24), m25(other.m25), m26(other.m26), m27(other.m27), m28(other.m28), m29(other.m29), m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34), m35(other.m35), m36(other.m36), m37(other.m37), m38(other.m38), m39(other.m39), m40(other.m40), m41(other.m41), m42(other.m42), m43(other.m43), m44(other.m44), m45(other.m45), m46(other.m46), m47(other.m47), m48(other.m48), m49(other.m49) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector_data50&
    operator=(vector_data50 const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        this->m46 = vec.m46;
        this->m47 = vec.m47;
        this->m48 = vec.m48;
        this->m49 = vec.m49;
        return *this;
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data50
    init_from_sequence(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        typedef typename result_of::next< I47>::type I48;
        I48 i48 = fusion::next(i47);
        typedef typename result_of::next< I48>::type I49;
        I49 i49 = fusion::next(i48);
        return vector_data50(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45, *i46, *i47, *i48, *i49);
    }
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    static vector_data50
    init_from_sequence(Sequence& seq)
    {
        typedef typename result_of::begin<Sequence>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        typedef typename result_of::next< I47>::type I48;
        I48 i48 = fusion::next(i47);
        typedef typename result_of::next< I48>::type I49;
        I49 i49 = fusion::next(i48);
        return vector_data50(*i0, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *i12, *i13, *i14, *i15, *i16, *i17, *i18, *i19, *i20, *i21, *i22, *i23, *i24, *i25, *i26, *i27, *i28, *i29, *i30, *i31, *i32, *i33, *i34, *i35, *i36, *i37, *i38, *i39, *i40, *i41, *i42, *i43, *i44, *i45, *i46, *i47, *i48, *i49);
    }
    T0 m0;
    T1 m1;
    T2 m2;
    T3 m3;
    T4 m4;
    T5 m5;
    T6 m6;
    T7 m7;
    T8 m8;
    T9 m9;
    T10 m10;
    T11 m11;
    T12 m12;
    T13 m13;
    T14 m14;
    T15 m15;
    T16 m16;
    T17 m17;
    T18 m18;
    T19 m19;
    T20 m20;
    T21 m21;
    T22 m22;
    T23 m23;
    T24 m24;
    T25 m25;
    T26 m26;
    T27 m27;
    T28 m28;
    T29 m29;
    T30 m30;
    T31 m31;
    T32 m32;
    T33 m33;
    T34 m34;
    T35 m35;
    T36 m36;
    T37 m37;
    T38 m38;
    T39 m39;
    T40 m40;
    T41 m41;
    T42 m42;
    T43 m43;
    T44 m44;
    T45 m45;
    T46 m46;
    T47 m47;
    T48 m48;
    T49 m49;
};
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47, typename T48, typename T49>
struct vector50
    : vector_data50<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49>
    , sequence_base<vector50<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49> >
{
    typedef vector50<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49> this_type;
    typedef vector_data50<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49> base_type;
    typedef mpl::vector50<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49> types;
    typedef vector_tag fusion_tag;
    typedef fusion_sequence_tag tag;
    typedef mpl::false_ is_view;
    typedef random_access_traversal_tag category;
    typedef mpl::int_<50> size;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector50() {}
# if !defined(BOOST_CLANG)
    BOOST_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector50(
        typename detail::call_param<T0 >::type arg0, typename detail::call_param<T1 >::type arg1, typename detail::call_param<T2 >::type arg2, typename detail::call_param<T3 >::type arg3, typename detail::call_param<T4 >::type arg4, typename detail::call_param<T5 >::type arg5, typename detail::call_param<T6 >::type arg6, typename detail::call_param<T7 >::type arg7, typename detail::call_param<T8 >::type arg8, typename detail::call_param<T9 >::type arg9, typename detail::call_param<T10 >::type arg10, typename detail::call_param<T11 >::type arg11, typename detail::call_param<T12 >::type arg12, typename detail::call_param<T13 >::type arg13, typename detail::call_param<T14 >::type arg14, typename detail::call_param<T15 >::type arg15, typename detail::call_param<T16 >::type arg16, typename detail::call_param<T17 >::type arg17, typename detail::call_param<T18 >::type arg18, typename detail::call_param<T19 >::type arg19, typename detail::call_param<T20 >::type arg20, typename detail::call_param<T21 >::type arg21, typename detail::call_param<T22 >::type arg22, typename detail::call_param<T23 >::type arg23, typename detail::call_param<T24 >::type arg24, typename detail::call_param<T25 >::type arg25, typename detail::call_param<T26 >::type arg26, typename detail::call_param<T27 >::type arg27, typename detail::call_param<T28 >::type arg28, typename detail::call_param<T29 >::type arg29, typename detail::call_param<T30 >::type arg30, typename detail::call_param<T31 >::type arg31, typename detail::call_param<T32 >::type arg32, typename detail::call_param<T33 >::type arg33, typename detail::call_param<T34 >::type arg34, typename detail::call_param<T35 >::type arg35, typename detail::call_param<T36 >::type arg36, typename detail::call_param<T37 >::type arg37, typename detail::call_param<T38 >::type arg38, typename detail::call_param<T39 >::type arg39, typename detail::call_param<T40 >::type arg40, typename detail::call_param<T41 >::type arg41, typename detail::call_param<T42 >::type arg42, typename detail::call_param<T43 >::type arg43, typename detail::call_param<T44 >::type arg44, typename detail::call_param<T45 >::type arg45, typename detail::call_param<T46 >::type arg46, typename detail::call_param<T47 >::type arg47, typename detail::call_param<T48 >::type arg48, typename detail::call_param<T49 >::type arg49)
        : base_type(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43, arg44, arg45, arg46, arg47, arg48, arg49) {}
# if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector50(U0 && arg0, U1 && arg1, U2 && arg2, U3 && arg3, U4 && arg4, U5 && arg5, U6 && arg6, U7 && arg7, U8 && arg8, U9 && arg9, U10 && arg10, U11 && arg11, U12 && arg12, U13 && arg13, U14 && arg14, U15 && arg15, U16 && arg16, U17 && arg17, U18 && arg18, U19 && arg19, U20 && arg20, U21 && arg21, U22 && arg22, U23 && arg23, U24 && arg24, U25 && arg25, U26 && arg26, U27 && arg27, U28 && arg28, U29 && arg29, U30 && arg30, U31 && arg31, U32 && arg32, U33 && arg33, U34 && arg34, U35 && arg35, U36 && arg36, U37 && arg37, U38 && arg38, U39 && arg39, U40 && arg40, U41 && arg41, U42 && arg42, U43 && arg43, U44 && arg44, U45 && arg45, U46 && arg46, U47 && arg47, U48 && arg48, U49 && arg49)
        : base_type(std::forward<U0>( arg0), std::forward<U1>( arg1), std::forward<U2>( arg2), std::forward<U3>( arg3), std::forward<U4>( arg4), std::forward<U5>( arg5), std::forward<U6>( arg6), std::forward<U7>( arg7), std::forward<U8>( arg8), std::forward<U9>( arg9), std::forward<U10>( arg10), std::forward<U11>( arg11), std::forward<U12>( arg12), std::forward<U13>( arg13), std::forward<U14>( arg14), std::forward<U15>( arg15), std::forward<U16>( arg16), std::forward<U17>( arg17), std::forward<U18>( arg18), std::forward<U19>( arg19), std::forward<U20>( arg20), std::forward<U21>( arg21), std::forward<U22>( arg22), std::forward<U23>( arg23), std::forward<U24>( arg24), std::forward<U25>( arg25), std::forward<U26>( arg26), std::forward<U27>( arg27), std::forward<U28>( arg28), std::forward<U29>( arg29), std::forward<U30>( arg30), std::forward<U31>( arg31), std::forward<U32>( arg32), std::forward<U33>( arg33), std::forward<U34>( arg34), std::forward<U35>( arg35), std::forward<U36>( arg36), std::forward<U37>( arg37), std::forward<U38>( arg38), std::forward<U39>( arg39), std::forward<U40>( arg40), std::forward<U41>( arg41), std::forward<U42>( arg42), std::forward<U43>( arg43), std::forward<U44>( arg44), std::forward<U45>( arg45), std::forward<U46>( arg46), std::forward<U47>( arg47), std::forward<U48>( arg48), std::forward<U49>( arg49)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector50(vector50&& rhs)
        : base_type(std::forward<base_type>(rhs)) {}
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector50(vector50 const& rhs)
        : base_type(static_cast<base_type const&>(rhs)) {}
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector50&
    operator=(vector50 const& vec)
    {
        base_type::operator=(vec);
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector50&
    operator=(vector50&& vec)
    {
        this->m0 = std::forward< T0>(vec.m0);
        this->m1 = std::forward< T1>(vec.m1);
        this->m2 = std::forward< T2>(vec.m2);
        this->m3 = std::forward< T3>(vec.m3);
        this->m4 = std::forward< T4>(vec.m4);
        this->m5 = std::forward< T5>(vec.m5);
        this->m6 = std::forward< T6>(vec.m6);
        this->m7 = std::forward< T7>(vec.m7);
        this->m8 = std::forward< T8>(vec.m8);
        this->m9 = std::forward< T9>(vec.m9);
        this->m10 = std::forward< T10>(vec.m10);
        this->m11 = std::forward< T11>(vec.m11);
        this->m12 = std::forward< T12>(vec.m12);
        this->m13 = std::forward< T13>(vec.m13);
        this->m14 = std::forward< T14>(vec.m14);
        this->m15 = std::forward< T15>(vec.m15);
        this->m16 = std::forward< T16>(vec.m16);
        this->m17 = std::forward< T17>(vec.m17);
        this->m18 = std::forward< T18>(vec.m18);
        this->m19 = std::forward< T19>(vec.m19);
        this->m20 = std::forward< T20>(vec.m20);
        this->m21 = std::forward< T21>(vec.m21);
        this->m22 = std::forward< T22>(vec.m22);
        this->m23 = std::forward< T23>(vec.m23);
        this->m24 = std::forward< T24>(vec.m24);
        this->m25 = std::forward< T25>(vec.m25);
        this->m26 = std::forward< T26>(vec.m26);
        this->m27 = std::forward< T27>(vec.m27);
        this->m28 = std::forward< T28>(vec.m28);
        this->m29 = std::forward< T29>(vec.m29);
        this->m30 = std::forward< T30>(vec.m30);
        this->m31 = std::forward< T31>(vec.m31);
        this->m32 = std::forward< T32>(vec.m32);
        this->m33 = std::forward< T33>(vec.m33);
        this->m34 = std::forward< T34>(vec.m34);
        this->m35 = std::forward< T35>(vec.m35);
        this->m36 = std::forward< T36>(vec.m36);
        this->m37 = std::forward< T37>(vec.m37);
        this->m38 = std::forward< T38>(vec.m38);
        this->m39 = std::forward< T39>(vec.m39);
        this->m40 = std::forward< T40>(vec.m40);
        this->m41 = std::forward< T41>(vec.m41);
        this->m42 = std::forward< T42>(vec.m42);
        this->m43 = std::forward< T43>(vec.m43);
        this->m44 = std::forward< T44>(vec.m44);
        this->m45 = std::forward< T45>(vec.m45);
        this->m46 = std::forward< T46>(vec.m46);
        this->m47 = std::forward< T47>(vec.m47);
        this->m48 = std::forward< T48>(vec.m48);
        this->m49 = std::forward< T49>(vec.m49);
        return *this;
    }
# endif
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector50(
        vector50<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49> const& vec)
        : base_type(vec.m0, vec.m1, vec.m2, vec.m3, vec.m4, vec.m5, vec.m6, vec.m7, vec.m8, vec.m9, vec.m10, vec.m11, vec.m12, vec.m13, vec.m14, vec.m15, vec.m16, vec.m17, vec.m18, vec.m19, vec.m20, vec.m21, vec.m22, vec.m23, vec.m24, vec.m25, vec.m26, vec.m27, vec.m28, vec.m29, vec.m30, vec.m31, vec.m32, vec.m33, vec.m34, vec.m35, vec.m36, vec.m37, vec.m38, vec.m39, vec.m40, vec.m41, vec.m42, vec.m43, vec.m44, vec.m45, vec.m46, vec.m47, vec.m48, vec.m49) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector50(
        Sequence const& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename Sequence>
# if !defined(BOOST_CLANG)
    BOOST_CXX14_CONSTEXPR
# endif
    BOOST_FUSION_GPU_ENABLED
    vector50(
        Sequence& seq
        , typename boost::enable_if<traits::is_sequence<Sequence> >::type* = 0
    )
        : base_type(base_type::init_from_sequence(seq)) {}
    template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7, typename U8, typename U9, typename U10, typename U11, typename U12, typename U13, typename U14, typename U15, typename U16, typename U17, typename U18, typename U19, typename U20, typename U21, typename U22, typename U23, typename U24, typename U25, typename U26, typename U27, typename U28, typename U29, typename U30, typename U31, typename U32, typename U33, typename U34, typename U35, typename U36, typename U37, typename U38, typename U39, typename U40, typename U41, typename U42, typename U43, typename U44, typename U45, typename U46, typename U47, typename U48, typename U49>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    vector50&
    operator=(vector50<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18, U19, U20, U21, U22, U23, U24, U25, U26, U27, U28, U29, U30, U31, U32, U33, U34, U35, U36, U37, U38, U39, U40, U41, U42, U43, U44, U45, U46, U47, U48, U49> const& vec)
    {
        this->m0 = vec.m0;
        this->m1 = vec.m1;
        this->m2 = vec.m2;
        this->m3 = vec.m3;
        this->m4 = vec.m4;
        this->m5 = vec.m5;
        this->m6 = vec.m6;
        this->m7 = vec.m7;
        this->m8 = vec.m8;
        this->m9 = vec.m9;
        this->m10 = vec.m10;
        this->m11 = vec.m11;
        this->m12 = vec.m12;
        this->m13 = vec.m13;
        this->m14 = vec.m14;
        this->m15 = vec.m15;
        this->m16 = vec.m16;
        this->m17 = vec.m17;
        this->m18 = vec.m18;
        this->m19 = vec.m19;
        this->m20 = vec.m20;
        this->m21 = vec.m21;
        this->m22 = vec.m22;
        this->m23 = vec.m23;
        this->m24 = vec.m24;
        this->m25 = vec.m25;
        this->m26 = vec.m26;
        this->m27 = vec.m27;
        this->m28 = vec.m28;
        this->m29 = vec.m29;
        this->m30 = vec.m30;
        this->m31 = vec.m31;
        this->m32 = vec.m32;
        this->m33 = vec.m33;
        this->m34 = vec.m34;
        this->m35 = vec.m35;
        this->m36 = vec.m36;
        this->m37 = vec.m37;
        this->m38 = vec.m38;
        this->m39 = vec.m39;
        this->m40 = vec.m40;
        this->m41 = vec.m41;
        this->m42 = vec.m42;
        this->m43 = vec.m43;
        this->m44 = vec.m44;
        this->m45 = vec.m45;
        this->m46 = vec.m46;
        this->m47 = vec.m47;
        this->m48 = vec.m48;
        this->m49 = vec.m49;
        return *this;
    }
    template <typename Sequence>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename boost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
    operator=(Sequence const& seq)
    {
        typedef typename result_of::begin<Sequence const>::type I0;
        I0 i0 = fusion::begin(seq);
        typedef typename result_of::next< I0>::type I1;
        I1 i1 = fusion::next(i0);
        typedef typename result_of::next< I1>::type I2;
        I2 i2 = fusion::next(i1);
        typedef typename result_of::next< I2>::type I3;
        I3 i3 = fusion::next(i2);
        typedef typename result_of::next< I3>::type I4;
        I4 i4 = fusion::next(i3);
        typedef typename result_of::next< I4>::type I5;
        I5 i5 = fusion::next(i4);
        typedef typename result_of::next< I5>::type I6;
        I6 i6 = fusion::next(i5);
        typedef typename result_of::next< I6>::type I7;
        I7 i7 = fusion::next(i6);
        typedef typename result_of::next< I7>::type I8;
        I8 i8 = fusion::next(i7);
        typedef typename result_of::next< I8>::type I9;
        I9 i9 = fusion::next(i8);
        typedef typename result_of::next< I9>::type I10;
        I10 i10 = fusion::next(i9);
        typedef typename result_of::next< I10>::type I11;
        I11 i11 = fusion::next(i10);
        typedef typename result_of::next< I11>::type I12;
        I12 i12 = fusion::next(i11);
        typedef typename result_of::next< I12>::type I13;
        I13 i13 = fusion::next(i12);
        typedef typename result_of::next< I13>::type I14;
        I14 i14 = fusion::next(i13);
        typedef typename result_of::next< I14>::type I15;
        I15 i15 = fusion::next(i14);
        typedef typename result_of::next< I15>::type I16;
        I16 i16 = fusion::next(i15);
        typedef typename result_of::next< I16>::type I17;
        I17 i17 = fusion::next(i16);
        typedef typename result_of::next< I17>::type I18;
        I18 i18 = fusion::next(i17);
        typedef typename result_of::next< I18>::type I19;
        I19 i19 = fusion::next(i18);
        typedef typename result_of::next< I19>::type I20;
        I20 i20 = fusion::next(i19);
        typedef typename result_of::next< I20>::type I21;
        I21 i21 = fusion::next(i20);
        typedef typename result_of::next< I21>::type I22;
        I22 i22 = fusion::next(i21);
        typedef typename result_of::next< I22>::type I23;
        I23 i23 = fusion::next(i22);
        typedef typename result_of::next< I23>::type I24;
        I24 i24 = fusion::next(i23);
        typedef typename result_of::next< I24>::type I25;
        I25 i25 = fusion::next(i24);
        typedef typename result_of::next< I25>::type I26;
        I26 i26 = fusion::next(i25);
        typedef typename result_of::next< I26>::type I27;
        I27 i27 = fusion::next(i26);
        typedef typename result_of::next< I27>::type I28;
        I28 i28 = fusion::next(i27);
        typedef typename result_of::next< I28>::type I29;
        I29 i29 = fusion::next(i28);
        typedef typename result_of::next< I29>::type I30;
        I30 i30 = fusion::next(i29);
        typedef typename result_of::next< I30>::type I31;
        I31 i31 = fusion::next(i30);
        typedef typename result_of::next< I31>::type I32;
        I32 i32 = fusion::next(i31);
        typedef typename result_of::next< I32>::type I33;
        I33 i33 = fusion::next(i32);
        typedef typename result_of::next< I33>::type I34;
        I34 i34 = fusion::next(i33);
        typedef typename result_of::next< I34>::type I35;
        I35 i35 = fusion::next(i34);
        typedef typename result_of::next< I35>::type I36;
        I36 i36 = fusion::next(i35);
        typedef typename result_of::next< I36>::type I37;
        I37 i37 = fusion::next(i36);
        typedef typename result_of::next< I37>::type I38;
        I38 i38 = fusion::next(i37);
        typedef typename result_of::next< I38>::type I39;
        I39 i39 = fusion::next(i38);
        typedef typename result_of::next< I39>::type I40;
        I40 i40 = fusion::next(i39);
        typedef typename result_of::next< I40>::type I41;
        I41 i41 = fusion::next(i40);
        typedef typename result_of::next< I41>::type I42;
        I42 i42 = fusion::next(i41);
        typedef typename result_of::next< I42>::type I43;
        I43 i43 = fusion::next(i42);
        typedef typename result_of::next< I43>::type I44;
        I44 i44 = fusion::next(i43);
        typedef typename result_of::next< I44>::type I45;
        I45 i45 = fusion::next(i44);
        typedef typename result_of::next< I45>::type I46;
        I46 i46 = fusion::next(i45);
        typedef typename result_of::next< I46>::type I47;
        I47 i47 = fusion::next(i46);
        typedef typename result_of::next< I47>::type I48;
        I48 i48 = fusion::next(i47);
        typedef typename result_of::next< I48>::type I49;
        I49 i49 = fusion::next(i48);
        this->m0 = *i0;
        this->m1 = *i1;
        this->m2 = *i2;
        this->m3 = *i3;
        this->m4 = *i4;
        this->m5 = *i5;
        this->m6 = *i6;
        this->m7 = *i7;
        this->m8 = *i8;
        this->m9 = *i9;
        this->m10 = *i10;
        this->m11 = *i11;
        this->m12 = *i12;
        this->m13 = *i13;
        this->m14 = *i14;
        this->m15 = *i15;
        this->m16 = *i16;
        this->m17 = *i17;
        this->m18 = *i18;
        this->m19 = *i19;
        this->m20 = *i20;
        this->m21 = *i21;
        this->m22 = *i22;
        this->m23 = *i23;
        this->m24 = *i24;
        this->m25 = *i25;
        this->m26 = *i26;
        this->m27 = *i27;
        this->m28 = *i28;
        this->m29 = *i29;
        this->m30 = *i30;
        this->m31 = *i31;
        this->m32 = *i32;
        this->m33 = *i33;
        this->m34 = *i34;
        this->m35 = *i35;
        this->m36 = *i36;
        this->m37 = *i37;
        this->m38 = *i38;
        this->m39 = *i39;
        this->m40 = *i40;
        this->m41 = *i41;
        this->m42 = *i42;
        this->m43 = *i43;
        this->m44 = *i44;
        this->m45 = *i45;
        this->m46 = *i46;
        this->m47 = *i47;
        this->m48 = *i48;
        this->m49 = *i49;
        return *this;
    }
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T0>::type
    at_impl(mpl::int_<0>)
    {
        return this->m0;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T0>::type>::type at_impl(mpl::int_<0>) const
    {
        return this->m0;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T1>::type at_impl(mpl::int_<1>)
    {
        return this->m1;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T1>::type>::type at_impl(mpl::int_<1>) const
    {
        return this->m1;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T2>::type at_impl(mpl::int_<2>)
    {
        return this->m2;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T2>::type>::type at_impl(mpl::int_<2>) const
    {
        return this->m2;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T3>::type at_impl(mpl::int_<3>)
    {
        return this->m3;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T3>::type>::type at_impl(mpl::int_<3>) const
    {
        return this->m3;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T4>::type at_impl(mpl::int_<4>)
    {
        return this->m4;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T4>::type>::type at_impl(mpl::int_<4>) const
    {
        return this->m4;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T5>::type at_impl(mpl::int_<5>)
    {
        return this->m5;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T5>::type>::type at_impl(mpl::int_<5>) const
    {
        return this->m5;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T6>::type at_impl(mpl::int_<6>)
    {
        return this->m6;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T6>::type>::type at_impl(mpl::int_<6>) const
    {
        return this->m6;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T7>::type at_impl(mpl::int_<7>)
    {
        return this->m7;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T7>::type>::type at_impl(mpl::int_<7>) const
    {
        return this->m7;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T8>::type at_impl(mpl::int_<8>)
    {
        return this->m8;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T8>::type>::type at_impl(mpl::int_<8>) const
    {
        return this->m8;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T9>::type at_impl(mpl::int_<9>)
    {
        return this->m9;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T9>::type>::type at_impl(mpl::int_<9>) const
    {
        return this->m9;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T10>::type at_impl(mpl::int_<10>)
    {
        return this->m10;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T10>::type>::type at_impl(mpl::int_<10>) const
    {
        return this->m10;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T11>::type at_impl(mpl::int_<11>)
    {
        return this->m11;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T11>::type>::type at_impl(mpl::int_<11>) const
    {
        return this->m11;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T12>::type at_impl(mpl::int_<12>)
    {
        return this->m12;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T12>::type>::type at_impl(mpl::int_<12>) const
    {
        return this->m12;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T13>::type at_impl(mpl::int_<13>)
    {
        return this->m13;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T13>::type>::type at_impl(mpl::int_<13>) const
    {
        return this->m13;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T14>::type at_impl(mpl::int_<14>)
    {
        return this->m14;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T14>::type>::type at_impl(mpl::int_<14>) const
    {
        return this->m14;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T15>::type at_impl(mpl::int_<15>)
    {
        return this->m15;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T15>::type>::type at_impl(mpl::int_<15>) const
    {
        return this->m15;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T16>::type at_impl(mpl::int_<16>)
    {
        return this->m16;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T16>::type>::type at_impl(mpl::int_<16>) const
    {
        return this->m16;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T17>::type at_impl(mpl::int_<17>)
    {
        return this->m17;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T17>::type>::type at_impl(mpl::int_<17>) const
    {
        return this->m17;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T18>::type at_impl(mpl::int_<18>)
    {
        return this->m18;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T18>::type>::type at_impl(mpl::int_<18>) const
    {
        return this->m18;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T19>::type at_impl(mpl::int_<19>)
    {
        return this->m19;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T19>::type>::type at_impl(mpl::int_<19>) const
    {
        return this->m19;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T20>::type at_impl(mpl::int_<20>)
    {
        return this->m20;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T20>::type>::type at_impl(mpl::int_<20>) const
    {
        return this->m20;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T21>::type at_impl(mpl::int_<21>)
    {
        return this->m21;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T21>::type>::type at_impl(mpl::int_<21>) const
    {
        return this->m21;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T22>::type at_impl(mpl::int_<22>)
    {
        return this->m22;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T22>::type>::type at_impl(mpl::int_<22>) const
    {
        return this->m22;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T23>::type at_impl(mpl::int_<23>)
    {
        return this->m23;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T23>::type>::type at_impl(mpl::int_<23>) const
    {
        return this->m23;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T24>::type at_impl(mpl::int_<24>)
    {
        return this->m24;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T24>::type>::type at_impl(mpl::int_<24>) const
    {
        return this->m24;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T25>::type at_impl(mpl::int_<25>)
    {
        return this->m25;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T25>::type>::type at_impl(mpl::int_<25>) const
    {
        return this->m25;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T26>::type at_impl(mpl::int_<26>)
    {
        return this->m26;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T26>::type>::type at_impl(mpl::int_<26>) const
    {
        return this->m26;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T27>::type at_impl(mpl::int_<27>)
    {
        return this->m27;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T27>::type>::type at_impl(mpl::int_<27>) const
    {
        return this->m27;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T28>::type at_impl(mpl::int_<28>)
    {
        return this->m28;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T28>::type>::type at_impl(mpl::int_<28>) const
    {
        return this->m28;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T29>::type at_impl(mpl::int_<29>)
    {
        return this->m29;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T29>::type>::type at_impl(mpl::int_<29>) const
    {
        return this->m29;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T30>::type at_impl(mpl::int_<30>)
    {
        return this->m30;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T30>::type>::type at_impl(mpl::int_<30>) const
    {
        return this->m30;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T31>::type at_impl(mpl::int_<31>)
    {
        return this->m31;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T31>::type>::type at_impl(mpl::int_<31>) const
    {
        return this->m31;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T32>::type at_impl(mpl::int_<32>)
    {
        return this->m32;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T32>::type>::type at_impl(mpl::int_<32>) const
    {
        return this->m32;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T33>::type at_impl(mpl::int_<33>)
    {
        return this->m33;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T33>::type>::type at_impl(mpl::int_<33>) const
    {
        return this->m33;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T34>::type at_impl(mpl::int_<34>)
    {
        return this->m34;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T34>::type>::type at_impl(mpl::int_<34>) const
    {
        return this->m34;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T35>::type at_impl(mpl::int_<35>)
    {
        return this->m35;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T35>::type>::type at_impl(mpl::int_<35>) const
    {
        return this->m35;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T36>::type at_impl(mpl::int_<36>)
    {
        return this->m36;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T36>::type>::type at_impl(mpl::int_<36>) const
    {
        return this->m36;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T37>::type at_impl(mpl::int_<37>)
    {
        return this->m37;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T37>::type>::type at_impl(mpl::int_<37>) const
    {
        return this->m37;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T38>::type at_impl(mpl::int_<38>)
    {
        return this->m38;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T38>::type>::type at_impl(mpl::int_<38>) const
    {
        return this->m38;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T39>::type at_impl(mpl::int_<39>)
    {
        return this->m39;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T39>::type>::type at_impl(mpl::int_<39>) const
    {
        return this->m39;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T40>::type at_impl(mpl::int_<40>)
    {
        return this->m40;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T40>::type>::type at_impl(mpl::int_<40>) const
    {
        return this->m40;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T41>::type at_impl(mpl::int_<41>)
    {
        return this->m41;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T41>::type>::type at_impl(mpl::int_<41>) const
    {
        return this->m41;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T42>::type at_impl(mpl::int_<42>)
    {
        return this->m42;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T42>::type>::type at_impl(mpl::int_<42>) const
    {
        return this->m42;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T43>::type at_impl(mpl::int_<43>)
    {
        return this->m43;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T43>::type>::type at_impl(mpl::int_<43>) const
    {
        return this->m43;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T44>::type at_impl(mpl::int_<44>)
    {
        return this->m44;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T44>::type>::type at_impl(mpl::int_<44>) const
    {
        return this->m44;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T45>::type at_impl(mpl::int_<45>)
    {
        return this->m45;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T45>::type>::type at_impl(mpl::int_<45>) const
    {
        return this->m45;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T46>::type at_impl(mpl::int_<46>)
    {
        return this->m46;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T46>::type>::type at_impl(mpl::int_<46>) const
    {
        return this->m46;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T47>::type at_impl(mpl::int_<47>)
    {
        return this->m47;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T47>::type>::type at_impl(mpl::int_<47>) const
    {
        return this->m47;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T48>::type at_impl(mpl::int_<48>)
    {
        return this->m48;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T48>::type>::type at_impl(mpl::int_<48>) const
    {
        return this->m48;
    } BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<T49>::type at_impl(mpl::int_<49>)
    {
        return this->m49;
    } BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED typename add_reference<typename add_const<T49>::type>::type at_impl(mpl::int_<49>) const
    {
        return this->m49;
    }
    template<typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename mpl::at<types, I>::type>::type
    at_impl(I)
    {
        return this->at_impl(mpl::int_<I::value>());
    }
    template<typename I>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
    at_impl(I) const
    {
        return this->at_impl(mpl::int_<I::value>());
    }
};
}
}
