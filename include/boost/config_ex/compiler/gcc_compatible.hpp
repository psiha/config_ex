////////////////////////////////////////////////////////////////////////////////
///
/// \file gcc_compatible.hpp
/// ------------------------
///
/// Definitions shared between GCC and its 'compatibles'/'emulators' (e.g.
/// Clang)
///
/// (c) Copyright Domagoj Saric 2015 - 2017.
///
///  Use, modification and distribution are subject to the
///  Boost Software License, Version 1.0. (See accompanying file
///  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///
///  See http://www.boost.org for most recent version.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------

// Branch prediction hints
#ifndef BOOST_LIKELY
#    define BOOST_LIKELY(   x ) __builtin_expect( x, true  )
#    define BOOST_UNLIKELY( x ) __builtin_expect( x, false )
#endif // BOOST_LIKELY

#define BOOST_UNREACHABLE_UNCHECKED() __builtin_unreachable()

#define BOOST_ATTRIBUTES( ... ) __attribute__(( __VA_ARGS__ ))
#define BOOST_RESTRICTED_FUNCTION_L1     
#define BOOST_RESTRICTED_FUNCTION_L2     pure
#define BOOST_RESTRICTED_FUNCTION_L3     const
#define BOOST_RESTRICTED_FUNCTION_RETURN malloc
#define BOOST_HOT                        hot
#define BOOST_COLD                       cold
#define BOOST_EXCEPTIONLESS              nothrow
#define BOOST_DOES_NOT_RETURN            noreturn
#define BOOST_WARN_UNUSED_RESULT         warn_unused_result

#ifdef __i386__
#   define BOOST_CC_CDECL    __attribute__(( cdecl    ))
#   define BOOST_CC_FASTCALL __attribute__(( fastcall ))
#   define BOOST_CC_STDCALL  __attribute__(( stdcall  ))
#   define BOOST_CC_STACK    BOOST_CC_STDCALL
#   define BOOST_CC_REG_ABI  __attribute__(( regparm( 3 ), stdcall ))
#   define BOOST_CC_REG      BOOST_CC_REG_ABI
#endif // __i386__

#ifdef __x86_64__
#ifdef _WIN32
#   define BOOST_CC_FASTCALL __attribute__(( sysv_abi ))
#   define BOOST_CC_REG_ABI  __attribute__(( sysv_abi ))
#endif // Windows
#endif // __x86_64__

#define BOOST_NOTHROW_LITE __attribute__(( nothrow ))

#define BOOST_THREAD_LOCAL_POD __thread

#define BOOST_RESTRICTED __restrict__

#define BOOST_HAS_UNION_TYPE_PUNNING_TRICK

#define BOOST_OVERRIDABLE_SYMBOL        extern __attribute__(( weak ))
#define BOOST_OVERRIDABLE_MEMBER_SYMBOL __attribute__(( weak ))
#define BOOST_OVERRIDABLE_FUNCTION      BOOST_OVERRIDABLE_SYMBOL

//------------------------------------------------------------------------------
