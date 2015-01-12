/* Author:			TrippyColors
 * Created:			10.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Utility_inl_included
#define LunchTimeTracer_Utility_inl_included

#include <cmath>
#include <stdexcept>

#include <LunchTimeTracer/Utility.hpp>
#include <LunchTimeTracer/Fundamental.hpp>

bool LTT_TrippyColors::EpsEq(RealT Lhs, RealT Rhs)
{
	return std::abs(Lhs - Rhs) < Epsilon;
}

LTT_TrippyColors::RealT LTT_TrippyColors::Round(RealT Value)
{
	return std::floor(Value + static_cast<RealT>(0.5));
}

template<typename T>
T LTT_TrippyColors::Clamp(T const& Value, T const& Min, T const& Max)
{
#ifdef LunchTimeTracer_Debug
	if(Max < Min)
	{
		throw std::invalid_argument("Clamp: Max < Min");
	}
#endif // LunchTimeTracer_Debug

	if(Value > Max)
	{
		return Max;
	}
	if(Value < Min)
	{
		return Min;
	}
	return Value;
}

template<typename T>
T const& LTT_TrippyColors::Constify(T const& Object)
{
	return Object;
}

template<typename T, typename OutputIteratorType>
void LTT_TrippyColors::ToLittleEndian(T const& Value, OutputIteratorType Out)
{
	const T Mask = static_cast<T>(std::numeric_limits<UInt8>::max());
	for(SizeType Offset = 0; Offset != (sizeof(T) / sizeof(UInt8)) * std::numeric_limits<UInt8>::digits; Offset += std::numeric_limits<UInt8>::digits)
	{
		*Out = static_cast<UInt8>((Value & (Mask << Offset)) >> Offset);
		++Out;
	}
}

template<typename T, typename OutputIteratorType>
void LTT_TrippyColors::ToBigEndian(T const& Value, OutputIteratorType Out)
{
	const T Mask = static_cast<T>(std::numeric_limits<UInt8>::max());
	for(SizeType Offset = (sizeof(T) / sizeof(UInt8)) * std::numeric_limits<UInt8>::digits; Offset != 0;)
	{
		Offset -= std::numeric_limits<UInt8>::digits;
		*Out = static_cast<UInt8>((Value & (Mask << Offset)) >> Offset);
		++Out;
	}
}

#endif // LunchTimeTracer_Utility_inl_included
