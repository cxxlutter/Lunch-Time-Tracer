/* Author:			TrippyColors
 * Created:			09.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_TypeTraits_hpp_included
#define LunchTimeTracer_TypeTraits_hpp_included

#include <LunchTimeTracer/Fundamental.hpp>

namespace LTT_TrippyColors
{
	template<typename T>
	struct Identity
	{
		typedef T Type;
	};

	template<typename T, T Val>
	struct IntegralConstant : public Identity<IntegralConstant<T, Val> >
	{
		typedef T ValueType;

		static const ValueType Value = Val;
	};

	template<int Val>
	struct IntToType : public IntegralConstant<int, Val>
	{
	};

	template<SizeType Val>
	struct SizeToType : public IntegralConstant<SizeType, Val>
	{
	};

	template<bool Val>
	struct BoolToType : public IntegralConstant<bool, Val>
	{
	};

	typedef BoolToType<true> TrueType;
	typedef BoolToType<false> FalseType;

	template<bool Condition, typename T, typename U>
	struct Conditional;
	template<typename T, typename U>
	struct Conditional<true, T, U> : public Identity<T>
	{
	};
	template<typename T, typename U>
	struct Conditional<false, T, U> : public Identity<U>
	{
	};

	template<bool Condition, typename T = void>
	struct EnableIf
	{
	};
	template<typename T>
	struct EnableIf<true, T> : public Identity<T>
	{
	};

	template<bool Condition>
	struct DefinedIf;
	template<>
	struct DefinedIf<true>
	{
	};

	template<typename T, typename U>
	struct IsSame : public BoolToType<false>
	{
	};
	template<typename T>
	struct IsSame<T, T> : public BoolToType<true>
	{
	};

	template<typename T>
	struct RemoveCV : public Identity<T>
	{
	};
	template<typename T>
	struct RemoveCV<const T> : public Identity<T>
	{
	};
	template<typename T>
	struct RemoveCV<volatile T> : public Identity<T>
	{
	};
	template<typename T>
	struct RemoveCV<const volatile T> : public Identity<T>
	{
	};

	template<typename T>
	struct IsFloatingPoint : public BoolToType<(IsSame<T, float>::Value || IsSame<T, double>::Value || IsSame<T, long double>::Value)>
	{
	};
}

#endif // LunchTimeTracer_TypeTraits_hpp_included
