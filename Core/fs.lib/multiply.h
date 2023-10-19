

namespace fs
{
//	void multiply(fs::qword p_a, fs::qword p_b, fs::dqword *p_pResult);

	//
	// Add with carry
	//

	inline void Add(const fs::byte p_a, const fs::byte p_b, fs::word *p_pW)
	{
		const fs::word a = p_a;
		const fs::word b = p_b;
		const fs::word acc = a + b;
		*p_pW = acc;
	}

	inline void Add(const fs::word p_a, const fs::word p_b, fs::dword *p_pW)
	{
		const fs::dword a = p_a;
		const fs::dword b = p_b;
		const fs::dword acc = a + b;
		*p_pW = acc;
	}

	inline void Add(const fs::dword p_a, const fs::dword p_b, fs::qword *p_pW)
	{
		const fs::qword a = p_a;
		const fs::qword b = p_b;
		const fs::qword acc = a + b;
		*p_pW = acc;
	}


	//
	// AddTo add halfword to existing word.
	//
	inline void AddTo(const fs::byte p_addend, fs::word *p_pW)
	{
		*p_pW += p_addend;
	}

	inline void AddTo(const fs::word p_addend, fs::dword *p_pW)
	{
		*p_pW += p_addend;
	}

	inline void AddTo(const fs::dword p_addend, fs::qword *p_pW)
	{
		*p_pW += p_addend;
	}

	template <class word_t>
		void AddTo(word_t p_word, typename Traits<word_t>::dword_t *p_pW)
	{
		word_t tl = loword(*p_pW);
		word_t th = hiword(*p_pW);
		tl += p_word;
		if (tl < p_word)
		{
			++th;
		}
		*p_pW = pack(th, tl);
	}

	//
	// Multiply promotes to the next word size instead of perfoming a modular multiply as the built in operators do.
	// The versions for built in integral types are simple. A generalized template is provided for constructed
	// fixed width integral types for which appropriate Traits are defined.
	//

	inline void Multiply(const fs::byte p_a, const fs::byte p_b, fs::dword *p_pW)
	{
		const fs::dword a = p_a;
		const fs::dword b = p_b;
		const fs::dword acc = a * b;
		*p_pW = acc;
	}

	inline void Multiply(const fs::word p_a, const fs::word p_b, fs::dword *p_pW)
	{
		const fs::dword a = p_a;
		const fs::dword b = p_b;
		const fs::dword acc = a * b;
		*p_pW = acc;
	}

	inline void Multiply(const fs::dword p_a, const fs::dword p_b, fs::qword *p_pW)
	{
		const fs::qword a = p_a;
		const fs::qword b = p_b;
		const fs::qword acc = a * b;
		*p_pW = acc;
	}


	template <class word_t>
		void Multiply(word_t p_a, word_t p_b, typename Traits<word_t>::dword_t *p_pW)
	{
		typedef Traits<word_t>::dword_t dword_t;
		typedef Traits<word_t>::hword_t hword_t;
		hword_t al;
		hword_t ah;
		unpack(p_a, &ah, &al);
		hword_t bl;
		hword_t bh;
		unpack(p_b, &bh, &bl);

		//          ah    al
		//          bh    bl
		// _________________
		//       ah*bl al*bl
		// bh*ah bh*al
		//
		word_t tmp;

		word_t rl;
		Multiply(al, bl, &rl);
		word_t rh;
		Multiply(ah, bh, &rh);


		//
		// first intermediate term
		//
		Multiply(ah, bl, &tmp);

		word_t tmp2 = rl + pack(loword(tmp), hword_t(0));

		if (tmp2 < rl) // did we carry?
		{
			++rh;
		}
		rl = tmp2;
		AddTo(hiword(tmp), &rh);



		//
		// second row intermediate term.
		//

		Multiply(bh, al, &tmp);

		tmp2 = rl + pack(loword(tmp), hword_t(0));

		if (tmp2 < rl) // did we carry?
		{
			++rh;
		}
		rl = tmp2;
		AddTo(hiword(tmp), &rh);

		*p_pW = pack(rh, rl);
	}



	void Divide(fs::dword p_dividend, fs::word p_divisor, fs::dword *p_pQuotient, fs::word *p_pRemainder);

	fs::dword sqrt(fs::dword p_n); // floor(p_n^.5)


	inline void Divide(fs::dword p_dividend, fs::dword p_divisor, fs::dword *p_pQuotient, fs::dword *p_pRemainder)
	{
		// sAssert(0 != p_divisor) check somewhere else this is
		// suppose to be fast

		dword q;
		dword r;
#if defined(_M_IX86)
		_asm
		{
			MOV EDX, 0
			mov EAX, [p_dividend]
			DIV [p_divisor]
			mov [q], EAX
			mov [r], EDX
		}
#else
		q = p_dividend / p_divisor;
		r = p_dividend % p_divisor;
#endif
		*p_pQuotient = q;
		*p_pRemainder = r;
	}

//	void Divide(fs::qword p_dividend, fs::dword p_divisor, fs::qword *p_pQuotient, fs::dword *p_pRemainder);
	void Divide(fs::qword p_dividend, fs::dword p_divisor, fs::dword *p_pQuotient, fs::dword *p_pRemainder);

	void Divide(fs::qword p_dividend, fs::qword p_divisor, fs::qword *p_pQuotient, fs::qword *p_pRemainder);
	inline fs::dword Ceiling(fs::dword p_dividend, fs::dword p_divisor)
	{
		fs::dword q;
		fs::dword r;
		Divide(p_dividend, p_divisor, &q, &r);
		if (r > 0)
		{
			++q;
		}
		return q;
	}

	inline fs::qword Ceiling(fs::qword p_dividend, fs::qword p_divisor)
	{
		fs::qword q;
		fs::qword r;
		Divide(p_dividend, p_divisor, &q, &r);
		if (r > 0)
		{
			++q;
		}
		return q;
	}
}

namespace fs
{
	inline fs::Double abs(fs::Double p_v)
	{
		if (p_v < 0)
		{
			return -1 * p_v;
		}
		return p_v;
	}
}


