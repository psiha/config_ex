// (C) Copyright Domagoj Saric  2015
//
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

// Clang compiler setup.

#include "gcc_compatible.hpp"


#ifndef __has_declspec_attribute
#   define __has_declspec_attribute(x) 0
#endif

#if __has_builtin( __builtin_assume )
#   define BOOST_ASSUME_UNCHECKED( condition ) __builtin_assume( condition )
#endif

#define BOOST_OVERRIDE override
#define BOOST_FINAL    final

#define BOOST_MINSIZE minsize

// Requires -fms-extensions
#if __has_declspec_attribute( novtable )
    #define BOOST_NOVTABLE __declspec( novtable )
#endif

#if defined( __SSE2__ ) && __has_attribute( vectorcall )
#   undef  BOOST_CC_REG
#   define BOOST_CC_REG __attribute__(( vectorcall ))
#endif

// No support for fast-math and size<->speed optimisation macros/pragmas yet...
// http://lists.cs.uiuc.edu/pipermail/llvmdev/2013-April/061527.html
// http://comments.gmane.org/gmane.comp.compilers.clang.devel/28958

