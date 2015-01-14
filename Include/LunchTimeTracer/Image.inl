/* Author:			TrippyColors
 * Created:			10.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Image_inl_included
#define LunchTimeTracer_Image_inl_included

#include <algorithm>
#include <ostream>
#include <fstream>
#include <iterator>

#include <LunchTimeTracer/Image.hpp>
#include <LunchTimeTracer/Fundamental.hpp>
#include <LunchTimeTracer/Utility.hpp>
#include <LunchTimeTracer/Color.hpp>

template<typename T>
LTT_TrippyColors::BasicImage<T>::BasicImage()
	: SizeX(0), SizeY(0)
{
}

template<typename T>
LTT_TrippyColors::BasicImage<T>::BasicImage(SizeType Width, SizeType Height)
	: Data(Width * Height), SizeX(Width), SizeY(Height)
{
}

template<typename T>
LTT_TrippyColors::BasicImage<T>::BasicImage(SizeType NewWidth, SizeType NewHeight, ValueType const& Value)
	: Data(NewWidth * NewHeight, Value), SizeX(NewWidth), SizeY(NewHeight)
{
}

template<typename T>
LTT_TrippyColors::SizeType LTT_TrippyColors::BasicImage<T>::Width() const
{
	return SizeX;
}

template<typename T>
LTT_TrippyColors::SizeType LTT_TrippyColors::BasicImage<T>::Height() const
{
	return SizeY;
}

template<typename T>
LTT_TrippyColors::SizeType LTT_TrippyColors::BasicImage<T>::Size() const
{
	return Data->size();
}

template<typename T>
bool LTT_TrippyColors::BasicImage<T>::Empty() const
{
	return Size() == 0;
}

template<typename T>
void LTT_TrippyColors::BasicImage<T>::Resize(SizeType NewWidth, SizeType NewHeight)
{
	Data.resize(NewWidth * NewHeight);
	SizeX = NewWidth;
	SizeY = NewHeight;
}

template<typename T>
void LTT_TrippyColors::BasicImage<T>::Resize(SizeType NewWidth, SizeType NewHeight, ValueType const& Value)
{
	Data.resize(NewWidth * NewHeight, Value);
	SizeX = NewWidth;
	SizeY = NewHeight;
}

template<typename T>
void LTT_TrippyColors::BasicImage<T>::ResizeKeep(SizeType NewWidth, SizeType NewHeight)
{
	BasicImage New(NewWidth, NewHeight);

	for(SizeType X = 0; X < std::min(Width(), New.Width()); ++X)
	{
		for(SizeType Y = 0; Y < std::min(Height(), New.Height()); ++Y)
		{
			New(X, Y) = (*this)(X, Y);
		}
	}

	Swap(New);
}

template<typename T>
void LTT_TrippyColors::BasicImage<T>::ResizeKeep(SizeType NewWidth, SizeType NewHeight, ValueType const& Value)
{
	BasicImage New(NewWidth, NewHeight);

	const SizeType MinX = std::min(Width(), New.Width());
	const SizeType MinY = std::min(Height(), New.Height());
	for(SizeType X = 0; X < MinX; ++X)
	{
		for(SizeType Y = 0; Y < MinY; ++Y)
		{
			New(X, Y) = (*this)(X, Y);
		}
	}
	for(SizeType X = MinX; X < New.Width(); ++X)
	{
		for(SizeType Y = 0; Y < New.Height(); ++Y)
		{
			New(X, Y) = Value;
		}
	}
	for(SizeType Y = MinY; Y < New.Height(); ++Y)
	{
		for(SizeType X = 0; X < MinX; ++X)
		{
			New(X, Y) = Value;
		}
	}

	Swap(New);
}

template<typename T>
void LTT_TrippyColors::BasicImage<T>::Clear()
{
	Data.clear();
	SizeX = 0;
	SizeY = 0;
}

template<typename T>
typename LTT_TrippyColors::BasicImage<T>::ValueType const& LTT_TrippyColors::BasicImage<T>::operator() (SizeType X, SizeType Y) const
{
	return Data[Y * Width() + X];
}

template<typename T>
typename LTT_TrippyColors::BasicImage<T>::ValueType& LTT_TrippyColors::BasicImage<T>::operator() (SizeType X, SizeType Y)
{
	return const_cast<ValueType&>(Constify(*this)(X, Y));
}

template<typename T>
void LTT_TrippyColors::BasicImage<T>::Swap(BasicImage& Rhs)
{
	using std::swap;
	swap(Data, Rhs.Data);
	swap(SizeX, Rhs.SizeX);
	swap(SizeY, Rhs.SizeY);
}

template<typename T>
void LTT_TrippyColors::swap(BasicImage<T>& Lhs, BasicImage<T>& Rhs)
{
	Lhs.Swap(Rhs);
}

template<typename T>
LTT_TrippyColors::BasicImage<T> LTT_TrippyColors::ScaleUp(BasicImage<T> const& Object, SizeType Factor)
{
	BasicImage<T> Result(Object.Width() * Factor, Object.Height() * Factor);

	for(SizeType X = 0; X < Object.Width(); ++X)
	{
		for(SizeType Y = 0; Y < Object.Height(); ++Y)
		{
			for(SizeType SubX = 0; SubX < Factor; ++SubX)
			{
				for(SizeType SubY = 0; SubY < Factor; ++SubY)
				{
					Result(X * Factor + SubX, Y * Factor + SubY) = Object(X, Y);
				}
			}
		}
	}

	return Result;
}

template<typename T>
LTT_TrippyColors::BasicImage<T> LTT_TrippyColors::ScaleDown(BasicImage<T> const& Object, SizeType Factor)
{
	BasicImage<T> Result(Object.Width() / Factor, Object.Height() / Factor);

	for(SizeType X = 0; X < Result.Width(); ++X)
	{
		for(SizeType Y = 0; Y < Result.Height(); ++Y)
		{
			Color Mixed;
			for(SizeType SubX = 0; SubX < Factor; ++SubX)
			{
				for(SizeType SubY = 0; SubY < Factor; ++SubY)
				{
					Mixed += Object(X * Factor + SubX, Y * Factor + SubY);
				}
			}
			Mixed /= Factor * Factor;
			Result(X, Y) = static_cast<typename BasicColor<T>::ValueType>(Mixed);
		}
	}

	return Result;
}

void LTT_TrippyColors::ToBmp(Image const& Object, std::ostream& Stream)
{
	if(Object.Width() == 0 || Object.Height() == 0)
	{
		return;
	}

	const SizeType UnalignedWidth = Object.Width() * 24;
	const SizeType AlignedWidth = (UnalignedWidth + 31) & ~static_cast<SizeType>(31);
	const SizeType PaddingBytes = (AlignedWidth - UnalignedWidth) / ByteBits;

	const SizeType InfoHeaderSize = 40;
	const SizeType NonImageDataSize = 14 + InfoHeaderSize;

	std::ostream_iterator<std::ostream::char_type> Out(Stream);

	// BITMAPFILEHEADER::bfType
	// Magic number
	*Out++ = 0x42;
	*Out++ = 0x4D;

	// BITMAPFILEHEADER::bfSize
	// File size
	ToLittleEndian(static_cast<UInt32>(NonImageDataSize + (AlignedWidth / ByteBits) * Object.Height()), Out);

	// BITMAPFILEHEADER::bfReserved
	// Reserved
	ToLittleEndian(static_cast<UInt32>(0), Out);

	// BITMAPFILEHEADER::bfOffBits
	// Offset
	ToLittleEndian(static_cast<UInt32>(NonImageDataSize), Out);

	// BITMAPINFOHEADER::biSize
	// Info header size
	ToLittleEndian(static_cast<UInt32>(InfoHeaderSize), Out);

	// BITMAPINFOHEADER::biWidth
	// Image width
	ToLittleEndian(static_cast<UInt32>(Object.Width()), Out);

	// BITMAPINFOHEADER::biHeight
	// Image height
	ToLittleEndian(static_cast<UInt32>(Object.Height()), Out);

	// BITMAPINFOHEADER::biPlanes
	// Planes
	ToLittleEndian(static_cast<UInt16>(1), Out);

	// BITMAPINFOHEADER::biBitCount
	// Bit count
	ToLittleEndian(static_cast<UInt16>(24), Out);

	// BITMAPINFOHEADER::biCompression
	// Compression
	ToLittleEndian(static_cast<UInt32>(0), Out);

	// BITMAPINFOHEADER::biSizeImage
	// Image size
	ToLittleEndian(static_cast<UInt32>(0), Out);

	// BITMAPINFOHEADER::biXPelsPerMeter
	// Horizontal pixels per meter
	ToLittleEndian(static_cast<UInt32>(0), Out);

	// BITMAPINFOHEADER::biYPelsPerMeter
	// Vertical pixels per meter
	ToLittleEndian(static_cast<UInt32>(0), Out);

	// BITMAPINFOHEADER::biClrUsed
	// Color palette size
	ToLittleEndian(static_cast<UInt32>(0), Out);

	// BITMAPINFOHEADER::biClrImportant
	// Used colors
	ToLittleEndian(static_cast<UInt32>(0), Out);

	// Color masks
	// Not used

	// Color palette
	// Not used

	// Image data
	for(SizeType Y = 0; Y < Object.Height(); ++Y)
	{
		for(SizeType X = 0; X < Object.Width(); ++X)
		{
			*Out++ = Object(X, Object.Height() - Y - 1).Blue;
			*Out++ = Object(X, Object.Height() - Y - 1).Green;
			*Out++ = Object(X, Object.Height() - Y - 1).Red;
		}
		for(SizeType i = 0; i < PaddingBytes; ++i)
		{
			*Out++ = static_cast<UInt8>(0);
		}
	}
}

bool LTT_TrippyColors::SaveAsBmp(Image const& Object, CString Filename)
{
	std::ofstream Output(Filename, std::ofstream::binary | std::ofstream::trunc);
	if(!Output)
	{
		return false;
	}
	ToBmp(Object, Output);
	return true;
}

#endif // LunchTimeTracer_Image_inl_included
