#include <iostream>
#include <fstream>

#include <LunchTimeTracer.hpp>

int main()
{
	using namespace LTT;

	// Angle conversion
	std::cout << "90 Deg = " << Angle(90, Deg).Get() << " rad\n";

	// Bitmap output and HSV to RGB conversion
	Image Img(256, 256);
	for(SizeType X = 0; X < Img.Width(); ++X)
	{
		for(SizeType Y = 0; Y < Img.Height(); ++Y)
		{
			Img(X, Y) = static_cast<ImageColor>(HsvToColor(Angle(static_cast<RealT>(X) / (Img.Width() - 1) * 360, Deg), 1, static_cast<RealT>(Y) / (Img.Height() - 1)));
		}
	}

	SaveAsBmp(Img, "Test.bmp");

	// Logging
	std::ofstream LogFile("LTT.log", std::ofstream::app);
	RdbufSaver RdbufGuard(std::clog, LogFile.rdbuf());

	Log(mtInfo) << "Some unimportant info\n";
	SetLogMode(mtInfo, lmIgnore);
	Log(mtInfo) << "Some unimportant info that is being ignored\n";
}
