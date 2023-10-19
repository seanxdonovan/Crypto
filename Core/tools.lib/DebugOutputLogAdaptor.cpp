#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"
#include "DebugOutputLogAdaptor.h"

namespace tools
{
	void LogToDebugger::Info(const char *p_s)
	{
		out("Info", p_s);
	}

	void LogToDebugger::Warning(const char *p_s)
	{
		out("Warning", p_s);
	}

	void LogToDebugger::Error(const char *p_s)
	{
		out("Error", p_s);
	}

	void LogToDebugger::out(const char *p_sPrefix, const char *p_sMessage)
	{
		OutputDebugString(p_sPrefix);
		OutputDebugString(": ");
		OutputDebugString(p_sMessage);
		OutputDebugString("\n");
	}

	LogToDebugger::LogToDebugger()
	{
	}

	LogToDebugger::RCP LogToDebugger::Make()
	{
		return RCP(new LogToDebugger);
	}
}
