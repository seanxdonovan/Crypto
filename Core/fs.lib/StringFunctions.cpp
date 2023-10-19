#include "precomp.h"
#include "declarations.h"

#include "stringfunctions.h"

#include <ctype.h>

namespace fs
{
	std::string toUpper(const std::string& p_s)
	{
		std::string s;

		s.resize(p_s.length());

		for (size_t ix = 0; ix < p_s.length(); ++ix)
		{
			s[ix] = toupper(p_s[ix]);
		}

		return s;
	}

	std::string toLower(const std::string& p_s)
	{
		std::string s;
		s.resize(p_s.length());

		for (size_t ix = 0; ix < p_s.length(); ++ix)
		{
			s[ix] = tolower(p_s[ix]);
		}

		return s;
	}

	void Split(const std::string& p_toSplit, const char p_splitChar, std::vector<std::string> *m_pSplits)
	{
		size_t ixStart = 0;

		size_t ix;
		for (ix = 0; ix < p_toSplit.length(); ++ix)
		{
			if (p_splitChar == p_toSplit[ix])
			{
				m_pSplits->push_back(p_toSplit.substr(ixStart, ix - ixStart));
				ixStart = ix + 1;
			}
		}

		m_pSplits->push_back(p_toSplit.substr(ixStart, ix - ixStart));
	}

	void Tokenize(const std::string& p_sInput, const std::string& p_sDelimiters, std::vector<std::string> *p_pvsTokens)
	{
		bool indelimiter = true;

		size_t ixBeginCurrentToken = std::string::npos;
		size_t ix = 0;

		while (ix < p_sInput.length())
		{
			size_t pos = p_sDelimiters.find_first_of(p_sInput[ix]);
			if (indelimiter)
			{
				if (std::string::npos == pos)
				{
					ixBeginCurrentToken = ix;
					indelimiter = false;
				}
			}
			else
			{
				if (std::string::npos != pos)
				{
					p_pvsTokens->push_back(p_sInput.substr(ixBeginCurrentToken, ix - ixBeginCurrentToken));
					ixBeginCurrentToken = std::string::npos;
					indelimiter = true;
				}
			}
			++ix;
		}
		if (!indelimiter)
		{
			p_pvsTokens->push_back(p_sInput.substr(ixBeginCurrentToken, ix - ixBeginCurrentToken));
		}
	}

	std::string Trim(const std::string& p_s, const std::string& p_sTrimCharacters /* = " \n\t" */)
	{
		size_t ixLeft = 0;
		size_t ixRight = p_s.length();

		while (ixLeft < ixRight)
		{
			if (std::string::npos == p_sTrimCharacters.find_first_of(p_s[ixLeft]))
			{
				break;
			}
			++ixLeft;
		}

		while (ixLeft < ixRight)
		{
			if (std::string::npos == p_sTrimCharacters.find_first_of(p_s[ixRight - 1]))
			{
				break;
			}
			--ixRight;
		}

		std::string s = p_s.substr(ixLeft, ixRight - ixLeft);

		return s;
	}

	std::string StripQuotes(const std::string& p_s)
	{
		sPrecondition(p_s.length() >= 2);

		size_t nStart = 0;
		size_t nLength = p_s.length();

		if (p_s[0] == '\"')
		{
			++nStart;
			--nLength;
		}
		if (p_s[p_s.length() - 1] == '\"')
		{
			--nLength;
		}

		return p_s.substr(nStart, nLength);


	}

	size_t StringCopy(wchar_t *p_sTo, const wchar_t *p_sFrom, size_t p_nMax)
	{
		size_t n = 0;
		const wchar_t *s = p_sFrom;

		while (n < p_nMax && *s)
		{
			p_sTo[n] = *s;
			++n;
			++s;
		}

		if (n == p_nMax)
		{
			p_sTo[n - 1] = 0;
		}
		else
		{
			p_sTo[n] = 0;
		}

		return n;
	}

	

	namespace
	{
		bool isAlphaNum[] = 
		{
			false, // '\0x00'
			false, // '\0x01'
			false, // '\0x02'
			false, // '\0x03'
			false, // '\0x04'
			false, // '\0x05'
			false, // '\0x06'
			false, // '\0x07'
			false, // '\0x08'
			false, // '\0x09'
			false, // '\0x0a'
			false, // '\0x0b'
			false, // '\0x0c'
			false, // '\0x0d'
			false, // '\0x0e'
			false, // '\0x0f'
			false, // '\0x10'
			false, // '\0x11'
			false, // '\0x12'
			false, // '\0x13'
			false, // '\0x14'
			false, // '\0x15'
			false, // '\0x16'
			false, // '\0x17'
			false, // '\0x18'
			false, // '\0x19'
			false, // '\0x1a'
			false, // '\0x1b'
			false, // '\0x1c'
			false, // '\0x1d'
			false, // '\0x1e'
			false, // '\0x1f'
			false, // ' '
			false, // '!'
			false, // '"'
			false, // '#'
			false, // '$'
			false, // '%'
			false, // '&'
			false, // '''
			false, // '('
			false, // ')'
			false, // '*'
			false, // '+'
			false, // ','
			false, // '-'
			false, // '.'
			false, // '/'
			true, // '0'
			true, // '1'
			true, // '2'
			true, // '3'
			true, // '4'
			true, // '5'
			true, // '6'
			true, // '7'
			true, // '8'
			true, // '9'
			false, // ':'
			false, // ';'
			false, // '<'
			false, // '='
			false, // '>'
			false, // '?'
			false, // '@'
			true, // 'A'
			true, // 'B'
			true, // 'C'
			true, // 'D'
			true, // 'E'
			true, // 'F'
			true, // 'G'
			true, // 'H'
			true, // 'I'
			true, // 'J'
			true, // 'K'
			true, // 'L'
			true, // 'M'
			true, // 'N'
			true, // 'O'
			true, // 'P'
			true, // 'Q'
			true, // 'R'
			true, // 'S'
			true, // 'T'
			true, // 'U'
			true, // 'V'
			true, // 'W'
			true, // 'X'
			true, // 'Y'
			true, // 'Z'
			false, // '['
			false, // '\'
			false, // ']'
			false, // '^'
			false, // '_'
			false, // '`'
			true, // 'a'
			true, // 'b'
			true, // 'c'
			true, // 'd'
			true, // 'e'
			true, // 'f'
			true, // 'g'
			true, // 'h'
			true, // 'i'
			true, // 'j'
			true, // 'k'
			true, // 'l'
			true, // 'm'
			true, // 'n'
			true, // 'o'
			true, // 'p'
			true, // 'q'
			true, // 'r'
			true, // 's'
			true, // 't'
			true, // 'u'
			true, // 'v'
			true, // 'w'
			true, // 'x'
			true, // 'y'
			true, // 'z'
			false, // '{'
			false, // '|'
			false, // '}'
			false, // '~'
			false, // '\0x7f'
			false, // '\0x80'
			false, // '\0x81'
			false, // '\0x82'
			false, // '\0x83'
			false, // '\0x84'
			false, // '\0x85'
			false, // '\0x86'
			false, // '\0x87'
			false, // '\0x88'
			false, // '\0x89'
			false, // '\0x8a'
			false, // '\0x8b'
			false, // '\0x8c'
			false, // '\0x8d'
			false, // '\0x8e'
			false, // '\0x8f'
			false, // '\0x90'
			false, // '\0x91'
			false, // '\0x92'
			false, // '\0x93'
			false, // '\0x94'
			false, // '\0x95'
			false, // '\0x96'
			false, // '\0x97'
			false, // '\0x98'
			false, // '\0x99'
			false, // '\0x9a'
			false, // '\0x9b'
			false, // '\0x9c'
			false, // '\0x9d'
			false, // '\0x9e'
			false, // '\0x9f'
			false, // '\0xa0'
			false, // '\0xa1'
			false, // '\0xa2'
			false, // '\0xa3'
			false, // '\0xa4'
			false, // '\0xa5'
			false, // '\0xa6'
			false, // '\0xa7'
			false, // '\0xa8'
			false, // '\0xa9'
			false, // '\0xaa'
			false, // '\0xab'
			false, // '\0xac'
			false, // '\0xad'
			false, // '\0xae'
			false, // '\0xaf'
			false, // '\0xb0'
			false, // '\0xb1'
			false, // '\0xb2'
			false, // '\0xb3'
			false, // '\0xb4'
			false, // '\0xb5'
			false, // '\0xb6'
			false, // '\0xb7'
			false, // '\0xb8'
			false, // '\0xb9'
			false, // '\0xba'
			false, // '\0xbb'
			false, // '\0xbc'
			false, // '\0xbd'
			false, // '\0xbe'
			false, // '\0xbf'
			false, // '\0xc0'
			false, // '\0xc1'
			false, // '\0xc2'
			false, // '\0xc3'
			false, // '\0xc4'
			false, // '\0xc5'
			false, // '\0xc6'
			false, // '\0xc7'
			false, // '\0xc8'
			false, // '\0xc9'
			false, // '\0xca'
			false, // '\0xcb'
			false, // '\0xcc'
			false, // '\0xcd'
			false, // '\0xce'
			false, // '\0xcf'
			false, // '\0xd0'
			false, // '\0xd1'
			false, // '\0xd2'
			false, // '\0xd3'
			false, // '\0xd4'
			false, // '\0xd5'
			false, // '\0xd6'
			false, // '\0xd7'
			false, // '\0xd8'
			false, // '\0xd9'
			false, // '\0xda'
			false, // '\0xdb'
			false, // '\0xdc'
			false, // '\0xdd'
			false, // '\0xde'
			false, // '\0xdf'
			false, // '\0xe0'
			false, // '\0xe1'
			false, // '\0xe2'
			false, // '\0xe3'
			false, // '\0xe4'
			false, // '\0xe5'
			false, // '\0xe6'
			false, // '\0xe7'
			false, // '\0xe8'
			false, // '\0xe9'
			false, // '\0xea'
			false, // '\0xeb'
			false, // '\0xec'
			false, // '\0xed'
			false, // '\0xee'
			false, // '\0xef'
			false, // '\0xf0'
			false, // '\0xf1'
			false, // '\0xf2'
			false, // '\0xf3'
			false, // '\0xf4'
			false, // '\0xf5'
			false, // '\0xf6'
			false, // '\0xf7'
			false, // '\0xf8'
			false, // '\0xf9'
			false, // '\0xfa'
			false, // '\0xfb'
			false, // '\0xfc'
			false, // '\0xfd'
			false, // '\0xfe'
			false, // '\0xff'
		};
	}

	bool IsAlphaNum(const std::string& p_s)
	{

		for (size_t ix = 0; ix < p_s.size(); ++ix)
		{
			if (!isAlphaNum[p_s[ix]])
			{
				return false;
			}
		}

		return true;
	}


}

/* End Of File: stringfunctions.cpp */
