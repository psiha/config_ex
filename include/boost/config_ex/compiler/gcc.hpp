////////////////////////////////////////////////////////////////////////////////
///
/// \file gcc.hpp
/// -------------
///
/// Boost.Config wrappers/extensions
///
/// (c) Copyright Domagoj Saric 2016 - 2017.
///
///  Use, modification and distribution are subject to the
///  Boost Software License, Version 1.0. (See accompanying file
///  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///
///  See http://www.boost.org for most recent version.
///
////////////////////////////////////////////////////////////////////////////////

#include "gcc_compatible.hpp"

#if ( ( __GNUC__ * 10 ) + __GNUC_MINOR__ ) >= 47
#   define BOOST_OVERRIDE override
#   define BOOST_FINAL    final
#endif

#define BOOST_MINSIZE optimize( "Os" )

#ifdef __i386__
#   undef  BOOST_CC_REG
#   define BOOST_CC_REG __attribute__(( regparm( 3 ), stdcall, sseregparm ))
#endif

#if ( ( ( __GNUC__ * 10 ) + __GNUC_MINOR__ ) >= 44 )
    // http://gcc.gnu.org/bugzilla/show_bug.cgi?id=41201
    // http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52144
    #define BOOST_OPTIMIZE_FOR_SPEED_BEGIN()  \
        _Pragma( "GCC push_options"        )  \
        _Pragma( "GCC optimize ( \"O3\" )" )  \

    #define BOOST_OPTIMIZE_FOR_SPEED_END() \
        _Pragma( "GCC pop_options" )       \

    #define BOOST_OPTIMIZE_FOR_SIZE_BEGIN()  \
        _Pragma( "GCC push_options"        ) \
        _Pragma( "GCC optimize ( \"Os\" )" ) \

    #define BOOST_OPTIMIZE_FOR_SIZE_END BOOST_OPTIMIZE_FOR_SPEED_END


    // http://lists.cs.uiuc.edu/pipermail/llvmdev/2013-April/061527.html
    // http://gcc.gnu.org/bugzilla/show_bug.cgi?id=50782
    #define BOOST_FAST_MATH_ON()  _Pragma( "GCC optimize ( \"associative-math\"    )" )
    #define BOOST_FAST_MATH_OFF() _Pragma( "GCC optimize ( \"no-associative-math\" )" )

    #define BOOST_FAST_MATH_ON_BEGIN() \
        _Pragma( "GCC push_options" )  \
        BOOST_FAST_MATH_ON()

    #define BOOST_FAST_MATH_ON_END() _Pragma( "GCC pop_options" )

    #define BOOST_FAST_MATH_OFF_BEGIN() \
        _Pragma( "GCC push_options" )   \
        BOOST_FAST_MATH_OFF()

    #define BOOST_FAST_MATH_OFF_END() _Pragma( "GCC pop_options" )
#endif
