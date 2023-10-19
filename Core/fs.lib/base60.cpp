#include "precomp.h"

#include "declarations.h"

#include "base60.h"

namespace fs
{
	namespace base60
	{
		const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		std::string Encode(fs::qword p_value)
		{
			fs::qword v = p_value;

			std::string s;

			do
			{
				fs::qword pos = v % 60;
				s += digits[pos];
				v /= 60;
			}
			while (v != 0);

			return s;
		}


		bool Decode(const std::string& p_s, fs::qword *p_pValue)
		{
			fs::qword value = 0;

			size_t ix = p_s.length();
			char scan[2] = {0, 0};

			while (ix > 0)
			{
				value *= 60;
				--ix;
				scan[0] = p_s[ix];
				size_t ix = strcspn(digits, scan); // quick and dirty, not terribly efficient.
				if (ix >= 60)
				{
					return false;
				}

				value += ix;
			}

			*p_pValue = value;
			return true;
		}
	}
}
