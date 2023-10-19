#include "precomp.h"
#include "../fs.lib/fs.lib.h"
#include "Console.h"

#include <wincon.h>
namespace tools
{
	void Console::Attach()
	{
		sValidate(AttachConsole(-1), ("AttachConsole() failed, GetLastError() == ", GetLastError()));
	}

}

/* End of File: Console.cpp */
