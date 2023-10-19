#include "precomp.h"
#include "declarations.h"
#include "format.h"
#include "exception.h"

namespace fs
{
	static void (*fcnOnRaiseError)();

	void OnRaiseError(void (*p_fcn)())
	{
		fcnOnRaiseError = p_fcn;
	}

	void raiseError(const char *strFileName, const si32 lineNumber, const char *strMsg)
	{
		std::string strError = format(strFileName, "(", lineNumber, "): ", strMsg);

#if !defined(NDEBUG)
		if (IsDebuggerPresent())
		{
			::OutputDebugString(strError.c_str());
			::OutputDebugString("\n");
		}
#endif
		if (0 != fcnOnRaiseError)
		{
			fcnOnRaiseError();
		}

		throw Exception(strMsg, strFileName, lineNumber, "localhost", "callstack");
	}
}
