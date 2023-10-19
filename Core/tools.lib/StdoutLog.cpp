#include "precomp.h"
#include "../fs.lib/fs.lib.h"
#include "StdoutLog.h"

namespace tools
{
	StdoutLog::StdoutLog()
		: m_enable(true)
	{
	}

	StdoutLog::RCP StdoutLog::Make()
	{
		RCP p = RCP(new StdoutLog);

		return p;
	}

	void StdoutLog::Info(const char * str)
	{
		if (!m_enable)
		{
			return;
		}

		if (m_timestampEntries)
		{
			std::string s = fs::format(fs::Local());
			fputs("[", stdout);
			fputs(s.c_str(), stdout);
			fputs("] ", stdout);
		}
		fputs("I: ", stdout);
		fputs(str, stdout);
		fputs("\n", stdout);
	}

	void StdoutLog::Warning(const char * str)
	{
		if (!m_enable)
		{
			return;
		}


		if (m_timestampEntries)
		{
			std::string s = fs::format(fs::Now());
			fputs("[", stdout);
			fputs(s.c_str(), stdout);
			fputs("] ", stdout);
		}
		fputs("W: ", stdout);
		fputs(str, stdout);
		fputs("\n", stdout);
	}

	void StdoutLog::Error(const char * str)
	{
		if (!m_enable)
		{
			return;
		}

		if (m_timestampEntries)
		{
			std::string s = fs::format(fs::Now());
			fputs("[", stdout);
			fputs(s.c_str(), stdout);
			fputs("] ", stdout);
		}
		fputs("E: ", stdout);
		fputs(str, stdout);
		fputs("\n", stdout);
	}

	bool& StdoutLog::Enable()
	{
		return m_enable;
	}
	const bool StdoutLog::Enable() const
	{
		return m_enable;
	}
}

/* StdoutLogger.cpp */
