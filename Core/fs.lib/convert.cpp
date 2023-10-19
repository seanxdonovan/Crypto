#include "precomp.h"
#include "declarations.h"

namespace fs
{
	bool Convert(const std::string& p_s, bool *p_pValue)
	{
		if (("true" == p_s) ||
		    ("t"    == p_s) ||
		    ("True" == p_s) ||
		    ("T"    == p_s) ||
		    ("TRUE" == p_s))
		{
			*p_pValue = true;
			return true;
		}
		else if (("false" == p_s) ||
			 ("f"     == p_s) ||
			 ("False" == p_s) ||
			 ("F"     == p_s) ||
			 ("FALSE" == p_s))
		{
			*p_pValue = false;
			return true;
		}

		return false;
	}

	bool Convert(const char *strInt, int *pInt)
	{
		int NeedToEliminateThisFunction;
		bool result = false;

		char *tmp = 0;
		long l = strtol(strInt, &tmp, 10);

		result = ((0 != *strInt) && (0 == *tmp));
		if (result)
		{
			*pInt = l;
		}

		return result;
	}

	namespace
	{
		int values[] = 
		{
			-1, // '\0x00'
			-1, // '\0x01'
			-1, // '\0x02'
			-1, // '\0x03'
			-1, // '\0x04'
			-1, // '\0x05'
			-1, // '\0x06'
			-1, // '\0x07'
			-1, // '\0x08'
			-1, // '\0x09'
			-1, // '\0x0a'
			-1, // '\0x0b'
			-1, // '\0x0c'
			-1, // '\0x0d'
			-1, // '\0x0e'
			-1, // '\0x0f'
			-1, // '\0x10'
			-1, // '\0x11'
			-1, // '\0x12'
			-1, // '\0x13'
			-1, // '\0x14'
			-1, // '\0x15'
			-1, // '\0x16'
			-1, // '\0x17'
			-1, // '\0x18'
			-1, // '\0x19'
			-1, // '\0x1a'
			-1, // '\0x1b'
			-1, // '\0x1c'
			-1, // '\0x1d'
			-1, // '\0x1e'
			-1, // '\0x1f'
			-1, // ' '
			-1, // '!'
			-1, // '"'
			-1, // '#'
			-1, // '$'
			-1, // '%'
			-1, // '&'
			-1, // '''
			-1, // '('
			-1, // ')'
			-1, // '*'
			-1, // '+'
			-1, // ','
			-1, // '-'
			-1, // '.'
			-1, // '/'
			0, // '0'
			1, // '1'
			2, // '2'
			3, // '3'
			4, // '4'
			5, // '5'
			6, // '6'
			7, // '7'
			8, // '8'
			9, // '9'
			-1, // ':'
			-1, // ';'
			-1, // '<'
			-1, // '='
			-1, // '>'
			-1, // '?'
			-1, // '@'
			10, // 'A'
			11, // 'B'
			12, // 'C'
			13, // 'D'
			14, // 'E'
			15, // 'F'
			16, // 'G'
			17, // 'H'
			18, // 'I'
			19, // 'J'
			20, // 'K'
			21, // 'L'
			22, // 'M'
			23, // 'N'
			24, // 'O'
			25, // 'P'
			26, // 'Q'
			27, // 'R'
			28, // 'S'
			29, // 'T'
			30, // 'U'
			31, // 'V'
			32, // 'W'
			33, // 'X'
			34, // 'Y'
			35, // 'Z'
			-1, // '['
			-1, // '\'
			-1, // ']'
			-1, // '^'
			-1, // '_'
			-1, // '`'
			10, // 'a'
			11, // 'b'
			12, // 'c'
			13, // 'd'
			14, // 'e'
			15, // 'f'
			16, // 'g'
			17, // 'h'
			18, // 'i'
			19, // 'j'
			20, // 'k'
			21, // 'l'
			22, // 'm'
			23, // 'n'
			24, // 'o'
			25, // 'p'
			26, // 'q'
			27, // 'r'
			28, // 's'
			29, // 't'
			30, // 'u'
			31, // 'v'
			32, // 'w'
			33, // 'x'
			34, // 'y'
			35, // 'z'
			-1, // '{'
			-1, // '|'
			-1, // '}'
			-1, // '~'
			-1, // '\0x7f'
			-1, // '\0x80'
			-1, // '\0x81'
			-1, // '\0x82'
			-1, // '\0x83'
			-1, // '\0x84'
			-1, // '\0x85'
			-1, // '\0x86'
			-1, // '\0x87'
			-1, // '\0x88'
			-1, // '\0x89'
			-1, // '\0x8a'
			-1, // '\0x8b'
			-1, // '\0x8c'
			-1, // '\0x8d'
			-1, // '\0x8e'
			-1, // '\0x8f'
			-1, // '\0x90'
			-1, // '\0x91'
			-1, // '\0x92'
			-1, // '\0x93'
			-1, // '\0x94'
			-1, // '\0x95'
			-1, // '\0x96'
			-1, // '\0x97'
			-1, // '\0x98'
			-1, // '\0x99'
			-1, // '\0x9a'
			-1, // '\0x9b'
			-1, // '\0x9c'
			-1, // '\0x9d'
			-1, // '\0x9e'
			-1, // '\0x9f'
			-1, // '\0xa0'
			-1, // '\0xa1'
			-1, // '\0xa2'
			-1, // '\0xa3'
			-1, // '\0xa4'
			-1, // '\0xa5'
			-1, // '\0xa6'
			-1, // '\0xa7'
			-1, // '\0xa8'
			-1, // '\0xa9'
			-1, // '\0xaa'
			-1, // '\0xab'
			-1, // '\0xac'
			-1, // '\0xad'
			-1, // '\0xae'
			-1, // '\0xaf'
			-1, // '\0xb0'
			-1, // '\0xb1'
			-1, // '\0xb2'
			-1, // '\0xb3'
			-1, // '\0xb4'
			-1, // '\0xb5'
			-1, // '\0xb6'
			-1, // '\0xb7'
			-1, // '\0xb8'
			-1, // '\0xb9'
			-1, // '\0xba'
			-1, // '\0xbb'
			-1, // '\0xbc'
			-1, // '\0xbd'
			-1, // '\0xbe'
			-1, // '\0xbf'
			-1, // '\0xc0'
			-1, // '\0xc1'
			-1, // '\0xc2'
			-1, // '\0xc3'
			-1, // '\0xc4'
			-1, // '\0xc5'
			-1, // '\0xc6'
			-1, // '\0xc7'
			-1, // '\0xc8'
			-1, // '\0xc9'
			-1, // '\0xca'
			-1, // '\0xcb'
			-1, // '\0xcc'
			-1, // '\0xcd'
			-1, // '\0xce'
			-1, // '\0xcf'
			-1, // '\0xd0'
			-1, // '\0xd1'
			-1, // '\0xd2'
			-1, // '\0xd3'
			-1, // '\0xd4'
			-1, // '\0xd5'
			-1, // '\0xd6'
			-1, // '\0xd7'
			-1, // '\0xd8'
			-1, // '\0xd9'
			-1, // '\0xda'
			-1, // '\0xdb'
			-1, // '\0xdc'
			-1, // '\0xdd'
			-1, // '\0xde'
			-1, // '\0xdf'
			-1, // '\0xe0'
			-1, // '\0xe1'
			-1, // '\0xe2'
			-1, // '\0xe3'
			-1, // '\0xe4'
			-1, // '\0xe5'
			-1, // '\0xe6'
			-1, // '\0xe7'
			-1, // '\0xe8'
			-1, // '\0xe9'
			-1, // '\0xea'
			-1, // '\0xeb'
			-1, // '\0xec'
			-1, // '\0xed'
			-1, // '\0xee'
			-1, // '\0xef'
			-1, // '\0xf0'
			-1, // '\0xf1'
			-1, // '\0xf2'
			-1, // '\0xf3'
			-1, // '\0xf4'
			-1, // '\0xf5'
			-1, // '\0xf6'
			-1, // '\0xf7'
			-1, // '\0xf8'
			-1, // '\0xf9'
			-1, // '\0xfa'
			-1, // '\0xfb'
			-1, // '\0xfc'
			-1, // '\0xfd'
			-1, // '\0xfe'
			-1, // '\0xff'
		}; // int values[]
	}

	bool convertHex(const std::string& p_s, fs::byte *p_pValue)
	{
		if (p_s.length() > 0 && p_s.length() < 3)
		{
			byte acc = 0;
			byte factor = 1;
			for (size_t ix = p_s.length(); ix > 0; --ix)
			{
				const char ch = p_s[ix - 1];
				if (!isxdigit(ch))
				{
					return false;
				}
				acc += (values[ch] * factor);

				factor *= 16;
			}
			*p_pValue = acc;
			return true;
		}

		return false;
	}

	bool convertHex(const std::string& p_s, word *p_pValue)
	{
		if (p_s.length() > 0 && p_s.length() < 5)
		{
			word acc = 0;
			word factor = 1;
			for (size_t ix = p_s.length(); ix > 0; --ix)
			{
				const char ch = p_s[ix - 1];
				if (!isxdigit(ch))
				{
					return false;
				}
				acc += (values[ch] * factor);

				factor *= 16;
			}
			*p_pValue = acc;
			return true;
		}

		return false;
	}

	bool convertHex(const std::string& p_s, dword *p_pValue)
	{
		if (p_s.length() > 0 && p_s.length() < 9)
		{
			dword acc = 0;
			dword factor = 1;
			for (size_t ix = p_s.length(); ix > 0; --ix)
			{
				const char ch = p_s[ix - 1];
				if (!isxdigit(ch))
				{
					return false;
				}
				acc += (values[ch] * factor);

				factor *= 16;
			}
			*p_pValue = acc;
			return true;
		}

		return false;
	}

	bool convertHex(const std::string& p_s, qword *p_pValue)
	{
		if (p_s.length() > 0 && p_s.length() < 17)
		{
			qword acc = 0;
			qword factor = 1;
			for (size_t ix = p_s.length(); ix > 0; --ix)
			{
				const char ch = p_s[ix - 1];
				if (!isxdigit(ch))
				{
					return false;
				}
				acc += (values[ch] * factor);

				factor *= 16;
			}
			*p_pValue = acc;
			return true;
		}

		return false;
	}


	bool Convert(const std::string& p_s, fs::byte *p_pValue)
	{
		size_t size = p_s.length();
		if (0 == size)
		{
			return false;
		}
		if (1 == size)
		{
			*p_pValue = (p_s[0] - '0');
			return true;
		}

		if ('0' == p_s[0] && ('x' == p_s[1] || 'X' == p_s[1]))
		{
			if (2 == size)
			{
				return false;
			}

			return convertHex(p_s.substr(2), p_pValue);
		}

		return convert(p_s.c_str(), p_pValue);
	}

	bool Convert(const std::string& p_s, fs::word *p_pValue)
	{
		size_t size = p_s.length();
		if (0 == size)
		{
			return false;
		}
		if (1 == size)
		{
			*p_pValue = (p_s[0] - '0');
			return true;
		}

		if ('0' == p_s[0] && ('x' == p_s[1] || 'X' == p_s[1]))
		{
			if (2 == size)
			{
				return false;
			}

			return convertHex(p_s.substr(2), p_pValue);
		}

		return convert(p_s.c_str(), p_pValue);
	}

	bool Convert(const std::string& p_s, fs::dword *p_pValue)
	{
		size_t size = p_s.length();
		if (0 == size)
		{
			return false;
		}
		if (1 == size)
		{
			*p_pValue = (p_s[0] - '0');
			return true;
		}

		if ('0' == p_s[0] && ('x' == p_s[1] || 'X' == p_s[1]))
		{
			if (2 == size)
			{
				return false;
			}

			return convertHex(p_s.substr(2), p_pValue);
		}

		return convert(p_s.c_str(), p_pValue);
	}

	bool Convert(const std::string& p_s, fs::qword *p_pValue)
	{
		size_t size = p_s.length();
		if (0 == size)
		{
			return false;
		}
		if (1 == size)
		{
			*p_pValue = (p_s[0] - '0');
			return true;
		}

		if ('0' == p_s[0] && ('x' == p_s[1] || 'X' == p_s[1]))
		{
			if (2 == size)
			{
				return false;
			}

			return convertHex(p_s.substr(2), p_pValue);
		}

		return convert(p_s.c_str(), p_pValue);
	}

	bool Convert(const std::string& p_s, fs::si8 *p_pValue)
	{
		return false;
	}
	bool Convert(const std::string& p_s, fs::si16 *p_pValue)
	{
		return false;
	}

	bool Convert(const std::string& p_s, fs::si32 *p_pValue)
	{
		::fs::si64 v;

		if (!Convert(p_s, &v))
		{
			return false;
		}
		
		const si64 max = fs::Traits<si32>::Maximum;
		const si64 min = fs::Traits<si32>::Minimum;

		if (v > max)
		{
			return false;
		}

		if (v < min)
		{
			return false;
		}

		*p_pValue = (si32) v;

		return true;
	}

	bool Convert(const std::string& p_s, fs::si64 *p_pValue)
	{
		size_t size = p_s.length();
		if (0 == size)
		{
			return false;
		}
		if (1 == size)
		{
			if (!isdigit(p_s[0]))
			{
				return false;
			}
			*p_pValue = (p_s[0] - '0');
			return true;
		}


		int base = 10;
		if (p_s[0] == '0')
		{
			base = 8;
		}
		if ('0' == p_s[0] && ('x' == p_s[1] || 'X' == p_s[1]))
		{
			if (2 == size)
			{
				return false;
			}

			base = 16;
		}

		char *p;
		si64 v = _strtoi64(p_s.c_str(), &p, base);

		if (*p == 0)
		{
			*p_pValue = v;
			return true;
		}

		return false;
	}

	bool convert(const char *p_pText, byte  *p_pValue, dword p_base /* = 10 */)
	{
		bool result = false;

		char *tmp = 0;
		unsigned long l = strtoul(p_pText, &tmp, p_base);

		if (l > Traits<byte>::Maximum)
		{
			return false;
		}

		result = ((0 != *p_pText) && (0 == *tmp));

		if (result)
		{
			*p_pValue = sCoerce(byte, l);
		}

		return result;
	}

	bool convert(const char *p_pText, word  *p_pValue, dword p_base /* = 10 */)
	{
		bool result = false;

		char *tmp = 0;
		unsigned long l = strtoul(p_pText, &tmp, p_base);

		if (l > Traits<word>::Maximum)
		{
			return false;
		}

		result = ((0 != *p_pText) && (0 == *tmp));

		if (result)
		{
			*p_pValue = sCoerce(word, l);
		}

		return result;
	}

	bool convert(const char *p_pText, dword *p_pValue, dword p_base /* = 10 */)
	{
		bool result = false;

		char *tmp = 0;
		unsigned long l = strtoul(p_pText, &tmp, p_base);

		result = ((0 != *p_pText) && (0 == *tmp));

		if (result)
		{
			*p_pValue = l;
		}

		return result;
	}

	bool convert(const char *p_pText, qword *p_pValue)
	{
		bool result = false;

		char *tmp = 0;
		qword value = _strtoui64(p_pText, &tmp, 10);

		result = ((0 != *p_pText) && (0 == *tmp));

		if (result)
		{
			*p_pValue = value;
		}

		return result;
	}

#if 0
	bool convert(const char *p_pText, si8  *p_pValue)
	{
		int nNotImplemented;
		return false;
	}

	bool convert(const char *p_pText, si16 *p_pValue)
	{
		int nNotImplemented;
		return false;
	}
#endif
	
	bool convert(const char *p_pText, si32 *p_pValue)
	{
		bool result = false;

		char *tmp = 0;
		unsigned long l = strtol(p_pText, &tmp, 10);

		result = ((0 != *p_pText) && (0 == *tmp));

		if (result)
		{
			*p_pValue = l;
		}

		return result;
	}

#if 0
	bool convert(const char *p_pText, si64 *p_pValue)
	{
		int nNotImplemented;
		return false;
	}
#endif


	void Convert(const char *strGUID, GUID *pGUID)
	{
		sAssert(IsValidGUID(strGUID));

		char buf[36 + 1];
		strcpy(buf, strGUID);
		buf[8]  = 0;
		buf[13] = 0;
		buf[18] = 0;
		buf[23] = 0;

		const char *strData1  = buf;
		const char *strData2  = buf + 9;
		const char *strData3  = buf + 14;
		const char *strData4a = buf + 19;
		const char *strData4b = buf + 24;

		char *tmp = 0;

		dword val = strtoul(strData1, &tmp, 16);
		pGUID->Data1 = val;
		sAssert(0 == *tmp);

		val = strtoul(strData2, &tmp, 16);
		pGUID->Data2 = static_cast<WORD>(val);
		sAssert(0 == *tmp);

		val = strtoul(strData3, &tmp, 16);
		pGUID->Data3 = static_cast<WORD>(val);
		sAssert(0 == *tmp);

		pGUID->Data4[0] = (values[strData4a[0]]  << 4) | values[strData4a[1]];
		pGUID->Data4[1] = (values[strData4a[2]]  << 4) | values[strData4a[3]];
		pGUID->Data4[2] = (values[strData4b[0]]  << 4) | values[strData4b[1]];
		pGUID->Data4[3] = (values[strData4b[2]]  << 4) | values[strData4b[3]];
		pGUID->Data4[4] = (values[strData4b[4]]  << 4) | values[strData4b[5]];
		pGUID->Data4[5] = (values[strData4b[6]]  << 4) | values[strData4b[7]];
		pGUID->Data4[6] = (values[strData4b[8]]  << 4) | values[strData4b[9]];
		pGUID->Data4[7] = (values[strData4b[10]] << 4) | values[strData4b[11]];
	}


	bool IsValidGUID(const char *strGUID)
	{
		const char *s = strGUID;
		int count = 0;
		while (*s)
		{
			if ((8 == count) || (13 == count) || (18 == count) || (23 == count))
			{
				if ('-' != *s)
				{
					return false;
				}
			}
			else if (values[*s] == -1)
			{
				return false;
			}

			++count;
			++s;
		}

		return (36 == count);
	}

	bool convert(const char *p_pText, double *p_pValue)
	{
		char *pEnd;
		double d = strtod(p_pText, &pEnd);
		*p_pValue = d;
		return (0 == *pEnd);
	}

	bool Convert(const std::string& p_s, double *p_pValue)
	{
		return convert(p_s.c_str(), p_pValue);
	}

} /* namespace fs */

/* End Of File: convert.cpp */
