#include "precomp.h"
#include "../fs.lib/fs.lib.h"
#include "declarations.h"

namespace tools
{
	::std::string SystemDate()
	{
		SYSTEMTIME systemTime;
		::GetSystemTime(&systemTime);

		char buffer[9];
		::sprintf(buffer, "%04u%02u%02u", systemTime.wYear, systemTime.wMonth, systemTime.wDay);

		return buffer;
	}

	::std::string LocalDate()
	{
		SYSTEMTIME systemTime;
		::GetLocalTime(&systemTime);

		char buffer[9];
		::sprintf(buffer, "%04u%02u%02u", systemTime.wYear, systemTime.wMonth, systemTime.wDay);

		return buffer;
	}

} /* namespace tools */

/* End Of File: SystemDate.cpp */
