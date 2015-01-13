/* Author:			TrippyColors
 * Created:			13.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_Log_hpp_included
#define LunchTimeTracer_Log_hpp_included

namespace LTT_TrippyColors
{
	enum LogModeT
	{
		lmLog,
		lmIgnore,
		lmBreak
	};

	enum MessageTypeT
	{
		mtDebug,
		mtInfo,
		mtWarning,
		mtError,
		mtCritical,

		MessageTypeMax
	};

	class Logger
	{
		LogModeT Mode;

	public:
		explicit Logger(LogModeT Mode);

		LogModeT GetMode() const;
	};

	template<typename T>
	Logger const& operator<< (Logger const& Stream, T const& Object);

	Logger Log(MessageTypeT MessageType);

	LogModeT GetLogMode(MessageTypeT MessageType);
	void SetLogMode(MessageTypeT MessageType, LogModeT Mode);
}

#include <LunchTimeTracer/Log.inl>

#endif // LunchTimeTracer_Log_hpp_included
