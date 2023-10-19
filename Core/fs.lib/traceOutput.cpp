#include "precomp.h"
#include "declarations.h"
#include "format.h"

namespace fs
{

	void traceOutput(const char *strFileName, const si32 lineNumber, const char *strMsg)
	{
		std::string str = format(strFileName, "(", lineNumber, "): ", strMsg, "\n");

		OutputDebugString(str.c_str());
	}
}
