////////////////////////////////////////////////////////////////////////////////
///
/// \file confix_ex.hpp
/// -------------------
///
/// boost/config.hpp wrapper
///
/// (c) Copyright Domagoj Saric 2016.
///
///  Use, modification and distribution are subject to the
///  Boost Software License, Version 1.0. (See accompanying file
///  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///
///  See http://www.boost.org for most recent version.
///
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <boost/config.hpp>

#if defined __clang__ && !defined(__CUDACC__) && !defined(__ibmxl__)
#   define BOOST_COMPILER_CONFIG_EX "boost/config_ex/compiler/clang.hpp"
# elif defined(__GNUC__) && !defined(__ibmxl__)
#   define BOOST_COMPILER_CONFIG_EX "boost/config_ex/compiler/gcc.hpp"
#elif defined BOOST_MSVC
#   define BOOST_COMPILER_CONFIG_EX "boost/config_ex/compiler/visualc.hpp"
#endif

#ifdef BOOST_COMPILER_CONFIG_EX
#  include BOOST_COMPILER_CONFIG_EX
#endif

#include <boost/config_ex/suffix.hpp>
