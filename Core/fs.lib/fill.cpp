#include "precomp.h"
#include "declarations.h"



namespace fs
{
	std::string fill(const std::string& p_s, size_t p_width, fs::byte p_ch, bool p_trailing)
	{
		std::string s(p_width, p_ch);

		size_t nToCopy = p_width;
		if (nToCopy > p_s.length())
		{
			nToCopy = p_s.length();
		}

		size_t ixStart = 0;
		if (!p_trailing)
		{
			sAssert(nToCopy <= p_s.length());
			ixStart = p_width - nToCopy;
		}

		for (size_t ix = 0; ix < nToCopy; ++ix)
		{
			s[ixStart + ix] = p_s[ix];
		}

		return s;
	}
}

/* End of File: fill.cpp */
