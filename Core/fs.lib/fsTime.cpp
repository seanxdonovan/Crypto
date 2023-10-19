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
#include "fsTime.h"
#include "multiply.h"

namespace fs
{
	const ::fs::dword ticksPerDay         = 1000 * 60 * 60 * 24;
	const ::fs::dword ticksPerHour        = 1000 * 60 * 60;
	const ::fs::dword ticksPerMinute      = 1000 * 60;
	const ::fs::dword ticksPerSecond      = 1000;
	const ::fs::dword ticksPerMilliSecond = 1;

	Time::Time(dword p_hours, dword p_minutes, dword p_seconds, dword p_ms)
	{
		m_tickCount = p_hours * ticksPerHour
			      + p_minutes * ticksPerMinute
			      + p_seconds * ticksPerSecond
			      + p_ms;

		sAssert(m_tickCount < ticksPerDay);
	}

	void Time::Crack(fs::dword *p_pHours, fs::dword *p_pMinutes, fs::dword *p_pSeconds, fs::dword *p_pms) const
	{
		*p_pHours = m_tickCount / ticksPerHour;

		dword tmp = m_tickCount % ticksPerHour;
		*p_pMinutes = tmp / ticksPerMinute;
		tmp = m_tickCount % ticksPerMinute;
		*p_pSeconds = tmp / ticksPerSecond;
		*p_pms = m_tickCount % ticksPerSecond;
	}



	::fs::Time::Span Time::Span::abs() const
	{
		if (m_ticks < 0 )
		{
			return Span(-m_ticks);
		}

		return *this;
	}

	//
	// take this time and return the time which is the lower bound
	// to the whole interval in which it is contained
	// e.g. Time t(12, 45, 14);
	//      Time lb = t.LowerBound(Minutes(10))
	// lb == '12:40:00'.
	//
	Time Time::LowerBound(Span p_interval) const
	{
		Time result;
		result.m_tickCount = (m_tickCount / p_interval.m_ticks) * p_interval.m_ticks;
		return result;
	}

	//
	// e.g.
	// Time ub = t.UpperBound(Minutes(15))
	// ub == '13:00:00'
	//
	Time Time::UpperBound(Span p_interval) const
	{
		Time result;
		result.m_tickCount = ((m_tickCount / p_interval.m_ticks) + 1) * p_interval.m_ticks;
		return result;
	}

	const Time::Span Time::DaySpan = ticksPerDay;



	Time::Span operator - (fs::Time p_lhs, fs::Time p_rhs)
	{
		return p_lhs.m_tickCount - p_rhs.m_tickCount;
	}

	Time::Span operator + (const Time::Span& p_a, const Time::Span& p_b)
	{
		Time::Span s = p_a;
		s.m_ticks += p_b.m_ticks;

		int makegoboomifoverflow;
		return s;
	}

	fs::dword operator / (const Time::Span& p_a, const Time::Span& p_b)
	{
		return p_a.m_ticks / p_b.m_ticks;
	}

	Time::Span Hours(::fs::si32 p_nHours)
	{
		int checkbounds;
		Time::Span s;
		s.m_ticks = p_nHours * ticksPerHour;

		return s;
	}

	Time::Span Minutes(::fs::si32 p_nMinutes)
	{
		int checkbounds;
		Time::Span s;
		s.m_ticks = p_nMinutes * ticksPerMinute;

		return s;
	}
			
	Time::Span Seconds(::fs::si32 p_nSeconds)
	{
		int checkbounds;
		Time::Span s;
		s.m_ticks = p_nSeconds * ticksPerSecond;

		return s;
	}

	Time::Span MilliSeconds(::fs::si32 p_nms)
	{
		int checkbounds;
		Time::Span s;
		s.m_ticks = p_nms * ticksPerMilliSecond;

		return s;
	}


	fs::dword PeriodsPer(fs::Time::Span p_period, fs::Time::Span p_total)
	{
		fs::dword q = p_total.TickCount() / p_period.TickCount();
		fs::dword r = p_total.TickCount() % p_period.TickCount();

		if (0 != r)
		{
			++q;
		}
		return q;
	}

	std::string format(const fs::Time& p_time)
	{
		char buf[13];


		fs::dword hours;
		fs::dword minutes;
		fs::dword seconds;
		fs::dword ms;

		p_time.Crack(&hours, &minutes, &seconds, &ms);
		if (0 != ms)
		{
			_snprintf(buf, 13, "%02u:%02u:%02u.%03u", hours, minutes, seconds, ms);
		}
		else if (0 != seconds)
		{
			_snprintf(buf, 13, "%02u:%02u:%02u", hours, minutes, seconds);
		}

		else
		{
			_snprintf(buf, 13, "%02u:%02u", hours, minutes);
		}

		buf[12] = 0;
		return buf;
	}

	bool Convert(const std::string& p_s, Time *p_pTime)
	{
		return convert(p_s.c_str(), p_pTime);
	}

	bool convert(const char *p_ps, Time *p_pTime)
	{
		// "HH:MM" len 5
		// "HH:MM:SS" len 8
		// "HH:MM:SS sss" len 12

		const size_t length = strlen(p_ps);

		if (5 == length && ':' == p_ps[2])
		{
			char buf[6];
			strcpy(buf, p_ps);
			buf[2] = 0;

			fs::dword hours;
			fs::dword minutes;

			if (convert(buf, &hours) &&
			    convert(buf + 3, &minutes))
			{
				*p_pTime = fs::Time(hours, minutes);
				return true;
			}
		}
		else if (8 == length && ':' == p_ps[2] && ':' == p_ps[5])
		{
			char buf[9];
			strcpy(buf, p_ps);
			buf[2] = 0;
			buf[5] = 0;

			fs::dword hours;
			fs::dword minutes;
			fs::dword seconds;

			if (convert(buf, &hours) &&
			    convert(buf + 3, &minutes) &&
			    convert(buf + 6, &seconds))
			{
				*p_pTime = fs::Time(hours, minutes, seconds);
				return true;
			}
		}
		else if (12 == length && ':' == p_ps[2] && ':' == p_ps[5] && '.' == p_ps[8])
		{
			char buf[13];
			
			strcpy(buf, p_ps);
			buf[2] = 0;
			buf[5] = 0;
			buf[8] = 0;

			fs::dword hours;
			fs::dword minutes;
			fs::dword seconds;
			fs::dword milliseconds;
					
			if (convert(buf, &hours) &&
			    convert(buf + 3, &minutes) &&
			    convert(buf + 6, &seconds) &&
			    convert(buf + 9, &milliseconds))
			{
				*p_pTime = fs::Time(hours, minutes, seconds, milliseconds);
				return true;
			}
		}

		return false;
	}

	bool Convert(const std::string& p_s, fs::Time::Span *p_pInterval)
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
			return false;
		}
		else if ('h' == chTimeIndicator)
		{
			*p_pInterval = Hours(nTimeInterval);
		}
		else if ('m' == chTimeIndicator)
		{
			*p_pInterval = Minutes(nTimeInterval);
		}
		else if ('s' == chTimeIndicator)
		{
			*p_pInterval = Seconds(nTimeInterval);
		}
		else if ('v' == chTimeIndicator)
		{
			*p_pInterval = MilliSeconds(nTimeInterval);
		}
		else
		{
			return false;
		}

		return true;
	}


	double ExcelTime(fs::Time p_tm)
	{
//		sfcn();

		double tc = p_tm.TickCount();
		double tcDay = ticksPerDay;

		double result = tc / tcDay;
	
		return result;
	}

}

/* End Of File: fsTime.cpp */
