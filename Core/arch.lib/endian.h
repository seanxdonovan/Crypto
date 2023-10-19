namespace arch
{
	//
	// m - machine
	// l - little
	// b - big
	//
	// m2b -- machine (native) to big-endian
	// l2m -- little-endian to machine representation
	//

	 word m2l( word p_w);
	dword m2l(dword p_w);
	qword m2l(qword p_w);

	 word m2b( word p_w);
	dword m2b(dword p_w);
	qword m2b(qword p_w);

	 word l2m( word p_w);
	dword l2m(dword p_w);
	qword l2m(qword p_w);

	 word b2m( word p_w);
	dword b2m(dword p_w);
	qword b2m(qword p_w);



#if defined(_M_IX86) || defined(_M_X64)
	inline word m2l( word p_w)
	{
		return p_w;
	}

	inline dword m2l(dword p_w)
	{
		return p_w;
	}

	inline qword m2l(qword p_w)
	{
		return p_w;
	}

	inline word m2b( word p_w)
	{
		return _byteswap_ushort(p_w);
	}

	inline dword m2b(dword p_w)
	{
		return _byteswap_ulong(p_w);
	}

	inline qword m2b(qword p_w)
	{
		return _byteswap_uint64(p_w);
	}


	inline word l2m( word p_w)
	{
		return p_w;
	}

	inline dword l2m(dword p_w)
	{
		return p_w;
	}

	inline qword l2m(qword p_w)
	{
		return p_w;
	}


	inline word b2m( word p_w)
	{
		return _byteswap_ushort(p_w);
	}
	inline dword b2m(dword p_w)
	{
		return _byteswap_ulong(p_w);
	}

	inline qword b2m(qword p_w)
	{
		return _byteswap_uint64(p_w);
	}
#endif
}
