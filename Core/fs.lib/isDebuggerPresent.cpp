#include "precomp.h"
#include "declarations.h"

namespace fs
{
	bool IsDebuggerPresent()
	{
#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
		return (TRUE == ::IsDebuggerPresent());
#else
		return false;
#endif
	}
}