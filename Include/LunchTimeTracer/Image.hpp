/* Author:			TrippyColors
 * Created:			09.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Image_hpp_included
#define LunchTimeTracer_Image_hpp_included

#include <ostream>
#include <vector>

#include <LunchTimeTracer/Fundamental.hpp>
#include <LunchTimeTracer/Color.hpp>

namespace LTT_TrippyColors
{
	template<typename T>
	class BasicImage
	{
	public:
		typedef T ValueType;

	private:
		std::vector<ValueType> Data;
		SizeType SizeX;
		SizeType SizeY;

	public:
		BasicImage();
		BasicImage(SizeType NewWidth, SizeType NewHeight);
		BasicImage(SizeType NewWidth, SizeType NewHeight, ValueType const& Value);

		SizeType Width() const;
		SizeType Height() const;
		SizeType Size() const;
		bool Empty() const;

		void Resize(SizeType NewWidth, SizeType NewHeight);
		void Resize(SizeType NewWidth, SizeType NewHeight, ValueType const& Value);

		void ResizeKeep(SizeType NewWidth, SizeType NewHeight);
		void ResizeKeep(SizeType NewWidth, SizeType NewHeight, ValueType const& Value);

		void Clear();

		ValueType const& operator() (SizeType X, SizeType Y) const;
		ValueType& operator() (SizeType X, SizeType Y);

		void Swap(BasicImage& Rhs);
	};

	typedef BasicImage<ImageColor> Image;

	template<typename T>
	BasicImage<T> ScaleUp(BasicImage<T> const& Object, SizeType Factor);
	template<typename T>
	BasicImage<T> ScaleDown(BasicImage<T> const& Object, SizeType Factor);

	void ToBmp(Image const& Object, std::ostream& Stream);
	bool SaveAsBmp(Image const& Object, CString Filename);
}

#include <LunchTimeTracer/Image.inl>

#endif // LunchTimeTracer_Image_hpp_included
