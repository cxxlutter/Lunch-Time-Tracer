/* Author:			TrippyColors
 * Created:			10.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Color_inl_included
#define LunchTimeTracer_Color_inl_included

#include <limits>

#include <LunchTimeTracer/Color.hpp>
#include <LunchTimeTracer/Fundamental.hpp>
#include <LunchTimeTracer/TypeTraits.hpp>
#include <LunchTimeTracer/Angle.hpp>
#include <LunchTimeTracer/Utility.hpp>

template<typename T>
template<typename RhsT>
typename LTT_TrippyColors::BasicColor<T>::ValueType LTT_TrippyColors::BasicColor<T>::ConvertComponent(RhsT Rhs)
{
	if(std::numeric_limits<ValueType>::is_integer)
	{
		if(std::numeric_limits<RhsT>::is_integer)
		{
			const RealT FloatRep = static_cast<RealT>(Rhs) / static_cast<RealT>(BasicColor<RhsT>::Max());
			return static_cast<ValueType>(Round(FloatRep * Max()));
		}
		else
		{
			return static_cast<ValueType>(Round(Rhs * Max()));
		}
	}
	else
	{
		if(std::numeric_limits<RhsT>::is_integer)
		{
			return static_cast<ValueType>(Rhs) / static_cast<ValueType>(BasicColor<RhsT>::Max());
		}
		else
		{
			return static_cast<ValueType>(Rhs);
		}
	}
}

template<typename T>
typename LTT_TrippyColors::BasicColor<T>::ValueType LTT_TrippyColors::BasicColor<T>::Min()
{
	return static_cast<ValueType>(0);
}

template<typename T>
typename LTT_TrippyColors::BasicColor<T>::ValueType LTT_TrippyColors::BasicColor<T>::Max()
{
	if(std::numeric_limits<ValueType>::is_integer)
	{
		return std::numeric_limits<ValueType>::max();
	}
	else
	{
		return static_cast<ValueType>(1);
	}
}

template<typename T>
LTT_TrippyColors::BasicColor<T>::BasicColor()
	: Red(Min()), Green(Min()), Blue(Min()), Alpha(Max())
{
}

template<typename T>
LTT_TrippyColors::BasicColor<T>::BasicColor(ValueType Red, ValueType Green, ValueType Blue)
	: Red(Red), Green(Green), Blue(Blue), Alpha(Max())
{
}

template<typename T>
LTT_TrippyColors::BasicColor<T>::BasicColor(ValueType Red, ValueType Green, ValueType Blue, ValueType Alpha)
	: Red(Red), Green(Green), Blue(Blue), Alpha(Alpha)
{
}

template<typename T>
template<typename RhsT>
LTT_TrippyColors::BasicColor<T>::BasicColor(BasicColor<RhsT> const& Rhs)
	: Red(ConvertComponent(Rhs.Red)), Green(ConvertComponent(Rhs.Green)), Blue(ConvertComponent(Rhs.Blue)), Alpha(ConvertComponent(Rhs.Alpha))
{
}

template<typename T>
bool LTT_TrippyColors::operator== (BasicColor<T> const& Lhs, BasicColor<T> const& Rhs)
{
	return EpsEq(Lhs.Red, Rhs.Red) && EpsEq(Lhs.Green, Rhs.Green) && EpsEq(Lhs.Blue, Rhs.Blue) && EpsEq(Lhs.Alpha, Rhs.Alpha);
}

template<typename T>
bool LTT_TrippyColors::operator!= (BasicColor<T> const& Lhs, BasicColor<T> const& Rhs)
{
	return !(Lhs == Rhs);
}

template<typename T>
LTT_TrippyColors::BasicColor<T>& LTT_TrippyColors::operator+= (BasicColor<T>& Lhs, BasicColor<T> const& Rhs)
{
	Lhs.Red += Rhs.Red;
	Lhs.Green += Rhs.Green;
	Lhs.Blue += Rhs.Blue;
	Lhs.Alpha += Rhs.Alpha;
	return Lhs;
}

template<typename T>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::operator+ (BasicColor<T> Lhs, BasicColor<T> const& Rhs)
{
	return Lhs += Rhs;
}

template<typename T>
LTT_TrippyColors::BasicColor<T>& LTT_TrippyColors::operator-= (BasicColor<T>& Lhs, BasicColor<T> const& Rhs)
{
	Lhs.Red -= Rhs.Red;
	Lhs.Green -= Rhs.Green;
	Lhs.Blue -= Rhs.Blue;
	Lhs.Alpha -= Rhs.Alpha;
	return Lhs;
}

template<typename T>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::operator- (BasicColor<T> Lhs, BasicColor<T> const& Rhs)
{
	return Lhs -= Rhs;
}

template<typename T>
LTT_TrippyColors::BasicColor<T>& LTT_TrippyColors::operator*= (BasicColor<T>& Lhs, BasicColor<T> const& Rhs)
{
	Lhs.Red *= Rhs.Red;
	Lhs.Green *= Rhs.Green;
	Lhs.Blue *= Rhs.Blue;
	Lhs.Alpha *= Rhs.Alpha;
	return Lhs;
}

template<typename T>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::operator* (BasicColor<T> Lhs, BasicColor<T> const& Rhs)
{
	return Lhs *= Rhs;
}

template<typename T, typename ScalarType>
LTT_TrippyColors::BasicColor<T>& LTT_TrippyColors::operator*= (BasicColor<T>& Lhs, ScalarType const& Rhs)
{
	Lhs.Red *= Rhs;
	Lhs.Green *= Rhs;
	Lhs.Blue *= Rhs;
	Lhs.Alpha *= Rhs;
	return Lhs;
}

template<typename T, typename ScalarType>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::operator* (BasicColor<T> Lhs, ScalarType const& Rhs)
{
	return Lhs *= Rhs;
}

template<typename ScalarType, typename T>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::operator* (ScalarType const& Lhs, BasicColor<T> Rhs)
{
	return Rhs *= Lhs;
}

template<typename T>
LTT_TrippyColors::BasicColor<T>& LTT_TrippyColors::operator/= (BasicColor<T>& Lhs, BasicColor<T> const& Rhs)
{
	Lhs.Red /= Rhs.Red;
	Lhs.Green /= Rhs.Green;
	Lhs.Blue /= Rhs.Blue;
	Lhs.Alpha /= Rhs.Alpha;
	return Lhs;
}

template<typename T>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::operator/ (BasicColor<T> Lhs, BasicColor<T> const& Rhs)
{
	return Lhs /= Rhs;
}

template<typename T, typename ScalarType>
LTT_TrippyColors::BasicColor<T>& LTT_TrippyColors::operator/= (BasicColor<T>& Lhs, ScalarType const& Rhs)
{
	Lhs.Red /= Rhs;
	Lhs.Green /= Rhs;
	Lhs.Blue /= Rhs;
	Lhs.Alpha /= Rhs;
	return Lhs;
}

template<typename T, typename ScalarType>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::operator/ (BasicColor<T> Lhs, ScalarType const& Rhs)
{
	return Lhs /= Rhs;
}

template<typename ScalarType, typename T>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::operator/ (ScalarType const& Lhs, BasicColor<T> Rhs)
{
	return Rhs /= Lhs;
}

template<typename T>
LTT_TrippyColors::BasicColor<T> LTT_TrippyColors::Complement(BasicColor<T> const& Object)
{
	return BasicColor<T>(Object.Max() - Object.Red, Object.Max() - Object.Green, Object.Max() - Object.Blue, Object.Alpha);
}

LTT_TrippyColors::Color LTT_TrippyColors::HsvToColor(Angle Hue, RealT Saturation, RealT Value, RealT Alpha)
{
	Saturation = Clamp(Saturation, Color::Min(), Color::Max());
	Value = Clamp(Value, Color::Min(), Color::Max());

	Color Result;

	if(EpsEq(Saturation, Color::Min()))
	{
		Result.Red = Value;
		Result.Green = Value;
		Result.Blue = Value;
	}
	else
	{
		const RealT Sectors = static_cast<RealT>(6);
		RealT HueSector = (Hue / Angle::FullAngle) * Sectors;

		for(; HueSector < 0; HueSector += Sectors);
		for(; HueSector >= Sectors; HueSector -= Sectors);

		const int Sector = static_cast<int>(HueSector);
		const RealT A = Value * (Color::Max() - Saturation);
		const RealT B = Value * (Color::Max() - Saturation * (HueSector - static_cast<RealT>(Sector)));
		const RealT C = Value * (Color::Max() - Saturation * (Color::Max() - (HueSector - static_cast<RealT>(Sector))));

		switch(Sector)
		{
		case 0:
			Result.Red = Value;
			Result.Green = C;
			Result.Blue = A;
			break;

		case 1:
			Result.Red = B;
			Result.Green = Value;
			Result.Blue = A;
			break;

		case 2:
			Result.Red = A;
			Result.Green = Value;
			Result.Blue = C;
			break;

		case 3:
			Result.Red = A;
			Result.Green = B;
			Result.Blue = Value;
			break;

		case 4:
			Result.Red = C;
			Result.Green = A;
			Result.Blue = Value;
			break;

		case 5:
			Result.Red = Value;
			Result.Green = A;
			Result.Blue = B;
		}
	}

	Result.Alpha = Alpha;

	return Result;
}

LTT_TrippyColors::Color LTT_TrippyColors::HsvToColor(Angle Hue, RealT Saturation, RealT Value)
{
	return HsvToColor(Hue, Saturation, Value, Color::Max());
}

#endif // LunchTimeTracer_Color_inl_included
