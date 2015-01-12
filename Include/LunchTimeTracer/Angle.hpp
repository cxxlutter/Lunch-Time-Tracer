/* Author:			TrippyColors
 * Created:			09.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Angle_hpp_included
#define LunchTimeTracer_Angle_hpp_included

#include <LunchTimeTracer/Fundamental.hpp>

namespace LTT_TrippyColors
{
	struct RadType
	{
		template<typename T>
		static T To(T Value);

		template<typename T>
		static T From(T Value);
	};
	const RadType Rad;

	struct DegType
	{
		template<typename T>
		static T To(T Value);

		template<typename T>
		static T From(T Value);
	};
	const DegType Deg;

	template<typename T>
	class BasicAngle
	{
	public:
		typedef T ValueType;

		static const BasicAngle NullAngle;
		static const BasicAngle RightAngle;
		static const BasicAngle StraightAngle;
		static const BasicAngle FullAngle;

	private:
		ValueType Angle;

	public:
		BasicAngle();
		template<typename RhsT>
		BasicAngle(BasicAngle<RhsT> const& Rhs);
		template<typename UnitT>
		BasicAngle(ValueType NewAngle, UnitT Unit);

		ValueType Get() const;
		template<typename UnitT>
		ValueType Get(UnitT Unit) const;

		void Set(ValueType NewAngle);
		template<typename UnitT>
		void Set(ValueType NewAngle, UnitT Unit);
	};

	typedef BasicAngle<RealT> Angle;

	template<typename LhsT, typename RhsT>
	bool operator== (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs);
	template<typename LhsT, typename RhsT>
	bool operator!= (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs);

	template<typename LhsT, typename RhsT>
	bool operator< (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs);
	template<typename LhsT, typename RhsT>
	bool operator<= (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs);
	template<typename LhsT, typename RhsT>
	bool operator> (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs);
	template<typename LhsT, typename RhsT>
	bool operator>= (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs);

	template<typename T>
	BasicAngle<T> operator+ (BasicAngle<T> const& Object);
	template<typename T>
	BasicAngle<T> operator- (BasicAngle<T> const& Object);

	template<typename LhsT, typename RhsT>
	BasicAngle<LhsT>& operator+= (BasicAngle<LhsT>& Lhs, BasicAngle<RhsT> const& Rhs);
	template<typename LhsT, typename RhsT>
	BasicAngle<LhsT> operator+ (BasicAngle<LhsT> Lhs, BasicAngle<RhsT> const& Rhs);

	template<typename LhsT, typename RhsT>
	BasicAngle<LhsT>& operator-= (BasicAngle<LhsT>& Lhs, BasicAngle<RhsT> const& Rhs);
	template<typename LhsT, typename RhsT>
	BasicAngle<LhsT> operator- (BasicAngle<LhsT> Lhs, BasicAngle<RhsT> const& Rhs);

	template<typename T, typename ScalarType>
	BasicAngle<T>& operator*= (BasicAngle<T>& Lhs, ScalarType const& Rhs);
	template<typename T, typename ScalarType>
	BasicAngle<T> operator* (BasicAngle<T> Lhs, ScalarType const& Rhs);
	template<typename ScalarType, typename T>
	BasicAngle<T> operator* (ScalarType const& Lhs, BasicAngle<T> Rhs);

	template<typename T, typename ScalarType>
	BasicAngle<T>& operator/= (BasicAngle<T>& Lhs, ScalarType const& Rhs);
	template<typename T, typename ScalarType>
	BasicAngle<T> operator/ (BasicAngle<T> Lhs, ScalarType const& Rhs);
	template<typename ScalarType, typename T>
	BasicAngle<T> operator/ (ScalarType const& Lhs, BasicAngle<T> Rhs);

	template<typename LhsT, typename RhsT>
	RealT operator/ (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs);

	template<typename LhsT, typename RhsT>
	BasicAngle<LhsT>& operator%= (BasicAngle<LhsT>& Lhs, BasicAngle<RhsT> const& Rhs);
	template<typename LhsT, typename RhsT>
	BasicAngle<LhsT> operator% (BasicAngle<LhsT> Lhs, BasicAngle<RhsT> const& Rhs);
}

#include "Angle.inl"

#endif // LunchTimeTracer_Angle_hpp_included
