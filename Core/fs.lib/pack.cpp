#include "precomp.h"
#include "declarations.h"

namespace fs
{
	word pack(byte p_high, byte p_low)
	{
		return (word) p_high << 8 | p_low;
	}

	dword pack(word p_high, word p_low)
	{
		return (dword) p_high << 16 | p_low;
	}

	qword pack(dword p_high, dword p_low)
	{
		return (qword) p_high << 32 | p_low;
	}

	dqword pack(qword p_high, qword p_low)
	{
		dqword tmp;
		tmp.m_hi = p_high;
		tmp.m_low = p_low;
		return tmp;
	}
}

/* End Of File: pack.cpp */
