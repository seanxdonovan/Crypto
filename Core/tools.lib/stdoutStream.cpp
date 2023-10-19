#include "precomp.h"
#include "../fs.lib/fs.lib.h"

#include "./stdoutStream.h"

namespace tools
{
	void stdoutStream::Write(const fs::Buffer& p_data)
	{
		fwrite(p_data.Data(), p_data.Size(), 1, stdout);
	}

	void stdoutStream::Read(fs::Buffer& p_into)
	{
		fread(p_into.Data(), p_into.Size(), 1, stdout);
	}

} /* namespace tools */

/* End Of File: stdoutStream.cpp */
