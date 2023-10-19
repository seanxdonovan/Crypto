#include "precomp.h"
#include "declarations.h"
#include "type.h"

namespace fs
{
	namespace
	{
		std::string format(const char *p_pFormat, va_list p_arglist)
		{
			char buf[1024];

			_vsnprintf(buf, sizeof(buf) - 1, p_pFormat, p_arglist);
			buf[sizeof(buf) - 1]  = 0;

			return std::string(buf);
		}

		std::string __cdecl format(const char *p_pFormat, ...)
		{
			va_list arglist;

			va_start(arglist, p_pFormat);

			std::string s = format(p_pFormat, arglist);

			va_end(arglist);

			return s;
		}
	}

	std::string format(const char p_c)
	{
		std::string s;

		s = format("%c", p_c);

		return s;
	}

	std::string hex(byte p_value)
	{
		std::string s;

		s = format("%02x", p_value);

		return s;
	}

	std::string hex(word p_value)
	{
		std::string s;

		s = format("%04x", p_value);

		return s;
	}

	std::string hex(dword p_value)
	{
		std::string s;

		s = format("%08x", p_value);

		return s;
	}

	std::string hex(qword p_value)
	{
		std::string s;

		dword high;
		dword low;
		unpack(p_value, &high, &low);

		s = format("%08x%08x", high, low);
		return s;
	}

	std::string hex_(qword p_value)
	{
	    std::string s;

	    dword high;
	    dword low;
	    unpack(p_value, &high, &low);
	    if (0 == high)
	    {
		    s = format("%x", low);
	    }
	    else
	    {
		    s = format("%x%08x", high, low);
	    }
	    return s;
	}
	    

	std::string hex(dqword p_value)
	{
		std::string s;

		dword highhigh;
		dword highlow;
		dword lowhigh;
		dword lowlow;

		unpack(p_value.m_hi, &highhigh, &highlow);
		unpack(p_value.m_low, &lowhigh, &lowlow);

		s = format("%08x%08x%08x%08x", highhigh, highlow, lowhigh, lowlow);

		return s;
	}

	std::string hex(const void * const p_p)
	{
		std::string s;

		int n64bits;
		dword v = (dword)p_p;
		s = hex(v);
		return s;
	}

	std::string format(double p_value)
	{
		std::string s;

		s = format("%f", p_value);

		return s;
	}

	std::string format(double p_value, ::fs::dword precision)
	{
		char fmt[20];

		sprintf(fmt, "%%.%df", precision);

		auto s = format(fmt, p_value);
		return s;
	}

	std::string format(const GUID& p_guid)
	{
		return format("%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
			   p_guid.Data1,
			   p_guid.Data2,
			   p_guid.Data3,
			   p_guid.Data4[0],
			   p_guid.Data4[1],
			   p_guid.Data4[2],
			   p_guid.Data4[3],
			   p_guid.Data4[4],
			   p_guid.Data4[5],
			   p_guid.Data4[6],
			   p_guid.Data4[7]);
	}
#if defined(_M_IX86)
	std::string format(size_t p_n)
	{
		int n64bit;
		return format(static_cast<dword>(p_n));
	}
#endif

	std::string format(bool p_b)
	{
		if (p_b)
		{
			return "T";
		}
		return "F";
	}


	std::string format(byte p_value)
	{
		return format("%u", static_cast<dword>(p_value));
	}

	std::string format(word p_value)
	{
		return format("%u", static_cast<dword>(p_value));
	}

	std::string format(dword p_value)
	{
		return format("%u", p_value);
	}

	std::string format(qword p_value)
	{
		return format("%I64u", p_value);
	}

	std::string format(dqword p_value)
	{
		sAssert(false);
		int nNotImplemented;
		return "not-implemented";
	}


	std::string format(si8 p_value)
	{
		return format("%d", p_value);
	}

	std::string format(si16 p_value)
	{
		return format("%d", p_value);
	}

	std::string format(si32 p_value)
	{
		return format("%d", p_value);
	}
	std::string format(si64 p_value)
	{
		return format("%I64d", p_value);
	}

	std::string format(si128 p_value)
	{
		sAssert(false);
		int nNotImplemented;
		return "not-implemented";
	}

	std::string format(const Guid& p_guid)
	{
		const GUID *p = (const GUID *)&p_guid;

		return format(*p);
	}

	std::string format(const std::wstring& p_sWide)
	{
		return format("%S", p_sWide.c_str());
	}

	std::string format(fs::type::Null)
	{
		return "null";
	}

	std::string format(const char *p_s)
	{
		return p_s;
	}
}

/* End Of File: format.cpp */
