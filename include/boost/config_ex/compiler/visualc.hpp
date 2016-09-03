////////////////////////////////////////////////////////////////////////////////
///
/// \file visualc.hpp
/// -----------------
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

#ifndef BOOST_NO_STRICT_ALIASING
#   define BOOST_NO_STRICT_ALIASING
#endif // BOOST_NO_STRICT_ALIASING

#define BOOST_RESTRICTED_PTR __restrict
#if _MSC_VER >= 1900
#	define BOOST_RESTRICTED_REF __restrict
#endif

#define BOOST_CC_CDECL    __cdecl
#define BOOST_CC_FASTCALL __fastcall
#define BOOST_CC_STDCALL  __stdcall
#define BOOST_CC_STACK    BOOST_CC_STDCALL
#define BOOST_CC_REG_ABI  BOOST_CC_FASTCALL
#define BOOST_CC_REG      BOOST_CC_REG_ABI

#if ( _MSC_VER >= 1800 ) && ( defined( _M_X64 ) || ( _M_IX86_FP >= 2 ) )
#   undef  BOOST_CC_REG
#   define BOOST_CC_REG __vectorcall
#endif

#define BOOST_NOTHROW_LITE __declspec( nothrow )

#define BOOST_NOVTABLE __declspec( novtable )

#define BOOST_THREAD_LOCAL_POD __declspec( thread )

#define BOOST_OVERRIDABLE_SYMBOL extern __declspec( selectany )
#define BOOST_OVERRIDABLE_MEMBER_SYMBOL __declspec( selectany )
// http://blogs.msdn.com/b/freik/archive/2005/10/26/485276.aspx
#define BOOST_OVERRIDABLE_FUNCTION extern __declspec( noinline ) inline

#define BOOST_ASSUME_UNCHECKED( condition ) __assume( condition )

#define BOOST_ATTRIBUTES( ... ) __declspec( __VA_ARGS__ )
#define BOOST_RESTRICTED_FUNCTION_L1     noalias
#define BOOST_RESTRICTED_FUNCTION_L2     BOOST_RESTRICTED_FUNCTION_L1
#define BOOST_RESTRICTED_FUNCTION_L3     BOOST_RESTRICTED_FUNCTION_L2
#define BOOST_RESTRICTED_FUNCTION_RETURN restrict
#define BOOST_HOT
#define BOOST_COLD
#define BOOST_EXCEPTIONLESS              nothrow
#define BOOST_DOES_NOT_RETURN            noreturn
#define BOOST_WARN_UNUSED_RESULT         "SAL_mustInspect"

#define BOOST_OPTIMIZE_FOR_SPEED_BEGIN()     \
    __pragma( optimize        ( "t", on ) )  \
    __pragma( auto_inline     ( on      ) )  \
    __pragma( inline_recursion( on      ) )  \
    __pragma( inline_depth    ( 255     ) )  \


#define BOOST_OPTIMIZE_FOR_SPEED_END() \
    __pragma( optimize    ( "", on ) )

#define BOOST_OPTIMIZE_FOR_SIZE_BEGIN() \
    __pragma( optimize    ( "s", on ) )

#define BOOST_OPTIMIZE_FOR_SIZE_END BOOST_OPTIMIZE_FOR_SPEED_END


// msdn.microsoft.com/en-us/library/45ec64h6.aspx
#define BOOST_FAST_MATH_ON()                   \
    __pragma( float_control( except , off ) )  \
    __pragma( fenv_access  ( off          ) )  \
    __pragma( float_control( precise, off ) )  \
    __pragma( fp_contract  ( on           ) )

#define BOOST_FAST_MATH_OFF()                  \
    __pragma( float_control( precise, on  ) )  \
    __pragma( fenv_access  ( on           ) )  \
    __pragma( float_control( except , on  ) )  \
    __pragma( fp_contract  ( off          ) )

#define BOOST_FAST_MATH_ON_BEGIN()             \
    __pragma( float_control( push ) )          \
    BOOST_FAST_MATH_ON()

#define BOOST_FAST_MATH_ON_END()               \
    BOOST_FAST_MATH_OFF()                      \
    __pragma( float_control( pop ) )

#define BOOST_FAST_MATH_OFF_BEGIN()            \
    __pragma( float_control( push ) )          \
    BOOST_FAST_MATH_OFF()

#define BOOST_FAST_MATH_OFF_END()              \
    BOOST_FAST_MATH_ON()                       \
    __pragma( float_control( pop ) )

