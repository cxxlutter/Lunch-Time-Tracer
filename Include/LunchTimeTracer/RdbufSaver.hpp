/* Author:			lutter
 * Created:			14.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_RdbufSaver_hpp_included
#define LunchTimeTracer_RdbufSaver_hpp_included

#include <ios>
#include <string>

namespace LTT_TrippyColors
{
	// after basic_ios_rdbuf_saver from boost/io/ios_state.hpp
	template <typename Ch, class Tr>
	class BasicIosRdbufSaver
	{
	public:
		typedef std::basic_ios<Ch, Tr> StateType;
		typedef std::basic_streambuf<Ch, Tr>* AspectType;

	private:
		StateType& State;
		AspectType const Aspect;

	public:
		explicit BasicIosRdbufSaver(StateType& State);
		BasicIosRdbufSaver(StateType& State, AspectType const& Aspect);
		~BasicIosRdbufSaver();
		void Restore();
	};

	typedef BasicIosRdbufSaver<char, std::char_traits<char> > RdbufSaver;
}

#include "RdbufSaver.inl"

#endif // LunchTimeTracer_RdbufSaver_hpp_included

