#include "precomp.h"
#include "declarations.h"

namespace fs
{
	void unpack(word p_word, byte *p_pHighByte, byte *p_pLowByte)
	{
		*p_pHighByte = p_word >> 8;
		*p_pLowByte = p_word & 0xFF;
	}

	void unpack(dword p_dword, word *p_pHighWord, word *p_pLowWord)
	{
		*p_pHighWord = (word)(p_dword >> 16);
		*p_pLowWord = (word)(p_dword & 0xFFff);
	}

	void unpack(qword p_qword, dword *p_pHighDword, dword *p_pLowDword)
	{
		*p_pHighDword = (dword)(p_qword >> 32);
		*p_pLowDword = (dword)(p_qword & 0xFFffFFff);
	}
}

/* End Of File: unpack.cpp */
