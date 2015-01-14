/* Author:			TrippyColors
 * Created:			10.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Angle_inl_included
#define LunchTimeTracer_Angle_inl_included

#include <LunchTimeTracer/Angle.hpp>
#include <LunchTimeTracer/Fundamental.hpp>
#include <LunchTimeTracer/Utility.hpp>

template<typename T>
T LTT_TrippyColors::RadType::To(T Value)
{
	return Value;
}

template<typename T>
T LTT_TrippyColors::RadType::From(T Value)
{
	return Value;
}
#include <LunchTimeTracer/Fundamental.hpp>
template<typename T>
T LTT_TrippyColors::DegType::To(T Value)
{
	return Value / Pi * static_cast<T>(180);
}

template<typename T>
T LTT_TrippyColors::DegType::From(T Value)
{
	return Value / static_cast<T>(180) * Pi;
}

template<typename T>
const LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::BasicAngle<T>::NullAngle(0, Deg);

template<typename T>
const LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::BasicAngle<T>::RightAngle(90, Deg);

template<typename T>
const LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::BasicAngle<T>::StraightAngle(180, Deg);

template<typename T>
const LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::BasicAngle<T>::FullAngle(360, Deg);

template<typename T>
LTT_TrippyColors::BasicAngle<T>::BasicAngle()
	: Angle(ValueType())
{
}

template<typename T>
template<typename RhsT>
LTT_TrippyColors::BasicAngle<T>::BasicAngle(BasicAngle<RhsT> const& Rhs)
	: Angle(static_cast<ValueType>(Rhs.Get()))
{
}

template<typename T>
template<typename UnitT>
LTT_TrippyColors::BasicAngle<T>::BasicAngle(ValueType NewAngle, UnitT Unit)
{
	Set(NewAngle, Unit);
}

template<typename T>
typename LTT_TrippyColors::BasicAngle<T>::ValueType LTT_TrippyColors::BasicAngle<T>::Get() const
{
	return Angle;
}

template<typename T>
template<typename UnitT>
typename LTT_TrippyColors::BasicAngle<T>::ValueType LTT_TrippyColors::BasicAngle<T>::Get(UnitT) const
{
	return UnitT::To(Angle);
}

template<typename T>
void LTT_TrippyColors::BasicAngle<T>::Set(ValueType NewAngle)
{
	Angle = NewAngle;
}

template<typename T>
template<typename UnitT>
void LTT_TrippyColors::BasicAngle<T>::Set(ValueType NewAngle, UnitT)
{
	Angle = UnitT::From(NewAngle);
}

template<typename LhsT, typename RhsT>
bool LTT_TrippyColors::operator== (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs)
{
	return EpsEq(Lhs.Get(), Rhs.Get());
}

template<typename LhsT, typename RhsT>
bool LTT_TrippyColors::operator!= (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs)
{
	return !(Lhs == Rhs);
}

template<typename LhsT, typename RhsT>
bool LTT_TrippyColors::operator< (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs)
{
	return Lhs.Get() < Rhs.Get();
}

template<typename LhsT, typename RhsT>
bool LTT_TrippyColors::operator<= (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs)
{
	return Lhs.Get() <= Rhs.Get();
}

template<typename LhsT, typename RhsT>
bool LTT_TrippyColors::operator> (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs)
{
	return Lhs.Get() > Rhs.Get();
}

template<typename LhsT, typename RhsT>
bool LTT_TrippyColors::operator>= (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs)
{
	return Lhs.Get() >= Rhs.Get();
}

template<typename T>
LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::operator+ (BasicAngle<T> const& Object)
{
	return Object;
}

template<typename T>
LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::operator- (BasicAngle<T> const& Object)
{
	return BasicAngle<T>(-Object.Get());
}

template<typename LhsT, typename RhsT>
LTT_TrippyColors::BasicAngle<LhsT>& LTT_TrippyColors::operator+= (BasicAngle<LhsT>& Lhs, BasicAngle<RhsT> const& Rhs)
{
	Lhs.Set(Lhs.Get() + Rhs.Get());
	return Lhs;
}

template<typename LhsT, typename RhsT>
LTT_TrippyColors::BasicAngle<LhsT> LTT_TrippyColors::operator+ (BasicAngle<LhsT> Lhs, BasicAngle<RhsT> const& Rhs)
{
	return Lhs += Rhs;
}

template<typename LhsT, typename RhsT>
LTT_TrippyColors::BasicAngle<LhsT>& LTT_TrippyColors::operator-= (BasicAngle<LhsT>& Lhs, BasicAngle<RhsT> const& Rhs)
{
	Lhs.Set(Lhs.Get() - Rhs.Get());
	return Lhs;
}

template<typename LhsT, typename RhsT>
LTT_TrippyColors::BasicAngle<LhsT> LTT_TrippyColors::operator- (BasicAngle<LhsT> Lhs, BasicAngle<RhsT> const& Rhs)
{
	return Lhs -= Rhs;
}

template<typename T, typename ScalarType>
LTT_TrippyColors::BasicAngle<T>& LTT_TrippyColors::operator*= (BasicAngle<T>& Lhs, ScalarType const& Rhs)
{
	Lhs.Set(Lhs.Get() * Rhs);
	return Lhs;
}

template<typename T, typename ScalarType>
LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::operator* (BasicAngle<T> Lhs, ScalarType const& Rhs)
{
	return Lhs *= Rhs;
}

template<typename ScalarType, typename T>
LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::operator* (ScalarType const& Lhs, BasicAngle<T> Rhs)
{
	return Rhs *= Lhs;
}

template<typename T, typename ScalarType>
LTT_TrippyColors::BasicAngle<T>& LTT_TrippyColors::operator/= (BasicAngle<T>& Lhs, ScalarType const& Rhs)
{
	Lhs.Set(Lhs.Get() / Rhs);
	return Lhs;
}

template<typename T, typename ScalarType>
LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::operator/ (BasicAngle<T> Lhs, ScalarType const& Rhs)
{
	return Lhs *= Rhs;
}

template<typename ScalarType, typename T>
LTT_TrippyColors::BasicAngle<T> LTT_TrippyColors::operator/ (ScalarType const& Lhs, BasicAngle<T> Rhs)
{
	return Rhs *= Lhs;
}

template<typename LhsT, typename RhsT>
LTT_TrippyColors::RealT LTT_TrippyColors::operator/ (BasicAngle<LhsT> const& Lhs, BasicAngle<RhsT> const& Rhs)
{
	return static_cast<RealT>(Lhs.Get()) / static_cast<RealT>(Rhs.Get());
}

template<typename LhsT, typename RhsT>
LTT_TrippyColors::BasicAngle<LhsT>& LTT_TrippyColors::operator%= (BasicAngle<LhsT>& Lhs, BasicAngle<RhsT> const& Rhs)
{
	if(Rhs < BasicAngle<RhsT>::NullAngle)
	{
		while(Lhs >= BasicAngle<LhsT>::NullAngle)
		{
			Lhs -= Rhs;
		}
		while(Lhs < Rhs)
		{
			Lhs += Rhs;
		}
	}
	else
	{
		while(Lhs >= Rhs)
		{
			Lhs -= Rhs;
		}
		while(Lhs < BasicAngle<LhsT>::NullAngle)
		{
			Lhs += Rhs;
		}
	}
	return Lhs;
}

template<typename LhsT, typename RhsT>
LTT_TrippyColors::BasicAngle<LhsT> LTT_TrippyColors::operator% (BasicAngle<LhsT> Lhs, BasicAngle<RhsT> const& Rhs)
{
	return Lhs %= Rhs;
}

#endif // LunchTimeTracer_Angle_inl_included
