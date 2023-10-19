#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"

#include "stdinStream.h"

namespace tools
{
	void stdinStream::Write(const fs::Buffer& p_buffer)
	{
		sRaiseError(("Can not write to stdin."));
	}

	void stdinStream::Read(fs::Buffer& p_buffer)
	{
		fread(p_buffer.Data(), p_buffer.Size(), 1, stdin);
	}

	bool stdinStream::EndOfFile()
	{
		return (0 != feof(stdin));
	}

	bool stdinStream::EndOfStream()
	{
		return EndOfFile();
	}

} /* namespace tools */

/* End Of File: stdinStream.cpp */
