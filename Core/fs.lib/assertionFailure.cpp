#include "precomp.h"
#include "declarations.h"
#include "format.h"
#include "exception.h"

namespace fs
{

	void assertionFailure(const char *strFileName, const si32 lineNumber, const char *strMsg)
	{
		std::string strError = format(strFileName, "(", lineNumber, "): Assertion Failure -> ", strMsg);

		if (IsDebuggerPresent())
		{
			sTrace((strError.c_str()));
			sTrace(("\n"));

			DebugBreak();
		}

		throw Exception(strError.c_str(), strFileName, lineNumber, "localhost", "") ;
	}
}
