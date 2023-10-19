#include "precomp.h"
#include "declarations.h"
#include "format.h"

namespace fs
{
	qword TickCount()
	{
		LARGE_INTEGER li;
		if (!QueryPerformanceCounter(&li))
		{
			sRaiseError(("QueryPerformenceCounter() failed, GetLastError() == ", GetLastError(), "."));
		}

		return li.QuadPart;
	}

	qword TicksPerSecond()
	{
		LARGE_INTEGER li;
		QueryPerformanceFrequency(&li);
		return li.QuadPart;
	}

	Elapsed::Elapsed()
			: m_ticksPerSecond(fs::TicksPerSecond())
			, m_start(fs::TickCount())
	{
	}

	Elapsed::Elapsed(fs::qword p_startStamp)
			: m_ticksPerSecond(fs::TicksPerSecond())
			, m_start(p_startStamp)
	{
	}

	fs::qword Elapsed::us() const
	{
		fs::qword current = fs::TickCount();
		fs::qword delta = current - m_start;
		delta *= 1000;
		delta *= 1000;
		delta /= m_ticksPerSecond;

		return delta;
	}

	fs::qword Elapsed::ms() const
	{
		fs::qword current = fs::TickCount();
		fs::qword delta = current - m_start;
		delta *= 1000;
		delta /= m_ticksPerSecond;

		return delta;
	}

	void Elapsed::Start()
	{
		m_start = fs::TickCount();
	}

}

/* End Of File: TickCount.cpp */

