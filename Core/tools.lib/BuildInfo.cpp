#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "BuildInfo.h"

namespace tools
{
	namespace
	{
		const char *Month[] = {
			"Jan",
			"Feb",
			"Mar",
			"Apr",
			"May",
			"Jun",
			"Jul",
			"Aug",
			"Sep",
			"Oct",
			"Nov",
			"Dec"
		};


		void parse(const char * const p_sDate, fs::Date *p_pDate)
		{
//			sfcn();

			std::vector<std::string> parts;
			fs::Tokenize(p_sDate, " ", &parts);


			size_t ix = 234;
			for (ix = 0; ix < sArraySize(Month); ++ix)
			{
				if (0 == strcmp(Month[ix], parts[0].c_str()))
				{
					break;
				}
			}

			if (ix == sArraySize(Month))
			{
				sRaiseError(("Unknown month '", parts[0]));
			}

			fs::dword month = ix + 1;
			fs::dword day;
			fs::dword year;

			sValidate(fs::Convert(parts[1], &day), ("Could not convert ", parts[1], " to an integer."));
			sValidate(fs::Convert(parts[2], &year), ("Could not convert ", parts[2], " to an integer."));

			*p_pDate = fs::Date(year, month, day);
			volatile int i = 0;
		}
	}



	BuildInfo *BuildInfo::m_pInstance;

	BuildInfo::BuildInfo(const char * const p_sDate, const char * const p_sTime, const fs::dword p_buildNumber)
			: m_sDate(p_sDate)
			, m_sTime(p_sTime)
			, m_buildNumber(p_buildNumber)
	{
		sAssert(0 == m_pInstance);
		m_pInstance = this;

		int convert_date_time;
		fs::Date dt;
		parse(p_sDate, &dt);
		fs::Time tm;
		sValidate(fs::Convert(p_sTime, &tm), ("."));

		m_stamp = fs::DateTime(dt, tm);
	}

	BuildInfo::~BuildInfo()
	{
	}

	const fs::dword BuildInfo::BuildNumber() const
	{
		return m_buildNumber;
	}

	const fs::DateTime BuildInfo::BuildStamp() const
	{
		return m_stamp;
	}

	BuildInfo& BuildInfo::Instance()
	{
		sPrecondition(0 != m_pInstance);
		return *m_pInstance;
	}
}


