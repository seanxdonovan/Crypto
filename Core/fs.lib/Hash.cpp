#include "precomp.h"

#include "declarations.h"
#include "Hash.h"


namespace fs
{

//	Thomas Wang's 64 bit Mix Function
//	href="http://www.concentric.net/~Ttwang/tech/inthash.htm"

#if 0
	qword Hash(qword key)
	{
		key += ~(key << 32);
		key ^= (key >> 22);
		key += ~(key << 13);
		key ^= (key >> 8);
		key += (key << 3);
		key ^= (key >> 15);
		key += ~(key << 27);
		key ^= (key >> 31);
		return key;
	}
#endif



	void Hash(const char *p_pText, dword *p_pHashCode)
	{
		//
		// Dragon Book p. 436
		//

		dword h = 0;
		dword g;
		const char *p = p_pText;

		while (*p)
		{
			h = (h << 4) + (*p);
			g = h & 0xF0000000;
			if (g)
			{
				h = h ^ (g >> 24);
				h = h ^ g;
			}
			++p;
		}

		//
		// we do not limit the hash here as is done in the
		// above cite. The using application needs to restrict
		// the value if needed. We are only generating a seed
		// here.
		//

		*p_pHashCode = h;
	}
}
extern "C"
{
#include "./lookup3.c"
}



/* End Of File: Hash.cpp */
