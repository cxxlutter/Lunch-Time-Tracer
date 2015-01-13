/* Author:			TrippyColors
 * Created:			13.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Log_inl_included
#define LunchTimeTracer_Log_inl_included

#include <cstdlib>
#include <iostream>
#include <algorithm>

#include <LunchTimeTracer/Log.hpp>

namespace LTT_TrippyColors
{
	namespace Detail
	{
		class LogModeArray
		{
			LogModeArray()
			{
				std::fill(Data, Data + (sizeof(Data) / sizeof(*Data)), lmLog);
			}

			LogModeArray(LogModeArray const& Rhs);
			LogModeArray& operator= (LogModeArray const& Rhs);

		public:
			LogModeT Data[MessageTypeMax];

			static LogModeArray& Instance()
			{
				static LogModeArray Object;
				return Object;
			}
		};
	}
}

LTT_TrippyColors::Logger::Logger(LogModeT Mode)
	: Mode(Mode)
{
}

LTT_TrippyColors::LogModeT LTT_TrippyColors::Logger::GetMode() const
{
	return Mode;
}

template<typename T>
LTT_TrippyColors::Logger const& LTT_TrippyColors::operator<< (Logger const& Stream, T const& Object)
{
	switch(Stream.GetMode())
	{
	case lmLog:
		std::clog << Object;
		break;

	case lmBreak:
		std::abort();
		break;

	default: // -Wswitch
		;
	}
	return Stream;
}

LTT_TrippyColors::Logger LTT_TrippyColors::Log(MessageTypeT MessageType)
{
	return Logger(GetLogMode(MessageType));
}

LTT_TrippyColors::LogModeT LTT_TrippyColors::GetLogMode(MessageTypeT MessageType)
{
	return Detail::LogModeArray::Instance().Data[MessageType];
}

void LTT_TrippyColors::SetLogMode(MessageTypeT MessageType, LogModeT Mode)
{
	Detail::LogModeArray::Instance().Data[MessageType] = Mode;
}

#endif // LunchTimeTracer_Log_inl_included
