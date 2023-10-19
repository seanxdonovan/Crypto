#include "precomp.h"
#include "declarations.h"
#include "type.h"
#include "type.id.h"

#include "strings.h"

namespace fs
{
	void StringShort::Assign(const std::string& p_string)
	{
		sPrecondition(p_string.size() <= Traits<byte>::Maximum);

		m_size = Coerce<size_t, fs::byte>()(p_string.length());

		char *pData = (char *)(this + 1);

		strncpy(pData, p_string.c_str(), p_string.length());
	}

	void StringMedium::Assign(const std::string& p_string)
	{
		
		sPrecondition(p_string.size() <= Traits<word>::Maximum);
		m_size = Coerce<size_t, fs::word>()(p_string.length());

		char *pData = (char *)(this + 1);

		strncpy(pData, p_string.c_str(), p_string.length());
	}

	std::string format(const fs::StringShort& p_s)
	{
		return "string short";
	}

#if 0
	StringShort *StringShort::Make(const char *p_pText, byte p_length)
	{
		char *p = new char [ sizeof(StringShort) + p_length ];

		memcpy(p + sizeof(StringShort), p_pText, p_length);
		StringShort *pS = (StringShort *) p;
		pS->m_size = p_length;

		return pS;
	}

	void StringShort::Release(StringShort *p_pString)
	{
		char * p = (char *) p_pString;

		delete [] p;
	}
#endif
	std::string format(const fs::StringMedium& p_s)
	{
		return "string medium";
	}

} /* namespace fundamental */


/* End Of File: strings.cpp */
