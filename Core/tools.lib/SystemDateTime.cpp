#include "precomp.h"
#include "../fs.lib/fs.lib.h"
#include "declarations.h"

namespace tools
{
	::std::string SystemDateTime()
	{
		SYSTEMTIME systemTime;
		::GetSystemTime(&systemTime);

		char buffer[16];

		sprintf(buffer, "%04u%02u%02u_%02u%02u%02u", systemTime.wYear, systemTime.wMonth, systemTime.wDay, systemTime.wHour, systemTime.wMinute, systemTime.wSecond);

		return buffer;
	}

	::std::string LocalDateTime()
	{
		SYSTEMTIME systemTime;
		::GetLocalTime(&systemTime);

		char buffer[16];

		sprintf(buffer, "%04u%02u%02u_%02u%02u%02u", systemTime.wYear, systemTime.wMonth, systemTime.wDay, systemTime.wHour, systemTime.wMinute, systemTime.wSecond);

		return buffer;
	}

	::std::string LocalTime()
	{
		SYSTEMTIME systemTime;
		::GetLocalTime(&systemTime);

		char buffer[16];

		sprintf(buffer, "%02u%02u%02u", systemTime.wHour, systemTime.wMinute, systemTime.wSecond);

		return buffer;
	}
}

/* End Of File: SystemDateTime.cpp */

