#include <iostream>

#include <LunchTimeTracer.hpp>

int main()
{
	using namespace LTT;

	std::cout << "90 Deg = " << Angle(90, Deg).Get() << " rad\n";

	Image Img(256, 256);
	for(SizeType X = 0; X < Img.Width(); ++X)
	{
		for(SizeType Y = 0; Y < Img.Height(); ++Y)
		{
			Img(X, Y) = static_cast<ImageColor>(HsvToColor(Angle(static_cast<RealT>(X) / (Img.Width() - 1) * 360, Deg), 1, static_cast<RealT>(Y) / (Img.Height() - 1)));
		}
	}

	SaveAsBmp(Img, "Test.bmp");
}
