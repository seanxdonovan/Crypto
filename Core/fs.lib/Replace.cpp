#include "precomp.h"
#include "declarations.h"

namespace fs
{


	void Replace(const char p_find, const char p_replace, std::string *p_pString)
	{
		std::string& s = *p_pString;

		for (size_t ix = 0; ix < s.size(); ++ix)
		{
			if (p_find == s[ix])
			{
				s[ix] = p_replace;
			}
		}
	}
}

/* End Of File: Replace.cpp */
