/* Author:			TrippyColors
 * Created:			10.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Utility_hpp_included
#define LunchTimeTracer_Utility_hpp_included

#include <limits>

#include <LunchTimeTracer/Fundamental.hpp>

namespace LTT_TrippyColors
{
	const RealT Epsilon = static_cast<RealT>(1.0e-6);

	bool EpsEq(RealT Lhs, RealT Rhs);

	RealT Round(RealT Value);

	template<typename T>
	T Clamp(T const& Value, T const& Min, T const& Max);

	template<typename T>
	T const& Constify(T const& Object);

	template<typename T, typename OutputIteratorType>
	void ToLittleEndian(T const& Value, OutputIteratorType Out);

	template<typename T, typename OutputIteratorType>
	void ToBigEndian(T const& Value, OutputIteratorType Out);
}

#include <LunchTimeTracer/Utility.inl>

#endif // LunchTimeTracer_Utility_hpp_included
