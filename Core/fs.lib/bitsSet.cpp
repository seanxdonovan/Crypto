#include "precomp.h"
#include "declarations.h"

namespace fs
{
	dword bitsSet(byte b)
	{
		int n = 0;

		while (b)
		{
			if (b & 1)
			{
				++n;
			}
			b = b >> 1;
		}

		return n;
	}

	dword bitsSet(word w)
	{
		int n = 0;

		while (w)
		{
			if (w & 1)
			{
				++n;
			}
			w = w >> 1;
		}

		return n;
	}

	dword bitsSet(dword dw)
	{
		int n = 0;

		while (dw)
		{
			if (dw & 1)
			{
				++n;
			}
			dw = dw >> 1;
		}

		return n;
	}

	dword bitsSet(qword qw)
	{
		int n = 0;

		while (qw)
		{
			if (qw & 1)
			{
				++n;
			}
			qw = qw << 1;
		}

		return n;
	}
}

/* End Of File: bitsSet.cpp */
