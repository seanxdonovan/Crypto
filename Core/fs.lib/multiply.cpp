#include "precomp.h"
#include "declarations.h"
#include "multiply.h"

#include "math.h"
namespace fs
{
	void multiply(fs::qword p_a, fs::qword p_b, fs::dqword *p_pResult)
	{
		fs::dword al;
		fs::dword ah;
		fs::unpack(p_a, &ah, &al);
		fs::dword bl;
		fs::dword bh;
		fs::unpack(p_b, &bh, &bl);

		fs::qword tmp;

		fs::qword rl = fs::qword(al) * fs::qword(bl);
		fs::qword rh = fs::qword(ah) * fs::qword(bh);

		tmp = fs::qword(bl) * fs::qword(ah);

		fs::qword tmp2 = rl + (tmp << 32);

		if (tmp2 < rl)
		{
			++rh;
		}
		rl = tmp2;

		rh += tmp >> 32;

		tmp = fs::qword(bh) * fs::qword(al);

		tmp2 = rl + (tmp << 32);
		if (tmp2 < rl)
		{
			++rh;
		}
		rl = tmp2;
		rh += tmp >> 32;

		p_pResult->m_hi = rh;
		p_pResult->m_low = rl;
	}


	void Divide(fs::qword p_dividend, fs::dword p_divisor, fs::dword *p_pQuotient, fs::dword *p_pRemainder)
	{
		if (0 == p_divisor)
		{
			throw DivideByZero();
		}

		*p_pQuotient = p_dividend / p_divisor;
		*p_pRemainder = p_dividend % p_divisor;

/* not right
		fs::dword hi = hiword(p_dividend);
		fs::dword lo = loword(p_dividend);

		fs::dword q;
		fs::dword r;
		_asm
		{
			mov EDX, [hi]
			mov EAX, [lo]
			DIV [p_divisor]
			mov [q], EAX
			mov [r], EDX
		}
		*p_pQuotient = q;
		*p_pRemainder = r;
*/
	}

	void Divide(fs::dword p_dividend, fs::word p_divisor, fs::dword *p_pQuotient, fs::word *p_pRemainder)
	{
		if (0 == p_divisor)
		{
			throw DivideByZero();
		}
		dword q;
		word r;
		fs::dword divisor = p_divisor;
#if defined(_M_IX86)
		_asm
		{
			MOV EDX, 0
			mov EAX, [p_dividend]
			DIV [divisor]
			mov [q], EAX
			mov [r], DX
		}
#else
		q = p_dividend / divisor;
		r = p_dividend % divisor;
#endif
		*p_pQuotient = q;
		*p_pRemainder = r;
	}

	void Divide(fs::qword p_dividend, fs::qword p_divisor, fs::qword *p_pQuotient, fs::qword *p_pRemainder)
	{
		*p_pQuotient = p_dividend / p_divisor;
		*p_pRemainder = p_dividend % p_divisor;
	}



	fs::dword sqrt(fs::dword p_n)
	{
		double x = p_n;
		double r = ::sqrt(x);
		return (dword) r;
	}


	double round(double p_value, fs::dword p_nSignificantDigits)
	{
		int putthisinafloatingpointfile;

		double v = p_value;
		for (fs::dword ix = 0; ix < p_nSignificantDigits; ++ix)
		{
			v *= 10;
		}

		double v2;
		if (v >= 0)
		{
			v += .5;
			 v2 = floor(v);
		}
		else
		{
			v -= .5;
			v2 = ceil(v);
		}

		for (fs::dword ix = 0; ix < p_nSignificantDigits; ++ix)
		{
			v2 /= 10;
		}
		return v2;
	}

}

