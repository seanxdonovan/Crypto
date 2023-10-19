#include "precomp.h"
#include "declarations.h"

namespace fs
{
	std::string JoinStrings(const std::vector<std::string>& arrStrings, const char chJoin)
	{
		std::string str;
		if (arrStrings.size() > 0)
		{
			size_t ix = 0;

			str = arrStrings[ix];
			++ix;

			while (ix < arrStrings.size())
			{
				str += chJoin;
				str += arrStrings[ix];
				++ix;
			}
		}

		return str;
	}
}

/* End Of File: JoinStrings.cpp */
