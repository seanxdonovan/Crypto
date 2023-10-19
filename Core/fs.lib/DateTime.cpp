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
#include "Layout.h"
#include "Date.h"
#include "fsTime.h"
#include "DateTime.h"

#include "multiply.h"
/*
 *
 * We use a modified julian day scheme. Julian day 0 is midnight 1 Jan
 * 4713 UT BC. 2454477 is 11 Jan 2008. Daycount % 7 yields the day of
 * week 0 = Monday, ... ,6 = Sunday.
 *
 *
 *
 * 
 */

namespace fs
{

	DateTime::Span::Span(Date::Span p_span)
		: m_tickCount(p_span.DayCount() * TicksPerDay)
	{
	}

	DateTime::Span::Span(Time::Span p_span)
			: m_tickCount(p_span.TickCount())
	{
	}

#if 0
	void DateTime::Span::Crack(fs::dword *p_pDayCount, fs::dword *p_pTickCount)
	{
		fs::qword ticks = 0;
		if (m_tickCount < 0)
			ticks = -m_tickCount;
		else
			ticks = m_tickCount;
		Divide(ticks, TicksPerDay, p_pDayCount, p_pTickCount);
	}
#endif


	DateTime::Span& DateTime::Span::operator *=(fs::si64 p_scalar)
	{
		m_tickCount *= p_scalar;
		return *this;
	}

	DateTime::Span DateTime::Days(fs::si64 p_nDays)
	{
		si64 ticks = p_nDays * TicksPerDay;

		Span span(ticks);
		return span;
	}

	DateTime::Span DateTime::Hours(fs::si64 p_nHours)
	{
		si64 ticks = p_nHours;
		ticks *= TicksPerHour;

		Span span(ticks);
		return span;
	}

	DateTime::Span DateTime::Minutes(fs::si64 p_nMinutes)
	{
		si64 ticks = p_nMinutes;
		ticks *= TicksPerMinute;

		Span span(ticks);
		return span;
	}

	DateTime::Span DateTime::Seconds(fs::si64 p_nSeconds)
	{
		si64 ticks = p_nSeconds;
		ticks *= TicksPerSecond;

		Span span(ticks);
		return span;
	}

	DateTime::Span DateTime::NanoSeconds(::fs::qword p_ns)
	{
		// we lose data here

		qword ticks = p_ns;
		ticks /= 1000;
		ticks /= 1000;
		
		Span span(ticks);
		return span;
	}


	DateTime::Span operator *(const DateTime::Span& p_span, si64 p_multiplier)
	{
		DateTime::Span span = p_span;
		span *= p_multiplier;
		return span;
	}

	DateTime::Span operator *(si64 p_multiplier, const DateTime::Span& p_span)
	{
		DateTime::Span span = p_span;
		span *= p_multiplier;
		return span;
	}


	fs::si64 operator / (DateTime::Span p_l, DateTime::Span p_r)
	{
		return p_l.TickCount() / p_r.TickCount();
	}

	fs::si64 operator % (DateTime::Span p_l, DateTime::Span p_r)
	{
		return p_l.TickCount() % p_r.TickCount();
	}









	DateTime::DateTime(fs::si32 p_year, fs::dword p_month, fs::dword p_day, fs::dword p_hour, fs::dword p_minute, fs::dword p_seconds, fs::dword p_ms)
	{
		Set(p_year, p_month, p_day, p_hour, p_minute, p_seconds, p_ms);
	}


	void DateTime::Crack(fs::si32 *p_pYear, fs::dword *p_pMonth, fs::dword *p_pDay, fs::dword *p_pHours, fs::dword *p_pMinutes, fs::dword *p_pSeconds, fs::dword *p_pms) const
	{
		Date dt;
		Time tm;

		dt.m_dayCount = sCoerce(dword, m_ticks / TicksPerDay);
		tm.m_tickCount = sCoerce(dword, m_ticks % TicksPerDay);

		dt.Crack(p_pYear, p_pMonth, p_pDay);
		tm.Crack(p_pHours, p_pMinutes, p_pSeconds, p_pms);
	}

	void DateTime::Set(fs::si32 p_year, fs::dword p_month, fs::dword p_day, fs::dword p_hour, fs::dword p_minute, fs::dword p_second, fs::dword p_ms)
	{
		Date dt(p_year, p_month, p_day);
		Time tm(p_hour, p_minute, p_second, p_ms);

		m_ticks = ((qword)dt.m_dayCount) * TicksPerDay +  tm.m_tickCount;
	}

	DateTime& DateTime::operator +=(const Time::Span& p_span)
	{
		m_ticks += p_span.TickCount();

		return *this;
	}

	DateTime DateTime::LowerBound(Span p_interval) const
	{
		fs::qword ticks = TickCount();

		fs::qword newTicks = (ticks/p_interval.TickCount()) * p_interval.TickCount();

		DateTime dt(newTicks);
		return dt;
	}

	DateTime DateTime::UpperBound(Span p_interval) const
	{
		fs::qword ticks = TickCount();

		fs::qword newTicks = (ticks/p_interval.TickCount() + 1) * p_interval.TickCount();

		DateTime dt(newTicks);
		return dt;
	}


	bool DateTime::Between(fs::DateTime p_leftBound, fs::DateTime p_rightBound) const
	{
		return *this >= p_leftBound && *this <= p_rightBound;
	}

	DateTime& DateTime::operator +=(Span p_span)
	{
		m_ticks += p_span.TickCount();

		return *this;
	}

	DateTime& DateTime::operator -=(Span p_span)
	{
		m_ticks -= p_span.TickCount();
		return *this;
	}

	const DateTime DateTime::BeginningOfTime;




	void convert(const DateTime& p_datetime, SYSTEMTIME *p_pSystemTime)
	{
		Date dt;
		dt.m_dayCount = sCoerce(dword, p_datetime.TickCount() / DateTime::TicksPerDay);

		fs::si32 y;
		fs::dword m;
		fs::dword d;
		dt.Crack(&y, &m, &d);
		
		fs::dword dow;
		DofW(dt, &dow);

		Time tm;
		tm.m_tickCount = sCoerce(dword, p_datetime.TickCount() % DateTime::TicksPerDay);
		fs::dword hours;
		fs::dword minutes;
		fs::dword seconds;
		fs::dword ms;
		tm.Crack(&hours, &minutes, &seconds, &ms);

		p_pSystemTime->wYear = sCoerce(WORD, y);
		p_pSystemTime->wMonth = sCoerce(WORD, m);
		p_pSystemTime->wDayOfWeek = sCoerce(WORD, (dow + 1) % 7);
		p_pSystemTime->wDay = sCoerce(WORD, d);
		p_pSystemTime->wHour = sCoerce(WORD, hours);
		p_pSystemTime->wMinute = sCoerce(WORD, minutes);
		p_pSystemTime->wSecond = sCoerce(WORD, seconds);
		p_pSystemTime->wMilliseconds = sCoerce(WORD, ms);
	}

	void convert(const SYSTEMTIME& p_systemtime, DateTime *p_pDatetime)
	{
		DateTime dt(p_systemtime.wYear, p_systemtime.wMonth, p_systemtime.wDay, p_systemtime.wHour, p_systemtime.wMinute, p_systemtime.wSecond, p_systemtime.wMilliseconds);

		*p_pDatetime = dt;
	}


	DateTime Now()
	{
		SYSTEMTIME systemtime;

		GetSystemTime(&systemtime);

		DateTime datetime;

		convert(systemtime, &datetime);

		return datetime;
	}

	DateTime Local()
	{
		SYSTEMTIME systemtime;

		GetLocalTime(&systemtime);

		DateTime datetime;

		convert(systemtime, &datetime);

		return datetime;
	}

	Date Today(fs::dword p_hoursOffsetUTC, fs::dword p_minutesOffsetUTC)
	{
		DateTime now = Now();

		// make time zone adjustment;
		Time::Span span = Hours(p_hoursOffsetUTC) + Minutes(p_minutesOffsetUTC);

		now += span;

		return now.DatePart();
	}

	Date Yesterday(fs::dword p_hoursOffsetUTC, fs::dword p_minutesOffsetUTC)
	{
		Date dt = Today(p_hoursOffsetUTC, p_minutesOffsetUTC);
		dt -= Days(1);

		return dt;
	}

	Date Tomorrow(fs::dword p_hoursOffsetUTC, fs::dword p_minutesOffsetUTC)
	{
		Date dt = Today(p_hoursOffsetUTC, p_minutesOffsetUTC);
		dt += Days(1);

		return dt;
	}

	DateTime operator - (DateTime p_a, DateTime::Span p_b)
	{
		DateTime r = p_a;
		r -= p_b;

		return r;
	}

	DateTime operator + (DateTime p_a, DateTime::Span p_b)
	{
		DateTime r = p_a;
		r += p_b;

		return r;
	}

	si64 Minutes(const DateTime::Span& p_span)
	{
		return p_span.TickCount() / DateTime::TicksPerMinute;
	}


	fs::qword PeriodsPer(fs::DateTime::Span p_period, fs::DateTime::Span p_total)
	{
		si64 q = p_total.TickCount() / p_period.TickCount();
		si64 r = p_total.TickCount() % p_period.TickCount();

		fs::qword periods = fs::abs(q);
		if (0 != r)
		{
			++periods;
		}
		return periods;
	}

	std::string format(const DateTime& p_datetime)
	{
		fs::si32 y;
		fs::dword m;
		fs::dword d;
		fs::dword h;
		fs::dword mm;
		fs::dword s;
		fs::dword ms;
		p_datetime.Crack(&y, &m, &d, &h, &mm, &s, &ms);

		char buf[30];
		int exactcalc;
		_snprintf(buf, 30, "%04u/%02u/%02u %02u:%02u:%02u.%03u", y, m, d, h, mm, s, ms);
		
		return buf; //format(y, "/", m, "/", d, " ", h, ":", mm, ":", s, " ", ms);
	}


	std::string format(DateTime::Span p_span)
	{
		std::string s;

		fs::qword ticks = p_span.TickCount();

		if (p_span.TickCount() < 0)
		{
			s += "-";
			ticks = -p_span.TickCount();
		}


		qword r;
		fs::qword days  = ticks / DateTime::TicksPerDay;
		r = ticks % DateTime::TicksPerDay;
		
		fs::qword hours = r / DateTime::TicksPerHour;
		r = r % DateTime::TicksPerHour;
		fs::qword mins = r / DateTime::TicksPerMinute;
		r = r % DateTime::TicksPerMinute;
		fs::qword secs = r / DateTime::TicksPerSecond;
		r = r % DateTime::TicksPerSecond;

		if (days != 0)
		{
			s += "d" + format(days);
		}
		if (0 != hours)
		{
			s += "h" + format(hours);
		}
		if (0 != mins)
		{
			s += "m" + format(mins);
		}
		if (0 != secs)
		{
			s += "s" + format(secs);
		}
		if (0 != r)
		{
			s += "v" + format(r);
		}
		if (s.empty())
		{
			s = "0";
		}

		return s;
	}

	std::string format(DateTime::Epoch p_epoch)
	{
		return format(p_epoch.Count());
	}

	bool i_allDigits(const std::string& p_s)
	{
		for (size_t ix = 0; ix < p_s.length(); ++ix)
		{
			if (!isdigit(p_s[ix]))
			{
				return false;
			}
		}

		return true;
	}

	static const struct {
		const char * const name;
		fs::dword value;
	} months [] = {
		{"Jan" , 1},
		{"Feb" , 2},
		{"Mar" , 3},
		{"Apr" , 4},
		{"May" , 5},
		{"Jun" , 6},
		{"Jul" , 7},
		{"Aug" , 8},
		{"Sep" , 9},
		{"Oct" , 10},
		{"Nov" , 11},
		{"Dec" , 12}
	};

	bool i_isMonth(const std::string& p_s, fs::dword *p_pMonth)
	{
		for (size_t ix = 0; ix < sArraySize(months); ++ix)
		{
			if (0 == _stricmp(months[ix].name, p_s.c_str()))
			{
				*p_pMonth = months[ix].value;
				return true;
			}
		}

		return false;
	}

	bool Convert(const std::string& p_s, fs::DateTime *p_pDateTime)
	{
		if (p_s.empty())
		{
			return false;
		}

		if (i_allDigits(p_s))
		{
			si32 year;
			dword month;
			dword day;
			dword hours = 0;
			dword minutes = 0 ;
			dword seconds = 0;
			dword ms = 0;
			if (8 == p_s.size())
			{
				// date only
				if (!convert(p_s.substr(0,4).c_str(), &year))
				{
					return false;
				}
				if (!convert(p_s.substr(4,2).c_str(), &month))
				{
					return false;
				}
				if (!convert(p_s.substr(6,2).c_str(), &day))
				{
					return false;
				}
				*p_pDateTime = fs::DateTime(year, month, day);
				return true;
			}
			else if (10 == p_s.size())
			{
				// date + hours
				if (!convert(p_s.substr(0,4).c_str(), &year))
				{
					return false;
				}
				if (!convert(p_s.substr(4,2).c_str(), &month))
				{
					return false;
				}
				if (!convert(p_s.substr(6,2).c_str(), &day))
				{
					return false;
				}
				if (!convert(p_s.substr(8,2).c_str(), &hours))
				{
					return false;
				}
				*p_pDateTime = fs::DateTime(year, month, day, hours);
				return true;
			}
			if (12 == p_s.size())
			{
				// date + hours + minutes
				if (!convert(p_s.substr(0,4).c_str(), &year))
				{
					return false;
				}
				if (!convert(p_s.substr(4,2).c_str(), &month))
				{
					return false;
				}
				if (!convert(p_s.substr(6,2).c_str(), &day))
				{
					return false;
				}
				if (!convert(p_s.substr(8,2).c_str(), &hours))
				{
					return false;
				}
				if (!convert(p_s.substr(10,2).c_str(), &minutes))
				{
					return false;
				}
				*p_pDateTime = fs::DateTime(year, month, day, hours, minutes);
				return true;
			}
			if (14 == p_s.size())
			{
				// date + hours + minutes + seconds
				if (!convert(p_s.substr(0,4).c_str(), &year))
				{
					return false;
				}
				if (!convert(p_s.substr(4,2).c_str(), &month))
				{
					return false;
				}
				if (!convert(p_s.substr(6,2).c_str(), &day))
				{
					return false;
				}
				if (!convert(p_s.substr(8,2).c_str(), &hours))
				{
					return false;
				}
				if (!convert(p_s.substr(10,2).c_str(), &minutes))
				{
					return false;
				}
				if (!convert(p_s.substr(12,2).c_str(), &seconds))
				{
					return false;
				}
				*p_pDateTime = fs::DateTime(year, month, day, hours, minutes, seconds);
				return true;
			}
			if (17 == p_s.size())
			{
				// date + hours + minutes + seconds + ms
			}

		}
		else if (p_s.length() == 17)
		{
			//           1111111
			// 01234567890123456
			// 01-Mar-2010 13:33
			if ('-' == p_s[2] && '-' == p_s[6] && ' ' == p_s[11] && ':' == p_s[14])
			{
				fs::si32  year;
				fs::dword month;
				fs::dword day;
				fs::dword hours;
				fs::dword minutes;

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

				if (!fs::Convert(p_s.substr(12, 2), &hours))
				{
					return false;
				}
				if (!fs::Convert(p_s.substr(15, 2), &minutes))
				{
					return false;
				}
				
				*p_pDateTime = fs::DateTime(year, month, day, hours, minutes);
				return true;
			}
		}

		return false;
	}


	bool Convert(const std::string& p_s, fs::DateTime::Span *p_pInterval)
	{
		if (p_s.empty())
		{
			return false;
		}

		fs::byte chTimeIndicator = p_s[0];
		fs::dword nTimeInterval;
		if (!fs::convert(p_s.substr(1).c_str(), &nTimeInterval))
		{
			// ("Failed to convert '", p_s.substr(1).c_str(), "' to an integer.")
			return false;
		}

		if ('d' == chTimeIndicator)
		{
			*p_pInterval = DateTime::Days(nTimeInterval);
		}
		else if ('h' == chTimeIndicator)
		{
			*p_pInterval = DateTime::Hours(nTimeInterval);
		}
		else if ('m' == chTimeIndicator)
		{
			*p_pInterval = DateTime::Minutes(nTimeInterval);
		}
		else if ('s' == chTimeIndicator)
		{
			*p_pInterval = DateTime::Seconds(nTimeInterval);
		}
		else if ('v' == chTimeIndicator)
		{
			*p_pInterval = DateTime::MilliSeconds(nTimeInterval);
		}
		else
		{
			return false;
		}

		return true;
	}

	bool Convert(const std::string& p_s, fs::DateTime::Epoch *p_pEpoch)
	{
		DateTime::Epoch::Ordinal n;
		if (convert(p_s.c_str(), &n))
		{
			*p_pEpoch = DateTime::Epoch(n);

			return true;
		}

		return false;
	}
}

/* End Of File: DateTime.cpp */
