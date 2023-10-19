#include "precomp.h"
#include "declarations.h"

#include "Random.h"
//
// See Numerical Recipes in C 2nd Ed. p 278
//
namespace fs
{
	Random::Random(ui32 p_seed)
	    : m_current(p_seed)
	{
	}

	ui32 Random::Next()
	{
		const ui64 a = 16807;
		const ui64 m = 2147483647;
		ui64 acc = m_current;
		acc *= a;
		acc %= m;

		ui32 h;
		unpack(acc, &h, &m_current);
		sAssert(0 == h);

		return m_current;
	}
}
/* End Of File: Random.cpp */
