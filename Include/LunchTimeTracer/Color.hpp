/* Author:			TrippyColors
 * Created:			09.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Color_hpp_included
#define LunchTimeTracer_Color_hpp_included

#include <limits>

#include <LunchTimeTracer/Fundamental.hpp>
#include <LunchTimeTracer/TypeTraits.hpp>
#include <LunchTimeTracer/Angle.hpp>

namespace LTT_TrippyColors
{
	template<typename T>
	class BasicColor : public DefinedIf<(std::numeric_limits<T>::is_integer || IsFloatingPoint<T>::Value)>
	{
	public:
		typedef T ValueType;

	private:
		template<typename RhsT>
		static ValueType ConvertComponent(RhsT Rhs);

	public:
		static ValueType Min();
		static ValueType Max();

		ValueType Red;
		ValueType Green;
		ValueType Blue;
		ValueType Alpha;

		BasicColor();
		BasicColor(ValueType Red, ValueType Green, ValueType Blue);
		BasicColor(ValueType Red, ValueType Green, ValueType Blue, ValueType Alpha);

		template<typename RhsT>
		explicit BasicColor(BasicColor<RhsT> const& Rhs);
	};

	typedef BasicColor<RealT> Color;
	typedef BasicColor<UInt8> ImageColor;

	template<typename T>
	bool operator== (BasicColor<T> const& Lhs, BasicColor<T> const& Rhs);
	template<typename T>
	bool operator!= (BasicColor<T> const& Lhs, BasicColor<T> const& Rhs);

	template<typename T>
	BasicColor<T>& operator+= (BasicColor<T>& Lhs, BasicColor<T> const& Rhs);
	template<typename T>
	BasicColor<T> operator+ (BasicColor<T> Lhs, BasicColor<T> const& Rhs);

	template<typename T>
	BasicColor<T>& operator-= (BasicColor<T>& Lhs, BasicColor<T> const& Rhs);
	template<typename T>
	BasicColor<T> operator- (BasicColor<T> Lhs, BasicColor<T> const& Rhs);

	template<typename T>
	BasicColor<T>& operator*= (BasicColor<T>& Lhs, BasicColor<T> const& Rhs);
	template<typename T>
	BasicColor<T> operator* (BasicColor<T> Lhs, BasicColor<T> const& Rhs);

	template<typename T, typename ScalarType>
	BasicColor<T>& operator*= (BasicColor<T>& Lhs, ScalarType const& Rhs);
	template<typename T, typename ScalarType>
	BasicColor<T> operator* (BasicColor<T> Lhs, ScalarType const& Rhs);
	template<typename ScalarType, typename T>
	BasicColor<T> operator* (ScalarType const& Lhs, BasicColor<T> Rhs);

	template<typename T>
	BasicColor<T>& operator/= (BasicColor<T>& Lhs, BasicColor<T> const& Rhs);
	template<typename T>
	BasicColor<T> operator/ (BasicColor<T> Lhs, BasicColor<T> const& Rhs);

	template<typename T, typename ScalarType>
	BasicColor<T>& operator/= (BasicColor<T>& Lhs, ScalarType const& Rhs);
	template<typename T, typename ScalarType>
	BasicColor<T> operator/ (BasicColor<T> Lhs, ScalarType const& Rhs);
	template<typename ScalarType, typename T>
	BasicColor<T> operator/ (ScalarType const& Lhs, BasicColor<T> Rhs);

	template<typename T>
	BasicColor<T> Complement(BasicColor<T> const& Object);

	Color HsvToColor(Angle Hue, RealT Saturation, RealT Value, RealT Alpha);
	Color HsvToColor(Angle Hue, RealT Saturation, RealT Value);
}

#include <LunchTimeTracer/Color.inl>

#endif // LunchTimeTracer_Color_hpp_included
