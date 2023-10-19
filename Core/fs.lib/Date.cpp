#include "precomp.h"
#include "declarations.h"
#include "type.h"
#include "type.id.h"
#include "type.List.h"
#include "type.Traits.h"
#include "type.Conversion.h"
#include "format.h"
#include "Buffer.h"
#include "io.h"

#include "Date.h"

namespace fs
{
	Date::Date()
	    : m_dayCount(0)
	{
	}

	Date::Date(fs::si32 p_year, fs::dword p_month, fs::dword p_day)
	{
		fs::dword a = (14 - p_month) / 12;
		fs::si32 y = (p_year + 4800 - a);
		fs::dword m = p_month + (12 * a) - 3;

		m_dayCount = p_day
			+ (153 * m + 2) / 5
			+ 365 * y
			+ y/ 4
			- y / 100
			+ y / 400
			- 32045;
		volatile int i = 0;
	}



	void Date::Crack(fs::si32 *p_pYear, fs::dword *p_pMonth, fs::dword *p_pDay) const
	{
		fs::dword J = m_dayCount; // Julian day number
		fs::dword j = J + 32044;
		fs::dword g = j /146097;
		fs::dword dg = j % 146097;
		fs::dword c = (dg / 36524 + 1) * 3 / 4;
		fs::dword dc = dg - c * 36524;
		fs::dword b = dc / 1461;
		fs::dword db = dc % 1461;
		fs::dword a = (db / 365 + 1) * 3 / 4;
		fs::dword da = db - a * 365;
		fs::dword y = g * 400 + c * 100 + b * 4 + a;
		fs::dword m = (da * 5 + 308) / 153 - 2;
		fs::dword d = da - (m + 4) * 153 / 5 + 122;
		fs::dword Y = y - 4800 + (m + 2) / 12;
		fs::dword M = (m + 2) % 12 + 1;
		fs::dword D = d + 1;

		*p_pYear = Y;
		*p_pMonth = M;
		*p_pDay = D;
	}

	//
	// Julian Day Number mod 7
	// 0 - Monday
	// 1 - Tuesday
	// ...
	// 5 - Sat
	// 6 - Sun

	void Date::DayOfWeek(fs::dword *p_dayOfWeek)
	{
		*p_dayOfWeek = m_dayCount % 7;
	}

	fs::dword Date::DayOfWeek() const
	{
		return m_dayCount % 7;
	}

	void DofW(const Date& p_date, fs::dword *p_dayOfWeek)
	{
		*p_dayOfWeek = p_date.m_dayCount % 7;
	}


	Date Make(fs::si32 p_year, fs::dword p_month, fs::dword p_day)
	{
		Date dt;
		dt.m_dayCount = p_day
				+ (153 * p_month) / 5
				+ 365 * p_year
				+ p_year / 4
				- p_year / 100
				+ p_year / 400
				- 32045;
		return dt;
	}


	Date& Date::operator -= (Span p_span)
	{
		m_dayCount -= p_span.DayCount();

		return *this;
	}

	Date& Date::operator += (Span p_span)
	{
		m_dayCount += p_span.DayCount();
		return *this;
	}

	std::string format(const Date& p_date)
	{
		fs::si32 y;
		fs::dword m;
		fs::dword d;
		p_date.Crack(&y, &m, &d);
		return format(y, "/", m, "/", d);
	}

	bool convert(const char *p_ps, Date *p_pDate)
	{
		char sYear[5];
		char sMonth[3];
		char sDay[3];

		const char *p = p_ps;

		size_t ix = 0;
		while (*p && *p != '/')
		{
			if (4 == ix || !isdigit(*p))
			{
				return false;
			}
			sYear[ix] = *p;
			++ix;
			++p;
		}
		sYear[ix] = 0;

		if ('/' != *p)
		{
			return false;
		}
		++p;
		ix = 0;

		while (*p && *p != '/')
		{
			if (2 == ix || !isdigit(*p))
			{
				return false;
			}
			sMonth[ix] = *p;
			++ix;
			++p;
		}
		sMonth[ix] = 0;

		if ('/' != *p)
		{
			return false;
		}

		++p;
		ix = 0;

		while (*p)
		{
			if (2 == ix || !isdigit(*p))
			{
				return false;
			}
			sDay[ix] = *p;
			++ix;
			++p;
		}
		sDay[ix] = 0;

		fs::si32 year;
		fs::dword month;
		fs::dword day;

		if (convert(sYear, &year) && convert(sMonth, &month) && convert(sDay, &day))
		{
			*p_pDate = Date(year, month, day);
			return true;
		}

		return false;
	}

	bool i_allDigits(const std::string& p_s);
	bool i_isMonth(const std::string& p_s, fs::dword *p_pMonth);

	bool Convert(const std::string& p_s, Date *p_pDate)
	{
		if (p_s.length() == 8 && i_allDigits(p_s))
		{
			fs::si32 year;
			fs::dword month;
			fs::dword day;

			if (!convert(p_s.substr(0, 4).c_str(), &year))
			{
				return false;
			}
			if (!convert(p_s.substr(4, 2).c_str(), &month))
			{
				return false;
			}
			if (!convert(p_s.substr(6, 2).c_str(), &day))
			{
				return false;
			}

			*p_pDate = fs::Date(year, month, day);
			return true;
		}

		
		if (11 == p_s.length() && '-' == p_s[2] && '-' == p_s[6])
		{
			fs::si32  year;
			fs::dword month;
			fs::dword day;

			if (!fs::convert(p_s.substr(7, 4).c_str(), &year))
			{
				return false;
			}
			if (!i_isMonth(p_s.substr(3, 3), &month))
			{
				return false;
			}
			if (!fs::Convert(p_s.substr(0,2), &day))
			{
				return false;
			}

			*p_pDate = fs::Date(year, month, day);
			return true;
		}

		return convert(p_s.c_str(), p_pDate);
	}
}


/* End Of File: Date.cpp */
