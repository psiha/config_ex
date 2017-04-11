////////////////////////////////////////////////////////////////////////////////
///
/// \file suffix.hpp
/// ----------------
///
/// Boost.Config wrappers/extensions
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

#ifndef BOOST_ASSUME_UNCHECKED
#   ifdef BOOST_UNREACHABLE_UNCHECKED
#		define BOOST_ASSUME_UNCHECKED( condition ) do { if ( !( condition ) ) BOOST_UNREACHABLE_UNCHECKED(); } while ( 0 )
#	else
#		define BOOST_ASSUME_UNCHECKED( condition )
#   endif
#endif

#ifndef BOOST_UNREACHABLE_UNCHECKED
#	define BOOST_UNREACHABLE_UNCHECKED() BOOST_ASSUME_UNCHECKED( false )
#endif // BOOST_UNREACHABLE_UNCHECKED


#define BOOST_UNREACHABLE(      ) BOOST_ASSERT_MSG( false    , "This code should not be reached!" ); BOOST_UNREACHABLE_UNCHECKED()
#define BOOST_ASSUME( condition ) BOOST_ASSERT_MSG( condition, "Assumption broken!"               ); BOOST_ASSUME_UNCHECKED( condition )

#define BOOST_DEFAULT_CASE_UNREACHABLE_UNCHECKED() default:                                                                  BOOST_UNREACHABLE_UNCHECKED(); break
#define BOOST_DEFAULT_CASE_UNREACHABLE()           default: BOOST_ASSERT_MSG( false, "Unexpected: default case executed!" ); BOOST_UNREACHABLE_UNCHECKED(); break

#ifndef BOOST_OVERRIDE
#   define BOOST_OVERRIDE
#   define BOOST_FINAL
#endif // BOOST_OVERRIDE

#ifndef BOOST_NOVTABLE
#   define BOOST_NOVTABLE
#endif // BOOST_NOVTABLE

#ifndef BOOST_OPTIMIZE_FOR_SPEED_BEGIN
#   define BOOST_OPTIMIZE_FOR_SPEED_BEGIN()
#   define BOOST_OPTIMIZE_FOR_SPEED_END()
#   define BOOST_OPTIMIZE_FOR_SIZE_BEGIN()
#   define BOOST_OPTIMIZE_FOR_SIZE_END()
#endif // BOOST_OPTIMIZE_FOR_SPEED_BEGIN

#ifndef BOOST_FAST_MATH_ON
#   define BOOST_FAST_MATH_ON()
#   define BOOST_FAST_MATH_OFF()
#   define BOOST_FAST_MATH_ON_BEGIN()
#   define BOOST_FAST_MATH_ON_END()
#   define BOOST_FAST_MATH_OFF_BEGIN()
#   define BOOST_FAST_MATH_OFF_END()
#endif // BOOST_FAST_MATH_ON

#ifndef BOOST_CC_CDECL
#   define BOOST_CC_CDECL
#endif // BOOST_CC_CDECL
#ifndef BOOST_CC_FASTCALL
#   define BOOST_CC_FASTCALL
#endif // BOOST_CC_FASTCALL
#ifndef BOOST_CC_STDCALL
#   define BOOST_CC_STDCALL
#endif // BOOST_CC_STDCALL
#ifndef BOOST_CC_STACK
#   define BOOST_CC_STACK
#endif // BOOST_CC_STACK
#ifndef BOOST_CC_REG_ABI
#   define BOOST_CC_REG_ABI BOOST_CC_FASTCALL
#endif // BOOST_CC_REG_ABI
#ifndef BOOST_CC_REG
#   define BOOST_CC_REG BOOST_CC_REG_ABI
#endif // BOOST_CC_REG


#ifdef BOOST_RESTRICTED
#   define BOOST_RESTRICTED_PTR  BOOST_RESTRICTED
#   define BOOST_RESTRICTED_REF  BOOST_RESTRICTED
#   define BOOST_RESTRICTED_THIS BOOST_RESTRICTED
#else
#   ifndef BOOST_RESTRICTED_PTR
#       define BOOST_RESTRICTED_PTR
#   endif // BOOST_RESTRICTED_PTR
#   ifndef BOOST_RESTRICTED_REF
#       define BOOST_RESTRICTED_REF
#   endif // BOOST_RESTRICTED_REF
#   ifndef BOOST_RESTRICTED_THIS
#       define BOOST_RESTRICTED_THIS
#   endif // BOOST_RESTRICTED_THIS
#endif // BOOST_RESTRICTED

#ifndef BOOST_ATTRIBUTES
#   define BOOST_ATTRIBUTES( attribs )
#endif // BOOST_ATTRIBUTES

#ifndef BOOST_MINSIZE
#   define BOOST_MINSIZE
#endif // BOOST_MINSIZE

#ifdef BOOST_MAY_ALIAS
#   define BOOST_HAS_MAY_ALIAS
#endif // BOOST_MAY_ALIAS


#ifdef BOOST_OVERRIDABLE_SYMBOL
#   define BOOST_HAS_OVERRIDABLE_SYMBOL
#else
#   define BOOST_OVERRIDABLE_SYMBOL
#endif // BOOST_OVERRIDABLE_SYMBOL

#ifndef BOOST_OVERRIDABLE_FUNCTION
#   ifdef BOOST_HAS_OVERRIDABLE_SYMBOL
#       define BOOST_OVERRIDABLE_FUNCTION BOOST_HAS_OVERRIDABLE_SYMBOL
#   else
#       define BOOST_OVERRIDABLE_FUNCTION
#   endif // BOOST_HAS_OVERRIDABLE_SYMBOL
#endif // BOOST_OVERRIDABLE_FUNCTION



#ifndef BOOST_NOTHROW_LITE
#   define BOOST_NOTHROW_LITE BOOST_NOEXCEPT_OR_NOTHROW
#endif // BOOST_NOTHROW_LITE
